# 1 "data/maps/SlateportCity_Harbor/scripts.pory"

# 2 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_MapScripts::
# 3 "data/maps/SlateportCity_Harbor/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_Harbor_OnTransition
# 4 "data/maps/SlateportCity_Harbor/scripts.pory"
	.byte 0
# 5 "data/maps/SlateportCity_Harbor/scripts.pory"

# 6 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_OnTransition:
# 7 "data/maps/SlateportCity_Harbor/scripts.pory"
	setescapewarp MAP_SLATEPORT_CITY, 28, 13
# 8 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_TEMP_1, 0
# 9 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_SLATEPORT_HARBOR_STATE, 1, SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene
# 10 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_ShowSSTidal
# 11 "data/maps/SlateportCity_Harbor/scripts.pory"
    call_if_set FLAG_BADGE08_GET, SlateportCity_Harbor_EventScript_ShowSSTidal
# 12 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 13 "data/maps/SlateportCity_Harbor/scripts.pory"

# 14 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ShowSSTidal::
# 15 "data/maps/SlateportCity_Harbor/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
# 16 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 17 "data/maps/SlateportCity_Harbor/scripts.pory"

# 18 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ReadyAquaEscapeScene::
# 19 "data/maps/SlateportCity_Harbor/scripts.pory"
	savebgm MUS_ENCOUNTER_AQUA
# 20 "data/maps/SlateportCity_Harbor/scripts.pory"
	setobjectxyperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN, 12, 13
# 21 "data/maps/SlateportCity_Harbor/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_LEFT
# 22 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
# 23 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 24 "data/maps/SlateportCity_Harbor/scripts.pory"

# 25 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger0::
# 26 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 27 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 0
# 28 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 29 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 30 "data/maps/SlateportCity_Harbor/scripts.pory"

# 31 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger1::
# 32 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 33 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 1
# 34 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 35 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 36 "data/maps/SlateportCity_Harbor/scripts.pory"

# 37 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger2::
# 38 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 39 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 2
# 40 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 41 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 42 "data/maps/SlateportCity_Harbor/scripts.pory"

# 43 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeTrigger3::
# 44 "data/maps/SlateportCity_Harbor/scripts.pory"
	lockall
# 45 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8008, 3
# 46 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_PlayerWalkUp
# 47 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 48 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AquaEscapeScene
# 49 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 50 "data/maps/SlateportCity_Harbor/scripts.pory"

# 51 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AquaEscapeScene::
# 52 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, Common_Movement_WalkInPlaceFasterDown
# 53 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 54 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, Common_Movement_WalkInPlaceFasterDown
# 55 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 56 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 57 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove, MSGBOX_DEFAULT
# 58 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 59 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_GRUNT, SlateportCity_Harbor_Movement_AquaBoardSub
# 60 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_ARCHIE, SlateportCity_Harbor_Movement_AquaBoardSub
# 61 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_SUBMARINE, SlateportCity_Harbor_Movement_SubmarineExit
# 62 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 63 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeobject LOCALID_SLATEPORT_HARBOR_GRUNT
# 64 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeobject LOCALID_SLATEPORT_HARBOR_ARCHIE
# 65 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeobject LOCALID_SLATEPORT_HARBOR_SUBMARINE
# 66 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
# 67 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_MET_TEAM_AQUA_HARBOR
# 68 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_MOTEL_SCOTT
# 69 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 0, SlateportCity_Harbor_EventScript_SternApproachPlayer0
# 70 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 1, SlateportCity_Harbor_EventScript_SternApproachPlayer1
# 71 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 2, SlateportCity_Harbor_EventScript_SternApproachPlayer
# 72 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_0x8008, 3, SlateportCity_Harbor_EventScript_SternApproachPlayer
# 73 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
# 74 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 75 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
# 76 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
# 77 "data/maps/SlateportCity_Harbor/scripts.pory"
	copyobjectxytoperm LOCALID_SLATEPORT_HARBOR_CAPT_STERN
# 78 "data/maps/SlateportCity_Harbor/scripts.pory"
	setobjectmovementtype LOCALID_SLATEPORT_HARBOR_CAPT_STERN, MOVEMENT_TYPE_FACE_RIGHT
# 79 "data/maps/SlateportCity_Harbor/scripts.pory"
	releaseall
# 80 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 81 "data/maps/SlateportCity_Harbor/scripts.pory"

# 82 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SternApproachPlayer0::
# 83 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer0
# 84 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 85 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 86 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 87 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 88 "data/maps/SlateportCity_Harbor/scripts.pory"

# 89 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SternApproachPlayer1::
# 90 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer1
# 91 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 92 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 93 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 94 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 95 "data/maps/SlateportCity_Harbor/scripts.pory"

