#include "global.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "battle_pyramid_bag.h"
#include "bg.h"
#include "debug.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_object_lock.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "field_weather.h"
#include "field_screen_effect.h"
#include "frontier_pass.h"
#include "frontier_util.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "l_menu.h"
#include "link.h"
#include "load_save.h"
#include "main.h"
#include "menu.h"
#include "new_game.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokemon_storage_system.h"
#include "pokenav.h"
#include "safari_zone.h"
#include "save.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_card.h"
#include "window.h"
#include "union_room.h"
//#include "dexnav.h"
#include "wild_encounter.h"
#include "constants/battle_frontier.h"
#include "constants/rgb.h"
#include "constants/songs.h"

void HealPlayerParty(void);

// Menu actions
enum
{
    MENU_ACTION_POKEVIAL,
    MENU_ACTION_PC_BOX,
    //MENU_ACTION_DEXNAV,
    MENU_ACTION_AUTO_RUN_ON,
    MENU_ACTION_AUTO_RUN_OFF,
    MENU_ACTION_EXIT,
};

// IWRAM common
bool8 (*gMenuCallback2)(void);

// EWRAM
EWRAM_DATA static u8 sLMenuCursorPos = 0;
EWRAM_DATA static u8 sNumLMenuActions = 0;
EWRAM_DATA static u8 sCurrentLMenuActions[9] = {0};
EWRAM_DATA static s8 sInitLMenuData[2] = {0};

// Menu action callbacks
static bool8 LMenuPokeVialCallback(void);
static bool8 LMenuPlayerNameCallback(void);
static bool8 LMenuExitCallback(void);
//static bool8 LMenuDexNavCallback(void);
static bool8 LMenuPCBoxCallback(void);
static bool8 LMenuAutoRunCallback(void);

// Menu callbacks
static bool8 HandleLMenuInput(void);

// Task callbacks
static void LMenuTask(u8 taskId);
static bool8 FieldCB_ReturnToFieldLMenu(void);

static const struct MenuAction sLMenuItems[] =
{
    [MENU_ACTION_POKEVIAL]    = {gText_MenuPokeVial, {.u8_void = LMenuPokeVialCallback}},
    [MENU_ACTION_PC_BOX]      = {gText_MenuPC,           {.u8_void = LMenuPCBoxCallback}},
    //[MENU_ACTION_DEXNAV]    = {gText_MenuDexNav,  {.u8_void = LMenuDexNavCallback}},
    [MENU_ACTION_AUTO_RUN_ON] = {gText_AutoRunOn,  {.u8_void = LMenuAutoRunCallback}},
    [MENU_ACTION_AUTO_RUN_OFF]= {gText_AutoRunOff,  {.u8_void = LMenuAutoRunCallback}},
    [MENU_ACTION_EXIT]        = {gText_MenuExit,    {.u8_void = LMenuExitCallback}},
};

// Local functions
static void BuildLMenuActions(void);
static void AddLMenuAction(u8 action);
static void BuildNormalLMenu(void);
static void BuildSafariZoneLMenu(void);
static void BuildLinkModeLMenu(void);
static void BuildUnionRoomLMenu(void);
static void BuildBattlePikeLMenu(void);
static void BuildBattlePyramidLMenu(void);
static void BuildMultiPartnerRoomLMenu(void);
static void BuildElite4LMenu(void);
static bool32 PrintLMenuActions(s8 *pIndex, u32 count);
static bool32 InitLMenuStep(void);
static void CreateLMenuTask(TaskFunc followupFunc);
static void HideLMenuWindow(void);
static void HideLMenuWindowAutoRun(void);


