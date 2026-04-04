# 1 "data/maps/MossdeepCity/scripts.pory"

# 2 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_MapScripts::
# 3 "data/maps/MossdeepCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
# 4 "data/maps/MossdeepCity/scripts.pory"
	.byte 0
# 5 "data/maps/MossdeepCity/scripts.pory"

# 6 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_OnTransition:
# 7 "data/maps/MossdeepCity/scripts.pory"
    clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
# 8 "data/maps/MossdeepCity/scripts.pory"
    clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
# 9 "data/maps/MossdeepCity/scripts.pory"
    clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
# 10 "data/maps/MossdeepCity/scripts.pory"
    clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
# 11 "data/maps/MossdeepCity/scripts.pory"
    call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 12 "data/maps/MossdeepCity/scripts.pory"
    goto MossdeepCity_EventScript_CheckDeoxysScientist
# 13 "data/maps/MossdeepCity/scripts.pory"
    end
# 14 "data/maps/MossdeepCity/scripts.pory"

# 15 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_CheckDeoxysScientist:
# 16 "data/maps/MossdeepCity/scripts.pory"
    goto_if_unset FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE, MossdeepCity_EventScript_HideScientist
# 17 "data/maps/MossdeepCity/scripts.pory"
    goto_if_set FLAG_RECEIVED_AURORA_TICKET, MossdeepCity_EventScript_HideScientist
# 18 "data/maps/MossdeepCity/scripts.pory"
    clearflag FLAG_HIDE_DEOXYS_SCIENTIST
# 19 "data/maps/MossdeepCity/scripts.pory"
    return
# 20 "data/maps/MossdeepCity/scripts.pory"

# 21 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_HideScientist:
# 22 "data/maps/MossdeepCity/scripts.pory"
    setflag FLAG_HIDE_DEOXYS_SCIENTIST
# 23 "data/maps/MossdeepCity/scripts.pory"
    return
# 24 "data/maps/MossdeepCity/scripts.pory"

# 25 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanF::
# 26 "data/maps/MossdeepCity/scripts.pory"
	lock
# 27 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 28 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
# 29 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
# 30 "data/maps/MossdeepCity/scripts.pory"
	release
# 31 "data/maps/MossdeepCity/scripts.pory"
	end
# 32 "data/maps/MossdeepCity/scripts.pory"

# 33 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanFMagmaGone::
# 34 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
# 35 "data/maps/MossdeepCity/scripts.pory"
	release
# 36 "data/maps/MossdeepCity/scripts.pory"
	end
# 37 "data/maps/MossdeepCity/scripts.pory"

# 38 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Sailor::
# 39 "data/maps/MossdeepCity/scripts.pory"
	lock
# 40 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 41 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
# 42 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
# 43 "data/maps/MossdeepCity/scripts.pory"
	release
# 44 "data/maps/MossdeepCity/scripts.pory"
	end
# 45 "data/maps/MossdeepCity/scripts.pory"

# 46 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SailorMagmaGone::
# 47 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
# 48 "data/maps/MossdeepCity/scripts.pory"
	release
# 49 "data/maps/MossdeepCity/scripts.pory"
	end
# 50 "data/maps/MossdeepCity/scripts.pory"

# 51 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_NinjaBoy::
# 52 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
# 53 "data/maps/MossdeepCity/scripts.pory"
	end
# 54 "data/maps/MossdeepCity/scripts.pory"

# 55 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ExpertM::
# 56 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
# 57 "data/maps/MossdeepCity/scripts.pory"
	end
# 58 "data/maps/MossdeepCity/scripts.pory"

# 59 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Girl::
# 60 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
# 61 "data/maps/MossdeepCity/scripts.pory"
	end
# 62 "data/maps/MossdeepCity/scripts.pory"

# 63 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Woman::
# 64 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
# 65 "data/maps/MossdeepCity/scripts.pory"
	end
# 66 "data/maps/MossdeepCity/scripts.pory"

