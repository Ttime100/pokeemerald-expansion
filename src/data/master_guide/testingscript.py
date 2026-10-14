from ast import pattern
import re
import os
import base64
import json

# --- CONFIGURATION ---
SPECIES_INFO_DIR = 'src/data/pokemon/species_info/'
OUTPUT_HTML = 'Master_Pokedex_Guide.html'

def clean_comments(text):
    text = re.sub(r'/\*[\s\S]*?\*/', '', text)
    text = re.sub(r'//.*', '', text)
    return text

def format_gender_html(gender_str):
    if not gender_str or "Genderless" in gender_str or "255" in gender_str:
        return '<span class="gender-none">Genderless</span>'
    if "♂" in gender_str and "♀" in gender_str:
        parts = gender_str.split('/')
        m_pct = parts[0].replace('♂', '').strip()
        f_pct = parts[1].replace('♀', '').strip()
        return (f'<div class="gender-row"><span class="gender-male">'
                f'<span class="gender-symbol">♂</span> {m_pct}'
                f'</span></div>'
                f'<div class="gender-row"><span class="gender-female">'
                f'<span class="gender-symbol">♀</span> {f_pct}'
                f'</span></div>')
    elif "♂" in gender_str:
        m_pct = gender_str.replace('♂', '').strip()
        return (f'<div class="gender-row"><span class="gender-male">'
                f'<span class="gender-symbol">♂</span> {m_pct}'
                f'</span></div>')
    elif "♀" in gender_str:
        f_pct = gender_str.replace('♀', '').strip()
        return (f'<div class="gender-row"><span class="gender-female">'
                f'<span class="gender-symbol">♀</span> {f_pct}'
                f'</span></div>')
    return gender_str

def normalize_name(name):
    if not name:
        return ""
    return (str(name).lower()
            .replace('♀', '_f')
            .replace('♂', '_m')
            .replace('-', '_')
            .replace(' ', '_')
            .replace('(', '')
            .replace(')', '')
            .replace("'", '')
            .replace('.', '')
            .replace(':', ''))

def get_sprite_url(species_name, is_shiny=False, use_icon=True):
    norm_name = normalize_name(species_name)
    variant = 'shiny' if is_shiny else 'normal'
    candidates = []
    
    if use_icon:
        candidates.append(f"{norm_name}_icon.png")
    else:
        candidates.append(f"{norm_name}_{variant}.png")
    if '_' in norm_name:
        base_name = norm_name.split('_')[0]
        if use_icon:
            candidates.append(f"{base_name}_icon.png")
        else:
            candidates.append(f"{base_name}_{variant}.png")
    img_dir = "src/data/master_guide/images/pokemon"
    for filename in candidates:
        img_path = os.path.join(img_dir, filename)
        if os.path.exists(img_path):
            with open(img_path, "rb") as img_file:
                encoded_string = base64.b64encode(img_file.read()).decode('utf-8')
                return f"data:image/png;base64,{encoded_string}"
    return ""

def resolve_c_value(value, defines):
    value = value.strip()
    if 'STANDARD_FRIENDSHIP' in value:
        return "50"
    if '?' in value:
        match = re.search(r'\?\s*([^:]+):', value)
        if match:
            value = match.group(1).strip('() ')
    if value.startswith('{'):
        return [v.strip() for v in value.strip('{}').split(',')]
    if value in defines:
        return resolve_c_value(defines[value], defines)
    return value