# 96 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SternApproachPlayer::
# 97 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_SLATEPORT_HARBOR_CAPT_STERN, SlateportCity_Harbor_Movement_SternApproachPlayer
# 98 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 99 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 100 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 101 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 102 "data/maps/SlateportCity_Harbor/scripts.pory"

# 103 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_AquaBoardSub:
# 104 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 105 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 106 "data/maps/SlateportCity_Harbor/scripts.pory"
	jump_up
# 107 "data/maps/SlateportCity_Harbor/scripts.pory"
	set_invisible
# 108 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 109 "data/maps/SlateportCity_Harbor/scripts.pory"

# 110 "data/maps/SlateportCity_Harbor/scripts.pory"
@ Unused, Archie instead shares above identical movement script with Grunt
# 111 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_ArchieBoardSub:
# 112 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 113 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 114 "data/maps/SlateportCity_Harbor/scripts.pory"
	jump_up
# 115 "data/maps/SlateportCity_Harbor/scripts.pory"
	set_invisible
# 116 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 117 "data/maps/SlateportCity_Harbor/scripts.pory"

# 118 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SubmarineExit:
# 119 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 120 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 121 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 122 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay_16
# 123 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 124 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 125 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 126 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 127 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 128 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 129 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 130 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 131 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_fast_right
# 132 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 133 "data/maps/SlateportCity_Harbor/scripts.pory"

# 134 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SternApproachPlayer0:
# 135 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 136 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 137 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 138 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 139 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 140 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 141 "data/maps/SlateportCity_Harbor/scripts.pory"

# 142 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SternApproachPlayer1:
# 143 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 144 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 145 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 146 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 147 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 148 "data/maps/SlateportCity_Harbor/scripts.pory"

# 149 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_SternApproachPlayer:
# 150 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 151 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 152 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_left
# 153 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 154 "data/maps/SlateportCity_Harbor/scripts.pory"

# 155 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_PlayerWalkUp:
# 156 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 157 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 158 "data/maps/SlateportCity_Harbor/scripts.pory"

# 159 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_FerryAttendant::
# 160 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 161 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 162 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_AskForTicket
# 163 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
# 164 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 165 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 166 "data/maps/SlateportCity_Harbor/scripts.pory"

# 167 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AskForTicket::
# 168 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 169 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_FlashedTicketWhereTo
# 170 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 171 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseDestination
# 172 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 173 "data/maps/SlateportCity_Harbor/scripts.pory"

# 174 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseDestination::
# 175 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_MET_SCOTT_ON_SS_TIDAL, SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier
# 176 "data/maps/SlateportCity_Harbor/scripts.pory"
	multichoicedefault 18, 8, MULTI_SSTIDAL_SLATEPORT_NO_BF, 2, FALSE
# 177 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 178 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 0, SlateportCity_Harbor_EventScript_Lilycove
# 179 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 1, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 180 "data/maps/SlateportCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 181 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 182 "data/maps/SlateportCity_Harbor/scripts.pory"

# 183 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseDestinationWithBattleFrontier::
# 184 "data/maps/SlateportCity_Harbor/scripts.pory"
	multichoicedefault 17, 6, MULTI_SSTIDAL_SLATEPORT_WITH_BF, 2, FALSE
# 185 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 186 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 0, SlateportCity_Harbor_EventScript_Lilycove
# 187 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 1, SlateportCity_Harbor_EventScript_BattleFrontier
# 188 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 2, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 189 "data/maps/SlateportCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_CancelDestinationSelect
# 190 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 191 "data/maps/SlateportCity_Harbor/scripts.pory"

# 192 "data/maps/SlateportCity_Harbor/scripts.pory"
@ Unused. Should be impossible for player to reach Ferry without having received SS Tidal ticket
# 193 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_NoTicket::
# 194 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_YouMustHaveTicket, MSGBOX_DEFAULT
# 195 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 196 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 197 "data/maps/SlateportCity_Harbor/scripts.pory"

# 198 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_Lilycove::
# 199 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_LilycoveItIs, MSGBOX_YESNO
# 200 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
# 201 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, SS_TIDAL_BOARD_SLATEPORT
# 202 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportCity_Harbor_EventScript_BoardFerry
# 203 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_SS_TIDAL_CORRIDOR, 1, 10
# 204 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitstate
# 205 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 206 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 207 "data/maps/SlateportCity_Harbor/scripts.pory"

# 208 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BattleFrontier::
# 209 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_BattleFrontierItIs, MSGBOX_YESNO
# 210 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
# 211 "data/maps/SlateportCity_Harbor/scripts.pory"
	call SlateportCity_Harbor_EventScript_BoardFerry
# 212 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 19, 67
# 213 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitstate
# 214 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 215 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 216 "data/maps/SlateportCity_Harbor/scripts.pory"

