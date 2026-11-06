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
MtChimney_EventScript_HideMoltres::
# 14 "data/maps/MtChimney/scripts.pory"
	setvar VAR_TEMP_1, 1
# 15 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MOLTRES_EMERALD
# 16 "data/maps/MtChimney/scripts.pory"
	return
# 17 "data/maps/MtChimney/scripts.pory"

# 18 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_TryShowMoltres::
# 19 "data/maps/MtChimney/scripts.pory"
	setvar VAR_TEMP_1, 1
# 20 "data/maps/MtChimney/scripts.pory"
	goto_if_set FLAG_CAUGHT_MOLTRES, Common_EventScript_NopReturn
# 21 "data/maps/MtChimney/scripts.pory"
	goto_if_set FLAG_DEFEATED_MOLTRES, Common_EventScript_NopReturn
# 22 "data/maps/MtChimney/scripts.pory"
	setvar VAR_TEMP_1, 0
# 23 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_MOLTRES_EMERALD
# 24 "data/maps/MtChimney/scripts.pory"
	return
# 25 "data/maps/MtChimney/scripts.pory"

# 26 "data/maps/MtChimney/scripts.pory"
MtChimney_OnResume:
# 27 "data/maps/MtChimney/scripts.pory"
	setstepcallback STEP_CB_ASH
# 28 "data/maps/MtChimney/scripts.pory"
    call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtChimney_EventScript_TryRemoveMoltres
# 29 "data/maps/MtChimney/scripts.pory"
	end
# 30 "data/maps/MtChimney/scripts.pory"

# 31 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_TryRemoveMoltres::
# 32 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 33 "data/maps/MtChimney/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 34 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MOLTRES
# 35 "data/maps/MtChimney/scripts.pory"
	return
# 36 "data/maps/MtChimney/scripts.pory"

# 37 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Archie::
# 38 "data/maps/MtChimney/scripts.pory"
	lock
# 39 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 40 "data/maps/MtChimney/scripts.pory"
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
# 41 "data/maps/MtChimney/scripts.pory"
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
# 42 "data/maps/MtChimney/scripts.pory"
	closemessage
# 43 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
# 44 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 45 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
# 46 "data/maps/MtChimney/scripts.pory"
	release
# 47 "data/maps/MtChimney/scripts.pory"
	end
# 48 "data/maps/MtChimney/scripts.pory"

# 49 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieGoStopTeamMagma::
# 50 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
# 51 "data/maps/MtChimney/scripts.pory"
	return
# 52 "data/maps/MtChimney/scripts.pory"

# 53 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieBusyFighting::
# 54 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
# 55 "data/maps/MtChimney/scripts.pory"
	return
# 56 "data/maps/MtChimney/scripts.pory"

# 57 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Maxie::
# 58 "data/maps/MtChimney/scripts.pory"
	lockall
# 59 "data/maps/MtChimney/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 60 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
# 61 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
# 62 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 63 "data/maps/MtChimney/scripts.pory"
	playse SE_PIN
# 64 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
# 65 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 66 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
# 67 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 68 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
# 69 "data/maps/MtChimney/scripts.pory"
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
# 70 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
# 71 "data/maps/MtChimney/scripts.pory"
	closemessage
# 72 "data/maps/MtChimney/scripts.pory"
	delay 30
# 73 "data/maps/MtChimney/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 74 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MAXIE
# 75 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
# 76 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_TABITHA
# 77 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
# 78 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
# 79 "data/maps/MtChimney/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 80 "data/maps/MtChimney/scripts.pory"
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
# 81 "data/maps/MtChimney/scripts.pory"
	addobject LOCALID_MT_CHIMNEY_ARCHIE
# 82 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
# 83 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
# 84 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 85 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 86 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
# 87 "data/maps/MtChimney/scripts.pory"
	closemessage
# 88 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
# 89 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
# 90 "data/maps/MtChimney/scripts.pory"
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
# 91 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
# 92 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
# 93 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
# 94 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
# 95 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
# 96 "data/maps/MtChimney/scripts.pory"
	releaseall
# 97 "data/maps/MtChimney/scripts.pory"
	end
# 98 "data/maps/MtChimney/scripts.pory"

# 99 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerEast::
# 100 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
# 101 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 102 "data/maps/MtChimney/scripts.pory"
	return
# 103 "data/maps/MtChimney/scripts.pory"

# 104 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieApproachPlayerNorth::
# 105 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
# 106 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 107 "data/maps/MtChimney/scripts.pory"
	return
# 108 "data/maps/MtChimney/scripts.pory"

# 109 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitEast::
# 110 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
# 111 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 112 "data/maps/MtChimney/scripts.pory"
	return
# 113 "data/maps/MtChimney/scripts.pory"

# 114 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_ArchieExitNorth::
# 115 "data/maps/MtChimney/scripts.pory"
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
# 116 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 117 "data/maps/MtChimney/scripts.pory"
	return
# 118 "data/maps/MtChimney/scripts.pory"

# 119 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_LavaCookieLady::
# 120 "data/maps/MtChimney/scripts.pory"
	lock
# 121 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 122 "data/maps/MtChimney/scripts.pory"
	showmoneybox 0, 0
# 123 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
# 124 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
# 125 "data/maps/MtChimney/scripts.pory"
	checkmoney 200
# 126 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
# 127 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
# 128 "data/maps/MtChimney/scripts.pory"
	checkitemspace ITEM_LAVA_COOKIE
# 129 "data/maps/MtChimney/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
# 130 "data/maps/MtChimney/scripts.pory"
.if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_OFF
# 131 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 132 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 133 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 134 "data/maps/MtChimney/scripts.pory"
	release
# 135 "data/maps/MtChimney/scripts.pory"
	end
# 136 "data/maps/MtChimney/scripts.pory"

# 137 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 138 "data/maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 139 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 140 "data/maps/MtChimney/scripts.pory"
	release
# 141 "data/maps/MtChimney/scripts.pory"
	end
# 142 "data/maps/MtChimney/scripts.pory"
.else
# 143 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 144 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_LAVA_COOKIE
# 145 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
# 146 "data/maps/MtChimney/scripts.pory"
	release
# 147 "data/maps/MtChimney/scripts.pory"
	end
# 148 "data/maps/MtChimney/scripts.pory"

# 149 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BagIsFull::
# 150 "data/maps/MtChimney/scripts.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 151 "data/maps/MtChimney/scripts.pory"
	release
# 152 "data/maps/MtChimney/scripts.pory"
	end
# 153 "data/maps/MtChimney/scripts.pory"
.endif @ OW_SHOW_ITEM_DESCRIPTIONS
# 154 "data/maps/MtChimney/scripts.pory"

# 155 "data/maps/MtChimney/scripts.pory"

# 156 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RemoveMoney::
# 157 "data/maps/MtChimney/scripts.pory"
	removemoney 200
# 158 "data/maps/MtChimney/scripts.pory"
	updatemoneybox
# 159 "data/maps/MtChimney/scripts.pory"
	return
# 160 "data/maps/MtChimney/scripts.pory"

# 161 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_DeclineLavaCookie::
# 162 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
# 163 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 164 "data/maps/MtChimney/scripts.pory"
	release
# 165 "data/maps/MtChimney/scripts.pory"
	end
