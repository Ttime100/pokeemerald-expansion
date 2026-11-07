# 1 "data/maps/MtChimney/scripts.pory"

# 2 "data/maps/MtChimney/scripts.pory"
MtChimney_MapScripts::
# 3 "data/maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
# 4 "data/maps/MtChimney/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
# 5 "data/maps/MtChimney/scripts.pory"
	.byte 0
# 6 "data/maps/MtChimney/scripts.pory"

# 7 "data/maps/MtChimney/scripts.pory"
MtChimney_OnTransition:
# 8 "data/maps/MtChimney/scripts.pory"
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
# 9 "data/maps/MtChimney/scripts.pory"
    setflag FLAG_HIDE_MOLTRES_EMERALD
# 10 "data/maps/MtChimney/scripts.pory"
	call_if_set FLAG_RECEIVED_ROAMER_CALL, MtChimney_EventScript_TryShowMoltres
# 11 "data/maps/MtChimney/scripts.pory"
	end
# 12 "data/maps/MtChimney/scripts.pory"

# 13 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_TryShowMoltres::
# 14 "data/maps/MtChimney/scripts.pory"
	setvar VAR_TEMP_1, 1
# 15 "data/maps/MtChimney/scripts.pory"
	goto_if_set FLAG_CAUGHT_MOLTRES, Common_EventScript_NopReturn
# 16 "data/maps/MtChimney/scripts.pory"
	goto_if_set FLAG_DEFEATED_MOLTRES, Common_EventScript_NopReturn
# 17 "data/maps/MtChimney/scripts.pory"
	setvar VAR_TEMP_1, 0
# 18 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_MOLTRES_EMERALD
# 19 "data/maps/MtChimney/scripts.pory"
	return
# 20 "data/maps/MtChimney/scripts.pory"

# 21 "data/maps/MtChimney/scripts.pory"
MtChimney_OnResume:
# 22 "data/maps/MtChimney/scripts.pory"
	setstepcallback STEP_CB_ASH
# 23 "data/maps/MtChimney/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtChimney_EventScript_TryRemoveMoltres
# 24 "data/maps/MtChimney/scripts.pory"
	end
# 25 "data/maps/MtChimney/scripts.pory"

# 26 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_TryRemoveMoltres::
# 27 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 28 "data/maps/MtChimney/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 29 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MOLTRES
# 30 "data/maps/MtChimney/scripts.pory"
	return
# 31 "data/maps/MtChimney/scripts.pory"

# 32 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Archie::
# 33 "data/maps/MtChimney/scripts.pory"
	lock
# 34 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 35 "data/maps/MtChimney/scripts.pory"
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
# 36 "data/maps/MtChimney/scripts.pory"
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
# 37 "data/maps/MtChimney/scripts.pory"
	closemessage
# 38 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
# 39 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 40 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
# 41 "data/maps/MtChimney/scripts.pory"
	release
# 42 "data/maps/MtChimney/scripts.pory"
	end
# 43 "data/maps/MtChimney/scripts.pory"

# 44 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieGoStopTeamMagma::
# 45 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
# 46 "data/maps/MtChimney/scripts.pory"
	return
# 47 "data/maps/MtChimney/scripts.pory"

# 48 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieBusyFighting::
# 49 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
# 50 "data/maps/MtChimney/scripts.pory"
	return
# 51 "data/maps/MtChimney/scripts.pory"

# 52 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Maxie::
# 53 "data/maps/MtChimney/scripts.pory"
	lockall
# 54 "data/maps/MtChimney/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 55 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
# 56 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
# 57 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 58 "data/maps/MtChimney/scripts.pory"
	playse SE_PIN
# 59 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
# 60 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 61 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
# 62 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 63 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
# 64 "data/maps/MtChimney/scripts.pory"
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
# 65 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
# 66 "data/maps/MtChimney/scripts.pory"
	closemessage
# 67 "data/maps/MtChimney/scripts.pory"
	delay 30
# 68 "data/maps/MtChimney/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 69 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MAXIE
# 70 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
# 71 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_TABITHA
# 72 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
# 73 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
# 74 "data/maps/MtChimney/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 75 "data/maps/MtChimney/scripts.pory"
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
# 76 "data/maps/MtChimney/scripts.pory"
	addobject LOCALID_MT_CHIMNEY_ARCHIE
# 77 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
# 78 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
# 79 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 80 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 81 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
# 82 "data/maps/MtChimney/scripts.pory"
	closemessage
# 83 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
# 84 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
# 85 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
# 86 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
# 87 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
# 88 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
# 89 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
# 90 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
# 91 "data/maps/MtChimney/scripts.pory"
	releaseall
# 92 "data/maps/MtChimney/scripts.pory"
	end
# 93 "data/maps/MtChimney/scripts.pory"

# 94 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerEast::
# 95 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
# 96 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 97 "data/maps/MtChimney/scripts.pory"
	return
# 98 "data/maps/MtChimney/scripts.pory"

# 99 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerNorth::
# 100 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
# 101 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 102 "data/maps/MtChimney/scripts.pory"
	return
# 103 "data/maps/MtChimney/scripts.pory"

# 104 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitEast::
# 105 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
# 106 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 107 "data/maps/MtChimney/scripts.pory"
	return
# 108 "data/maps/MtChimney/scripts.pory"

# 109 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitNorth::
# 110 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
# 111 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 112 "data/maps/MtChimney/scripts.pory"
	return
# 113 "data/maps/MtChimney/scripts.pory"

# 114 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_LavaCookieLady::
# 115 "data/maps/MtChimney/scripts.pory"
	lock
# 116 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 117 "data/maps/MtChimney/scripts.pory"
	showmoneybox 0, 0
# 118 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
# 119 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
# 120 "data/maps/MtChimney/scripts.pory"
	checkmoney 200
# 121 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
# 122 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
# 123 "data/maps/MtChimney/scripts.pory"
	checkitemspace ITEM_LAVA_COOKIE
# 124 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
# 125 "data/maps/MtChimney/scripts.pory"
.if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_OFF
# 126 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 127 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 128 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 129 "data/maps/MtChimney/scripts.pory"
	release
# 130 "data/maps/MtChimney/scripts.pory"
	end
# 131 "data/maps/MtChimney/scripts.pory"

# 132 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 133 "data/maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 134 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 135 "data/maps/MtChimney/scripts.pory"
	release
# 136 "data/maps/MtChimney/scripts.pory"
	end
# 137 "data/maps/MtChimney/scripts.pory"
.else
# 138 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 139 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 140 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 141 "data/maps/MtChimney/scripts.pory"
	release
# 142 "data/maps/MtChimney/scripts.pory"
	end
# 143 "data/maps/MtChimney/scripts.pory"

# 144 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 145 "data/maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 146 "data/maps/MtChimney/scripts.pory"
	release
# 147 "data/maps/MtChimney/scripts.pory"
	end
# 148 "data/maps/MtChimney/scripts.pory"
.endif @ OW_SHOW_ITEM_DESCRIPTIONS
# 149 "data/maps/MtChimney/scripts.pory"

