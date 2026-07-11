# 1 "data/maps/PacifidlogTown/scripts.pory"

# 2 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_MapScripts::
# 3 "data/maps/PacifidlogTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
# 4 "data/maps/PacifidlogTown/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
# 5 "data/maps/PacifidlogTown/scripts.pory"
	.byte 0
# 6 "data/maps/PacifidlogTown/scripts.pory"

# 7 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_OnTransition:
# 8 "data/maps/PacifidlogTown/scripts.pory"
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
# 9 "data/maps/PacifidlogTown/scripts.pory"
	end
# 10 "data/maps/PacifidlogTown/scripts.pory"

# 11 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_OnResume:
# 12 "data/maps/PacifidlogTown/scripts.pory"
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
# 13 "data/maps/PacifidlogTown/scripts.pory"
	end
# 14 "data/maps/PacifidlogTown/scripts.pory"

# 15 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_NinjaBoy::
# 16 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
# 17 "data/maps/PacifidlogTown/scripts.pory"
	end
# 18 "data/maps/PacifidlogTown/scripts.pory"

# 19 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Girl::
# 20 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
# 21 "data/maps/PacifidlogTown/scripts.pory"
	end
# 22 "data/maps/PacifidlogTown/scripts.pory"

# 23 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Fisherman::
# 24 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
# 25 "data/maps/PacifidlogTown/scripts.pory"
	end
# 26 "data/maps/PacifidlogTown/scripts.pory"

# 27 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_TownSign::
# 28 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
# 29 "data/maps/PacifidlogTown/scripts.pory"
	end
# 30 "data/maps/PacifidlogTown/scripts.pory"

# 31 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_FastRunningCurrent:
# 32 "data/maps/PacifidlogTown/scripts.pory"
	.string "The sea between Pacifidlog and\n"
# 33 "data/maps/PacifidlogTown/scripts.pory"
	.string "Slateport has a fast-running tide.\p"
# 34 "data/maps/PacifidlogTown/scripts.pory"
	.string "If you decide to Surf, you could end\n"
# 35 "data/maps/PacifidlogTown/scripts.pory"
	.string "up swept away somewhere else.$"
# 36 "data/maps/PacifidlogTown/scripts.pory"

# 37 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_NeatHousesOnWater:
# 38 "data/maps/PacifidlogTown/scripts.pory"
	.string "See, isn't it neat?\n"
# 39 "data/maps/PacifidlogTown/scripts.pory"
	.string "These houses are on water!\p"
# 40 "data/maps/PacifidlogTown/scripts.pory"
	.string "I was born here!$"
# 41 "data/maps/PacifidlogTown/scripts.pory"

# 42 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SkyPillarTooScary:
# 43 "data/maps/PacifidlogTown/scripts.pory"
	.string "The Sky Pillar?\p"
# 44 "data/maps/PacifidlogTown/scripts.pory"
	.string "…Oh, you must mean that tall, tall\n"
# 45 "data/maps/PacifidlogTown/scripts.pory"
	.string "tower a little further out.\p"
# 46 "data/maps/PacifidlogTown/scripts.pory"
	.string "If you asked me, I wouldn't climb it.\n"
# 47 "data/maps/PacifidlogTown/scripts.pory"
	.string "It's too scary to get up that high.\p"
# 48 "data/maps/PacifidlogTown/scripts.pory"
	.string "Life at sea level in Pacifidlog,\n"
# 49 "data/maps/PacifidlogTown/scripts.pory"
	.string "that suits me fine.$"
# 50 "data/maps/PacifidlogTown/scripts.pory"

# 51 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_TownSign:
# 52 "data/maps/PacifidlogTown/scripts.pory"
	.string "Pacifidlog Town\p"
# 53 "data/maps/PacifidlogTown/scripts.pory"
	.string "“Where the morning sun smiles upon\n"
# 54 "data/maps/PacifidlogTown/scripts.pory"
	.string "the waters.”$"

PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees::
# 58 "data/maps/PacifidlogTown/scripts.pory"
	lock
# 59 "data/maps/PacifidlogTown/scripts.pory"
	faceplayer
# 60 "data/maps/PacifidlogTown/scripts.pory"
	goto_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_2
# 64 "data/maps/PacifidlogTown/scripts.pory"
	random 4
PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_1:
# 66 "data/maps/PacifidlogTown/scripts.pory"
	switch VAR_RESULT
# 67 "data/maps/PacifidlogTown/scripts.pory"
	case 0, PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_7
# 68 "data/maps/PacifidlogTown/scripts.pory"
	case 1, PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_8
# 69 "data/maps/PacifidlogTown/scripts.pory"
	case 2, PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_9
# 70 "data/maps/PacifidlogTown/scripts.pory"
	case 3, PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_10
PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_5:
# 72 "data/maps/PacifidlogTown/scripts.pory"
	release
	end

PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_2:
# 61 "data/maps/PacifidlogTown/scripts.pory"
	random 2
	goto PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_1

PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_7:
# 67 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_RumorsOfAnIslandForRefugees_1
	goto PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_5

PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_8:
# 68 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_RumorsOfAnIslandForRefugees_2
	goto PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_5

PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_9:
# 69 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_RumorsOfAnIslandForRefugees_3
	goto PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_5

PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_10:
# 70 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_RumorsOfAnIslandForRefugees_4
	goto PacifidlogTown_EventScript_RumorsOfAnIslandForRefugees_5


PacifidlogTown_Text_RumorsOfAnIslandForRefugees_1::
# 76 "data/maps/PacifidlogTown/scripts.pory"
	.string "They say there's an island where the\n"
	.string "shadows never fade, hidden somewhere\l"
	.string "amidst the treacherous currents.\p"
	.string "It’s a place where many lost souls\n"
	.string "go to keep from being found.\p"
	.string "If you go looking for it,\n"
	.string "make sure you are careful.$"

PacifidlogTown_Text_RumorsOfAnIslandForRefugees_2::
# 83 "data/maps/PacifidlogTown/scripts.pory"
	.string "The rapids are treacherous, but they\n"
	.string "lead to more than Slateport.\p"
	.string "If you follow the pull where the sky\n"
	.string "turns a darker shade of grey, you might\l"
	.string "just find the fabled Obsidian Shores.$"

PacifidlogTown_Text_RumorsOfAnIslandForRefugees_3::
# 89 "data/maps/PacifidlogTown/scripts.pory"
	.string "I heard that the bosses of Team Aqua\n"
	.string "and Team Magma have left the region.\p"
	.string "I guess they were tired of fighting\n"
	.string "each other.\p"
	.string "I wonder if their grunts will follow suit\n"
	.string "or seek refuge elsewhere.$"

PacifidlogTown_Text_RumorsOfAnIslandForRefugees_4::
# 95 "data/maps/PacifidlogTown/scripts.pory"
	.string "I've seen former Team Aqua and Magma\n"
	.string "grunts drifting toward the rapids.\p"
	.string "I wonder if they will try to make their\n"
	.string "way to Slateport or find a hidden island\l"
	.string "somewhere in the currents.$"
