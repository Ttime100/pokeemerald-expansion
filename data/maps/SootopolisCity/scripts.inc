# 1 "data/maps/SootopolisCity/scripts.pory"

# 2 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_MapScripts::
# 3 "data/maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_OnLoad
# 4 "data/maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_OnTransition
# 5 "data/maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_OnResume
# 6 "data/maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_OnFrame
# 7 "data/maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SootopolisCity_OnWarp
# 8 "data/maps/SootopolisCity/scripts.pory"
	.byte 0
# 9 "data/maps/SootopolisCity/scripts.pory"

# 10 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnLoad:
# 11 "data/maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockGymDoor
# 12 "data/maps/SootopolisCity/scripts.pory"
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_EventScript_LegendariesNotArrived
# 13 "data/maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockHouseDoors
# 14 "data/maps/SootopolisCity/scripts.pory"
	end
# 15 "data/maps/SootopolisCity/scripts.pory"

# 16 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesNotArrived::
# 17 "data/maps/SootopolisCity/scripts.pory"
	end
# 18 "data/maps/SootopolisCity/scripts.pory"

# 19 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LockHouseDoors::
# 20 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 9, 6, METATILE_Sootopolis_Door_Closed, TRUE
# 21 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 9, 17, METATILE_Sootopolis_Door_Closed, TRUE
# 22 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 9, 26, METATILE_Sootopolis_Door_Closed, TRUE
# 23 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 44, 17, METATILE_Sootopolis_Door_Closed, TRUE
# 24 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 8, 35, METATILE_Sootopolis_Door_Closed, TRUE
# 25 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 53, 28, METATILE_Sootopolis_Door_Closed, TRUE
# 26 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 45, 6, METATILE_Sootopolis_Door_Closed, TRUE
# 27 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 48, 25, METATILE_Sootopolis_Door_Closed, TRUE
# 28 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 51, 36, METATILE_Sootopolis_Door_Closed, TRUE
# 29 "data/maps/SootopolisCity/scripts.pory"
	return
# 30 "data/maps/SootopolisCity/scripts.pory"

# 31 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LockGymDoor::
# 32 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 31, 32, METATILE_Sootopolis_GymDoor_Closed, TRUE
# 33 "data/maps/SootopolisCity/scripts.pory"
	return
# 34 "data/maps/SootopolisCity/scripts.pory"

# 35 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnTransition:
# 36 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
# 37 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_HideMapNamePopup
# 38 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_HideMapNamePopup
# 39 "data/maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetWeather
# 40 "data/maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetLayout
# 41 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetBattleSpectators
# 42 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_SetBattleSpectators
# 43 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetBattleSpectators
# 44 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetBattleSpectators
# 45 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_SetBattleSpectators
# 46 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
# 47 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
# 48 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetExitCaveOfOriginObjPos
# 49 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_SetOutsideGymObjPos
# 50 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetExpertBlockCaveEntrance
# 51 "data/maps/SootopolisCity/scripts.pory"
	end
# 52 "data/maps/SootopolisCity/scripts.pory"

# 53 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_HideMapNamePopup::
# 54 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 55 "data/maps/SootopolisCity/scripts.pory"
	return
# 56 "data/maps/SootopolisCity/scripts.pory"

# 57 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetBattleSpectators::
# 58 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_KIRI, 13, 48
# 59 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_BOY_1, 46, 32
# 60 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_NINJA_BOY, 48, 41
# 61 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_WOMAN_1, 45, 43
# 62 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_KIRI, MOVEMENT_TYPE_FACE_UP
# 63 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_BOY_1, MOVEMENT_TYPE_FACE_LEFT
# 64 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_NINJA_BOY, MOVEMENT_TYPE_FACE_LEFT
# 65 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_WOMAN_1, MOVEMENT_TYPE_FACE_LEFT
# 66 "data/maps/SootopolisCity/scripts.pory"
	return
# 67 "data/maps/SootopolisCity/scripts.pory"

# 68 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetLayout::
# 69 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, SootopolisCity_EventScript_SetNormalLayout
# 70 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetNormalLayout
# 71 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetLegendariesLayout
# 72 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_SetLegendariesLayout
# 73 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetLegendariesLayout
# 74 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetLegendariesLayout
# 75 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_SetLegendariesLayout
# 76 "data/maps/SootopolisCity/scripts.pory"
	return
# 77 "data/maps/SootopolisCity/scripts.pory"

# 78 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetNormalLayout::
# 79 "data/maps/SootopolisCity/scripts.pory"
	return
# 80 "data/maps/SootopolisCity/scripts.pory"

# 81 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetLegendariesLayout::
# 82 "data/maps/SootopolisCity/scripts.pory"
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_LEGENDS_BATTLE
# 83 "data/maps/SootopolisCity/scripts.pory"
	return
# 84 "data/maps/SootopolisCity/scripts.pory"

# 85 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWeather::
# 86 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, SootopolisCity_EventScript_SetNormalWeather
# 87 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetNormalWeather
# 88 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetDownpour
# 89 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_SetDownpour
# 90 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SKY_PILLAR_STATE, 1, Common_EventScript_SetAbnormalWeather
# 91 "data/maps/SootopolisCity/scripts.pory"
	return
# 92 "data/maps/SootopolisCity/scripts.pory"

# 93 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetNormalWeather::
# 94 "data/maps/SootopolisCity/scripts.pory"
	return
# 95 "data/maps/SootopolisCity/scripts.pory"

# 96 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetDownpour::
# 97 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_DOWNPOUR
# 98 "data/maps/SootopolisCity/scripts.pory"
	return
# 99 "data/maps/SootopolisCity/scripts.pory"

# 100 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos::
# 101 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos
# 102 "data/maps/SootopolisCity/scripts.pory"
	return
# 103 "data/maps/SootopolisCity/scripts.pory"

# 104 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos::
# 105 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 30, 18
# 106 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 32, 18
# 107 "data/maps/SootopolisCity/scripts.pory"
	return
# 108 "data/maps/SootopolisCity/scripts.pory"

# 109 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetExitCaveOfOriginObjPos::
# 110 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 30, 18
# 111 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 31, 18
# 112 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 32, 18
# 113 "data/maps/SootopolisCity/scripts.pory"
	end
# 114 "data/maps/SootopolisCity/scripts.pory"

# 115 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetOutsideGymObjPos::
# 116 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 31, 18
# 117 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 29, 33
# 118 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_MAXIE, 33, 35
# 119 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_ARCHIE, 34, 35
# 120 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 0, SootopolisCity_EventScript_SetWallaceMiddle
# 121 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 1, SootopolisCity_EventScript_SetWallaceRight
# 122 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 2, SootopolisCity_EventScript_SetWallaceLeft
# 123 "data/maps/SootopolisCity/scripts.pory"
	return
# 124 "data/maps/SootopolisCity/scripts.pory"

# 125 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWallaceMiddle::
# 126 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 31, 33
# 127 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
# 128 "data/maps/SootopolisCity/scripts.pory"
	return
# 129 "data/maps/SootopolisCity/scripts.pory"

# 130 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWallaceRight::
# 131 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 32, 33
# 132 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
# 133 "data/maps/SootopolisCity/scripts.pory"
	return
# 134 "data/maps/SootopolisCity/scripts.pory"

# 135 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWallaceLeft::
# 136 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 30, 33
# 137 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
# 138 "data/maps/SootopolisCity/scripts.pory"
	return
# 139 "data/maps/SootopolisCity/scripts.pory"

# 140 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetExpertBlockCaveEntrance::
# 141 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 31, 18
# 142 "data/maps/SootopolisCity/scripts.pory"
	return
# 143 "data/maps/SootopolisCity/scripts.pory"

# 144 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnWarp:
# 145 "data/maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_PlayerFaceLegendaries
# 146 "data/maps/SootopolisCity/scripts.pory"
	.2byte 0
# 147 "data/maps/SootopolisCity/scripts.pory"

# 148 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries::
# 149 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_PlayerFaceLegendaries1
# 150 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SKY_PILLAR_STATE, 2, SootopolisCity_EventScript_PlayerFaceLegendaries2
# 151 "data/maps/SootopolisCity/scripts.pory"
	end
# 152 "data/maps/SootopolisCity/scripts.pory"

# 153 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries1::
# 154 "data/maps/SootopolisCity/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 155 "data/maps/SootopolisCity/scripts.pory"
	return
# 156 "data/maps/SootopolisCity/scripts.pory"

# 157 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries2::
# 158 "data/maps/SootopolisCity/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 159 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 3
# 160 "data/maps/SootopolisCity/scripts.pory"
	return
# 161 "data/maps/SootopolisCity/scripts.pory"

# 162 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnResume:
# 163 "data/maps/SootopolisCity/scripts.pory"
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 9, 6
# 164 "data/maps/SootopolisCity/scripts.pory"
	end
# 165 "data/maps/SootopolisCity/scripts.pory"

# 166 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnFrame:
# 167 "data/maps/SootopolisCity/scripts.pory"
    map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_StartLegendariesScene
# 168 "data/maps/SootopolisCity/scripts.pory"
    map_script_2 VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_StartRayquazaScene
# 169 "data/maps/SootopolisCity/scripts.pory"
    map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_RoamerCallOnFrame
# 170 "data/maps/SootopolisCity/scripts.pory"
    .2byte 0
# 171 "data/maps/SootopolisCity/scripts.pory"

# 172 "data/maps/SootopolisCity/scripts.pory"
@ If not at PokeCenter, assumed to have arrived via Dive
# 173 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartLegendariesScene::
# 174 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 175 "data/maps/SootopolisCity/scripts.pory"
	special StorePlayerCoordsInVars
# 176 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_LegendariesSceneFromDive
# 177 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_LegendariesSceneFromDive
# 178 "data/maps/SootopolisCity/scripts.pory"
	goto SootopolisCity_EventScript_LegendariesSceneFromPokeCenter
# 179 "data/maps/SootopolisCity/scripts.pory"
	end
