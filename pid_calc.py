def find_shiny_nature_pid(ot_id, secret_id, target_nature):
    """
    Finds a Gen 3/4 PID that satisfies both Shininess and a Target Nature.
    
    Natures:
    0: Hardy      5: Bold        10: Timid     15: Modest    20: Quiet
    1: Lonely     6: Docile      11: Hasty     16: Mild      21: Bashful
    2: Brave      7: Relaxed     12: Serious   17: Rash      22: Rash
    3: Adamant    8: Impish      13: Jolly     18: Calm      23: Careful
    4: Naughty    9: Lax         14: Naive     19: Gentle    24: Quirky
    """
    threshold = 128 # This number should match Shiny Odds in include/constants/pokemon.h
    target_xor = ot_id ^ secret_id
    
    print(f"Searching for PID... (OT: {ot_id}, SID: {secret_id}, Target Nature: {target_nature})")
    print(f"Using Custom Shiny Threshold (< {threshold})")
    print("-" * 50)
    
    matches = []
    
    # Iterate through possible high and low 16-bit combinations
    for pid_high in range(0x10000):
        # Calculate what pid_low needs to be to satisfy the shiny XOR condition
        # (pid_high ^ pid_low) ^ target_xor < threshold
        # Therefore, (pid_high ^ target_xor) gives the base pid_low
        base_low = pid_high ^ target_xor
        
        # Check the window allowed by the shiny threshold
        for offset in range(threshold):
            pid_low = base_low ^ offset
            
            if pid_low >= 0x10000:
                continue
                
            # Combine into the full 32-bit PID
            pid = (pid_high << 16) | pid_low
            
            # Verify Nature
            if pid % 25 == target_nature:
                matches.append(pid)
                if len(matches) >= 5:  # Break early once we have a few options
                    break
        if len(matches) >= 5:
            break

    if not matches:
        print("No exact match found with these parameters.")
        return

    print(f"Found {len(matches)} valid PIDs:")
    for match in matches:
        p_high = match >> 16
        p_low = match & 0xFFFF
        actual_xor = (p_high ^ p_low) ^ target_xor
        print(f"  Hex: 0x{match:08X} | Decimal: {match} | XOR Result: {actual_xor} (< {threshold})")

# ==========================================
# INPUT YOUR DATA HERE
# ==========================================
# For in-game NPC trades, Secret ID usually defaults to 0
OT_ID = 51423
SECRET_ID = 0
TARGET_NATURE = 15

find_shiny_nature_pid(OT_ID, SECRET_ID, TARGET_NATURE)