# 67 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_WhiteRock::
# 68 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
# 69 "data/maps/MossdeepCity/scripts.pory"
	end
# 70 "data/maps/MossdeepCity/scripts.pory"

# 71 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_GymSign::
# 72 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
# 73 "data/maps/MossdeepCity/scripts.pory"
	end
# 74 "data/maps/MossdeepCity/scripts.pory"

# 75 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_CitySign::
# 76 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
# 77 "data/maps/MossdeepCity/scripts.pory"
	end
# 78 "data/maps/MossdeepCity/scripts.pory"

# 79 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SpaceCenterSign::
# 80 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
# 81 "data/maps/MossdeepCity/scripts.pory"
	end
# 82 "data/maps/MossdeepCity/scripts.pory"

# 83 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_VisitedMossdeep::
# 84 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_VISITED_MOSSDEEP_CITY
# 85 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 86 "data/maps/MossdeepCity/scripts.pory"
	end
# 87 "data/maps/MossdeepCity/scripts.pory"

# 88 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
# 89 "data/maps/MossdeepCity/scripts.pory"
	lockall
# 90 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
# 91 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 92 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
# 93 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
# 94 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
# 95 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
# 96 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 97 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
# 98 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
# 99 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
# 100 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
# 101 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
# 102 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 103 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_MAXIE
# 104 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_GRUNT_1
# 105 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_GRUNT_2
# 106 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_GRUNT_3
# 107 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_GRUNT_4
# 108 "data/maps/MossdeepCity/scripts.pory"
	delay 30
# 109 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_MOSSDEEP_CITY_STATE, 2
# 110 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
# 111 "data/maps/MossdeepCity/scripts.pory"
	releaseall
# 112 "data/maps/MossdeepCity/scripts.pory"
	end
# 113 "data/maps/MossdeepCity/scripts.pory"

# 114 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieGestureToSpaceCenter:
# 115 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 116 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 117 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 118 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 119 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 120 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 121 "data/maps/MossdeepCity/scripts.pory"
	face_left
# 122 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 123 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 124 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 125 "data/maps/MossdeepCity/scripts.pory"

# 126 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_GruntFaceSpaceCenter:
# 127 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 128 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 129 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 130 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 131 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 132 "data/maps/MossdeepCity/scripts.pory"

# 133 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieEnterSpaceCenter:
# 134 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 135 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 136 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 137 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 138 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 139 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 140 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 141 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 142 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 143 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 144 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 145 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 146 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 147 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 148 "data/maps/MossdeepCity/scripts.pory"

# 149 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt1EnterSpaceCenter:
# 150 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 151 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 152 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 153 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 154 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 155 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 156 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 157 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 158 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 159 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 160 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 161 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 162 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 163 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 164 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 165 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 166 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 167 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 168 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 169 "data/maps/MossdeepCity/scripts.pory"

# 170 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt2EnterSpaceCenter:
# 171 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 172 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 173 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 174 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 175 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 176 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 177 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 178 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 179 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 180 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 181 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 182 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 183 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 184 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 185 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 186 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 187 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 188 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 189 "data/maps/MossdeepCity/scripts.pory"

# 190 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt3EnterSpaceCenter:
# 191 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 192 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 193 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 194 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 195 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 196 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 197 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 198 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 199 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 200 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 201 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 202 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 203 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 204 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 205 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 206 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 207 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 208 "data/maps/MossdeepCity/scripts.pory"

# 209 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt4EnterSpaceCenter:
# 210 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 211 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 212 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 213 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 214 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 215 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 216 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 217 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 218 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 219 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 220 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 221 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 222 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 223 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 224 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 225 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 226 "data/maps/MossdeepCity/scripts.pory"

# 227 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Man::
# 228 "data/maps/MossdeepCity/scripts.pory"
	lock
# 229 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 230 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
# 231 "data/maps/MossdeepCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 232 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 233 "data/maps/MossdeepCity/scripts.pory"
	release
