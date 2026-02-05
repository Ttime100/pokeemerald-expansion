ScorchedSlab_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ScorchedSlab_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlab_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, ScorchedSlab_OnLoad
	.byte 0

ScorchedSlab_OnTransition:
	setflag FLAG_LANDMARK_SCORCHED_SLAB
	end

ScorchedSlab_OnResume:
	call_if_eq VAR_SCORCHED_SLAB_STATE, 0, ScorchedSlab_EventScript_CheckHasHeatRock
	end

ScorchedSlab_EventScript_CheckHasHeatRock::
	checkitem ITEM_HEAT_ROCK
	goto_if_eq VAR_RESULT, TRUE, ScorchedSlab_EventScript_SetReadyToOpenHeatranWall
	return

ScorchedSlab_EventScript_SetReadyToOpenHeatranWall::
	setvar VAR_SCORCHED_SLAB_STATE, 1
	return

ScorchedSlab_OnLoad:
	goto_if_le VAR_SCORCHED_SLAB_STATE, 1, ScorchedSlab_EventScript_ConcealHeatranEntrance
	end

ScorchedSlab_EventScript_ConcealHeatranEntrance::
	setmetatile 6, 1, METATILE_Cave_CaveWall, TRUE
	setmetatile 6, 2, METATILE_Cave_CaveWall, TRUE
	setmetatile 7, 1, METATILE_Cave_CaveWall, TRUE
	setmetatile 7, 2, METATILE_Cave_CaveWall, TRUE
	setmetatile 8, 1, METATILE_Cave_CaveWall, TRUE
	setmetatile 8, 2, METATILE_Cave_CaveWall, TRUE
	end

ScorchedSlab_EventScript_OpenHeatranWall::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox ScorchedSlab_Text_WallShakingInResponseToHeatRock, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 6, 1, METATILE_Cave_WallUpperLeftofOpening, TRUE
	setmetatile 6, 2, METATILE_Cave_WallLowerLeftofOpening, TRUE
	setmetatile 7, 1, METATILE_Cave_WallEntranceTop, TRUE
	setmetatile 7, 2, METATILE_Cave_WallEntranceBottom, FALSE
	setmetatile 8, 1, METATILE_Cave_WallUpperRightofOpening, TRUE
	setmetatile 8, 2, METATILE_Cave_WallLowerRightofOpening, TRUE
	special DrawWholeMapView
	delay 30
	setvar VAR_SCORCHED_SLAB_STATE, 2
	waitse
	releaseall
	end

ScorchedSlab_Text_WallShakingInResponseToHeatRock:
	.string "Oh! The walls are shaking in response\n"
	.string "to your Heat Rock!$"
