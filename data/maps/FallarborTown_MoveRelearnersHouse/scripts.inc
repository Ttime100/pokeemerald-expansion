# 1 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 2 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_MapScripts::
# 3 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.byte 0
# 4 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 5 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
# 6 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	lockall
# 7 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
# 8 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitmovement 0
# 9 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
# 10 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
# 11 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_TEMP_1
# 12 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
# 13 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 14 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 15 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
# 16 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	checkitem ITEM_HEART_SCALE
# 17 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 18 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
# 19 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	switch VAR_RESULT
# 20 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 21 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 22 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 23 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 24 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
# 25 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
# 26 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setmoverelearnerstate MOVE_RELEARNER_LEVEL_UP_MOVES @ Specifically supposed to teach level up moves
# 27 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	chooseboxmon SELECT_PC_MON_MOVE_RELEARNER
# 28 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitstate
# 29 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 30 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special IsSelectedMonEgg
# 31 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
# 32 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special Special_HasMoveToRelearn
# 33 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
# 34 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
# 35 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 36 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 37 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
# 38 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
# 39 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	special TeachMoveRelearnerMove
# 40 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 41 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
# 42 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	removeitem ITEM_HEART_SCALE
# 43 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
# 44 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 45 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 46 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
# 47 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
# 48 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 49 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 50 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 51 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
# 52 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
# 53 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
# 54 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 55 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 56 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
# 57 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
# 58 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	releaseall
# 59 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	end
# 60 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 61 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor:
# 62 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I'm the Move Tutor.\p"
# 63 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I know all the moves that Pokémon\n"
# 64 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "learn--every one of them--and I can\l"
# 65 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "teach Pokémon those moves.\p"
# 66 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I can teach a move to a Pokémon\n"
# 67 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "of yours if you'd like.\p"
# 68 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I'll do it for a Heart Scale.\n"
# 69 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I'm collecting those now.$"
# 70 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 71 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove:
# 72 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Oh! That's it! That's an honest to\n"
# 73 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "goodness Heart Scale!\p"
# 74 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Let me guess, you want me to teach\n"
# 75 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "a move?$"
# 76 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 77 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon:
# 78 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Which Pokémon needs tutoring?$"
# 79 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 80 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove:
# 81 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Which move should I teach?$"
# 82 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 83 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon:
# 84 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Sorry…\p"
# 85 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "It doesn't appear as if I have any move\n"
# 86 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I can teach that Pokémon.$"
# 87 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 88 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale:
# 89 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{PLAYER} handed over one Heart Scale\n"
# 90 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "in exchange.$"
# 91 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 92 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale:
# 93 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "If your Pokémon need to learn a move,\n"
# 94 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "come back with a Heart Scale.$"
# 95 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"

# 96 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg:
# 97 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Hunh? There isn't a single move that\n"
# 98 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I can teach an egg.$"

FallarborTown_MoveRelearner_EventScript_HeartScaleCollector::
# 106 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	lock
# 107 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	faceplayer
# 108 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearner_EventScript_HeartScaleCollector_2
FallarborTown_MoveRelearner_EventScript_HeartScaleCollector_1:
# 111 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_HeartScalesForPokemon
# 112 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setflag FLAG_TEMP_1
# 113 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	call FallarborTown_MoveRelearner_EventScript_AskForTrade
# 114 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	release
	end

FallarborTown_MoveRelearner_EventScript_HeartScaleCollector_2:
# 109 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	call FallarborTown_MoveRelearner_EventScript_AskForTrade
	goto FallarborTown_MoveRelearner_EventScript_HeartScaleCollector_1


FallarborTown_MoveRelearner_EventScript_AskForTrade::
# 119 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	checkitem ITEM_HEART_SCALE, 3
# 120 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FallarborTown_MoveRelearner_EventScript_AskForTrade_2
# 125 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantARarePokemon, MSGBOX_YESNO
# 126 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FallarborTown_MoveRelearner_EventScript_AskForTrade_5
# 131 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
PokemonSelectionMenu:
# 132 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_0
# 133 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	dynmultipush FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_1, SPECIES_BULBASAUR
# 134 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	dynmultipush FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_2, SPECIES_CHARMANDER
# 135 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	dynmultipush FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_3, SPECIES_SQUIRTLE
# 136 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	dynmultipush FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_4, SPECIES_CHIKORITA
# 137 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	dynmultipush FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_5, SPECIES_CYNDAQUIL
# 138 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	dynmultipush FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_6, SPECIES_TOTODILE
# 139 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, SPECIES_BULBASAUR, 0
# 140 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq FallarborTown_MoveRelearner_EventScript_AskForTrade_8
# 145 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 146 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_TEMP_2
# 147 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_7, MSGBOX_YESNO
# 148 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_MoveRelearner_EventScript_AskForTrade_11
FallarborTown_MoveRelearner_EventScript_AskForTrade_10:
# 151 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_MakeItShiny, MSGBOX_YESNO
# 152 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitmessage
# 153 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	copyvar VAR_TEMP_4, VAR_RESULT
# 154 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_TEMP_4, 0
	goto_if_ne FallarborTown_MoveRelearner_EventScript_AskForTrade_14
