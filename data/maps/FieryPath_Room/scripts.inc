# 1 "data/maps/FieryPath_Room/scripts.pory"

# 2 "data/maps/FieryPath_Room/scripts.pory"
FieryPath_Room_MapScripts::
# 3 "data/maps/FieryPath_Room/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, FieryPath_Room_OnLoad
# 4 "data/maps/FieryPath_Room/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_Room_OnTransition
# 5 "data/maps/FieryPath_Room/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FieryPath_Room_OnResume
# 6 "data/maps/FieryPath_Room/scripts.pory"
	.byte 0
# 7 "data/maps/FieryPath_Room/scripts.pory"

# 8 "data/maps/FieryPath_Room/scripts.pory"
FieryPath_Room_OnLoad:
# 9 "data/maps/FieryPath_Room/scripts.pory"
	call_if_unset FLAG_SYS_GAME_CLEAR, FieryPath_Room_EventScript_HideStairs
# 10 "data/maps/FieryPath_Room/scripts.pory"
	end
# 11 "data/maps/FieryPath_Room/scripts.pory"

# 12 "data/maps/FieryPath_Room/scripts.pory"
FieryPath_Room_EventScript_HideStairs:
# 13 "data/maps/FieryPath_Room/scripts.pory"
    setmetatile 15, 26, METATILE_Lavaridge_RockWall, TRUE
# 14 "data/maps/FieryPath_Room/scripts.pory"
	setmetatile 12, 31, METATILE_Lavaridge_RockWall, TRUE
# 15 "data/maps/FieryPath_Room/scripts.pory"
	return
# 16 "data/maps/FieryPath_Room/scripts.pory"

# 17 "data/maps/FieryPath_Room/scripts.pory"
FieryPath_Room_OnTransition:
# 18 "data/maps/FieryPath_Room/scripts.pory"
	call_if_set FLAG_CAUGHT_RESHIRAM, FieryPath_Room_EventScript_HideReshiram
# 19 "data/maps/FieryPath_Room/scripts.pory"
	call_if_unset FLAG_CAUGHT_RESHIRAM, FieryPath_Room_EventScript_TryShowReshiram
# 20 "data/maps/FieryPath_Room/scripts.pory"
	end
# 21 "data/maps/FieryPath_Room/scripts.pory"

# 22 "data/maps/FieryPath_Room/scripts.pory"
FieryPath_Room_EventScript_HideReshiram::
# 23 "data/maps/FieryPath_Room/scripts.pory"
	setvar VAR_TEMP_1, 1
# 24 "data/maps/FieryPath_Room/scripts.pory"
	setflag FLAG_HIDE_RESHIRAM
# 25 "data/maps/FieryPath_Room/scripts.pory"
	return
# 26 "data/maps/FieryPath_Room/scripts.pory"

# 27 "data/maps/FieryPath_Room/scripts.pory"
FieryPath_Room_EventScript_TryShowReshiram::
# 28 "data/maps/FieryPath_Room/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, FieryPath_Room_EventScript_HideReshiram
# 29 "data/maps/FieryPath_Room/scripts.pory"
	setvar VAR_TEMP_1, 0
# 30 "data/maps/FieryPath_Room/scripts.pory"
	clearflag FLAG_HIDE_RESHIRAM
# 31 "data/maps/FieryPath_Room/scripts.pory"
	return
# 32 "data/maps/FieryPath_Room/scripts.pory"

# 33 "data/maps/FieryPath_Room/scripts.pory"
FieryPath_Room_OnResume:
# 34 "data/maps/FieryPath_Room/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FieryPath_Room_EventScript_TryRemoveReshiram
# 35 "data/maps/FieryPath_Room/scripts.pory"
	end
# 36 "data/maps/FieryPath_Room/scripts.pory"

# 37 "data/maps/FieryPath_Room/scripts.pory"
FieryPath_Room_EventScript_TryRemoveReshiram::
# 38 "data/maps/FieryPath_Room/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 39 "data/maps/FieryPath_Room/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 40 "data/maps/FieryPath_Room/scripts.pory"
	removeobject LOCALID_FIERY_PATH_ROOM_RESHIRAM
# 41 "data/maps/FieryPath_Room/scripts.pory"
	return

FieryPath_Room_EventScript_BattleReshiram::
# 45 "data/maps/FieryPath_Room/scripts.pory"
	lock
# 46 "data/maps/FieryPath_Room/scripts.pory"
	faceplayer
# 47 "data/maps/FieryPath_Room/scripts.pory"
	setvar VAR_TEMP_1, 1
# 48 "data/maps/FieryPath_Room/scripts.pory"
	playmoncry SPECIES_RESHIRAM, CRY_MODE_ENCOUNTER
# 49 "data/maps/FieryPath_Room/scripts.pory"
	delay 30
# 50 "data/maps/FieryPath_Room/scripts.pory"
	waitmoncry
# 51 "data/maps/FieryPath_Room/scripts.pory"
	seteventmon SPECIES_RESHIRAM, 70
# 52 "data/maps/FieryPath_Room/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 53 "data/maps/FieryPath_Room/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 54 "data/maps/FieryPath_Room/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 55 "data/maps/FieryPath_Room/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FIERY_PATH_ROOM_RESHIRAM
# 56 "data/maps/FieryPath_Room/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 57 "data/maps/FieryPath_Room/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FieryPath_Room_EventScript_RanFromReshiram
# 58 "data/maps/FieryPath_Room/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FieryPath_Room_EventScript_RanFromReshiram
# 59 "data/maps/FieryPath_Room/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FieryPath_Room_EventScript_RanFromReshiram
# 60 "data/maps/FieryPath_Room/scripts.pory"
	setflag FLAG_CAUGHT_RESHIRAM
# 61 "data/maps/FieryPath_Room/scripts.pory"
	release
	end


FieryPath_Room_EventScript_RanFromReshiram::
# 66 "data/maps/FieryPath_Room/scripts.pory"
	setvar VAR_0x8004, SPECIES_RESHIRAM
# 67 "data/maps/FieryPath_Room/scripts.pory"
	call Common_EventScript_LegendaryFlewAway
# 68 "data/maps/FieryPath_Room/scripts.pory"
	release
	end

