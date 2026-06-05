AncientColonnade_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AncientColonnade_OnResume
	map_script MAP_SCRIPT_ON_LOAD, AncientColonnade_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, AncientColonnade_OnTransition
	.byte 0

AncientColonnade_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AncientColonnade_EventScript_TryRemoveRegigigas
	end

AncientColonnade_EventScript_TryRemoveRegigigas::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AncientColonnade_OnTransition:
	setflag FLAG_LANDMARK_ANCIENT_COLONNADE
	call_if_unset FLAG_DEFEATED_REGIGIGAS, AncientColonnade_EventScript_ShowRegigigas
	end

AncientColonnade_EventScript_ShowRegigigas::
	clearflag FLAG_HIDE_REGIGIGAS
	return

AncientColonnade_OnLoad:
	call_if_unset FLAG_SYS_REGIGIGAS_PUZZLE_COMPLETED, AncientColonnade_EventScript_HideRegiEntrance
	end

AncientColonnade_EventScript_HideRegiEntrance::
	setmetatile 12, 31, METATILE_Cave_EntranceCover, TRUE
	setmetatile 13, 31, METATILE_Cave_EntranceCover, TRUE
	setmetatile 14, 31, METATILE_Cave_EntranceCover, TRUE
	setmetatile 12, 32, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 13, 32, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	setmetatile 14, 32, METATILE_Cave_SealedChamberBraille_Mid, TRUE
	return

AncientColonnade_EventScript_CaveEntranceMiddle::
	lockall
	goto_if_set FLAG_SYS_REGIGIGAS_PUZZLE_COMPLETED, AncientColonnade_EventScript_BigHoleInWall
	braillemsgbox AncientColonnade_Braille_ThreeGiantsAsOne
	specialvar VAR_RESULT ShouldDoBrailleRegigigasEffect
    goto_if_eq VAR_RESULT, FALSE, AncientColonnade_EventScript_Release
    fadeoutbgm 0
    playse SE_BANG
    special DoSealedChamberShakingEffect_Long
    delay 30
    special DoBrailleRegigigasEffect
    fadeinbgm 0
	releaseall
	end

AncientColonnade_EventScript_Release:
    releaseall
    end

AncientColonnade_EventScript_BigHoleInWall::
	msgbox gText_BigHoleInTheWall, MSGBOX_DEFAULT
	releaseall
	end

AncientColonnade_EventScript_CaveEntranceSide::
	lockall
	braillemsgbox AncientColonnade_Braille_ThreeGiantsAsOne
	releaseall
	end

AncientColonnade_EventScript_Regigigas::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIGIGAS, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AncientColonnade_EventScript_DefeatedRegigigas
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AncientColonnade_EventScript_RanFromRegigigas
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AncientColonnade_EventScript_RanFromRegigigas
	setflag FLAG_DEFEATED_REGIGIGAS
	release
	end

AncientColonnade_EventScript_DefeatedRegigigas::
	setflag FLAG_DEFEATED_REGIGIGAS
	goto Common_EventScript_RemoveStaticPokemon
	end

AncientColonnade_EventScript_RanFromRegigigas::
	setvar VAR_0x8004, SPECIES_REGIGIGAS
	goto Common_EventScript_LegendaryFlewAway
	end
