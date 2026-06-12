# 1 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 2 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_MapScripts::
# 3 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition
# 4 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
# 5 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.byte 0
# 6 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 7 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_OnTransition:
# 8 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE
# 9 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
# 10 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call_if_unset FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor
# 11 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 12 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 13 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor::
# 14 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setobjectxyperm LOCALID_LEAGUE_GUARD_1, 9, 2
# 15 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setobjectxyperm LOCALID_LEAGUE_GUARD_2, 10, 2
# 16 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	return
# 17 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 18 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_Nurse::
# 19 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setvar VAR_0x800B, LOCALID_LEAGUE_NURSE
# 20 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call Common_EventScript_PkmnCenterNurse
# 21 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 22 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitbuttonpress
# 23 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
# 24 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 25 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 26 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_Clerk::
# 27 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	lock
# 28 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	faceplayer
# 29 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message gText_HowMayIServeYou
# 30 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 31 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	pokemart EverGrandeCity_PokemonLeague_1F_Pokemart
# 32 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 33 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
# 34 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 35 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 36 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.align 2
# 37 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Pokemart:
# 38 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 39 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 40 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_MAX_POTION
# 41 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_FULL_RESTORE
# 42 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 43 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_REVIVE
# 44 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 45 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	pokemartlistend
# 46 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 47 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
@ The door guards only check for FLAG_BADGE06_GET because Winonas badge is the only one that can be skipped
# 48 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
@ Its assumed the player has the remaining badges
# 49 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard::
# 50 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	lockall
# 51 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_set FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GoForth
# 52 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 53 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call_if_ge VAR_TEMP_0, 11, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight
# 54 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call_if_le VAR_TEMP_0, 8, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft
# 55 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges
# 56 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 57 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 120
# 58 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_unset FLAG_BADGE06_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
# 59 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 60 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_LEAGUE_GUARD_1, EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay
# 61 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_LEAGUE_GUARD_2, EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay
# 62 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 63 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 10
# 64 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playfanfare MUS_OBTAIN_BADGE
# 65 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	message EverGrandeCity_PokemonLeague_1F_Text_GoForth
# 66 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmessage
# 67 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitfanfare
# 68 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 69 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	copyobjectxytoperm LOCALID_LEAGUE_GUARD_1
# 70 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	copyobjectxytoperm LOCALID_LEAGUE_GUARD_2
# 71 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setflag FLAG_ENTERED_ELITE_FOUR
# 72 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 73 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 74 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 75 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight::
# 76 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight
# 77 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 78 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	return
# 79 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 80 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft::
# 81 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement LOCALID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft
# 82 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 83 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	return
# 84 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 85 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges::
# 86 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playse SE_FAILURE
# 87 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges, MSGBOX_DEFAULT
# 88 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 89 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 90 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 91 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_EventScript_GoForth::
# 92 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 93 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 94 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_Text_GoForth, MSGBOX_DEFAULT
# 95 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	closemessage
# 96 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 97 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 0
# 98 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	releaseall
# 99 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	end
# 100 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 101 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight:
# 102 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_down
# 103 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_left
# 104 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_up
# 105 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 106 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 107 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft:
# 108 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_down
# 109 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_right
# 110 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_up
# 111 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 112 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 113 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay:
# 114 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_left
# 115 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_down
# 116 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 117 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 118 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay:
# 119 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_right
# 120 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	walk_in_place_faster_down
# 121 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	step_end
# 122 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 123 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges:
# 124 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Beyond this point, only those Trainers\n"
# 125 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "who have collected all the Gym Badges\l"
# 126 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "are permitted to enter.\p"
# 127 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Trainer, let us confirm that you have\n"
# 128 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "all the Gym Badges.$"
# 129 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 130 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges:
# 131 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "You haven't obtained all the Badges.\p"
# 132 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "If you're bound for the Pokémon\n"
# 133 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "League, you must return with them.$"
# 134 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"

# 135 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
EverGrandeCity_PokemonLeague_1F_Text_GoForth:
# 136 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Trainer! Believe in yourself and your\n"
# 137 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Pokémon, and go forth!$"

