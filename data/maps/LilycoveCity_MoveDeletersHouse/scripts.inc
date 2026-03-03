# 1 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 2 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_MapScripts::
# 3 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.byte 0
# 4 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 5 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_MoveDeleter::
# 6 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	lockall
# 7 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	applymovement LOCALID_MOVE_DELETER, Common_Movement_FacePlayer
# 8 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitmovement 0
# 9 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove, MSGBOX_YESNO
# 10 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	switch VAR_RESULT
# 11 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
# 12 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
# 13 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 14 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 15 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 16 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget::
# 17 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget, MSGBOX_DEFAULT
# 18 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special ChoosePartyMon
# 19 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitstate
# 20 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
# 21 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special IsSelectedMonEgg
# 22 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
# 23 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special GetNumMovesSelectedMonHas
# 24 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
# 25 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
# 26 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 27 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special MoveDeleterChooseMoveToForget
# 28 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 29 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
# 30 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 31 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
# 32 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	switch VAR_RESULT
# 33 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove
# 34 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
# 35 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 36 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 37 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 38 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove::
# 39 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special IsLastMonThatKnowsSurf
# 40 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf
# 41 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special MoveDeleterForgetMove
# 42 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	playfanfare MUS_MOVE_DELETED
# 43 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitfanfare
# 44 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
# 45 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 46 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 47 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 48 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
# 49 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 50 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
# 51 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 52 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 53 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 54 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
# 55 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
# 56 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 57 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 58 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 59 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain::
# 60 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
# 61 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 62 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 63 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 64 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
# 65 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 66 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
# 67 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 68 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 69 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 70 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
# 71 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Uh…\n"
# 72 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Oh, yes, I'm the Move Deleter.\p"
# 73 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "I can make Pokémon forget their moves.\p"
# 74 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Would you like me to do that?$"
# 75 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 76 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget:
# 77 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Which Pokémon should forget a move?$"
# 78 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 79 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
# 80 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Which move should be forgotten?$"
# 81 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 82 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
# 83 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_1} knows only one move\n"
# 84 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "so it can't be forgotten…$"
# 85 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 86 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
# 87 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
# 88 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "That move should be forgotten?$"
# 89 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 90 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove:
# 91 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "It worked to perfection!\p"
# 92 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_1} has forgotten\n"
# 93 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_2} completely.$"
# 94 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 95 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_ComeAgain:
# 96 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Come again if there are moves that\n"
# 97 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "need to be forgotten.$"
# 98 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 99 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves:
# 100 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "What?\n"
# 101 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "No egg should know any moves.$"
# 102 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 103 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf:
# 104 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Hm!\p"
# 105 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
# 106 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "to forget Surf.$"

LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer::
# 114 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	lock
# 115 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	faceplayer
# 116 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_set FLAG_TEMP_HYPTRN, LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_2
# 120 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	call Introduction
LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_1:
# 122 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	checkitem ITEM_GOLD_BOTTLE_CAP
# 123 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_6
LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_5:
# 126 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	checkitem ITEM_BOTTLE_CAP
# 127 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_9
LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_8:
# 130 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_Text_0
# 131 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end

LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_2:
# 117 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	call ShortGreeting
	goto LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_1

LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_6:
# 124 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	call HypertrainAll
	goto LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_5

LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_9:
# 128 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	call HypertrainOne
	goto LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_8


Introduction::
# 136 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox Introduction_Text_0
# 140 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox Introduction_Text_1
# 142 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	setflag FLAG_TEMP_HYPTRN
	return


ShortGreeting::
# 146 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox ShortGreeting_Text_0
	return


HypertrainAll::
# 150 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_0, MSGBOX_YESNO
# 153 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq HypertrainAll_2
# 157 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_2
# 158 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special ChoosePartyMon
# 159 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitstate
# 160 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq HypertrainAll_5
# 165 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	copyvar VAR_TEMP_1, VAR_0x8004
# 166 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_TEMP_1
# 167 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_4, MSGBOX_YESNO
# 168 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq HypertrainAll_8
# 173 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	removeitem ITEM_GOLD_BOTTLE_CAP
# 174 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hypertrain STAT_HP, VAR_TEMP_1
# 175 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hypertrain STAT_ATK, VAR_TEMP_1
# 176 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hypertrain STAT_DEF, VAR_TEMP_1
# 177 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hypertrain STAT_SPATK, VAR_TEMP_1
# 178 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hypertrain STAT_SPDEF, VAR_TEMP_1
# 179 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hypertrain STAT_SPEED, VAR_TEMP_1
# 180 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_5
# 181 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end