# 180 "data/maps/SootopolisCity/scripts.pory"

# 181 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesSceneFromPokeCenter::
# 182 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 183 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 184 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
# 185 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 186 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 187 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 188 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 189 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_ABNORMAL
# 190 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 191 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
# 192 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 193 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
# 194 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
# 195 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 196 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 197 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 198 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 199 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 200 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 201 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 202 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 203 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 204 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 205 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 206 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 207 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 208 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 209 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 210 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 211 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 212 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
# 213 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
# 214 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
# 215 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 216 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 217 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 218 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 219 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 220 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 221 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 222 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 223 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 224 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 225 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 226 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 227 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 228 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 229 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 230 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 231 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 232 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 233 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 234 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 235 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 236 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 237 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 238 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 239 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 240 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
# 241 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
# 242 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToPokeCenter
# 243 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 244 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 245 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
# 246 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 247 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 248 "data/maps/SootopolisCity/scripts.pory"
	end
# 249 "data/maps/SootopolisCity/scripts.pory"

# 250 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanToActionFromPokeCenter:
# 251 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 252 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 253 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 254 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 255 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 256 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 257 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 258 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 259 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 260 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 261 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 262 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 263 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 264 "data/maps/SootopolisCity/scripts.pory"

# 265 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanBackToPokeCenter:
# 266 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 267 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 268 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 269 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 270 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 271 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 272 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 273 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 274 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 275 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 276 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 277 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 278 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 279 "data/maps/SootopolisCity/scripts.pory"

# 280 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesSceneFromDive::
# 281 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 282 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 283 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
# 284 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 285 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 286 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 287 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 288 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_ABNORMAL
# 289 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 290 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
# 291 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 292 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
# 293 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
# 294 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 295 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 296 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 297 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 298 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 299 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 300 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 301 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 302 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 303 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 304 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 305 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 306 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 307 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 308 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 309 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 310 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 311 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
# 312 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
# 313 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
# 314 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 315 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 316 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 317 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 318 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 319 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 320 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 321 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 322 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 323 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 324 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 325 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 326 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 327 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 328 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 329 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 330 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 331 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 332 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 333 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 334 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 335 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 336 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 337 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 338 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 339 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
# 340 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
# 341 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToDive
# 342 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 343 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 344 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
# 345 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 346 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 347 "data/maps/SootopolisCity/scripts.pory"
	end
# 348 "data/maps/SootopolisCity/scripts.pory"

# 349 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanToActionFromDive:
# 350 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 351 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 352 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 353 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 354 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 355 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 356 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 357 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 358 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 359 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 360 "data/maps/SootopolisCity/scripts.pory"

# 361 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanBackToDive:
# 362 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 363 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 364 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 365 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 366 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 367 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 368 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 369 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 370 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 371 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 372 "data/maps/SootopolisCity/scripts.pory"

# 373 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreAttack:
# 374 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 375 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 376 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 377 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 378 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 379 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 380 "data/maps/SootopolisCity/scripts.pory"
	init_affine_anim
# 381 "data/maps/SootopolisCity/scripts.pory"
	walk_left_affine
# 382 "data/maps/SootopolisCity/scripts.pory"
	clear_affine_anim
# 383 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 384 "data/maps/SootopolisCity/scripts.pory"

# 385 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreDefend:
# 386 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 387 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 388 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 389 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 390 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 391 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 392 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 393 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 394 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 395 "data/maps/SootopolisCity/scripts.pory"
	init_affine_anim
# 396 "data/maps/SootopolisCity/scripts.pory"
	walk_left_affine
# 397 "data/maps/SootopolisCity/scripts.pory"
	clear_affine_anim
# 398 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 399 "data/maps/SootopolisCity/scripts.pory"

# 400 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreMoveBack:
# 401 "data/maps/SootopolisCity/scripts.pory"
	lock_facing_direction
# 402 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 403 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 404 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 405 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 406 "data/maps/SootopolisCity/scripts.pory"
	unlock_facing_direction
# 407 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 408 "data/maps/SootopolisCity/scripts.pory"

# 409 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreIdle:
# 410 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 411 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 412 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 413 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 414 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 415 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 416 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 417 "data/maps/SootopolisCity/scripts.pory"

# 418 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonAttack:
# 419 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 420 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 421 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 422 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 423 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 424 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 425 "data/maps/SootopolisCity/scripts.pory"
	walk_fast_right
# 426 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 427 "data/maps/SootopolisCity/scripts.pory"

# 428 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonDefend:
# 429 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 430 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 431 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 432 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 433 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 434 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 435 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 436 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 437 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 438 "data/maps/SootopolisCity/scripts.pory"
	walk_fast_right
# 439 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 440 "data/maps/SootopolisCity/scripts.pory"

# 441 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonMoveBack:
# 442 "data/maps/SootopolisCity/scripts.pory"
	lock_facing_direction
# 443 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 444 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 445 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 446 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 447 "data/maps/SootopolisCity/scripts.pory"
	unlock_facing_direction
# 448 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 449 "data/maps/SootopolisCity/scripts.pory"

# 450 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonIdle:
# 451 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 452 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 453 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 454 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 455 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 456 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 457 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 458 "data/maps/SootopolisCity/scripts.pory"

# 459 "data/maps/SootopolisCity/scripts.pory"
@ If not at PokeCenter, assumed to have arrived via Dive
# 460 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartRayquazaScene::
# 461 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 462 "data/maps/SootopolisCity/scripts.pory"
	special StorePlayerCoordsInVars
# 463 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_RayquazaSceneFromDive
# 464 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_RayquazaSceneFromDive
# 465 "data/maps/SootopolisCity/scripts.pory"
	goto SootopolisCity_EventScript_RayquazaSceneFromPokeCenter
# 466 "data/maps/SootopolisCity/scripts.pory"
	end
# 467 "data/maps/SootopolisCity/scripts.pory"

# 468 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_RayquazaSceneFromPokeCenter::
# 469 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 470 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 471 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
# 472 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 473 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 474 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 475 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 476 "data/maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetRoughWater
# 477 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_GROUDON
# 478 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
# 479 "data/maps/SootopolisCity/scripts.pory"
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 480 "data/maps/SootopolisCity/scripts.pory"
	hideobjectat LOCALID_SOOTOPOLIS_RAYQUAZA, MAP_SOOTOPOLIS_CITY
# 481 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, TRUE
# 482 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 483 "data/maps/SootopolisCity/scripts.pory"
	playse SE_THUNDER
# 484 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 485 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
# 486 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 487 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 488 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 489 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 490 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 491 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 492 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 493 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 494 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 495 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 496 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 497 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 498 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 499 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 500 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 501 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 502 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 503 "data/maps/SootopolisCity/scripts.pory"
	waitmoncry
# 504 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_NONE
# 505 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 506 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
# 507 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 508 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 509 "data/maps/SootopolisCity/scripts.pory"
	special WaitWeather
# 510 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SYS_WEATHER_CTRL
# 511 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 3
# 512 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 513 "data/maps/SootopolisCity/scripts.pory"
	fadenewbgm MUS_SOOTOPOLIS
# 514 "data/maps/SootopolisCity/scripts.pory"
	delay 120
# 515 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 516 "data/maps/SootopolisCity/scripts.pory"
	warpwhitefade MAP_SOOTOPOLIS_CITY, 43, 32
# 517 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 518 "data/maps/SootopolisCity/scripts.pory"
	end
# 519 "data/maps/SootopolisCity/scripts.pory"

# 520 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_RayquazaSceneFromDive::
# 521 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 522 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 523 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
# 524 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 525 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 526 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 527 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 528 "data/maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetRoughWater
# 529 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_GROUDON
# 530 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
# 531 "data/maps/SootopolisCity/scripts.pory"
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 532 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, TRUE
# 533 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 534 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 535 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
# 536 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerApproachLegendaries
# 537 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 538 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 539 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 540 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 541 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 542 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 543 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 544 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 545 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 546 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 547 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 548 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 549 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 550 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 551 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 552 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 553 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 554 "data/maps/SootopolisCity/scripts.pory"
	waitmoncry
# 555 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_NONE
# 556 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 557 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
# 558 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 559 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 560 "data/maps/SootopolisCity/scripts.pory"
	special WaitWeather
# 561 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SYS_WEATHER_CTRL
# 562 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 2
# 563 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 564 "data/maps/SootopolisCity/scripts.pory"
	fadenewbgm MUS_SURF
# 565 "data/maps/SootopolisCity/scripts.pory"
	delay 120
# 566 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 567 "data/maps/SootopolisCity/scripts.pory"
	warpwhitefade MAP_SOOTOPOLIS_CITY, 29, 53
# 568 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 569 "data/maps/SootopolisCity/scripts.pory"
	end
# 570 "data/maps/SootopolisCity/scripts.pory"

# 571 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetRoughWater::
# 572 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 27, 43, METATILE_Sootopolis_RoughWater, FALSE
# 573 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 28, 43, METATILE_Sootopolis_RoughWater, FALSE
# 574 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 29, 43, METATILE_Sootopolis_RoughWater, FALSE
# 575 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 30, 43, METATILE_Sootopolis_RoughWater, FALSE
# 576 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 27, 44, METATILE_Sootopolis_RoughWater, FALSE
# 577 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 28, 44, METATILE_Sootopolis_RoughWater, FALSE
# 578 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 29, 44, METATILE_Sootopolis_RoughWater, FALSE
# 579 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 30, 44, METATILE_Sootopolis_RoughWater, FALSE
# 580 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 27, 45, METATILE_Sootopolis_RoughWater, FALSE
# 581 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 28, 45, METATILE_Sootopolis_RoughWater, FALSE
# 582 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 29, 45, METATILE_Sootopolis_RoughWater, FALSE
# 583 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 30, 45, METATILE_Sootopolis_RoughWater, FALSE
# 584 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 32, 43, METATILE_Sootopolis_RoughWater, FALSE
# 585 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 33, 43, METATILE_Sootopolis_RoughWater, FALSE
# 586 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 34, 43, METATILE_Sootopolis_RoughWater, FALSE
# 587 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 35, 43, METATILE_Sootopolis_RoughWater, FALSE
# 588 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 32, 44, METATILE_Sootopolis_RoughWater, FALSE
# 589 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 33, 44, METATILE_Sootopolis_RoughWater, FALSE
# 590 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 34, 44, METATILE_Sootopolis_RoughWater, FALSE
# 591 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 35, 44, METATILE_Sootopolis_RoughWater, FALSE
# 592 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 32, 45, METATILE_Sootopolis_RoughWater, FALSE
# 593 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 33, 45, METATILE_Sootopolis_RoughWater, FALSE
# 594 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 34, 45, METATILE_Sootopolis_RoughWater, FALSE
# 595 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 35, 45, METATILE_Sootopolis_RoughWater, FALSE
# 596 "data/maps/SootopolisCity/scripts.pory"
	return