# 166 "data/maps/MtChimney/scripts.pory"

# 167 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_NotEnoughMoney::
# 168 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
# 169 "data/maps/MtChimney/scripts.pory"
	hidemoneybox
# 170 "data/maps/MtChimney/scripts.pory"
	release
# 171 "data/maps/MtChimney/scripts.pory"
	end
# 172 "data/maps/MtChimney/scripts.pory"

# 173 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerEast:
# 174 "data/maps/MtChimney/scripts.pory"
	walk_up
# 175 "data/maps/MtChimney/scripts.pory"
	walk_up
# 176 "data/maps/MtChimney/scripts.pory"
	walk_up
# 177 "data/maps/MtChimney/scripts.pory"
	walk_up
# 178 "data/maps/MtChimney/scripts.pory"
	walk_up
# 179 "data/maps/MtChimney/scripts.pory"
	walk_up
# 180 "data/maps/MtChimney/scripts.pory"
	walk_right
# 181 "data/maps/MtChimney/scripts.pory"
	step_end
# 182 "data/maps/MtChimney/scripts.pory"

# 183 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitEast:
# 184 "data/maps/MtChimney/scripts.pory"
	walk_left
# 185 "data/maps/MtChimney/scripts.pory"
	walk_down
# 186 "data/maps/MtChimney/scripts.pory"
	walk_down
# 187 "data/maps/MtChimney/scripts.pory"
	walk_down
# 188 "data/maps/MtChimney/scripts.pory"
	walk_down
# 189 "data/maps/MtChimney/scripts.pory"
	walk_down
# 190 "data/maps/MtChimney/scripts.pory"
	walk_down
# 191 "data/maps/MtChimney/scripts.pory"
	walk_down
# 192 "data/maps/MtChimney/scripts.pory"
	step_end
# 193 "data/maps/MtChimney/scripts.pory"

# 194 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieApproachPlayerNorth:
# 195 "data/maps/MtChimney/scripts.pory"
	walk_up
# 196 "data/maps/MtChimney/scripts.pory"
	walk_up
# 197 "data/maps/MtChimney/scripts.pory"
	walk_up
# 198 "data/maps/MtChimney/scripts.pory"
	walk_up
# 199 "data/maps/MtChimney/scripts.pory"
	walk_up
# 200 "data/maps/MtChimney/scripts.pory"
	walk_right
# 201 "data/maps/MtChimney/scripts.pory"
	walk_right
# 202 "data/maps/MtChimney/scripts.pory"
	step_end
# 203 "data/maps/MtChimney/scripts.pory"

# 204 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_ArchieExitNorth:
# 205 "data/maps/MtChimney/scripts.pory"
	walk_left
# 206 "data/maps/MtChimney/scripts.pory"
	walk_left
# 207 "data/maps/MtChimney/scripts.pory"
	walk_down
# 208 "data/maps/MtChimney/scripts.pory"
	walk_down
# 209 "data/maps/MtChimney/scripts.pory"
	walk_down
# 210 "data/maps/MtChimney/scripts.pory"
	walk_down
# 211 "data/maps/MtChimney/scripts.pory"
	walk_down
# 212 "data/maps/MtChimney/scripts.pory"
	walk_down
# 213 "data/maps/MtChimney/scripts.pory"
	walk_down
# 214 "data/maps/MtChimney/scripts.pory"
	step_end
# 215 "data/maps/MtChimney/scripts.pory"

# 216 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused1:
# 217 "data/maps/MtChimney/scripts.pory"
	walk_down
# 218 "data/maps/MtChimney/scripts.pory"
	walk_down
# 219 "data/maps/MtChimney/scripts.pory"
	walk_down
# 220 "data/maps/MtChimney/scripts.pory"
	walk_down
# 221 "data/maps/MtChimney/scripts.pory"
	walk_down
# 222 "data/maps/MtChimney/scripts.pory"
	walk_left
# 223 "data/maps/MtChimney/scripts.pory"
	walk_left
# 224 "data/maps/MtChimney/scripts.pory"
	walk_down
# 225 "data/maps/MtChimney/scripts.pory"
	walk_down
# 226 "data/maps/MtChimney/scripts.pory"
	walk_down
# 227 "data/maps/MtChimney/scripts.pory"
	walk_down
# 228 "data/maps/MtChimney/scripts.pory"
	walk_left
# 229 "data/maps/MtChimney/scripts.pory"
	walk_left
# 230 "data/maps/MtChimney/scripts.pory"
	walk_left
# 231 "data/maps/MtChimney/scripts.pory"
	walk_left
# 232 "data/maps/MtChimney/scripts.pory"
	walk_left
# 233 "data/maps/MtChimney/scripts.pory"
	walk_down
# 234 "data/maps/MtChimney/scripts.pory"
	step_end
# 235 "data/maps/MtChimney/scripts.pory"

# 236 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused2:
# 237 "data/maps/MtChimney/scripts.pory"
	walk_down
# 238 "data/maps/MtChimney/scripts.pory"
	walk_down
# 239 "data/maps/MtChimney/scripts.pory"
	walk_down
# 240 "data/maps/MtChimney/scripts.pory"
	walk_down
# 241 "data/maps/MtChimney/scripts.pory"
	walk_left
# 242 "data/maps/MtChimney/scripts.pory"
	walk_left
# 243 "data/maps/MtChimney/scripts.pory"
	walk_left
# 244 "data/maps/MtChimney/scripts.pory"
	walk_down
# 245 "data/maps/MtChimney/scripts.pory"
	step_end
# 246 "data/maps/MtChimney/scripts.pory"

# 247 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused3:
# 248 "data/maps/MtChimney/scripts.pory"
	walk_right
# 249 "data/maps/MtChimney/scripts.pory"
	walk_down
# 250 "data/maps/MtChimney/scripts.pory"
	walk_down
# 251 "data/maps/MtChimney/scripts.pory"
	walk_down
# 252 "data/maps/MtChimney/scripts.pory"
	walk_down
# 253 "data/maps/MtChimney/scripts.pory"
	walk_left
# 254 "data/maps/MtChimney/scripts.pory"
	walk_left
# 255 "data/maps/MtChimney/scripts.pory"
	walk_left
# 256 "data/maps/MtChimney/scripts.pory"
	walk_left
# 257 "data/maps/MtChimney/scripts.pory"
	walk_left
# 258 "data/maps/MtChimney/scripts.pory"
	walk_down
# 259 "data/maps/MtChimney/scripts.pory"
	walk_down
# 260 "data/maps/MtChimney/scripts.pory"
	walk_down
# 261 "data/maps/MtChimney/scripts.pory"
	walk_down
# 262 "data/maps/MtChimney/scripts.pory"
	step_end
# 263 "data/maps/MtChimney/scripts.pory"

# 264 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused4:
# 265 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 266 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 267 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 268 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 269 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 270 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 271 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 272 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 273 "data/maps/MtChimney/scripts.pory"
	walk_fast_down
# 274 "data/maps/MtChimney/scripts.pory"
	walk_left
# 275 "data/maps/MtChimney/scripts.pory"
	walk_left
# 276 "data/maps/MtChimney/scripts.pory"
	walk_down
# 277 "data/maps/MtChimney/scripts.pory"
	walk_down
