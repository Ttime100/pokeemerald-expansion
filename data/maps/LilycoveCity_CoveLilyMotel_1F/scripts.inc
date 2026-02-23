# 1 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 2 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_MapScripts::
# 3 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
    map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition
# 4 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_CoveLilyMotel_1F_MapScripts_OnFrame
# 5 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.byte 0
# 6 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 7 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_MapScripts_OnFrame:
# 8 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
    map_script_2 VAR_DARKRAI_STATE, 1, LilycoveCity_CoveLilyMotel_1F_EventScript_Warning
# 9 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
    map_script_2 VAR_DARKRAI_STATE, 3, LilycoveCity_CoveLilyMotel_1F_EventScript_WakeUp
# 10 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
    .2byte 0
# 11 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 12 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
# 13 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	lockall
# 14 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
# 15 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
# 16 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
# 17 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
# 18 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 19 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
# 20 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	closemessage
# 21 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
# 22 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 23 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	releaseall
# 24 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	end
# 25 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 26 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
# 27 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
# 28 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
# 29 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 30 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
# 31 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	closemessage
# 32 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
# 33 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 34 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	releaseall
# 35 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	end
# 36 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 37 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
# 38 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
# 39 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
# 40 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 41 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
# 42 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	closemessage
# 43 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
# 44 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 45 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	releaseall
# 46 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	end
# 47 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 48 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
# 49 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	lockall
# 50 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	playse SE_PIN
# 51 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
# 52 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 53 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
# 54 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 55 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 56 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 57 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
# 58 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	closemessage
# 59 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
# 60 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
# 61 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 62 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
# 63 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 64 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	release
# 65 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	end
# 66 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 67 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
# 68 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	face_right
# 69 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	lock_facing_direction
# 70 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	walk_left
# 71 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	unlock_facing_direction
# 72 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	step_end
# 73 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 74 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
# 75 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	walk_up
# 76 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	step_end
# 77 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 78 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
# 79 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	face_down
# 80 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	walk_down
# 81 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	face_up
# 82 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	step_end
# 83 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 84 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
# 85 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Hm, so they doubled the guests by\n"
# 86 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "using Pokémon as attractions?\p"
# 87 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Hm, well, maybe I should make a cute\n"
# 88 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Pokémon our inn's mascot.\p"
# 89 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "I wonder if that will attract more\n"
# 90 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "guests to stay with us?$"
# 91 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 92 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
# 93 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Oh, sorry, sorry!\n"
# 94 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "I was too involved in watching TV!\p"
# 95 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Since that Team Aqua came to town,\n"
# 96 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "the tourists have been staying away.$"
# 97 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 98 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
# 99 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Hey, down in front!\n"
# 100 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "I can't see the TV!$"
# 101 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 102 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
# 103 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Amazing! You're telling me a Pokémon\n"
# 104 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "found someone's lost item?\p"
# 105 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "That's something. If we had some smart\n"
# 106 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Pokémon like that…\p"
# 107 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "We could recover anything that our\n"
# 108 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "guests mislaid…$"
# 109 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 110 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
# 111 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Oh, sorry, sorry!\n"
# 112 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "I was too involved in watching TV!\p"
# 113 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "I heard that someone busted\n"
# 114 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "the Team Aqua Hideout.\p"
# 115 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Thanks to that, we just booked\n"
# 116 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "a reservation from a big group.\p"
# 117 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "It was a company called… Uh…\n"
# 118 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Game something…$"
# 119 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 120 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
# 121 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Amazing! A house-sitting Pokémon\n"
# 122 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "caught a burglar?\p"
# 123 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "That's something. If we had a tough\n"
# 124 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Pokémon as a security guard…\p"
# 125 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "We would be able to provide our guests\n"
# 126 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "with greater safety.$"
# 127 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"

# 128 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
# 129 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Oh, sorry, sorry!\n"
# 130 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "I was too involved in watching TV.\p"
# 131 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Oh, yes. A big group of guests arrived\n"
# 132 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "a little while ago.\p"
# 133 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "They booked in as Game Freak,\n"
# 134 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "so I guess they must make games.\p"
# 135 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Uh-oh, I'd better get working on\n"
# 136 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "their dinner!$"

LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition::
# 141 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	compare VAR_DARKRAI_STATE, 0
	goto_if_eq LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_2
LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_1:
# 148 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	compare VAR_DARKRAI_STATE, 2
	goto_if_eq LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_5
# 153 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	setdynamicwarp MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_2F, 0, 2, 2
LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_4:
# 156 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	compare VAR_DARKRAI_STATE, 1
	goto_if_eq LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_11
# 156 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	compare VAR_DARKRAI_STATE, 2
	goto_if_eq LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_11
