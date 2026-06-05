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
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
# 20 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special IsSelectedMonEgg
# 21 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves
# 22 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special GetNumMovesSelectedMonHas
# 23 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, 1, LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove
# 24 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten, MSGBOX_DEFAULT
# 25 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	fadescreen FADE_TO_BLACK
# 26 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special MoveDeleterChooseMoveToForget
# 27 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 28 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_0x8005, MAX_MON_MOVES, LilycoveCity_MoveDeletersHouse_EventScript_ChooseMonAndMoveToForget
# 29 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 30 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten, MSGBOX_YESNO
# 31 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	switch VAR_RESULT
# 32 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case YES, LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove
# 33 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	case NO, LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain
# 34 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 35 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 36 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 37 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_TryForgetMove::
# 38 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special IsLastMonThatKnowsSurf
# 39 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf
# 40 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special MoveDeleterForgetMove
# 41 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	playfanfare MUS_MOVE_DELETED
# 42 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	waitfanfare
# 43 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove, MSGBOX_DEFAULT
# 44 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 45 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 46 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 47 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_MonOnlyKnowsOneMove::
# 48 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 49 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove, MSGBOX_DEFAULT
# 50 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 51 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 52 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 53 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_EggCantForgetMoves::
# 54 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves, MSGBOX_DEFAULT
# 55 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 56 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 57 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 58 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_ComeAgain::
# 59 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_ComeAgain, MSGBOX_DEFAULT
# 60 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 61 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 62 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 63 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_EventScript_LastMonWithSurf::
# 64 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special BufferMoveDeleterNicknameAndMove
# 65 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf, MSGBOX_DEFAULT
# 66 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	releaseall
# 67 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	end
# 68 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 69 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_ICanMakeMonForgetMove:
# 70 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Uh…\n"
# 71 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Oh, yes, I'm the Move Deleter.\p"
# 72 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "I can make Pokémon forget their moves.\p"
# 73 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Would you like me to do that?$"
# 74 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 75 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_WhichMonShouldForget:
# 76 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Which Pokémon should forget a move?$"
# 77 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 78 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_WhichMoveShouldBeForgotten:
# 79 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Which move should be forgotten?$"
# 80 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 81 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_MonOnlyKnowsOneMove:
# 82 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_1} knows only one move\n"
# 83 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "so it can't be forgotten…$"
# 84 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 85 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_MonsMoveShouldBeForgotten:
# 86 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Hm! {STR_VAR_1}'s {STR_VAR_2}?\n"
# 87 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "That move should be forgotten?$"
# 88 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 89 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_MonHasForgottenMove:
# 90 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "It worked to perfection!\p"
# 91 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_1} has forgotten\n"
# 92 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_2} completely.$"
# 93 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 94 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_ComeAgain:
# 95 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Come again if there are moves that\n"
# 96 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "need to be forgotten.$"
# 97 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 98 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_EggCantForgetMoves:
# 99 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "What?\n"
# 100 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "No egg should know any moves.$"
# 101 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"

# 102 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
LilycoveCity_MoveDeletersHouse_Text_CantForgetSurf:
# 103 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Hm!\p"
# 104 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Your {STR_VAR_1} doesn't seem willing\n"
# 105 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "to forget Surf.$"

LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer::
# 113 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	lock
# 114 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	faceplayer
# 115 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	goto_if_set FLAG_TEMP_HYPTRN, LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_2
# 119 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	call Introduction
LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_1:
# 121 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	checkitem ITEM_GOLD_BOTTLE_CAP
# 122 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_6
LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_5:
# 125 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	checkitem ITEM_BOTTLE_CAP
# 126 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_9
LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_8:
# 129 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_Text_0
# 130 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end

LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_2:
# 116 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	call ShortGreeting
	goto LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_1

LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_6:
# 123 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	call HypertrainAll
	goto LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_5

LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_9:
# 127 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	call HypertrainOne
	goto LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_8


Introduction::
# 135 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox Introduction_Text_0
# 139 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox Introduction_Text_1
# 141 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	setflag FLAG_TEMP_HYPTRN
	return


ShortGreeting::
# 145 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox ShortGreeting_Text_0
	return


HypertrainAll::
# 149 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_0, MSGBOX_YESNO
# 152 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq HypertrainAll_2
# 156 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_2
# 157 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special ChoosePartyMon
# 158 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq HypertrainAll_5
# 163 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	copyvar VAR_TEMP_1, VAR_0x8004
# 164 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_TEMP_1
# 165 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_4, MSGBOX_YESNO
# 166 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq HypertrainAll_8
# 171 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	removeitem ITEM_GOLD_BOTTLE_CAP
# 172 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hypertrain STAT_HP, VAR_TEMP_1
# 173 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hypertrain STAT_ATK, VAR_TEMP_1
# 174 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hypertrain STAT_DEF, VAR_TEMP_1
# 175 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hypertrain STAT_SPATK, VAR_TEMP_1
# 176 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hypertrain STAT_SPDEF, VAR_TEMP_1
# 177 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hypertrain STAT_SPEED, VAR_TEMP_1
# 178 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_5
# 179 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end

