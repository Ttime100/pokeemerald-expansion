# 1 "data/maps/SootopolisCity_House2/scripts.pory"

# 2 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_MapScripts::
# 3 "data/maps/SootopolisCity_House2/scripts.pory"
	.byte 0
# 4 "data/maps/SootopolisCity_House2/scripts.pory"

# 5 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_EventScript_ExpertF::
# 6 "data/maps/SootopolisCity_House2/scripts.pory"
	lock
# 7 "data/maps/SootopolisCity_House2/scripts.pory"
	faceplayer
# 8 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
# 9 "data/maps/SootopolisCity_House2/scripts.pory"
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
# 10 "data/maps/SootopolisCity_House2/scripts.pory"
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
# 11 "data/maps/SootopolisCity_House2/scripts.pory"
	release
# 12 "data/maps/SootopolisCity_House2/scripts.pory"
	end
# 13 "data/maps/SootopolisCity_House2/scripts.pory"

# 14 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_EventScript_KnowAboutOrbs::
# 15 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
# 16 "data/maps/SootopolisCity_House2/scripts.pory"
	return
# 17 "data/maps/SootopolisCity_House2/scripts.pory"

# 18 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
# 19 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
# 20 "data/maps/SootopolisCity_House2/scripts.pory"
	return
# 21 "data/maps/SootopolisCity_House2/scripts.pory"

# 22 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
# 23 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Mt. Pyre…\p"
# 24 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "At its peak are two orbs placed side\n"
# 25 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "by side. Did you know?$"
# 26 "data/maps/SootopolisCity_House2/scripts.pory"

# 27 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
# 28 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Yes, two orbs side by side…\p"
# 29 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "The sight of them together…\n"
# 30 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "It is somehow soothing…$"
# 31 "data/maps/SootopolisCity_House2/scripts.pory"

# 32 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_Text_OughtToVisitAndSee:
# 33 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Is that so?\n"
# 34 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Perhaps you ought to visit and see…$"

DummyScript::
# 40 "data/maps/SootopolisCity_House2/scripts.pory"
	special ChooseMonForMoveTutor
# 41 "data/maps/SootopolisCity_House2/scripts.pory"
	release
	end


SootopolisCity_House2_EventScript_UltimateMoveTutor::
# 46 "data/maps/SootopolisCity_House2/scripts.pory"
	lock
# 47 "data/maps/SootopolisCity_House2/scripts.pory"
	faceplayer
# 48 "data/maps/SootopolisCity_House2/scripts.pory"
	goto_if_set FLAG_TEMP_2, SootopolisCity_House2_EventScript_UltimateMoveTutor_2
# 53 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_UltimateMoveTutorIntro, MSGBOX_YESNO
# 54 "data/maps/SootopolisCity_House2/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq SootopolisCity_House2_EventScript_UltimateMoveTutor_5
# 59 "data/maps/SootopolisCity_House2/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, UltimateTutor_EventScript_JumpInPlaceDown
# 60 "data/maps/SootopolisCity_House2/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, UltimateTutor_EventScript_JumpInPlaceUp
# 61 "data/maps/SootopolisCity_House2/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, UltimateTutor_EventScript_JumpInPlaceLeft
# 62 "data/maps/SootopolisCity_House2/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, UltimateTutor_EventScript_JumpInPlaceRight
# 63 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_EventScript_UltimateMoveTutor_Text_0
# 66 "data/maps/SootopolisCity_House2/scripts.pory"
	call SootopolisCity_House2_EventScript_ChooseMove
# 67 "data/maps/SootopolisCity_House2/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq SootopolisCity_House2_EventScript_UltimateMoveTutor_8
SootopolisCity_House2_EventScript_UltimateMoveTutor_7:
# 70 "data/maps/SootopolisCity_House2/scripts.pory"
	buffermovename STR_VAR_2, VAR_0x8005
# 71 "data/maps/SootopolisCity_House2/scripts.pory"
	compare VAR_0x8005, MOVE_BLAST_BURN
	goto_if_eq SootopolisCity_House2_EventScript_UltimateMoveTutor_11
# 73 "data/maps/SootopolisCity_House2/scripts.pory"
	compare VAR_0x8005, MOVE_FRENZY_PLANT
	goto_if_eq SootopolisCity_House2_EventScript_UltimateMoveTutor_12
# 75 "data/maps/SootopolisCity_House2/scripts.pory"
	compare VAR_0x8005, MOVE_HYDRO_CANNON
	goto_if_eq SootopolisCity_House2_EventScript_UltimateMoveTutor_13
SootopolisCity_House2_EventScript_UltimateMoveTutor_10:
# 78 "data/maps/SootopolisCity_House2/scripts.pory"
	release
	end