EverGrandeCity_PokemonLeague_EventScript_Gatekeeper::
# 141 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	lock
# 142 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	faceplayer
# 144 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_set FLAG_MET_GATEKEEPERS, EverGrandeCity_PokemonLeague_EventScript_Gatekeeper_2
EverGrandeCity_PokemonLeague_EventScript_Gatekeeper_1:
# 147 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges
# 148 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playse SE_PIN
# 149 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement 3, Common_Movement_ExclamationMark
# 150 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement 4, Common_Movement_ExclamationMark
# 151 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 3
# 152 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 4
# 153 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 60
# 154 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playse SE_DOOR
# 155 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
# 156 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	clearflag FLAG_HIDE_TYLER_LEAGUE
# 157 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	addobject 5
# 158 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 30
# 159 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_Text_TylersChallenge
# 160 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	clearflag FLAG_HIDE_EXILE_SIDNEY
# 161 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	clearflag FLAG_HIDE_EXILE_PHOEBE
# 162 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	clearflag FLAG_HIDE_EXILE_GLACIA
# 163 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	clearflag FLAG_HIDE_EXILE_DRAKE
# 164 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	clearflag FLAG_HIDE_HINT_GIVER
# 165 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setflag FLAG_MET_GATEKEEPERS
# 166 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	applymovement 5, Common_Movement_FaceUp
# 167 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	waitmovement 5
# 168 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	delay 20
# 169 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	removeobject 5
# 170 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	playse SE_DOOR
# 171 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setflag FLAG_HIDE_TYLER_LEAGUE
# 172 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	fadedefaultbgm
# 173 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
	end

EverGrandeCity_PokemonLeague_EventScript_Gatekeeper_2:
# 145 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto EverGrandeCity_PokemonLeague_CheckProgress
	goto EverGrandeCity_PokemonLeague_EventScript_Gatekeeper_1


EverGrandeCity_PokemonLeague_CheckProgress::
# 178 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_PokemonLeague_CheckProgress_5
EverGrandeCity_PokemonLeague_CheckProgress_3:
# 183 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_CheckProgress_Text_0
EverGrandeCity_PokemonLeague_CheckProgress_1:
# 186 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
	end

EverGrandeCity_PokemonLeague_CheckProgress_2:
# 180 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	call EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard
	goto EverGrandeCity_PokemonLeague_CheckProgress_1

EverGrandeCity_PokemonLeague_CheckProgress_4:
# 179 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_PokemonLeague_CheckProgress_8
	goto EverGrandeCity_PokemonLeague_CheckProgress_3

EverGrandeCity_PokemonLeague_CheckProgress_5:
# 178 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PokemonLeague_CheckProgress_4
	goto EverGrandeCity_PokemonLeague_CheckProgress_3

EverGrandeCity_PokemonLeague_CheckProgress_8:
# 179 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_PokemonLeague_CheckProgress_2
	goto EverGrandeCity_PokemonLeague_CheckProgress_3


EverGrandeCity_PokemonLeague_HintGiver::
# 191 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	lock
# 192 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	faceplayer
# 193 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_set FLAG_TEMP_1, EverGrandeCity_PokemonLeague_HintGiver_2
# 196 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_HintGiver_Text_1
# 199 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setflag FLAG_TEMP_1
EverGrandeCity_PokemonLeague_HintGiver_1:
# 201 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setvar VAR_TEMP_5, 0
# 202 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_PokemonLeague_HintGiver_6
EverGrandeCity_PokemonLeague_HintGiver_5:
# 203 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PokemonLeague_HintGiver_9
EverGrandeCity_PokemonLeague_HintGiver_8:
# 204 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_PokemonLeague_HintGiver_12
EverGrandeCity_PokemonLeague_HintGiver_11:
# 205 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_PokemonLeague_HintGiver_15
EverGrandeCity_PokemonLeague_HintGiver_14:
# 206 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	compare VAR_TEMP_5, 0
	goto_if_eq EverGrandeCity_PokemonLeague_HintGiver_18
# 211 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	random VAR_TEMP_5
# 212 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	setvar VAR_TEMP_6, 0
# 213 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_PokemonLeague_HintGiver_21
EverGrandeCity_PokemonLeague_HintGiver_20:
# 221 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_PokemonLeague_HintGiver_24
EverGrandeCity_PokemonLeague_HintGiver_23:
# 229 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_PokemonLeague_HintGiver_30
EverGrandeCity_PokemonLeague_HintGiver_29:
# 237 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	goto_if_unset FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_PokemonLeague_HintGiver_36
EverGrandeCity_PokemonLeague_HintGiver_35:
# 245 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
	end

EverGrandeCity_PokemonLeague_HintGiver_2:
# 194 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_HintGiver_Text_0
	goto EverGrandeCity_PokemonLeague_HintGiver_1

EverGrandeCity_PokemonLeague_HintGiver_6:
# 202 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	addvar VAR_TEMP_5, 1
	goto EverGrandeCity_PokemonLeague_HintGiver_5

EverGrandeCity_PokemonLeague_HintGiver_9:
# 203 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	addvar VAR_TEMP_5, 1
	goto EverGrandeCity_PokemonLeague_HintGiver_8

EverGrandeCity_PokemonLeague_HintGiver_12:
# 204 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	addvar VAR_TEMP_5, 1
	goto EverGrandeCity_PokemonLeague_HintGiver_11

EverGrandeCity_PokemonLeague_HintGiver_15:
# 205 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	addvar VAR_TEMP_5, 1
	goto EverGrandeCity_PokemonLeague_HintGiver_14