# 234 "data/maps/MossdeepCity/scripts.pory"
	end
# 235 "data/maps/MossdeepCity/scripts.pory"

# 236 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_KingsRockBoy::
# 237 "data/maps/MossdeepCity/scripts.pory"
	lock
# 238 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 239 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
# 240 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
# 241 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
# 242 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
# 243 "data/maps/MossdeepCity/scripts.pory"
	giveitem ITEM_KINGS_ROCK
# 244 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 245 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_RECEIVED_KINGS_ROCK
# 246 "data/maps/MossdeepCity/scripts.pory"
	release
# 247 "data/maps/MossdeepCity/scripts.pory"
	end
# 248 "data/maps/MossdeepCity/scripts.pory"

# 249 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ReceivedKingsRock::
# 250 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
# 251 "data/maps/MossdeepCity/scripts.pory"
	release
# 252 "data/maps/MossdeepCity/scripts.pory"
	end
# 253 "data/maps/MossdeepCity/scripts.pory"

# 254 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_DeclineKingsRock::
# 255 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
# 256 "data/maps/MossdeepCity/scripts.pory"
	release
# 257 "data/maps/MossdeepCity/scripts.pory"
	end
# 258 "data/maps/MossdeepCity/scripts.pory"

# 259 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_BlackBelt::
# 260 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
# 261 "data/maps/MossdeepCity/scripts.pory"
	end
# 262 "data/maps/MossdeepCity/scripts.pory"

# 263 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Scott::
# 264 "data/maps/MossdeepCity/scripts.pory"
	lock
# 265 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 266 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
# 267 "data/maps/MossdeepCity/scripts.pory"
	closemessage
# 268 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
# 269 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
# 270 "data/maps/MossdeepCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 271 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_SCOTT
# 272 "data/maps/MossdeepCity/scripts.pory"
	release
# 273 "data/maps/MossdeepCity/scripts.pory"
	end
# 274 "data/maps/MossdeepCity/scripts.pory"

# 275 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitNorth::
# 276 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 277 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
# 278 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 279 "data/maps/MossdeepCity/scripts.pory"
	return
# 280 "data/maps/MossdeepCity/scripts.pory"

# 281 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitEast::
# 282 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 283 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
# 284 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 285 "data/maps/MossdeepCity/scripts.pory"
	return
# 286 "data/maps/MossdeepCity/scripts.pory"

# 287 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_PlayerWatchScottExit:
# 288 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 289 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 290 "data/maps/MossdeepCity/scripts.pory"
	walk_in_place_faster_left
# 291 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 292 "data/maps/MossdeepCity/scripts.pory"

# 293 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitNorth:
# 294 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 295 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 296 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 297 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 298 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 299 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 300 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 301 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 302 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 303 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 304 "data/maps/MossdeepCity/scripts.pory"

# 305 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitEast:
# 306 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 307 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 308 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 309 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 310 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 311 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 312 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 313 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 314 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 315 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 316 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 317 "data/maps/MossdeepCity/scripts.pory"

# 318 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WantKingsRockStevenGaveMe:
# 319 "data/maps/MossdeepCity/scripts.pory"
	.string "I got this from Steven, but I don't\n"
# 320 "data/maps/MossdeepCity/scripts.pory"
	.string "know what it's good for.\p"
# 321 "data/maps/MossdeepCity/scripts.pory"
	.string "I think it's called King's Rock.\n"
# 322 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you want it?$"
# 323 "data/maps/MossdeepCity/scripts.pory"

# 324 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_YouCanKeepIt:
# 325 "data/maps/MossdeepCity/scripts.pory"
	.string "Why would you want it?\n"
# 326 "data/maps/MossdeepCity/scripts.pory"
	.string "You're weird.\p"
# 327 "data/maps/MossdeepCity/scripts.pory"
	.string "You can keep it, but keep it a secret\n"