# 150 "data/maps/MtChimney/scripts.pory"

# 151 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RemoveMoney::
# 152 "data/maps/MtChimney/scripts.pory"
	removemoney 200
# 153 "data/maps/MtChimney/scripts.pory"
	updatemoneybox
# 154 "data/maps/MtChimney/scripts.pory"
	return
# 155 "data/maps/MtChimney/scripts.pory"

# 156 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_DeclineLavaCookie::
# 157 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
# 158 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 159 "data/maps/MtChimney/scripts.pory"
	release
# 160 "data/maps/MtChimney/scripts.pory"
	end
# 161 "data/maps/MtChimney/scripts.pory"

# 162 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_NotEnoughMoney::
# 163 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 164 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 165 "data/maps/MtChimney/scripts.pory"
	release
# 166 "data/maps/MtChimney/scripts.pory"
	end
# 167 "data/maps/MtChimney/scripts.pory"

# 168 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerEast:
# 169 "data/maps/MtChimney/scripts.pory"
	walk_up
# 170 "data/maps/MtChimney/scripts.pory"
	walk_up
# 171 "data/maps/MtChimney/scripts.pory"
	walk_up
# 172 "data/maps/MtChimney/scripts.pory"
	walk_up
# 173 "data/maps/MtChimney/scripts.pory"
	walk_up
# 174 "data/maps/MtChimney/scripts.pory"
	walk_up
# 175 "data/maps/MtChimney/scripts.pory"
	walk_right
# 176 "data/maps/MtChimney/scripts.pory"
	step_end
# 177 "data/maps/MtChimney/scripts.pory"

# 178 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitEast:
# 179 "data/maps/MtChimney/scripts.pory"
	walk_left
# 180 "data/maps/MtChimney/scripts.pory"
	walk_down
# 181 "data/maps/MtChimney/scripts.pory"
	walk_down
# 182 "data/maps/MtChimney/scripts.pory"
	walk_down
# 183 "data/maps/MtChimney/scripts.pory"
	walk_down
# 184 "data/maps/MtChimney/scripts.pory"
	walk_down
# 185 "data/maps/MtChimney/scripts.pory"
	walk_down
# 186 "data/maps/MtChimney/scripts.pory"
	walk_down
# 187 "data/maps/MtChimney/scripts.pory"
	step_end
# 188 "data/maps/MtChimney/scripts.pory"

# 189 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerNorth:
# 190 "data/maps/MtChimney/scripts.pory"
	walk_up
# 191 "data/maps/MtChimney/scripts.pory"
	walk_up
# 192 "data/maps/MtChimney/scripts.pory"
	walk_up
# 193 "data/maps/MtChimney/scripts.pory"
	walk_up
# 194 "data/maps/MtChimney/scripts.pory"
	walk_up
# 195 "data/maps/MtChimney/scripts.pory"
	walk_right
# 196 "data/maps/MtChimney/scripts.pory"
	walk_right
# 197 "data/maps/MtChimney/scripts.pory"
	step_end
# 198 "data/maps/MtChimney/scripts.pory"

# 199 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitNorth:
# 200 "data/maps/MtChimney/scripts.pory"
	walk_left
# 201 "data/maps/MtChimney/scripts.pory"
	walk_left
# 202 "data/maps/MtChimney/scripts.pory"
	walk_down
# 203 "data/maps/MtChimney/scripts.pory"
	walk_down
# 204 "data/maps/MtChimney/scripts.pory"
	walk_down
# 205 "data/maps/MtChimney/scripts.pory"
	walk_down
# 206 "data/maps/MtChimney/scripts.pory"
	walk_down
# 207 "data/maps/MtChimney/scripts.pory"
	walk_down
# 208 "data/maps/MtChimney/scripts.pory"
	walk_down
# 209 "data/maps/MtChimney/scripts.pory"
	step_end
# 210 "data/maps/MtChimney/scripts.pory"

# 211 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused1:
# 212 "data/maps/MtChimney/scripts.pory"
	walk_down
# 213 "data/maps/MtChimney/scripts.pory"
	walk_down
# 214 "data/maps/MtChimney/scripts.pory"
	walk_down
# 215 "data/maps/MtChimney/scripts.pory"
	walk_down
# 216 "data/maps/MtChimney/scripts.pory"
	walk_down
# 217 "data/maps/MtChimney/scripts.pory"
	walk_left
# 218 "data/maps/MtChimney/scripts.pory"
	walk_left
# 219 "data/maps/MtChimney/scripts.pory"
	walk_down
# 220 "data/maps/MtChimney/scripts.pory"
	walk_down
# 221 "data/maps/MtChimney/scripts.pory"
	walk_down
# 222 "data/maps/MtChimney/scripts.pory"
	walk_down
# 223 "data/maps/MtChimney/scripts.pory"
	walk_left
# 224 "data/maps/MtChimney/scripts.pory"
	walk_left
# 225 "data/maps/MtChimney/scripts.pory"
	walk_left
# 226 "data/maps/MtChimney/scripts.pory"
	walk_left
# 227 "data/maps/MtChimney/scripts.pory"
	walk_left
# 228 "data/maps/MtChimney/scripts.pory"
	walk_down
# 229 "data/maps/MtChimney/scripts.pory"
	step_end
# 230 "data/maps/MtChimney/scripts.pory"

# 231 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused2:
# 232 "data/maps/MtChimney/scripts.pory"
	walk_down
# 233 "data/maps/MtChimney/scripts.pory"
	walk_down
# 234 "data/maps/MtChimney/scripts.pory"
	walk_down
# 235 "data/maps/MtChimney/scripts.pory"
	walk_down
# 236 "data/maps/MtChimney/scripts.pory"
	walk_left
# 237 "data/maps/MtChimney/scripts.pory"
	walk_left
# 238 "data/maps/MtChimney/scripts.pory"
	walk_left
# 239 "data/maps/MtChimney/scripts.pory"
	walk_down
# 240 "data/maps/MtChimney/scripts.pory"
	step_end
# 241 "data/maps/MtChimney/scripts.pory"

# 242 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused3:
# 243 "data/maps/MtChimney/scripts.pory"
	walk_right
# 244 "data/maps/MtChimney/scripts.pory"
	walk_down
# 245 "data/maps/MtChimney/scripts.pory"
	walk_down
# 246 "data/maps/MtChimney/scripts.pory"
	walk_down
# 247 "data/maps/MtChimney/scripts.pory"
	walk_down
# 248 "data/maps/MtChimney/scripts.pory"
	walk_left
# 249 "data/maps/MtChimney/scripts.pory"
	walk_left
# 250 "data/maps/MtChimney/scripts.pory"
	walk_left
# 251 "data/maps/MtChimney/scripts.pory"
	walk_left
# 252 "data/maps/MtChimney/scripts.pory"
	walk_left
# 253 "data/maps/MtChimney/scripts.pory"
	walk_down
# 254 "data/maps/MtChimney/scripts.pory"
	walk_down
# 255 "data/maps/MtChimney/scripts.pory"
	walk_down
# 256 "data/maps/MtChimney/scripts.pory"
	walk_down