# 278 "data/maps/MtChimney/scripts.pory"
	walk_down
# 279 "data/maps/MtChimney/scripts.pory"
	walk_left
# 280 "data/maps/MtChimney/scripts.pory"
	walk_left
# 281 "data/maps/MtChimney/scripts.pory"
	walk_down
# 282 "data/maps/MtChimney/scripts.pory"
	walk_down
# 283 "data/maps/MtChimney/scripts.pory"
	walk_left
# 284 "data/maps/MtChimney/scripts.pory"
	walk_left
# 285 "data/maps/MtChimney/scripts.pory"
	walk_left
# 286 "data/maps/MtChimney/scripts.pory"
	walk_left
# 287 "data/maps/MtChimney/scripts.pory"
	walk_left
# 288 "data/maps/MtChimney/scripts.pory"
	walk_down
# 289 "data/maps/MtChimney/scripts.pory"
	step_end
# 290 "data/maps/MtChimney/scripts.pory"

# 291 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused5:
# 292 "data/maps/MtChimney/scripts.pory"
	delay_16
# 293 "data/maps/MtChimney/scripts.pory"
	delay_16
# 294 "data/maps/MtChimney/scripts.pory"
	delay_16
# 295 "data/maps/MtChimney/scripts.pory"
	walk_down
# 296 "data/maps/MtChimney/scripts.pory"
	walk_down
# 297 "data/maps/MtChimney/scripts.pory"
	walk_down
# 298 "data/maps/MtChimney/scripts.pory"
	walk_left
# 299 "data/maps/MtChimney/scripts.pory"
	walk_left
# 300 "data/maps/MtChimney/scripts.pory"
	walk_left
# 301 "data/maps/MtChimney/scripts.pory"
	walk_down
# 302 "data/maps/MtChimney/scripts.pory"
	step_end
# 303 "data/maps/MtChimney/scripts.pory"

# 304 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused6:
# 305 "data/maps/MtChimney/scripts.pory"
	delay_16
# 306 "data/maps/MtChimney/scripts.pory"
	walk_left
# 307 "data/maps/MtChimney/scripts.pory"
	walk_down
# 308 "data/maps/MtChimney/scripts.pory"
	walk_down
# 309 "data/maps/MtChimney/scripts.pory"
	walk_down
# 310 "data/maps/MtChimney/scripts.pory"
	walk_down
# 311 "data/maps/MtChimney/scripts.pory"
	walk_left
# 312 "data/maps/MtChimney/scripts.pory"
	walk_left
# 313 "data/maps/MtChimney/scripts.pory"
	walk_left
# 314 "data/maps/MtChimney/scripts.pory"
	walk_left
# 315 "data/maps/MtChimney/scripts.pory"
	walk_left
# 316 "data/maps/MtChimney/scripts.pory"
	walk_down
# 317 "data/maps/MtChimney/scripts.pory"
	walk_down
# 318 "data/maps/MtChimney/scripts.pory"
	walk_down
# 319 "data/maps/MtChimney/scripts.pory"
	walk_down
# 320 "data/maps/MtChimney/scripts.pory"
	step_end
# 321 "data/maps/MtChimney/scripts.pory"

# 322 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused7:
# 323 "data/maps/MtChimney/scripts.pory"
	delay_16
# 324 "data/maps/MtChimney/scripts.pory"
	walk_left
# 325 "data/maps/MtChimney/scripts.pory"
	walk_left
# 326 "data/maps/MtChimney/scripts.pory"
	walk_down
# 327 "data/maps/MtChimney/scripts.pory"
	walk_down
# 328 "data/maps/MtChimney/scripts.pory"
	walk_down
# 329 "data/maps/MtChimney/scripts.pory"
	walk_left
# 330 "data/maps/MtChimney/scripts.pory"
	walk_left
# 331 "data/maps/MtChimney/scripts.pory"
	walk_down
# 332 "data/maps/MtChimney/scripts.pory"
	walk_down
# 333 "data/maps/MtChimney/scripts.pory"
	walk_left
# 334 "data/maps/MtChimney/scripts.pory"
	walk_left
# 335 "data/maps/MtChimney/scripts.pory"
	walk_left
# 336 "data/maps/MtChimney/scripts.pory"
	walk_left
# 337 "data/maps/MtChimney/scripts.pory"
	walk_left
# 338 "data/maps/MtChimney/scripts.pory"
	walk_down
# 339 "data/maps/MtChimney/scripts.pory"
	step_end
# 340 "data/maps/MtChimney/scripts.pory"

# 341 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused8:
# 342 "data/maps/MtChimney/scripts.pory"
	delay_16
# 343 "data/maps/MtChimney/scripts.pory"
	walk_down
# 344 "data/maps/MtChimney/scripts.pory"
	walk_left
# 345 "data/maps/MtChimney/scripts.pory"
	walk_left
# 346 "data/maps/MtChimney/scripts.pory"
	walk_left
# 347 "data/maps/MtChimney/scripts.pory"
	walk_left
# 348 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_down
# 349 "data/maps/MtChimney/scripts.pory"
	step_end
# 350 "data/maps/MtChimney/scripts.pory"

# 351 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused9:
# 352 "data/maps/MtChimney/scripts.pory"
	walk_down
# 353 "data/maps/MtChimney/scripts.pory"
	walk_down
# 354 "data/maps/MtChimney/scripts.pory"
	walk_down
# 355 "data/maps/MtChimney/scripts.pory"
	walk_down
# 356 "data/maps/MtChimney/scripts.pory"
	walk_left
# 357 "data/maps/MtChimney/scripts.pory"
	walk_left
# 358 "data/maps/MtChimney/scripts.pory"
	walk_left
# 359 "data/maps/MtChimney/scripts.pory"
	walk_left
# 360 "data/maps/MtChimney/scripts.pory"
	walk_left
# 361 "data/maps/MtChimney/scripts.pory"
	walk_down
# 362 "data/maps/MtChimney/scripts.pory"
	walk_down
# 363 "data/maps/MtChimney/scripts.pory"
	walk_down
# 364 "data/maps/MtChimney/scripts.pory"
	walk_down
# 365 "data/maps/MtChimney/scripts.pory"
	step_end
# 366 "data/maps/MtChimney/scripts.pory"

# 367 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused10:
# 368 "data/maps/MtChimney/scripts.pory"
	walk_down
# 369 "data/maps/MtChimney/scripts.pory"
	step_end
# 370 "data/maps/MtChimney/scripts.pory"

# 371 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused11:
# 372 "data/maps/MtChimney/scripts.pory"
	walk_down
# 373 "data/maps/MtChimney/scripts.pory"
	walk_down
# 374 "data/maps/MtChimney/scripts.pory"
	walk_down
# 375 "data/maps/MtChimney/scripts.pory"
	walk_down
# 376 "data/maps/MtChimney/scripts.pory"
	walk_down
# 377 "data/maps/MtChimney/scripts.pory"
	walk_down
# 378 "data/maps/MtChimney/scripts.pory"
	walk_down
# 379 "data/maps/MtChimney/scripts.pory"
	step_end
# 380 "data/maps/MtChimney/scripts.pory"

# 381 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused12:
# 382 "data/maps/MtChimney/scripts.pory"
	delay_16
