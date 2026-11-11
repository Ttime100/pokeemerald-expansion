# 1 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"

# 2 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
VictoryRoad_MewtwoRoom_MapScripts::
# 3 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_MewtwoRoom_OnTransition
# 4 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, VictoryRoad_MewtwoRoom_OnResume
# 5 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	.byte 0
# 6 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"

# 7 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
VictoryRoad_MewtwoRoom_OnTransition:
# 8 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	setflag FLAG_HIDE_MEWTWO_EMERALD
# 9 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	call_if_set FLAG_IS_CHAMPION, VictoryRoad_MewtwoRoom_EventScript_TryShowMewtwo
# 10 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	end
# 11 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"

# 12 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
VictoryRoad_MewtwoRoom_EventScript_TryShowMewtwo::
# 13 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 14 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	goto_if_set FLAG_CAUGHT_MEWTWO, Common_EventScript_NopReturn
# 15 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_MEWTWO, Common_EventScript_NopReturn
# 16 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	setvar VAR_TEMP_1, 0
# 17 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	clearflag FLAG_HIDE_MEWTWO_EMERALD
# 18 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	return
# 19 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"

# 20 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
VictoryRoad_MewtwoRoom_OnResume:
# 21 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, VictoryRoad_MewtwoRoom_EventScript_TryRemoveMewtwo
# 22 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	end
# 23 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"

# 24 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
VictoryRoad_MewtwoRoom_EventScript_TryRemoveMewtwo::
# 25 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 26 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 27 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	removeobject LOCALID_VICTORY_ROAD_MEWTWO_ROOM_MEWTWO
# 28 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	return

VictoryRoad_MewtwoRoom_BattleMewtwo::
# 33 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	lock
# 34 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	faceplayer
# 35 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
# 36 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
# 37 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	delay 30
# 38 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	waitmoncry
# 39 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	seteventmon SPECIES_MEWTWO, 70
# 40 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 41 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 42 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 43 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_VICTORY_ROAD_MEWTWO_ROOM_MEWTWO
# 44 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 45 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, VictoryRoad_MewtwoRoom_EventScript_DefeatedMewtwo
# 46 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VictoryRoad_MewtwoRoom_EventScript_RanFromMewtwo
# 47 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, VictoryRoad_MewtwoRoom_EventScript_RanFromMewtwo
# 48 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	setflag FLAG_CAUGHT_MEWTWO
# 49 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	release
	end


VictoryRoad_MewtwoRoom_EventScript_DefeatedMewtwo::
# 54 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	setflag FLAG_DEFEATED_MEWTWO
# 55 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	setvar VAR_0x8004, SPECIES_MEWTWO
# 56 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	call Common_EventScript_LegendaryFlewAway
# 57 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	release
	end


VictoryRoad_MewtwoRoom_EventScript_RanFromMewtwo::
# 62 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	setvar VAR_0x8004, SPECIES_MEWTWO
# 63 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	call Common_EventScript_LegendaryFlewAway
# 64 "data/maps/VictoryRoad_MewtwoRoom/scripts.pory"
	release
	end

