import json
import os
import re
import base64
from collections import defaultdict

# ==========================================
# CONFIGURATION SECTION
# ==========================================
WILD_JSON_PATH = 'src/data/wild_encounters.json'
TRAINER_PARTY_PATH = 'src/data/trainers.party'
POKEDEX_LIST_PATH = 'src/data/custom_pokedex_list.txt'
MAPS_DIR_PATH = "data/maps"
SPECIES_INFO_DIR = 'src/data/pokemon/species_info/'
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

STORY_ORDER = [
    "LittlerootTown",
    "Route101",
    "OldaleTown",
    "Route102",
    "Route104South",
    "PetalburgWoods",
    "Route104North",
    "RustboroCity",
    "Route116",
    "RusturfTunnel",
    "DewfordTown",
    "GraniteCave",
    "Route109",
    "SlateportCity",
    "Route110",
    "Route110_TrickHousePuzzle1",
    "Route110_TrickHousePuzzle2",
    "Route110_TrickHousePuzzle3",
    "Route110_TrickHousePuzzle4",
    "Route110_TrickHousePuzzle5",
    "Route110_TrickHousePuzzle6",
    "Route110_TrickHousePuzzle7",
    "Route110_TrickHousePuzzle8",
    "Route103",
    "MauvilleCity",
    "MauvilleCity_Gym",
    "NewMauville",
    "Route117",
    "VerdanturfTown",
    "Route111",
    "MirageTower",
    "Route112",
    "FieryPath",
    "Route113",
    "FallarborTown",
    "Route114",
    "MeteorFalls",
    "Route115",
    "MtChimney",
    "JaggedPass",
    "LavaridgeTown",
    "PetalburgCity",
    "Route118",
    "Route119",
    "Route119_WeatherInstitute",
    "FortreeCity",
    "Route120",
    "Route121",
    "Route122",
    "MtPyre_1F",
    "MtPyre_2F",
    "MtPyre_3F",
    "MtPyre_4F",
    "MtPyre_5F",
    "MtPyre_6F",
    "MtPyre_Exterior",
    "MtPyre_Summit",
    "Route123",
    "LilycoveCity",
    "MagmaHideout",
    "AquaHideout",
    "Route124",
    "Underwater_Route124",
    "MossdeepCity",
    "MossdeepCity_Gym",
    "MossdeepCity_SpaceCenter",
    "Route125",
    "ShoalCave",
    "Starfall_Glacier",
    "Route126",
    "Underwater_Route126",
    "Route127",
    "Underwater_Route127",
    "Route128",
    "SeafloorCavern",
    "SootopolisCity",
    "CaveOfOrigin",
    "Route129",
    "Route130",
    "Route131",
    "PacifidlogTown",
    "SkyPillar",
    "Route132",
    "Route133",
    "Route134",
    "ObsidianShores",
    "Shadespur_Isle",
    "Umbra_Inlet",
    "EverGrandeCity",
    "VictoryRoad_1F",
    "VictoryRoad_B1F",
    "VictoryRoad_B2F",
    "Route105",
    "Route106",
    "Route107",
    "Route108",
    "AbandonedShip",
    "SafariZone",
]

WILD_ORDER_OVERRIDES = {
    'Route103': 3,
    'PetalburgCity': 3,
}

NON_TRAINER_FLAGS = {
    'TRAINER_BATTLE_TOWER_ON',
    'TRAINER_HILL_IS_ACTIVE',
    'TRAINER_TOWER',
    'TRAINER_TOWER_LOBBY',
}

LOCATION_OVERRIDES = {
    'TRAINER_BILLY': 'Route104South',
    'TRAINER_DARIAN': 'Route104South',
    'TRAINER_CINDY_1': 'Route104South',

    'TRAINER_WINSTON_1': 'Route104North',
    'TRAINER_HALEY_1': 'Route104North',
    'TRAINER_GINA_AND_MIA_1': 'Route104North',
    'TRAINER_IVAN': 'Route104North',
    'TRAINER_BRENDAN_RUSTBORO_MUDKIP': 'Route104North',
    'TRAINER_BRENDAN_RUSTBORO_TREECKO': 'Route104North',
    'TRAINER_BRENDAN_RUSTBORO_TORCHIC': 'Route104North',
    'TRAINER_MAY_RUSTBORO_MUDKIP': 'Route104North',
    'TRAINER_MAY_RUSTBORO_TREECKO': 'Route104North',
    'TRAINER_MAY_RUSTBORO_TORCHIC': 'Route104North',
}

# ==========================================