SootopolisCity_House2_EventScript_UltimateMoveTutor_2:
# 49 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_MakeBestUseOfMove
# 50 "data/maps/SootopolisCity_House2/scripts.pory"
	release
	end

SootopolisCity_House2_EventScript_UltimateMoveTutor_5:
# 55 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_UltimateMoveTutorJustMistaken
# 56 "data/maps/SootopolisCity_House2/scripts.pory"
	release
	end

SootopolisCity_House2_EventScript_UltimateMoveTutor_8:
# 68 "data/maps/SootopolisCity_House2/scripts.pory"
	goto SootopolisCity_House2_EventScript_YouRejectIt
	goto SootopolisCity_House2_EventScript_UltimateMoveTutor_7

SootopolisCity_House2_EventScript_UltimateMoveTutor_11:
# 72 "data/maps/SootopolisCity_House2/scripts.pory"
	move_tutor MOVE_BLAST_BURN, SootopolisCity_House2_Text_WhichPokemonToTeach, SootopolisCity_House2_Text_ChooseAPokemon, SootopolisCity_House2_EventScript_YouRejectIt, SootopolisCity_House2_EventScript_TaughtMove
	goto SootopolisCity_House2_EventScript_UltimateMoveTutor_10

SootopolisCity_House2_EventScript_UltimateMoveTutor_12:
# 74 "data/maps/SootopolisCity_House2/scripts.pory"
	move_tutor MOVE_FRENZY_PLANT, SootopolisCity_House2_Text_WhichPokemonToTeach, SootopolisCity_House2_Text_ChooseAPokemon, SootopolisCity_House2_EventScript_YouRejectIt, SootopolisCity_House2_EventScript_TaughtMove
	goto SootopolisCity_House2_EventScript_UltimateMoveTutor_10

SootopolisCity_House2_EventScript_UltimateMoveTutor_13:
# 76 "data/maps/SootopolisCity_House2/scripts.pory"
	move_tutor MOVE_HYDRO_CANNON, SootopolisCity_House2_Text_WhichPokemonToTeach, SootopolisCity_House2_Text_ChooseAPokemon, SootopolisCity_House2_EventScript_YouRejectIt, SootopolisCity_House2_EventScript_TaughtMove
	goto SootopolisCity_House2_EventScript_UltimateMoveTutor_10


SootopolisCity_House2_EventScript_YouRejectIt::
# 83 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_YouRejectIt
# 84 "data/maps/SootopolisCity_House2/scripts.pory"
	release
	end


SootopolisCity_House2_EventScript_ChooseMove::
# 89 "data/maps/SootopolisCity_House2/scripts.pory"
	dynmultipush SootopolisCity_House2_EventScript_ChooseMove_Text_0, 0
# 90 "data/maps/SootopolisCity_House2/scripts.pory"
	dynmultipush SootopolisCity_House2_EventScript_ChooseMove_Text_1, 1
# 91 "data/maps/SootopolisCity_House2/scripts.pory"
	dynmultipush SootopolisCity_House2_EventScript_ChooseMove_Text_2, 2
# 92 "data/maps/SootopolisCity_House2/scripts.pory"
	dynmultistack 0, 0, FALSE, 3, TRUE, 0, 0
# 93 "data/maps/SootopolisCity_House2/scripts.pory"
	switch VAR_RESULT
# 94 "data/maps/SootopolisCity_House2/scripts.pory"
	case 0, SootopolisCity_House2_EventScript_ChooseMove_3
# 97 "data/maps/SootopolisCity_House2/scripts.pory"
	case 1, SootopolisCity_House2_EventScript_ChooseMove_4
# 100 "data/maps/SootopolisCity_House2/scripts.pory"
	case 2, SootopolisCity_House2_EventScript_ChooseMove_5
SootopolisCity_House2_EventScript_ChooseMove_1:
	return

SootopolisCity_House2_EventScript_ChooseMove_3:
# 95 "data/maps/SootopolisCity_House2/scripts.pory"
	setvar VAR_0x8005, MOVE_FRENZY_PLANT
	goto SootopolisCity_House2_EventScript_ChooseMove_1

SootopolisCity_House2_EventScript_ChooseMove_4:
# 98 "data/maps/SootopolisCity_House2/scripts.pory"
	setvar VAR_0x8005, MOVE_BLAST_BURN
	goto SootopolisCity_House2_EventScript_ChooseMove_1

SootopolisCity_House2_EventScript_ChooseMove_5:
# 101 "data/maps/SootopolisCity_House2/scripts.pory"
	setvar VAR_0x8005, MOVE_HYDRO_CANNON
	goto SootopolisCity_House2_EventScript_ChooseMove_1