def extract_species_data(const, block, defines, macros):
    active_block = block
    if block.strip() in macros:
        params, body = macros[block.strip()]
        active_block = body

    def get_val(pattern):
        raw = re.search(pattern, active_block)
        if not raw: return "0"
        return resolve_c_value(raw.group(1), defines)

    abilities = []
    a_m = re.search(r'\.abilities\s*=\s*(?:\{([^}]+)\}|(\w+))', active_block, re.DOTALL)
    if a_m:
        raw_abil_str = a_m.group(1) or a_m.group(2)
        if raw_abil_str:
            resolved_abils = resolve_c_value(raw_abil_str, defines)
            if isinstance(resolved_abils, str):
                tokens = [t.strip() for t in resolved_abils.strip('{}').split(',')]
            elif isinstance(resolved_abils, list):
                tokens = resolved_abils
            else:
                tokens = [str(resolved_abils)]

            for i, token in enumerate(tokens):
                raw_val = resolve_c_value(token.strip(), defines)
                if isinstance(raw_val, list):
                    raw_val = raw_val[0] if raw_val else ""
                raw_val = str(raw_val).strip()
                
                if not raw_val or raw_val in ['ABILITY_NONE', 'NONE', '0']:
                    continue
                
                clean = raw_val.replace('ABILITY_', '').replace('_', ' ').title()
                if clean and clean != "None":
                    # Mark index 2 as Hidden Ability (H)
                    abilities.append(f"{clean} (H)" if i == 2 else clean)

    ev_yields = []
    ev_matches = re.findall(r'\.evYield_(\w+)\s*=\s*([^,]+),', active_block)
    for stat_name, val in ev_matches:
        resolved_val = resolve_c_value(val, defines)
        clean_stat = stat_name
        if clean_stat.lower() == 'hp': clean_stat = 'HP'
        elif clean_stat.lower() == 'attack': clean_stat = 'Atk'
        elif clean_stat.lower() == 'defense': clean_stat = 'Def'
        elif clean_stat.lower() == 'spattack': clean_stat = 'Sp. Atk'
        elif clean_stat.lower() == 'spdefense': clean_stat = 'Sp. Def'
        elif clean_stat.lower() == 'speed': clean_stat = 'Speed'
        
        if resolved_val and str(resolved_val).isdigit() and int(resolved_val) > 0:
            ev_yields.append(f"+{resolved_val} {clean_stat}")
    
    ev_yield_str = ", ".join(ev_yields) if ev_yields else "None"
    catch_rate = get_val(r'\.catchRate\s*=\s*([^,]+),')
    friendship = get_val(r'\.friendship\s*=\s*([^,]+),')
    growth_rate = get_val(r'\.growthRate\s*=\s*([^,]+),').replace('GROWTH_', '').replace('_', ' ').title()
    
    egg_groups = []
    eg_m = re.search(r'\.eggGroups\s*=\s*(?:MON_EGG_GROUPS\(([^)]+)\)|\{([^}]+)\})', active_block, re.DOTALL)
    if eg_m:
        raw_eg_match = eg_m.group(1) or eg_m.group(2)
        resolved_egs = resolve_c_value(raw_eg_match, defines)
        
        if isinstance(resolved_egs, str):
            resolved_egs = [resolved_egs]
            
        for eg in resolved_egs:
            clean_eg = eg.strip().replace('EGG_GROUP_', '').replace('_', ' ').title()
            if clean_eg and clean_eg != "None": 
                egg_groups.append(clean_eg)
            
    gender_raw = get_val(r'\.genderRatio\s*=\s*([^,]+),')
    if 'GENDERLESS' in gender_raw or '255' in gender_raw:
        gender_ratio_str = "Genderless"
    elif 'MON_MALE' in gender_raw:
        gender_ratio_str = "♂ 100%"
    elif 'MON_FEMALE' in gender_raw:
        gender_ratio_str = "♀ 100%"
    else:
        match_f = re.search(r'PERCENT_FEMALE\(([\d.]+)\)', gender_raw)
        if match_f:
            f_pct = float(match_f.group(1))
            m_pct = 100.0 - f_pct
            m_str = f"{int(m_pct)}%" if m_pct.is_integer() else f"{m_pct}%"
            f_str = f"{int(f_pct)}%" if f_pct.is_integer() else f"{f_pct}%"
            gender_ratio_str = f"♂ {m_str} / ♀ {f_str}"
        else:
            gender_ratio_str = gender_raw.replace('MON_', '').title()

    extras = {
        "ev_yield": ev_yield_str,
        "catch_rate": catch_rate,
        "friendship": friendship,
        "growth_rate": growth_rate,
        "egg_groups": ", ".join(egg_groups) if egg_groups else "None",
        "gender_ratio": gender_ratio_str
    }

    def get_stat_val(pattern):
        raw_val = get_val(pattern)
        if '?' in raw_val:
            parts = raw_val.split('?')
            if len(parts) > 1:
                options = parts[1].split(':')
                if len(options) > 0:
                    return resolve_c_value(options[0].strip(), defines)
        return raw_val

    stats = {
        'hp': get_stat_val(r'\.baseHP\s*=\s*(.*?),'),
        'atk': get_stat_val(r'\.baseAttack\s*=\s*(.*?),'),
        'def': get_stat_val(r'\.baseDefense\s*=\s*(.*?),'),
        'spa': get_stat_val(r'\.baseSpAttack?\s*=\s*(.*?),'),
        'spd': get_stat_val(r'\.baseSpDefense?\s*=\s*(.*?),'),
        'spe': get_stat_val(r'\.baseSpeed\s*=\s*(.*?),'),
    }

    types = []
    t_m = re.search(r'\.types\s*=\s*(?:MON_TYPES\((.*?)\)|\{([^}]+)\}|(\w+_TYPES))', active_block, re.DOTALL)
    if t_m:
        raw_type_match = t_m.group(1) or t_m.group(2) or t_m.group(3)
        if raw_type_match:
            type_args = [arg.strip() for arg in raw_type_match.split(',')]
            for arg in type_args:
                resolved = resolve_c_value(arg, defines)
                if isinstance(resolved, list):
                    for st in resolved:
                        clean_t = st.strip().replace('TYPE_', '').title()
                        if clean_t and clean_t != "None": types.append(clean_t)
                else:
                    clean_t = str(resolved).strip().replace('TYPE_', '').title()
                    if clean_t and clean_t != "None": types.append(clean_t)

    types = [t for t in list(dict.fromkeys(types)) if t != "None"]

    return stats, types, (abilities if abilities else ["None"]), extras