# 158 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_TEMP_3, 3
FallarborTown_MoveRelearner_EventScript_AskForTrade_13:
# 160 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	checkitem ITEM_HEART_SCALE, VAR_TEMP_3
# 161 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq FallarborTown_MoveRelearner_EventScript_AskForTrade_18
# 167 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	removeitem ITEM_HEART_SCALE, VAR_TEMP_3
# 169 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	compare VAR_TEMP_4, TRUE
	goto_if_eq FallarborTown_MoveRelearner_EventScript_AskForTrade_22
# 173 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	givemon VAR_TEMP_2, 10, ITEM_LUM_BERRY, ITEM_CHERISH_BALL
FallarborTown_MoveRelearner_EventScript_AskForTrade_21:
# 175 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 176 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_PlayerReceivedPokemon
# 177 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitfanfare
# 178 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_TEMP_3
# 179 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScales
# 180 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	waitmessage
# 181 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_8
# 182 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	release
	end

FallarborTown_MoveRelearner_EventScript_AskForTrade_2:
# 121 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScales
# 122 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	release
	end

FallarborTown_MoveRelearner_EventScript_AskForTrade_5:
# 127 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_OhThatsAShame
# 128 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	release
	end

FallarborTown_MoveRelearner_EventScript_AskForTrade_8:
# 141 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_OhThatsAShame
# 142 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	release
	end

FallarborTown_MoveRelearner_EventScript_AskForTrade_11:
# 149 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	goto PokemonSelectionMenu
	goto FallarborTown_MoveRelearner_EventScript_AskForTrade_10

FallarborTown_MoveRelearner_EventScript_AskForTrade_14:
# 155 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	setvar VAR_TEMP_3, 4
	goto FallarborTown_MoveRelearner_EventScript_AskForTrade_13

FallarborTown_MoveRelearner_EventScript_AskForTrade_18:
# 162 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	msgbox FallarborTown_MoveRelearnersHouse_Text_NotEnough
# 163 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	release
	end

FallarborTown_MoveRelearner_EventScript_AskForTrade_22:
# 170 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	givemon VAR_TEMP_2, 10, ITEM_LUM_BERRY, ITEM_CHERISH_BALL, shinyMode = SHINY_MODE_ALWAYS
	goto FallarborTown_MoveRelearner_EventScript_AskForTrade_21


FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_0:
# 132 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Which Pokémon would you like?$"

FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_1:
# 133 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Bulbasaur$"

FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_2:
# 134 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Charmander$"

FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_3:
# 135 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Squirtle$"

FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_4:
# 136 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Chikorita$"

FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_5:
# 137 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Cyndaquil$"

FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_6:
# 138 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Totodile$"

FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_7:
# 147 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "So your choice is {STR_VAR_1}?$"

FallarborTown_MoveRelearner_EventScript_AskForTrade_Text_8:
# 181 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Enjoy your {STR_VAR_1}!$"

FallarborTown_MoveRelearnersHouse_Text_HeartScalesForPokemon::
# 186 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "I'm a collector of rare Pokémon.\p"
	.string "The only thing I enjoy collecting more\n"
	.string "than rare Pokémon are Heart Scales.\p"
	.string "You wouldn't happen to have any,\n"
	.string "would you?\p"
	.string "If you do, I might be willing\n"
	.string "to make a trade.$"

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantARarePokemon::
# 194 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Oh! That's it! Those are honest\n"
	.string "to goodness Heart Scales!\p"
	.string "I would be willing to give you one of\n"
	.string "my rare Pokémon for three Heart Scales.\p"
	.string "If you give me a forth one,\n"
	.string "I can even guarantee it to be shiny!\p"
	.string "What do you say?$"

FallarborTown_MoveRelearnersHouse_Text_MakeItShiny::
# 202 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Do you want to make it shiny\n"
	.string "for one more Heart Scale?$"

FallarborTown_MoveRelearnersHouse_Text_OhThatsAShame::
# 206 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "Oh... That's a shame.\p"
	.string "If you change your mind,\n"
	.string "come back with some Heart Scales.$"

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScales::
# 211 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "If you want some rare Pokémon, come\n"
	.string "back with at least three Heart Scales.$"

FallarborTown_MoveRelearnersHouse_Text_NotEnough::
# 215 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "You do not have enough Heart Scales\n"
	.string "for this option.$"

FallarborTown_MoveRelearnersHouse_Text_PlayerReceivedPokemon::
# 219 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{PLAYER} received {STR_VAR_1}!$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScales::
# 223 "data/maps/FallarborTown_MoveRelearnersHouse/scripts.pory"
	.string "{PLAYER} handed over {STR_VAR_2} Heart Scales.$"
