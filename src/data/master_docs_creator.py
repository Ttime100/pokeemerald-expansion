import json
import re
from collections import defaultdict

# ==========================================
# CONFIGURATION SECTION
# ==========================================
WILD_JSON_PATH = 'src/data/wild_encounters.json'
TRAINER_PARTY_PATH = 'src/data/trainers.party'
POKEDEX_LIST_PATH = '/home/tyler/decomps/pokeemerald-expansion/src/data/custom_pokedex_list.txt'
OUTPUT_HTML = 'Master_Strategy_Guide.html'

CURRENT_LEAGUE_IDS = [
    'TRAINER_ELITE_FOUR_PARTH',
    'TRAINER_ELITE_FOUR_AUSTIN',
    'TRAINER_ELITE_FOUR_ROB',
    'TRAINER_ELITE_FOUR_TYLER',
    'TRAINER_WALLACE',
]
GYM_LEADER_IDS = [
    'TRAINER_ROXANNE_1',
    'TRAINER_BRAWLY_1',
    'TRAINER_WATTSON_1',
    'TRAINER_FLANNERY_1',
    'TRAINER_NORMAN_1',
    'TRAINER_WINONA_1',
    'TRAINER_TATE_AND_LIZA_1',
    'TRAINER_JUAN_1',
]
FORMER_LEAGUE_IDS = [
    'TRAINER_SIDNEY',
    'TRAINER_PHOEBE',
    'TRAINER_GLACIA',
    'TRAINER_DRAKE',
]

LAND_RATES = [13, 13, 13, 10, 10, 10, 10, 10, 5, 4, 1, 1]
WATER_RATES = [55, 25, 10, 5, 3, 1, 1]
OLD_ROD_RATES = [70, 30]
GOOD_ROD_RATES = [60, 20, 20]
SUPER_ROD_RATES = [40, 40, 15, 4, 1]
ROCK_RATES = [60, 30, 5, 4, 1]

# ==========================================

def is_ignored_entry(entry: dict) -> bool:
    base_label = entry.get("base_label", "")
    map_name = entry.get("map", "")
    
    ignored_keywords = (
        "FireRed", "LeafGreen", "FIRERED", "LEAFGREEN",
        "UnusedRubySapphire", "UNUSED_RUBY_SAPPHIRE",
        "BattlePyramid", "BattlePike",
        "BATTLE_PYRAMID", "BATTLE_PIKE"
    )
    return any(kw in base_label for kw in ignored_keywords) or any(kw in map_name for kw in ignored_keywords)

def get_base_species_name(species_name: str) -> str:
    # Fix punctuation mismatches first
    if species_name == "Mr Mime": return "Mr. Mime"
    if species_name == "Mime Jr": return "Mime Jr."
    if species_name == "Farfetchd": return "Farfetch'D"
    name_clean = species_name.strip()
    # List of base species that have form suffixes in decomp data
    multi_form_bases = [
        'Burmy', 'Wormadam', 'Shellos', 'Gastrodon', 'Basculin', 
        'Deoxys', 'Giratina', 'Shaymin', 'Rotom', 'Castform', 
        'Cherrim', 'Arceus', 'Darmanitan', 'Meloetta'
    ]
    for base in multi_form_bases:
        if name_clean.lower().startswith(base.lower()):
            return base
    return name_clean

def clean_comments(text):
    text = re.sub(r'/\*[\s\S]*?\*/', '', text)
    text = re.sub(r'//.*', '', text)
    return text


def load_pokedex_order(path):
    pokedex_order = {}
    pokedex_species_list = []
    try:
        with open(path, 'r', encoding='utf-8') as f:
            index = 0
            for line in f:
                line = line.strip()
                if line:
                    clean_name = line.replace('SPECIES_', '').replace('_', ' ').title().strip()
                    lower_name = clean_name.lower()
                    if lower_name not in pokedex_order:
                        pokedex_order[lower_name] = index
                        pokedex_species_list.append(clean_name)
                        index += 1
    except FileNotFoundError:
        print(f"Warning: Pokédex list not found at {path}. Defaulting to alphabetical sort.")
    return pokedex_order, pokedex_species_list


