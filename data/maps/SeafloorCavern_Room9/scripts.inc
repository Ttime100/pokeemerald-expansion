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
	waitstate
# 36 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
# 37 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special WaitWeather
# 38 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 39 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_RESULT, 1
# 40 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_M_DETECT
# 41 "data/maps/SeafloorCavern_Room9/scripts.pory"
	dofieldeffectsparkle 16, 42, 0
# 42 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 43 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 44 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_RESULT, 0
# 45 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playfanfare MUS_AWAKEN_LEGEND
# 46 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_ORB
# 47 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special DoOrbEffect
# 48 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
# 49 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 50 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 51 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 150
# 52 "data/maps/SeafloorCavern_Room9/scripts.pory"
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE_SLEEPING
# 53 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
# 54 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 55 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 60
# 56 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
# 57 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 58 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special FadeOutOrbEffect
# 59 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 60 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 61 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 62 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 63 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 64 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special ShakeCamera
# 65 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 66 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
# 67 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 68 "data/maps/SeafloorCavern_Room9/scripts.pory"
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
# 69 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 4
# 70 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, 2  @ vertical pan
# 71 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 72 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 73 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 74 "data/maps/SeafloorCavern_Room9/scripts.pory"
	special ShakeCamera
# 75 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 76 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 30
# 77 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
# 78 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
# 79 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
# 80 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
# 81 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
# 82 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_PC_LOGIN
# 83 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 84 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 85 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
# 86 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 87 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
# 88 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 89 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
# 90 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 91 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_PC_OFF
# 92 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay 20
# 93 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
# 94 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 95 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
# 96 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 97 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8005
# 98 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8006
# 99 "data/maps/SeafloorCavern_Room9/scripts.pory"
	addobject VAR_0x8007
# 100 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
# 101 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
# 102 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
# 103 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 104 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
# 105 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 106 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
# 107 "data/maps/SeafloorCavern_Room9/scripts.pory"
	playse SE_PIN
# 108 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
# 109 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 110 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, Common_Movement_Delay48
# 111 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 112 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
# 113 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
# 114 "data/maps/SeafloorCavern_Room9/scripts.pory"
	closemessage
# 115 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
# 116 "data/maps/SeafloorCavern_Room9/scripts.pory"
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
# 117 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitmovement 0
# 118 "data/maps/SeafloorCavern_Room9/scripts.pory"
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
# 119 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_ROUTE128_STATE, 1
# 120 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
# 121 "data/maps/SeafloorCavern_Room9/scripts.pory"
    setflag FLAG_DEFEAT_ARCHIE
# 122 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
# 123 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
# 124 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
# 125 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
# 126 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
# 127 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
# 128 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
# 129 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 130 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
# 131 "data/maps/SeafloorCavern_Room9/scripts.pory"
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
# 132 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_SYS_WEATHER_CTRL
# 133 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
# 134 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
# 135 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_STEVENS_HOUSE_STATE, 2
# 136 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
# 137 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
# 138 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
# 139 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
# 140 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
# 141 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
# 142 "data/maps/SeafloorCavern_Room9/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 143 "data/maps/SeafloorCavern_Room9/scripts.pory"
	warp MAP_ROUTE128, 38, 22
# 144 "data/maps/SeafloorCavern_Room9/scripts.pory"
	waitstate
# 145 "data/maps/SeafloorCavern_Room9/scripts.pory"
	releaseall
# 146 "data/maps/SeafloorCavern_Room9/scripts.pory"
	end
# 147 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 148 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
# 149 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 150 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 151 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 152 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 153 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 154 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 155 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 156 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 157 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 158 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_Unused1:
# 159 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_left
# 160 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_left
# 161 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 162 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 163 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_ArchieListenMessage:
# 164 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_left
# 165 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 166 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 167 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 168 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_Unused2:
# 169 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 170 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 171 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 172 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_ArchieExit:
# 173 "data/maps/SeafloorCavern_Room9/scripts.pory"
	face_up
# 174 "data/maps/SeafloorCavern_Room9/scripts.pory"
	lock_facing_direction
# 175 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_down
# 176 "data/maps/SeafloorCavern_Room9/scripts.pory"
	unlock_facing_direction
# 177 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_in_place_faster_right
# 178 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 179 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 180 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_KyogreApproach:
# 181 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 182 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 183 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_slow_down
# 184 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 185 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 186 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 187 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_slow_down
# 188 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 189 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 190 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 191 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 192 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 193 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_KyogreExit:
# 194 "data/maps/SeafloorCavern_Room9/scripts.pory"
	slide_up