# 383 "data/maps/MtChimney/scripts.pory"
	delay_16
# 384 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 385 "data/maps/MtChimney/scripts.pory"
	delay_16
# 386 "data/maps/MtChimney/scripts.pory"
	walk_down
# 387 "data/maps/MtChimney/scripts.pory"
	walk_down
# 388 "data/maps/MtChimney/scripts.pory"
	walk_down
# 389 "data/maps/MtChimney/scripts.pory"
	walk_down
# 390 "data/maps/MtChimney/scripts.pory"
	walk_down
# 391 "data/maps/MtChimney/scripts.pory"
	step_end
# 392 "data/maps/MtChimney/scripts.pory"

# 393 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused13:
# 394 "data/maps/MtChimney/scripts.pory"
	delay_16
# 395 "data/maps/MtChimney/scripts.pory"
	delay_16
# 396 "data/maps/MtChimney/scripts.pory"
	delay_16
# 397 "data/maps/MtChimney/scripts.pory"
	delay_16
# 398 "data/maps/MtChimney/scripts.pory"
	delay_16
# 399 "data/maps/MtChimney/scripts.pory"
	delay_16
# 400 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_left
# 401 "data/maps/MtChimney/scripts.pory"
	delay_16
# 402 "data/maps/MtChimney/scripts.pory"
	walk_down
# 403 "data/maps/MtChimney/scripts.pory"
	walk_down
# 404 "data/maps/MtChimney/scripts.pory"
	step_end
# 405 "data/maps/MtChimney/scripts.pory"

# 406 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused14:
# 407 "data/maps/MtChimney/scripts.pory"
	lock_facing_direction
# 408 "data/maps/MtChimney/scripts.pory"
	walk_fast_left
# 409 "data/maps/MtChimney/scripts.pory"
	unlock_facing_direction
# 410 "data/maps/MtChimney/scripts.pory"
	face_right
# 411 "data/maps/MtChimney/scripts.pory"
	step_end
# 412 "data/maps/MtChimney/scripts.pory"

# 413 "data/maps/MtChimney/scripts.pory"
MtChimney_Movement_Unused15:
# 414 "data/maps/MtChimney/scripts.pory"
	walk_left
# 415 "data/maps/MtChimney/scripts.pory"
	walk_in_place_faster_right
# 416 "data/maps/MtChimney/scripts.pory"
	delay_16
# 417 "data/maps/MtChimney/scripts.pory"
	step_end
# 418 "data/maps/MtChimney/scripts.pory"

# 419 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt1::
# 420 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
# 421 "data/maps/MtChimney/scripts.pory"
	end
# 422 "data/maps/MtChimney/scripts.pory"

# 423 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt2::
# 424 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
# 425 "data/maps/MtChimney/scripts.pory"
	end
# 426 "data/maps/MtChimney/scripts.pory"

# 427 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyAquaGrunt3::
# 428 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
# 429 "data/maps/MtChimney/scripts.pory"
	end
# 430 "data/maps/MtChimney/scripts.pory"

# 431 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Tabitha::
# 432 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
# 433 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 434 "data/maps/MtChimney/scripts.pory"
	end
# 435 "data/maps/MtChimney/scripts.pory"

# 436 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt2::
# 437 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
# 438 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 439 "data/maps/MtChimney/scripts.pory"
	end
# 440 "data/maps/MtChimney/scripts.pory"

# 441 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt1::
# 442 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
# 443 "data/maps/MtChimney/scripts.pory"
	end
# 444 "data/maps/MtChimney/scripts.pory"

# 445 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt2::
# 446 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
# 447 "data/maps/MtChimney/scripts.pory"
	end
# 448 "data/maps/MtChimney/scripts.pory"

# 449 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt3::
# 450 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
# 451 "data/maps/MtChimney/scripts.pory"
	end
# 452 "data/maps/MtChimney/scripts.pory"

# 453 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt4::
# 454 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
# 455 "data/maps/MtChimney/scripts.pory"
	end
# 456 "data/maps/MtChimney/scripts.pory"

# 457 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt5::
# 458 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
# 459 "data/maps/MtChimney/scripts.pory"
	end
# 460 "data/maps/MtChimney/scripts.pory"

# 461 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_BusyMagmaGrunt6::
# 462 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
# 463 "data/maps/MtChimney/scripts.pory"
	end
# 464 "data/maps/MtChimney/scripts.pory"

# 465 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MagmaPoochyena::
# 466 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
# 467 "data/maps/MtChimney/scripts.pory"
	end
# 468 "data/maps/MtChimney/scripts.pory"

# 469 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_AquaPoochyena::
# 470 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
# 471 "data/maps/MtChimney/scripts.pory"
	end
# 472 "data/maps/MtChimney/scripts.pory"

# 473 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MeteoriteMachine::
# 474 "data/maps/MtChimney/scripts.pory"
	lockall
# 475 "data/maps/MtChimney/scripts.pory"
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
# 476 "data/maps/MtChimney/scripts.pory"
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
# 477 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
# 478 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
# 479 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
# 480 "data/maps/MtChimney/scripts.pory"
	giveitem ITEM_METEORITE
# 481 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 482 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_RECEIVED_METEORITE
# 483 "data/maps/MtChimney/scripts.pory"
	releaseall
# 484 "data/maps/MtChimney/scripts.pory"
	end
# 485 "data/maps/MtChimney/scripts.pory"

# 486 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_LeaveMeteoriteAlone::
# 487 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
# 488 "data/maps/MtChimney/scripts.pory"
	releaseall
# 489 "data/maps/MtChimney/scripts.pory"
	end
# 490 "data/maps/MtChimney/scripts.pory"

# 491 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOff::
# 492 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
# 493 "data/maps/MtChimney/scripts.pory"
	releaseall
# 494 "data/maps/MtChimney/scripts.pory"
	end
# 495 "data/maps/MtChimney/scripts.pory"

# 496 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_MachineOn::
# 497 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MeteoriteFittedOnMachine, MSGBOX_DEFAULT
# 498 "data/maps/MtChimney/scripts.pory"
	releaseall
# 499 "data/maps/MtChimney/scripts.pory"
	end
# 500 "data/maps/MtChimney/scripts.pory"

# 501 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RouteSign::
# 502 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
# 503 "data/maps/MtChimney/scripts.pory"
	end
# 504 "data/maps/MtChimney/scripts.pory"

# 505 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shelby::
# 506 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
# 507 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 508 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
# 509 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
# 510 "data/maps/MtChimney/scripts.pory"
	release
# 511 "data/maps/MtChimney/scripts.pory"
	end
# 512 "data/maps/MtChimney/scripts.pory"

# 513 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_DefeatedShelby::
# 514 "data/maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 515 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 516 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
# 517 "data/maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SHELBY_1
# 518 "data/maps/MtChimney/scripts.pory"
	release
# 519 "data/maps/MtChimney/scripts.pory"
	end
# 520 "data/maps/MtChimney/scripts.pory"

# 521 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_RematchShelby::
# 522 "data/maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
# 523 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
# 524 "data/maps/MtChimney/scripts.pory"
	end
# 525 "data/maps/MtChimney/scripts.pory"

# 526 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Melissa::
# 527 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
# 528 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
# 529 "data/maps/MtChimney/scripts.pory"
	end