# 217 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseNewDestination::
# 218 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_WhereWouldYouLikeToGo
# 219 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 220 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseDestination
# 221 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 222 "data/maps/SlateportCity_Harbor/scripts.pory"

# 223 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BoardFerry::
# 224 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_PleaseBoardFerry, MSGBOX_DEFAULT
# 225 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 226 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
# 227 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 228 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay 30
# 229 "data/maps/SlateportCity_Harbor/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
# 230 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SlateportCity_Harbor_EventScript_BoardFerryNorth
# 231 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_Harbor_EventScript_BoardFerryEast
# 232 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay 30
# 233 "data/maps/SlateportCity_Harbor/scripts.pory"
	hideplayer
# 234 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_SLATEPORT_HARBOR_SS_TIDAL
# 235 "data/maps/SlateportCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
# 236 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 237 "data/maps/SlateportCity_Harbor/scripts.pory"

# 238 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CancelDestinationSelect::
# 239 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_SailAnotherTime, MSGBOX_DEFAULT
# 240 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 241 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 242 "data/maps/SlateportCity_Harbor/scripts.pory"

# 243 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BoardFerryEast::
# 244 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryEast
# 245 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 246 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 247 "data/maps/SlateportCity_Harbor/scripts.pory"

# 248 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_BoardFerryNorth::
# 249 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement LOCALID_PLAYER, SlateportCity_Harbor_Movement_BoardFerryNorth
# 250 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 251 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 252 "data/maps/SlateportCity_Harbor/scripts.pory"

# 253 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_BoardFerryEast:
# 254 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 255 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_in_place_faster_up
# 256 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 257 "data/maps/SlateportCity_Harbor/scripts.pory"

# 258 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_BoardFerryNorth:
# 259 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 260 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end
# 261 "data/maps/SlateportCity_Harbor/scripts.pory"

# 262 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_Sailor::
# 263 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 264 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 265 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather
# 266 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8004, 0
# 267 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_set FLAG_DEFEATED_KYOGRE, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
# 268 "data/maps/SlateportCity_Harbor/scripts.pory"
	call_if_set FLAG_DEFEATED_GROUDON, SlateportCity_Harbor_EventScript_CountDefeatedLegendary
# 269 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_0x8004, 2, SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather  @ Defeated both
# 270 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_AbnormalWeather, MSGBOX_DEFAULT
# 271 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 272 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 273 "data/maps/SlateportCity_Harbor/scripts.pory"

# 274 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_SailorNoAbnormalWeather::
# 275 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday, MSGBOX_DEFAULT
# 276 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 277 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 278 "data/maps/SlateportCity_Harbor/scripts.pory"

# 279 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CountDefeatedLegendary::
# 280 "data/maps/SlateportCity_Harbor/scripts.pory"
	addvar VAR_0x8004, 1
# 281 "data/maps/SlateportCity_Harbor/scripts.pory"
	return
# 282 "data/maps/SlateportCity_Harbor/scripts.pory"

# 283 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_FatMan::
# 284 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_SubTooSmallForMe, MSGBOX_NPC
# 285 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 286 "data/maps/SlateportCity_Harbor/scripts.pory"

# 287 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CaptStern::
# 288 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 289 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 290 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment
# 291 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE, SlateportCity_Harbor_EventScript_NeedDive
# 292 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive
# 293 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_SLATEPORT_HARBOR_STATE, 2, SlateportCity_Harbor_EventScript_WhyStealSubmarine
# 294 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum, MSGBOX_DEFAULT
# 295 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 296 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 297 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 298 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 299 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 300 "data/maps/SlateportCity_Harbor/scripts.pory"

# 301 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_WhyStealSubmarine::
# 302 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine, MSGBOX_DEFAULT
# 303 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 304 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 305 "data/maps/SlateportCity_Harbor/scripts.pory"

# 306 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_TeamAquaLeftNeedDive::
# 307 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE
# 308 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_TeamAquaLeftNeedDive, MSGBOX_DEFAULT
# 309 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 310 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 311 "data/maps/SlateportCity_Harbor/scripts.pory"

# 312 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_NeedDive::
# 313 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_NeedDiveToCatchSub, MSGBOX_DEFAULT
# 314 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 315 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 316 "data/maps/SlateportCity_Harbor/scripts.pory"

# 317 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_CaptSternFerryOrScannerComment::
# 318 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_TEMP_1, 1, SlateportCity_Harbor_EventScript_TradedScanner
# 319 "data/maps/SlateportCity_Harbor/scripts.pory"
	checkitem ITEM_SCANNER
# 320 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_Harbor_EventScript_AskToTradeScanner
# 321 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_Harbor_EventScript_FerryFinished
# 322 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry, MSGBOX_DEFAULT
# 323 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 324 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 325 "data/maps/SlateportCity_Harbor/scripts.pory"

