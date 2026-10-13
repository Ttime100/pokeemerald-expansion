import os
from PIL import Image

DECOMP_POKEMON_DIR = "/home/tyler/decomps/pokeemerald-expansion/graphics/pokemon/"
OUTPUT_DIR = "src/data/master_guide/images/pokemon/"

DEFAULT_FORMS = {
    "basculin": "red_striped",
    "burmy": "plant",
    "wormadam": "plant",
    "shellos": "west",
    "gastrodon": "west"
}

def normalize_name(name):
    return (name.lower()
            .replace('-', '_')
            .replace(' ', '_')
            .replace('(', '')
            .replace(')', '')
            .replace("'", '')
            .replace('.', ''))

def parse_jasc_pal(filepath):
    with open(filepath, 'r') as f:
        lines = [l.strip() for l in f.readlines()]
    
    colors = []
    for line in lines[3:19]: 
        r, g, b = map(int, line.split())
        colors.extend([r, g, b])
    return colors + [0] * (768 - len(colors))

def process_sprite(source_folder, output_prefix, out_folder):
    front_path = os.path.join(source_folder, "anim_front.png")
    if not os.path.exists(front_path):
        front_path = os.path.join(source_folder, "front.png")
        if not os.path.exists(front_path):
            return False
            
    img = Image.open(front_path).convert("P")
    
    if img.height > img.width:
        img = img.crop((0, 0, img.width, img.width))

    for pal_type in ["normal", "shiny"]:
        pal_path = os.path.join(source_folder, f"{pal_type}.pal")
        if os.path.exists(pal_path):
            pal_colors = parse_jasc_pal(pal_path)
            colored_img = img.copy()
            colored_img.putpalette(pal_colors)
            
            out_name = f"{output_prefix}_{pal_type}.png"
            colored_img.save(os.path.join(out_folder, out_name), transparency=0)

    icon_path = os.path.join(source_folder, "icon.png")
    if os.path.exists(icon_path):
        icon_img = Image.open(icon_path).convert("P")
        if icon_img.height > icon_img.width:
            icon_img = icon_img.crop((0, 0, icon_img.width, icon_img.width))
        elif icon_img.width > icon_img.height:
            icon_img = icon_img.crop((0, 0, icon_img.height, icon_img.height))
            
        icon_img.save(os.path.join(out_folder, f"{output_prefix}_icon.png"), transparency=0)

def main():
    os.makedirs(OUTPUT_DIR, exist_ok=True)
    
    for species in os.listdir(DECOMP_POKEMON_DIR):
        species_dir = os.path.join(DECOMP_POKEMON_DIR, species)
        
        if not os.path.isdir(species_dir):
            continue
            
        norm_species = normalize_name(species)
        process_sprite(species_dir, norm_species, OUTPUT_DIR)
        if norm_species in DEFAULT_FORMS:
            default_form_name = DEFAULT_FORMS[norm_species]
            explicit_prefix = f"{norm_species}_{default_form_name}"
            process_sprite(species_dir, explicit_prefix, OUTPUT_DIR)
        for sub_item in os.listdir(species_dir):
            sub_dir = os.path.join(species_dir, sub_item)
            if os.path.isdir(sub_dir):
                norm_sub = normalize_name(sub_item)
                form_prefix = f"{norm_species}_{norm_sub}"
                process_sprite(sub_dir, form_prefix, OUTPUT_DIR)
            
    print(f"✅ Successfully exported all web-ready sprites to {OUTPUT_DIR}")

if __name__ == "__main__":
    main()