# 328 "data/maps/MossdeepCity/scripts.pory"
	.string "from Steven.$"
# 329 "data/maps/MossdeepCity/scripts.pory"

# 330 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_StevensHouseOverThere:
# 331 "data/maps/MossdeepCity/scripts.pory"
	.string "Steven's house is right over there!$"
# 332 "data/maps/MossdeepCity/scripts.pory"

# 333 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WhatToDoWithWeirdRock:
# 334 "data/maps/MossdeepCity/scripts.pory"
	.string "Yeah, you think so, too! What are you\n"
# 335 "data/maps/MossdeepCity/scripts.pory"
	.string "supposed to do with some weird rock?$"
# 336 "data/maps/MossdeepCity/scripts.pory"

# 337 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WailmerWatching:
# 338 "data/maps/MossdeepCity/scripts.pory"
	.string "Around Mossdeep, you can see wild\n"
# 339 "data/maps/MossdeepCity/scripts.pory"
	.string "Wailmer.\p"
# 340 "data/maps/MossdeepCity/scripts.pory"
	.string "It's called, uh…\n"
# 341 "data/maps/MossdeepCity/scripts.pory"
	.string "What was it now…\p"
# 342 "data/maps/MossdeepCity/scripts.pory"
	.string "Wai, Wai, Wai…\p"
# 343 "data/maps/MossdeepCity/scripts.pory"
	.string "Wailmer-watching!$"
# 344 "data/maps/MossdeepCity/scripts.pory"

# 345 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterReceivedLetter:
# 346 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's Space Center has been\n"
# 347 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.\p"
# 348 "data/maps/MossdeepCity/scripts.pory"
	.string "There's been some kind of an uproar\n"
# 349 "data/maps/MossdeepCity/scripts.pory"
	.string "over a letter they received recently.$"
# 350 "data/maps/MossdeepCity/scripts.pory"

# 351 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterLaunchingRockets:
# 352 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's Space Center has been\n"
# 353 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.$"
# 354 "data/maps/MossdeepCity/scripts.pory"

# 355 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_MossdeepTargetedByMagma:
# 356 "data/maps/MossdeepCity/scripts.pory"
	.string "I heard from a Sailor buddy that\n"
# 357 "data/maps/MossdeepCity/scripts.pory"
	.string "Team Aqua set up shop in Lilycove.\p"
# 358 "data/maps/MossdeepCity/scripts.pory"
	.string "I also heard that someone came along\n"
# 359 "data/maps/MossdeepCity/scripts.pory"
	.string "and wiped the floor with them!\p"
# 360 "data/maps/MossdeepCity/scripts.pory"
	.string "But Mossdeep here's been targeted\n"
# 361 "data/maps/MossdeepCity/scripts.pory"
	.string "by that Team Magma.\p"
# 362 "data/maps/MossdeepCity/scripts.pory"
	.string "If you want to know what they're up to,\n"
# 363 "data/maps/MossdeepCity/scripts.pory"
	.string "go visit the Space Center.$"
# 364 "data/maps/MossdeepCity/scripts.pory"

# 365 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_FeelReliefOnLand:
# 366 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm a Sailor, so the sea's obviously\n"
# 367 "data/maps/MossdeepCity/scripts.pory"
	.string "more important to me.\p"
# 368 "data/maps/MossdeepCity/scripts.pory"
	.string "But you know? When I get back on land\n"
# 369 "data/maps/MossdeepCity/scripts.pory"
	.string "after a long voyage, I do feel relief!$"
# 370 "data/maps/MossdeepCity/scripts.pory"

# 371 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
# 372 "data/maps/MossdeepCity/scripts.pory"
	.string "Wouldn't it be nice?\p"
# 373 "data/maps/MossdeepCity/scripts.pory"
	.string "If the whole world was covered in\n"
# 374 "data/maps/MossdeepCity/scripts.pory"
	.string "plants and flowers like this island?$"
# 375 "data/maps/MossdeepCity/scripts.pory"