def is_ignored_entry(entry: dict) -> bool:
    base_label = entry.get("base_label", "")
    map_name = entry.get("map", "")

    if base_label == "gRoute104" or map_name == "MAP_ROUTE104":
        return True
    
    ignored_keywords = (
        "FireRed", "LeafGreen", "FIRERED", "LEAFGREEN",
        "UnusedRubySapphire", "UNUSED_RUBY_SAPPHIRE",
        "BattlePyramid", "BattlePike",
        "BATTLE_PYRAMID", "BATTLE_PIKE"
    )
    return any(kw in base_label for kw in ignored_keywords) or any(kw in map_name for kw in ignored_keywords)

def get_base_species_name(species_name: str) -> str:
    if not species_name:
        return ""
    name_clean = species_name.strip()
    multi_form_bases = [
        'Burmy', 'Wormadam', 'Shellos', 'Gastrodon', 'Basculin', 
        'Deoxys', 'Giratina', 'Shaymin', 'Rotom', 'Castform', 
        'Cherrim', 'Arceus', 'Darmanitan', 'Meloetta'
    ]
    for base in multi_form_bases:
        if name_clean.lower().startswith(base.lower()):
            return base
    return name_clean

def format_display_name(name: str) -> str:
    if not name:
        return ""
    clean = str(name).replace("SPECIES_", "").replace("_", " ").strip()
    lower_clean = clean.lower()
    if "farfetch" in lower_clean:
        return clean.title().replace("Farfetchd", "Farfetch'd").replace("Farfetch'D", "Farfetch'd")
    if lower_clean == "mr mime":
        return "Mr. Mime"
    if lower_clean in ["mime jr", "mime jr."]:
        return "Mime Jr."
    if lower_clean in ["nidoran m", "nidoran_m", "nidoran♂"]:
        return "Nidoran♂"
    if lower_clean in ["nidoran f", "nidoran_f", "nidoran♀"]:
        return "Nidoran♀"
    return clean.title()

def clean_comments(text):
    text = re.sub(r'/\*[\s\S]*?\*/', '', text)
    text = re.sub(r'//.*', '', text)
    return text
    
    return replacements.get(clean, clean)

def load_pokedex_order(path):
    pokedex_order = {}
    pokedex_species_list = []
    try:
        with open(path, 'r', encoding='utf-8') as f:
            index = 0
            for line in f:
                line = line.strip()
                if line:
                    clean_name = format_display_name(line)
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
    label = re.sub(r'\bSS\b', 'S.S. ', label)
    label = label.replace('Route104South', 'Route 104 (South)')
    label = label.replace('Route104North', 'Route 104 (North)')
    label = re.sub(r'\bSS([A-Z])', r'S.S. \1', label)
    label = re.sub(r'([a-z])([A-Z])', r'\1 \2', label)
    label = re.sub(r'([a-zA-Z])(\d)', r'\1 \2', label)
    label = re.sub(r'\bB\s+(\d+\s*F)\b', r'B\1', label, flags=re.IGNORECASE)
    label = re.sub(r'\bMt\b', 'Mt.', label)
    return label.strip()

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
            ev_yields.append(f"{resolved_val} {clean_stat}")
    
    ev_yield_list = ev_yields if ev_yields else ["None"]
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
        "ev_yield": ev_yield_list,
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

def format_stat_cell(stat_name, new_val_str, vanilla_stats):
    try:
        new_val = int(new_val_str)
    except ValueError:
        return f"<b>{new_val_str}</b>" if stat_name == 'hp' else new_val_str

    stat_map = {
        'hp': 'hp',
        'atk': 'at',
        'def': 'de',
        'spa': 'sa',
        'spd': 'sd',
        'spe': 'sp'
    }
    json_key = stat_map.get(stat_name, stat_name)

    vanilla_val = None
    if vanilla_stats and json_key in vanilla_stats:
        try:
            vanilla_val = int(vanilla_stats[json_key])
        except (ValueError, TypeError):
            pass

    prefix = "<b>" if stat_name == 'hp' else ""
    suffix = "</b>" if stat_name == 'hp' else ""

    if vanilla_val is not None and new_val != vanilla_val:
        diff = new_val - vanilla_val
        cls = "stat-buff" if diff > 0 else "stat-nerf"
        diff_str = f"+{diff}" if diff > 0 else str(diff)
        return f'<span class="{cls}">{prefix}{new_val}{suffix}</span><span class="stat-note {cls}">({diff_str})</span>'
    else:
        return f'{prefix}{new_val}{suffix}'