static void BuildLMenuActions(void)
{
    sNumLMenuActions = 0;

    if (IsOverworldLinkActive() == TRUE)
    {
        BuildLinkModeLMenu();
    }
    else if (InUnionRoom() == TRUE)
    {
        BuildUnionRoomLMenu();
    }
    else if (GetSafariZoneFlag() == TRUE)
    {
        BuildSafariZoneLMenu();
    }
    else if (InBattlePike())
    {
        BuildBattlePikeLMenu();
    }
    else if (InBattlePyramid_())
    {
        BuildBattlePyramidLMenu();
    }
    else if (InMultiPartnerRoom())
    {
        BuildMultiPartnerRoomLMenu();
    }
    else if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_EVER_GRANDE_CITY_SIDNEYS_ROOM) 
          || gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_EVER_GRANDE_CITY_PHOEBES_ROOM)
          || gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_EVER_GRANDE_CITY_GLACIAS_ROOM)
          || gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_EVER_GRANDE_CITY_DRAKES_ROOM)
          || gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_EVER_GRANDE_CITY_CHAMPIONS_ROOM)
          || gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_EVER_GRANDE_CITY_HALL1)
          || gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_EVER_GRANDE_CITY_HALL2)
          || gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_EVER_GRANDE_CITY_HALL3)
          || gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_EVER_GRANDE_CITY_HALL4)
          || gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_EVER_GRANDE_CITY_HALL5))
    {
        BuildElite4LMenu();
    }
    else
    {
        BuildNormalLMenu();
    }
}

static void AddLMenuAction(u8 action)
{
    AppendToLList(sCurrentLMenuActions, &sNumLMenuActions, action);
}

static void BuildNormalLMenu(void)
{
    if(FlagGet(FLAG_SYS_POKEMON_GET))
    {
        AddLMenuAction(MENU_ACTION_POKEVIAL);
        AddLMenuAction(MENU_ACTION_PC_BOX);
    }
    //if (FlagGet(FLAG_SYS_DEXNAV_GET))
    //{
    //    AddLMenuAction(MENU_ACTION_DEXNAV);
    //}
    if (FlagGet(FLAG_SYS_B_DASH))
    {
        if (gSaveBlock2Ptr->autoRun)
        {
            AddLMenuAction(MENU_ACTION_AUTO_RUN_ON);
        }
        else
        {
            AddLMenuAction(MENU_ACTION_AUTO_RUN_OFF);
        }
    }
    AddLMenuAction(MENU_ACTION_EXIT);
}

static void BuildSafariZoneLMenu(void)
{
    //if (FlagGet(FLAG_SYS_DEXNAV_GET))
    //{
    //    AddLMenuAction(MENU_ACTION_DEXNAV);
    //}
    if (FlagGet(FLAG_SYS_B_DASH))
    {
        if (gSaveBlock2Ptr->autoRun)
        {
            AddLMenuAction(MENU_ACTION_AUTO_RUN_ON);
        }
        else
        {
            AddLMenuAction(MENU_ACTION_AUTO_RUN_OFF);
        }
    }
    AddLMenuAction(MENU_ACTION_EXIT);
}

static void BuildLinkModeLMenu(void)
{
    if(FlagGet(FLAG_SYS_POKEMON_GET))
    {
        AddLMenuAction(MENU_ACTION_POKEVIAL);
    }
    //if (FlagGet(FLAG_SYS_DEXNAV_GET))
    //{
    //    AddLMenuAction(MENU_ACTION_DEXNAV);
    //}
    if (FlagGet(FLAG_SYS_B_DASH))
    {
        if (gSaveBlock2Ptr->autoRun)
        {
            AddLMenuAction(MENU_ACTION_AUTO_RUN_ON);
        }
        else
        {
            AddLMenuAction(MENU_ACTION_AUTO_RUN_OFF);
        }
    }
    AddLMenuAction(MENU_ACTION_EXIT);
}

static void BuildUnionRoomLMenu(void)
{
    if(FlagGet(FLAG_SYS_POKEMON_GET))
    {
        AddLMenuAction(MENU_ACTION_POKEVIAL);
    }
    //if (FlagGet(FLAG_SYS_DEXNAV_GET))
    //{
    //    AddLMenuAction(MENU_ACTION_DEXNAV);
    //}
    if (FlagGet(FLAG_SYS_B_DASH))
    {
        if (gSaveBlock2Ptr->autoRun)
        {
            AddLMenuAction(MENU_ACTION_AUTO_RUN_ON);
        }
        else
        {
            AddLMenuAction(MENU_ACTION_AUTO_RUN_OFF);
        }
    }
    AddLMenuAction(MENU_ACTION_EXIT);
}