# 376 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_LifeNeedsSeaToLive:
# 377 "data/maps/MossdeepCity/scripts.pory"
	.string "All life needs the sea to live, even\n"
# 378 "data/maps/MossdeepCity/scripts.pory"
	.string "though it makes its home on the land.\p"
# 379 "data/maps/MossdeepCity/scripts.pory"
	.string "Life, having run its course, becomes\n"
# 380 "data/maps/MossdeepCity/scripts.pory"
	.string "soil and returns to the land.\p"
# 381 "data/maps/MossdeepCity/scripts.pory"
	.string "And the sea is always connected to\n"
# 382 "data/maps/MossdeepCity/scripts.pory"
	.string "the land.\p"
# 383 "data/maps/MossdeepCity/scripts.pory"
	.string "Yes, like the very shoreline here.$"
# 384 "data/maps/MossdeepCity/scripts.pory"

# 385 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SurfExhilarating:
# 386 "data/maps/MossdeepCity/scripts.pory"
	.string "A voyage on a ship is fine.\p"
# 387 "data/maps/MossdeepCity/scripts.pory"
	.string "But crossing the sea with Pokémon\n"
# 388 "data/maps/MossdeepCity/scripts.pory"
	.string "using Surf…\p"
# 389 "data/maps/MossdeepCity/scripts.pory"
	.string "Now that's an exhilarating trip!\n"
# 390 "data/maps/MossdeepCity/scripts.pory"
	.string "Wouldn't you agree, youngster?$"
# 391 "data/maps/MossdeepCity/scripts.pory"

# 392 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpecialSpaceCenterRock:
# 393 "data/maps/MossdeepCity/scripts.pory"
	.string "This rock has a special meaning to\n"
# 394 "data/maps/MossdeepCity/scripts.pory"
	.string "the people at the Space Center.\p"
# 395 "data/maps/MossdeepCity/scripts.pory"
	.string "They put it here as their wish for\n"
# 396 "data/maps/MossdeepCity/scripts.pory"
	.string "their rockets to fly safely.\p"
# 397 "data/maps/MossdeepCity/scripts.pory"
	.string "When you make a wish, what do you use?\n"
# 398 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you wish upon a star?\p"
# 399 "data/maps/MossdeepCity/scripts.pory"
	.string "I use a wish tag to make it happen.\n"
# 400 "data/maps/MossdeepCity/scripts.pory"
	.string "That's what I do.$"
# 401 "data/maps/MossdeepCity/scripts.pory"

# 402 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ItsAWhiteRock:
# 403 "data/maps/MossdeepCity/scripts.pory"
	.string "It's a white rock.$"
# 404 "data/maps/MossdeepCity/scripts.pory"

# 405 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_GymSign:
# 406 "data/maps/MossdeepCity/scripts.pory"
	.string "Mossdeep City Pokémon Gym\n"
# 407 "data/maps/MossdeepCity/scripts.pory"
	.string "Leaders: Liza & Tate\p"
# 408 "data/maps/MossdeepCity/scripts.pory"
	.string "“The mystic combination!”$"
# 409 "data/maps/MossdeepCity/scripts.pory"

# 410 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_CitySign:
# 411 "data/maps/MossdeepCity/scripts.pory"
	.string "Mossdeep City\n"
# 412 "data/maps/MossdeepCity/scripts.pory"
	.string "“Our slogan: Cherish Pokémon!”$"
# 413 "data/maps/MossdeepCity/scripts.pory"

# 414 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterSign:
# 415 "data/maps/MossdeepCity/scripts.pory"
	.string "Mossdeep Space Center\n"
# 416 "data/maps/MossdeepCity/scripts.pory"
	.string "“The closest place to space.”$"
# 417 "data/maps/MossdeepCity/scripts.pory"

# 418 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ScottSomethingWrongWithTown:
# 419 "data/maps/MossdeepCity/scripts.pory"
	.string "Scott: {PLAYER}{KUN}, feeling good?\n"