# 326 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_FerryFinished::
# 327 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_FinishedMakingFerry, MSGBOX_DEFAULT
# 328 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 329 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 330 "data/maps/SlateportCity_Harbor/scripts.pory"

# 331 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_AskToTradeScanner::
# 332 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_WouldYouTradeScanner
# 333 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 334 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
# 335 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 336 "data/maps/SlateportCity_Harbor/scripts.pory"

# 337 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseScannerTrade::
# 338 "data/maps/SlateportCity_Harbor/scripts.pory"
	multichoice 0, 0, MULTI_STERN_DEEPSEA, FALSE
# 339 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 340 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 0, SlateportCity_Harbor_EventScript_DeepSeaTooth
# 341 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 1, SlateportCity_Harbor_EventScript_DeepSeaScale
# 342 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 2, SlateportCity_Harbor_EventScript_DeclineTrade
# 343 "data/maps/SlateportCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_DeclineTrade
# 344 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 345 "data/maps/SlateportCity_Harbor/scripts.pory"

# 346 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_DeepSeaTooth::
# 347 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaTooth, MSGBOX_YESNO
# 348 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
# 349 "data/maps/SlateportCity_Harbor/scripts.pory"
	giveitem ITEM_DEEP_SEA_TOOTH
# 350 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 351 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeitem ITEM_SCANNER
# 352 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
# 353 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_EXCHANGED_SCANNER
# 354 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_TradedScanner
# 355 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 356 "data/maps/SlateportCity_Harbor/scripts.pory"

# 357 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_DeepSeaScale::
# 358 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_TradeForDeepSeaScale, MSGBOX_YESNO
# 359 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseDifferentTrade
# 360 "data/maps/SlateportCity_Harbor/scripts.pory"
	giveitem ITEM_DEEP_SEA_SCALE
# 361 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 362 "data/maps/SlateportCity_Harbor/scripts.pory"
	removeitem ITEM_SCANNER
# 363 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_HandedScannerToStern, MSGBOX_DEFAULT
# 364 "data/maps/SlateportCity_Harbor/scripts.pory"
	setflag FLAG_EXCHANGED_SCANNER
# 365 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_TradedScanner
# 366 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 367 "data/maps/SlateportCity_Harbor/scripts.pory"

# 368 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_DeclineTrade::
# 369 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow, MSGBOX_DEFAULT
# 370 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 371 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 372 "data/maps/SlateportCity_Harbor/scripts.pory"

# 373 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_ChooseDifferentTrade::
# 374 "data/maps/SlateportCity_Harbor/scripts.pory"
	message SlateportCity_Harbor_Text_WhichOneDoYouWant
# 375 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 376 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_ChooseScannerTrade
# 377 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 378 "data/maps/SlateportCity_Harbor/scripts.pory"

# 379 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_EventScript_TradedScanner::
# 380 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_TEMP_1, 1
# 381 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_ThisWillHelpResearch, MSGBOX_DEFAULT
# 382 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
# 383 "data/maps/SlateportCity_Harbor/scripts.pory"
	end
# 384 "data/maps/SlateportCity_Harbor/scripts.pory"

# 385 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_FerryServiceUnavailable:
# 386 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I beg your pardon?\n"
# 387 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You're looking for a ship?\p"
# 388 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I'm sorry, the ferry service isn't\n"
# 389 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "available at present…$"
# 390 "data/maps/SlateportCity_Harbor/scripts.pory"

# 391 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_MayISeeYourTicket:
# 392 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Hello, are you here for the ferry?\n"
# 393 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "May I see your Ticket?$"
# 394 "data/maps/SlateportCity_Harbor/scripts.pory"

# 395 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_YouMustHaveTicket:
# 396 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER} doesn't have the Ticket…\p"
# 397 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I'm terribly sorry.\p"
# 398 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You must have a Ticket to board\n"
# 399 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "the ferry.$"
# 400 "data/maps/SlateportCity_Harbor/scripts.pory"

# 401 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_FlashedTicketWhereTo:
# 402 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER} flashed the Ticket.\p"
# 403 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Perfect! That's all you need!\p"
# 404 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "And where would you like to go?$"
# 405 "data/maps/SlateportCity_Harbor/scripts.pory"

# 406 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_SailAnotherTime:
# 407 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Please sail with us another time!$"
# 408 "data/maps/SlateportCity_Harbor/scripts.pory"

# 409 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_LilycoveItIs:
# 410 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Lilycove City it is, then!$"
# 411 "data/maps/SlateportCity_Harbor/scripts.pory"

# 412 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_BattleFrontierItIs:
# 413 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Battle Frontier it is, then!$"
# 414 "data/maps/SlateportCity_Harbor/scripts.pory"

