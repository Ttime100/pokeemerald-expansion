#include "global.h"
#include "fossil_revival.h"
#include "item.h"
#include "string_util.h"
#include "constants/items.h"
#include "constants/species.h"
#include "script_menu.h"
#include "event_scripts.h"
#include "event_data.h"
#include "menu.h"

static const struct FossilRevival sFossilRevivalTable[] = {
    {ITEM_ROOT_FOSSIL,  SPECIES_LILEEP},
    {ITEM_CLAW_FOSSIL,  SPECIES_ANORITH},
    {ITEM_HELIX_FOSSIL, SPECIES_OMANYTE},
    {ITEM_DOME_FOSSIL,  SPECIES_KABUTO},
    {ITEM_OLD_AMBER,    SPECIES_AERODACTYL},
    {ITEM_ARMOR_FOSSIL, SPECIES_CRANIDOS},
    {ITEM_SKULL_FOSSIL, SPECIES_SHIELDON}
};

bool8 GetHasMultipleFossils(void)
{
    u32 i;
    u8 count = 0;
    for (i = 0; i < ARRAY_COUNT(sFossilRevivalTable); i++)
    {
        if (CheckBagHasItem(sFossilRevivalTable[i].fossilItemId, 1))
            count++;
    }
    return (count > 1);
}

u16 GetFossilItemId(void)
{
    u32 i;
    u16 speciesId = VarGet(VAR_TEMP_1);
    for (i = 0; i < ARRAY_COUNT(sFossilRevivalTable); i++)
    {
        if (sFossilRevivalTable[i].speciesId == speciesId)
            return sFossilRevivalTable[i].fossilItemId;
    }
    return ITEM_NONE;
}

u16 GetFossilItemIdFromIndex(void)
{
    if (gSpecialVar_Result >= ARRAY_COUNT(sFossilRevivalTable))
        return ITEM_NONE;

    return sFossilRevivalTable[gSpecialVar_Result].fossilItemId;
}

u16 GetSpeciesFromFossil(void)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sFossilRevivalTable); i++)
    {
        if (CheckBagHasItem(sFossilRevivalTable[i].fossilItemId, 1))
            return sFossilRevivalTable[i].speciesId;
    }
    return SPECIES_NONE;
}

u16 GetSpeciesFromFossilIndex(void)
{
    if (gSpecialVar_Result == 0x7F || gSpecialVar_Result >= ARRAY_COUNT(sFossilRevivalTable))
        return SPECIES_NONE;

    return sFossilRevivalTable[gSpecialVar_Result].speciesId;
}
