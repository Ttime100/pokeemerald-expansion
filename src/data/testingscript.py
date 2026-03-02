import re
import os
import json

# --- CONFIGURATION ---
POKEDEX_H_PATH = 'include/constants/pokedex.h'
SPECIES_INFO_DIR = 'src/data/pokemon/species_info/'
OUTPUT_HTML = 'Master_Pokedex_Guide.html'

def clean_comments(text):
    text = re.sub(r'/\*[\s\S]*?\*/', '', text)
    text = re.sub(r'//.*', '', text)
    return text

def get_sprite_url(species_name):
    sn = species_name.replace("SPECIES_", "").upper()
    if "DEOXYS" in sn:
        f = sn.replace("DEOXYS_", "").lower()
        slug = f"deoxys-{f}" if f not in ["deoxys", "normal"] else "deoxys"
    elif "ROTOM" in sn:
        f = sn.replace("ROTOM_", "").lower()
        slug = f"rotom-{f}" if f not in ["rotom", "normal"] else "rotom"
    elif "CASTFORM" in sn:
        f = sn.replace("CASTFORM_", "").lower()
        slug = f"castform-{f}" if f not in ["castform", "normal"] else "castform"
    elif "GIRATINA" in sn:
        slug = "giratina-origin" if "ORIGIN" in sn else "giratina-altered"
    elif "SHAYMIN" in sn:
        slug = "shaymin-sky" if "SKY" in sn else "shaymin-land"
    elif "BASCULIN" in sn:
        slug = "basculin-blue-striped" if "BLUE_STRIPED" in sn else "basculin-red-striped"
    else:
        slug = sn.lower().replace("_", "-").replace(".", "").replace("'", "")
        slug = slug.replace("♀", "-f").replace("♂", "-m")
    return f"https://img.pokemondb.net/sprites/black-white/normal/{slug}.png"

def resolve_c_value(value, defines):
    value = value.strip()
    if '?' in value:
        match = re.search(r'\?\s*([\w{} ,_]+)', value)
        if match: value = match.group(1).strip('() ')
    if value.startswith('{'):
        return [v.strip() for v in value.strip('{}').split(',')]
    if value in defines:
        return resolve_c_value(defines[value], defines)
    return value

def extract_species_data(const, block, defines, macros):
    abilities = []
    a_m = re.search(r'\.abilities\s*=\s*\{([^}]+)\}', block, re.DOTALL)
    if a_m:
        raw_abils = a_m.group(1).split(',')
        for i, a in enumerate(raw_abils):
            clean = a.strip().replace('ABILITY_', '').replace('_', ' ').title()
            if not clean or "None" in clean or clean == "":
                continue
            abilities.append(f"{clean} (H)" if i == 2 else clean)
    macro_call = re.search(r'(\w+_SPECIES_INFO)\((.*?)\)', block)
    active_block = block
    macro_args = []
    if macro_call:
        macro_name = macro_call.group(1)
        macro_args = [arg.strip() for arg in macro_call.group(2).split(',')]
        if macro_name in macros: active_block = macros[macro_name]
    def get_val(pattern):
        raw = re.search(pattern, active_block)
        if not raw: return "0"
        val = raw.group(1)
        if val == "type" and len(macro_args) > 0: return macro_args[0]
        return resolve_c_value(val, defines)
    stats = {
        'hp': get_val(r'\.baseHP\s*=\s*(.*?),'),
        'atk': get_val(r'\.baseAttack\s*=\s*(.*?),'),
        'def': get_val(r'\.baseDefense\s*=\s*(.*?),'),
        'spa': get_val(r'\.baseSpAttack?\s*=\s*(.*?),'),
        'spd': get_val(r'\.baseSpDefense?\s*=\s*(.*?),'),
        'spe': get_val(r'\.baseSpeed\s*=\s*(.*?),'),
    }
    types = []
    t_m = re.search(r'\.types\s*=\s*MON_TYPES\(([^)]+)\)', active_block)
    if t_m:
        for t in t_m.group(1).split(','):
            res = resolve_c_value(t.strip(), defines)
            if isinstance(res, list):
                for st in res: types.append(st.replace('TYPE_', '').title())
            else: types.append(res.replace('TYPE_', '').title())
    types = [t for t in list(dict.fromkeys(types)) if t != "None"]
    return stats, types, (abilities if abilities else ["None"])