# 160 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	setflag FLAG_HIDE_MOTEL_GUEST
# 161 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	clearflag FLAG_HIDE_MOTEL_OWNER
LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_10:
# 164 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	compare VAR_DARKRAI_STATE, 2
	goto_if_eq LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_17
LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_16:
	end

LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_2:
# 142 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	checkitem ITEM_MEMBER_CARD
# 143 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_8
	goto LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_1

LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_5:
# 149 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	setdynamicwarp MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_DARKRAI_ROOM, 0
# 150 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	playbgm MUS_RG_LAVENDER, TRUE
	goto LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_4

LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_8:
# 144 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	setvar VAR_DARKRAI_STATE, 1
	goto LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_1

LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_11:
# 157 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	setflag FLAG_HIDE_MOTEL_OWNER
# 158 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	clearflag FLAG_HIDE_MOTEL_GUEST
	goto LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_10

LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_17:
# 165 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	setflag FLAG_HIDE_MOTEL_GUEST
	goto LilycoveCity_CoveLilyMotel_1F_MapScripts_OnTransition_16


LilycoveCity_CoveLilyMotel_1F_EventScript_Warning::
# 171 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	lockall
# 172 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	fadeoutbgm 1
# 173 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	delay 30
# 174 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	setvar VAR_DARKRAI_STATE, 2
# 175 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_GUEST, Common_Movement_FacePlayer
# 176 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 177 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	delay 60
# 178 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_EventScript_Warning_Text_0
# 180 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	closemessage
# 181 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_GUEST, mGuestFirstStep
# 182 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 183 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	delay 30
# 184 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	playse SE_PIN
# 185 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_GUEST, Common_Movement_ExclamationMark
# 186 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 187 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_EventScript_Warning_Text_1
# 189 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	closemessage
# 190 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_GUEST, mGuestApproachesSlowly
# 191 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 192 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_EventScript_Warning_Text_2
# 196 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	closemessage
# 197 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_MOTEL_GUEST, mGuestDisappears
# 198 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 199 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	setdynamicwarp MAP_LILYCOVE_CITY_COVE_LILY_MOTEL_DARKRAI_ROOM, 0
# 200 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	fadescreen FADE_TO_WHITE
# 201 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	removeobject LOCALID_MOTEL_GUEST
# 202 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	playbgm MUS_RG_LAVENDER, TRUE
# 203 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	fadescreen FADE_FROM_WHITE
# 204 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	setflag FLAG_HIDE_MOTEL_GUEST
# 205 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	releaseall
	end


LilycoveCity_CoveLilyMotel_1F_EventScript_WakeUp::
# 210 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	lockall
# 211 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	delay 30
# 212 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_PLAYER, mDazed
# 213 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_EventScript_WakeUp_Text_0
# 215 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 216 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	closemessage
# 217 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	playse SE_PIN
# 218 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 219 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	waitmovement 0
# 220 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	msgbox LilycoveCity_CoveLilyMotel_1F_EventScript_WakeUp_Text_1
# 222 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	closemessage
# 223 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	setvar VAR_DARKRAI_STATE, 4
# 224 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	releaseall
	end


# 228 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
mGuestFirstStep:
# 229 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	walk_down
	step_end

# 232 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
mGuestApproachesSlowly:
# 233 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	walk_down
# 234 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	walk_down
	step_end

# 237 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
mGuestDisappears:
# 238 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	walk_up
# 239 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	walk_up
# 240 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	walk_up
# 241 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	walk_up
# 242 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	walk_up
	step_end

# 245 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
mDazed:
# 246 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	face_left
# 247 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	delay_16
# 248 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	face_right
# 249 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	delay_16
# 250 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	face_up
# 251 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	delay_16
# 252 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	face_left
# 253 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	delay_16
# 254 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	face_right
# 255 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	delay_16
# 256 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	face_down
# 257 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	delay_4
# 258 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	step_end

LilycoveCity_CoveLilyMotel_1F_EventScript_Warning_Text_0:
# 178 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "Who are you?\p"
	.string "No one has come to visit this hotel in\n"
	.string "50 years.$"

LilycoveCity_CoveLilyMotel_1F_EventScript_Warning_Text_1:
# 187 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "That Member Card...\n"
	.string "Could it be?$"

LilycoveCity_CoveLilyMotel_1F_EventScript_Warning_Text_2:
# 192 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "I can't believe I didn't recognize you!\n"
	.string "You haven't aged a day!\p"
	.string "Your room upstairs is waiting for you\n"
	.string "just how you left it.\p"
	.string "Enjoy your stay...$"

LilycoveCity_CoveLilyMotel_1F_EventScript_WakeUp_Text_0:
# 213 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "... ... ... ... ...\n"
	.string "... ... ... ... ...$"

LilycoveCity_CoveLilyMotel_1F_EventScript_WakeUp_Text_1:
# 220 "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.pory"
	.string "You jolted upright!\p"
	.string "It all felt so real...$"