def get_pokedex_data():
    custom_list_path = 'src/data/custom_pokedex_list.txt'
    ordered_constants = []
    dex_numbers = {}
    vanilla_path = 'src/data/vanilla_library.json'
    vanilla_db = {}
    
    if os.path.exists(vanilla_path):
        with open(vanilla_path, 'r', encoding='utf-8') as f:
            raw_vanilla = json.load(f)
            vanilla_db = {k.upper(): v for k, v in raw_vanilla.items()}

    def get_vanilla_stats(form_key, base_id):
        keys_to_try = [
            form_key,
            f"SPECIES_{form_key}",
            base_id,
            f"SPECIES_{base_id}",
            base_id.split('_')[0],
            f"SPECIES_{base_id.split('_')[0]}",
            form_key.split('_')[0],
            f"SPECIES_{form_key.split('_')[0]}"
        ]
        for k in keys_to_try:
            k_upper = k.upper()
            if k_upper in vanilla_db:
                return vanilla_db[k_upper]
        return None
    
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
            form_data["vanilla_stats"] = get_vanilla_stats(target_key, const)
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
                for sub_k, sub_v in sub_forms.items(): # <--- LOOP TO ATTACH VANILLA STATS
                    fd = sub_v.copy()
                    fd["vanilla_stats"] = get_vanilla_stats(sub_k, const)
                    forms[sub_k] = fd
            
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
            species = format_display_name(species)
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

def consolidate_rival_trainers(trainers_list):

    consolidated = []
    seen_ids = set()

    for t in trainers_list:
        tid = t['id']
        if tid in seen_ids:
            continue
        if 'TRAINER_MAY_' in tid or 'TRAINER_BRENDAN_' in tid:
            counterpart_id = tid.replace('TRAINER_MAY_', 'TRAINER_BRENDAN_') if 'TRAINER_MAY_' in tid else tid.replace('TRAINER_BRENDAN_', 'TRAINER_MAY_')
            counterpart = next((other for other in trainers_list if other['id'] == counterpart_id), None)
            if counterpart:
                seen_ids.add(tid)
                seen_ids.add(counterpart_id)
                rival_card = dict(t)
                rival_card['class'] = 'Rival'
                rival_card['name'] = ''
                if 'TREECKO' in tid:
                    rival_card['class'] = 'Rival (Treecko Starter)'
                elif 'TORCHIC' in tid:
                    rival_card['class'] = 'Rival (Torchic Starter)'
                elif 'MUDKIP' in tid:
                    rival_card['class'] = 'Rival (Mudkip Starter)'
                consolidated.append(rival_card)
                continue
        seen_ids.add(tid)
        consolidated.append(t)

    return consolidated

def build_trainer_location_map(maps_directory="data/maps"):
    trainer_locations = {}
    if not os.path.exists(maps_directory):
        print(f"Warning: Maps directory not found at {maps_directory}")
        return trainer_locations
    # 1. Loop through every folder inside data/maps
    for map_name in os.listdir(maps_directory):
        if "_Frlg" in map_name or "FIRERED" in map_name.upper() or "LEAFGREEN" in map_name.upper():
            continue
        normalized_map = normalize_map_name(map_name)
        map_path = os.path.join(maps_directory, map_name)
        
        if os.path.isdir(map_path):
            # 2. Check for Poryscript or standard script files
            script_path_pory = os.path.join(map_path, "scripts.pory")
            script_path_inc = os.path.join(map_path, "scripts.inc")
            
            target_script = None
            if os.path.exists(script_path_pory):
                target_script = script_path_pory
            elif os.path.exists(script_path_inc):
                target_script = script_path_inc
                
            if target_script:
                with open(target_script, "r", encoding="utf-8") as f:
                    content = f.read()
                    
                    # 3. Search for any word starting with TRAINER_ followed by uppercase letters/numbers/underscores
                    # This captures things like TRAINER_GRUNT_PETALBURG_WOODS
                    found_trainers = re.findall(r'(TRAINER_[A-Z0-9_]+)', content)
                    
                    # 4. Map each found trainer to this map folder
                    for trainer_id in found_trainers:
                        if trainer_id in NON_TRAINER_FLAGS:
                            continue
                        if 'LOCATION_OVERRIDES' in globals() and trainer_id in LOCATION_OVERRIDES:
                            trainer_locations[trainer_id] = LOCATION_OVERRIDES[trainer_id]
                        else:
                            trainer_locations[trainer_id] = normalized_map
                        
    return trainer_locations

def group_trainers_by_location(trainers_data, maps_directory="data/maps"):
    trainer_locations = build_trainer_location_map(MAPS_DIR_PATH)
    trainers_by_map = {}
    for trainer in trainers_data:
        trainer_id = trainer.get("id")
        if trainer_id in LOCATION_OVERRIDES:
            map_name = LOCATION_OVERRIDES[trainer_id]
        if trainer_id in trainer_locations:
            map_name = trainer_locations[trainer_id]
            if map_name not in trainers_by_map:
                trainers_by_map[map_name] = []     
            trainers_by_map[map_name].append(trainer)
        else:
            # The trainer was in trainers.party but not found in any map script.
            # These are rematches, Battle Frontier teams, or unused trainers.
            pass        
    return trainers_by_map

