# 1 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 2 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_MapScripts::
# 3 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.byte 0
# 4 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 5 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
# 6 "data/maps/SeafloorCavern_Room9/scripts.pory"
	lockall
# 7 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
# 8 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
# 9 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
# 10 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
# 11 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 12 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 13 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
# 14 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 15 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 16 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
# 17 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 18 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8004
# 19 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 20 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 21 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
# 22 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 23 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
# 24 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
# 25 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 26 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
# 27 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_FacePlayer
# 28 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 29 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
# 30 "data/maps/SeafloorCavern_Room9/scripts.pory"
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
# 31 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
# 32 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setweather WEATHER_NONE
# 33 "data/maps/SeafloorCavern_Room9/scripts.pory"
	doweather
# 34 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special Script_FadeOutMapMusic
# 35 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
# 36 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special WaitWeather
# 37 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_RESULT, 1
# 38 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_M_DETECT
# 39 "data/maps/SeafloorCavern_Room9/scripts.pory"
	dofieldeffectsparkle 16, 42, 0
# 40 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 41 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 42 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_RESULT, 0
# 43 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playfanfare MUS_AWAKEN_LEGEND
# 44 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_ORB
# 45 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special DoOrbEffect
# 46 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
# 47 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 48 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 49 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 150
# 50 "data/maps/SeafloorCavern_Room9/scripts.pory"
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE_SLEEPING
# 51 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
# 52 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 53 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 60
# 54 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
# 55 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 56 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special FadeOutOrbEffect
# 57 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 58 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 59 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 60 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 61 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special ShakeCamera
# 62 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 63 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
# 64 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 65 "data/maps/SeafloorCavern_Room9/scripts.pory"
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
# 66 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 4
# 67 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, 2  @ vertical pan
# 68 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 69 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 70 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 71 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special ShakeCamera
# 72 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 73 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 30
# 74 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
# 75 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
# 76 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
# 77 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
# 78 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
# 79 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_PC_LOGIN
# 80 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 81 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 82 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
# 83 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 84 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
# 85 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 86 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
# 87 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 88 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_PC_OFF
# 89 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 20
# 90 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
# 91 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 92 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
# 93 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 94 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8005
# 95 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8006
# 96 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8007
# 97 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
# 98 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
# 99 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
# 100 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 101 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
# 102 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 103 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
# 104 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_PIN
# 105 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
# 106 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 107 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_Delay48
# 108 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 109 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
# 110 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
# 111 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 112 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
# 113 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
# 114 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 115 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
# 116 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_ROUTE128_STATE, 1
# 117 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
# 118 "data/maps/SeafloorCavern_Room9/scripts.pory"
    setflag FLAG_DEFEAT_ARCHIE
# 119 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
# 120 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
# 121 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
# 122 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
# 123 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
# 124 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
# 125 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
# 126 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 127 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
# 128 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
# 129 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_SYS_WEATHER_CTRL
# 130 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
# 131 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
# 132 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_STEVENS_HOUSE_STATE, 2
# 133 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
# 134 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
# 135 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
# 136 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
# 137 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
# 138 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
# 139 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 140 "data/maps/SeafloorCavern_Room9/scripts.pory"
	warp MAP_ROUTE128, 38, 22
# 141 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 142 "data/maps/SeafloorCavern_Room9/scripts.pory"
	releaseall
# 143 "data/maps/SeafloorCavern_Room9/scripts.pory"
	end
# 144 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 145 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
# 146 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 147 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 148 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 149 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 150 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 151 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 152 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 153 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 154 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 155 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_Unused1:
# 156 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_left
# 157 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_left
# 158 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 159 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 160 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_ArchieListenMessage:
# 161 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_left
# 162 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 163 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 164 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 165 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_Unused2:
# 166 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 167 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 168 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 169 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_ArchieExit:
# 170 "data/maps/SeafloorCavern_Room9/scripts.pory"
	face_up
# 171 "data/maps/SeafloorCavern_Room9/scripts.pory"
	lock_facing_direction
# 172 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_down
# 173 "data/maps/SeafloorCavern_Room9/scripts.pory"
	unlock_facing_direction