# 257 "data/maps/MtChimney/scripts.pory"
	step_end
# 258 "data/maps/MtChimney/scripts.pory"

# 259 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused4:
# 260 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 261 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 262 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 263 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 264 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 265 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 266 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 267 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 268 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 269 "data/maps/MtChimney/scripts.pory"
	walk_left
# 270 "data/maps/MtChimney/scripts.pory"
	walk_left
# 271 "data/maps/MtChimney/scripts.pory"
	walk_down
# 272 "data/maps/MtChimney/scripts.pory"
	walk_down
# 273 "data/maps/MtChimney/scripts.pory"
	walk_down
# 274 "data/maps/MtChimney/scripts.pory"
	walk_left
# 275 "data/maps/MtChimney/scripts.pory"
	walk_left
# 276 "data/maps/MtChimney/scripts.pory"
	walk_down
# 277 "data/maps/MtChimney/scripts.pory"
	walk_down
# 278 "data/maps/MtChimney/scripts.pory"
	walk_left
# 279 "data/maps/MtChimney/scripts.pory"
	walk_left
# 280 "data/maps/MtChimney/scripts.pory"
	walk_left
# 281 "data/maps/MtChimney/scripts.pory"
	walk_left
# 282 "data/maps/MtChimney/scripts.pory"
	walk_left
# 283 "data/maps/MtChimney/scripts.pory"
	walk_down
# 284 "data/maps/MtChimney/scripts.pory"
	step_end
# 285 "data/maps/MtChimney/scripts.pory"

# 286 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused5:
# 287 "data/maps/MtChimney/scripts.pory"
	delay_16
# 288 "data/maps/MtChimney/scripts.pory"
	delay_16
# 289 "data/maps/MtChimney/scripts.pory"
	delay_16
# 290 "data/maps/MtChimney/scripts.pory"
	walk_down
# 291 "data/maps/MtChimney/scripts.pory"
	walk_down
# 292 "data/maps/MtChimney/scripts.pory"
	walk_down
# 293 "data/maps/MtChimney/scripts.pory"
	walk_left
# 294 "data/maps/MtChimney/scripts.pory"
	walk_left
# 295 "data/maps/MtChimney/scripts.pory"
	walk_left
# 296 "data/maps/MtChimney/scripts.pory"
	walk_down
# 297 "data/maps/MtChimney/scripts.pory"
	step_end
# 298 "data/maps/MtChimney/scripts.pory"

# 299 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused6:
# 300 "data/maps/MtChimney/scripts.pory"
	delay_16
# 301 "data/maps/MtChimney/scripts.pory"
	walk_left
# 302 "data/maps/MtChimney/scripts.pory"
	walk_down
# 303 "data/maps/MtChimney/scripts.pory"
	walk_down
# 304 "data/maps/MtChimney/scripts.pory"
	walk_down
# 305 "data/maps/MtChimney/scripts.pory"
	walk_down
# 306 "data/maps/MtChimney/scripts.pory"
	walk_left
# 307 "data/maps/MtChimney/scripts.pory"
	walk_left
# 308 "data/maps/MtChimney/scripts.pory"
	walk_left
# 309 "data/maps/MtChimney/scripts.pory"
	walk_left
# 310 "data/maps/MtChimney/scripts.pory"
	walk_left
# 311 "data/maps/MtChimney/scripts.pory"
	walk_down
# 312 "data/maps/MtChimney/scripts.pory"
	walk_down
# 313 "data/maps/MtChimney/scripts.pory"
	walk_down
# 314 "data/maps/MtChimney/scripts.pory"
	walk_down
# 315 "data/maps/MtChimney/scripts.pory"
	step_end
# 316 "data/maps/MtChimney/scripts.pory"

# 317 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused7:
# 318 "data/maps/MtChimney/scripts.pory"
	delay_16
# 319 "data/maps/MtChimney/scripts.pory"
	walk_left
# 320 "data/maps/MtChimney/scripts.pory"
	walk_left
# 321 "data/maps/MtChimney/scripts.pory"
	walk_down
# 322 "data/maps/MtChimney/scripts.pory"
	walk_down
# 323 "data/maps/MtChimney/scripts.pory"
	walk_down
# 324 "data/maps/MtChimney/scripts.pory"
	walk_left
# 325 "data/maps/MtChimney/scripts.pory"
	walk_left
# 326 "data/maps/MtChimney/scripts.pory"
	walk_down
# 327 "data/maps/MtChimney/scripts.pory"
	walk_down
# 328 "data/maps/MtChimney/scripts.pory"
	walk_left
# 329 "data/maps/MtChimney/scripts.pory"
	walk_left
# 330 "data/maps/MtChimney/scripts.pory"
	walk_left
# 331 "data/maps/MtChimney/scripts.pory"
	walk_left
# 332 "data/maps/MtChimney/scripts.pory"
	walk_left
# 333 "data/maps/MtChimney/scripts.pory"
	walk_down
# 334 "data/maps/MtChimney/scripts.pory"
	step_end
# 335 "data/maps/MtChimney/scripts.pory"

# 336 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused8:
# 337 "data/maps/MtChimney/scripts.pory"
	delay_16
# 338 "data/maps/MtChimney/scripts.pory"
	walk_down
# 339 "data/maps/MtChimney/scripts.pory"
	walk_left
# 340 "data/maps/MtChimney/scripts.pory"
	walk_left
# 341 "data/maps/MtChimney/scripts.pory"
	walk_left
# 342 "data/maps/MtChimney/scripts.pory"
	walk_left
# 343 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_down
# 344 "data/maps/MtChimney/scripts.pory"
	step_end
# 345 "data/maps/MtChimney/scripts.pory"

# 346 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused9:
# 347 "data/maps/MtChimney/scripts.pory"
	walk_down
# 348 "data/maps/MtChimney/scripts.pory"
	walk_down
# 349 "data/maps/MtChimney/scripts.pory"
	walk_down
# 350 "data/maps/MtChimney/scripts.pory"
	walk_down
# 351 "data/maps/MtChimney/scripts.pory"
	walk_left
# 352 "data/maps/MtChimney/scripts.pory"
	walk_left
# 353 "data/maps/MtChimney/scripts.pory"
	walk_left
# 354 "data/maps/MtChimney/scripts.pory"
	walk_left
# 355 "data/maps/MtChimney/scripts.pory"
	walk_left
# 356 "data/maps/MtChimney/scripts.pory"
	walk_down
# 357 "data/maps/MtChimney/scripts.pory"
	walk_down
# 358 "data/maps/MtChimney/scripts.pory"
	walk_down
# 359 "data/maps/MtChimney/scripts.pory"
	walk_down
# 360 "data/maps/MtChimney/scripts.pory"
	step_end
# 361 "data/maps/MtChimney/scripts.pory"

# 362 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused10:
# 363 "data/maps/MtChimney/scripts.pory"
	walk_down
# 364 "data/maps/MtChimney/scripts.pory"
	step_end
# 365 "data/maps/MtChimney/scripts.pory"

# 366 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused11:
# 367 "data/maps/MtChimney/scripts.pory"
	walk_down