# 597 "data/maps/SootopolisCity/scripts.pory"

# 598 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_RayquazaFlyOff:
# 599 "data/maps/SootopolisCity/scripts.pory"
	walk_fast_up
# 600 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 601 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 602 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 603 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 604 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 605 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 606 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 607 "data/maps/SootopolisCity/scripts.pory"

# 608 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanUp:
# 609 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 610 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 611 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 612 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 613 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 614 "data/maps/SootopolisCity/scripts.pory"

# 615 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerApproachLegendaries:
# 616 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 617 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 618 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 619 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 620 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 621 "data/maps/SootopolisCity/scripts.pory"

# 622 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 623 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerApproachLegendariesDown:
# 624 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 625 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 626 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 627 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 628 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 629 "data/maps/SootopolisCity/scripts.pory"

# 630 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 631 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_UnusedPanUp:
# 632 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 633 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 634 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 635 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 636 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 637 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 638 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 639 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 640 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 641 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 642 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 643 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 644 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 645 "data/maps/SootopolisCity/scripts.pory"

# 646 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 647 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_UnusedPanBack:
# 648 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 649 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 650 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 651 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 652 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 653 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 654 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 655 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 656 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 657 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 658 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 659 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 660 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 661 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 662 "data/maps/SootopolisCity/scripts.pory"

# 663 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CaveOfOriginExpert::
# 664 "data/maps/SootopolisCity/scripts.pory"
	lock
# 665 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 666 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ExpertPostLegendaries
# 667 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ExpertLegendaries
# 668 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_ExpertLeadToCave
# 669 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CaveOfOriginPleaseLeave, MSGBOX_DEFAULT
# 670 "data/maps/SootopolisCity/scripts.pory"
	release
# 671 "data/maps/SootopolisCity/scripts.pory"
	end
# 672 "data/maps/SootopolisCity/scripts.pory"

# 673 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertLeadToCave::
# 674 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_LeadSuperiorTrainerToCave, MSGBOX_DEFAULT
# 675 "data/maps/SootopolisCity/scripts.pory"
	release
# 676 "data/maps/SootopolisCity/scripts.pory"
	end
# 677 "data/maps/SootopolisCity/scripts.pory"

# 678 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertPostLegendaries::
# 679 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CaveOfOriginSleepsToo, MSGBOX_DEFAULT
# 680 "data/maps/SootopolisCity/scripts.pory"
	release
# 681 "data/maps/SootopolisCity/scripts.pory"
	end
# 682 "data/maps/SootopolisCity/scripts.pory"

# 683 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertLegendaries::
# 684 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AwakenedPokemonClash, MSGBOX_DEFAULT
# 685 "data/maps/SootopolisCity/scripts.pory"
	release
# 686 "data/maps/SootopolisCity/scripts.pory"
	end
# 687 "data/maps/SootopolisCity/scripts.pory"

# 688 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Kiri::
# 689 "data/maps/SootopolisCity/scripts.pory"
	lock
# 690 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 691 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_KiriGiveBerry
# 692 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_KiriGiveBerry
# 693 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_KiriRayquaza
# 694 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_BigPokemonFighting, MSGBOX_DEFAULT
# 695 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 696 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KIRI, Common_Movement_FaceOriginalDirection
# 697 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 698 "data/maps/SootopolisCity/scripts.pory"
	release
# 699 "data/maps/SootopolisCity/scripts.pory"
	end
# 700 "data/maps/SootopolisCity/scripts.pory"

# 701 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriRayquaza::
# 702 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_PrettyMonCameFromSky, MSGBOX_DEFAULT
# 703 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 704 "data/maps/SootopolisCity/scripts.pory"
	release
# 705 "data/maps/SootopolisCity/scripts.pory"
	end
# 706 "data/maps/SootopolisCity/scripts.pory"

# 707 "data/maps/SootopolisCity/scripts.pory"
@ Gives 2 berries daily. First ranges from BERRY_ID_POMEG to BERRY_ID_NOMEL, second is always Figy or Iapapa
# 708 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriGiveBerry::
# 709 "data/maps/SootopolisCity/scripts.pory"
	dotimebasedevents
# 710 "data/maps/SootopolisCity/scripts.pory"
	special GetPlayerBigGuyGirlString
# 711 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_KiriReceivedBerry
# 712 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NameIsKiriHaveOneOfThese, MSGBOX_DEFAULT
# 713 "data/maps/SootopolisCity/scripts.pory"
	giverandomberry BERRY_ID_POMEG, BERRY_ID_NOMEL
# 714 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 715 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
# 716 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiveYouThisBerryToo, MSGBOX_DEFAULT
# 717 "data/maps/SootopolisCity/scripts.pory"
	random 2
# 718 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SootopolisCity_EventScript_GiveFigyBerry
# 719 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SootopolisCity_EventScript_GiveIapapaBerry
# 720 "data/maps/SootopolisCity/scripts.pory"
	end
# 721 "data/maps/SootopolisCity/scripts.pory"

# 722 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveFigyBerry::
# 723 "data/maps/SootopolisCity/scripts.pory"
	giveitem ITEM_FIGY_BERRY
# 724 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 725 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
# 726 "data/maps/SootopolisCity/scripts.pory"
	release
# 727 "data/maps/SootopolisCity/scripts.pory"
	end
# 728 "data/maps/SootopolisCity/scripts.pory"

# 729 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveIapapaBerry::
# 730 "data/maps/SootopolisCity/scripts.pory"
	giveitem ITEM_IAPAPA_BERRY
# 731 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 732 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
# 733 "data/maps/SootopolisCity/scripts.pory"
	release
# 734 "data/maps/SootopolisCity/scripts.pory"
	end
# 735 "data/maps/SootopolisCity/scripts.pory"

# 736 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriReceivedBerry::
# 737 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_LikeSeasonBornIn, MSGBOX_YESNO
# 738 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SootopolisCity_EventScript_KiriLikeSeasonBornIn
# 739 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_OhDoesntMatter, MSGBOX_DEFAULT
# 740 "data/maps/SootopolisCity/scripts.pory"
	release
# 741 "data/maps/SootopolisCity/scripts.pory"
	end
# 742 "data/maps/SootopolisCity/scripts.pory"

# 743 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriLikeSeasonBornIn::
# 744 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThenILoveAutumn, MSGBOX_DEFAULT
# 745 "data/maps/SootopolisCity/scripts.pory"
	release
# 746 "data/maps/SootopolisCity/scripts.pory"
	end
# 747 "data/maps/SootopolisCity/scripts.pory"

# 748 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman2::
# 749 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 750 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FacePlayer
# 751 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 752 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman2Rayquaza
# 753 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WeatherWentWild, MSGBOX_DEFAULT
# 754 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 755 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FaceOriginalDirection
# 756 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 757 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 758 "data/maps/SootopolisCity/scripts.pory"
	end
# 759 "data/maps/SootopolisCity/scripts.pory"

# 760 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman2Rayquaza::
# 761 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_YouBroughtFlyingMon, MSGBOX_DEFAULT
# 762 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 763 "data/maps/SootopolisCity/scripts.pory"
	end
# 764 "data/maps/SootopolisCity/scripts.pory"

# 765 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Man::
# 766 "data/maps/SootopolisCity/scripts.pory"
	lock
# 767 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 768 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ManPostLegendaries
# 769 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NoOrdinaryTourist, MSGBOX_DEFAULT
# 770 "data/maps/SootopolisCity/scripts.pory"
	release
# 771 "data/maps/SootopolisCity/scripts.pory"
	end
# 772 "data/maps/SootopolisCity/scripts.pory"

# 773 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ManPostLegendaries::
# 774 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CityRegainedCalm, MSGBOX_DEFAULT
# 775 "data/maps/SootopolisCity/scripts.pory"
	release
# 776 "data/maps/SootopolisCity/scripts.pory"
	end
# 777 "data/maps/SootopolisCity/scripts.pory"

# 778 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1::
# 779 "data/maps/SootopolisCity/scripts.pory"
	lock
# 780 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 781 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Woman1PostLegendaries
# 782 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman1Rayquaza
# 783 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_Woman1Legendaries
# 784 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisSkyBeautiful, MSGBOX_DEFAULT
# 785 "data/maps/SootopolisCity/scripts.pory"
	release
# 786 "data/maps/SootopolisCity/scripts.pory"
	end
# 787 "data/maps/SootopolisCity/scripts.pory"

# 788 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1Legendaries::
# 789 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiganticPokemonFight, MSGBOX_DEFAULT
# 790 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 791 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WOMAN_1, Common_Movement_FaceOriginalDirection
# 792 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 793 "data/maps/SootopolisCity/scripts.pory"
	release
# 794 "data/maps/SootopolisCity/scripts.pory"
	end
# 795 "data/maps/SootopolisCity/scripts.pory"

# 796 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1PostLegendaries::
# 797 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NightSkyFavoriteScenery, MSGBOX_DEFAULT
# 798 "data/maps/SootopolisCity/scripts.pory"
	release
# 799 "data/maps/SootopolisCity/scripts.pory"
	end
# 800 "data/maps/SootopolisCity/scripts.pory"