# 415 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_PleaseBoardFerry:
# 416 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Please board the ferry and wait for\n"
# 417 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "departure.$"
# 418 "data/maps/SlateportCity_Harbor/scripts.pory"

# 419 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WhereWouldYouLikeToGo:
# 420 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Then, where would you like to go?$"
# 421 "data/maps/SlateportCity_Harbor/scripts.pory"

# 422 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_LoveToGoDeepUnderwaterSomeday:
# 423 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "A journey to the bottom of the sea…\n"
# 424 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I wonder what it'd be like?\p"
# 425 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I'd love to go deep underwater like\n"
# 426 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "that someday.$"
# 427 "data/maps/SlateportCity_Harbor/scripts.pory"

# 428 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_AbnormalWeather:
# 429 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "For a ship to sail safely, we need to\n"
# 430 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "know about the weather!\p"
# 431 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Speaking of weather, I heard something\n"
# 432 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "from a guy at the Weather Institute.\p"
# 433 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "He was saying abnormal weather has\n"
# 434 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "been reported all over the place!\p"
# 435 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You should visit the Weather Institute\n"
# 436 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "and ask around!$"
# 437 "data/maps/SlateportCity_Harbor/scripts.pory"

# 438 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_SubTooSmallForMe:
# 439 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I wanted to go with Capt. Stern on\n"
# 440 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "the ocean floor exploration.\p"
# 441 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "But the sub's too small for me.\p"
# 442 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "If I squeezed in, there wouldn't be\n"
# 443 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "any room for the Captain…$"
# 444 "data/maps/SlateportCity_Harbor/scripts.pory"

# 445 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_SameThugsTriedToRobAtMuseum:
# 446 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Those thugs…\p"
# 447 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "They're the same lot who tried to rob\n"
# 448 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "the Devon Goods at the Museum.$"
# 449 "data/maps/SlateportCity_Harbor/scripts.pory"

# 450 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_ArchieYouAgainHideoutInLilycove:
# 451 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Archie: Oh?\n"
# 452 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Not you again…\p"
# 453 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You are tenacious to track us here,\n"
# 454 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "that much I will give you.\p"
# 455 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "But now…\n"
# 456 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "No one can stop us! No one!\p"
# 457 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Or, will you follow us back to our\n"
# 458 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Hideout in Lilycove City?\p"
# 459 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Fwahahahaha…$"
# 460 "data/maps/SlateportCity_Harbor/scripts.pory"

# 461 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_CaptSternWhyStealMySubmarine:
# 462 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Why…\p"
# 463 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Why would Team Aqua steal\n"
# 464 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Submarine Explorer 1?\p"
# 465 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "They can't be after the slumbering\n"
# 466 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Pokémon at the bottom of the sea…\p"
# 467 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "But even if I were to chase them,\n"
# 468 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "I don't stand a chance against them…$"
# 469 "data/maps/SlateportCity_Harbor/scripts.pory"

# 470 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_TeamAquaLeftNeedDive:
# 471 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Oh, {PLAYER}{KUN}…\p"
# 472 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Okay… So Team Aqua left before you\n"
# 473 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "could stop them…\p"
# 474 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Oh, no, don't blame yourself.\n"
# 475 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You're not responsible for this.\p"
# 476 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Trying to catch a submarine…\n"
# 477 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "It's impossible for most people.\p"
# 478 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You would need a Pokémon that knows\n"
# 479 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "how to Dive…\p"
# 480 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Perhaps if you went out to\n"
# 481 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Mossdeep City…\p"
# 482 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "A lot of divers live out there, so\n"
# 483 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "someone might be able to teach you…$"
# 484 "data/maps/SlateportCity_Harbor/scripts.pory"

# 485 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_NeedDiveToCatchSub:
# 486 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Trying to catch a\n"
# 487 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "submarine… It's impossible.\p"
# 488 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "You would need a Pokémon that knows\n"
# 489 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "how to Dive…\p"
# 490 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Perhaps if you went out to\n"
# 491 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Mossdeep City…\p"
# 492 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "A lot of divers live out there, so\n"
# 493 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "someone might be able to teach you…$"
# 494 "data/maps/SlateportCity_Harbor/scripts.pory"

# 495 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WontBeLongBeforeWeFinishFerry:
# 496 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Oh, yes.\n"
# 497 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Mr. Briney came to our Shipyard.\p"
# 498 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "It won't be long now before we finish\n"
# 499 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "making the ferry!$"
# 500 "data/maps/SlateportCity_Harbor/scripts.pory"