# 368 "data/maps/MtChimney/scripts.pory"
	walk_down
# 369 "data/maps/MtChimney/scripts.pory"
	walk_down
# 370 "data/maps/MtChimney/scripts.pory"
	walk_down
# 371 "data/maps/MtChimney/scripts.pory"
	walk_down
# 372 "data/maps/MtChimney/scripts.pory"
	walk_down
# 373 "data/maps/MtChimney/scripts.pory"
	walk_down
# 374 "data/maps/MtChimney/scripts.pory"
	step_end
# 375 "data/maps/MtChimney/scripts.pory"

# 376 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused12:
# 377 "data/maps/MtChimney/scripts.pory"
	delay_16
# 378 "data/maps/MtChimney/scripts.pory"
	delay_16
# 379 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 380 "data/maps/MtChimney/scripts.pory"
	delay_16
# 381 "data/maps/MtChimney/scripts.pory"
	walk_down
# 382 "data/maps/MtChimney/scripts.pory"
	walk_down
# 383 "data/maps/MtChimney/scripts.pory"
	walk_down
# 384 "data/maps/MtChimney/scripts.pory"
	walk_down
# 385 "data/maps/MtChimney/scripts.pory"
	walk_down
# 386 "data/maps/MtChimney/scripts.pory"
	step_end
# 387 "data/maps/MtChimney/scripts.pory"

# 388 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused13:
# 389 "data/maps/MtChimney/scripts.pory"
	delay_16
# 390 "data/maps/MtChimney/scripts.pory"
	delay_16
# 391 "data/maps/MtChimney/scripts.pory"
	delay_16
# 392 "data/maps/MtChimney/scripts.pory"
	delay_16
# 393 "data/maps/MtChimney/scripts.pory"
	delay_16
# 394 "data/maps/MtChimney/scripts.pory"
	delay_16
# 395 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 396 "data/maps/MtChimney/scripts.pory"
	delay_16
# 397 "data/maps/MtChimney/scripts.pory"
	walk_down
# 398 "data/maps/MtChimney/scripts.pory"
	walk_down
# 399 "data/maps/MtChimney/scripts.pory"
	step_end
# 400 "data/maps/MtChimney/scripts.pory"

# 401 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused14:
# 402 "data/maps/MtChimney/scripts.pory"
	lock_facing_direction
# 403 "data/maps/MtChimney/scripts.pory"
	walk_fast_left
# 404 "data/maps/MtChimney/scripts.pory"
	unlock_facing_direction
# 405 "data/maps/MtChimney/scripts.pory"
	face_right
# 406 "data/maps/MtChimney/scripts.pory"
	step_end
# 407 "data/maps/MtChimney/scripts.pory"

# 408 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused15:
# 409 "data/maps/MtChimney/scripts.pory"
	walk_left
# 410 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_right
# 411 "data/maps/MtChimney/scripts.pory"
	delay_16
# 412 "data/maps/MtChimney/scripts.pory"
	step_end
# 413 "data/maps/MtChimney/scripts.pory"

# 414 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt1::
# 415 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
# 416 "data/maps/MtChimney/scripts.pory"
	end
# 417 "data/maps/MtChimney/scripts.pory"

# 418 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt2::
# 419 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
# 420 "data/maps/MtChimney/scripts.pory"
	end
# 421 "data/maps/MtChimney/scripts.pory"

# 422 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt3::
# 423 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
# 424 "data/maps/MtChimney/scripts.pory"
	end
# 425 "data/maps/MtChimney/scripts.pory"

# 426 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Tabitha::
# 427 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
# 428 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 429 "data/maps/MtChimney/scripts.pory"
	end
# 430 "data/maps/MtChimney/scripts.pory"

# 431 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt2::
# 432 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
# 433 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 434 "data/maps/MtChimney/scripts.pory"
	end
# 435 "data/maps/MtChimney/scripts.pory"

# 436 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt1::
# 437 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
# 438 "data/maps/MtChimney/scripts.pory"
	end
# 439 "data/maps/MtChimney/scripts.pory"

# 440 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt2::
# 441 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
# 442 "data/maps/MtChimney/scripts.pory"
	end
# 443 "data/maps/MtChimney/scripts.pory"

# 444 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt3::
# 445 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
# 446 "data/maps/MtChimney/scripts.pory"
	end
# 447 "data/maps/MtChimney/scripts.pory"

# 448 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt4::
# 449 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
# 450 "data/maps/MtChimney/scripts.pory"
	end
# 451 "data/maps/MtChimney/scripts.pory"

# 452 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt5::
# 453 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
# 454 "data/maps/MtChimney/scripts.pory"
	end
# 455 "data/maps/MtChimney/scripts.pory"

# 456 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt6::
# 457 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
# 458 "data/maps/MtChimney/scripts.pory"
	end
# 459 "data/maps/MtChimney/scripts.pory"

# 460 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MagmaPoochyena::
# 461 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
# 462 "data/maps/MtChimney/scripts.pory"
	end
# 463 "data/maps/MtChimney/scripts.pory"

# 464 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_AquaPoochyena::
# 465 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
# 466 "data/maps/MtChimney/scripts.pory"
	end
# 467 "data/maps/MtChimney/scripts.pory"

# 468 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MeteoriteMachine::
# 469 "data/maps/MtChimney/scripts.pory"
	lockall
# 470 "data/maps/MtChimney/scripts.pory"
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
# 471 "data/maps/MtChimney/scripts.pory"
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
# 472 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
# 473 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
# 474 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
# 475 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_METEORITE
# 476 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 477 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_RECEIVED_METEORITE
# 478 "data/maps/MtChimney/scripts.pory"
	releaseall
# 479 "data/maps/MtChimney/scripts.pory"
	end
# 480 "data/maps/MtChimney/scripts.pory"

# 481 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_LeaveMeteoriteAlone::
# 482 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
# 483 "data/maps/MtChimney/scripts.pory"
	releaseall
# 484 "data/maps/MtChimney/scripts.pory"
	end
# 485 "data/maps/MtChimney/scripts.pory"

# 486 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOff::
# 487 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
# 488 "data/maps/MtChimney/scripts.pory"
	releaseall
# 489 "data/maps/MtChimney/scripts.pory"
	end
# 490 "data/maps/MtChimney/scripts.pory"

# 491 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOn::
# 492 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoriteFittedOnMachine, MSGBOX_DEFAULT
# 493 "data/maps/MtChimney/scripts.pory"
	releaseall
# 494 "data/maps/MtChimney/scripts.pory"
	end
# 495 "data/maps/MtChimney/scripts.pory"

# 496 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RouteSign::
# 497 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
# 498 "data/maps/MtChimney/scripts.pory"
	end
# 499 "data/maps/MtChimney/scripts.pory"

# 500 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shelby::
# 501 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
# 502 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 503 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
# 504 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
# 505 "data/maps/MtChimney/scripts.pory"
	release
# 506 "data/maps/MtChimney/scripts.pory"
	end
# 507 "data/maps/MtChimney/scripts.pory"

