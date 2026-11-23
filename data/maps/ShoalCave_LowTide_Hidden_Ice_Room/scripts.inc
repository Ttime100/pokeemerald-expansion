# 1 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"

# 2 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
ShoalCave_LowTide_Hidden_Ice_Room_MapScripts::
# 3 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ShoalCave_LowTide_Hidden_Ice_Room_OnTransition
# 4 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, ShoalCave_LowTide_Hidden_Ice_Room_OnResume
# 5 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	.byte 0
# 6 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"

# 7 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
ShoalCave_LowTide_Hidden_Ice_Room_OnTransition:
# 8 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	call_if_set FLAG_CAUGHT_KYUREM, ShoalCave_LowTide_Hidden_Ice_Room_EventScript_HideKyurem
# 9 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	call_if_unset FLAG_CAUGHT_KYUREM, ShoalCave_LowTide_Hidden_Ice_Room_EventScript_TryShowKyurem
# 10 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	end
# 11 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"

# 12 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
ShoalCave_LowTide_Hidden_Ice_Room_EventScript_HideKyurem::
# 13 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	setvar VAR_TEMP_1, 1
# 14 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	setflag FLAG_HIDE_KYUREM
# 15 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	return
# 16 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"

# 17 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
ShoalCave_LowTide_Hidden_Ice_Room_EventScript_TryShowKyurem::
# 18 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	setvar VAR_TEMP_1, 1
# 19 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	goto_if_set FLAG_DEFEATED_KYUREM, Common_EventScript_NopReturn
# 20 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	setvar VAR_TEMP_1, 0
# 21 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	clearflag FLAG_HIDE_KYUREM
# 22 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	return
# 23 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"

# 24 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
ShoalCave_LowTide_Hidden_Ice_Room_OnResume:
# 25 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ShoalCave_LowTide_Hidden_Ice_Room_EventScript_TryRemoveKyurem
# 26 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	end
# 27 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"

# 28 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
ShoalCave_LowTide_Hidden_Ice_Room_EventScript_TryRemoveKyurem::
# 29 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 30 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 31 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	removeobject LOCALID_SHOAL_CAVE_KYUREM
# 32 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	return

ShoalCave_LowTide_Hidden_Ice_Room_BattleKyurem::
# 35 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	lock
# 36 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	faceplayer
# 37 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	setvar VAR_TEMP_1, 1
# 38 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	playmoncry SPECIES_KYUREM, CRY_MODE_ENCOUNTER
# 39 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	delay 30
# 40 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	waitmoncry
# 41 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	seteventmon SPECIES_KYUREM, 70
# 42 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 43 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 44 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 45 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_SHOAL_CAVE_KYUREM
# 46 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 47 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ShoalCave_LowTide_Hidden_Ice_Room_EventScript_DefeatedKyurem
# 48 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ShoalCave_LowTide_Hidden_Ice_Room_EventScript_RanFromKyurem
# 49 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ShoalCave_LowTide_Hidden_Ice_Room_EventScript_RanFromKyurem
# 50 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	setflag FLAG_CAUGHT_KYUREM
# 51 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	release
	end


ShoalCave_LowTide_Hidden_Ice_Room_EventScript_DefeatedKyurem::
# 56 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	setflag FLAG_DEFEATED_KYUREM
# 57 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	setvar VAR_0x8004, SPECIES_KYUREM
# 58 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	call Common_EventScript_LegendaryFlewAway
# 59 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	release
	end


ShoalCave_LowTide_Hidden_Ice_Room_EventScript_RanFromKyurem::
# 64 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	setvar VAR_0x8004, SPECIES_KYUREM
# 65 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	call Common_EventScript_LegendaryFlewAway
# 66 "data/maps/ShoalCave_LowTide_Hidden_Ice_Room/scripts.pory"
	release
	end