static void BuildBattlePikeLMenu(void)
{
    //if (FlagGet(FLAG_SYS_DEXNAV_GET))
    //{
    //    AddLMenuAction(MENU_ACTION_DEXNAV);
    //}
    if (FlagGet(FLAG_SYS_B_DASH))
    {
        if (gSaveBlock2Ptr->autoRun)
        {
            AddLMenuAction(MENU_ACTION_AUTO_RUN_ON);
        }
        else
        {
            AddLMenuAction(MENU_ACTION_AUTO_RUN_OFF);
        }
    }
    AddLMenuAction(MENU_ACTION_EXIT);
}

static void BuildBattlePyramidLMenu(void)
{
    //if (FlagGet(FLAG_SYS_DEXNAV_GET))
    //{
    //    AddLMenuAction(MENU_ACTION_DEXNAV);
    //}
    if (FlagGet(FLAG_SYS_B_DASH))
    {
        if (gSaveBlock2Ptr->autoRun)
        {
            AddLMenuAction(MENU_ACTION_AUTO_RUN_ON);
        }
        else
        {
            AddLMenuAction(MENU_ACTION_AUTO_RUN_OFF);
        }
    }
    AddLMenuAction(MENU_ACTION_EXIT);
}

static void BuildMultiPartnerRoomLMenu(void)
{
    //if (FlagGet(FLAG_SYS_DEXNAV_GET))
    //{
    //    AddLMenuAction(MENU_ACTION_DEXNAV);
    //}
    if (FlagGet(FLAG_SYS_B_DASH))
    {
        if (gSaveBlock2Ptr->autoRun)
        {
            AddLMenuAction(MENU_ACTION_AUTO_RUN_ON);
        }
        else
        {
            AddLMenuAction(MENU_ACTION_AUTO_RUN_OFF);
        }
    }
    AddLMenuAction(MENU_ACTION_EXIT);
}

static void BuildElite4LMenu(void)
{
    if(FlagGet(FLAG_SYS_POKEMON_GET))
    {
        AddLMenuAction(MENU_ACTION_POKEVIAL);
    }
    
    if (FlagGet(FLAG_SYS_B_DASH))
    {
        if (gSaveBlock2Ptr->autoRun)
            AddLMenuAction(MENU_ACTION_AUTO_RUN_ON);
        else
            AddLMenuAction(MENU_ACTION_AUTO_RUN_OFF);
    }
    AddLMenuAction(MENU_ACTION_EXIT);
}

static bool32 PrintLMenuActions(s8 *pIndex, u32 count)
{
    s8 index = *pIndex;

    do
    {
        if (sLMenuItems[sCurrentLMenuActions[index]].func.u8_void == LMenuPlayerNameCallback)
        {
            PrintPlayerNameOnWindow(GetLMenuWindowId(), sLMenuItems[sCurrentLMenuActions[index]].text, 8, (index << 4) + 9);
        }
        else
        {
            StringExpandPlaceholders(gStringVar4, sLMenuItems[sCurrentLMenuActions[index]].text);
            AddTextPrinterParameterized(GetLMenuWindowId(), FONT_NORMAL, gStringVar4, 8, (index << 4) + 9, TEXT_SKIP_DRAW, NULL);
        }

        index++;
        if (index >= sNumLMenuActions)
        {
            *pIndex = index;
            return TRUE;
        }

        count--;
    }
    while (count != 0);

    *pIndex = index;
    return FALSE;
}