def get_pokedex_data():
    ordered_constants = []
    dex_numbers = {}
    with open(POKEDEX_H_PATH, 'r') as f:
        content = f.read()
        enum = re.search(r'enum NationalDexOrder\s*\{(.*?)\}', content, re.DOTALL)
        if enum:
            counter = 1
            for line in enum.group(1).split('\n'):
                if 'NATIONAL_DEX_' in line and 'NONE' not in line:
                    const = line.split('=')[0].replace('NATIONAL_DEX_', '').strip().strip(',')
                    ordered_constants.append(const)
                    dex_numbers[const] = counter
                    counter += 1
                    if 'GENESECT' in line: break
    pokemon_db = {}
    for root, _, files in os.walk(SPECIES_INFO_DIR):
        for file in files:
            if file.endswith('.h'):
                with open(os.path.join(root, file), 'r', encoding='utf-8') as f:
                    content = clean_comments(f.read())
                    defines = {m[0]: m[1].strip() for m in re.findall(r'#define\s+(\w+)\s+(.*)', content)}
                    macros = {m[0]: m[1] for m in re.findall(r'#define\s+(\w+_SPECIES_INFO)\(.*? \s*\{(.*?)\}', content, re.DOTALL)}
                    all_species_in_file = re.findall(r'\[\s*SPECIES_(\w+)\s*\]\s*=\s*\{(.*?)\},', content, re.DOTALL)
                    for s_name, s_block in all_species_in_file:
                        if any(x in s_name for x in ["MEGA_", "ALOLAN", "GALARIAN", "HISUIAN", "PALDEAN"]): continue
                        stats, types, abils = extract_species_data(s_name, s_block, defines, macros)
                        pokemon_db[s_name] = {
                            "name": s_name.replace('_', ' ').title(),
                            "stats": stats, "types": types, "abilities": abils,
                            "img": get_sprite_url(s_name)
                        }
    final_data = []
    seen_species = set()
    always_group = ["ROTOM", "DEOXYS", "GIRATINA", "SHAYMIN", "BASCULIN", "CASTFORM"]
    for const in ordered_constants:
        if const in seen_species: continue
        lookup_key = const
        if lookup_key not in pokemon_db and f"{const}_NORMAL" in pokemon_db: lookup_key = f"{const}_NORMAL"
        elif lookup_key not in pokemon_db and f"{const}_LAND" in pokemon_db: lookup_key = f"{const}_LAND"
        elif lookup_key not in pokemon_db and f"{const}_ALTERED" in pokemon_db: lookup_key = f"{const}_ALTERED"
        if lookup_key in pokemon_db:
            if any(base == const for base in always_group):
                forms = {k: v for k, v in pokemon_db.items() if k == const or k.startswith(const + "_")}
                for k in forms: seen_species.add(k)
                final_data.append({"base": const, "dex": dex_numbers.get(const, 0), "forms": forms})
            else:
                final_data.append({"base": const, "dex": dex_numbers.get(const, 0), "forms": {lookup_key: pokemon_db[lookup_key]}})
                seen_species.add(lookup_key)
    return final_data