def format_map_name(label):
    if not label:
        return 'Unknown Location'
    if label.startswith('g'):
        label = label[1:]
    label = re.sub(r'_(Land|Water|Fishing|RockSmash)Mons$', '', label)
    label = label.replace('_', ' ')
    label = re.sub(r'([a-zA-Z])(\d)', r'\1 \2', label)
    return label.strip()


def get_sprite_url(species_name, is_shiny=False, use_icon=True):
    name_clean = species_name.lower().replace('_', '-').replace(' ', '-').replace("'", '').replace('.', '')
    if use_icon:
        prefix = 'shiny' if is_shiny else 'sun-moon'
        return f'https://img.pokemondb.net/sprites/{prefix}/icon/{name_clean}.png'
    else:
        folder = 'shiny' if is_shiny else 'normal'
        return f'https://img.pokemondb.net/sprites/black-white/{folder}/{name_clean}.png'


def parse_trainers(path):
    try:
        with open(path, 'r', encoding='utf-8') as f:
            raw_text = f.read()
    except FileNotFoundError:
        return {}

    clean_text = clean_comments(raw_text)
    trainer_matches = re.split(r'===\s*(TRAINER_[\w_]+)\s*===', clean_text)
    trainers = {}
    
    for i in range(1, len(trainer_matches), 2):
        t_id = trainer_matches[i]
        content = trainer_matches[i+1].strip()
        if t_id == "TRAINER_NONE": continue
        blocks = re.split(r'\n\s*\n', content)
        t_data = {"id": t_id, "name": "Unknown", "class": "Trainer", "party": []}
        header_lines = blocks[0].strip().split('\n')
        pokemon_start_index = 0
        if not header_lines[0].strip().startswith("-") and "Level:" not in header_lines[0]:
             for line in header_lines:
                if ":" in line and not line.strip().startswith("-"):
                    key, val = line.split(":", 1)
                    t_data[key.strip().lower()] = val.strip()
                else: break
             pokemon_start_index = 1
        pokemon_text = "\n\n".join(blocks[pokemon_start_index:])
        pkmn_list = []
        current_mon_lines = []
        KNOWN_PROPS = ['Level:', 'IVs:', 'EVs:', 'Ability:', 'Nature:', 'Shiny:', 'Ball:', 'Happiness:']
        for line in pokemon_text.split('\n'):
            line = line.strip()
            if not line: continue
            is_prop = any(line.startswith(x) for x in KNOWN_PROPS) or line.startswith("- ")
            if not is_prop:
                if current_mon_lines: pkmn_list.append(current_mon_lines)
                current_mon_lines = [line]
            else:
                current_mon_lines.append(line)
        if current_mon_lines: pkmn_list.append(current_mon_lines)
        for mon_lines in pkmn_list:
            first_line = mon_lines[0]
            item = "None"
            if "@" in first_line:
                first_line_parts = first_line.split("@", 1)
                first_line = first_line_parts[0]
                item = first_line_parts[1].strip().replace("ITEM_", "").replace("_", " ").title()
            gender = ""
            if "(M)" in first_line: gender = "♂"
            elif "(F)" in first_line: gender = "♀"
            clean_name = first_line.replace("(M)", "").replace("(F)", "").strip()
            paren_match = re.search(r'\(([^)]+)\)', clean_name)
            species = paren_match.group(1) if paren_match else clean_name
            species = get_base_species_name(species.replace("SPECIES_", "").strip().replace("_", " ").title())
            mon = {"species": species, "gender": gender, "item": item, "level": "??", "ivs": "31/31/31/31/31/31", "nature": "Hardy", "ability": "Any", "is_shiny": False, "moves": []}
            for line in mon_lines[1:]:
                if line.startswith("Level:"): mon['level'] = line.split(":")[1].strip()
                elif line.startswith("IVs:"): mon['ivs'] = line.split(":")[1].strip()
                elif line.startswith("Nature:"): mon['nature'] = line.split(":")[1].strip()
                elif line.startswith("Ability:"): mon['ability'] = line.split(":")[1].strip()
                elif line.startswith("Shiny:"): mon['is_shiny'] = "Yes" in line
                elif line.startswith("- "): mon['moves'].append(line.replace("- ", "").title())
            t_data['party'].append(mon)
        trainers[t_id] = t_data
    return trainers