# 501 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_FinishedMakingFerry:
# 502 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: {PLAYER}{KUN}!\p"
# 503 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "We finally finished making the ferry\n"
# 504 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "S.S. Tidal!\p"
# 505 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "We couldn't have done it without\n"
# 506 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "your friend Mr. Briney.\p"
# 507 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Please go for a short cruise on it!$"
# 508 "data/maps/SlateportCity_Harbor/scripts.pory"

# 509 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WouldYouTradeScanner:
# 510 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Oh?\n"
# 511 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER}{KUN}, that item you have…\p"
# 512 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "That's a Scanner! That would sure\n"
# 513 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "help us on our explorations.\p"
# 514 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER}{KUN}, would you trade your\n"
# 515 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Scanner for something?\p"
# 516 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Like, say, a Deep Sea Tooth or\n"
# 517 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "a Deep Sea Scale that I have?$"
# 518 "data/maps/SlateportCity_Harbor/scripts.pory"

# 519 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_IfYouWantToTradeLetMeKnow:
# 520 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Are you certain?\n"
# 521 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "It's useless to you, {PLAYER}{KUN}…\p"
# 522 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Well, okay, then. If you want to trade\n"
# 523 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "your Scanner, let me know.$"
# 524 "data/maps/SlateportCity_Harbor/scripts.pory"

# 525 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_TradeForDeepSeaTooth:
# 526 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: So you'll trade it for\n"
# 527 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "my Deep Sea Tooth?$"
# 528 "data/maps/SlateportCity_Harbor/scripts.pory"

# 529 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_TradeForDeepSeaScale:
# 530 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: So you'll trade it for\n"
# 531 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "my Deep Sea Scale?$"
# 532 "data/maps/SlateportCity_Harbor/scripts.pory"

# 533 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_WhichOneDoYouWant:
# 534 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Which one do you want?$"
# 535 "data/maps/SlateportCity_Harbor/scripts.pory"

# 536 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_HandedScannerToStern:
# 537 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "{PLAYER} handed the Scanner to\n"
# 538 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern.$"
# 539 "data/maps/SlateportCity_Harbor/scripts.pory"

# 540 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Text_ThisWillHelpResearch:
# 541 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Capt. Stern: Thanks, {PLAYER}{KUN}!\n"
# 542 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "This will help our research a lot!$"

_SlateportCity_Harbor_EventScript_FerryAttendant::
# 545 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 546 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 547 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, _SlateportCity_Harbor_EventScript_FerryAttendant_2
_SlateportCity_Harbor_EventScript_FerryAttendant_1:
# 550 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, _SlateportCity_Harbor_EventScript_FerryAttendant_5
# 576 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox SlateportCity_Harbor_Text_FerryServiceUnavailable, MSGBOX_DEFAULT
# 577 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
	end

_SlateportCity_Harbor_EventScript_FerryAttendant_2:
# 548 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_AskForTicket
	goto _SlateportCity_Harbor_EventScript_FerryAttendant_1

_SlateportCity_Harbor_EventScript_FerryAttendant_5:
# 551 "data/maps/SlateportCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetEonTicketState
# 552 "data/maps/SlateportCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetAuroraTicketState
# 553 "data/maps/SlateportCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetOldSeaMapState
# 554 "data/maps/SlateportCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetMysticTicketState
# 555 "data/maps/SlateportCity_Harbor/scripts.pory"
	call LilycoveCity_Harbor_EventScript_GetLibertyPassState
# 556 "data/maps/SlateportCity_Harbor/scripts.pory"
	call _LilycoveCity_Harbor_EventScript_GetFirstTimeShowingTicket
# 557 "data/maps/SlateportCity_Harbor/scripts.pory"
	call _LilycoveCity_Harbor_EventScript_GetHasTicketsState
# 558 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, _SlateportCity_Harbor_EventScript_FerryAttendant_8
# 559 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_ENABLE_SHIP_NAVEL_ROCK, _SlateportCity_Harbor_EventScript_FerryAttendant_8
# 560 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_ENABLE_SHIP_BIRTH_ISLAND, _SlateportCity_Harbor_EventScript_FerryAttendant_8
# 561 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_ENABLE_SHIP_FARAWAY_ISLAND, _SlateportCity_Harbor_EventScript_FerryAttendant_8
# 562 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_ENABLE_SHIP_LIBERTY_GARDEN, _SlateportCity_Harbor_EventScript_FerryAttendant_8
_SlateportCity_Harbor_EventScript_FerryAttendant_7:
# 570 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox _SlateportCity_Harbor_EventScript_FerryAttendant_Text_1
# 573 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
	end

_SlateportCity_Harbor_EventScript_FerryAttendant_8:
# 564 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox _SlateportCity_Harbor_EventScript_FerryAttendant_Text_0
# 567 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmessage
# 568 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto SlateportCity_Harbor_EventScript_EarlyIslandSelect
	goto _SlateportCity_Harbor_EventScript_FerryAttendant_7


