# 1 "data/maps/ShadespurPokemonCenter/scripts.pory"

# 2 "data/maps/ShadespurPokemonCenter/scripts.pory"
ShadespurPokemonCenter_MapScripts::
# 3 "data/maps/ShadespurPokemonCenter/scripts.pory"
    map_script MAP_SCRIPT_ON_LOAD, ShadespurPokemonCenter_OnLoad
# 4 "data/maps/ShadespurPokemonCenter/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ShadespurPokemonCenter_OnTransition
# 5 "data/maps/ShadespurPokemonCenter/scripts.pory"
	.byte 0
# 6 "data/maps/ShadespurPokemonCenter/scripts.pory"

# 7 "data/maps/ShadespurPokemonCenter/scripts.pory"
ShadespurPokemonCenter_OnLoad:
# 8 "data/maps/ShadespurPokemonCenter/scripts.pory"
    call_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, ShadespurPokemonCenter_ShowMasterBall
# 9 "data/maps/ShadespurPokemonCenter/scripts.pory"
    end
# 10 "data/maps/ShadespurPokemonCenter/scripts.pory"

# 11 "data/maps/ShadespurPokemonCenter/scripts.pory"
ShadespurPokemonCenter_ShowMasterBall::
# 12 "data/maps/ShadespurPokemonCenter/scripts.pory"
    clearflag FLAG_HIDE_SHADESPUR_POKEMON_CENTER_MASTER_BALL
# 13 "data/maps/ShadespurPokemonCenter/scripts.pory"
    return
# 14 "data/maps/ShadespurPokemonCenter/scripts.pory"

# 15 "data/maps/ShadespurPokemonCenter/scripts.pory"
ShadespurPokemonCenter_OnTransition:
# 16 "data/maps/ShadespurPokemonCenter/scripts.pory"
	setrespawn HEAL_LOCATION_SHADESPUR_ISLE
# 17 "data/maps/ShadespurPokemonCenter/scripts.pory"
	end
# 18 "data/maps/ShadespurPokemonCenter/scripts.pory"

# 19 "data/maps/ShadespurPokemonCenter/scripts.pory"
ShadespurPokemonCenter_EventScript_Nurse::
# 20 "data/maps/ShadespurPokemonCenter/scripts.pory"
	setvar VAR_0x800B, LOCALID_SHADESPUR_NURSE
# 21 "data/maps/ShadespurPokemonCenter/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 22 "data/maps/ShadespurPokemonCenter/scripts.pory"
	waitmessage
# 23 "data/maps/ShadespurPokemonCenter/scripts.pory"
	waitbuttonpress
# 24 "data/maps/ShadespurPokemonCenter/scripts.pory"
	release
# 25 "data/maps/ShadespurPokemonCenter/scripts.pory"
	end

ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats::
# 28 "data/maps/ShadespurPokemonCenter/scripts.pory"
	lock
# 29 "data/maps/ShadespurPokemonCenter/scripts.pory"
	faceplayer
# 30 "data/maps/ShadespurPokemonCenter/scripts.pory"
	random 3
# 31 "data/maps/ShadespurPokemonCenter/scripts.pory"
	switch VAR_RESULT
# 32 "data/maps/ShadespurPokemonCenter/scripts.pory"
	case 0, ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_3
# 36 "data/maps/ShadespurPokemonCenter/scripts.pory"
	case 1, ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_4
# 40 "data/maps/ShadespurPokemonCenter/scripts.pory"
	case 2, ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_5
ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_1:
# 46 "data/maps/ShadespurPokemonCenter/scripts.pory"
	release
	end

ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_3:
# 32 "data/maps/ShadespurPokemonCenter/scripts.pory"
	msgbox ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_Text_0
	goto ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_1

ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_4:
# 36 "data/maps/ShadespurPokemonCenter/scripts.pory"
	msgbox ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_Text_1
	goto ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_1

ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_5:
# 40 "data/maps/ShadespurPokemonCenter/scripts.pory"
	msgbox ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_Text_2
	goto ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_1


ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats::
# 51 "data/maps/ShadespurPokemonCenter/scripts.pory"
	lock
# 52 "data/maps/ShadespurPokemonCenter/scripts.pory"
	faceplayer
# 53 "data/maps/ShadespurPokemonCenter/scripts.pory"
	random 3
# 54 "data/maps/ShadespurPokemonCenter/scripts.pory"
	switch VAR_RESULT
# 55 "data/maps/ShadespurPokemonCenter/scripts.pory"
	case 0, ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_3
# 60 "data/maps/ShadespurPokemonCenter/scripts.pory"
	case 1, ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_4