# 801 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1Rayquaza::
# 802 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_FearedWorstWhenPokemonFlewDown, MSGBOX_DEFAULT
# 803 "data/maps/SootopolisCity/scripts.pory"
	release
# 804 "data/maps/SootopolisCity/scripts.pory"
	end
# 805 "data/maps/SootopolisCity/scripts.pory"

# 806 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoy::
# 807 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 808 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FacePlayer
# 809 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 810 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_NinjaBoyRayquaza
# 811 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_NinjaBoyNormal
# 812 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_NinjaBoyNormal
# 813 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThisIsWicked, MSGBOX_DEFAULT
# 814 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 815 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FaceOriginalDirection
# 816 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 817 "data/maps/SootopolisCity/scripts.pory"
	release
# 818 "data/maps/SootopolisCity/scripts.pory"
	end
# 819 "data/maps/SootopolisCity/scripts.pory"

# 820 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoyNormal::
# 821 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WonderWhatWorldIsLike, MSGBOX_DEFAULT
# 822 "data/maps/SootopolisCity/scripts.pory"
	release
# 823 "data/maps/SootopolisCity/scripts.pory"
	end
# 824 "data/maps/SootopolisCity/scripts.pory"

# 825 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoyRayquaza::
# 826 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThatWasWicked, MSGBOX_DEFAULT
# 827 "data/maps/SootopolisCity/scripts.pory"
	release
# 828 "data/maps/SootopolisCity/scripts.pory"
	end
# 829 "data/maps/SootopolisCity/scripts.pory"

# 830 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1::
# 831 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 832 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FacePlayer
# 833 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 834 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy1Rayquaza
# 835 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_EventScript_Boy1GameClear
# 836 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Boy1Normal
# 837 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_Boy1Normal
# 838 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiantPokemonSuddenlyAppeared, MSGBOX_DEFAULT
# 839 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 840 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FaceOriginalDirection
# 841 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 842 "data/maps/SootopolisCity/scripts.pory"
	release
# 843 "data/maps/SootopolisCity/scripts.pory"
	end
# 844 "data/maps/SootopolisCity/scripts.pory"

# 845 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1Rayquaza::
# 846 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatIsThatGreenPokemon, MSGBOX_DEFAULT
# 847 "data/maps/SootopolisCity/scripts.pory"
	release
# 848 "data/maps/SootopolisCity/scripts.pory"
	end
# 849 "data/maps/SootopolisCity/scripts.pory"

# 850 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1GameClear::
# 851 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhereDidLegendariesGo, MSGBOX_DEFAULT
# 852 "data/maps/SootopolisCity/scripts.pory"
	release
# 853 "data/maps/SootopolisCity/scripts.pory"
	end
# 854 "data/maps/SootopolisCity/scripts.pory"

# 855 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1Normal::
# 856 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_PhysicallyFitLivingHere, MSGBOX_DEFAULT
# 857 "data/maps/SootopolisCity/scripts.pory"
	release
# 858 "data/maps/SootopolisCity/scripts.pory"
	end
# 859 "data/maps/SootopolisCity/scripts.pory"

# 860 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GymSign::
# 861 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GymSign, MSGBOX_SIGN
# 862 "data/maps/SootopolisCity/scripts.pory"
	end
# 863 "data/maps/SootopolisCity/scripts.pory"

# 864 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CitySign::
# 865 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CitySign, MSGBOX_SIGN
# 866 "data/maps/SootopolisCity/scripts.pory"
	end
# 867 "data/maps/SootopolisCity/scripts.pory"

# 868 "data/maps/SootopolisCity/scripts.pory"
EventScript_ClosedSootopolisDoor::
# 869 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoorIsClosed, MSGBOX_SIGN
# 870 "data/maps/SootopolisCity/scripts.pory"
	end
# 871 "data/maps/SootopolisCity/scripts.pory"

# 872 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Steven::
# 873 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 874 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, Common_Movement_FacePlayer
# 875 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 876 "data/maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin
# 877 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_StevenHelpWallace
# 878 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_StevenHelpedWallace
# 879 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_StevenHelpedWallace
# 880 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_StevenMaxieArchieLeft
# 881 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SoThatsRayquaza, MSGBOX_DEFAULT
# 882 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 883 "data/maps/SootopolisCity/scripts.pory"
	end
# 884 "data/maps/SootopolisCity/scripts.pory"

# 885 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenHelpWallace::
# 886 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_KnowWhatsNeededToHelpHim, MSGBOX_DEFAULT
# 887 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 888 "data/maps/SootopolisCity/scripts.pory"
	end
# 889 "data/maps/SootopolisCity/scripts.pory"

# 890 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenMaxieArchieLeft::
# 891 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_MaxieArchieLeft, MSGBOX_DEFAULT
# 892 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 893 "data/maps/SootopolisCity/scripts.pory"
	end
# 894 "data/maps/SootopolisCity/scripts.pory"

# 895 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenHelpedWallace::
# 896 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NeverBeenToSkyPillar, MSGBOX_DEFAULT
# 897 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 898 "data/maps/SootopolisCity/scripts.pory"
	end
# 899 "data/maps/SootopolisCity/scripts.pory"

# 900 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin::
# 901 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_InvolvedWithCrisisComeWithMe, MSGBOX_DEFAULT
# 902 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 903 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_StartWalkToCaveOfOriginWest
# 904 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth
# 905 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoesThisMakeYourFearPokemon, MSGBOX_DEFAULT
# 906 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 907 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenWalkToCaveOfOrigin
# 908 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerWalkToCaveOfOrigin
# 909 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 910 "data/maps/SootopolisCity/scripts.pory"
	delay 120
# 911 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_EXPERT, SootopolisCity_Movement_ExpertMoveAside
# 912 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 913 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenArriveCaveEntrance
# 914 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerArriveCaveEntrance
# 915 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 916 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_HereWereAreHelpWallace, MSGBOX_DEFAULT
# 917 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 918 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
# 919 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerEnterCaveOfOrigin
# 920 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 921 "data/maps/SootopolisCity/scripts.pory"
	warp MAP_CAVE_OF_ORIGIN_ENTRANCE, 9, 20
# 922 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 923 "data/maps/SootopolisCity/scripts.pory"
	end
# 924 "data/maps/SootopolisCity/scripts.pory"

# 925 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartWalkToCaveOfOriginWest::
# 926 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
# 927 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest
# 928 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 929 "data/maps/SootopolisCity/scripts.pory"
	return
# 930 "data/maps/SootopolisCity/scripts.pory"

# 931 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth::
# 932 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
# 933 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth
# 934 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 935 "data/maps/SootopolisCity/scripts.pory"
	return
# 936 "data/maps/SootopolisCity/scripts.pory"

# 937 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin:
# 938 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 939 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 940 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 941 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 942 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 943 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 944 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 945 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 946 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 947 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 948 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 949 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 950 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 951 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 952 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 953 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 954 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 955 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 956 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 957 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 958 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 959 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 960 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 961 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 962 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 963 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 964 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 965 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 966 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 967 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 968 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 969 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 970 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 971 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 972 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 973 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 974 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 975 "data/maps/SootopolisCity/scripts.pory"

# 976 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest:
# 977 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 978 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 979 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 980 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 981 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 982 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 983 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 984 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 985 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 986 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 987 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 988 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 989 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 990 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 991 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 992 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 993 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 994 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 995 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 996 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 997 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 998 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 999 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1000 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1001 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1002 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1003 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1004 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1005 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1006 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1007 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1008 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1009 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1010 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1011 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1012 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1013 "data/maps/SootopolisCity/scripts.pory"

# 1014 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth:
# 1015 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1016 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1017 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1018 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1019 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1020 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1021 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1022 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1023 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1024 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1025 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1026 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1027 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1028 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1029 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1030 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1031 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1032 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1033 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1034 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1035 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1036 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1037 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1038 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1039 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1040 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1041 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1042 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1043 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1044 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1045 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1046 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1047 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1048 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1049 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1050 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1051 "data/maps/SootopolisCity/scripts.pory"

# 1052 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenWalkToCaveOfOrigin:
# 1053 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1054 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1055 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1056 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1057 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1058 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1059 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1060 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1061 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1062 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1063 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1064 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1065 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1066 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1067 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1068 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1069 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1070 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1071 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1072 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1073 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1074 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1075 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1076 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1077 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1078 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1079 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1080 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1081 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1082 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1083 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1084 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1085 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1086 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1087 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1088 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1089 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1090 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1091 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1092 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1093 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1094 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1095 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1096 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1097 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1098 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1099 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1100 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1101 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1102 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1103 "data/maps/SootopolisCity/scripts.pory"
	delay_4
# 1104 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_left
# 1105 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1106 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1107 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1108 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1109 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1110 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1111 "data/maps/SootopolisCity/scripts.pory"

# 1112 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerWalkToCaveOfOrigin:
# 1113 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1114 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1115 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1116 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1117 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1118 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1119 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1120 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1121 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1122 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1123 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1124 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1125 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1126 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1127 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1128 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1129 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1130 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1131 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1132 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1133 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1134 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1135 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1136 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1137 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1138 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1139 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1140 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1141 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1142 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1143 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1144 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1145 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1146 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1147 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1148 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1149 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1150 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1151 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1152 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1153 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1154 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1155 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1156 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1157 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1158 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1159 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1160 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1161 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1162 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1163 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1164 "data/maps/SootopolisCity/scripts.pory"

# 1165 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_ExpertMoveAside:
# 1166 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_left
# 1167 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_right
# 1168 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1169 "data/maps/SootopolisCity/scripts.pory"

# 1170 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenArriveCaveEntrance:
# 1171 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1172 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1173 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1174 "data/maps/SootopolisCity/scripts.pory"
	delay_8
# 1175 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1176 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1177 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1178 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1179 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1180 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_left
# 1181 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1182 "data/maps/SootopolisCity/scripts.pory"

# 1183 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerArriveCaveEntrance:
# 1184 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1185 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1186 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1187 "data/maps/SootopolisCity/scripts.pory"
	delay_8