SootopolisCity_House2_EventScript_TaughtMove::
# 108 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_TaughtMove
# 109 "data/maps/SootopolisCity_House2/scripts.pory"
	setflag FLAG_TEMP_2
# 110 "data/maps/SootopolisCity_House2/scripts.pory"
	release
	end


UltimateTutor_EventScript_JumpInPlaceDown::
# 115 "data/maps/SootopolisCity_House2/scripts.pory"
	applymovement LOCALID_ULTIMATE_TUTOR, Movement_JumpInPlaceDown
# 116 "data/maps/SootopolisCity_House2/scripts.pory"
	waitmovement 0
	return


UltimateTutor_EventScript_JumpInPlaceUp::
# 121 "data/maps/SootopolisCity_House2/scripts.pory"
	applymovement LOCALID_ULTIMATE_TUTOR, Movement_JumpInPlaceUp
# 122 "data/maps/SootopolisCity_House2/scripts.pory"
	waitmovement 0
	return


UltimateTutor_EventScript_JumpInPlaceLeft::
# 127 "data/maps/SootopolisCity_House2/scripts.pory"
	applymovement LOCALID_ULTIMATE_TUTOR, Movement_JumpInPlaceLeft
# 128 "data/maps/SootopolisCity_House2/scripts.pory"
	waitmovement 0
	return


UltimateTutor_EventScript_JumpInPlaceRight::
# 133 "data/maps/SootopolisCity_House2/scripts.pory"
	applymovement LOCALID_ULTIMATE_TUTOR, Movement_JumpInPlaceRight
# 134 "data/maps/SootopolisCity_House2/scripts.pory"
	waitmovement 0
	return


# 138 "data/maps/SootopolisCity_House2/scripts.pory"
Movement_JumpInPlaceDown:
# 139 "data/maps/SootopolisCity_House2/scripts.pory"
	jump_in_place_down
# 140 "data/maps/SootopolisCity_House2/scripts.pory"
	step_end

# 143 "data/maps/SootopolisCity_House2/scripts.pory"
Movement_JumpInPlaceUp:
# 144 "data/maps/SootopolisCity_House2/scripts.pory"
	jump_in_place_up
# 145 "data/maps/SootopolisCity_House2/scripts.pory"
	step_end

# 148 "data/maps/SootopolisCity_House2/scripts.pory"
Movement_JumpInPlaceLeft:
# 149 "data/maps/SootopolisCity_House2/scripts.pory"
	jump_in_place_left
# 150 "data/maps/SootopolisCity_House2/scripts.pory"
	step_end

# 153 "data/maps/SootopolisCity_House2/scripts.pory"
Movement_JumpInPlaceRight:
# 154 "data/maps/SootopolisCity_House2/scripts.pory"
	jump_in_place_right
# 155 "data/maps/SootopolisCity_House2/scripts.pory"
	step_end

SootopolisCity_House2_EventScript_UltimateMoveTutor_Text_0:
# 63 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "You mean it?\n"
	.string "You will let me teach the ultimate move?\p"
	.string "Which move would you like to teach?$"

SootopolisCity_House2_EventScript_ChooseMove_Text_0:
# 89 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Frenzy Plant$"

SootopolisCity_House2_EventScript_ChooseMove_Text_1:
# 90 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Blast Burn$"

SootopolisCity_House2_EventScript_ChooseMove_Text_2:
# 91 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Hydro Cannon$"

SootopolisCity_House2_Text_UltimateMoveTutorIntro::
# 158 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "I perfected the ultimate move of\n"
	.string "its type…\p"
	.string "But will no one take it for\n"
	.string "future use?\p"
	.string "Will you allow it?\p"
	.string "Will you allow your Pokémon to\n"
	.string "learn my ultimate move?$"

SootopolisCity_House2_Text_UltimateMoveTutorJustMistaken::
# 168 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "…No…\n"
	.string "I was just mistaken.$"

SootopolisCity_House2_Text_YouRejectIt::
# 173 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Gaah! You reject it?\n"
	.string "No, I won't be dissuaded!$"

SootopolisCity_House2_Text_WhichPokemonToTeach::
# 178 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Will you teach your Pokémon\n"
	.string "{STR_VAR_2}?$"

SootopolisCity_House2_Text_ChooseAPokemon::
# 183 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Please chose a Pokémon to learn\n"
	.string "{STR_VAR_2}.$"

SootopolisCity_House2_Text_TaughtMove::
# 187 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Gasp, gasp, gasp…\p"
	.string "I didn't think I could teach that\n"
	.string "move while I still lived…$"

SootopolisCity_House2_Text_MakeBestUseOfMove::
# 193 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "I implore you to make the best\n"
	.string "use of that move and gain power!$"
