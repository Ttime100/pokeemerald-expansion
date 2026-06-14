GraniteCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, GraniteCave_B1F_SetHoleWarp
	.byte 0

GraniteCave_B1F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_GRANITE_CAVE_B2F
	end

@ Moved from Route 105
GraniteCave_B1F_EventScript_Foster::
	trainerbattle_single TRAINER_FOSTER, Route105_Text_FosterIntro, Route105_Text_FosterDefeated
	msgbox Route105_Text_FosterPostBattle, MSGBOX_AUTOCLOSE
	end