# 1188 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1189 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1190 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1191 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1192 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1193 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_right
# 1194 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1195 "data/maps/SootopolisCity/scripts.pory"

# 1196 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerEnterCaveOfOrigin:
# 1197 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1198 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1199 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1200 "data/maps/SootopolisCity/scripts.pory"

# 1201 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy2::
# 1202 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1203 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FacePlayer
# 1204 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1205 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy2Rayquaza
# 1206 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_TwoPokemonArentAngry, MSGBOX_DEFAULT
# 1207 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1208 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FaceOriginalDirection
# 1209 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1210 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1211 "data/maps/SootopolisCity/scripts.pory"
	end
# 1212 "data/maps/SootopolisCity/scripts.pory"

# 1213 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy2Rayquaza::
# 1214 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_FlyingMonStoppedRampage, MSGBOX_DEFAULT
# 1215 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1216 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1217 "data/maps/SootopolisCity/scripts.pory"
	end
# 1218 "data/maps/SootopolisCity/scripts.pory"

# 1219 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BlackBelt::
# 1220 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1221 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_BlackBeltRayquaza
# 1222 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GoRedAndBlueMon, MSGBOX_DEFAULT
# 1223 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1224 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
# 1225 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1226 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoYouKnowMonNames, MSGBOX_DEFAULT
# 1227 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1228 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FaceOriginalDirection
# 1229 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1230 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1231 "data/maps/SootopolisCity/scripts.pory"
	end
# 1232 "data/maps/SootopolisCity/scripts.pory"

# 1233 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BlackBeltRayquaza::
# 1234 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
# 1235 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1236 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GreenOneSettlesThings, MSGBOX_DEFAULT
# 1237 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1238 "data/maps/SootopolisCity/scripts.pory"
	end
# 1239 "data/maps/SootopolisCity/scripts.pory"

# 1240 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Girl::
# 1241 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1242 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FacePlayer
# 1243 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1244 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_GirlRayquaza
# 1245 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisWillBeWrecked, MSGBOX_DEFAULT
# 1246 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1247 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FaceOriginalDirection
# 1248 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1249 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1250 "data/maps/SootopolisCity/scripts.pory"
	end
# 1251 "data/maps/SootopolisCity/scripts.pory"

# 1252 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GirlRayquaza::
# 1253 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisDidntGetWrecked, MSGBOX_DEFAULT
# 1254 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1255 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1256 "data/maps/SootopolisCity/scripts.pory"
	end
# 1257 "data/maps/SootopolisCity/scripts.pory"

# 1258 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Maniac::
# 1259 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1260 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FacePlayer
# 1261 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1262 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ManiacRayquaza
# 1263 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SeeingLegendWithOwnEyes, MSGBOX_DEFAULT
# 1264 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1265 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FaceOriginalDirection
# 1266 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1267 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1268 "data/maps/SootopolisCity/scripts.pory"
	end
# 1269 "data/maps/SootopolisCity/scripts.pory"

# 1270 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ManiacRayquaza::
# 1271 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SawLegendWithOwnEyes, MSGBOX_DEFAULT
# 1272 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1273 "data/maps/SootopolisCity/scripts.pory"
	end
# 1274 "data/maps/SootopolisCity/scripts.pory"

# 1275 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Wallace::
# 1276 "data/maps/SootopolisCity/scripts.pory"
	lock
# 1277 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 1278 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_GoToSkyPillar
# 1279 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_WATERFALL, SootopolisCity_EventScript_GoToGym
# 1280 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_GiveWaterfall
# 1281 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AquaMagmaDidntMeanHarm, MSGBOX_DEFAULT
# 1282 "data/maps/SootopolisCity/scripts.pory"
	release
# 1283 "data/maps/SootopolisCity/scripts.pory"
	end
# 1284 "data/maps/SootopolisCity/scripts.pory"

# 1285 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveWaterfall::
# 1286 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThankYouForHelpAcceptThis, MSGBOX_DEFAULT
# 1287 "data/maps/SootopolisCity/scripts.pory"
	giveitem ITEM_HM_WATERFALL
# 1288 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_RECEIVED_HM_WATERFALL
# 1289 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ExplainWaterfallGoToGym, MSGBOX_DEFAULT
# 1290 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1291 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_WallaceMoveFromGym
# 1292 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, SootopolisCity_EventScript_WallaceMoveFromGym
# 1293 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_WallaceMoveFromGymWest
# 1294 "data/maps/SootopolisCity/scripts.pory"
	release
# 1295 "data/maps/SootopolisCity/scripts.pory"
	end
# 1296 "data/maps/SootopolisCity/scripts.pory"

# 1297 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_WallaceMoveFromGym::
# 1298 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGym
# 1299 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1300 "data/maps/SootopolisCity/scripts.pory"
	copyobjectxytoperm LOCALID_SOOTOPOLIS_WALLACE
# 1301 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 1
# 1302 "data/maps/SootopolisCity/scripts.pory"
	return
# 1303 "data/maps/SootopolisCity/scripts.pory"

# 1304 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_WallaceMoveFromGymWest::
# 1305 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGymWest
# 1306 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1307 "data/maps/SootopolisCity/scripts.pory"
	copyobjectxytoperm LOCALID_SOOTOPOLIS_WALLACE
# 1308 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 2
# 1309 "data/maps/SootopolisCity/scripts.pory"
	return
# 1310 "data/maps/SootopolisCity/scripts.pory"

# 1311 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GoToSkyPillar::
# 1312 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_HaventYouScaledSkyPillar, MSGBOX_DEFAULT
# 1313 "data/maps/SootopolisCity/scripts.pory"
	release
# 1314 "data/maps/SootopolisCity/scripts.pory"
	end
# 1315 "data/maps/SootopolisCity/scripts.pory"

# 1316 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GoToGym::
# 1317 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DazzledByMentor, MSGBOX_DEFAULT
# 1318 "data/maps/SootopolisCity/scripts.pory"
	release
# 1319 "data/maps/SootopolisCity/scripts.pory"
	end
# 1320 "data/maps/SootopolisCity/scripts.pory"

# 1321 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_WallaceMoveFromGym:
# 1322 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1323 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 1324 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1325 "data/maps/SootopolisCity/scripts.pory"

# 1326 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_WallaceMoveFromGymWest:
# 1327 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1328 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 1329 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1330 "data/maps/SootopolisCity/scripts.pory"

# 1331 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Maxie::
# 1332 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1333 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_MaxieRayquaza
# 1334 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GroudonPleaseStop, MSGBOX_DEFAULT
# 1335 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1336 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1337 "data/maps/SootopolisCity/scripts.pory"
	end
# 1338 "data/maps/SootopolisCity/scripts.pory"

# 1339 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_MaxieRayquaza::
# 1340 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AfterAllOurScheming, MSGBOX_DEFAULT
# 1341 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
# 1342 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_MET_ARCHIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
# 1343 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1344 "data/maps/SootopolisCity/scripts.pory"
	end
# 1345 "data/maps/SootopolisCity/scripts.pory"

# 1346 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Archie::
# 1347 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1348 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ArchieRayquaza
# 1349 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_KyogreCalmDown, MSGBOX_DEFAULT
# 1350 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1351 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1352 "data/maps/SootopolisCity/scripts.pory"
	end
# 1353 "data/maps/SootopolisCity/scripts.pory"

# 1354 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ArchieRayquaza::
# 1355 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_TryingMeaninglessToPokemon, MSGBOX_DEFAULT
# 1356 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
# 1357 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_MET_MAXIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
# 1358 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1359 "data/maps/SootopolisCity/scripts.pory"
	end
# 1360 "data/maps/SootopolisCity/scripts.pory"

# 1361 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_MaxieArchieLeave::
# 1362 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
# 1363 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
# 1364 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
# 1365 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
# 1366 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
# 1367 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 2
# 1368 "data/maps/SootopolisCity/scripts.pory"
	warpsilent MAP_SOOTOPOLIS_CITY, 31, 34
# 1369 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 1370 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1371 "data/maps/SootopolisCity/scripts.pory"
	end
# 1372 "data/maps/SootopolisCity/scripts.pory"

# 1373 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 1374 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_Levitate::
# 1375 "data/maps/SootopolisCity/scripts.pory"
	levitate
# 1376 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1377 "data/maps/SootopolisCity/scripts.pory"

# 1378 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 1379 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_DestroyTask::
# 1380 "data/maps/SootopolisCity/scripts.pory"
	destroy_extra_task
# 1381 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1382 "data/maps/SootopolisCity/scripts.pory"

# 1383 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GymSign:
# 1384 "data/maps/SootopolisCity/scripts.pory"
	.string "Sootopolis City Pokémon Gym\n"
# 1385 "data/maps/SootopolisCity/scripts.pory"
	.string "Leader: Juan\p"
# 1386 "data/maps/SootopolisCity/scripts.pory"
	.string "“The Gym Leader with the beauty\n"
# 1387 "data/maps/SootopolisCity/scripts.pory"
	.string "of pure water!”$"
# 1388 "data/maps/SootopolisCity/scripts.pory"

# 1389 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CitySign:
# 1390 "data/maps/SootopolisCity/scripts.pory"
	.string "Sootopolis City\p"
# 1391 "data/maps/SootopolisCity/scripts.pory"
	.string "“The mystical city where history\n"
# 1392 "data/maps/SootopolisCity/scripts.pory"
	.string "slumbers.”$"
# 1393 "data/maps/SootopolisCity/scripts.pory"

# 1394 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoorIsClosed:
# 1395 "data/maps/SootopolisCity/scripts.pory"
	.string "The door is closed.$"
# 1396 "data/maps/SootopolisCity/scripts.pory"

# 1397 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_PhysicallyFitLivingHere:
# 1398 "data/maps/SootopolisCity/scripts.pory"
	.string "Diving in the sea. Climbing up and\n"
# 1399 "data/maps/SootopolisCity/scripts.pory"
	.string "down stairs all the time…\p"