# 530 "data/maps/MtChimney/scripts.pory"

# 531 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sheila::
# 532 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
# 533 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
# 534 "data/maps/MtChimney/scripts.pory"
	end
# 535 "data/maps/MtChimney/scripts.pory"

# 536 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Shirley::
# 537 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
# 538 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
# 539 "data/maps/MtChimney/scripts.pory"
	end
# 540 "data/maps/MtChimney/scripts.pory"

# 541 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Grunt1::
# 542 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
# 543 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 544 "data/maps/MtChimney/scripts.pory"
	end
# 545 "data/maps/MtChimney/scripts.pory"

# 546 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_Sawyer::
# 547 "data/maps/MtChimney/scripts.pory"
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
# 548 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 549 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
# 550 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
# 551 "data/maps/MtChimney/scripts.pory"
	release
# 552 "data/maps/MtChimney/scripts.pory"
	end
# 553 "data/maps/MtChimney/scripts.pory"

# 554 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerDefeated::
# 555 "data/maps/MtChimney/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 556 "data/maps/MtChimney/scripts.pory"
	waitmovement 0
# 557 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
# 558 "data/maps/MtChimney/scripts.pory"
	register_matchcall TRAINER_SAWYER_1
# 559 "data/maps/MtChimney/scripts.pory"
	release
# 560 "data/maps/MtChimney/scripts.pory"
	end
# 561 "data/maps/MtChimney/scripts.pory"

# 562 "data/maps/MtChimney/scripts.pory"
MtChimney_EventScript_SawyerRematch::
# 563 "data/maps/MtChimney/scripts.pory"
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
# 564 "data/maps/MtChimney/scripts.pory"
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
# 565 "data/maps/MtChimney/scripts.pory"
	end
# 566 "data/maps/MtChimney/scripts.pory"

# 567 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoriteWillActivateVolcano:
# 568 "data/maps/MtChimney/scripts.pory"
	.string "The power contained in the Meteorite…\p"
# 569 "data/maps/MtChimney/scripts.pory"
	.string "By amplifying its power with this\n"
# 570 "data/maps/MtChimney/scripts.pory"
	.string "machine, Mt. Chimney's volcanic\l"
# 571 "data/maps/MtChimney/scripts.pory"
	.string "activity will instantly intensify…\p"
# 572 "data/maps/MtChimney/scripts.pory"
	.string "Its energy will grow deep inside\n"
# 573 "data/maps/MtChimney/scripts.pory"
	.string "the crater and…\l"
# 574 "data/maps/MtChimney/scripts.pory"
	.string "Fufufu…$"
# 575 "data/maps/MtChimney/scripts.pory"

# 576 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieIntro:
# 577 "data/maps/MtChimney/scripts.pory"
	.string "Maxie: Hm?\n"
# 578 "data/maps/MtChimney/scripts.pory"
	.string "Who are you?\p"
# 579 "data/maps/MtChimney/scripts.pory"
	.string "… … … … … …\n"
# 580 "data/maps/MtChimney/scripts.pory"
	.string "… … … … … …\p"
# 581 "data/maps/MtChimney/scripts.pory"
	.string "I'd heard Archie bemoaning a child\n"
# 582 "data/maps/MtChimney/scripts.pory"
	.string "who's been meddling in Team Aqua's\l"
# 583 "data/maps/MtChimney/scripts.pory"
	.string "affairs.\p"
# 584 "data/maps/MtChimney/scripts.pory"
	.string "It must be you he meant.\p"
# 585 "data/maps/MtChimney/scripts.pory"
	.string "Humph! So you're thinking of\n"
# 586 "data/maps/MtChimney/scripts.pory"
	.string "interfering with us, Team Magma?\p"
# 587 "data/maps/MtChimney/scripts.pory"
	.string "Now you listen.\n"
# 588 "data/maps/MtChimney/scripts.pory"
	.string "Long ago, living things used the\l"
# 589 "data/maps/MtChimney/scripts.pory"
	.string "land to live and grow.\p"
# 590 "data/maps/MtChimney/scripts.pory"
	.string "That is why land is all important!\n"
# 591 "data/maps/MtChimney/scripts.pory"
	.string "It is the cradle of all!\p"
# 592 "data/maps/MtChimney/scripts.pory"
	.string "That is why Team Magma is dedicated\n"
# 593 "data/maps/MtChimney/scripts.pory"
	.string "to the expansion of the land mass.\p"
# 594 "data/maps/MtChimney/scripts.pory"
	.string "It is for further advancement of\n"
# 595 "data/maps/MtChimney/scripts.pory"
	.string "humankind and Pokémon!\p"
# 596 "data/maps/MtChimney/scripts.pory"
	.string "And for that, we need the power of\n"
# 597 "data/maps/MtChimney/scripts.pory"
	.string "what sleeps within this mountain…\p"
# 598 "data/maps/MtChimney/scripts.pory"
	.string "Oh! There was no need for you to\n"
# 599 "data/maps/MtChimney/scripts.pory"
	.string "learn that much.\p"
# 600 "data/maps/MtChimney/scripts.pory"
	.string "But, no matter!\n"
# 601 "data/maps/MtChimney/scripts.pory"
	.string "I'll teach you the consequences of\l"
# 602 "data/maps/MtChimney/scripts.pory"
	.string "meddling in our grand design!$"
# 603 "data/maps/MtChimney/scripts.pory"

# 604 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieDefeat:
# 605 "data/maps/MtChimney/scripts.pory"
	.string "What?!\p"
# 606 "data/maps/MtChimney/scripts.pory"
	.string "I, Maxie, was caught off guard?!$"
# 607 "data/maps/MtChimney/scripts.pory"

# 608 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
# 609 "data/maps/MtChimney/scripts.pory"
	.string "Maxie: But, enough.\n"
# 610 "data/maps/MtChimney/scripts.pory"
	.string "I will back off this time.\p"
# 611 "data/maps/MtChimney/scripts.pory"
	.string "But don't think that this is the last\n"
# 612 "data/maps/MtChimney/scripts.pory"
	.string "you've seen of Team Magma.\p"
# 613 "data/maps/MtChimney/scripts.pory"
	.string "Fufufu…\p"
# 614 "data/maps/MtChimney/scripts.pory"
	.string "Even without the Meteorite, if we\n"
# 615 "data/maps/MtChimney/scripts.pory"
	.string "obtain that Orb… Fufufu…$"
# 616 "data/maps/MtChimney/scripts.pory"

# 617 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaIntro:
# 618 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe!\p"
# 619 "data/maps/MtChimney/scripts.pory"
	.string "So you've come all the way here!\p"
# 620 "data/maps/MtChimney/scripts.pory"
	.string "But you're too late!\n"
# 621 "data/maps/MtChimney/scripts.pory"
	.string "I've already delivered the Meteorite\l"
# 622 "data/maps/MtChimney/scripts.pory"
	.string "from Meteor Falls to the boss!$"
# 623 "data/maps/MtChimney/scripts.pory"

# 624 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaDefeat:
# 625 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe…\p"
# 626 "data/maps/MtChimney/scripts.pory"
	.string "Even though I've lost, if our leader\n"
# 627 "data/maps/MtChimney/scripts.pory"
	.string "awakens that thing…$"