def generate_master_guide():
    try:
        with open(WILD_JSON_PATH, 'r', encoding='utf-8') as f:
            wild_data = json.load(f)
    except Exception:
        wild_data = {'wild_encounter_groups': []}

    trainers_dict = parse_trainers(TRAINER_PARTY_PATH)
    pokedex_order, pokedex_species_list = load_pokedex_order(POKEDEX_LIST_PATH)

    pokemon_encounters = defaultdict(list)
    route_cards_data = []

    for group in wild_data.get('wild_encounter_groups', []):
        for enc in group.get('encounters', []):
            if is_ignored_entry(enc):
                continue
            raw_label = enc.get('base_label', enc.get('map', ''))
            map_name = format_map_name(raw_label)
            route_info = {'map_name': map_name, 'methods': {}}

            def process_slice(sub_method_name, mons_slice, rates_slice):
                mons_data = []
                species_agg = {}
                for i, m in enumerate(mons_slice):
                    raw_species = m['species'].replace('SPECIES_', '').replace('_', ' ').title().strip()
                    species = raw_species  # Keep full name (e.g., Shellos East) for precise tracking
                    min_lvl = int(m.get('min_level', 1))
                    max_lvl = int(m.get('max_level', min_lvl))
                    rate = rates_slice[i] if i < len(rates_slice) else 0

                    lvl_str = f'Lv.{min_lvl}' if min_lvl == max_lvl else f'Lv.{min_lvl}-{max_lvl}'
                    mons_data.append({
                        'species': species,
                        'level_str': lvl_str,
                        'rate': rate,
                    })

                    # Key MUST include species to avoid overwriting lower slots in the same table
                    agg_key = (species, map_name, sub_method_name)
                    if agg_key not in species_agg:
                        species_agg[agg_key] = {
                            'species': species,
                            'map_name': map_name,
                            'method': sub_method_name,
                            'min_level': min_lvl,
                            'max_level': max_lvl,
                            'rate': 0,
                        }
                    species_agg[agg_key]['rate'] += rate
                    species_agg[agg_key]['min_level'] = min(species_agg[agg_key]['min_level'], min_lvl)
                    species_agg[agg_key]['max_level'] = max(species_agg[agg_key]['max_level'], max_lvl)

                for entry in species_agg.values():
                    pokemon_encounters[entry['species']].append(entry)

                return mons_data

            if 'land_mons' in enc and 'mons' in enc['land_mons']:
                route_info['methods']['Land'] = process_slice('Land', enc['land_mons']['mons'], LAND_RATES)

            if 'water_mons' in enc and 'mons' in enc['water_mons']:
                route_info['methods']['Water'] = process_slice('Water', enc['water_mons']['mons'], WATER_RATES)

            if 'fishing_mons' in enc and 'mons' in enc['fishing_mons']:
                all_fishing = enc['fishing_mons']['mons']
                fishing_groups = {}
                if len(all_fishing) >= 2:
                    fishing_groups['Old Rod'] = process_slice('Old Rod', all_fishing[0:2], OLD_ROD_RATES)
                if len(all_fishing) >= 5:
                    fishing_groups['Good Rod'] = process_slice('Good Rod', all_fishing[2:5], GOOD_ROD_RATES)
                if len(all_fishing) >= 10:
                    fishing_groups['Super Rod'] = process_slice('Super Rod', all_fishing[5:10], SUPER_ROD_RATES)
                if fishing_groups:
                    route_info['methods']['Fishing'] = fishing_groups

            if 'rock_smash_mons' in enc and 'mons' in enc['rock_smash_mons']:
                route_info['methods']['Rock Smash'] = process_slice('Rock Smash', enc['rock_smash_mons']['mons'], ROCK_RATES)

            if route_info['methods']:
                route_cards_data.append(route_info)

    html = """<!DOCTYPE html><html><head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
    body { font-family: 'Segoe UI', Tahoma, sans-serif; background: #f0f2f5; margin: 0; color: #333; overflow-x: hidden; }
    
    .tab-radio { display: none; }
    .nav { background: #2c3e50; padding: 12px; position: sticky; top: 0; text-align: center; z-index: 1000; display: flex; justify-content: center; gap: 8px; position: relative; }
    .nav label { padding: 10px 18px; font-size: 14px; cursor: pointer; background: #34495e; color: white; border-radius: 6px; transition: 0.2s; -webkit-tap-highlight-color: transparent; }
    
    .tab-content { display: none; padding: 15px; max-width: 1400px; margin: auto; }
    
    #radio-wild:checked ~ .nav label[for="radio-wild"],
    #radio-trainers:checked ~ .nav label[for="radio-trainers"],
    #radio-bosses:checked ~ .nav label[for="radio-bosses"] { background: #3498db; font-weight: bold; }
    
    #radio-wild:checked ~ #wild-view,
    #radio-trainers:checked ~ #trainers-view,
    #radio-bosses:checked ~ #bosses-view { display: block; }

    .subtab-radio { display: none; }
    .sub-nav { display: flex; justify-content: center; gap: 10px; margin-bottom: 15px; background: #e2e8f0; padding: 8px; border-radius: 8px; }
    .sub-nav label { padding: 8px 16px; font-size: 13px; cursor: pointer; background: #cbd5e1; color: #334155; border-radius: 6px; font-weight: 600; transition: 0.2s; }
    
    #radio-wild-route:checked ~ .sub-nav label[for="radio-wild-route"],
    #radio-wild-pokemon:checked ~ .sub-nav label[for="radio-wild-pokemon"] { background: #27ae60; color: white; }
    
    #radio-wild-route:checked ~ #wild-route-view,
    #radio-wild-pokemon:checked ~ #wild-pokemon-view { display: block; }
    .sub-tab-content { display: none; }

    .search-container { margin-bottom: 15px; text-align: center; }
    .search-input { width: 100%; max-width: 400px; padding: 10px 14px; font-size: 0.95em; border: 2px solid #cbd5e1; border-radius: 8px; outline: none; transition: 0.2s; }
    .search-input:focus { border-color: #3498db; }

    .card { background: white; padding: 15px; margin-bottom: 20px; border-radius: 12px; box-shadow: 0 4px 6px rgba(0,0,0,0.05); border-left: 6px solid #3498db; }
    .card h3 { margin-top: 0; border-bottom: 2px solid #eee; padding-bottom: 8px; text-transform: capitalize; font-size: 1.2em; color: #2c3e50; }
    
    /* Responsive Pokémon Grid - Max 3 columns on wide screens */
    .mon-grid { display: grid; grid-template-columns: repeat(auto-fill, minmax(300px, 1fr)); gap: 10px; }
    @media (min-width: 992px) {
        .mon-grid { grid-template-columns: repeat(3, 1fr); }
    }

    .mon-row { display: flex; background: white; border: 1px solid #eee; padding: 10px; border-radius: 8px; align-items: center; }
    .mon-img { width: 32px; height: 32px; margin-right: 10px; flex-shrink: 0; }
    .boss-row .mon-img { width: 80px; height: 80px; }
    .mon-data { flex: 1; font-size: 0.9em; overflow: hidden; }
    .mon-header { display: flex; justify-content: space-between; font-weight: bold; }
    .move-list { margin: 5px 0 0 0; padding-left: 15px; columns: 2; font-size: 0.85em; color: #444; list-style-type: disc; }
    .rate-tag { float: right; color: #3498db; font-weight: bold; font-size: 0.9em; }
    .section-title { font-size: 1.8em; margin: 30px 0 15px 0; color: #2c3e50; text-align: center; border-bottom: 4px solid #3498db; padding-bottom: 5px; }

    .rod-subheading { font-weight: bold; font-size: 0.85em; color: #00695c; margin: 10px 0 4px 0; padding-bottom: 2px; border-bottom: 1px solid #e0f2f1; text-transform: uppercase; letter-spacing: 0.5px; }
    .rod-subheading:first-child { margin-top: 0; }

    .pkmn-grid { display: grid; grid-template-columns: repeat(auto-fill, minmax(320px, 1fr)); gap: 15px; }
    .pkmn-card { background: white; border-radius: 10px; padding: 12px; border: 1px solid #e2e8f0; box-shadow: 0 2px 4px rgba(0,0,0,0.04); }
    .pkmn-header { display: flex; align-items: center; gap: 10px; border-bottom: 1px solid #f1f5f9; padding-bottom: 8px; margin-bottom: 8px; }
    .pkmn-header img { width: 36px; height: 36px; }
    .pkmn-title { font-weight: bold; color: #1e293b; font-size: 1.05em; }
    .pkmn-count { font-size: 0.75em; color: #64748b; background: #f1f5f9; padding: 2px 6px; border-radius: 4px; margin-left: auto; }
    
    .enc-table { width: 100%; border-collapse: collapse; font-size: 0.82em; }
    .enc-table th { text-align: left; background: #f8fafc; color: #64748b; padding: 5px 6px; font-weight: 600; }
    .enc-table td { padding: 6px; border-top: 1px solid #f1f5f9; }
    
    .badge { display: inline-block; padding: 2px 6px; border-radius: 4px; font-size: 0.78em; font-weight: 600; }
    .badge-land { background: #e8f5e9; color: #2e7d32; }
    .badge-water { background: #e3f2fd; color: #1565c0; }
    .badge-fishing { background: #e0f2f1; color: #00695c; }
    .badge-rock { background: #fff8e1; color: #f57f17; }
    
    /* Dark Mode Theme */
    body.dark-mode { background: #121212; color: #e0e0e0; }
    body.dark-mode .nav { background: #1f1f1f; }
    body.dark-mode .nav label { background: #2d2d2d; color: #bbb; }
    body.dark-mode .sub-nav { background: #1e293b; }
    body.dark-mode .sub-nav label { background: #334155; color: #cbd5e1; }
    body.dark-mode .card, body.dark-mode .pkmn-card, body.dark-mode .mon-row { background: #1e1e1e; color: #e0e0e0; border-color: #333; }
    body.dark-mode .card h3, body.dark-mode .section-title { color: #64b5f6; border-bottom-color: #333; }
    body.dark-mode .pkmn-title { color: #e0e0e0; }
    body.dark-mode .search-input { background: #2d2d2d; color: #fff; border-color: #444; }
    body.dark-mode .enc-table th { background: #252525; color: #aaa; }
    body.dark-mode .enc-table td { border-top-color: #333; }
    body.dark-mode .pkmn-count { background: #2a2a2a; color: #aaa; }
    body.dark-mode div[style*="background:#f9f9f9"] { background: #282828 !important; }
    
    /* Dark Mode Toggle Switch */
    .theme-switch-wrapper { display: flex; align-items: center; position: absolute; right: 40px; top: 50%; transform: translateY(-50%); }
    .theme-switch { display: inline-block; height: 9px; position: relative; width: 18px; }
    .theme-switch input { display: none; }
    .slider { background-color: #ccc; bottom: 0; cursor: pointer; left: 0; position: absolute; right: 0; top: 0; transition: .3s; border-radius: 18px; }
    .slider:before { background-color: #fff; bottom: 0; content: ""; height: 18px; left: 0; height: 100%; aspect-ratio: 1/1; position: absolute; transition: .3s; width: auto; border-radius: 50%; box-shadow: 0 1px 3px rgba(0,0,0,0.3); }
    input:checked + .slider { background-color: #3498db; }
    input:checked + .slider:before { transform: translateX(calc(100% - 4px)); }

    @media (max-width: 600px) {
        .nav label { font-size: 12px; padding: 8px 10px; }
        .mon-grid, .pkmn-grid { grid-template-columns: 1fr; }
    }
    </style>
    <script>
    function filterRoutes() {
        var input = document.getElementById('route-search').value.toLowerCase();
        var cards = document.querySelectorAll('.route-card');
        cards.forEach(function(card) {
            var name = card.getAttribute('data-name') || '';
            card.style.display = name.includes(input) ? '' : 'none';
        });
    }

    function filterPokemon() {
        var input = document.getElementById('pkmn-search').value.toLowerCase();
        var cards = document.querySelectorAll('.pkmn-card');
        cards.forEach(function(card) {
            var name = card.getAttribute('data-name') || '';
            card.style.display = name.includes(input) ? '' : 'none';
        });
    }

    function toggleDarkMode() {
        var isDark = document.getElementById('theme-toggle').checked;
        document.body.classList.toggle('dark-mode', isDark);
        localStorage.setItem('theme', isDark ? 'dark' : 'light');
    }

    window.addEventListener('DOMContentLoaded', function() {
        if (localStorage.getItem('theme') === 'dark') {
            document.body.classList.add('dark-mode');
            var toggle = document.getElementById('theme-toggle');
            if (toggle) toggle.checked = true;
        }
    });
    </script>
    </head><body>

    <input type="radio" name="tabs" id="radio-wild" class="tab-radio" checked>
    <input type="radio" name="tabs" id="radio-trainers" class="tab-radio">
    <input type="radio" name="tabs" id="radio-bosses" class="tab-radio">

    <div class="nav">
        <label for="radio-wild">Wild Encounters</label>
        <label for="radio-trainers">Trainers</label>
        <label for="radio-bosses">Bosses</label>
        
        <div class="theme-switch-wrapper">
            <span style="color: #fff; font-size: 12px; margin-right: 8px;">🌙</span>
            <label class="theme-switch" for="theme-toggle">
                <input type="checkbox" id="theme-toggle" onchange="toggleDarkMode()">
                <span class="slider"></span>
            </label>
        </div>
    </div>

    <div id="wild-view" class="tab-content">
        <input type="radio" name="wild_subtabs" id="radio-wild-route" class="subtab-radio" checked>
        <input type="radio" name="wild_subtabs" id="radio-wild-pokemon" class="subtab-radio">

        <div class="sub-nav">
            <label for="radio-wild-route">🗺️️ Route View</label>
            <label for="radio-wild-pokemon">🐾 Pokémon View</label>
        </div>

        <div id="wild-route-view" class="sub-tab-content">
            <div class="search-container">
                <input type="text" id="route-search" class="search-input" placeholder="Search route or location name..." onkeyup="filterRoutes()">
            </div>"""

    for r in route_cards_data:
        map_name = r['map_name']
        html += f'<div class="card route-card" data-name="{map_name.lower()}"><h3>{map_name}</h3><div style="display: flex; gap: 10px; flex-wrap: wrap;">'
        for method_key, method_title in [
            ('Land', 'LAND'),
            ('Water', 'WATER'),
            ('Fishing', 'FISHING'),
            ('Rock Smash', 'ROCK SMASH'),
        ]:
            if method_key in r['methods']:
                html += f'<div style="flex: 1; min-width: 220px;"><h4>{method_title}</h4>'
                if method_key == 'Fishing':
                    for rod_name, mons in r['methods']['Fishing'].items():
                        if mons:
                            html += f'<div class="rod-subheading">🎣 {rod_name}</div>'
                            for m in mons:
                                species = m['species']
                                rate_str = f"{m['rate']}%" if m['rate'] > 0 else ''
                                html += f"""<div style="display:flex; align-items:center; margin-bottom:6px; background:#f9f9f9; padding:6px; border-radius:6px;">
                                    <img src="{get_sprite_url(species)}" style="width:32px;">
                                    <div style="flex-grow: 1; font-size:0.8em; margin-left:8px;"><b>{species}</b><br><small>{m['level_str']}</small></div>
                                    <div class="rate-tag">{rate_str}</div>
                                </div>"""
                else:
                    for m in r['methods'][method_key]:
                        species = m['species']
                        rate_str = f"{m['rate']}%" if m['rate'] > 0 else ''
                        html += f"""<div style="display:flex; align-items:center; margin-bottom:6px; background:#f9f9f9; padding:6px; border-radius:6px;">
                            <img src="{get_sprite_url(species)}" style="width:32px;">
                            <div style="flex-grow: 1; font-size:0.8em; margin-left:8px;"><b>{species}</b><br><small>{m['level_str']}</small></div>
                            <div class="rate-tag">{rate_str}</div>
                        </div>"""
                html += '</div>'
        html += '</div></div>'

    html += """</div>

        <div id="wild-pokemon-view" class="sub-tab-content">
            <div class="search-container">
                <input type="text" id="pkmn-search" class="search-input" placeholder="Search Pokémon by name..." onkeyup="filterPokemon()">
            </div>
            <div class="pkmn-grid">"""

    all_species_set = set(pokedex_species_list)

    def get_sort_key(species_name):
        return pokedex_order.get(species_name.lower().strip(), 99999)

    sorted_species = sorted(all_species_set, key=lambda s: (get_sort_key(s), s))

    base_grouped_encounters = defaultdict(lambda: defaultdict(list))
    for spec, encs in pokemon_encounters.items():
        base = get_base_species_name(spec)
        base_grouped_encounters[base][spec].extend(encs)

    for base_species in sorted_species:
        forms_dict = base_grouped_encounters.get(base_species, {})
        
        # Calculate total unique locations across all forms
        total_locs = sum(len(enc_list) for enc_list in forms_dict.values())
        header_sprite = get_sprite_url(base_species)
        
        # added to fix Farfetch'd display name issue
        display_name = base_species.replace("Farfetch'D", "Farfetch'd")

        html += f"""<div class="pkmn-card" data-name="{base_species.lower()}">
            <div class="pkmn-header">
                <img src="{header_sprite}" alt="{base_species}">
                <span class="pkmn-title">{display_name}</span>
                <span class="pkmn-count">{total_locs} Location{'s' if total_locs != 1 else ''}</span>
            </div>"""

        if forms_dict:
            # If more than 1 form exists, display subheaders
            has_multiple_forms = len(forms_dict) > 1

            for form_name, enc_list in forms_dict.items():
                if has_multiple_forms:
                    form_sublabel = form_name.replace(base_species, '').strip()
                    if not form_sublabel:
                        form_sublabel = "Standard"
                    html += f"""<div style="margin: 10px 0 4px 0; font-weight:bold; font-size:0.85em; color:#3498db; border-bottom: 1px solid #e2e8f0; padding-bottom: 2px;">
                        <span>{form_sublabel} Form</span>
                    </div>"""

                html += """<table class="enc-table">
                    <thead>
                        <tr><th>Location</th><th>Method</th><th>Level</th><th>Rate</th></tr>
                    </thead>
                    <tbody>"""

                for enc in enc_list:
                    m_type = enc['method']
                    badge_class = 'badge-land'
                    if 'Water' in m_type:
                        badge_class = 'badge-water'
                    elif 'Rod' in m_type or 'Fishing' in m_type:
                        badge_class = 'badge-fishing'
                    elif 'Rock' in m_type:
                        badge_class = 'badge-rock'

                    min_lvl = enc['min_level']
                    max_lvl = enc['max_level']
                    lvl_str = f'Lv.{min_lvl}' if min_lvl == max_lvl else f'Lv.{min_lvl}-{max_lvl}'

                    html += f"""<tr>
                        <td><b>{enc['map_name']}</b></td>
                        <td><span class="badge {badge_class}">{m_type}</span></td>
                        <td>{lvl_str}</td>
                        <td><b style="color:#3498db;">{enc['rate']}%</b></td>
                    </tr>"""
                html += '</tbody></table>'
        else:
            html += """<table class="enc-table">
                <tbody>
                    <tr>
                        <td colspan="4" style="text-align:center; color:#94a3b8; padding: 10px;">None (Not found in the wild)</td>
                    </tr>
                </tbody>
            </table>"""

        html += '</div>'

    html += """</div></div></div>"""

    def create_detailed_card(t, use_gen5=False):
        party_html = '<div class="mon-grid">'
        row_class = 'boss-row' if use_gen5 else 'standard-row'
        for p in t['party']:
            sprite_url = get_sprite_url(p['species'], p['is_shiny'], use_icon=(not use_gen5))
            moves = ''.join([f'<li>{m}</li>' for m in p['moves']])
            held_item = p.get('item', 'None')
            iv_display = p.get('ivs', '31/31/31/31/31/31')
            
            # Colored gender display
            gender_str = ""
            if p.get('gender') == '♂':
                gender_str = ' <span style="color: #2980b9; font-weight: bold;">♂</span>'
            elif p.get('gender') == '♀':
                gender_str = ' <span style="color: #e84393; font-weight: bold;">♀</span>'

            party_html += f"""<div class="mon-row {row_class}">
                <img class="mon-img" src="{sprite_url}">
                <div class="mon-data">
                    <div class="mon-header"><span>{p['species']}{gender_str}</span> <span>Lv.{p['level']}</span></div>
                    <div style="color: #666; font-size: 0.9em;"><b>{p['nature']}</b> | {p['ability']}</div>
                    <div style="color: #2c3e50; font-size: 0.85em; margin-top: 2px;"><b>Item:</b> {held_item}</div>
                    <div style="color: #7f8c8d; font-size: 0.8em; margin-top: 1px;"><b>IVs:</b> {iv_display}</div>
                    <ul class="move-list">{moves}</ul>
                </div>
            </div>"""
        party_html += '</div>'
        return f'<div class="card"><h3>{t.get("class","Trainer")} {t.get("name","Unknown")}</h3>{party_html}</div>'

    html += '<div id="trainers-view" class="tab-content">'
    for tid, t in trainers_dict.items():
        if tid not in CURRENT_LEAGUE_IDS + GYM_LEADER_IDS + FORMER_LEAGUE_IDS:
            html += create_detailed_card(t, use_gen5=False)
    html += '</div>'

    html += '<div id="bosses-view" class="tab-content">'
    for title, id_list in [
        ('Gym Leaders', GYM_LEADER_IDS),
        ('Current Elite Four', CURRENT_LEAGUE_IDS),
        ('Former League', FORMER_LEAGUE_IDS),
    ]:
        html += f'<div class="section-title">{title}</div>'
        for tid in id_list:
            if tid in trainers_dict:
                html += create_detailed_card(trainers_dict[tid], use_gen5=True)
    html += '</div></body></html>'

    with open(OUTPUT_HTML, 'w', encoding='utf-8') as f:
        f.write(html)
    print('Master Guide Generated!')

if __name__ == '__main__':
    generate_master_guide()