import requests
import json
import time

# Maps PokeAPI names to your internal SPECIES_ constants for perfect matching
NAME_TO_CONSTANT = {
    "nidoran-f": "NIDORAN_F",
    "nidoran-m": "NIDORAN_M",
    "farfetchd": "FARFETCHD",
    "mr-mime": "MR_MIME",
    "mime-jr": "MIME_JR",
    "porygon2": "PORYGON2",
    "porygon-z": "PORYGON_Z",
    "deoxys-normal": "DEOXYS",
}

def update_vanilla_library():
    vanilla_library = {}
    print("Building Vanilla Library (Gen 1-9)...")

    # Fetching 1025 species
    for i in range(1, 1026):
        try:
            response = requests.get(f"https://pokeapi.co/api/v2/pokemon/{i}")
            if response.status_code == 200:
                data = response.json()
                api_name = data['name']
                
                # Use the map if it exists, otherwise clean the API name
                const_name = NAME_TO_CONSTANT.get(api_name, api_name.replace("-", "_").upper())
                
                stats = data['stats']
                vanilla_library[f"SPECIES_{const_name}"] = {
                    "hp": stats[0]['base_stat'],
                    "at": stats[1]['base_stat'],
                    "de": stats[2]['base_stat'],
                    "sa": stats[3]['base_stat'],
                    "sd": stats[4]['base_stat'],
                    "sp": stats[5]['base_stat']
                }
            if i % 100 == 0: print(f"Synced {i} Pokémon...")
            time.sleep(0.02)
        except Exception as e:
            print(f"Error on ID {i}: {e}")

    with open('vanilla_library.json', 'w') as f:
        json.dump(vanilla_library, f, indent=4)
    print("Success! 'vanilla_library.json' created.")

if __name__ == "__main__":
    update_vanilla_library()
