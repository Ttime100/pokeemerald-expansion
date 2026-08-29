# This script compares the list of 600 Pokemon
# in my custom Pokedex against the Pokemon used in a trainers.party file
# to find which Pokemon are missing from the trainers' rosters.

import re
import os

# Get the directory where compare_rosters.py is currently located
script_dir = os.path.dirname(os.path.abspath(__file__))

# Build absolute paths to the text files in that same directory
trainers_file = os.path.join(script_dir, "trainers.party")
pokemon_list_file = os.path.join(script_dir, "custom_pokedex_list.txt")

# 1. Load the 600 Pokemon list
with open(pokemon_list_file, 'r', encoding='utf-8') as f:
    pokedex = set(line.strip().upper() for line in f if line.strip())

# 2. Read the trainers.party file
with open(trainers_file, 'r', encoding='utf-8') as f:
    trainers_content = f.read()

# 3. Find all Pokemon used in the trainers file
used_pokemon = set()

# Sort by longest first to safely check prefixes (prevents Porygon matching Porygon-Z)
sorted_pokedex = sorted(pokedex, key=len, reverse=True)

for word in re.findall(r"[A-Za-z0-9_'-]+", trainers_content):
    clean_word = word.replace("SPECIES_", "").upper()
    
    # 1. Check for exact match
    if clean_word in pokedex:
        used_pokemon.add(clean_word)
        continue
        
    # 2. Check for form variants or hyphen differences
    for p in sorted_pokedex:
        safe_p = p.replace("-", "_") # Treats hyphens like underscores for Ho-Oh, Porygon-Z, etc.
        
        # Match hyphen-to-underscore differences directly
        if clean_word == safe_p:
            used_pokemon.add(p)
            break
            
        # Match forms (e.g. BASCULIN_RED_STRIPED matches BASCULIN)
        if clean_word.startswith(safe_p + "_"):
            used_pokemon.add(p)
            break

# 4. Find the difference
missing_pokemon = pokedex - used_pokemon

# 5. Define Legendaries and Mythicals (Gen 1-5)
legendaries = {
    "ARTICUNO", "ZAPDOS", "MOLTRES", "MEWTWO", "MEW",
    "RAIKOU", "ENTEI", "SUICUNE", "LUGIA", "HO-OH", "CELEBI",
    "REGIROCK", "REGICE", "REGISTEEL", "LATIAS", "LATIOS", "KYOGRE", 
    "GROUDON", "RAYQUAZA", "JIRACHI", "DEOXYS", 
    "ROTOM", "DIALGA", "PALKIA", "HEATRAN", "REGIGIGAS", "GIRATINA", 
    "CRESSELIA", "PHIONE", "MANAPHY", "DARKRAI", "SHAYMIN", "ARCEUS",
    "VICTINI", "TORNADUS", "THUNDURUS", "RESHIRAM", "ZEKROM", "LANDORUS", 
    "KYUREM", "GENESECT", "MELTAN", "MELMETAL"
}

missing_legends = [p for p in missing_pokemon if p in legendaries]
missing_regular = [p for p in missing_pokemon if p not in legendaries]

# 6. Output the results
print(f"Total Pokemon in your list: {len(pokedex)}")
print(f"Total unique Pokemon used by trainers: {len(used_pokemon)}")
print(f"Total missing: {len(missing_pokemon)}\n")

print(f"--- MISSING LEGENDARIES & MYTHICALS ({len(missing_legends)}) ---")
for p in sorted(missing_legends):
    print(p.title())

print(f"\n--- MISSING REGULAR POKEMON ({len(missing_regular)}) ---")
for p in sorted(missing_regular):
    print(p.title())