HypertrainAll_2:
# 153 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_1
	return

HypertrainAll_5:
# 159 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_3
# 160 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end

HypertrainAll_8:
# 167 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_3
# 168 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end


HypertrainOne::
# 184 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainOne_Text_0, MSGBOX_YESNO
# 186 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq HypertrainOne_2
# 191 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainOne_Text_1
# 192 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	special ChoosePartyMon
# 193 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq HypertrainOne_5
# 198 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	copyvar VAR_TEMP_1, VAR_0x8004
# 199 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	bufferpartymonnick STR_VAR_1, VAR_TEMP_1
# 200 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	dynmultipush HypertrainOne_Text_2, STAT_HP
# 201 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	dynmultipush HypertrainOne_Text_3, STAT_ATK
# 202 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	dynmultipush HypertrainOne_Text_4, STAT_DEF
# 203 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	dynmultipush HypertrainOne_Text_5, STAT_SPATK
# 204 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	dynmultipush HypertrainOne_Text_6, STAT_SPDEF
# 205 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	dynmultipush HypertrainOne_Text_7, STAT_SPEED
# 206 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, 0, 0
# 207 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq HypertrainOne_8
# 212 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	copyvar VAR_TEMP_2, VAR_RESULT
# 213 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	canhypertrain VAR_TEMP_2, VAR_TEMP_1
# 214 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	copyvar VAR_TEMP_3, VAR_RESULT
# 215 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	compare VAR_TEMP_3, 0
	goto_if_eq HypertrainOne_11
# 218 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	removeitem ITEM_BOTTLE_CAP
# 219 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	hypertrain VAR_TEMP_2, VAR_TEMP_1
HypertrainOne_10:
# 220 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainOne_Text_9
# 223 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end

HypertrainOne_2:
# 187 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_3
# 188 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end

HypertrainOne_5:
# 194 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_3
# 195 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end

HypertrainOne_8:
# 208 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainAll_Text_3
# 209 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	release
	end

HypertrainOne_11:
# 216 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	msgbox HypertrainOne_Text_8
	goto HypertrainOne_10


LilycoveCity_MoveDeletersHouse_EventScript_HyperTrainer_Text_0:
# 129 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "It doesn't look like you have any Bottle\n"
	.string "Caps.\p"
	.string "Come back when you do!$"

Introduction_Text_0:
# 135 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Hello!\p"
	.string "I used to be the move deleter, but now\n"
	.string "that HMs are deletable, that job has\l"
	.string "become obsolete...\p"
	.string "Now I'm a hyper trainer!$"

Introduction_Text_1:
# 139 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "For the cost of a Bottle Cap,\n"
	.string "I can hypertrain one of your Pokémon's\l"
	.string "stats.$"

ShortGreeting_Text_0:
# 145 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "I can hypertrain your Pokémon's stats\n"
	.string "if you have a Bottle Cap.$"

HypertrainAll_Text_0:
# 149 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Oooo! You have a Gold Bottle Cap.\n"
	.string "Those are quite rare!\p"
	.string "I tell you what, I can hyper train all of\n"
	.string "the stats of one of your Pokémon for\l"
	.string "that!\p"
	.string "What do you say?$"

HypertrainAll_Text_1:
# 153 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Aww... Fine...\p"
	.string "Well do you at least have a regular\n"
	.string "Bottle Cap then?$"

HypertrainAll_Text_2:
# 156 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Please select the Pokémon you would\n"
	.string "like to hyper train.$"

HypertrainAll_Text_3:
# 159 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "If you change your mind, I am always\n"
	.string "ready to train!$"

HypertrainAll_Text_4:
# 165 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "So you would like me to hyper train all\n"
	.string "of {STR_VAR_1}'s stats?$"

HypertrainAll_Text_5:
# 178 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Your {STR_VAR_1} has maximized its\n"
	.string "training!$"

HypertrainOne_Text_0:
# 184 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Oh! It looks like you have a Bottle Cap!\n"
	.string "Would you like me to hyper train one of\l"
	.string "your Pokémon's stats?$"

HypertrainOne_Text_1:
# 191 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Which Pokémon would you like to hyper\n"
	.string "train?$"

HypertrainOne_Text_2:
# 200 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "HP$"

HypertrainOne_Text_3:
# 201 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Attack$"

HypertrainOne_Text_4:
# 202 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Defense$"

HypertrainOne_Text_5:
# 203 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Sp. Atk$"

HypertrainOne_Text_6:
# 204 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Sp. Def$"

HypertrainOne_Text_7:
# 205 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Speed$"

HypertrainOne_Text_8:
# 216 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "Sorry, that stat has already reached\n"
	.string "it's full potential.$"

HypertrainOne_Text_9:
# 220 "data/maps/LilycoveCity_MoveDeletersHouse/scripts.pory"
	.string "{STR_VAR_1} has been hyper trained!\p"
	.string "If you ever want to hyper train any\n"
	.string "more Pokémon, just bring me a Bottle\l"
	.string "Cap!$"