# 508 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_DefeatedShelby::
# 509 "data/maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 510 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 511 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
# 512 "data/maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SHELBY_1
# 513 "data/maps/MtChimney/scripts.pory"
	release
# 514 "data/maps/MtChimney/scripts.pory"
	end
# 515 "data/maps/MtChimney/scripts.pory"

# 516 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RematchShelby::
# 517 "data/maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
# 518 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
# 519 "data/maps/MtChimney/scripts.pory"
	end
# 520 "data/maps/MtChimney/scripts.pory"

# 521 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Melissa::
# 522 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
# 523 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
# 524 "data/maps/MtChimney/scripts.pory"
	end
# 525 "data/maps/MtChimney/scripts.pory"

# 526 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sheila::
# 527 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
# 528 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
# 529 "data/maps/MtChimney/scripts.pory"
	end
# 530 "data/maps/MtChimney/scripts.pory"

# 531 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shirley::
# 532 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
# 533 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
# 534 "data/maps/MtChimney/scripts.pory"
	end
# 535 "data/maps/MtChimney/scripts.pory"

# 536 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt1::
# 537 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
# 538 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 539 "data/maps/MtChimney/scripts.pory"
	end
# 540 "data/maps/MtChimney/scripts.pory"

# 541 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sawyer::
# 542 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
# 543 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 544 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
# 545 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
# 546 "data/maps/MtChimney/scripts.pory"
	release
# 547 "data/maps/MtChimney/scripts.pory"
	end
# 548 "data/maps/MtChimney/scripts.pory"

# 549 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerDefeated::
# 550 "data/maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 551 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 552 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
# 553 "data/maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SAWYER_1
# 554 "data/maps/MtChimney/scripts.pory"
	release
# 555 "data/maps/MtChimney/scripts.pory"
	end
# 556 "data/maps/MtChimney/scripts.pory"

# 557 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerRematch::
# 558 "data/maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
# 559 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
# 560 "data/maps/MtChimney/scripts.pory"
	end
# 561 "data/maps/MtChimney/scripts.pory"

# 562 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoriteWillActivateVolcano:
# 563 "data/maps/MtChimney/scripts.pory"
	.string "The power contained in the Meteorite…\p"
# 564 "data/maps/MtChimney/scripts.pory"
	.string "By amplifying its power with this\n"
# 565 "data/maps/MtChimney/scripts.pory"
	.string "machine, Mt. Chimney's volcanic\l"
# 566 "data/maps/MtChimney/scripts.pory"
	.string "activity will instantly intensify…\p"
# 567 "data/maps/MtChimney/scripts.pory"
	.string "Its energy will grow deep inside\n"
# 568 "data/maps/MtChimney/scripts.pory"
	.string "the crater and…\l"
# 569 "data/maps/MtChimney/scripts.pory"
	.string "Fufufu…$"
# 570 "data/maps/MtChimney/scripts.pory"

# 571 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieIntro:
# 572 "data/maps/MtChimney/scripts.pory"
	.string "Maxie: Hm?\n"
# 573 "data/maps/MtChimney/scripts.pory"
	.string "Who are you?\p"
# 574 "data/maps/MtChimney/scripts.pory"
	.string "… … … … … …\n"
# 575 "data/maps/MtChimney/scripts.pory"
	.string "… … … … … …\p"
# 576 "data/maps/MtChimney/scripts.pory"
	.string "I'd heard Archie bemoaning a child\n"
# 577 "data/maps/MtChimney/scripts.pory"
	.string "who's been meddling in Team Aqua's\l"
# 578 "data/maps/MtChimney/scripts.pory"
	.string "affairs.\p"
# 579 "data/maps/MtChimney/scripts.pory"
	.string "It must be you he meant.\p"
# 580 "data/maps/MtChimney/scripts.pory"
	.string "Humph! So you're thinking of\n"
# 581 "data/maps/MtChimney/scripts.pory"
	.string "interfering with us, Team Magma?\p"
# 582 "data/maps/MtChimney/scripts.pory"
	.string "Now you listen.\n"
# 583 "data/maps/MtChimney/scripts.pory"
	.string "Long ago, living things used the\l"
# 584 "data/maps/MtChimney/scripts.pory"
	.string "land to live and grow.\p"
# 585 "data/maps/MtChimney/scripts.pory"
	.string "That is why land is all important!\n"
# 586 "data/maps/MtChimney/scripts.pory"
	.string "It is the cradle of all!\p"
# 587 "data/maps/MtChimney/scripts.pory"
	.string "That is why Team Magma is dedicated\n"
# 588 "data/maps/MtChimney/scripts.pory"
	.string "to the expansion of the land mass.\p"
# 589 "data/maps/MtChimney/scripts.pory"
	.string "It is for further advancement of\n"
# 590 "data/maps/MtChimney/scripts.pory"
	.string "humankind and Pokémon!\p"
# 591 "data/maps/MtChimney/scripts.pory"
	.string "And for that, we need the power of\n"
# 592 "data/maps/MtChimney/scripts.pory"
	.string "what sleeps within this mountain…\p"
# 593 "data/maps/MtChimney/scripts.pory"
	.string "Oh! There was no need for you to\n"
# 594 "data/maps/MtChimney/scripts.pory"
	.string "learn that much.\p"
# 595 "data/maps/MtChimney/scripts.pory"
	.string "But, no matter!\n"
# 596 "data/maps/MtChimney/scripts.pory"
	.string "I'll teach you the consequences of\l"
# 597 "data/maps/MtChimney/scripts.pory"
	.string "meddling in our grand design!$"
# 598 "data/maps/MtChimney/scripts.pory"

# 599 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieDefeat:
# 600 "data/maps/MtChimney/scripts.pory"
	.string "What?!\p"
# 601 "data/maps/MtChimney/scripts.pory"
	.string "I, Maxie, was caught off guard?!$"
# 602 "data/maps/MtChimney/scripts.pory"

# 603 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
# 604 "data/maps/MtChimney/scripts.pory"
	.string "Maxie: But, enough.\n"
# 605 "data/maps/MtChimney/scripts.pory"
	.string "I will back off this time.\p"
# 606 "data/maps/MtChimney/scripts.pory"
	.string "But don't think that this is the last\n"
# 607 "data/maps/MtChimney/scripts.pory"
	.string "you've seen of Team Magma.\p"
# 608 "data/maps/MtChimney/scripts.pory"
	.string "Fufufu…\p"
# 609 "data/maps/MtChimney/scripts.pory"
	.string "Even without the Meteorite, if we\n"
# 610 "data/maps/MtChimney/scripts.pory"
	.string "obtain that Orb… Fufufu…$"
# 611 "data/maps/MtChimney/scripts.pory"

# 612 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaIntro:
# 613 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe!\p"
# 614 "data/maps/MtChimney/scripts.pory"
	.string "So you've come all the way here!\p"
# 615 "data/maps/MtChimney/scripts.pory"
	.string "But you're too late!\n"
# 616 "data/maps/MtChimney/scripts.pory"
	.string "I've already delivered the Meteorite\l"
# 617 "data/maps/MtChimney/scripts.pory"
	.string "from Meteor Falls to the boss!$"