# 420 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm doing great!\p"
# 421 "data/maps/MossdeepCity/scripts.pory"
	.string "I'd heard Mossdeep's Gym Leader is\n"
# 422 "data/maps/MossdeepCity/scripts.pory"
	.string "pretty strong, so I decided to come\l"
# 423 "data/maps/MossdeepCity/scripts.pory"
	.string "take a look-see for myself.\p"
# 424 "data/maps/MossdeepCity/scripts.pory"
	.string "But there's something wrong about\n"
# 425 "data/maps/MossdeepCity/scripts.pory"
	.string "this town.\p"
# 426 "data/maps/MossdeepCity/scripts.pory"
	.string "People are going on about a warning\n"
# 427 "data/maps/MossdeepCity/scripts.pory"
	.string "letter and the Space Center…\p"
# 428 "data/maps/MossdeepCity/scripts.pory"
	.string "I don't think it concerns me in any\n"
# 429 "data/maps/MossdeepCity/scripts.pory"
	.string "way, though.$"
# 430 "data/maps/MossdeepCity/scripts.pory"

# 431 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SootopolisNewGymLeader:
# 432 "data/maps/MossdeepCity/scripts.pory"
	.string "Ahh… It feels great letting the waves\n"
# 433 "data/maps/MossdeepCity/scripts.pory"
	.string "wash over my feet…\p"
# 434 "data/maps/MossdeepCity/scripts.pory"
	.string "Speaking of the waves, you know that\n"
# 435 "data/maps/MossdeepCity/scripts.pory"
	.string "island city Sootopolis?\p"
# 436 "data/maps/MossdeepCity/scripts.pory"
	.string "I think the Gym there had a new\n"
# 437 "data/maps/MossdeepCity/scripts.pory"
	.string "Leader come in.\p"
# 438 "data/maps/MossdeepCity/scripts.pory"
	.string "People tell me the new Leader once\n"
# 439 "data/maps/MossdeepCity/scripts.pory"
	.string "mentored Wallace.$"

MossdeepCity_EventScript_DeoxysScientist::
# 444 "data/maps/MossdeepCity/scripts.pory"
	lock
# 445 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 446 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_DeoxysScientist
# 447 "data/maps/MossdeepCity/scripts.pory"
	closemessage
# 448 "data/maps/MossdeepCity/scripts.pory"
	giveitem ITEM_AURORA_TICKET
# 449 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 450 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_RECEIVED_AURORA_TICKET
# 451 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
# 452 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_DeoxysScientistExit
# 453 "data/maps/MossdeepCity/scripts.pory"
	closemessage
# 454 "data/maps/MossdeepCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 455 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_TEMP_1, 23
	goto_if_eq MossdeepCity_EventScript_DeoxysScientist_2
MossdeepCity_EventScript_DeoxysScientist_1:
# 459 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_DEOXYS_SCIENTIST, MossdeepCity_Movement_DeoxysScientist
# 460 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 461 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_DEOXYS_SCIENTIST
# 462 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_HIDE_DEOXYS_SCIENTIST
# 463 "data/maps/MossdeepCity/scripts.pory"
	release
	end

MossdeepCity_EventScript_DeoxysScientist_2:
# 456 "data/maps/MossdeepCity/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerStepAside
# 457 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
	goto MossdeepCity_EventScript_DeoxysScientist_1


# 482 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_DeoxysScientist:
# 483 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 484 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 485 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 486 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 487 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 488 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 489 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 490 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 491 "data/maps/MossdeepCity/scripts.pory"
	walk_fast_up
# 492 "data/maps/MossdeepCity/scripts.pory"
	walk_fast_up
# 493 "data/maps/MossdeepCity/scripts.pory"
	walk_fast_up
# 494 "data/maps/MossdeepCity/scripts.pory"
	walk_fast_up
# 495 "data/maps/MossdeepCity/scripts.pory"
	walk_fast_up