def get_pokedex_data():
    custom_list_path = 'src/data/custom_pokedex_list.txt'
    ordered_constants = []
    dex_numbers = {}
    
    if os.path.exists(custom_list_path):
        with open(custom_list_path, 'r', encoding='utf-8') as f:
            counter = 1
            for line in f:
                name = line.strip()
                if name:
                    const = name.upper().replace(' ', '_').replace('-', '_').replace('.', '').replace("'", '')
                    ordered_constants.append(const)
                    dex_numbers[const] = counter
                    counter += 1
    else:
        print(f"Warning: Custom list not found at {custom_list_path}. Falling back to empty order.")

    unwanted_form_tags = [
        "_MEGA", "_GMAX", "_GIGAMAX", "_PRIMAL", 
        "_ALOLA", "_ALOLAN", "_GALAR", "_GALARIAN", 
        "_HISUI", "_HISUIAN", "_PALDEA", "_PALDEAN",
        "_COSPLAY", "_ROCK_STAR", "_BELLE", "_POP_STAR", "_PHD", "_LIBRE",
        "_CAP", "_ORIGINAL", "_HOENN", "_SINNOH", "_UNOVA", 
        "_KALOS", "_ALOLA", "_PARTNER", "_WORLD", "_STARTER",
        "_SPIKY_EARED", "_SPIKY", "_THERIAN"
    ]

    species_form_blacklist = {
        "KYUREM": ["KYUREM_BLACK", "KYUREM_WHITE"],
        "DIALGA": ["DIALGA_ORIGIN"],
        "PALKIA": ["PALKIA_ORIGIN"]
    }

    pokemon_db = {}
    for root, _, files in os.walk(SPECIES_INFO_DIR):
        for file in files:
            if file.endswith('.h'):
                with open(os.path.join(root, file), 'r', encoding='utf-8') as f:
                    content = clean_comments(f.read())
                    defines = {}
                    for match in re.finditer(r'(?:#if[^\n]*\n\s*)?#define\s+(\w+_(?:TYPES|TYPE[12]|ABILITIES))\s+(.*)', content):
                        mac_name = match.group(1)
                        mac_val = match.group(2).strip()
                        if mac_name not in defines or any(g in match.group(0) for g in ['GEN_2', 'GEN_4', 'GEN_5', 'GEN_6', 'GEN_8']):
                            defines[mac_name] = mac_val
                    for m in re.finditer(r'#define\s+(\w+)\s+(.*)', content):
                        if m.group(1) not in defines:
                            defines[m.group(1)] = m.group(2).strip()
                    macros = {}
                    macro_def_pattern = re.compile(r'#define\s+(\w+)(?:\(([^)]*)\))?\s*(?:\\\s*)?\{', re.DOTALL)
                    for match in macro_def_pattern.finditer(content):
                        mac_name = match.group(1)
                        mac_params = [p.strip() for p in m_params.split(',')] if (m_params := match.group(2)) else []
                        
                        start_idx = match.end() - 1
                        brace_count = 1
                        curr_idx = start_idx + 1
                        while curr_idx < len(content) and brace_count > 0:
                            if content[curr_idx] == '{':
                                brace_count += 1
                            elif content[curr_idx] == '}':
                                brace_count -= 1
                            curr_idx += 1
                        
                        mac_body = content[start_idx+1:curr_idx-1]
                        mac_body = re.sub(r'\\\s*$', '', mac_body, flags=re.MULTILINE)
                        macros[mac_name] = (mac_params, mac_body)
                    pos = 0
                    while True:
                        match = re.search(r'\[\s*SPECIES_(\w+)\s*\]\s*=\s*\{', content[pos:])
                        if not match: 
                            break
                        s_name = match.group(1)
                        start_idx = pos + match.end()
                        brace_count = 1
                        curr_idx = start_idx
                        while curr_idx < len(content) and brace_count > 0:
                            if content[curr_idx] == '{':
                                brace_count += 1
                            elif content[curr_idx] == '}':
                                brace_count -= 1
                            curr_idx += 1
                        
                        s_block = content[start_idx:curr_idx-1]
                        pos = curr_idx

                        if any(tag in f"_{s_name}" for tag in unwanted_form_tags): 
                            continue
                        
                        stats, types, abils, extras = extract_species_data(s_name, s_block, defines, macros)
                        pokemon_db[s_name] = {
                            "name": s_name.replace('_', ' ').title(),
                            "stats": stats, "types": types, "abilities": abils,
                            "extras": extras, "img": get_sprite_url(s_name, use_icon=False)
                        }
                    for m_alias in re.finditer(r'\[\s*SPECIES_(\w+)\s*\]\s*=\s*([A-Z_]+)(?:\((.*?)\))?', content):
                        s_name = m_alias.group(1)
                        macro_prefix = m_alias.group(2)
                        args_str = m_alias.group(3)
                        
                        matched_body = None
                        if macro_prefix in macros:
                            params, body = macros[macro_prefix]
                            active_body = body
                            if args_str:
                                macro_args = [arg.strip() for arg in args_str.split(',')]
                                for param, arg in zip(params, macro_args):
                                    active_body = re.sub(r'\b' + param + r'\b', arg, active_body)
                            matched_body = active_body
                        
                        if s_name not in pokemon_db and matched_body:
                            if any(tag in f"_{s_name}" for tag in unwanted_form_tags):
                                continue
                            stats, types, abils, extras = extract_species_data(s_name, matched_body, defines, macros)
                            pokemon_db[s_name] = {
                                "name": s_name.replace('_', ' ').title(),
                                "stats": stats, 
                                "types": types, 
                                "abilities": abils,
                                "extras": extras,
                                "img": get_sprite_url(s_name, use_icon=False)
                            }

    final_data = []
    seen_species = set()
    
    for const in ordered_constants:
        if const in seen_species: 
            continue
        
        forms = {}
        target_key = const

        base_mappings = {
            "LANDORUS": "LANDORUS_INCARNATE",
            "TORNADUS": "TORNADUS_INCARNATE",
            "THUNDURUS": "THUNDURUS_INCARNATE",
            "MOTHIM": "MOTHIM",
            "UNOWN": "UNOWN",
            "GENESECT": "GENESECT",
            "ARCEUS": "ARCEUS",
        }

        single_form_only = ["ARCEUS", "GENESECT", "UNOWN", "MOTHIM"]

        if const in base_mappings:
            mapped_key = base_mappings[const]
            if mapped_key in pokemon_db:
                target_key = mapped_key

        if target_key in pokemon_db and const not in species_form_blacklist.get(const, []):
            form_data = pokemon_db[target_key].copy()
            form_data["name"] = const.replace('_', ' ').title()
            forms[const] = form_data
            seen_species.add(target_key)
            seen_species.add(const)
        
        blacklisted_forms = species_form_blacklist.get(const, [])
        
        if const not in single_form_only:
            sub_forms = {
                k: v for k, v in pokemon_db.items() 
                if k.startswith(const + "_") 
                and k not in seen_species 
                and k not in ordered_constants
                and k not in blacklisted_forms
                and not any(tag in f"_{k}" for tag in unwanted_form_tags)
            }
            if sub_forms:
                forms.update(sub_forms)
            
        if not forms:
            for suffix in ["_NORMAL", "_LAND", "_ALTERED", "_PLANT", "_SINGLE", "_A"]:
                candidate = f"{const}{suffix}"
                if candidate in pokemon_db and candidate not in blacklisted_forms and not any(tag in f"_{candidate}" for tag in unwanted_form_tags):
                    form_data = pokemon_db[candidate].copy()
                    form_data["name"] = const.replace('_', ' ').title()
                    forms[const] = form_data
                    seen_species.add(candidate)
                    break

        if forms:
            for k in forms: 
                seen_species.add(k)
            final_data.append({"base": const, "dex": dex_numbers.get(const, 0), "forms": forms})
            
    return final_data