SlateportCity_Harbor_EventScript_EarlyIslandSelect::
# 582 "data/maps/SlateportCity_Harbor/scripts.pory"
	lock
# 583 "data/maps/SlateportCity_Harbor/scripts.pory"
	faceplayer
# 584 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_ENABLE_SHIP_SOUTHERN_ISLAND, SlateportCity_Harbor_EventScript_EarlyIslandSelect_2
SlateportCity_Harbor_EventScript_EarlyIslandSelect_1:
# 587 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_ENABLE_SHIP_NAVEL_ROCK, SlateportCity_Harbor_EventScript_EarlyIslandSelect_5
SlateportCity_Harbor_EventScript_EarlyIslandSelect_4:
# 590 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_ENABLE_SHIP_BIRTH_ISLAND, SlateportCity_Harbor_EventScript_EarlyIslandSelect_8
SlateportCity_Harbor_EventScript_EarlyIslandSelect_7:
# 593 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_ENABLE_SHIP_FARAWAY_ISLAND, SlateportCity_Harbor_EventScript_EarlyIslandSelect_11
SlateportCity_Harbor_EventScript_EarlyIslandSelect_10:
# 596 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto_if_set FLAG_ENABLE_SHIP_LIBERTY_GARDEN, SlateportCity_Harbor_EventScript_EarlyIslandSelect_14
SlateportCity_Harbor_EventScript_EarlyIslandSelect_13:
# 599 "data/maps/SlateportCity_Harbor/scripts.pory"
	dynmultipush SlateportCity_Harbor_EventScript_EarlyIslandSelect_Text_5, SSTIDAL_SELECTION_EXIT
# 600 "data/maps/SlateportCity_Harbor/scripts.pory"
	dynmultistack 0, 0, FALSE, 6, FALSE, DYN_MULTICHOICE_CB_NONE, DYN_MULTICHOICE_CB_NONE
# 602 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_RESULT
# 603 "data/maps/SlateportCity_Harbor/scripts.pory"
	case SSTIDAL_SELECTION_EXIT, SlateportCity_Harbor_EventScript_EarlyIslandSelect_17
# 604 "data/maps/SlateportCity_Harbor/scripts.pory"
	case MULTI_B_PRESSED, SlateportCity_Harbor_EventScript_EarlyIslandSelect_17
# 609 "data/maps/SlateportCity_Harbor/scripts.pory"
	copyvar VAR_TEMP_1, VAR_RESULT
# 610 "data/maps/SlateportCity_Harbor/scripts.pory"
	goto _Slateport_BoardTheShip
	return

SlateportCity_Harbor_EventScript_EarlyIslandSelect_2:
# 585 "data/maps/SlateportCity_Harbor/scripts.pory"
	dynmultipush SlateportCity_Harbor_EventScript_EarlyIslandSelect_Text_0, SSTIDAL_SELECTION_SOUTHERN_ISLAND
	goto SlateportCity_Harbor_EventScript_EarlyIslandSelect_1

SlateportCity_Harbor_EventScript_EarlyIslandSelect_5:
# 588 "data/maps/SlateportCity_Harbor/scripts.pory"
	dynmultipush SlateportCity_Harbor_EventScript_EarlyIslandSelect_Text_1, SSTIDAL_SELECTION_NAVEL_ROCK
	goto SlateportCity_Harbor_EventScript_EarlyIslandSelect_4

SlateportCity_Harbor_EventScript_EarlyIslandSelect_8:
# 591 "data/maps/SlateportCity_Harbor/scripts.pory"
	dynmultipush SlateportCity_Harbor_EventScript_EarlyIslandSelect_Text_2, SSTIDAL_SELECTION_BIRTH_ISLAND
	goto SlateportCity_Harbor_EventScript_EarlyIslandSelect_7

SlateportCity_Harbor_EventScript_EarlyIslandSelect_11:
# 594 "data/maps/SlateportCity_Harbor/scripts.pory"
	dynmultipush SlateportCity_Harbor_EventScript_EarlyIslandSelect_Text_3, SSTIDAL_SELECTION_FARAWAY_ISLAND
	goto SlateportCity_Harbor_EventScript_EarlyIslandSelect_10

SlateportCity_Harbor_EventScript_EarlyIslandSelect_14:
# 597 "data/maps/SlateportCity_Harbor/scripts.pory"
	dynmultipush SlateportCity_Harbor_EventScript_EarlyIslandSelect_Text_4, SSTIDAL_SELECTION_LIBERTY_GARDEN
	goto SlateportCity_Harbor_EventScript_EarlyIslandSelect_13

SlateportCity_Harbor_EventScript_EarlyIslandSelect_17:
# 605 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_SailAnotherTime
# 606 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
	end


