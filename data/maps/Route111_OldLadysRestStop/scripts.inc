# 1 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 2 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_MapScripts::
# 3 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
# 4 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.byte 0
# 5 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 6 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_OnTransition:
# 7 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
# 8 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	end
# 9 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 10 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_EventScript_OldLady::
# 11 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	lock
# 12 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	faceplayer
# 13 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
# 14 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
# 15 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
# 16 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	end
# 17 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 18 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_EventScript_Rest::
# 19 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
# 20 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	closemessage
# 21 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 22 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
# 23 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
# 24 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
# 25 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	end
# 26 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 27 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_EventScript_DeclineRest::
# 28 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
# 29 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	release
# 30 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	end
# 31 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 32 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_Text_RestUpHere:
# 33 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "Oh, dear, dear.\n"
# 34 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "Aren't your Pokémon exhausted?\p"
# 35 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "If you'd like, rest up here.\n"
# 36 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "That's a fine idea! You should do that.$"
# 37 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 38 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
# 39 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "That's right.\n"
# 40 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "Take your time and rest up!$"
# 41 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 42 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
# 43 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "Oh, dear, dear.\n"
# 44 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "Are your Pokémon still tired?\p"
# 45 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "You should take another rest here.\n"
# 46 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "That's a fine idea. You should do that.$"
# 47 "data/maps/Route111_OldLadysRestStop/scripts.pory"

# 48 "data/maps/Route111_OldLadysRestStop/scripts.pory"
Route111_OldLadysRestStop_Text_DontNeedToBeShy:
# 49 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "Is that so?\n"
# 50 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "You don't need to be shy about it.\l"
# 51 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "I could make some tea…$"

Route111_CarePackageLady::
# 55 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	lock
# 56 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	faceplayer
# 57 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	goto_if_unset FLAG_RECEIVED_CARE_PACKAGE_ROUTE_111, Route111_CarePackageLady_2
Route111_CarePackageLady_1:
# 67 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	msgbox Route111_CarePackageLady_Text_BeCareful
# 68 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	closemessage
# 69 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	release
	end

Route111_CarePackageLady_2:
# 58 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	msgbox Route111_CarePackageLady_Text_Intro
# 59 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	closemessage
# 60 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	giveitem ITEM_LEMONADE, 10
# 61 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	giveitem ITEM_PEWTER_CRUNCHIES, 10
# 62 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	giveitem ITEM_REVIVE, 5
# 63 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	giveitem ITEM_RARE_CANDY, 10
# 64 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	giveitem ITEM_BIG_NUGGET
# 65 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	setflag FLAG_RECEIVED_CARE_PACKAGE_ROUTE_111
	goto Route111_CarePackageLady_1


Route111_CarePackageLady_Text_Intro::
# 73 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "Oh, my! You look like you’ve walked\n"
	.string "halfway across Hoenn.\p"
	.string "Between the steep ridges and the soot\n"
	.string "falling from the mountain,\p"
	.string "a young Trainer can get\n"
	.string "worn down quickly.\p"
	.string "Here, take these to keep up your\n"
	.string "strength.$"

Route111_CarePackageLady_Text_BeCareful::
# 80 "data/maps/Route111_OldLadysRestStop/scripts.pory"
	.string "The road to Fallarbor is a long one. The\n"
	.string "air gets quite chilly near the craters.\p"
	.string "Keep your Pokémon warm, dear.$"