def generate_master_guide():
    data = get_pokedex_data()
    type_colors = {"Normal": "#A8A77A", "Fire": "#EE8130", "Water": "#6390F0", "Electric": "#F7D02C", "Grass": "#7AC74C", "Ice": "#96D9D6", "Fighting": "#C22E28", "Poison": "#A33EA1", "Ground": "#E2BF65", "Flying": "#A98FF3", "Psychic": "#F95587", "Bug": "#A6B91A", "Rock": "#B6A136", "Ghost": "#735797", "Dragon": "#6F35FC", "Steel": "#B7B7CE", "Dark": "#705746", "Fairy": "#D685AD"}

    html = f"""<!DOCTYPE html><html><head><meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {{ font-family: sans-serif; background: #f0f2f5; margin: 0; padding: 0; }}
        
        .nav {{ 
            background: #2c3e50; 
            padding: 20px; 
            color: white; 
            text-align: center; 
            position: sticky; 
            top: 0; 
            z-index: 1000; 
            height: 125px; 
            box-sizing: border-box;
        }}
        .nav h1 {{ margin: 0; font-size: 1.5em; text-transform: uppercase; letter-spacing: 1px; }}
        .search-container {{ margin-top: 15px; position: relative; max-width: 600px; margin-left: auto; margin-right: auto; }}
        #searchBar {{ padding: 10px 40px 10px 15px; width: 100%; border-radius: 20px; border: none; font-size: 16px; outline: none; box-sizing: border-box; }}
        #clearBtn {{ position: absolute; right: 15px; top: 50%; transform: translateY(-50%); background: #bdc3c7; color: white; border: none; border-radius: 50%; width: 22px; height: 22px; cursor: pointer; display: none; font-weight: bold; }}

        table {{ width: 100%; border-collapse: collapse; background: white; box-shadow: 0 4px 6px rgba(0,0,0,0.1); }}
        
        thead th {{ 
            background: #34495e; 
            color: white; 
            padding: 12px; 
            position: sticky; 
            top: 125px; 
            z-index: 900; 
            font-size: 1.1em;
            border-bottom: 2px solid #2c3e50;
        }}

        td {{ padding: 10px; border-bottom: 1px solid #eee; text-align: center; font-size: 0.9em; }}
        [class^="s-"] {{ font-size: 1.15em; font-weight: bold; font-family: monospace; }}
        
        .pk-img {{ width: 64px; height: 64px; image-rendering: pixelated; object-fit: contain; }}
        
        .type-pill {{ display: inline-block; padding: 4px 6px; border-radius: 4px; color: white; font-size: 11px; font-weight: bold; text-transform: uppercase; margin: 2px; min-width: 72px; text-align: center; box-sizing: border-box; }}
        .ab-row {{ display: block; font-size: 12px; color: #2980b9; font-weight: bold; margin-bottom: 2px; }}
        .form-btn {{ background: #ecf0f1; border: 1px solid #bdc3c7; padding: 5px 8px; margin: 2px; border-radius: 4px; cursor: pointer; font-weight: bold; font-size: 10px; }}
        .form-btn:hover {{ background: #3498db; color: white; }}
        .gender-male {{ color: #3498db; font-weight: bold; font-size: 0.95em; }}
        .gender-female {{ color: #e84393; font-weight: bold; font-size: 0.95em; }}
        .gender-symbol {{ font-size: 1.3em; font-weight: 900; }}
        .gender-none {{ color: #7f8c8d; font-style: italic; }}
        .gender-row {{ line-height: 1.3; text-align: center; }}

        #topBtn {{ display: none; position: fixed; bottom: 20px; right: 30px; z-index: 1100; background-color: #2c3e50; color: white; border: none; padding: 15px; border-radius: 50%; cursor: pointer; font-size: 18px; width: 50px; height: 50px; }}
    </style></head><body>
    <button onclick="topFunction()" id="topBtn">↑</button>
    <div class="nav">
        <h1>POKÉMON MASTER STRATEGY GUIDE</h1>
        <div class="search-container">
            <input type="text" id="searchBar" onkeyup="searchFilter()" placeholder="Search name, type, ability, egg group...">
            <button id="clearBtn" onclick="clearSearch()">✕</button>
        </div>
    </div>
    <table id="pkTable">
        <thead>
            <tr>
                <th>#</th><th>Sprite</th><th>Name</th><th>Type</th><th>Abilities</th>
                <th>EV Yield</th><th>Catch Rate</th><th>Base Friendship</th><th>Growth Rate</th><th>Egg Groups</th><th>Gender</th>
                <th>HP</th><th>Atk</th><th>Def</th><th>SpA</th><th>SpD</th><th>Spe</th><th>BST</th>
            </tr>
        </thead>
        <tbody>"""

    for entry in data:
        base_id = entry['base']
        f = next(iter(entry['forms'].values()))
        rid = f"row-{base_id}"
        ext = f['extras']
        bst = sum(int(v) for v in f['stats'].values() if str(v).isdigit())
        f_btns = "".join([f'<button class="form-btn" onclick=\'sw("{rid}","{k}",{json.dumps(entry["forms"]).replace('"', "&quot;")})\'>{k.replace(base_id + "_", "") if k != base_id else "BASE"}</button>' for k in entry['forms']]) if len(entry['forms']) > 1 else ""

        html += f"""<tr id="{rid}" class="pokemon-row">
            <td>#{str(entry['dex']).zfill(3)}</td>
            <td><img id="img-{rid}" src="{f['img']}" class="pk-img"></td>
            <td><b id="name-{rid}" style="font-size: 1.1em;">{f['name']}</b><br><div style="margin-top:6px;">{f_btns}</div></td>
            <td id="types-{rid}">{" ".join([f'<span class="type-pill" style="background:{type_colors.get(t,"#AAA")}">{t}</span>' for t in f['types']])}</td>
            <td id="abils-{rid}" style="min-width: 140px;">{" ".join([f'<span class="ab-row">{a}</span>' for a in f['abilities']])}</td>
            <td id="ev-{rid}">{ext['ev_yield']}</td>
            <td id="catch-{rid}">{ext['catch_rate']}</td>
            <td id="friend-{rid}">{ext['friendship']}</td>
            <td id="growth-{rid}">{ext['growth_rate']}</td>
            <td id="egg-{rid}">{ext['egg_groups']}</td>
            <td id="gender-{rid}">{format_gender_html(ext['gender_ratio'])}</td>
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
        function formatGenderJS(gStr) {
            if (!gStr || gStr.includes("Genderless") || gStr.includes("255")) return '<span class="gender-none">Genderless</span>';
            if (gStr.includes("♂") && gStr.includes("♀")) {
                let parts = gStr.split('/');
                let mPct = parts[0].replace('♂', '').trim();
                let fPct = parts[1].replace('♀', '').trim();
                return `<div class="gender-row"><span class="gender-male"><span class="gender-symbol">♂</span> ${mPct}</span></div>` +
                       `<div class="gender-row"><span class="gender-female"><span class="gender-symbol">♀</span> ${fPct}</span></div>`;
            } else if (gStr.includes("♂")) {
                let mPct = gStr.replace('♂', '').trim();
                return `<div class="gender-row"><span class="gender-male"><span class="gender-symbol">♂</span> ${mPct}</span></div>`;
            } else if (gStr.includes("♀")) {
                let fPct = gStr.replace('♀', '').trim();
                return `<div class="gender-row"><span class="gender-female"><span class="gender-symbol">♀</span> ${fPct}</span></div>`;
            }
            return gStr;
        }

        function sw(rid, key, formsData) {
            const f = formsData[key];
            const ext = f.extras;
            document.getElementById('img-' + rid).src = f.img;
            document.getElementById('name-' + rid).innerText = f.name;
            document.getElementById('types-' + rid).innerHTML = f.types.map(t => `<span class="type-pill" style="background:${typeColors[t] || '#AAA'}">${t}</span> `).join('');
            document.getElementById('abils-' + rid).innerHTML = f.abilities.map(a => `<span class="ab-row">${a}</span>`).join('');
            
            document.getElementById('ev-' + rid).innerText = ext.ev_yield;
            document.getElementById('catch-' + rid).innerText = ext.catch_rate;
            document.getElementById('friend-' + rid).innerText = ext.friendship;
            document.getElementById('growth-' + rid).innerText = ext.growth_rate;
            document.getElementById('egg-' + rid).innerText = ext.egg_groups;
            document.getElementById('gender-' + rid).innerHTML = formatGenderJS(ext.gender_ratio);

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

    OUTPUT_HTML = "src/data/master_guide/Master_Pokedex_Guide.html"
    
    with open(OUTPUT_HTML, 'w', encoding='utf-8') as f: f.write(html)
    print("Master Pokedex Guide generated with full metadata columns!")

if __name__ == "__main__":
    generate_master_guide()