# 496 "data/maps/MossdeepCity/scripts.pory"
	walk_fast_up
# 497 "data/maps/MossdeepCity/scripts.pory"
	walk_fast_up
	step_end

# 500 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_PlayerStepAside:
# 501 "data/maps/MossdeepCity/scripts.pory"
	walk_fast_left
# 502 "data/maps/MossdeepCity/scripts.pory"
	face_right
	step_end

MossdeepCity_EventScript_WhiteRockDeoxys::
# 506 "data/maps/MossdeepCity/scripts.pory"
	lockall
# 507 "data/maps/MossdeepCity/scripts.pory"
	checkspecies SPECIES_DEOXYS
# 508 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_EventScript_WhiteRockDeoxys_2
MossdeepCity_EventScript_WhiteRockDeoxys_1:
# 522 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WhiteRock_DeoxysGlow, MSGBOX_YESNO
# 523 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MossdeepCity_EventScript_WhiteRockDeoxys_5
MossdeepCity_EventScript_WhiteRockDeoxys_4:
# 550 "data/maps/MossdeepCity/scripts.pory"
	releaseall
	end

MossdeepCity_EventScript_WhiteRockDeoxys_2:
# 509 "data/maps/MossdeepCity/scripts.pory"
	checkspecies SPECIES_DEOXYS_ATTACK
# 510 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_EventScript_WhiteRockDeoxys_7
	goto MossdeepCity_EventScript_WhiteRockDeoxys_1

MossdeepCity_EventScript_WhiteRockDeoxys_5:
# 524 "data/maps/MossdeepCity/scripts.pory"
	special ChoosePartyMon
# 525 "data/maps/MossdeepCity/scripts.pory"
	waitstate
# 526 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq MossdeepCity_EventScript_WhiteRockDeoxys_10
MossdeepCity_EventScript_WhiteRockDeoxys_9:
# 529 "data/maps/MossdeepCity/scripts.pory"
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
# 530 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, SPECIES_DEOXYS
	goto_if_ne MossdeepCity_EventScript_WhiteRockDeoxys_17
MossdeepCity_EventScript_WhiteRockDeoxys_14:
# 538 "data/maps/MossdeepCity/scripts.pory"
	message MossdeepCity_EventScript_WhiteRockDeoxys_Text_1
# 539 "data/maps/MossdeepCity/scripts.pory"
	waitmessage
# 540 "data/maps/MossdeepCity/scripts.pory"
	multichoice 0, 0, MULTI_DEOXYS_FORM, FALSE
# 541 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq MossdeepCity_EventScript_WhiteRockDeoxys_26
MossdeepCity_EventScript_WhiteRockDeoxys_25:
# 544 "data/maps/MossdeepCity/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 545 "data/maps/MossdeepCity/scripts.pory"
	special DeoxysFormChange
# 546 "data/maps/MossdeepCity/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 547 "data/maps/MossdeepCity/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 548 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WhiteRock_DeoxysChanged
	goto MossdeepCity_EventScript_WhiteRockDeoxys_4

MossdeepCity_EventScript_WhiteRockDeoxys_7:
# 511 "data/maps/MossdeepCity/scripts.pory"
	checkspecies SPECIES_DEOXYS_DEFENSE
# 512 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_EventScript_WhiteRockDeoxys_12
	goto MossdeepCity_EventScript_WhiteRockDeoxys_1

MossdeepCity_EventScript_WhiteRockDeoxys_10:
# 527 "data/maps/MossdeepCity/scripts.pory"
	goto MossdeepCity_EventScript_WhiteRock_Cancel
	goto MossdeepCity_EventScript_WhiteRockDeoxys_9

MossdeepCity_EventScript_WhiteRockDeoxys_12:
# 513 "data/maps/MossdeepCity/scripts.pory"
	checkspecies SPECIES_DEOXYS_SPEED