static bool32 InitLMenuStep(void)
{
    s8 state = sInitLMenuData[0];

    switch (state)
    {
    case 0:
        sInitLMenuData[0]++;
        break;
    case 1:
        BuildLMenuActions();
        sInitLMenuData[0]++;
        break;
    case 2:
        LoadMessageBoxAndBorderGfx();
        DrawStdWindowFrame(AddLMenuWindow(sNumLMenuActions), FALSE);
        sInitLMenuData[1] = 0;
        sInitLMenuData[0]++;
        break;
    case 3:
        sInitLMenuData[0]++;
        break;
    case 4:
        if (PrintLMenuActions(&sInitLMenuData[1], 2))
            sInitLMenuData[0]++;
        break;
    case 5:
        sLMenuCursorPos = InitMenuNormal(GetLMenuWindowId(), FONT_NORMAL, 0, 9, 16, sNumLMenuActions, sLMenuCursorPos);
        CopyWindowToVram(GetLMenuWindowId(), COPYWIN_MAP);
        return TRUE;
    }

    return FALSE;
}

static void LMenuTask(u8 taskId)
{
    if (InitLMenuStep() == TRUE)
        SwitchTaskToFollowupFunc(taskId);
}

static void CreateLMenuTask(TaskFunc followupFunc)
{
    u8 taskId;

    sInitLMenuData[0] = 0;
    sInitLMenuData[1] = 0;
    taskId = CreateTask(LMenuTask, 0x50);
    SetTaskFuncWithFollowupFunc(taskId, LMenuTask, followupFunc);
}

static bool8 FieldCB_ReturnToFieldLMenu(void)
{
    if (InitLMenuStep() == FALSE)
    {
        return FALSE;
    }

    ReturnToFieldOpenLMenu();
    return TRUE;
}

void ShowReturnToFieldLMenu(void)
{
    sInitLMenuData[0] = 0;
    sInitLMenuData[1] = 0;
    gFieldCallback2 = FieldCB_ReturnToFieldLMenu;
}

void Task_ShowLMenu(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch(task->data[0])
    {
    case 0:
    #ifdef USE_UNION_ROOM_L_MENU
        if (InUnionRoom() == TRUE)
            SetUsingUnionRoomLMenu();
    #endif
        gMenuCallback2 = HandleLMenuInput;
        task->data[0]++;
        break;
    case 1:
        if (gMenuCallback2() == TRUE)
            DestroyTask(taskId);
        break;
    }
}

void ShowLMenu(void)
{
    if (!IsOverworldLinkActive())
    {
        FreezeObjectEvents();
        PlayerFreeze();
        StopPlayerAvatar();
    }
    CreateLMenuTask(Task_ShowLMenu);
    LockPlayerFieldControls();
}

static bool8 HandleLMenuInput(void)
{
    if (JOY_NEW(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        sLMenuCursorPos = Menu_MoveCursor(-1);
    }

    if (JOY_NEW(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        sLMenuCursorPos = Menu_MoveCursor(1);
    }

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        
        gMenuCallback2 = sLMenuItems[sCurrentLMenuActions[sLMenuCursorPos]].func.u8_void;

        return FALSE;
    }

    if (JOY_NEW(L_BUTTON | B_BUTTON))
    {
        HideLMenu();
        return TRUE;
    }

    return FALSE;
}

const u8 gText_VialHealed[] = _(" Party healed! {STR_VAR_1} uses left.");
const u8 gText_VialLast1[] = _(" Party healed! {STR_VAR_1} use left.");
const u8 gText_VialEmpty[] = _(" The PokéVial is empty!");

bool8 TryUsePokeVial(void)
{
    if (gSaveBlock2Ptr->pokeVialCharges > 0)
    {
        HealPlayerParty();
        gSaveBlock2Ptr->pokeVialCharges--;
        ConvertIntToDecimalStringN(gStringVar1, gSaveBlock2Ptr->pokeVialCharges, STR_CONV_MODE_LEFT_ALIGN, 1);
        PlaySE(SE_USE_ITEM);
        return TRUE;
    }
    PlaySE(SE_FAILURE);
    return FALSE;
}

void RefillPokeVial(void)
{
    u8 maxCharges = 1;

    if (FlagGet(FLAG_BADGE02_GET)) maxCharges++;
    if (FlagGet(FLAG_BADGE03_GET)) maxCharges++;
    if (FlagGet(FLAG_BADGE05_GET)) maxCharges++;
    if (FlagGet(FLAG_BADGE06_GET)) maxCharges++;
    if (FlagGet(FLAG_BADGE07_GET)) maxCharges++;

    gSaveBlock2Ptr->pokeVialMaxCharges = maxCharges;
    gSaveBlock2Ptr->pokeVialCharges = gSaveBlock2Ptr->pokeVialMaxCharges;
}

static void Task_WaitAndCloseVialMessage(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        if (RunTextPrintersAndIsPrinter0Active() != TRUE)
            task->data[0]++;
        break;
    case 1:
        if (gMain.newKeys & (A_BUTTON | B_BUTTON))
        {
            HideFieldMessageBox();
            task->data[0]++;
        }
        break;
    case 2:
        DestroyTask(taskId);
        break;
    }
}