# 618 "data/maps/MtChimney/scripts.pory"

# 619 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaDefeat:
# 620 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe…\p"
# 621 "data/maps/MtChimney/scripts.pory"
	.string "Even though I've lost, if our leader\n"
# 622 "data/maps/MtChimney/scripts.pory"
	.string "awakens that thing…$"
# 623 "data/maps/MtChimney/scripts.pory"

# 624 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaPostBattle:
# 625 "data/maps/MtChimney/scripts.pory"
	.string "Boss, hurry!\n"
# 626 "data/maps/MtChimney/scripts.pory"
	.string "Give it the Meteorite's energy!\p"
# 627 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe…$"
# 628 "data/maps/MtChimney/scripts.pory"

# 629 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Intro:
# 630 "data/maps/MtChimney/scripts.pory"
	.string "We of Team Magma are working hard for\n"
# 631 "data/maps/MtChimney/scripts.pory"
	.string "everyone's sake.\p"
# 632 "data/maps/MtChimney/scripts.pory"
	.string "Like, if that thing's power made more\n"
# 633 "data/maps/MtChimney/scripts.pory"
	.string "land, there'd be more places to live.\p"
# 634 "data/maps/MtChimney/scripts.pory"
	.string "Everyone'd be happy!$"
# 635 "data/maps/MtChimney/scripts.pory"

# 636 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Defeat:
# 637 "data/maps/MtChimney/scripts.pory"
	.string "Hunh?\n"
# 638 "data/maps/MtChimney/scripts.pory"
	.string "What do you mean I lost?$"
# 639 "data/maps/MtChimney/scripts.pory"

# 640 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2PostBattle:
# 641 "data/maps/MtChimney/scripts.pory"
	.string "Our boss says, “It will make everyone\n"
# 642 "data/maps/MtChimney/scripts.pory"
	.string "happy.”\p"
# 643 "data/maps/MtChimney/scripts.pory"
	.string "But why does everyone keep getting\n"
# 644 "data/maps/MtChimney/scripts.pory"
	.string "in our way?$"
# 645 "data/maps/MtChimney/scripts.pory"

# 646 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Intro:
# 647 "data/maps/MtChimney/scripts.pory"
	.string "If there were more land, I'd be able\n"
# 648 "data/maps/MtChimney/scripts.pory"
	.string "to get a big house of my own!\p"
# 649 "data/maps/MtChimney/scripts.pory"
	.string "I'm going to build it on hardened lava!$"
# 650 "data/maps/MtChimney/scripts.pory"

# 651 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Defeat:
# 652 "data/maps/MtChimney/scripts.pory"
	.string "My dream of a big house…$"
# 653 "data/maps/MtChimney/scripts.pory"

# 654 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1PostBattle:
# 655 "data/maps/MtChimney/scripts.pory"
	.string "A kid like you, you ought to be\n"
# 656 "data/maps/MtChimney/scripts.pory"
	.string "splashing about in the waves!$"
# 657 "data/maps/MtChimney/scripts.pory"

# 658 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
# 659 "data/maps/MtChimney/scripts.pory"
	.string "That annoying Team Aqua…\n"
# 660 "data/maps/MtChimney/scripts.pory"
	.string "They always mess with our plans!$"
# 661 "data/maps/MtChimney/scripts.pory"

# 662 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoritesPackAmazingPower:
# 663 "data/maps/MtChimney/scripts.pory"
	.string "Meteorites pack amazing power!$"
# 664 "data/maps/MtChimney/scripts.pory"

# 665 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_YouBetterNotMessWithUs:
# 666 "data/maps/MtChimney/scripts.pory"
	.string "You'd better not mess with us!\p"
# 667 "data/maps/MtChimney/scripts.pory"
	.string "We're trying to awaken that thing\n"
# 668 "data/maps/MtChimney/scripts.pory"
	.string "for the benefit of everyone!$"
# 669 "data/maps/MtChimney/scripts.pory"

# 670 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_AquasNameSimilar:
# 671 "data/maps/MtChimney/scripts.pory"
	.string "We're Team Magma!\p"
# 672 "data/maps/MtChimney/scripts.pory"
	.string "They're Team Aqua!\p"
# 673 "data/maps/MtChimney/scripts.pory"
	.string "It totally annoys me that they'd\n"
# 674 "data/maps/MtChimney/scripts.pory"
	.string "use a name like ours!$"
# 675 "data/maps/MtChimney/scripts.pory"

# 676 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_DouseThemInFire:
# 677 "data/maps/MtChimney/scripts.pory"
	.string "Yeah!\n"
# 678 "data/maps/MtChimney/scripts.pory"
	.string "Douse them in fire!$"
# 679 "data/maps/MtChimney/scripts.pory"

# 680 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_KeepMakingMoreLand:
# 681 "data/maps/MtChimney/scripts.pory"
	.string "We're going to keep making more land!$"
# 682 "data/maps/MtChimney/scripts.pory"

# 683 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Bufoh:
# 684 "data/maps/MtChimney/scripts.pory"
	.string "Bufoh!$"
# 685 "data/maps/MtChimney/scripts.pory"

# 686 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieGoStopTeamMagma:
# 687 "data/maps/MtChimney/scripts.pory"
	.string "Archie: Grr, {PLAYER}!\n"
# 688 "data/maps/MtChimney/scripts.pory"
	.string "I should've guessed you'd show up!\p"
# 689 "data/maps/MtChimney/scripts.pory"
	.string "See for yourself what the fanatics\n"
# 690 "data/maps/MtChimney/scripts.pory"
	.string "of Team Magma are up to!\p"
# 691 "data/maps/MtChimney/scripts.pory"
	.string "They're trying to inject the stolen\n"
# 692 "data/maps/MtChimney/scripts.pory"
	.string "Meteorite's power into the volcano!\p"
# 693 "data/maps/MtChimney/scripts.pory"
	.string "Doing something like that will cause\n"
# 694 "data/maps/MtChimney/scripts.pory"
	.string "the volcano's eruption!$"
# 695 "data/maps/MtChimney/scripts.pory"

# 696 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieIHaveMyHandsFull:
# 697 "data/maps/MtChimney/scripts.pory"
	.string "Archie: Grrr…\p"
# 698 "data/maps/MtChimney/scripts.pory"
	.string "I want to stop that Maxie,\n"
# 699 "data/maps/MtChimney/scripts.pory"
	.string "but I can't!\p"
# 700 "data/maps/MtChimney/scripts.pory"
	.string "Not when I have my hands full battling\n"
# 701 "data/maps/MtChimney/scripts.pory"
	.string "three opponents at once!$"
# 702 "data/maps/MtChimney/scripts.pory"

# 703 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieThankYou:
# 704 "data/maps/MtChimney/scripts.pory"
	.string "Archie: {PLAYER}!\n"
# 705 "data/maps/MtChimney/scripts.pory"
	.string "Thank you!\p"
# 706 "data/maps/MtChimney/scripts.pory"
	.string "With your help, we thwarted Team\n"
# 707 "data/maps/MtChimney/scripts.pory"
	.string "Magma's destructive plan!\p"
