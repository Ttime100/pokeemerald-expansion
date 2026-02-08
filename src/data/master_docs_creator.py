import json
import re

# ==========================================
# CONFIGURATION SECTION
# ==========================================
WILD_JSON_PATH = 'src/data/wild_encounters.json'
TRAINER_PARTY_PATH = 'src/data/trainers.party'
OUTPUT_HTML = 'Master_Strategy_Guide.html'

CURRENT_LEAGUE_IDS = ['TRAINER_ELITE_FOUR_PARTH', 'TRAINER_ELITE_FOUR_AUSTIN', 'TRAINER_ELITE_FOUR_ROB', 'TRAINER_ELITE_FOUR_TYLER', 'TRAINER_WALLACE']
GYM_LEADER_IDS = ['TRAINER_ROXANNE_1', 'TRAINER_BRAWLY_1', 'TRAINER_WATTSON_1', 'TRAINER_FLANNERY_1', 'TRAINER_NORMAN_1', 'TRAINER_WINONA_1', 'TRAINER_TATE_AND_LIZA_1', 'TRAINER_JUAN_1']
FORMER_LEAGUE_IDS = ['TRAINER_SIDNEY', 'TRAINER_PHOEBE', 'TRAINER_GLACIA', 'TRAINER_DRAKE']

LAND_RATES = [20, 20, 10, 10, 10, 10, 5, 5, 4, 4, 1, 1]
WATER_RATES = [60, 30, 5, 4, 1]
FISHING_RATES = [70, 30, 60, 20, 20, 40, 40, 15, 4, 1]
ROCK_RATES = [60, 30, 5, 4, 1]

# ==========================================

def clean_comments(text):
    text = re.sub(r'/\*[\s\S]*?\*/', '', text)
    text = re.sub(r'//.*', '', text)
    return text