def generate_master_guide():
    data = get_pokedex_data()
    type_colors = {"Normal": "#A8A77A", "Fire": "#EE8130", "Water": "#6390F0", "Electric": "#F7D02C", "Grass": "#7AC74C", "Ice": "#96D9D6", "Fighting": "#C22E28", "Poison": "#A33EA1", "Ground": "#E2BF65", "Flying": "#A98FF3", "Psychic": "#F95587", "Bug": "#A6B91A", "Rock": "#B6A136", "Ghost": "#735797", "Dragon": "#6F35FC", "Steel": "#B7B7CE", "Dark": "#705746", "Fairy": "#D685AD"}

    html = f"""<!DOCTYPE html><html><head><meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {{ font-family: sans-serif; background: #f0f2f5; margin: 0; padding: 0; }}
        
        /* RESTORED ORIGINAL NAV UI */
        .nav {{ 
            background: #2c3e50; 
            padding: 20px; 
            color: white; 
            text-align: center; 
            position: sticky; 
            top: 0; 
            z-index: 1000; 
            height: 125px; /* Restored original height */
            box-sizing: border-box;
        }}
        .nav h1 {{ margin: 0; font-size: 1.5em; text-transform: uppercase; letter-spacing: 1px; }}
        .search-container {{ margin-top: 15px; position: relative; max-width: 600px; margin-left: auto; margin-right: auto; }}
        #searchBar {{ padding: 10px 40px 10px 15px; width: 100%; border-radius: 20px; border: none; font-size: 16px; outline: none; box-sizing: border-box; }}
        #clearBtn {{ position: absolute; right: 15px; top: 50%; transform: translateY(-50%); background: #bdc3c7; color: white; border: none; border-radius: 50%; width: 22px; height: 22px; cursor: pointer; display: none; font-weight: bold; }}

        /* RESTORED ORIGINAL TABLE STYLING */
        table {{ width: 100%; border-collapse: collapse; background: white; box-shadow: 0 4px 6px rgba(0,0,0,0.1); }}
        
        thead th {{ 
            background: #34495e; 
            color: white; 
            padding: 12px; 
            position: sticky; 
            top: 125px; /* Glued perfectly to bottom of Nav */
            z-index: 900; 
            font-size: 1.15em;
            border-bottom: 2px solid #2c3e50;
        }}

        td {{ padding: 10px; border-bottom: 1px solid #eee; text-align: center; }}
        [class^="s-"] {{ font-size: 1.25em; font-weight: bold; font-family: monospace; }}
        
        /* RESTORED ORIGINAL IMAGE SIZING */
        .pk-img {{ width: 130px; height: 130px; image-rendering: pixelated; object-fit: contain; }}
        
        /* RESTORED PILLS AND TEXT */
        .type-pill {{ display: inline-block; padding: 5px 12px; border-radius: 4px; color: white; font-size: 12px; font-weight: bold; text-transform: uppercase; margin: 2px; }}
        .ab-row {{ display: block; font-size: 13px; color: #2980b9; font-weight: bold; margin-bottom: 3px; }}
        .form-btn {{ background: #ecf0f1; border: 1px solid #bdc3c7; padding: 6px 10px; margin: 2px; border-radius: 4px; cursor: pointer; font-weight: bold; font-size: 11px; }}
        .form-btn:hover {{ background: #3498db; color: white; }}

        #topBtn {{ display: none; position: fixed; bottom: 20px; right: 30px; z-index: 1100; background-color: #2c3e50; color: white; border: none; padding: 15px; border-radius: 50%; cursor: pointer; font-size: 18px; width: 50px; height: 50px; }}
    </style></head><body>
    <button onclick="topFunction()" id="topBtn">↑</button>
    <div class="nav">
        <h1>POKÉMON MASTER STRATEGY GUIDE</h1>
        <div class="search-container">
            <input type="text" id="searchBar" onkeyup="searchFilter()" placeholder="Search name, type, or ability...">
            <button id="clearBtn" onclick="clearSearch()">✕</button>
        </div>
    </div>
    <table id="pkTable">
        <thead>
            <tr>
                <th>#</th><th>Sprite</th><th>Name</th><th>Type</th><th>Abilities</th>
                <th>HP</th><th>Atk</th><th>Def</th><th>SpA</th><th>SpD</th><th>Spe</th><th>BST</th>
            </tr>
        </thead>
        <tbody>"""

    for entry in data:
        base_id = entry['base']
        f = next(iter(entry['forms'].values()))
        rid = f"row-{base_id}"
        bst = sum(int(v) for v in f['stats'].values() if str(v).isdigit())
        f_btns = "".join([f'<button class="form-btn" onclick=\'sw("{rid}","{k}",{json.dumps(entry["forms"]).replace('"', "&quot;")})\'>{k.replace(base_id + "_", "") if k != base_id else "BASE"}</button>' for k in entry['forms']]) if len(entry['forms']) > 1 else ""

        html += f"""<tr id="{rid}" class="pokemon-row">
            <td>#{str(entry['dex']).zfill(3)}</td>
            <td><img id="img-{rid}" src="{f['img']}" class="pk-img"></td>
            <td><b id="name-{rid}" style="font-size: 1.2em;">{f['name']}</b><br><div style="margin-top:8px;">{f_btns}</div></td>
            <td id="types-{rid}">{" ".join([f'<span class="type-pill" style="background:{type_colors.get(t,"#AAA")}">{t}</span>' for t in f['types']])}</td>
            <td id="abils-{rid}" style="min-width: 150px;">{" ".join([f'<span class="ab-row">{a}</span>' for a in f['abilities']])}</td>
            <td class="s-hp" id="hp-{rid}"><b>{f['stats']['hp']}</b></td>
            <td class="s-atk" id="atk-{rid}">{f['stats']['atk']}</td>
            <td class="s-def" id="def-{rid}">{f['stats']['def']}</td>
            <td class="s-spa" id="spa-{rid}">{f['stats']['spa']}</td>
            <td class="s-spd" id="spd-{rid}">{f['stats']['spd']}</td>
            <td class="s-spe" id="spe-{rid}">{f['stats']['spe']}</td>
            <td class="s-bst" id="bst-{rid}" style="color: #d35400;"><b>{bst}</b></td></tr>"""

    html += """</tbody></table>
    <script>
        const typeColors = """ + json.dumps(type_colors) + """;
        function sw(rid, key, formsData) {
            const f = formsData[key];
            document.getElementById('img-' + rid).src = f.img;
            document.getElementById('name-' + rid).innerText = f.name;
            document.getElementById('types-' + rid).innerHTML = f.types.map(t => `<span class="type-pill" style="background:${typeColors[t] || '#AAA'}">${t}</span> `).join('');
            document.getElementById('abils-' + rid).innerHTML = f.abilities.map(a => `<span class="ab-row">${a}</span>`).join('');
            let bst = 0;
            for (const [stat, value] of Object.entries(f.stats)) {
                const el = document.getElementById(stat + '-' + rid);
                if (el) {
                    el.innerHTML = (stat === 'hp') ? `<b>${value}</b>` : value;
                    bst += parseInt(value) || 0;
                }
            }
            document.getElementById('bst-' + rid).innerHTML = `<b>${bst}</b>`;
        }
        function searchFilter() {
            let input = document.getElementById("searchBar").value.toLowerCase();
            let rows = document.getElementsByClassName("pokemon-row");
            document.getElementById("clearBtn").style.display = input ? "block" : "none";
            for (let i = 0; i < rows.length; i++) {
                rows[i].style.display = rows[i].innerText.toLowerCase().includes(input) ? "" : "none";
            }
        }
        function clearSearch() { document.getElementById("searchBar").value = ""; searchFilter(); }
        let mybutton = document.getElementById("topBtn");
        window.onscroll = function() { mybutton.style.display = (window.pageYOffset > 300) ? "block" : "none"; };
        function topFunction() { window.scrollTo({top: 0, behavior: 'smooth'}); }
    </script></body></html>"""
    
    with open(OUTPUT_HTML, 'w', encoding='utf-8') as f: f.write(html)
    print("UI restored and headers anchored successfully!")

if __name__ == "__main__":
    generate_master_guide()