def normalize_map_name(map_name: str) -> str:
    if map_name.startswith('SSTidal'):
        return 'SSTidal'
    if map_name.startswith('LavaridgeTown_Gym'):
        return 'LavaridgeTown_Gym'
    if map_name.startswith('TrainerHill'):
        return 'TrainerHill'
    return map_name

def check_duplicate_trainer_locations(maps_directory="data/maps"):
    trainer_to_maps = defaultdict(set)
    if not os.path.exists(maps_directory):
        return
    for map_name in os.listdir(maps_directory):
        if "_Frlg" in map_name or "FIRERED" in map_name.upper() or "LEAFGREEN" in map_name.upper():
            continue
        normalized_map = normalize_map_name(map_name)
        map_path = os.path.join(maps_directory, map_name)
        if os.path.isdir(map_path):
            for script_file in ("scripts.pory", "scripts.inc"):
                script_path = os.path.join(map_path, script_file)
                if os.path.exists(script_path):
                    with open(script_path, "r", encoding="utf-8") as f:
                        content = clean_comments(f.read())
                        found_trainers = re.findall(r'(TRAINER_[A-Z0-9_]+)', content)
                        for trainer_id in found_trainers:
                            if trainer_id in NON_TRAINER_FLAGS:
                                continue
                            trainer_to_maps[trainer_id].add(normalized_map)
    duplicates = {t_id: maps for t_id, maps in trainer_to_maps.items() if len(maps) > 1}
    print("\n================ TRAINER LOCATION DUPLICATES ================")
    if not duplicates:
        print("No duplicate trainer IDs found across map files!")
    else:
        for t_id, maps in sorted(duplicates.items()):
            maps_str = ", ".join(sorted(maps))
            print(f"⚠️  {t_id} found in: {maps_str}")
    print("============================================================\n")