_Slateport_BoardTheShip::
# 615 "data/maps/SlateportCity_Harbor/scripts.pory"
	msgbox LilycoveCity_Harbor_Text_PleaseBoard
# 616 "data/maps/SlateportCity_Harbor/scripts.pory"
	closemessage
# 617 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
# 618 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 619 "data/maps/SlateportCity_Harbor/scripts.pory"
	delay 30
# 620 "data/maps/SlateportCity_Harbor/scripts.pory"
	hideobjectat VAR_LAST_TALKED, MAP_SLATEPORT_CITY_HARBOR
# 621 "data/maps/SlateportCity_Harbor/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_eq _Slateport_BoardTheShip_2
# 624 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_PlayerBoardFerryEast
_Slateport_BoardTheShip_1:
# 626 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitmovement 0
# 627 "data/maps/SlateportCity_Harbor/scripts.pory"
	hideplayer
# 628 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_0x8004, LOCALID_SLATEPORT_HARBOR_SS_TIDAL
# 629 "data/maps/SlateportCity_Harbor/scripts.pory"
	call Common_EventScript_FerryDepart
# 630 "data/maps/SlateportCity_Harbor/scripts.pory"
	setvar VAR_SS_TIDAL_STATE, 1
# 631 "data/maps/SlateportCity_Harbor/scripts.pory"
	switch VAR_TEMP_1
# 632 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 2, _Slateport_BoardTheShip_7
# 633 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 3, _Slateport_BoardTheShip_8
# 634 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 4, _Slateport_BoardTheShip_9
# 635 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 5, _Slateport_BoardTheShip_10
# 636 "data/maps/SlateportCity_Harbor/scripts.pory"
	case 6, _Slateport_BoardTheShip_11
_Slateport_BoardTheShip_5:
# 638 "data/maps/SlateportCity_Harbor/scripts.pory"
	waitstate
# 639 "data/maps/SlateportCity_Harbor/scripts.pory"
	release
	end

_Slateport_BoardTheShip_2:
# 622 "data/maps/SlateportCity_Harbor/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Harbor_Movement_PlayerBoardFerryNorth
	goto _Slateport_BoardTheShip_1

_Slateport_BoardTheShip_7:
# 632 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
	goto _Slateport_BoardTheShip_5

_Slateport_BoardTheShip_8:
# 633 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_NAVEL_ROCK_HARBOR, 8, 4
	goto _Slateport_BoardTheShip_5

_Slateport_BoardTheShip_9:
# 634 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_BIRTH_ISLAND_HARBOR, 8, 4
	goto _Slateport_BoardTheShip_5

_Slateport_BoardTheShip_10:
# 635 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
	goto _Slateport_BoardTheShip_5

_Slateport_BoardTheShip_11:
# 636 "data/maps/SlateportCity_Harbor/scripts.pory"
	warp MAP_LIBERTY_GARDEN, 3, 10
	goto _Slateport_BoardTheShip_5


# 643 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_PlayerBoardFerryEast:
# 644 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_right
# 645 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_in_place_faster_up
# 646 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end

# 649 "data/maps/SlateportCity_Harbor/scripts.pory"
SlateportCity_Harbor_Movement_PlayerBoardFerryNorth:
# 650 "data/maps/SlateportCity_Harbor/scripts.pory"
	walk_up
# 651 "data/maps/SlateportCity_Harbor/scripts.pory"
	step_end

_SlateportCity_Harbor_EventScript_FerryAttendant_Text_0:
# 564 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "The S.S. Tidal is complete, but we're\n"
	.string "only running limited voyages for now.\p"
	.string "Oh! You have a special ticket?\n"
	.string "Where would you like to go?$"

_SlateportCity_Harbor_EventScript_FerryAttendant_Text_1:
# 570 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "The S.S. Tidal is finally complete!\p"
	.string "However, we're only taking a limited\n"
	.string "number of passengers for trials.\p"
	.string "Please come back later for the\n"
	.string "full ferry service.$"

SlateportCity_Harbor_EventScript_EarlyIslandSelect_Text_0:
# 585 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Southern Island$"

SlateportCity_Harbor_EventScript_EarlyIslandSelect_Text_1:
# 588 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Navel Rock$"

SlateportCity_Harbor_EventScript_EarlyIslandSelect_Text_2:
# 591 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Birth Island$"

SlateportCity_Harbor_EventScript_EarlyIslandSelect_Text_3:
# 594 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Faraway Island$"

SlateportCity_Harbor_EventScript_EarlyIslandSelect_Text_4:
# 597 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Liberty Garden$"

SlateportCity_Harbor_EventScript_EarlyIslandSelect_Text_5:
# 599 "data/maps/SlateportCity_Harbor/scripts.pory"
	.string "Exit$"