# 195 "data/maps/SeafloorCavern_Room9/scripts.pory"
	slide_up
# 196 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 197 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 198 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_MaxieArrive:
# 199 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 200 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 201 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 202 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 203 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 204 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 205 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 206 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_MaxieExit:
# 207 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 208 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_right
# 209 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 210 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 211 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_MagmaGruntArrive:
# 212 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 213 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 214 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 215 "data/maps/SeafloorCavern_Room9/scripts.pory"
	walk_fast_right
# 216 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 217 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 218 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Movement_Delay32:
# 219 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 220 "data/maps/SeafloorCavern_Room9/scripts.pory"
	delay_16
# 221 "data/maps/SeafloorCavern_Room9/scripts.pory"
	step_end
# 222 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 223 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
# 224 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Hold it right there.$"
# 225 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 226 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieSoItWasYou:
# 227 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Fufufu…\n"
# 228 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "So it was you, after all.$"
# 229 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 230 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
# 231 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Behold!\p"
# 232 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "See how beautiful it is, the sleeping\n"
# 233 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "form of the ancient Pokémon Kyogre!\p"
# 234 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I have waited so long for this day to\n"
# 235 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "come…$"
# 236 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 237 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
# 238 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: It surprises me, how you've\n"
# 239 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "managed to chase me here.\p"
# 240 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "But that's all over now.\p"
# 241 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "For the realization of my dream,\n"
# 242 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "you must disappear now!$"
# 243 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 244 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieDefeat:
# 245 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "What?!\n"
# 246 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I lost to a mere child like you?!$"
# 247 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 248 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
# 249 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Fufufu…\p"
# 250 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I commend you. I must recognize that\n"
# 251 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "you are truly gifted.\p"
# 252 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "But!\n"
# 253 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I have this in my possession!\p"
# 254 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "With this Red Orb, I can make Kyogre…$"
# 255 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 256 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_RedOrbShinesByItself:
# 257 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "The Red Orb suddenly began shining\n"
# 258 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "by itself!$"
# 259 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 260 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
# 261 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: What?!\p"
# 262 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I didn't do anything.\n"
# 263 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Why did the Red Orb…\p"
# 264 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Where did Kyogre go?$"
# 265 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 266 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
# 267 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Hm? It's a message from our\n"
# 268 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "members outside…$"
# 269 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 270 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
# 271 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: Yes, what is it?\p"
# 272 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Hm…\n"
# 273 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "It's raining heavily?\p"
# 274 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Good… That should have happened.\n"
# 275 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "That is why we awakened Kyogre,\l"
# 276 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "to realize Team Aqua's vision of\l"
# 277 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "expanding the sea.\p"
# 278 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "What?!\p"
# 279 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "It's raining far harder than we\n"
# 280 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "envisioned? You're in danger?\p"
# 281 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "That can't be…\n"
# 282 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "That's just not possible…\p"
# 283 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Hold your position and monitor\n"
# 284 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "the situation!$"
# 285 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 286 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
# 287 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: There's something wrong…\p"
# 288 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "The Red Orb is supposed to awaken\n"
# 289 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "and control Kyogre…\p"
# 290 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "But… Why?\n"
# 291 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Why did Kyogre disappear?\p"
# 292 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Why?!$"
# 293 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 294 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
# 295 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Maxie: What have you wrought?\p"
# 296 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie… You've finally awoken Kyogre,\n"
# 297 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "haven't you?\p"
# 298 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "What will happen to the world if this\n"
# 299 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "downpour continues for all eternity?\p"
# 300 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "The world's landmass will drown in\n"
# 301 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "the deepening sea…$"
# 302 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 303 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
# 304 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Archie: W-what?!\n"
# 305 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Don't get all high and mighty with me!\p"
# 306 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Wasn't it you, Team Magma, that\n"
# 307 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "infuriated Groudon?\p"
# 308 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "So long as I have this Red Orb,\n"
# 309 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I should be able to control Kyogre…\p"
# 310 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "I should be able to control it…$"
# 311 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 312 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
# 313 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Maxie: We don't have the time to\n"
# 314 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "argue about it here!\p"
# 315 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Get outside and see for yourself!\p"
# 316 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "See if what you've wrought is the\n"
# 317 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "world that we desired!$"
# 318 "data/maps/SeafloorCavern_Room9/scripts.pory"

# 319 "data/maps/SeafloorCavern_Room9/scripts.pory"
SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
# 320 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "Maxie: {PLAYER}, come on, you have\n"
# 321 "data/maps/SeafloorCavern_Room9/scripts.pory"
	.string "to get out of here, too!$"
