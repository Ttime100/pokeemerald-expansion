# 1 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 2 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_MapScripts::
# 3 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_GlaciasRoom_OnFrame
# 4 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_GlaciasRoom_OnLoad
# 5 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_GlaciasRoom_OnWarp
# 6 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.byte 0
# 7 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 8 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_OnWarp:
# 9 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth
# 10 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.2byte 0
# 11 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 12 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_PlayerTurnNorth::
# 13 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 14 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 15 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 16 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_OnFrame:
# 17 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	map_script_2 VAR_ELITE_4_STATE, 2, EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor
# 18 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.2byte 0
# 19 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 20 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_WalkInCloseDoor::
# 21 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	lockall
# 22 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
# 23 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	setvar VAR_ELITE_4_STATE, 3
# 24 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	releaseall
# 25 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 26 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 27 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_OnLoad:
# 28 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom
# 29 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call_if_eq VAR_ELITE_4_STATE, 3, EverGrandeCity_GlaciasRoom_EventScript_CloseDoor
# 30 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 31 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 32 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_ResetAdvanceToNextRoom::
# 33 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
# 34 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	return
# 35 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 36 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_CloseDoor::
# 37 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_EventScript_CloseDoor
# 38 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	return
# 39 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 40 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_Glacia::
# 41 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	lock
# 42 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	faceplayer
# 43 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech
# 44 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
# 45 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_GlaciasRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 46 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_GLACIA, EverGrandeCity_GlaciasRoom_Text_Defeat
# 47 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto EverGrandeCity_GlaciasRoom_EventScript_Defeated
# 48 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 49 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 50 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_PostBattleSpeech::
# 51 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 52 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	release
# 53 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 54 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 55 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_EventScript_Defeated::
# 56 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_GLACIA
# 57 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 58 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 59 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	release
# 60 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	end
# 61 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 62 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_Text_IntroSpeech:
# 63 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "Welcome, my name is Glacia\n"
# 64 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "of the Elite Four.\p"
# 65 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "I've traveled from afar to Hoenn\n"
# 66 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "so that I may hone my ice skills.\p"
# 67 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "But all I have seen are challenges by\n"
# 68 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "weak Trainers and their Pokémon.\p"
# 69 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "What about you?\p"
# 70 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "It would please me to no end if I could\n"
# 71 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "go all out against you!$"
# 72 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 73 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_Text_Defeat:
# 74 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "You and your Pokémon…\n"
# 75 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "How hot your spirits burn!\p"
# 76 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "The all-consuming heat overwhelms.\p"
# 77 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "It's no surprise that my icy skills\n"
# 78 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "failed to harm you.$"
# 79 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"

# 80 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
EverGrandeCity_GlaciasRoom_Text_PostBattleSpeech:
# 81 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "Advance to the next room.\p"
# 82 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "And there, confirm the truly fearsome\n"
# 83 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "side of the Pokémon League.$"

EverGrandeCity_RobsRoom_EventScript_Rob::
# 87 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	lock
# 88 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	faceplayer
# 89 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_ROB, EverGrandeCity_RobsRoom_EventScript_PostBattleSpeech
# 90 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
# 91 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_RobsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
# 92 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	trainerbattle_no_intro TRAINER_ELITE_FOUR_ROB, EverGrandeCity_RobsRoom_Text_Defeat
# 93 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	goto EverGrandeCity_RobsRoom_EventScript_Defeated
	end


EverGrandeCity_RobsRoom_EventScript_PostBattleSpeech::
# 98 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_RobsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 99 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	release
	end


EverGrandeCity_RobsRoom_EventScript_Defeated::
# 104 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_ROB
# 105 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
# 106 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	msgbox EverGrandeCity_RobsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
# 107 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	release
	end


EverGrandeCity_RobsRoom_Text_IntroSpeech::
# 111 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "So, you're the one who managed to\n"
	.string "stumble through the first two rooms.\p"
	.string "I suppose I should congratulate you\n"
	.string "for surviving the volatility of Parth\l"
	.string "and the vanity of Austin.\p"
	.string "They believe victory is a matter of\n"
	.string "force. I know better.\l"
	.string "I'm not here to trade blows with you.\p"
	.string "I'm here to watch you struggle against\n"
	.string "a web you didn't even see me spin.\p"
	.string "By the time you realize you're losing,\n"
	.string "escape will already be out of reach.\p"
	.string "Let's see how much you enjoy a battle\n"
	.string "you can't actually fight.$"

EverGrandeCity_RobsRoom_Text_Defeat::
# 121 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "Wait... the web...\n"
	.string "it's supposed to hold!$"

EverGrandeCity_RobsRoom_Text_PostBattleSpeech::
# 125 "data/maps/EverGrandeCity_GlaciasRoom/scripts.pory"
	.string "Fine. You tore through it.\n"
	.string "I hope you're proud of yourself.\p"
	.string "Don't think for a second that the path\n"
	.string "ahead gets any easier though.\p"
	.string "The man in the next room isn't\n"
	.string "interested in your struggle.\p"
	.string "He's only interested in calculating how\n"
	.string "to defeat you.\p"
	.string "He's already reached his conclusion.\n"
	.string "He's just waiting for you to catch up!$"