# 1400 "data/maps/SootopolisCity/scripts.pory"
	.string "If you live in this town, you end up\n"
# 1401 "data/maps/SootopolisCity/scripts.pory"
	.string "getting physically fit.$"
# 1402 "data/maps/SootopolisCity/scripts.pory"

# 1403 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GiantPokemonSuddenlyAppeared:
# 1404 "data/maps/SootopolisCity/scripts.pory"
	.string "These giant Pokémon suddenly appeared\n"
# 1405 "data/maps/SootopolisCity/scripts.pory"
	.string "in the middle of the city!\p"
# 1406 "data/maps/SootopolisCity/scripts.pory"
	.string "And, I've never seen them before!\p"
# 1407 "data/maps/SootopolisCity/scripts.pory"
	.string "Why are they smashing into each\n"
# 1408 "data/maps/SootopolisCity/scripts.pory"
	.string "other like that?\p"
# 1409 "data/maps/SootopolisCity/scripts.pory"
	.string "Why can't they be friends, those\n"
# 1410 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon?$"
# 1411 "data/maps/SootopolisCity/scripts.pory"

# 1412 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WhatIsThatGreenPokemon:
# 1413 "data/maps/SootopolisCity/scripts.pory"
	.string "What? What? What?\n"
# 1414 "data/maps/SootopolisCity/scripts.pory"
	.string "What is that green Pokémon?!$"
# 1415 "data/maps/SootopolisCity/scripts.pory"

# 1416 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WhereDidLegendariesGo:
# 1417 "data/maps/SootopolisCity/scripts.pory"
	.string "Groudon and Kyogre…\n"
# 1418 "data/maps/SootopolisCity/scripts.pory"
	.string "Where did they go?\p"
# 1419 "data/maps/SootopolisCity/scripts.pory"
	.string "Will they cause droughts or downpours\n"
# 1420 "data/maps/SootopolisCity/scripts.pory"
	.string "somewhere else?$"
# 1421 "data/maps/SootopolisCity/scripts.pory"

# 1422 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_TwoPokemonArentAngry:
# 1423 "data/maps/SootopolisCity/scripts.pory"
	.string "I just get this sense somehow that\n"
# 1424 "data/maps/SootopolisCity/scripts.pory"
	.string "the two Pokémon aren't angry.\p"
# 1425 "data/maps/SootopolisCity/scripts.pory"
	.string "I think… They probably can't control\n"
# 1426 "data/maps/SootopolisCity/scripts.pory"
	.string "their own power…$"
# 1427 "data/maps/SootopolisCity/scripts.pory"

# 1428 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_FlyingMonStoppedRampage:
# 1429 "data/maps/SootopolisCity/scripts.pory"
	.string "That flying Pokémon came down from\n"
# 1430 "data/maps/SootopolisCity/scripts.pory"
	.string "the sky and stopped the rampaging\l"
# 1431 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon…$"
# 1432 "data/maps/SootopolisCity/scripts.pory"

# 1433 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WonderWhatWorldIsLike:
# 1434 "data/maps/SootopolisCity/scripts.pory"
	.string "I… I've never been out of this city.\p"
# 1435 "data/maps/SootopolisCity/scripts.pory"
	.string "I wonder what the world is like on\n"
# 1436 "data/maps/SootopolisCity/scripts.pory"
	.string "the other side of this round sky?$"
# 1437 "data/maps/SootopolisCity/scripts.pory"

# 1438 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThisIsWicked:
# 1439 "data/maps/SootopolisCity/scripts.pory"
	.string "Wow!\n"
# 1440 "data/maps/SootopolisCity/scripts.pory"
	.string "This is wicked!$"
# 1441 "data/maps/SootopolisCity/scripts.pory"

# 1442 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThatWasWicked:
# 1443 "data/maps/SootopolisCity/scripts.pory"
	.string "Wow!\n"
# 1444 "data/maps/SootopolisCity/scripts.pory"
	.string "That was wicked!$"
# 1445 "data/maps/SootopolisCity/scripts.pory"

# 1446 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GoRedAndBlueMon:
# 1447 "data/maps/SootopolisCity/scripts.pory"
	.string "Go for it, red Pokémon!\n"
# 1448 "data/maps/SootopolisCity/scripts.pory"
	.string "Don't back off, blue Pokémon!$"
# 1449 "data/maps/SootopolisCity/scripts.pory"

# 1450 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoYouKnowMonNames:
# 1451 "data/maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\p"
# 1452 "data/maps/SootopolisCity/scripts.pory"
	.string "Hi, do you know the names of those\n"
# 1453 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon fighting over there?$"
# 1454 "data/maps/SootopolisCity/scripts.pory"

# 1455 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GreenOneSettlesThings:
# 1456 "data/maps/SootopolisCity/scripts.pory"
	.string "I was wondering which one would win,\n"
# 1457 "data/maps/SootopolisCity/scripts.pory"
	.string "the red one or the blue one, but, oh no,\l"
# 1458 "data/maps/SootopolisCity/scripts.pory"
	.string "it's the green one that settles things!\p"
# 1459 "data/maps/SootopolisCity/scripts.pory"
	.string "Talk about a huge turn of events!$"
# 1460 "data/maps/SootopolisCity/scripts.pory"

# 1461 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SeeingLegendWithOwnEyes:
# 1462 "data/maps/SootopolisCity/scripts.pory"
	.string "There's an ancient legend that claims\n"
# 1463 "data/maps/SootopolisCity/scripts.pory"
	.string "the land and sea were shaped by\l"
# 1464 "data/maps/SootopolisCity/scripts.pory"
	.string "a colossal battle between Pokémon.\p"
# 1465 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, I'm seeing that happen with\n"
# 1466 "data/maps/SootopolisCity/scripts.pory"
	.string "my very own eyes!\p"
# 1467 "data/maps/SootopolisCity/scripts.pory"
	.string "Whoa! I never expected to be\n"
# 1468 "data/maps/SootopolisCity/scripts.pory"
	.string "witness to something this huge!$"
# 1469 "data/maps/SootopolisCity/scripts.pory"

# 1470 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SawLegendWithOwnEyes:
# 1471 "data/maps/SootopolisCity/scripts.pory"
	.string "There's an ancient legend that claims\n"
# 1472 "data/maps/SootopolisCity/scripts.pory"
	.string "the land and sea were shaped by\l"
# 1473 "data/maps/SootopolisCity/scripts.pory"
	.string "a colossal battle between Pokémon.\p"
# 1474 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, I saw that happen with\n"
# 1475 "data/maps/SootopolisCity/scripts.pory"
	.string "my very own eyes!\p"
# 1476 "data/maps/SootopolisCity/scripts.pory"
	.string "Whoa! I never expected to be\n"
# 1477 "data/maps/SootopolisCity/scripts.pory"
	.string "witness to something this huge!$"
# 1478 "data/maps/SootopolisCity/scripts.pory"

# 1479 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_BigPokemonFighting:
# 1480 "data/maps/SootopolisCity/scripts.pory"
	.string "A big Pokémon is fighting with\n"
# 1481 "data/maps/SootopolisCity/scripts.pory"
	.string "another big Pokémon!\p"
# 1482 "data/maps/SootopolisCity/scripts.pory"
	.string "Please, someone make them stop!$"
# 1483 "data/maps/SootopolisCity/scripts.pory"

# 1484 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_PrettyMonCameFromSky:
# 1485 "data/maps/SootopolisCity/scripts.pory"
	.string "A pretty Pokémon came down from\n"
# 1486 "data/maps/SootopolisCity/scripts.pory"
	.string "the sky…$"
# 1487 "data/maps/SootopolisCity/scripts.pory"

# 1488 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisWillBeWrecked:
# 1489 "data/maps/SootopolisCity/scripts.pory"
	.string "Oh, no!\n"
# 1490 "data/maps/SootopolisCity/scripts.pory"
	.string "Sootopolis City will get wrecked!$"
# 1491 "data/maps/SootopolisCity/scripts.pory"

# 1492 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisDidntGetWrecked:
# 1493 "data/maps/SootopolisCity/scripts.pory"
	.string "Hooray!\n"
# 1494 "data/maps/SootopolisCity/scripts.pory"
	.string "Sootopolis City didn't get wrecked!$"
# 1495 "data/maps/SootopolisCity/scripts.pory"

# 1496 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NoOrdinaryTourist:
# 1497 "data/maps/SootopolisCity/scripts.pory"
	.string "Hm!\n"
# 1498 "data/maps/SootopolisCity/scripts.pory"
	.string "You've come all the way to Sootopolis?\l"
# 1499 "data/maps/SootopolisCity/scripts.pory"
	.string "You're no ordinary tourist.\p"
# 1500 "data/maps/SootopolisCity/scripts.pory"
	.string "But I suppose that doesn't make you\n"
# 1501 "data/maps/SootopolisCity/scripts.pory"
	.string "an extraordinary tourist, either.$"
# 1502 "data/maps/SootopolisCity/scripts.pory"

# 1503 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CityRegainedCalm:
# 1504 "data/maps/SootopolisCity/scripts.pory"
	.string "The city has regained its calm…$"
# 1505 "data/maps/SootopolisCity/scripts.pory"

# 1506 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CaveOfOriginPleaseLeave:
# 1507 "data/maps/SootopolisCity/scripts.pory"
	.string "Who might you be?\p"
# 1508 "data/maps/SootopolisCity/scripts.pory"
	.string "This is the Cave Of Origin.\p"
# 1509 "data/maps/SootopolisCity/scripts.pory"
	.string "The spirits of Pokémon, becalmed at\n"
# 1510 "data/maps/SootopolisCity/scripts.pory"
	.string "Mt. Pyre, are said to be revived here.\p"
# 1511 "data/maps/SootopolisCity/scripts.pory"
	.string "Please leave.$"
# 1512 "data/maps/SootopolisCity/scripts.pory"

# 1513 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_LeadSuperiorTrainerToCave:
# 1514 "data/maps/SootopolisCity/scripts.pory"
	.string "A person with a strong will and\n"