# 628 "data/maps/MtChimney/scripts.pory"

# 629 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TabithaPostBattle:
# 630 "data/maps/MtChimney/scripts.pory"
	.string "Boss, hurry!\n"
# 631 "data/maps/MtChimney/scripts.pory"
	.string "Give it the Meteorite's energy!\p"
# 632 "data/maps/MtChimney/scripts.pory"
	.string "Hehehe…$"
# 633 "data/maps/MtChimney/scripts.pory"

# 634 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Intro:
# 635 "data/maps/MtChimney/scripts.pory"
	.string "We of Team Magma are working hard for\n"
# 636 "data/maps/MtChimney/scripts.pory"
	.string "everyone's sake.\p"
# 637 "data/maps/MtChimney/scripts.pory"
	.string "Like, if that thing's power made more\n"
# 638 "data/maps/MtChimney/scripts.pory"
	.string "land, there'd be more places to live.\p"
# 639 "data/maps/MtChimney/scripts.pory"
	.string "Everyone'd be happy!$"
# 640 "data/maps/MtChimney/scripts.pory"

# 641 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2Defeat:
# 642 "data/maps/MtChimney/scripts.pory"
	.string "Hunh?\n"
# 643 "data/maps/MtChimney/scripts.pory"
	.string "What do you mean I lost?$"
# 644 "data/maps/MtChimney/scripts.pory"

# 645 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt2PostBattle:
# 646 "data/maps/MtChimney/scripts.pory"
	.string "Our boss says, “It will make everyone\n"
# 647 "data/maps/MtChimney/scripts.pory"
	.string "happy.”\p"
# 648 "data/maps/MtChimney/scripts.pory"
	.string "But why does everyone keep getting\n"
# 649 "data/maps/MtChimney/scripts.pory"
	.string "in our way?$"
# 650 "data/maps/MtChimney/scripts.pory"

# 651 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Intro:
# 652 "data/maps/MtChimney/scripts.pory"
	.string "If there were more land, I'd be able\n"
# 653 "data/maps/MtChimney/scripts.pory"
	.string "to get a big house of my own!\p"
# 654 "data/maps/MtChimney/scripts.pory"
	.string "I'm going to build it on hardened lava!$"
# 655 "data/maps/MtChimney/scripts.pory"

# 656 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1Defeat:
# 657 "data/maps/MtChimney/scripts.pory"
	.string "My dream of a big house…$"
# 658 "data/maps/MtChimney/scripts.pory"

# 659 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Grunt1PostBattle:
# 660 "data/maps/MtChimney/scripts.pory"
	.string "A kid like you, you ought to be\n"
# 661 "data/maps/MtChimney/scripts.pory"
	.string "splashing about in the waves!$"
# 662 "data/maps/MtChimney/scripts.pory"

# 663 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
# 664 "data/maps/MtChimney/scripts.pory"
	.string "That annoying Team Aqua…\n"
# 665 "data/maps/MtChimney/scripts.pory"
	.string "They always mess with our plans!$"
# 666 "data/maps/MtChimney/scripts.pory"

# 667 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoritesPackAmazingPower:
# 668 "data/maps/MtChimney/scripts.pory"
	.string "Meteorites pack amazing power!$"
# 669 "data/maps/MtChimney/scripts.pory"

# 670 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_YouBetterNotMessWithUs:
# 671 "data/maps/MtChimney/scripts.pory"
	.string "You'd better not mess with us!\p"
# 672 "data/maps/MtChimney/scripts.pory"
	.string "We're trying to awaken that thing\n"
# 673 "data/maps/MtChimney/scripts.pory"
	.string "for the benefit of everyone!$"
# 674 "data/maps/MtChimney/scripts.pory"

# 675 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_AquasNameSimilar:
# 676 "data/maps/MtChimney/scripts.pory"
	.string "We're Team Magma!\p"
# 677 "data/maps/MtChimney/scripts.pory"
	.string "They're Team Aqua!\p"
# 678 "data/maps/MtChimney/scripts.pory"
	.string "It totally annoys me that they'd\n"
# 679 "data/maps/MtChimney/scripts.pory"
	.string "use a name like ours!$"
# 680 "data/maps/MtChimney/scripts.pory"

# 681 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_DouseThemInFire:
# 682 "data/maps/MtChimney/scripts.pory"
	.string "Yeah!\n"
# 683 "data/maps/MtChimney/scripts.pory"
	.string "Douse them in fire!$"
# 684 "data/maps/MtChimney/scripts.pory"

# 685 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_KeepMakingMoreLand:
# 686 "data/maps/MtChimney/scripts.pory"
	.string "We're going to keep making more land!$"
# 687 "data/maps/MtChimney/scripts.pory"

# 688 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Bufoh:
# 689 "data/maps/MtChimney/scripts.pory"
	.string "Bufoh!$"
# 690 "data/maps/MtChimney/scripts.pory"

# 691 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieGoStopTeamMagma:
# 692 "data/maps/MtChimney/scripts.pory"
	.string "Archie: Grr, {PLAYER}!\n"
# 693 "data/maps/MtChimney/scripts.pory"
	.string "I should've guessed you'd show up!\p"
# 694 "data/maps/MtChimney/scripts.pory"
	.string "See for yourself what the fanatics\n"
# 695 "data/maps/MtChimney/scripts.pory"
	.string "of Team Magma are up to!\p"
# 696 "data/maps/MtChimney/scripts.pory"
	.string "They're trying to inject the stolen\n"
# 697 "data/maps/MtChimney/scripts.pory"
	.string "Meteorite's power into the volcano!\p"
# 698 "data/maps/MtChimney/scripts.pory"
	.string "Doing something like that will cause\n"
# 699 "data/maps/MtChimney/scripts.pory"
	.string "the volcano's eruption!$"
# 700 "data/maps/MtChimney/scripts.pory"

# 701 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieIHaveMyHandsFull:
# 702 "data/maps/MtChimney/scripts.pory"
	.string "Archie: Grrr…\p"
# 703 "data/maps/MtChimney/scripts.pory"
	.string "I want to stop that Maxie,\n"
# 704 "data/maps/MtChimney/scripts.pory"
	.string "but I can't!\p"
# 705 "data/maps/MtChimney/scripts.pory"
	.string "Not when I have my hands full battling\n"
# 706 "data/maps/MtChimney/scripts.pory"
	.string "three opponents at once!$"
# 707 "data/maps/MtChimney/scripts.pory"

# 708 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ArchieThankYou:
# 709 "data/maps/MtChimney/scripts.pory"
	.string "Archie: {PLAYER}!\n"
# 710 "data/maps/MtChimney/scripts.pory"
	.string "Thank you!\p"
# 711 "data/maps/MtChimney/scripts.pory"
	.string "With your help, we thwarted Team\n"
# 712 "data/maps/MtChimney/scripts.pory"
	.string "Magma's destructive plan!\p"
# 713 "data/maps/MtChimney/scripts.pory"
	.string "But… You…\n"
# 714 "data/maps/MtChimney/scripts.pory"
	.string "Whose side are you on?\p"
# 715 "data/maps/MtChimney/scripts.pory"
	.string "Ah, it doesn't matter.\p"