# 708 "data/maps/MtChimney/scripts.pory"
	.string "But… You…\n"
# 709 "data/maps/MtChimney/scripts.pory"
	.string "Whose side are you on?\p"
# 710 "data/maps/MtChimney/scripts.pory"
	.string "Ah, it doesn't matter.\p"
# 711 "data/maps/MtChimney/scripts.pory"
	.string "We will remain vigilant and keep up\n"
# 712 "data/maps/MtChimney/scripts.pory"
	.string "our pursuit of Team Magma.\p"
# 713 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER}, we shall meet again!$"
# 714 "data/maps/MtChimney/scripts.pory"

# 715 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MagmaOutnumbersUs:
# 716 "data/maps/MtChimney/scripts.pory"
	.string "Darn… Team Magma outnumbers us!\n"
# 717 "data/maps/MtChimney/scripts.pory"
	.string "We can't keep up with them!$"
# 718 "data/maps/MtChimney/scripts.pory"

# 719 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_LessHabitatForWaterPokemon:
# 720 "data/maps/MtChimney/scripts.pory"
	.string "If they expand the land, there'll be\n"
# 721 "data/maps/MtChimney/scripts.pory"
	.string "less habitats for Water Pokémon!$"
# 722 "data/maps/MtChimney/scripts.pory"

# 723 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MagmasNameSimilar:
# 724 "data/maps/MtChimney/scripts.pory"
	.string "We're Team Aqua!\p"
# 725 "data/maps/MtChimney/scripts.pory"
	.string "They're Team Magma!\p"
# 726 "data/maps/MtChimney/scripts.pory"
	.string "It burns me up that they'd use such\n"
# 727 "data/maps/MtChimney/scripts.pory"
	.string "a confusing name!$"
# 728 "data/maps/MtChimney/scripts.pory"

# 729 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Bushaa:
# 730 "data/maps/MtChimney/scripts.pory"
	.string "Bushaa!$"
# 731 "data/maps/MtChimney/scripts.pory"

# 732 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_LavaCookiesJust200:
# 733 "data/maps/MtChimney/scripts.pory"
	.string "Lava Cookies are Mt. Chimney's local\n"
# 734 "data/maps/MtChimney/scripts.pory"
	.string "specialty.\p"
# 735 "data/maps/MtChimney/scripts.pory"
	.string "Try one. It's just ¥200.$"
# 736 "data/maps/MtChimney/scripts.pory"

# 737 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ThankYouDear:
# 738 "data/maps/MtChimney/scripts.pory"
	.string "Thank you, dear!$"
# 739 "data/maps/MtChimney/scripts.pory"

# 740 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_YouveNotGotTheMoney:
# 741 "data/maps/MtChimney/scripts.pory"
	.string "Oh, dear. You can't buy a thing if\n"
# 742 "data/maps/MtChimney/scripts.pory"
	.string "you've not got the money.$"
# 743 "data/maps/MtChimney/scripts.pory"

# 744 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_OhFineThen:
# 745 "data/maps/MtChimney/scripts.pory"
	.string "Oh, fine then.$"
# 746 "data/maps/MtChimney/scripts.pory"

# 747 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoriteFittedOnMachine:
# 748 "data/maps/MtChimney/scripts.pory"
	.string "A Meteorite is fitted on a mysterious\n"
# 749 "data/maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 750 "data/maps/MtChimney/scripts.pory"
	.string "The machine seems to be storing\n"
# 751 "data/maps/MtChimney/scripts.pory"
	.string "energy in the Meteorite.$"
# 752 "data/maps/MtChimney/scripts.pory"

# 753 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_RemoveTheMeteorite:
# 754 "data/maps/MtChimney/scripts.pory"
	.string "A Meteorite is fitted on a mysterious\n"
# 755 "data/maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 756 "data/maps/MtChimney/scripts.pory"
	.string "Do you want to remove the Meteorite?$"
# 757 "data/maps/MtChimney/scripts.pory"

# 758 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerRemovedMeteorite:
# 759 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER} removed the Meteorite from\n"
# 760 "data/maps/MtChimney/scripts.pory"
	.string "the mysterious machine.$"
# 761 "data/maps/MtChimney/scripts.pory"

# 762 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerLeftMeteorite:
# 763 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER} left the Meteorite where\n"
# 764 "data/maps/MtChimney/scripts.pory"
	.string "it was.$"
# 765 "data/maps/MtChimney/scripts.pory"

# 766 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MachineMakesNoResponse:
# 767 "data/maps/MtChimney/scripts.pory"
	.string "This mysterious machine…\n"
# 768 "data/maps/MtChimney/scripts.pory"
	.string "It makes no response whatsoever.$"
# 769 "data/maps/MtChimney/scripts.pory"

# 770 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_RouteSign:
# 771 "data/maps/MtChimney/scripts.pory"
	.string "{DOWN_ARROW} Jagged Pass\n"
# 772 "data/maps/MtChimney/scripts.pory"
	.string "Lavaridge Town Ahead$"
# 773 "data/maps/MtChimney/scripts.pory"

# 774 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyIntro:
# 775 "data/maps/MtChimney/scripts.pory"
	.string "I've been to the hot springs and\n"
# 776 "data/maps/MtChimney/scripts.pory"
	.string "refreshed my tired bones.\l"
# 777 "data/maps/MtChimney/scripts.pory"
	.string "Right now I'm feeling strong!$"
# 778 "data/maps/MtChimney/scripts.pory"

# 779 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyDefeat:
# 780 "data/maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 781 "data/maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 782 "data/maps/MtChimney/scripts.pory"

# 783 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostBattle:
# 784 "data/maps/MtChimney/scripts.pory"
	.string "Well, well, I've lost. I can't call\n"
# 785 "data/maps/MtChimney/scripts.pory"
	.string "myself an expert now, can I?$"
# 786 "data/maps/MtChimney/scripts.pory"

# 787 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRegister:
# 788 "data/maps/MtChimney/scripts.pory"
	.string "Thank you, child. It was fun, as if\n"
# 789 "data/maps/MtChimney/scripts.pory"
	.string "I were battling my own grandchild.\p"
# 790 "data/maps/MtChimney/scripts.pory"
	.string "Please, come see me again for\n"
# 791 "data/maps/MtChimney/scripts.pory"
	.string "a rematch.$"
# 792 "data/maps/MtChimney/scripts.pory"

# 793 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchIntro:
# 794 "data/maps/MtChimney/scripts.pory"
	.string "If you can mesh your heart with those\n"
# 795 "data/maps/MtChimney/scripts.pory"
	.string "of your Pokémon, why, you should be\l"
# 796 "data/maps/MtChimney/scripts.pory"
	.string "able to achieve great things.$"
# 797 "data/maps/MtChimney/scripts.pory"

# 798 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchDefeat:
# 799 "data/maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 800 "data/maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 801 "data/maps/MtChimney/scripts.pory"

# 802 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostRematch:
# 803 "data/maps/MtChimney/scripts.pory"
	.string "Perhaps your heart has become one\n"