# 1515 "data/maps/SootopolisCity/scripts.pory"
	.string "superior talent…\p"
# 1516 "data/maps/SootopolisCity/scripts.pory"
	.string "A Trainer who has knowledge and\n"
# 1517 "data/maps/SootopolisCity/scripts.pory"
	.string "experience of many kinds of Pokémon…\p"
# 1518 "data/maps/SootopolisCity/scripts.pory"
	.string "If such a person were to appear, I was\n"
# 1519 "data/maps/SootopolisCity/scripts.pory"
	.string "instructed by Wallace to lead that\l"
# 1520 "data/maps/SootopolisCity/scripts.pory"
	.string "Trainer to this Cave.$"
# 1521 "data/maps/SootopolisCity/scripts.pory"

# 1522 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AwakenedPokemonClash:
# 1523 "data/maps/SootopolisCity/scripts.pory"
	.string "Oh, my…\p"
# 1524 "data/maps/SootopolisCity/scripts.pory"
	.string "The clash between the two awakened\n"
# 1525 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon was quelled by the awakening\l"
# 1526 "data/maps/SootopolisCity/scripts.pory"
	.string "of a third Pokémon…$"
# 1527 "data/maps/SootopolisCity/scripts.pory"

# 1528 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CaveOfOriginSleepsToo:
# 1529 "data/maps/SootopolisCity/scripts.pory"
	.string "This is the Cave Of Origin…\p"
# 1530 "data/maps/SootopolisCity/scripts.pory"
	.string "With the passing of the crisis,\n"
# 1531 "data/maps/SootopolisCity/scripts.pory"
	.string "the cave, too, shall sleep…$"
# 1532 "data/maps/SootopolisCity/scripts.pory"

# 1533 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisSkyBeautiful:
# 1534 "data/maps/SootopolisCity/scripts.pory"
	.string "Sootopolis sprang up as a town in\n"
# 1535 "data/maps/SootopolisCity/scripts.pory"
	.string "the crater of a volcano.\p"
# 1536 "data/maps/SootopolisCity/scripts.pory"
	.string "If you look up at the sky, the lip of\n"
# 1537 "data/maps/SootopolisCity/scripts.pory"
	.string "the crater is also visible.\l"
# 1538 "data/maps/SootopolisCity/scripts.pory"
	.string "So, all you see is the sky in a circle.\p"
# 1539 "data/maps/SootopolisCity/scripts.pory"
	.string "But that's what makes the sky above\n"
# 1540 "data/maps/SootopolisCity/scripts.pory"
	.string "Sootopolis the most beautiful.$"
# 1541 "data/maps/SootopolisCity/scripts.pory"

# 1542 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GiganticPokemonFight:
# 1543 "data/maps/SootopolisCity/scripts.pory"
	.string "When two Pokémon that gigantic\n"
# 1544 "data/maps/SootopolisCity/scripts.pory"
	.string "are fighting that savagely, there's\l"
# 1545 "data/maps/SootopolisCity/scripts.pory"
	.string "not much that we can do.$"
# 1546 "data/maps/SootopolisCity/scripts.pory"

# 1547 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_FearedWorstWhenPokemonFlewDown:
# 1548 "data/maps/SootopolisCity/scripts.pory"
	.string "When that third Pokémon flew down,\n"
# 1549 "data/maps/SootopolisCity/scripts.pory"
	.string "I feared the worst.$"
# 1550 "data/maps/SootopolisCity/scripts.pory"

# 1551 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NightSkyFavoriteScenery:
# 1552 "data/maps/SootopolisCity/scripts.pory"
	.string "A circle of a night sky framed by\n"
# 1553 "data/maps/SootopolisCity/scripts.pory"
	.string "the crater of a volcano…\p"
# 1554 "data/maps/SootopolisCity/scripts.pory"
	.string "And in that ring, stars flicker and\n"
# 1555 "data/maps/SootopolisCity/scripts.pory"
	.string "blink as if they were alive…\l"
# 1556 "data/maps/SootopolisCity/scripts.pory"
	.string "It's my favorite scenery.$"
# 1557 "data/maps/SootopolisCity/scripts.pory"

# 1558 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WeatherWentWild:
# 1559 "data/maps/SootopolisCity/scripts.pory"
	.string "The weather was clear this morning,\n"
# 1560 "data/maps/SootopolisCity/scripts.pory"
	.string "but…\p"
# 1561 "data/maps/SootopolisCity/scripts.pory"
	.string "All of a sudden, dark clouds brewed up,\n"
# 1562 "data/maps/SootopolisCity/scripts.pory"
	.string "rain started falling in sheets, and\l"
# 1563 "data/maps/SootopolisCity/scripts.pory"
	.string "there was thunder and lightning, too.\p"
# 1564 "data/maps/SootopolisCity/scripts.pory"
	.string "The weather just went completely\n"
# 1565 "data/maps/SootopolisCity/scripts.pory"
	.string "wild!\p"
# 1566 "data/maps/SootopolisCity/scripts.pory"
	.string "Is all of this because of those\n"
# 1567 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon?$"
# 1568 "data/maps/SootopolisCity/scripts.pory"

# 1569 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_YouBroughtFlyingMon:
# 1570 "data/maps/SootopolisCity/scripts.pory"
	.string "Oh?\p"
# 1571 "data/maps/SootopolisCity/scripts.pory"
	.string "It was you who brought that flying\n"
# 1572 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon here?\p"
# 1573 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, aren't you amazing!$"
# 1574 "data/maps/SootopolisCity/scripts.pory"

# 1575 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GroudonPleaseStop:
# 1576 "data/maps/SootopolisCity/scripts.pory"
	.string "Maxie: G… Groudon…\n"
# 1577 "data/maps/SootopolisCity/scripts.pory"
	.string "Please! Stop what you're doing!\p"
# 1578 "data/maps/SootopolisCity/scripts.pory"
	.string "I know the extent of your power now!\p"
# 1579 "data/maps/SootopolisCity/scripts.pory"
	.string "If you keep going, all Hoenn, not just\n"
# 1580 "data/maps/SootopolisCity/scripts.pory"
	.string "Sootopolis, will be utterly ruined!$"
# 1581 "data/maps/SootopolisCity/scripts.pory"

# 1582 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AfterAllOurScheming:
# 1583 "data/maps/SootopolisCity/scripts.pory"
	.string "Maxie: So the super-ancient Pokémon\n"
# 1584 "data/maps/SootopolisCity/scripts.pory"
	.string "weren't only Groudon and Kyogre…\p"
# 1585 "data/maps/SootopolisCity/scripts.pory"
	.string "After all our fruitless scheming and\n"
# 1586 "data/maps/SootopolisCity/scripts.pory"
	.string "frantic efforts, that one Pokémon's\l"
# 1587 "data/maps/SootopolisCity/scripts.pory"
	.string "simple action puts everything right\l"
# 1588 "data/maps/SootopolisCity/scripts.pory"
	.string "again as if nothing had happened…\p"
# 1589 "data/maps/SootopolisCity/scripts.pory"
	.string "Fu…\n"
# 1590 "data/maps/SootopolisCity/scripts.pory"
	.string "Fuhahaha…$"
# 1591 "data/maps/SootopolisCity/scripts.pory"

# 1592 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_KyogreCalmDown:
# 1593 "data/maps/SootopolisCity/scripts.pory"
	.string "Archie: Kyogre! What's wrong?!\n"
# 1594 "data/maps/SootopolisCity/scripts.pory"
	.string "Look over here! It's the Red Orb!\l"
# 1595 "data/maps/SootopolisCity/scripts.pory"
	.string "Calm down! Kyogre!\p"
# 1596 "data/maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\n"
# 1597 "data/maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\p"
# 1598 "data/maps/SootopolisCity/scripts.pory"
	.string "It's no good!\n"
# 1599 "data/maps/SootopolisCity/scripts.pory"
	.string "It's not responding at all!$"
# 1600 "data/maps/SootopolisCity/scripts.pory"

# 1601 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_TryingMeaninglessToPokemon:
# 1602 "data/maps/SootopolisCity/scripts.pory"
	.string "Archie: Kyogre and Groudon both\n"
# 1603 "data/maps/SootopolisCity/scripts.pory"
	.string "flew off to who knows where.\p"
# 1604 "data/maps/SootopolisCity/scripts.pory"
	.string "The weather in Hoenn has returned\n"
# 1605 "data/maps/SootopolisCity/scripts.pory"
	.string "to its normal state…\p"
# 1606 "data/maps/SootopolisCity/scripts.pory"
	.string "Haha…\n"
# 1607 "data/maps/SootopolisCity/scripts.pory"
	.string "Hahaha…\p"
# 1608 "data/maps/SootopolisCity/scripts.pory"
	.string "Maybe what we were trying to do was\n"
# 1609 "data/maps/SootopolisCity/scripts.pory"
	.string "something small, even meaningless,\l"
# 1610 "data/maps/SootopolisCity/scripts.pory"
	.string "to Pokémon…$"
# 1611 "data/maps/SootopolisCity/scripts.pory"

# 1612 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_InvolvedWithCrisisComeWithMe:
# 1613 "data/maps/SootopolisCity/scripts.pory"
	.string "Steven: Those Pokémon fighting…\n"
# 1614 "data/maps/SootopolisCity/scripts.pory"
	.string "Groudon… And Kyogre…\p"
# 1615 "data/maps/SootopolisCity/scripts.pory"
	.string "The two super-ancient Pokémon\n"
# 1616 "data/maps/SootopolisCity/scripts.pory"
	.string "were awakened from a long sleep…\p"
# 1617 "data/maps/SootopolisCity/scripts.pory"
	.string "And now they are smashing each other\n"
# 1618 "data/maps/SootopolisCity/scripts.pory"
	.string "with their uncontrollable energy…\p"
# 1619 "data/maps/SootopolisCity/scripts.pory"
	.string "…{PLAYER}{KUN}.\p"
# 1620 "data/maps/SootopolisCity/scripts.pory"
	.string "You being here now I'll take to mean\n"