HypertrainAll_2:
# 154 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_1
	return

HypertrainAll_5:
# 161 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_3
# 162 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end

HypertrainAll_8:
# 169 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_3
# 170 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end


HypertrainOne::
# 186 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainOne_Text_0, MSGBOX_YESNO
# 188 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq HypertrainOne_2
# 193 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainOne_Text_1
# 194 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special ChoosePartyMon
# 195 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitstate
# 196 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq HypertrainOne_5
# 201 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	copyvar VAR_TEMP_1, VAR_0x8004
# 202 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_TEMP_1
# 203 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	dynmultipush HypertrainOne_Text_2, STAT_HP
# 204 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	dynmultipush HypertrainOne_Text_3, STAT_ATK
# 205 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	dynmultipush HypertrainOne_Text_4, STAT_DEF
# 206 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	dynmultipush HypertrainOne_Text_5, STAT_SPATK
# 207 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	dynmultipush HypertrainOne_Text_6, STAT_SPDEF
# 208 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	dynmultipush HypertrainOne_Text_7, STAT_SPEED
# 209 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, 0
# 210 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq HypertrainOne_8
# 215 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 216 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	canhypertrain VAR_TEMP_2, VAR_TEMP_1
# 217 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 218 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_TEMP_3, 0
	goto_if_eq HypertrainOne_11
# 221 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	removeitem ITEM_BOTTLE_CAP
# 222 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hypertrain VAR_TEMP_2, VAR_TEMP_1
HypertrainOne_10:
# 223 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainOne_Text_9
# 226 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end

HypertrainOne_2:
# 189 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_3
# 190 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end

HypertrainOne_5:
# 197 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_3
# 198 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end

HypertrainOne_8:
# 211 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_3
# 212 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end

HypertrainOne_11:
# 219 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainOne_Text_8
	goto HypertrainOne_10


LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_Text_0:
# 130 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "It doesn't look like you have any Bottle\n"
	.string "Caps.\p"
	.string "Come back when you do!$"

Introduction_Text_0:
# 136 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Hello!\p"
	.string "I used to be the move deleter, but now\n"
	.string "that HMs are deletable, that job has\l"
	.string "become obsolete...\p"
	.string "Now I'm a hyper trainer!$"

Introduction_Text_1:
# 140 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "For the cost of a Bottle Cap,\n"
	.string "I can hypertrain one of your Pokémon's\l"
	.string "stats.$"

ShortGreeting_Text_0:
# 146 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "I can hypertrain your Pokémon's stats\n"
	.string "if you have a Bottle Cap.$"

HypertrainAll_Text_0:
# 150 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Oooo! You have a Gold Bottle Cap.\n"
	.string "Those are quite rare!\p"
	.string "I tell you what, I can hyper train all of\n"
	.string "the stats of one of your Pokémon for\l"
	.string "that!\p"
	.string "What do you say?$"

HypertrainAll_Text_1:
# 154 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Aww... Fine...\p"
	.string "Well do you at least have a regular\n"
	.string "Bottle Cap then?$"

HypertrainAll_Text_2:
# 157 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Please select the Pokémon you would\n"
	.string "like to hyper train.$"

HypertrainAll_Text_3:
# 161 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "If you change your mind, I am always\n"
	.string "ready to train!$"

HypertrainAll_Text_4:
# 167 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "So you would like me to hyper train all\n"
	.string "of {STR_VAR_1}'s stats?$"

HypertrainAll_Text_5:
# 180 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Your {STR_VAR_1} has maximized its\n"
	.string "training!$"

HypertrainOne_Text_0:
# 186 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Oh! It looks like you have a Bottle Cap!\n"
	.string "Would you like me to hyper train one of\l"
	.string "your Pokémon's stats?$"

HypertrainOne_Text_1:
# 193 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Which Pokémon would you like to hyper\n"
	.string "train?$"

HypertrainOne_Text_2:
# 203 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "HP$"

HypertrainOne_Text_3:
# 204 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Attack$"

HypertrainOne_Text_4:
# 205 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Defense$"

HypertrainOne_Text_5:
# 206 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Sp. Atk$"

HypertrainOne_Text_6:
# 207 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Sp. Def$"

HypertrainOne_Text_7:
# 208 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Speed$"

HypertrainOne_Text_8:
# 219 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Sorry, that stat has already reached\n"
	.string "it's full potential.$"

HypertrainOne_Text_9:
# 223 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_1} has been hyper trained!\p"
	.string "If you ever want to hyper train any\n"
	.string "more Pokémon, just bring me a Bottle\l"
	.string "Cap!$"
