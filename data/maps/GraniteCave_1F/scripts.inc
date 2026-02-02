# 1 "data/maps/GraniteCave_1F/scripts.pory"

# 2 "data/maps/GraniteCave_1F/scripts.pory"
GraniteCave_1F_MapScripts::
# 3 "data/maps/GraniteCave_1F/scripts.pory"
	.byte 0
# 4 "data/maps/GraniteCave_1F/scripts.pory"

# 5 "data/maps/GraniteCave_1F/scripts.pory"
GraniteCave_1F_EventScript_Hiker::
# 6 "data/maps/GraniteCave_1F/scripts.pory"
	lock
# 7 "data/maps/GraniteCave_1F/scripts.pory"
	faceplayer
# 8 "data/maps/GraniteCave_1F/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
# 9 "data/maps/GraniteCave_1F/scripts.pory"
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
# 10 "data/maps/GraniteCave_1F/scripts.pory"
	giveitem ITEM_HM_FLASH
# 11 "data/maps/GraniteCave_1F/scripts.pory"
    giveitem ITEM_ESCAPE_ROPE
# 12 "data/maps/GraniteCave_1F/scripts.pory"
	setflag FLAG_RECEIVED_HM_FLASH
# 13 "data/maps/GraniteCave_1F/scripts.pory"
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
# 14 "data/maps/GraniteCave_1F/scripts.pory"
	release
# 15 "data/maps/GraniteCave_1F/scripts.pory"
	end
# 16 "data/maps/GraniteCave_1F/scripts.pory"

# 17 "data/maps/GraniteCave_1F/scripts.pory"
GraniteCave_1F_EventScript_ReceivedFlash::
# 18 "data/maps/GraniteCave_1F/scripts.pory"
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
# 19 "data/maps/GraniteCave_1F/scripts.pory"
	release
# 20 "data/maps/GraniteCave_1F/scripts.pory"
	end
# 21 "data/maps/GraniteCave_1F/scripts.pory"

# 22 "data/maps/GraniteCave_1F/scripts.pory"
GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
# 23 "data/maps/GraniteCave_1F/scripts.pory"
	.string "Hey, you.\n"
# 24 "data/maps/GraniteCave_1F/scripts.pory"
	.string "It gets awfully dark ahead.\l"
# 25 "data/maps/GraniteCave_1F/scripts.pory"
	.string "It'll be tough trying to explore.\p"
# 26 "data/maps/GraniteCave_1F/scripts.pory"
	.string "That guy who came by earlier…\n"
# 27 "data/maps/GraniteCave_1F/scripts.pory"
	.string "Steven, I think it was.\p"
# 28 "data/maps/GraniteCave_1F/scripts.pory"
	.string "He knew how to use Flash, so he ought\n"
# 29 "data/maps/GraniteCave_1F/scripts.pory"
	.string "to be all right, but…\p"
# 30 "data/maps/GraniteCave_1F/scripts.pory"
	.string "Well, for us Hikers, helping out those\n"
# 31 "data/maps/GraniteCave_1F/scripts.pory"
	.string "that we meet is our motto.\p"
# 32 "data/maps/GraniteCave_1F/scripts.pory"
	.string "Here you go, I'll pass these on to you.$"
# 33 "data/maps/GraniteCave_1F/scripts.pory"

# 34 "data/maps/GraniteCave_1F/scripts.pory"
GraniteCave_1F_Text_ExplainFlash:
# 35 "data/maps/GraniteCave_1F/scripts.pory"
    .string "That Escape Rope will help you\n"
# 36 "data/maps/GraniteCave_1F/scripts.pory"
    .string "get out of any cave in a pinch.\p"
# 37 "data/maps/GraniteCave_1F/scripts.pory"
	.string "Teach that hidden move Flash to\n"
# 38 "data/maps/GraniteCave_1F/scripts.pory"
	.string "a Pokémon and use it.\p"
# 39 "data/maps/GraniteCave_1F/scripts.pory"
	.string "It lights up even the inky darkness\n"
# 40 "data/maps/GraniteCave_1F/scripts.pory"
	.string "of caves.\p"
# 41 "data/maps/GraniteCave_1F/scripts.pory"
	.string "But, to use it, you need the Gym Badge\n"
# 42 "data/maps/GraniteCave_1F/scripts.pory"
	.string "from Dewford's Pokémon Gym.$"