static bool8 LMenuPokeVialCallback(void)
{
    if (!gPaletteFade.active)
    {
        if (TryUsePokeVial())
        {
            if (gSaveBlock2Ptr->pokeVialCharges == 1)
            {
            ShowFieldMessage(gText_VialLast1);
            }
            else
            {
            ShowFieldMessage(gText_VialHealed); 
            }
        }
        else
        {
            ShowFieldMessage(gText_VialEmpty);
        }

        HideLMenu();
        CreateTask(Task_WaitAndCloseVialMessage, 0x1);
        //HideFieldMessageBox();
        return TRUE;
    }
    return FALSE;
}

static bool8 LMenuPCBoxCallback(void)
{
    if (!gPaletteFade.active)
    {
        HideLMenu();
        sLMenuCursorPos = 0;
        ScriptContext_SetupScript(EventScript_AccessPokemonBoxLink);
        return TRUE;
    }
    return FALSE;
}

static bool8 LMenuPlayerNameCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();

        if (IsOverworldLinkActive() || InUnionRoom())
            ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card
        else if (FlagGet(FLAG_SYS_FRONTIER_PASS))
            ShowFrontierPass(CB2_ReturnToFieldWithOpenMenu); // Display frontier pass
        else
            ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card

        return TRUE;
    }

    return FALSE;
}


extern const u8 EventScript_DisableAutoRun[];
extern const u8 EventScript_EnableAutoRun[];
static bool8 LMenuAutoRunCallback(void)
{
    HideLMenuAutoRun(); // Hide start menu
    return TRUE;
}

static void HideLMenuWindowAutoRun(void)
{
    ClearStdWindowAndFrame(GetLMenuWindowId(), TRUE);
    RemoveLMenuWindow();
    ScriptUnfreezeObjectEvents();
    UnlockPlayerFieldControls();
    if (FlagGet(FLAG_SYS_B_DASH))
    {
        PlaySE(SE_SELECT);
        if (gSaveBlock2Ptr->autoRun)
        {
            gSaveBlock2Ptr->autoRun = FALSE;
            ScriptContext_SetupScript(EventScript_DisableAutoRun);
        }
        else
        {
            gSaveBlock2Ptr->autoRun = TRUE;
            ScriptContext_SetupScript(EventScript_EnableAutoRun);
        }
    }
}

void HideLMenuAutoRun(void)
{
    PlaySE(SE_SELECT);
    HideLMenuWindowAutoRun();
}

static bool8 LMenuExitCallback(void)
{
    HideLMenu(); // Hide start menu

    return TRUE;
}

static void HideLMenuWindow(void)
{
    ClearStdWindowAndFrame(GetLMenuWindowId(), TRUE);
    RemoveLMenuWindow();
    ScriptUnfreezeObjectEvents();
    UnlockPlayerFieldControls();
}

void HideLMenu(void)
{
    PlaySE(SE_SELECT);
    HideLMenuWindow();
}

void AppendToLList(u8 *list, u8 *pos, u8 newEntry)
{
    list[*pos] = newEntry;
    (*pos)++;
}

//static bool8 LMenuDexNavCallback(void)
//{
//    CreateTask(Task_OpenDexNavFromLMenu, 0);
//    return TRUE;
//}