# 66 "data/maps/ShadespurPokemonCenter/scripts.pory"
	case 2, ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_5
ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_1:
# 74 "data/maps/ShadespurPokemonCenter/scripts.pory"
	release
	end

ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_3:
# 55 "data/maps/ShadespurPokemonCenter/scripts.pory"
	msgbox ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_Text_0
	goto ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_1

ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_4:
# 60 "data/maps/ShadespurPokemonCenter/scripts.pory"
	msgbox ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_Text_1
	goto ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_1

ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_5:
# 66 "data/maps/ShadespurPokemonCenter/scripts.pory"
	msgbox ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_Text_2
	goto ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_1


ShadespurPokemonCenter_EventScript_OldManWarning::
# 79 "data/maps/ShadespurPokemonCenter/scripts.pory"
	lock
# 80 "data/maps/ShadespurPokemonCenter/scripts.pory"
	faceplayer
# 81 "data/maps/ShadespurPokemonCenter/scripts.pory"
	msgbox ShadespurPokemonCenter_EventScript_OldManWarning_Text_0
# 84 "data/maps/ShadespurPokemonCenter/scripts.pory"
	release
	end


ShadespurPokemonCenter_EventScript_FindMasterBall::
# 89 "data/maps/ShadespurPokemonCenter/scripts.pory"
	lock
# 90 "data/maps/ShadespurPokemonCenter/scripts.pory"
	finditem ITEM_MASTER_BALL
# 91 "data/maps/ShadespurPokemonCenter/scripts.pory"
	setflag FLAG_ITEM_SHADESPUR_POKEMON_CENTER_MASTER_BALL
# 92 "data/maps/ShadespurPokemonCenter/scripts.pory"
	release
	end


ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_Text_0:
# 32 "data/maps/ShadespurPokemonCenter/scripts.pory"
	.string "Well look what the tide dragged in.\n"
	.string "A fresh face.\p"
	.string "Don't worry, kid, we won't steal your\n"
	.string "Pokémon.\p"
	.string "We're done with all that. We just…\n"
	.string "ran out of oceans to conquer.$"

ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_Text_1:
# 36 "data/maps/ShadespurPokemonCenter/scripts.pory"
	.string "The hardest part of leaving?\n"
	.string "The quiet.\p"
	.string "No more yelling, no more rushed orders,\n"
	.string "no being treated like a spare anchor.\p"
	.string "This island is cold, but at least the\n"
	.string "cold is honest.$"

ShadespurPokemonCenter_EventScript_Aqua_Grunt_Chats_Text_2:
# 40 "data/maps/ShadespurPokemonCenter/scripts.pory"
	.string "I heard the boss is still out there,\n"
	.string "pushing for the Eternal Tide.\p"
	.string "Good luck to him.\p"
	.string "I just needed a place where I didn't\n"
	.string "have to choose between a life jacket\l"
	.string "and a jail cell.\p"
	.string "This place is far enough from everyone.$"

ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_Text_0:
# 55 "data/maps/ShadespurPokemonCenter/scripts.pory"
	.string "You startled me.\n"
	.string "Yeah, I’m Magma. He's Aqua.\p"
	.string "We found this spot and called a truce.\n"
	.string "Out here, we're not teams, we're just…\l"
	.string "outcasts.\p"
	.string "Nothing worse than being a grunt\n"
	.string "without a team to back you up.$"

ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_Text_1:
# 60 "data/maps/ShadespurPokemonCenter/scripts.pory"
	.string "The boss always talked about the\n"
	.string "perfect land, the perfect world.\p"
	.string "But the only perfect thing I ever\n"
	.string "found was a cot that didn't smell\l"
	.string "like volcanic sulfur.\p"
	.string "We’re all refugees from our own bad\n"
	.string "decisions, kid.$"

ShadespurPokemonCenter_EventScript_Magma_Grunt_Chats_Text_2:
# 66 "data/maps/ShadespurPokemonCenter/scripts.pory"
	.string "You see that computer? It's rigged for\n"
	.string "basic healing and storage.\p"
	.string "No network. No calls back to\n"
	.string "headquarters. We made sure of that.\p"
	.string "This isn't just a hideout;\n"
	.string "it's a dead zone.\p"
	.string "This is where to go when the fighting\n"
	.string "gets too loud.$"

ShadespurPokemonCenter_EventScript_OldManWarning_Text_0:
# 81 "data/maps/ShadespurPokemonCenter/scripts.pory"
	.string "They call this place a refuge.\p"
	.string "But the shore is where you bury your\n"
	.string "debts, not pay them.\p"
	.string "Be careful who you owe, young one.$"