# 514 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MossdeepCity_EventScript_WhiteRockDeoxys_23
	goto MossdeepCity_EventScript_WhiteRockDeoxys_1

MossdeepCity_EventScript_WhiteRockDeoxys_15:
# 534 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_EventScript_WhiteRockDeoxys_Text_0
# 535 "data/maps/MossdeepCity/scripts.pory"
	releaseall
	end

MossdeepCity_EventScript_WhiteRockDeoxys_16:
# 532 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, SPECIES_DEOXYS_DEFENSE
	goto_if_ne MossdeepCity_EventScript_WhiteRockDeoxys_20
	goto MossdeepCity_EventScript_WhiteRockDeoxys_14

MossdeepCity_EventScript_WhiteRockDeoxys_17:
# 531 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, SPECIES_DEOXYS_ATTACK
	goto_if_ne MossdeepCity_EventScript_WhiteRockDeoxys_16
	goto MossdeepCity_EventScript_WhiteRockDeoxys_14

MossdeepCity_EventScript_WhiteRockDeoxys_20:
# 533 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, SPECIES_DEOXYS_SPEED
	goto_if_ne MossdeepCity_EventScript_WhiteRockDeoxys_15
	goto MossdeepCity_EventScript_WhiteRockDeoxys_14

MossdeepCity_EventScript_WhiteRockDeoxys_23:
# 515 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
# 516 "data/maps/MossdeepCity/scripts.pory"
	releaseall
	end

MossdeepCity_EventScript_WhiteRockDeoxys_26:
# 542 "data/maps/MossdeepCity/scripts.pory"
	goto MossdeepCity_EventScript_WhiteRock_Cancel
	goto MossdeepCity_EventScript_WhiteRockDeoxys_25


MossdeepCity_EventScript_WhiteRock_Cancel::
# 555 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WhiteRock_Cancel
# 556 "data/maps/MossdeepCity/scripts.pory"
	releaseall
	end


MossdeepCity_EventScript_WhiteRockDeoxys_Text_0:
# 534 "data/maps/MossdeepCity/scripts.pory"
	.string "The rock's glow fades...\nIt doesn't seem to react.$"

MossdeepCity_EventScript_WhiteRockDeoxys_Text_1:
# 538 "data/maps/MossdeepCity/scripts.pory"
	.string "Which form should it take?$"

MossdeepCity_Text_DeoxysScientist::
# 468 "data/maps/MossdeepCity/scripts.pory"
	.string "Whew!\p"
	.string "Thank you for clearing those thugs\n"
	.string "out of the Space Center.\p"
	.string "They nearly disrupted a very delicate\n"
	.string "delivery from the Kanto region.\p"
	.string "It's a special pass meant\n"
	.string "for a top-tier Trainer.\p"
	.string "After seeing you handle Maxie,\n"
	.string "I think it belongs in your hands.$"

MossdeepCity_Text_DeoxysScientistExit::
# 476 "data/maps/MossdeepCity/scripts.pory"
	.string "I need to get back to the Space Center\n"
	.string "to recalibrate our equipment,\p"
	.string "but once the harbor is open again,\n"
	.string "you should go there immediately!\p"
	.string "That Aurora Ticket is a rare find;\n"
	.string "don't let it go to waste!$"

MossdeepCity_Text_WhiteRock_DeoxysGlow::
# 560 "data/maps/MossdeepCity/scripts.pory"
	.string "The white rock is glowing with a faint,\n"
	.string "purple light!\p"
	.string "Would you like to bring a Pokémon closer\n"
	.string "to the rock?$"

MossdeepCity_Text_WhiteRock_DeoxysChanged::
# 565 "data/maps/MossdeepCity/scripts.pory"
	.string "Deoxys reacted to the cosmic energy of\n"
	.string "the rock and changed its form!$"

MossdeepCity_Text_WhiteRock_Cancel::
# 569 "data/maps/MossdeepCity/scripts.pory"
	.string "The glowing light faded away...$"