def get_sprite_url(species_name, is_shiny=False, use_icon=True):
    name_clean = species_name.lower().replace("_", "-").replace(" ", "-")
    if "shellos" in name_clean: name_clean = "shellos"
    if "gastrodon" in name_clean: name_clean = "gastrodon"
    
    if use_icon:
        prefix = "shiny" if is_shiny else "sun-moon"
        return f"https://img.pokemondb.net/sprites/{prefix}/icon/{name_clean}.png"
    else:
        folder = "shiny" if is_shiny else "normal"
        return f"https://img.pokemondb.net/sprites/black-white/{folder}/{name_clean}.png"

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
                first_line, item_part = first_line.split("@", 1)
                item = item_part.strip().replace("ITEM_", "").title()
            gender = ""
            if "(M)" in first_line: gender = "♂"
            elif "(F)" in first_line: gender = "♀"
            clean_name = first_line.replace("(M)", "").replace("(F)", "").strip()
            paren_match = re.search(r'\(([^)]+)\)', clean_name)
            species = paren_match.group(1) if paren_match else clean_name
            species = species.replace("SPECIES_", "").strip().replace("_", " ").title()
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
        with open(WILD_JSON_PATH, 'r') as f: wild_data = json.load(f)
    except: wild_data = {'wild_encounter_groups': []}
    trainers_dict = parse_trainers(TRAINER_PARTY_PATH)

    html = """<!DOCTYPE html><html><head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
    body { font-family: 'Segoe UI', Tahoma, sans-serif; background: #f0f2f5; margin: 0; color: #333; overflow-x: hidden; }
    
    /* CSS TAB LOGIC - NO JS */
    .tab-radio { display: none; }
    .nav { background: #2c3e50; padding: 12px; position: sticky; top: 0; text-align: center; z-index: 1000; display: flex; justify-content: center; gap: 8px; }
    .nav label { padding: 10px 15px; font-size: 14px; cursor: pointer; background: #34495e; color: white; border-radius: 6px; transition: 0.2s; -webkit-tap-highlight-color: transparent; }
    
    .tab-content { display: none; padding: 15px; max-width: 1400px; margin: auto; }
    
    #radio-wild:checked ~ .nav label[for="radio-wild"],
    #radio-trainers:checked ~ .nav label[for="radio-trainers"],
    #radio-bosses:checked ~ .nav label[for="radio-bosses"] { background: #3498db; font-weight: bold; }
    
    #radio-wild:checked ~ #wild-view,
    #radio-trainers:checked ~ #trainers-view,
    #radio-bosses:checked ~ #bosses-view { display: block; }

    /* Layout */
    .card { background: white; padding: 15px; margin-bottom: 20px; border-radius: 12px; box-shadow: 0 4px 6px rgba(0,0,0,0.05); border-left: 6px solid #3498db; }
    .card h3 { margin-top: 0; border-bottom: 2px solid #eee; padding-bottom: 8px; text-transform: capitalize; font-size: 1.2em; }
    .mon-grid { display: grid; grid-template-columns: repeat(auto-fill, minmax(280px, 1fr)); gap: 10px; }
    .mon-row { display: flex; background: white; border: 1px solid #eee; padding: 10px; border-radius: 8px; align-items: center; }
    .mon-img { width: 32px; height: 32px; margin-right: 10px; flex-shrink: 0; }
    .boss-row .mon-img { width: 64px; height: 64px; }
    .mon-data { flex: 1; font-size: 0.85em; overflow: hidden; }
    .mon-header { display: flex; justify-content: space-between; font-weight: bold; }
    .move-list { margin: 5px 0 0 0; padding-left: 15px; columns: 2; font-size: 0.8em; color: #444; list-style-type: disc; }
    .rate-tag { float: right; color: #3498db; font-weight: bold; font-size: 0.9em; }
    .section-title { font-size: 1.8em; margin: 30px 0 15px 0; color: #2c3e50; text-align: center; border-bottom: 4px solid #3498db; padding-bottom: 5px; }
    
    @media (max-width: 600px) {
        .nav label { font-size: 12px; padding: 8px 10px; }
        .mon-grid { grid-template-columns: 1fr; }
    }
    </style></head><body>

    <input type="radio" name="tabs" id="radio-wild" class="tab-radio" checked>
    <input type="radio" name="tabs" id="radio-trainers" class="tab-radio">
    <input type="radio" name="tabs" id="radio-bosses" class="tab-radio">

    <div class="nav">
        <label for="radio-wild">Wild</label>
        <label for="radio-trainers">Trainers</label>
        <label for="radio-bosses">Bosses</label>
    </div>

    <div id="wild-view" class="tab-content">"""
    
    for group in wild_data.get('wild_encounter_groups', []):
        for enc in group['encounters']:
            map_name = enc['base_label'].replace('g', '').replace('_', ' ')
            html += f'<div class="card"><h3>{map_name}</h3><div style="display: flex; gap: 10px; flex-wrap: wrap;">'
            for e_type in ['land_mons', 'water_mons', 'fishing_mons', 'rock_smash_mons']:
                if e_type in enc:
                    html += f'<div style="flex: 1; min-width: 220px;"><h4>{e_type.replace("_mons","").upper()}</h4>'
                    rate_list = LAND_RATES if e_type == 'land_mons' else WATER_RATES if e_type == 'water_mons' else FISHING_RATES if e_type == 'fishing_mons' else ROCK_RATES
                    for i, m in enumerate(enc[e_type]['mons']):
                        species = m['species'].replace('SPECIES_', '').replace('_', ' ').title()
                        rate = f"{rate_list[i]}%" if i < len(rate_list) else ""
                        html += f'''<div style="display:flex; align-items:center; margin-bottom:6px; background:#f9f9f9; padding:6px; border-radius:6px;">
                            <img src="{get_sprite_url(species)}" style="width:32px;">
                            <div style="flex-grow: 1; font-size:0.8em; margin-left:8px;"><b>{species}</b><br><small>Lv.{m['min_level']}</small></div>
                            <div class="rate-tag">{rate}</div>
                        </div>'''
                    html += "</div>"
            html += "</div></div>"
    html += "</div>"

    def create_detailed_card(t, use_gen5=False):
        party_html = '<div class="mon-grid">'
        row_class = "boss-row" if use_gen5 else "standard-row"
        for p in t['party']:
            sprite_url = get_sprite_url(p['species'], p['is_shiny'], use_icon=(not use_gen5))
            moves = "".join([f"<li>{m}</li>" for m in p['moves']])
            party_html += f'''<div class="mon-row {row_class}">
                <img class="mon-img" src="{sprite_url}">
                <div class="mon-data">
                    <div class="mon-header"><span>{p['species']}</span> <span>Lv.{p['level']}</span></div>
                    <div style="color: #666; font-size: 0.9em;"><b>{p['nature']}</b> | {p['ability']}</div>
                    <ul class="move-list">{moves}</ul>
                </div>
            </div>'''
        party_html += "</div>"
        return f'<div class="card"><h3>{t.get("class","Trainer")} {t.get("name","Unknown")}</h3>{party_html}</div>'

    html += '<div id="trainers-view" class="tab-content">'
    for tid, t in trainers_dict.items():
        if tid not in CURRENT_LEAGUE_IDS + GYM_LEADER_IDS + FORMER_LEAGUE_IDS:
            html += create_detailed_card(t, use_gen5=False)
    html += "</div>"

    html += '<div id="bosses-view" class="tab-content">'
    for title, id_list in [("Gym Leaders", GYM_LEADER_IDS), ("Current Elite Four", CURRENT_LEAGUE_IDS), ("Former League", FORMER_LEAGUE_IDS)]:
        html += f'<div class="section-title">{title}</div>'
        for tid in id_list:
            if tid in trainers_dict: html += create_detailed_card(trainers_dict[tid], use_gen5=True)
    html += "</div></body></html>"

    with open(OUTPUT_HTML, 'w', encoding='utf-8') as f: f.write(html)
    print("Mobile-Ready Master Guide Generated!")

if __name__ == "__main__":
    generate_master_guide()
    