# 1621 "data/maps/SootopolisCity/scripts.pory"
	.string "that you're prepared to become\l"
# 1622 "data/maps/SootopolisCity/scripts.pory"
	.string "involved in this crisis.\p"
# 1623 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, then, there's someone that\n"
# 1624 "data/maps/SootopolisCity/scripts.pory"
	.string "I'd like you to meet.\p"
# 1625 "data/maps/SootopolisCity/scripts.pory"
	.string "Come with me, please.$"
# 1626 "data/maps/SootopolisCity/scripts.pory"

# 1627 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoesThisMakeYourFearPokemon:
# 1628 "data/maps/SootopolisCity/scripts.pory"
	.string "Steven: Listen, {PLAYER}{KUN}.\p"
# 1629 "data/maps/SootopolisCity/scripts.pory"
	.string "Does seeing Groudon and Kyogre make\n"
# 1630 "data/maps/SootopolisCity/scripts.pory"
	.string "you think Pokémon are to be feared?\p"
# 1631 "data/maps/SootopolisCity/scripts.pory"
	.string "But that's not true.\n"
# 1632 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon are really more…\p"
# 1633 "data/maps/SootopolisCity/scripts.pory"
	.string "…Why am I asking you this?\n"
# 1634 "data/maps/SootopolisCity/scripts.pory"
	.string "You already know.$"
# 1635 "data/maps/SootopolisCity/scripts.pory"

# 1636 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_HereWereAreHelpWallace:
# 1637 "data/maps/SootopolisCity/scripts.pory"
	.string "Steven: Okay, here we are!\p"
# 1638 "data/maps/SootopolisCity/scripts.pory"
	.string "Inside here you'll find someone named\n"
# 1639 "data/maps/SootopolisCity/scripts.pory"
	.string "Wallace.\p"
# 1640 "data/maps/SootopolisCity/scripts.pory"
	.string "I think you have what's needed to\n"
# 1641 "data/maps/SootopolisCity/scripts.pory"
	.string "help him…$"
# 1642 "data/maps/SootopolisCity/scripts.pory"

# 1643 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_KnowWhatsNeededToHelpHim:
# 1644 "data/maps/SootopolisCity/scripts.pory"
	.string "Steven: I think you have what's\n"
# 1645 "data/maps/SootopolisCity/scripts.pory"
	.string "needed to help him…$"
# 1646 "data/maps/SootopolisCity/scripts.pory"

# 1647 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NeverBeenToSkyPillar:
# 1648 "data/maps/SootopolisCity/scripts.pory"
	.string "Steven: The Sky Pillar…\p"
# 1649 "data/maps/SootopolisCity/scripts.pory"
	.string "I've never been there.\n"
# 1650 "data/maps/SootopolisCity/scripts.pory"
	.string "I wonder where it could be?$"
# 1651 "data/maps/SootopolisCity/scripts.pory"

# 1652 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SoThatsRayquaza:
# 1653 "data/maps/SootopolisCity/scripts.pory"
	.string "Steven: So that's Rayquaza…\p"
# 1654 "data/maps/SootopolisCity/scripts.pory"
	.string "It's incredible how the two rampaging\n"
# 1655 "data/maps/SootopolisCity/scripts.pory"
	.string "Pokémon would flee from it in fear…$"
# 1656 "data/maps/SootopolisCity/scripts.pory"

# 1657 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_MaxieArchieLeft:
# 1658 "data/maps/SootopolisCity/scripts.pory"
	.string "Steven: It looks like both Maxie and\n"
# 1659 "data/maps/SootopolisCity/scripts.pory"
	.string "Archie have gone away somewhere.\p"
# 1660 "data/maps/SootopolisCity/scripts.pory"
	.string "Perhaps they've gone to Mt. Pyre to\n"
# 1661 "data/maps/SootopolisCity/scripts.pory"
	.string "return those Orbs…$"
# 1662 "data/maps/SootopolisCity/scripts.pory"

# 1663 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_HaventYouScaledSkyPillar:
# 1664 "data/maps/SootopolisCity/scripts.pory"
	.string "Wallace: Oh?\n"
# 1665 "data/maps/SootopolisCity/scripts.pory"
	.string "{PLAYER}{KUN}?\p"
# 1666 "data/maps/SootopolisCity/scripts.pory"
	.string "Haven't you scaled the Sky Pillar\n"
# 1667 "data/maps/SootopolisCity/scripts.pory"
	.string "yet?\p"
# 1668 "data/maps/SootopolisCity/scripts.pory"
	.string "I'm sure that you can make it to\n"
# 1669 "data/maps/SootopolisCity/scripts.pory"
	.string "the top of the Sky Pillar…$"
# 1670 "data/maps/SootopolisCity/scripts.pory"

# 1671 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AquaMagmaDidntMeanHarm:
# 1672 "data/maps/SootopolisCity/scripts.pory"
	.string "Wallace: {PLAYER}{KUN}…\p"
# 1673 "data/maps/SootopolisCity/scripts.pory"
	.string "The leaders of Team Magma and Aqua,\n"
# 1674 "data/maps/SootopolisCity/scripts.pory"
	.string "I don't think they meant harm.\p"
# 1675 "data/maps/SootopolisCity/scripts.pory"
	.string "It wouldn't hurt to hear what they\n"
# 1676 "data/maps/SootopolisCity/scripts.pory"
	.string "have to say for themselves.$"
# 1677 "data/maps/SootopolisCity/scripts.pory"

# 1678 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThankYouForHelpAcceptThis:
# 1679 "data/maps/SootopolisCity/scripts.pory"
	.string "Wallace: {PLAYER}{KUN}…\n"
# 1680 "data/maps/SootopolisCity/scripts.pory"
	.string "My eyes didn't deceive me.\p"
# 1681 "data/maps/SootopolisCity/scripts.pory"
	.string "Thanks to your help, Sootopolis…\n"
# 1682 "data/maps/SootopolisCity/scripts.pory"
	.string "No, all of Hoenn was saved.\p"
# 1683 "data/maps/SootopolisCity/scripts.pory"
	.string "On behalf of the people, I thank you.\p"
# 1684 "data/maps/SootopolisCity/scripts.pory"
	.string "This is a gift from me.\n"
# 1685 "data/maps/SootopolisCity/scripts.pory"
	.string "Please accept it.$"
# 1686 "data/maps/SootopolisCity/scripts.pory"

# 1687 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ExplainWaterfallGoToGym:
# 1688 "data/maps/SootopolisCity/scripts.pory"
	.string "That Hidden Machine contains\n"
# 1689 "data/maps/SootopolisCity/scripts.pory"
	.string "Waterfall.\p"
# 1690 "data/maps/SootopolisCity/scripts.pory"
	.string "If you have the Rain Badge, a Pokémon\n"
# 1691 "data/maps/SootopolisCity/scripts.pory"
	.string "that has learned that HM move can\l"
# 1692 "data/maps/SootopolisCity/scripts.pory"
	.string "force its way up waterfalls.\p"
# 1693 "data/maps/SootopolisCity/scripts.pory"
	.string "And where does one get the Rain Badge?\n"
# 1694 "data/maps/SootopolisCity/scripts.pory"
	.string "You know, don't you?\p"
# 1695 "data/maps/SootopolisCity/scripts.pory"
	.string "That's right! You have to beat\n"
# 1696 "data/maps/SootopolisCity/scripts.pory"
	.string "the Sootopolis Gym Leader.\p"
# 1697 "data/maps/SootopolisCity/scripts.pory"
	.string "When you're all set to go, step through\n"
# 1698 "data/maps/SootopolisCity/scripts.pory"
	.string "that door.$"
# 1699 "data/maps/SootopolisCity/scripts.pory"

# 1700 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DazzledByMentor:
# 1701 "data/maps/SootopolisCity/scripts.pory"
	.string "Wallace: I'm sure that you will be\n"
# 1702 "data/maps/SootopolisCity/scripts.pory"
	.string "dazzled by my mentor's breathtakingly\l"
# 1703 "data/maps/SootopolisCity/scripts.pory"
	.string "elegant battle style.$"

SootopolisCity_EventScript_RoamerCallOnFrame::
# 1707 "data/maps/SootopolisCity/scripts.pory"
	goto_if_unset FLAG_RECEIVED_ROAMER_CALL, SootopolisCity_EventScript_RoamerCallOnFrame_2
SootopolisCity_EventScript_RoamerCallOnFrame_1:
	end

SootopolisCity_EventScript_RoamerCallOnFrame_2:
# 1708 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1709 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 1710 "data/maps/SootopolisCity/scripts.pory"
	pokenavcall SootopolisCity_Text_BirchRoamerCallPrompt
# 1711 "data/maps/SootopolisCity/scripts.pory"
	waitmessage
# 1712 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1713 "data/maps/SootopolisCity/scripts.pory"
	special InitRoamer
# 1714 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_RECEIVED_ROAMER_CALL
# 1715 "data/maps/SootopolisCity/scripts.pory"
	releaseall
	goto SootopolisCity_EventScript_RoamerCallOnFrame_1


SootopolisCity_Text_BirchRoamerCallPrompt::
# 1720 "data/maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\n"
	.string "… … … … … BZZZT!\p"
	.string "PROF. BIRCH: {PLAYER}!\n"
	.string "Thank goodness!\p"
	.string "I watched the whole thing on TV!\p"
	.string "When Rayquaza roared, my equipment\n"
	.string "went absolutely off the charts!\p"
	.string "It seems that massive burst of\n"
	.string "ancient energy has stirred up\l"
	.string "legendary forces all across\l"
	.string "the Hoenn region!\p"
	.string "My sensors are detecting powerful,\n"
	.string "roaming energy all over the map.\p"
	.string "Keep your eyes peeled while\n"
	.string "exploring, {PLAYER}.\p"
	.string "You might just encounter\n"
	.string "something magnificent out there!\p"
	.string "Good luck, and stay safe!\p"
	.string "… … … … … …\l"
	.string "Click!$"