def generate_master_guide():
    try:
        with open(WILD_JSON_PATH, 'r', encoding='utf-8') as f:
            wild_data = json.load(f)
    except Exception:
        wild_data = {'wild_encounter_groups': []}

    trainers_dict = parse_trainers(TRAINER_PARTY_PATH)
    grouped_trainers = group_trainers_by_location(trainers_dict.values(), MAPS_DIR_PATH)
    pokedex_order, pokedex_species_list = load_pokedex_order(POKEDEX_LIST_PATH)
    pokedex_data = get_pokedex_data()
    type_colors = {"Normal": "#A8A77A", "Fire": "#EE8130", "Water": "#6390F0", "Electric": "#F7D02C", "Grass": "#7AC74C", "Ice": "#96D9D6", "Fighting": "#C22E28", "Poison": "#A33EA1", "Ground": "#E2BF65", "Flying": "#A98FF3", "Psychic": "#F95587", "Bug": "#A6B91A", "Rock": "#B6A136", "Ghost": "#735797", "Dragon": "#6F35FC", "Steel": "#B7B7CE", "Dark": "#705746", "Fairy": "#D685AD"}

    pokemon_encounters = defaultdict(list)
    route_cards_data = []

    check_duplicate_trainer_locations(MAPS_DIR_PATH)

    for group in wild_data.get('wild_encounter_groups', []):
        for enc in group.get('encounters', []):
            if is_ignored_entry(enc):
                continue
            raw_label = enc.get('base_label', enc.get('map', ''))
            map_name = format_map_name(raw_label)
            route_info = {'map_name': map_name,'raw_label': raw_label, 'methods': {}}

            def get_wild_story_rank(raw_label):
                if not raw_label:
                    return 9999
                clean = raw_label[1:] if raw_label.startswith('g') else raw_label
                clean = re.sub(r'_(Land|Water|Fishing|RockSmash)Mons$', '', clean)
                if clean in WILD_ORDER_OVERRIDES:
                    return WILD_ORDER_OVERRIDES[clean]

                if clean in STORY_ORDER:
                    return STORY_ORDER.index(clean)
                for idx, story_map in enumerate(STORY_ORDER):
                    if clean.startswith(story_map):
                        return idx
                return 9999

            route_cards_data.sort(key=lambda r: get_wild_story_rank(r.get('raw_label', '')))

            for r in route_cards_data:
                map_name = r['map_name']

            def process_slice(sub_method_name, mons_slice, rates_slice):
                mons_data = []
                species_agg = {}
                for i, m in enumerate(mons_slice):
                    species = format_display_name(m['species'])
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
    .nav { background: #2c3e50; padding: 10px 20px; position: sticky; top: 0; z-index: 1000; display: grid; grid-template-columns: 220px 1fr 220px; align-items: center; }
    .nav label { padding: 10px 18px; font-size: 14px; cursor: pointer; background: #34495e; color: white; border-radius: 6px; transition: 0.2s; -webkit-tap-highlight-color: transparent; }
    .nav-tabs { display: flex; justify-content: center; gap: 8px; margin: auto;}
   .tab-content { display: none; padding: 15px; max-width: 1400px; margin: auto; }
    
    #radio-pokedex:checked ~ .nav label[for="radio-pokedex"] { background: #3498db; font-weight: bold; }
    #radio-wild:checked ~ .nav label[for="radio-wild"],
    #radio-trainers:checked ~ .nav label[for="radio-trainers"],
    #radio-bosses:checked ~ .nav label[for="radio-bosses"] { background: #3498db; font-weight: bold; }
    
    #radio-pokedex:checked ~ #pokedex-view { display: block; }
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

    .search-container { margin-bottom: 15px; text-align: center; position: sticky; top: 52px;background: #f0f2f5;padding: 10px 0; z-index: 950; max-width: 400px; margin-left: auto; margin-right: auto; }
    .search-input { width: 100%; max-width: 400px; padding: 10px 14px; font-size: 0.95em; border: 2px solid #cbd5e1; border-radius: 8px; outline: none; transition: 0.2s; }
    .search-input:focus { border-color: #3498db; }

    .card { background: white; padding: 15px; margin-bottom: 20px; border-radius: 12px; box-shadow: 0 4px 6px rgba(0,0,0,0.05); border-left: 6px solid #3498db; }
    .card h3 { margin-top: 0; border-bottom: 2px solid #eee; padding-bottom: 8px; text-transform: capitalize; font-size: 1.2em; color: #2c3e50; }
    
    #pokedex-view {
    max-width: 100% !important;
    box-sizing: border-box;
    padding-top: 0px;
    padding-left: 20px;
    padding-right: 20px;
    }

    table.pokedex-table {
        margin-left: auto;
        margin-right: auto;
    }

    /* Responsive Pokémon Grid - Max 3 columns on wide screens */
    .mon-grid { display: grid; grid-template-columns: repeat(auto-fill, minmax(300px, 1fr)); gap: 10px; }
    @media (min-width: 992px) {
        .mon-grid { grid-template-columns: repeat(3, 1fr); }
    }

    .mon-row { display: flex; background: white; border: 1px solid #eee; padding: 10px; border-radius: 8px; align-items: center; }
    .mon-img { width: 32px; height: 32px; margin-right: 10px; flex-shrink: 0; }
    .boss-row .mon-img { width: 64px; height: 64px; }
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

    /* Master Pokedex Styles & Stat Deltas */
    table.pokedex-table { width: 100%; border-collapse: collapse; background: white; box-shadow: 0 4px 6px rgba(0,0,0,0.1); }
    table.pokedex-table thead th { background: #34495e; color: white; padding: 12px; position: sticky; top: 50px; z-index: 900; font-size: 1.1em; border-bottom: 2px solid #2c3e50; }
    table.pokedex-table td { padding: 10px; border-bottom: 1px solid #eee; text-align: center; font-size: 0.9em; }
    table.pokedex-table td[class^="s-"] { position: relative; vertical-align: middle; font-size: 1.15em; font-weight: bold; font-family: monospace; }
    
    .stat-buff { color: #27ae60; font-weight: bold; }
    .stat-nerf { color: #c0392b; font-weight: bold; }
    .stat-note { 
        font-size: 10px; 
        font-weight: bold; 
        position: absolute; 
        top: 50%; 
        left: 0; 
        right: 0; 
        transform: translateY(6px); 
        text-align: center; 
        line-height: 1; 
    }
    
    .pk-img { width: 64px; height: 64px; image-rendering: pixelated; object-fit: contain; }
    .type-pill { display: inline-block; padding: 4px 6px; border-radius: 4px; color: white; font-size: 11px; font-weight: bold; text-transform: uppercase; margin: 2px; min-width: 72px; text-align: center; box-sizing: border-box; }
    .ab-row { display: block; font-size: 12px; color: #2980b9; font-weight: bold; margin-bottom: 2px; }
    .ev-row { display: block; font-size: 12px; color: #2c3e50; font-weight: bold; line-height: 1.3; }
    .form-btn { background: #ecf0f1; border: 1px solid #bdc3c7; padding: 5px 8px; margin: 2px; border-radius: 4px; cursor: pointer; font-weight: bold; font-size: 10px; }
    .form-btn:hover { background: #3498db; color: white; }
    .gender-male { color: #3498db; font-weight: bold; font-size: 0.95em; }
    .gender-female { color: #e84393; font-weight: bold; font-size: 0.95em; }
    .gender-symbol { font-size: 1.3em; font-weight: 900; }
    .gender-none { color: #7f8c8d; font-style: italic; }
    .gender-row { line-height: 1.3; text-align: center; }
    
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
    body.dark-mode table.pokedex-table { background: #1e1e1e; color: #e0e0e0; border-color: #333; }
    body.dark-mode table.pokedex-table thead th { background: #252525; color: #aaa; }
    body.dark-mode table.pokedex-table td { border-bottom-color: #333; }
    body.dark-mode .form-btn { background: #2d2d2d; color: #fff; border-color: #444; }
    body.dark-mode .form-btn:hover { background: #3498db; }
    body.dark-mode .search-container { background: #121212; }
    
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

    function universalSearchFilter() {
        let input = document.getElementById("universal-search").value.toLowerCase();
        let clearBtn = document.getElementById("clearBtn");
        if (clearBtn) clearBtn.style.display = input ? "block" : "none";

        let isPokedexActive = document.getElementById("radio-pokedex").checked;
        let isWildActive = document.getElementById("radio-wild").checked;
        let isTrainersActive = document.getElementById("radio-trainers").checked;
        let isBossesActive = document.getElementById("radio-bosses").checked;

        if (isPokedexActive) {
            let rows = document.getElementsByClassName("pokemon-row");
            for (let i = 0; i < rows.length; i++) {
                rows[i].style.display = rows[i].innerText.toLowerCase().includes(input) ? "" : "none";
            }
        } 
        else if (isWildActive) {
            let isRouteView = document.getElementById("radio-wild-route").checked;
            if (isRouteView) {
                var cards = document.querySelectorAll('.route-card');
                cards.forEach(function(card) {
                    var name = card.getAttribute('data-name') || '';
                    card.style.display = name.includes(input) ? '' : 'none';
                });
            } else {
                var cards = document.querySelectorAll('.pkmn-card');
                cards.forEach(function(card) {
                    var name = card.getAttribute('data-name') || '';
                    card.style.display = name.includes(input) ? '' : 'none';
                });
            }
        }
        else if (isTrainersActive) {
            let cards = document.querySelectorAll('#trainers-view .card');
            cards.forEach(function(card) {
                card.style.display = card.innerText.toLowerCase().includes(input) ? '' : 'none';
            });
        }
        else if (isBossesActive) {
            let cards = document.querySelectorAll('#bosses-view .card');
            cards.forEach(function(card) {
                card.style.display = card.innerText.toLowerCase().includes(input) ? '' : 'none';
            });
        }
    }

    function clearUniversalSearch() { 
        document.getElementById("universal-search").value = ""; 
        universalSearchFilter(); 
    }

    function formatStatJS(statName, newValStr, vanillaStats) {
        let newVal = parseInt(newValStr);
        let vanillaVal = null;
        const statMap = {'hp': 'hp', 'atk': 'at', 'def': 'de', 'spa': 'sa', 'spd': 'sd', 'spe': 'sp'};
        let jsonKey = statMap[statName] || statName;
        if (vanillaStats && vanillaStats[jsonKey] !== undefined) {
            vanillaVal = parseInt(vanillaStats[jsonKey]);
        }
        let isHp = (statName === 'hp');
        let prefix = isHp ? '<b>' : '';
        let suffix = isHp ? '</b>' : '';
        if (!isNaN(newVal) && vanillaVal !== null && !isNaN(vanillaVal) && newVal !== vanillaVal) {
            let diff = newVal - vanillaVal;
            let cls = diff > 0 ? 'stat-buff' : 'stat-nerf';
            let diffStr = diff > 0 ? '+' + diff : diff;
            return `<span class="${cls}">${prefix}${newVal}${suffix}</span><span class="stat-note ${cls}">(${diffStr})</span>`;
        } else {
            return `${prefix}${newVal}${suffix}`;
        }
    }
    const typeColors = """ + json.dumps(type_colors) + """;
    function formatGenderJS(genderStr) {
        if (!genderStr || genderStr.includes("Genderless") || genderStr.includes("255")) {
            return '<span class="gender-none">Genderless</span>';
        }
        if (genderStr.includes("♂") && genderStr.includes("♀")) {
            let parts = genderStr.split('/');
            let m_pct = parts[0].replace('♂', '').trim();
            let f_pct = parts[1].replace('♀', '').trim();
            return `<div class="gender-row"><span class="gender-male"><span class="gender-symbol">♂</span> ${m_pct}</span></div>` +
                   `<div class="gender-row"><span class="gender-female"><span class="gender-symbol">♀</span> ${f_pct}</span></div>`;
        } else if (genderStr.includes("♂")) {
            let m_pct = genderStr.replace('♂', '').trim();
            return `<div class="gender-row"><span class="gender-male"><span class="gender-symbol">♂</span> ${m_pct}</span></div>`;
        } else if (genderStr.includes("♀")) {
            let f_pct = genderStr.replace('♀', '').trim();
            return `<div class="gender-row"><span class="gender-female"><span class="gender-symbol">♀</span> ${f_pct}</span></div>`;
        }
        return genderStr;
    }

    function sw(rid, key, formsData) {
        const f = formsData[key];
        const ext = f.extras;
        document.getElementById('img-' + rid).src = f.img;
        document.getElementById('name-' + rid).innerText = f.name;
        document.getElementById('types-' + rid).innerHTML = f.types.map(t => `<span class="type-pill" style="background:${typeColors[t] || '#AAA'}">${t}</span> `).join('');
        document.getElementById('abils-' + rid).innerHTML = f.abilities.map(a => `<span class="ab-row">${a}</span>`).join('');
        document.getElementById('ev-' + rid).innerHTML = ext.ev_yield.map(e => `<span class="ev-row">${e}</span>`).join('');
        document.getElementById('catch-' + rid).innerText = ext.catch_rate;
        document.getElementById('friend-' + rid).innerText = ext.friendship;
        document.getElementById('growth-' + rid).innerText = ext.growth_rate;
        document.getElementById('egg-' + rid).innerText = ext.egg_groups;
        document.getElementById('gender-' + rid).innerHTML = formatGenderJS(ext.gender_ratio);

        let bst = 0;
        for (const [stat, value] of Object.entries(f.stats)) {
            const el = document.getElementById(stat + '-' + rid);
            if (el) {
                el.innerHTML = formatStatJS(stat, value, f.vanilla_stats);
                bst += parseInt(value) || 0;
            }
        }
        document.getElementById('bst-' + rid).innerHTML = `<b>${bst}</b>`;
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

    <input type="radio" name="tabs" id="radio-pokedex" class="tab-radio" checked>
    <input type="radio" name="tabs" id="radio-wild" class="tab-radio">
    <input type="radio" name="tabs" id="radio-trainers" class="tab-radio">
    <input type="radio" name="tabs" id="radio-bosses" class="tab-radio">

    <div class="nav">
        <div class="nav-search-container" style="position: relative; display: flex; align-items: center;">
            <input type="text" id="universal-search" class="search-input" onkeyup="universalSearchFilter()" placeholder="Search..." style="padding: 6px 10px; font-size: 0.85em; width: 180px; border-radius: 6px; border: 1px solid #475569; background: #334155; color: white;">
            <button id="clearBtn" onclick="clearUniversalSearch()" style="position: absolute; right: 22px; top: 50%; transform: translateY(-50%); background: transparent; color: #94a3b8; border: none; border-radius: 50%; width: 18px; height: 18px; cursor: pointer; display: none; font-size: 10px; font-weight: bold; padding: 0;">✕</button>
        </div>

        <div class="nav-tabs" style="display: flex; gap: 8px;">
            <label for="radio-pokedex">Pokedex</label>
            <label for="radio-wild">Wild Encounters</label>
            <label for="radio-trainers">Trainers</label>
            <label for="radio-bosses">Bosses</label>
        </div>
        
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

        <div id="wild-route-view" class="sub-tab-content">"""

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
                                species = format_display_name(m['species'])
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
        
        display_name = format_display_name(base_species)

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

    def create_detailed_card(t, use_sprite=False):
        party_html = '<div class="mon-grid">'
        row_class = 'boss-row' if use_sprite else 'standard-row'
        for p in t['party']:
            sprite_url = get_sprite_url(p['species'], p['is_shiny'], use_icon=(not use_sprite))
            moves = ''.join([f'<li>{m}</li>' for m in p['moves']])
            held_item = p.get('item', 'None')
            iv_display = p.get('ivs', '31/31/31/31/31/31')
            
            # Colored gender display
            gender_str = ""
            if p.get('gender') == '♂':
                gender_str = ' <span style="color: #2980b9; font-weight: bold;">♂</span>'
            elif p.get('gender') == '♀':
                gender_str = ' <span style="color: #e84393; font-weight: bold;">♀</span>'

            display_species_name = format_display_name(p['species'])

            party_html += f"""<div class="mon-row {row_class}">
                <img class="mon-img" src="{sprite_url}">
                <div class="mon-data">
                    <div class="mon-header"><span>{display_species_name}{gender_str}</span> <span>Lv.{p['level']}</span></div>
                    <div style="color: #666; font-size: 0.9em;"><b>{p['nature']}</b> | {p['ability']}</div>
                    <div style="color: #2c3e50; font-size: 0.85em; margin-top: 2px;"><b>Item:</b> {held_item}</div>
                    <div style="color: #7f8c8d; font-size: 0.8em; margin-top: 1px;"><b>IVs:</b> {iv_display}</div>
                    <ul class="move-list">{moves}</ul>
                </div>
            </div>"""
        party_html += '</div>'
        return f'<div class="card"><h3>{t.get("class","Trainer")} {t.get("name","Unknown")}</h3>{party_html}</div>'

    html += '<div id="trainers-view" class="tab-content">'
    def get_story_rank(map_folder):
        if map_folder in STORY_ORDER:
            return STORY_ORDER.index(map_folder)
        for idx, story_map in enumerate(STORY_ORDER):
            if map_folder.startswith(story_map):
                return idx
        return 9999
    map_keys = list(grouped_trainers.keys())
    sorted_map_keys = sorted(map_keys, key=get_story_rank)
    for map_folder in sorted_map_keys:
        map_trainer_list = grouped_trainers[map_folder]
        regular_trainers = [t for t in map_trainer_list if t['id'] not in CURRENT_LEAGUE_IDS + GYM_LEADER_IDS + FORMER_LEAGUE_IDS]
        regular_trainers = consolidate_rival_trainers(regular_trainers)
        if regular_trainers:
            display_map = format_map_name(map_folder)
            html += f'<div class="section-title"> {display_map}</div>'
            for t in regular_trainers:
                html += create_detailed_card(t, use_sprite=True)
                
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
                html += create_detailed_card(trainers_dict[tid], use_sprite=True)
    html += '</div></body></html>'

    html += '<div id="pokedex-view" class="tab-content">'
    html += '<table class="pokedex-table">'
    html += """<thead>
            <tr>
                <th>#</th><th>Sprite</th><th>Name</th><th>Type</th><th>Abilities</th>
                <th>EV Yield</th><th>Catch Rate</th><th>Base Friendship</th><th>Growth Rate</th><th>Egg Groups</th><th>Gender</th>
                <th>HP</th><th>Atk</th><th>Def</th><th>SpA</th><th>SpD</th><th>Spe</th><th>BST</th>
            </tr>
        </thead>
        <tbody>"""

    for entry in pokedex_data:
        base_id = entry['base']
        f = next(iter(entry['forms'].values()))
        rid = f"row-{base_id}"
        ext = f['extras']
        bst = sum(int(v) for v in f['stats'].values() if str(v).isdigit())
        f_btns = "".join([f'<button class="form-btn" onclick=\'sw("{rid}","{k}",{json.dumps(entry["forms"]).replace("\"", "&quot;")})\'>{k.replace(base_id + "_", "") if k != base_id else "BASE"}</button>' for k in entry['forms']]) if len(entry['forms']) > 1 else ""

        html += f"""<tr id="{rid}" class="pokemon-row">
            <td>#{str(entry['dex']).zfill(3)}</td>
            <td><img id="img-{rid}" src="{f['img']}" class="pk-img"></td>
            <td><b id="name-{rid}" style="font-size: 1.1em;">{f['name']}</b><br><div style="margin-top:6px;">{f_btns}</div></td>
            <td id="types-{rid}">{" ".join([f'<span class="type-pill" style="background:{type_colors.get(t,"#AAA")}">{t}</span>' for t in f['types']])}</td>
            <td id="abils-{rid}" style="min-width: 130px;">{" ".join([f'<span class="ab-row">{a}</span>' for a in f['abilities']])}</td>
            <td id="ev-{rid}" style="min-width: 100px;">{"".join([f'<span class="ev-row">{e}</span>' for e in ext['ev_yield']])}</td>
            <td id="catch-{rid}">{ext['catch_rate']}</td>
            <td id="friend-{rid}">{ext['friendship']}</td>
            <td id="growth-{rid}">{ext['growth_rate']}</td>
            <td id="egg-{rid}">{ext['egg_groups']}</td>
            <td id="gender-{rid}">{format_gender_html(ext['gender_ratio'])}</td>
            <td class="s-hp" id="hp-{rid}">{format_stat_cell('hp', f['stats']['hp'], f.get('vanilla_stats'))}</td>
            <td class="s-atk" id="atk-{rid}">{format_stat_cell('atk', f['stats']['atk'], f.get('vanilla_stats'))}</td>
            <td class="s-def" id="def-{rid}">{format_stat_cell('def', f['stats']['def'], f.get('vanilla_stats'))}</td>
            <td class="s-spa" id="spa-{rid}">{format_stat_cell('spa', f['stats']['spa'], f.get('vanilla_stats'))}</td>
            <td class="s-spd" id="spd-{rid}">{format_stat_cell('spd', f['stats']['spd'], f.get('vanilla_stats'))}</td>
            <td class="s-spe" id="spe-{rid}">{format_stat_cell('spe', f['stats']['spe'], f.get('vanilla_stats'))}</td>
            <td class="s-bst" id="bst-{rid}" style="color: #d35400;"><b>{bst}</b></td>
        </tr>"""

    html += "</tbody></table></div>"

    OUTPUT_HTML = "src/data/master_guide/Master_Strategy_Guide.html"

    with open(OUTPUT_HTML, 'w', encoding='utf-8') as f:
        f.write(html)
    print('Master Guide Generated!')

if __name__ == '__main__':
    generate_master_guide()