# 804 "data/maps/MtChimney/scripts.pory"
	.string "with the hearts of your Pokémon.$"
# 805 "data/maps/MtChimney/scripts.pory"

# 806 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaIntro:
# 807 "data/maps/MtChimney/scripts.pory"
	.string "I've got the fire in me, baby.\n"
# 808 "data/maps/MtChimney/scripts.pory"
	.string "I can't stand it! I have to battle!$"
# 809 "data/maps/MtChimney/scripts.pory"

# 810 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaDefeat:
# 811 "data/maps/MtChimney/scripts.pory"
	.string "Ooh, that was a scorching-hot match!$"
# 812 "data/maps/MtChimney/scripts.pory"

# 813 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaPostBattle:
# 814 "data/maps/MtChimney/scripts.pory"
	.string "The heat of Mt. Chimney warms\n"
# 815 "data/maps/MtChimney/scripts.pory"
	.string "me up, baby!$"
# 816 "data/maps/MtChimney/scripts.pory"

# 817 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaIntro:
# 818 "data/maps/MtChimney/scripts.pory"
	.string "I've finally made it to Mt. Chimney.\n"
# 819 "data/maps/MtChimney/scripts.pory"
	.string "I want to make my Pokémon battle!$"
# 820 "data/maps/MtChimney/scripts.pory"

# 821 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaDefeat:
# 822 "data/maps/MtChimney/scripts.pory"
	.string "The way you battle…\n"
# 823 "data/maps/MtChimney/scripts.pory"
	.string "It's like a Mt. Chimney eruption!$"
# 824 "data/maps/MtChimney/scripts.pory"

# 825 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaPostBattle:
# 826 "data/maps/MtChimney/scripts.pory"
	.string "Like I said, I've finally made it to\n"
# 827 "data/maps/MtChimney/scripts.pory"
	.string "Mt. Chimney. It would be a shame if\l"
# 828 "data/maps/MtChimney/scripts.pory"
	.string "I only do a little sightseeing…\p"
# 829 "data/maps/MtChimney/scripts.pory"
	.string "I want to get in some battles and buy\n"
# 830 "data/maps/MtChimney/scripts.pory"
	.string "Lava Cookies as souvenirs.$"
# 831 "data/maps/MtChimney/scripts.pory"

# 832 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyIntro:
# 833 "data/maps/MtChimney/scripts.pory"
	.string "Since I bathed in the hot springs,\n"
# 834 "data/maps/MtChimney/scripts.pory"
	.string "I've been feeling great!\l"
# 835 "data/maps/MtChimney/scripts.pory"
	.string "I'm sure I'm going to win!$"
# 836 "data/maps/MtChimney/scripts.pory"

# 837 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyDefeat:
# 838 "data/maps/MtChimney/scripts.pory"
	.string "Yowch!\n"
# 839 "data/maps/MtChimney/scripts.pory"
	.string "I'm getting a chill out of the water.$"
# 840 "data/maps/MtChimney/scripts.pory"

# 841 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyPostBattle:
# 842 "data/maps/MtChimney/scripts.pory"
	.string "I'll have to take another dip in the\n"
# 843 "data/maps/MtChimney/scripts.pory"
	.string "hot springs. Want to join me?\p"
# 844 "data/maps/MtChimney/scripts.pory"
	.string "Just joking!$"
# 845 "data/maps/MtChimney/scripts.pory"

# 846 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerIntro:
# 847 "data/maps/MtChimney/scripts.pory"
	.string "This is one fine mountain! Plenty of\n"
# 848 "data/maps/MtChimney/scripts.pory"
	.string "hot people around for company!$"
# 849 "data/maps/MtChimney/scripts.pory"

# 850 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerDefeat:
# 851 "data/maps/MtChimney/scripts.pory"
	.string "Oh, you're a real firebrand, too!$"
# 852 "data/maps/MtChimney/scripts.pory"

# 853 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostBattle:
# 854 "data/maps/MtChimney/scripts.pory"
	.string "I think I need a dip in Lavaridge\n"
# 855 "data/maps/MtChimney/scripts.pory"
	.string "Hot Spring with the locals!$"
# 856 "data/maps/MtChimney/scripts.pory"

# 857 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRegister:
# 858 "data/maps/MtChimney/scripts.pory"
	.string "I like little fireballs like you.\n"
# 859 "data/maps/MtChimney/scripts.pory"
	.string "Let me register you in my PokéNav.$"
# 860 "data/maps/MtChimney/scripts.pory"

# 861 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchIntro:
# 862 "data/maps/MtChimney/scripts.pory"
	.string "I'm happily surrounded by hot people\n"
# 863 "data/maps/MtChimney/scripts.pory"
	.string "around these parts. I won't lose!$"
# 864 "data/maps/MtChimney/scripts.pory"

# 865 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchDefeat:
# 866 "data/maps/MtChimney/scripts.pory"
	.string "Gosh, you're still the same\n"
# 867 "data/maps/MtChimney/scripts.pory"
	.string "firebrand as before!$"
# 868 "data/maps/MtChimney/scripts.pory"

# 869 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostRematch:
# 870 "data/maps/MtChimney/scripts.pory"
	.string "Actually, it really is hot here.\n"
# 871 "data/maps/MtChimney/scripts.pory"
	.string "I'm overdressed for these parts.$"

MtChimney_BattleMoltres::
# 875 "data/maps/MtChimney/scripts.pory"
	lock
# 876 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 877 "data/maps/MtChimney/scripts.pory"
	setvar VAR_TEMP_1, 1
# 878 "data/maps/MtChimney/scripts.pory"
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
# 879 "data/maps/MtChimney/scripts.pory"
	delay 30
# 880 "data/maps/MtChimney/scripts.pory"
	waitmoncry
# 881 "data/maps/MtChimney/scripts.pory"
	seteventmon SPECIES_MOLTRES, 50
# 882 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 883 "data/maps/MtChimney/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 884 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 885 "data/maps/MtChimney/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_MT_CHIMNEY_MOLTRES
# 886 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 887 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MtChimney_EventScript_DefeatedMoltres
# 888 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtChimney_EventScript_RanFromMoltres
# 889 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MtChimney_EventScript_RanFromMoltres
# 890 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_CAUGHT_MOLTRES
# 891 "data/maps/MtChimney/scripts.pory"
	release
	end


MtChimney_EventScript_DefeatedMoltres::
# 896 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_DEFEATED_MOLTRES
# 897 "data/maps/MtChimney/scripts.pory"
	setvar VAR_0x8004, SPECIES_MOLTRES
# 898 "data/maps/MtChimney/scripts.pory"
	call Common_EventScript_LegendaryFlewAway
# 899 "data/maps/MtChimney/scripts.pory"
	release
	end


MtChimney_EventScript_RanFromMoltres::
# 904 "data/maps/MtChimney/scripts.pory"
	setvar VAR_0x8004, SPECIES_MOLTRES
# 905 "data/maps/MtChimney/scripts.pory"
	call Common_EventScript_LegendaryFlewAway
# 906 "data/maps/MtChimney/scripts.pory"
	release
	end