# 174 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_in_place_faster_right
# 175 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 176 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 177 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_KyogreApproach:
# 178 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 179 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 180 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_slow_down
# 181 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 182 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 183 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 184 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_slow_down
# 185 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 186 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 187 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 188 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 189 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 190 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_KyogreExit:
# 191 "data/maps/SeafloorCavern_Room9/scripts.pory"
	slide_up
# 192 "data/maps/SeafloorCavern_Room9/scripts.pory"
	slide_up
# 193 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 194 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 195 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_MaxieArrive:
# 196 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 197 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 198 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 199 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 200 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 201 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 202 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 203 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_MaxieExit:
# 204 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 205 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 206 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 207 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 208 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_MagmaGruntArrive:
# 209 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 210 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 211 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 212 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 213 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 214 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 215 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_Delay32:
# 216 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 217 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 218 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 219 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 220 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
# 221 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Hold it right there.$"
# 222 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 223 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieSoItWasYou:
# 224 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Fufufu…\n"
# 225 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "So it was you, after all.$"
# 226 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 227 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
# 228 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Behold!\p"
# 229 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "See how beautiful it is, the sleeping\n"
# 230 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "form of the ancient Pokémon Kyogre!\p"
# 231 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I have waited so long for this day to\n"
# 232 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "come…$"
# 233 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 234 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
# 235 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: It surprises me, how you've\n"
# 236 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "managed to chase me here.\p"
# 237 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "But that's all over now.\p"
# 238 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "For the realization of my dream,\n"
# 239 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "you must disappear now!$"
# 240 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 241 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieDefeat:
# 242 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "What?!\n"
# 243 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I lost to a mere child like you?!$"
# 244 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 245 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
# 246 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Fufufu…\p"
# 247 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I commend you. I must recognize that\n"
# 248 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "you are truly gifted.\p"
# 249 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "But!\n"
# 250 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I have this in my possession!\p"
# 251 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "With this Red Orb, I can make Kyogre…$"
# 252 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 253 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_RedOrbShinesByItself:
# 254 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "The Red Orb suddenly began shining\n"
# 255 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "by itself!$"
# 256 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 257 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
# 258 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: What?!\p"
# 259 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I didn't do anything.\n"
# 260 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Why did the Red Orb…\p"
# 261 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Where did Kyogre go?$"
# 262 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 263 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
# 264 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Hm? It's a message from our\n"
# 265 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "members outside…$"
# 266 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 267 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
# 268 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Yes, what is it?\p"
# 269 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Hm…\n"
# 270 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "It's raining heavily?\p"
# 271 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Good… That should have happened.\n"
# 272 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "That is why we awakened Kyogre,\l"
# 273 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "to realize Team Aqua's vision of\l"
# 274 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "expanding the sea.\p"
# 275 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "What?!\p"
# 276 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "It's raining far harder than we\n"
# 277 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "envisioned? You're in danger?\p"
# 278 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "That can't be…\n"
# 279 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "That's just not possible…\p"
# 280 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Hold your position and monitor\n"
# 281 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "the situation!$"
# 282 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 283 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
# 284 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: There's something wrong…\p"
# 285 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "The Red Orb is supposed to awaken\n"
# 286 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "and control Kyogre…\p"
# 287 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "But… Why?\n"
# 288 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Why did Kyogre disappear?\p"
# 289 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Why?!$"
# 290 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 291 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
# 292 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Maxie: What have you wrought?\p"
# 293 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie… You've finally awoken Kyogre,\n"
# 294 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "haven't you?\p"
# 295 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "What will happen to the world if this\n"
# 296 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "downpour continues for all eternity?\p"
# 297 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "The world's landmass will drown in\n"
# 298 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "the deepening sea…$"
# 299 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 300 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
# 301 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: W-what?!\n"
# 302 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Don't get all high and mighty with me!\p"
# 303 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Wasn't it you, Team Magma, that\n"
# 304 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "infuriated Groudon?\p"
# 305 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "So long as I have this Red Orb,\n"
# 306 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I should be able to control Kyogre…\p"
# 307 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I should be able to control it…$"
# 308 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 309 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
# 310 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Maxie: We don't have the time to\n"
# 311 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "argue about it here!\p"
# 312 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Get outside and see for yourself!\p"
# 313 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "See if what you've wrought is the\n"
# 314 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "world that we desired!$"
# 315 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 316 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
# 317 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Maxie: {PLAYER}, come on, you have\n"
# 318 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "to get out of here, too!$"