# 716 "data/maps/MtChimney/scripts.pory"
	.string "We will remain vigilant and keep up\n"
# 717 "data/maps/MtChimney/scripts.pory"
	.string "our pursuit of Team Magma.\p"
# 718 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER}, we shall meet again!$"
# 719 "data/maps/MtChimney/scripts.pory"

# 720 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MagmaOutnumbersUs:
# 721 "data/maps/MtChimney/scripts.pory"
	.string "Darn… Team Magma outnumbers us!\n"
# 722 "data/maps/MtChimney/scripts.pory"
	.string "We can't keep up with them!$"
# 723 "data/maps/MtChimney/scripts.pory"

# 724 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_LessHabitatForWaterPokemon:
# 725 "data/maps/MtChimney/scripts.pory"
	.string "If they expand the land, there'll be\n"
# 726 "data/maps/MtChimney/scripts.pory"
	.string "less habitats for Water Pokémon!$"
# 727 "data/maps/MtChimney/scripts.pory"

# 728 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MagmasNameSimilar:
# 729 "data/maps/MtChimney/scripts.pory"
	.string "We're Team Aqua!\p"
# 730 "data/maps/MtChimney/scripts.pory"
	.string "They're Team Magma!\p"
# 731 "data/maps/MtChimney/scripts.pory"
	.string "It burns me up that they'd use such\n"
# 732 "data/maps/MtChimney/scripts.pory"
	.string "a confusing name!$"
# 733 "data/maps/MtChimney/scripts.pory"

# 734 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_Bushaa:
# 735 "data/maps/MtChimney/scripts.pory"
	.string "Bushaa!$"
# 736 "data/maps/MtChimney/scripts.pory"

# 737 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_LavaCookiesJust200:
# 738 "data/maps/MtChimney/scripts.pory"
	.string "Lava Cookies are Mt. Chimney's local\n"
# 739 "data/maps/MtChimney/scripts.pory"
	.string "specialty.\p"
# 740 "data/maps/MtChimney/scripts.pory"
	.string "Try one. It's just ¥200.$"
# 741 "data/maps/MtChimney/scripts.pory"

# 742 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ThankYouDear:
# 743 "data/maps/MtChimney/scripts.pory"
	.string "Thank you, dear!$"
# 744 "data/maps/MtChimney/scripts.pory"

# 745 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_YouveNotGotTheMoney:
# 746 "data/maps/MtChimney/scripts.pory"
	.string "Oh, dear. You can't buy a thing if\n"
# 747 "data/maps/MtChimney/scripts.pory"
	.string "you've not got the money.$"
# 748 "data/maps/MtChimney/scripts.pory"

# 749 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_OhFineThen:
# 750 "data/maps/MtChimney/scripts.pory"
	.string "Oh, fine then.$"
# 751 "data/maps/MtChimney/scripts.pory"

# 752 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MeteoriteFittedOnMachine:
# 753 "data/maps/MtChimney/scripts.pory"
	.string "A Meteorite is fitted on a mysterious\n"
# 754 "data/maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 755 "data/maps/MtChimney/scripts.pory"
	.string "The machine seems to be storing\n"
# 756 "data/maps/MtChimney/scripts.pory"
	.string "energy in the Meteorite.$"
# 757 "data/maps/MtChimney/scripts.pory"

# 758 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_RemoveTheMeteorite:
# 759 "data/maps/MtChimney/scripts.pory"
	.string "A Meteorite is fitted on a mysterious\n"
# 760 "data/maps/MtChimney/scripts.pory"
	.string "machine…\p"
# 761 "data/maps/MtChimney/scripts.pory"
	.string "Do you want to remove the Meteorite?$"
# 762 "data/maps/MtChimney/scripts.pory"

# 763 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerRemovedMeteorite:
# 764 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER} removed the Meteorite from\n"
# 765 "data/maps/MtChimney/scripts.pory"
	.string "the mysterious machine.$"
# 766 "data/maps/MtChimney/scripts.pory"

# 767 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_PlayerLeftMeteorite:
# 768 "data/maps/MtChimney/scripts.pory"
	.string "{PLAYER} left the Meteorite where\n"
# 769 "data/maps/MtChimney/scripts.pory"
	.string "it was.$"
# 770 "data/maps/MtChimney/scripts.pory"

# 771 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MachineMakesNoResponse:
# 772 "data/maps/MtChimney/scripts.pory"
	.string "This mysterious machine…\n"
# 773 "data/maps/MtChimney/scripts.pory"
	.string "It makes no response whatsoever.$"
# 774 "data/maps/MtChimney/scripts.pory"

# 775 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_RouteSign:
# 776 "data/maps/MtChimney/scripts.pory"
	.string "{DOWN_ARROW} Jagged Pass\n"
# 777 "data/maps/MtChimney/scripts.pory"
	.string "Lavaridge Town Ahead$"
# 778 "data/maps/MtChimney/scripts.pory"

# 779 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyIntro:
# 780 "data/maps/MtChimney/scripts.pory"
	.string "I've been to the hot springs and\n"
# 781 "data/maps/MtChimney/scripts.pory"
	.string "refreshed my tired bones.\l"
# 782 "data/maps/MtChimney/scripts.pory"
	.string "Right now I'm feeling strong!$"
# 783 "data/maps/MtChimney/scripts.pory"

# 784 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyDefeat:
# 785 "data/maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 786 "data/maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 787 "data/maps/MtChimney/scripts.pory"

# 788 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostBattle:
# 789 "data/maps/MtChimney/scripts.pory"
	.string "Well, well, I've lost. I can't call\n"
# 790 "data/maps/MtChimney/scripts.pory"
	.string "myself an expert now, can I?$"
# 791 "data/maps/MtChimney/scripts.pory"

# 792 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRegister:
# 793 "data/maps/MtChimney/scripts.pory"
	.string "Thank you, child. It was fun, as if\n"
# 794 "data/maps/MtChimney/scripts.pory"
	.string "I were battling my own grandchild.\p"
# 795 "data/maps/MtChimney/scripts.pory"
	.string "Please, come see me again for\n"
# 796 "data/maps/MtChimney/scripts.pory"
	.string "a rematch.$"
# 797 "data/maps/MtChimney/scripts.pory"

# 798 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchIntro:
# 799 "data/maps/MtChimney/scripts.pory"
	.string "If you can mesh your heart with those\n"
# 800 "data/maps/MtChimney/scripts.pory"
	.string "of your Pokémon, why, you should be\l"
# 801 "data/maps/MtChimney/scripts.pory"
	.string "able to achieve great things.$"
# 802 "data/maps/MtChimney/scripts.pory"

# 803 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyRematchDefeat:
# 804 "data/maps/MtChimney/scripts.pory"
	.string "Oh, my goodness.\n"
# 805 "data/maps/MtChimney/scripts.pory"
	.string "Now, aren't you something!$"
# 806 "data/maps/MtChimney/scripts.pory"

# 807 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShelbyPostRematch:
# 808 "data/maps/MtChimney/scripts.pory"
	.string "Perhaps your heart has become one\n"
# 809 "data/maps/MtChimney/scripts.pory"
	.string "with the hearts of your Pokémon.$"
# 810 "data/maps/MtChimney/scripts.pory"

