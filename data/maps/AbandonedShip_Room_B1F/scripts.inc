# 1 "data/maps/AbandonedShip_Room_B1F/scripts.pory"

# 2 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
AbandonedShip_Room_B1F_MapScripts::
# 3 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, AbandonedShip_Room_B1F_OnTransition
# 4 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Room_B1F_OnResume
# 5 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	.byte 0
# 6 "data/maps/AbandonedShip_Room_B1F/scripts.pory"

# 7 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
AbandonedShip_Room_B1F_OnTransition:
# 8 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	call_if_set FLAG_CAUGHT_SPIRITOMB, AbandonedShip_Room_B1F_EventScript_HideSpiritomb
# 9 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
    call_if_unset FLAG_CAUGHT_SPIRITOMB, AbandonedShip_Room_B1F_EventScript_CheckGymAndShowSpiritomb
# 10 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	end
# 11 "data/maps/AbandonedShip_Room_B1F/scripts.pory"

# 12 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
AbandonedShip_Room_B1F_EventScript_CheckGymAndShowSpiritomb::
# 13 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
    goto_if_unset FLAG_BADGE07_GET, AbandonedShip_Room_B1F_EventScript_HideSpiritomb
# 14 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
    goto AbandonedShip_Room_B1F_EventScript_TryShowSpiritomb
# 15 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
    end
# 16 "data/maps/AbandonedShip_Room_B1F/scripts.pory"

# 17 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
AbandonedShip_Room_B1F_EventScript_HideSpiritomb::
# 18 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 19 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	setflag FLAG_HIDE_SPIRITOMB
# 20 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	return
# 21 "data/maps/AbandonedShip_Room_B1F/scripts.pory"

# 22 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
AbandonedShip_Room_B1F_EventScript_TryShowSpiritomb::
# 23 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 24 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_SPIRITOMB, Common_EventScript_NopReturn
# 25 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	setvar VAR_TEMP_1, 0
# 26 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	clearflag FLAG_HIDE_SPIRITOMB
# 27 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	return
# 28 "data/maps/AbandonedShip_Room_B1F/scripts.pory"

# 29 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
AbandonedShip_Room_B1F_OnResume:
# 30 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AbandonedShip_Room_B1F_EventScript_TryRemoveSpiritomb
# 31 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	end
# 32 "data/maps/AbandonedShip_Room_B1F/scripts.pory"

# 33 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
AbandonedShip_Room_B1F_EventScript_TryRemoveSpiritomb::
# 34 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 36 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	removeobject LOCALID_ABANDONED_SHIP_ROOM_B1F_SPIRITOMB
# 37 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	return

AbandonedShip_Room_B1F_BattleSpiritomb::
# 40 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	lock
# 41 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	faceplayer
# 42 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	setvar VAR_TEMP_1, 1
# 43 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	playmoncry SPECIES_SPIRITOMB, CRY_MODE_ENCOUNTER
# 44 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	delay 30
# 45 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	waitmoncry
# 46 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	seteventmon SPECIES_SPIRITOMB, 50
# 47 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 48 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 49 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	waitstate
# 50 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 51 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ABANDONED_SHIP_ROOM_B1F_SPIRITOMB
# 52 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 53 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AbandonedShip_Room_B1F_EventScript_DefeatedSpiritomb
# 54 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AbandonedShip_Room_B1F_EventScript_RanFromSpiritomb
# 55 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AbandonedShip_Room_B1F_EventScript_RanFromSpiritomb
# 56 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	setflag FLAG_CAUGHT_SPIRITOMB
# 57 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	release
	end


AbandonedShip_Room_B1F_EventScript_DefeatedSpiritomb::
# 62 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	setflag FLAG_DEFEATED_SPIRITOMB
# 63 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	setvar VAR_0x8004, SPECIES_SPIRITOMB
# 64 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	call Common_EventScript_LegendaryFlewAway
# 65 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	release
	end


AbandonedShip_Room_B1F_EventScript_RanFromSpiritomb::
# 70 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	setvar VAR_0x8004, SPECIES_SPIRITOMB
# 71 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	call Common_EventScript_LegendaryFlewAway
# 72 "data/maps/AbandonedShip_Room_B1F/scripts.pory"
	release
	end

