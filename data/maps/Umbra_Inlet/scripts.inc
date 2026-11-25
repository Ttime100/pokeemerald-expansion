# 1 "data/maps/Umbra_Inlet/scripts.pory"

# 2 "data/maps/Umbra_Inlet/scripts.pory"
Umbra_Inlet_MapScripts::
# 3 "data/maps/Umbra_Inlet/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Umbra_Inlet_OnLoad
# 4 "data/maps/Umbra_Inlet/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Umbra_Inlet_OnTransition
# 5 "data/maps/Umbra_Inlet/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Umbra_Inlet_OnResume
# 6 "data/maps/Umbra_Inlet/scripts.pory"
	.byte 0
# 7 "data/maps/Umbra_Inlet/scripts.pory"

# 8 "data/maps/Umbra_Inlet/scripts.pory"
Umbra_Inlet_OnLoad:
# 9 "data/maps/Umbra_Inlet/scripts.pory"
	call_if_unset FLAG_SYS_GAME_CLEAR, Umbra_Inlet_EventScript_HideStairs
# 10 "data/maps/Umbra_Inlet/scripts.pory"
	end
# 11 "data/maps/Umbra_Inlet/scripts.pory"

# 12 "data/maps/Umbra_Inlet/scripts.pory"
Umbra_Inlet_EventScript_HideStairs:
# 13 "data/maps/Umbra_Inlet/scripts.pory"
	setmetatile 27, 14, 0x231, TRUE
# 14 "data/maps/Umbra_Inlet/scripts.pory"
	return
# 15 "data/maps/Umbra_Inlet/scripts.pory"

# 16 "data/maps/Umbra_Inlet/scripts.pory"
Umbra_Inlet_OnTransition:
# 17 "data/maps/Umbra_Inlet/scripts.pory"
	call_if_set FLAG_CAUGHT_ZEKROM, Umbra_Inlet_EventScript_HideZekrom
# 18 "data/maps/Umbra_Inlet/scripts.pory"
	call_if_unset FLAG_CAUGHT_ZEKROM, Umbra_Inlet_EventScript_TryShowZekrom
# 19 "data/maps/Umbra_Inlet/scripts.pory"
	end
# 20 "data/maps/Umbra_Inlet/scripts.pory"

# 21 "data/maps/Umbra_Inlet/scripts.pory"
Umbra_Inlet_EventScript_HideZekrom::
# 22 "data/maps/Umbra_Inlet/scripts.pory"
	setvar VAR_TEMP_1, 1
# 23 "data/maps/Umbra_Inlet/scripts.pory"
	setflag FLAG_HIDE_ZEKROM
# 24 "data/maps/Umbra_Inlet/scripts.pory"
	return
# 25 "data/maps/Umbra_Inlet/scripts.pory"

# 26 "data/maps/Umbra_Inlet/scripts.pory"
Umbra_Inlet_EventScript_TryShowZekrom::
# 27 "data/maps/Umbra_Inlet/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Umbra_Inlet_EventScript_HideZekrom
# 28 "data/maps/Umbra_Inlet/scripts.pory"
	setvar VAR_TEMP_1, 0
# 29 "data/maps/Umbra_Inlet/scripts.pory"
	clearflag FLAG_HIDE_ZEKROM
# 30 "data/maps/Umbra_Inlet/scripts.pory"
	return
# 31 "data/maps/Umbra_Inlet/scripts.pory"

# 32 "data/maps/Umbra_Inlet/scripts.pory"
Umbra_Inlet_OnResume:
# 33 "data/maps/Umbra_Inlet/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Umbra_Inlet_EventScript_TryRemoveZekrom
# 34 "data/maps/Umbra_Inlet/scripts.pory"
	end
# 35 "data/maps/Umbra_Inlet/scripts.pory"

# 36 "data/maps/Umbra_Inlet/scripts.pory"
Umbra_Inlet_EventScript_TryRemoveZekrom::
# 37 "data/maps/Umbra_Inlet/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 38 "data/maps/Umbra_Inlet/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 39 "data/maps/Umbra_Inlet/scripts.pory"
	removeobject LOCALID_UMBRA_INLET_ZEKROM
# 40 "data/maps/Umbra_Inlet/scripts.pory"
	return

Umbra_Inlet_EventScript_Sidney::
# 43 "data/maps/Umbra_Inlet/scripts.pory"
	lock