# 811 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaIntro:
# 812 "data/maps/MtChimney/scripts.pory"
	.string "I've got the fire in me, baby.\n"
# 813 "data/maps/MtChimney/scripts.pory"
	.string "I can't stand it! I have to battle!$"
# 814 "data/maps/MtChimney/scripts.pory"

# 815 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaDefeat:
# 816 "data/maps/MtChimney/scripts.pory"
	.string "Ooh, that was a scorching-hot match!$"
# 817 "data/maps/MtChimney/scripts.pory"

# 818 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_MelissaPostBattle:
# 819 "data/maps/MtChimney/scripts.pory"
	.string "The heat of Mt. Chimney warms\n"
# 820 "data/maps/MtChimney/scripts.pory"
	.string "me up, baby!$"
# 821 "data/maps/MtChimney/scripts.pory"

# 822 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaIntro:
# 823 "data/maps/MtChimney/scripts.pory"
	.string "I've finally made it to Mt. Chimney.\n"
# 824 "data/maps/MtChimney/scripts.pory"
	.string "I want to make my Pokémon battle!$"
# 825 "data/maps/MtChimney/scripts.pory"

# 826 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaDefeat:
# 827 "data/maps/MtChimney/scripts.pory"
	.string "The way you battle…\n"
# 828 "data/maps/MtChimney/scripts.pory"
	.string "It's like a Mt. Chimney eruption!$"
# 829 "data/maps/MtChimney/scripts.pory"

# 830 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SheilaPostBattle:
# 831 "data/maps/MtChimney/scripts.pory"
	.string "Like I said, I've finally made it to\n"
# 832 "data/maps/MtChimney/scripts.pory"
	.string "Mt. Chimney. It would be a shame if\l"
# 833 "data/maps/MtChimney/scripts.pory"
	.string "I only do a little sightseeing…\p"
# 834 "data/maps/MtChimney/scripts.pory"
	.string "I want to get in some battles and buy\n"
# 835 "data/maps/MtChimney/scripts.pory"
	.string "Lava Cookies as souvenirs.$"
# 836 "data/maps/MtChimney/scripts.pory"

# 837 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyIntro:
# 838 "data/maps/MtChimney/scripts.pory"
	.string "Since I bathed in the hot springs,\n"
# 839 "data/maps/MtChimney/scripts.pory"
	.string "I've been feeling great!\l"
# 840 "data/maps/MtChimney/scripts.pory"
	.string "I'm sure I'm going to win!$"
# 841 "data/maps/MtChimney/scripts.pory"

# 842 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyDefeat:
# 843 "data/maps/MtChimney/scripts.pory"
	.string "Yowch!\n"
# 844 "data/maps/MtChimney/scripts.pory"
	.string "I'm getting a chill out of the water.$"
# 845 "data/maps/MtChimney/scripts.pory"

# 846 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_ShirleyPostBattle:
# 847 "data/maps/MtChimney/scripts.pory"
	.string "I'll have to take another dip in the\n"
# 848 "data/maps/MtChimney/scripts.pory"
	.string "hot springs. Want to join me?\p"
# 849 "data/maps/MtChimney/scripts.pory"
	.string "Just joking!$"
# 850 "data/maps/MtChimney/scripts.pory"

# 851 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerIntro:
# 852 "data/maps/MtChimney/scripts.pory"
	.string "This is one fine mountain! Plenty of\n"
# 853 "data/maps/MtChimney/scripts.pory"
	.string "hot people around for company!$"
# 854 "data/maps/MtChimney/scripts.pory"

# 855 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerDefeat:
# 856 "data/maps/MtChimney/scripts.pory"
	.string "Oh, you're a real firebrand, too!$"
# 857 "data/maps/MtChimney/scripts.pory"

# 858 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostBattle:
# 859 "data/maps/MtChimney/scripts.pory"
	.string "I think I need a dip in Lavaridge\n"
# 860 "data/maps/MtChimney/scripts.pory"
	.string "Hot Spring with the locals!$"
# 861 "data/maps/MtChimney/scripts.pory"

# 862 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRegister:
# 863 "data/maps/MtChimney/scripts.pory"
	.string "I like little fireballs like you.\n"
# 864 "data/maps/MtChimney/scripts.pory"
	.string "Let me register you in my PokéNav.$"
# 865 "data/maps/MtChimney/scripts.pory"

# 866 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchIntro:
# 867 "data/maps/MtChimney/scripts.pory"
	.string "I'm happily surrounded by hot people\n"
# 868 "data/maps/MtChimney/scripts.pory"
	.string "around these parts. I won't lose!$"
# 869 "data/maps/MtChimney/scripts.pory"

# 870 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerRematchDefeat:
# 871 "data/maps/MtChimney/scripts.pory"
	.string "Gosh, you're still the same\n"
# 872 "data/maps/MtChimney/scripts.pory"
	.string "firebrand as before!$"
# 873 "data/maps/MtChimney/scripts.pory"

# 874 "data/maps/MtChimney/scripts.pory"
MtChimney_Text_SawyerPostRematch:
# 875 "data/maps/MtChimney/scripts.pory"
	.string "Actually, it really is hot here.\n"
# 876 "data/maps/MtChimney/scripts.pory"
	.string "I'm overdressed for these parts.$"

MtChimney_BattleMoltres::
# 880 "data/maps/MtChimney/scripts.pory"
	lock
# 881 "data/maps/MtChimney/scripts.pory"
	faceplayer
# 882 "data/maps/MtChimney/scripts.pory"
	setvar VAR_TEMP_1, 1
# 883 "data/maps/MtChimney/scripts.pory"
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
# 884 "data/maps/MtChimney/scripts.pory"
	delay 30
# 885 "data/maps/MtChimney/scripts.pory"
	waitmoncry
# 886 "data/maps/MtChimney/scripts.pory"
	seteventmon SPECIES_MOLTRES, 50
# 887 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 888 "data/maps/MtChimney/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 889 "data/maps/MtChimney/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 890 "data/maps/MtChimney/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_MT_CHIMNEY_MOLTRES
# 891 "data/maps/MtChimney/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 892 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MtChimney_EventScript_DefeatedMoltres
# 893 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtChimney_EventScript_RanFromMoltres
# 894 "data/maps/MtChimney/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MtChimney_EventScript_RanFromMoltres
# 895 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_CAUGHT_MOLTRES
# 896 "data/maps/MtChimney/scripts.pory"
	release
	end


MtChimney_EventScript_DefeatedMoltres::
# 901 "data/maps/MtChimney/scripts.pory"
	setflag FLAG_DEFEATED_MOLTRES
# 902 "data/maps/MtChimney/scripts.pory"
	setvar VAR_0x8004, SPECIES_MOLTRES
# 903 "data/maps/MtChimney/scripts.pory"
	call Common_EventScript_LegendaryFlewAway
# 904 "data/maps/MtChimney/scripts.pory"
	release
	end


MtChimney_EventScript_RanFromMoltres::
# 909 "data/maps/MtChimney/scripts.pory"
	setvar VAR_0x8004, SPECIES_MOLTRES
# 910 "data/maps/MtChimney/scripts.pory"
	call Common_EventScript_LegendaryFlewAway
# 911 "data/maps/MtChimney/scripts.pory"
	release
	end