EverGrandeCity_PokemonLeague_HintGiver_18:
# 207 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_HintGiver_Text_2
# 208 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
	end

EverGrandeCity_PokemonLeague_HintGiver_21:
# 214 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	compare VAR_TEMP_6, VAR_RESULT
	goto_if_eq EverGrandeCity_PokemonLeague_HintGiver_27
# 219 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	addvar VAR_TEMP_6, 1
	goto EverGrandeCity_PokemonLeague_HintGiver_20

EverGrandeCity_PokemonLeague_HintGiver_24:
# 222 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	compare VAR_TEMP_6, VAR_RESULT
	goto_if_eq EverGrandeCity_PokemonLeague_HintGiver_33
# 227 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	addvar VAR_TEMP_6, 1
	goto EverGrandeCity_PokemonLeague_HintGiver_23

EverGrandeCity_PokemonLeague_HintGiver_27:
# 215 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_Text_SidneyHint
# 216 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
	end

EverGrandeCity_PokemonLeague_HintGiver_30:
# 230 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	compare VAR_TEMP_6, VAR_RESULT
	goto_if_eq EverGrandeCity_PokemonLeague_HintGiver_39
# 235 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	addvar VAR_TEMP_6, 1
	goto EverGrandeCity_PokemonLeague_HintGiver_29

EverGrandeCity_PokemonLeague_HintGiver_33:
# 223 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_Text_PhoebeHint
# 224 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
	end

EverGrandeCity_PokemonLeague_HintGiver_36:
# 238 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	compare VAR_TEMP_6, VAR_RESULT
	goto_if_eq EverGrandeCity_PokemonLeague_HintGiver_42
# 243 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	addvar VAR_TEMP_6, 1
	goto EverGrandeCity_PokemonLeague_HintGiver_35

EverGrandeCity_PokemonLeague_HintGiver_39:
# 231 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_Text_GlaciaHint
# 232 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
	end

EverGrandeCity_PokemonLeague_HintGiver_42:
# 239 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	msgbox EverGrandeCity_PokemonLeague_Text_DrakeHint
# 240 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	release
	end


EverGrandeCity_PokemonLeague_CheckProgress_Text_0:
# 183 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "I'm sorry {PLAYER}.\p"
	.string "It sounds like you need to defeat the\n"
	.string "former members before returning.$"

EverGrandeCity_PokemonLeague_HintGiver_Text_0:
# 194 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Back for another lead?$"

EverGrandeCity_PokemonLeague_HintGiver_Text_1:
# 196 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "The League has been taken over.\n"
	.string "It's a mess.\p"
	.string "The original Elite Four have scattered\n"
	.string "across Hoenn, but thankfully there are\l"
	.string "murmurings on where they disappeared.$"

EverGrandeCity_PokemonLeague_HintGiver_Text_2:
# 207 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "You've found them all!\n"
	.string "Go reclaim the League!$"

EverGrandeCity_PokemonLeague_Text_TylersChallenge::
# 249 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "I'll handle this.\p"
	.string "So, this is the challenger\n"
	.string "I've been hearing about?\p"
	.string "You look rather ordinary.\p"
	.string "You think a few gym badges make you\n"
	.string "worthy of standing in our presence?\p"
	.string "We replaced the former Elite Four\n"
	.string "because they didn't have what it takes.\p"
	.string "If you want us to even consider opening\n"
	.string "these doors, you'll have to prove you're\l"
	.string "at least better than them.\p"
	.string "They have retreated to the\n"
	.string "far corners of Hoenn.\p"
	.string "Defeat them. All of them.\p"
	.string "Only then will I consider you\n"
	.string "as a legitimate challenger.$"

EverGrandeCity_PokemonLeague_Text_SidneyHint::
# 269 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Sidney was last spotted near the coast,\n"
	.string "somewhere where shadows never fade.\p"
	.string "If you look for the place where light is\n"
	.string "swallowed by the sea, you'll find him.$"

EverGrandeCity_PokemonLeague_Text_PhoebeHint::
# 275 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Phoebe hasn't been seen for a while.\n"
	.string "They say she's returned to the tower\l"
	.string "where spirits gather, waiting at the\l"
	.string "highest point to pay her respects.$"

EverGrandeCity_PokemonLeague_Text_GlaciaHint::
# 281 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "There's a strange chill lingering in the\n"
	.string "northern waters. Look for the place\l"
	.string "where the land turns to permafrost.\l"
	.string "That is where Glacia is keeping watch.$"

EverGrandeCity_PokemonLeague_Text_DrakeHint::
# 287 "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.pory"
	.string "Drake has retreated to his training\n"
	.string "grounds deep within the caves.\p"
	.string "He dwells where Dragon Pokémon raise\n"
	.string "their young amongst ancient meteors.$"
