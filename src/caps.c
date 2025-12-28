#include "global.h"
#include "battle.h"
#include "event_data.h"
#include "caps.h"
#include "pokemon.h"

static const u32 sLevelCapFlagMap[][2] =
{
    {FLAG_BADGE01_GET, 15},
    {FLAG_RUSTUNGRUNT, 17},
    {FLAG_BADGE02_GET, 24},
    {FLAG_MUSEUMGRUNT, 27},
    {FLAG_RIVAL3_BEAT, 30},
    {FLAG_BADGE03_GET, 34},
    {FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, 42},
    {FLAG_BADGE04_GET, 45},
    {FLAG_BADGE05_GET, 48},
    {FLAG_HIDE_ROUTE_119_TEAM_AQUA, 53}, // Triggers after defeating Shelly in Weather Institute
    {FLAG_BADGE06_GET, 56},
    {FLAG_RECEIVED_RED_OR_BLUE_ORB, 63}, // Triggers after defeating Aqua at Mt Pyre
    {FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, 68}, // Triggers after defeating Magma Hideout
    {FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, 71}, // Triggers after defeating Aqua Admin Matt
    {FLAG_BADGE07_GET, 77},
    {FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA, 80},
    {FLAG_BADGE08_GET, 85},
    {FLAG_IS_CHAMPION, 95},
};

u32 GetCurrentLevelCap(void)
{
    u32 i;

    if (B_LEVEL_CAP_TYPE == LEVEL_CAP_FLAG_LIST)
    {
        for (i = 0; i < ARRAY_COUNT(sLevelCapFlagMap); i++)
        {
            if (!FlagGet(sLevelCapFlagMap[i][0]))
                return sLevelCapFlagMap[i][1];
        }
    }
    else if (B_LEVEL_CAP_TYPE == LEVEL_CAP_VARIABLE)
    {
        return VarGet(B_LEVEL_CAP_VARIABLE);
    }

    return MAX_LEVEL;
}

u32 GetSoftLevelCapExpValue(u32 level, u32 expValue)
{
    static const u32 sExpScalingDown[5] = { 4, 8, 16, 32, 64 };
    static const u32 sExpScalingUp[5]   = { 16, 8, 4, 2, 1 };

    u32 levelDifference;
    u32 currentLevelCap = GetCurrentLevelCap();

    if (B_EXP_CAP_TYPE == EXP_CAP_NONE)
        return expValue;

    if (level < currentLevelCap)
    {
        if (B_LEVEL_CAP_EXP_UP)
        {
            levelDifference = currentLevelCap - level;
            if (levelDifference > ARRAY_COUNT(sExpScalingUp) - 1)
                return expValue + (expValue / sExpScalingUp[ARRAY_COUNT(sExpScalingUp) - 1]);
            else
                return expValue + (expValue / sExpScalingUp[levelDifference]);
        }
        else
        {
            return expValue;
        }
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_HARD)
    {
        return 0;
    }
    else if (B_EXP_CAP_TYPE == EXP_CAP_SOFT)
    {
        levelDifference = level - currentLevelCap;
        if (levelDifference > ARRAY_COUNT(sExpScalingDown) - 1)
            return expValue / sExpScalingDown[ARRAY_COUNT(sExpScalingDown) - 1];
        else
            return expValue / sExpScalingDown[levelDifference];
    }
    else
    {
       return expValue;
    }
}

u32 GetCurrentEVCap(void)
{
    static const u16 sEvCapFlagMap[][2] = {
        // Define EV caps for each milestone
        {FLAG_BADGE01_GET, MAX_TOTAL_EVS *  1 / 17},
        {FLAG_BADGE02_GET, MAX_TOTAL_EVS *  3 / 17},
        {FLAG_BADGE03_GET, MAX_TOTAL_EVS *  5 / 17},
        {FLAG_BADGE04_GET, MAX_TOTAL_EVS *  7 / 17},
        {FLAG_BADGE05_GET, MAX_TOTAL_EVS *  9 / 17},
        {FLAG_BADGE06_GET, MAX_TOTAL_EVS * 11 / 17},
        {FLAG_BADGE07_GET, MAX_TOTAL_EVS * 13 / 17},
        {FLAG_BADGE08_GET, MAX_TOTAL_EVS * 15 / 17},
        {FLAG_IS_CHAMPION, MAX_TOTAL_EVS},
    };

    if (B_EV_CAP_TYPE == EV_CAP_FLAG_LIST)
    {
        for (u32 evCap = 0; evCap < ARRAY_COUNT(sEvCapFlagMap); evCap++)
        {
            if (!FlagGet(sEvCapFlagMap[evCap][0]))
                return sEvCapFlagMap[evCap][1];
        }
    }
    else if (B_EV_CAP_TYPE == EV_CAP_VARIABLE)
    {
        return VarGet(B_EV_CAP_VARIABLE);
    }
    else if (B_EV_CAP_TYPE == EV_CAP_NO_GAIN)
    {
        return 0;
    }

    return MAX_TOTAL_EVS;
}

u32 GetPreviousLevelCap(void)
{
    u32 i;
    u32 currentCap = GetCurrentLevelCap();

    for (i = 0; i < ARRAY_COUNT(sLevelCapFlagMap); i++)
    {
        // [i][0] is the Flag ID, [i][1] is the Level
        if (!FlagGet(sLevelCapFlagMap[i][0]))
        {
            if (i == 0) return currentCap;
            FlagClear(sLevelCapFlagMap[i - 1][0]);
            u32 prevCap = GetCurrentLevelCap();
            FlagSet(sLevelCapFlagMap[i - 1][0]);

            return prevCap;
        }
    }
    FlagClear(sLevelCapFlagMap[ARRAY_COUNT(sLevelCapFlagMap) - 1][0]);
    u32 lastCap = GetCurrentLevelCap();
    FlagSet(sLevelCapFlagMap[ARRAY_COUNT(sLevelCapFlagMap) - 1][0]);

    return lastCap;
}