# 44 "data/maps/Umbra_Inlet/scripts.pory"
	faceplayer
# 45 "data/maps/Umbra_Inlet/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, Sidney_EventScript_PostbattleSpeech
# 46 "data/maps/Umbra_Inlet/scripts.pory"
	trainerbattle_single TRAINER_SIDNEY, Sidney_Text_IntroSpeech, Sidney_Text_Defeat, Sidney_EventScript_Defeated
# 47 "data/maps/Umbra_Inlet/scripts.pory"
	msgbox Sidney_Text_PostBattleSpeech, MSGBOX_AUTOCLOSE
	end


Sidney_EventScript_Defeated::
# 52 "data/maps/Umbra_Inlet/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
# 53 "data/maps/Umbra_Inlet/scripts.pory"
	msgbox Sidney_Text_PostBattleSpeech
# 54 "data/maps/Umbra_Inlet/scripts.pory"
	release
	end


Sidney_EventScript_PostbattleSpeech::
# 59 "data/maps/Umbra_Inlet/scripts.pory"
	msgbox Sidney_Text_PostBattleSpeech
# 60 "data/maps/Umbra_Inlet/scripts.pory"
	release
	end


Umbra_Inlet_EventScript_BattleZekrom::
# 89 "data/maps/Umbra_Inlet/scripts.pory"
	lock
# 90 "data/maps/Umbra_Inlet/scripts.pory"
	faceplayer
# 91 "data/maps/Umbra_Inlet/scripts.pory"
	setvar VAR_TEMP_1, 1
# 92 "data/maps/Umbra_Inlet/scripts.pory"
	playmoncry SPECIES_ZEKROM, CRY_MODE_ENCOUNTER
# 93 "data/maps/Umbra_Inlet/scripts.pory"
	delay 30
# 94 "data/maps/Umbra_Inlet/scripts.pory"
	waitmoncry
# 95 "data/maps/Umbra_Inlet/scripts.pory"
	seteventmon SPECIES_ZEKROM, 70
# 96 "data/maps/Umbra_Inlet/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 97 "data/maps/Umbra_Inlet/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 98 "data/maps/Umbra_Inlet/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 99 "data/maps/Umbra_Inlet/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_UMBRA_INLET_ZEKROM
# 100 "data/maps/Umbra_Inlet/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 101 "data/maps/Umbra_Inlet/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Umbra_Inlet_EventScript_RanFromZekrom
# 102 "data/maps/Umbra_Inlet/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Umbra_Inlet_EventScript_RanFromZekrom
# 103 "data/maps/Umbra_Inlet/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Umbra_Inlet_EventScript_RanFromZekrom
# 104 "data/maps/Umbra_Inlet/scripts.pory"
	setflag FLAG_CAUGHT_ZEKROM
# 105 "data/maps/Umbra_Inlet/scripts.pory"
	release
	end


Umbra_Inlet_EventScript_RanFromZekrom::
# 110 "data/maps/Umbra_Inlet/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZEKROM
# 111 "data/maps/Umbra_Inlet/scripts.pory"
	call Common_EventScript_LegendaryFlewAway
# 112 "data/maps/Umbra_Inlet/scripts.pory"
	release
	end


Sidney_Text_IntroSpeech::
# 64 "data/maps/Umbra_Inlet/scripts.pory"
	.string "Welcome... I'm Sidney,\n"
	.string "formerly of the Elite Four.\p"
	.string "I like that look you're giving me.\n"
	.string "I guess you'll give me a good match.\l"
	.string "That's good! Looking real good!\p"
	.string "All right! You and me, let's enjoy\n"
	.string "a battle that could rival\l"
	.string "the Pokémon League!$"

Sidney_Text_Defeat::
# 75 "data/maps/Umbra_Inlet/scripts.pory"
	.string "Well, how do you like that? I lost!\n"
	.string "Eh, it was fun, so it doesn't matter.$"

Sidney_Text_PostBattleSpeech::
# 80 "data/maps/Umbra_Inlet/scripts.pory"
	.string "Well, listen to what this loser has\n"
	.string "to say.\p"
	.string "You've got what it takes to go far.\n"
	.string "Now, go on to the Pokémon League and\l"
	.string "show them what a real trainer can do!$"
