Underwater_Route128_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Underwater_Route128_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Underwater_Route128_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Underwater_Route128_OnLoad
	.byte 0

Underwater_Route128_OnResume:
	call_if_eq VAR_UNDERWATER_ROUTE128_STATE, 0, Underwater_Route128_EventScript_CheckLegendaryEvent
	end

Underwater_Route128_OnTransition::
	call_if_eq VAR_UNDERWATER_ROUTE128_STATE, 0, Underwater_Route128_EventScript_CheckLegendaryEvent
	end

Underwater_Route128_EventScript_CheckLegendaryEvent::
    @ 5 = Rayquaza has cleared the weather in Sootopolis
    goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 5, Underwater_Route128_EventScript_SetReadyToOpenEntrance
    return

Underwater_Route128_EventScript_SetReadyToOpenEntrance::
	setvar VAR_UNDERWATER_ROUTE128_STATE, 1
	return

Underwater_Route128_OnLoad:
	goto_if_eq VAR_UNDERWATER_ROUTE128_STATE, 1, Underwater_Route128_EventScript_RevealEntrance
	goto Underwater_Route128_EventScript_ConcealEntrance
	end

Underwater_Route128_EventScript_ConcealEntrance::
    setmetatile 30, 35, METATILE_Underwater_RockWall, TRUE
    setmetatile 30, 36, METATILE_Underwater_RockWall, TRUE
	setmetatile 31, 35, METATILE_Underwater_RockWall, TRUE
	setmetatile 31, 36, METATILE_Underwater_RockWall, TRUE
    setmetatile 32, 35, METATILE_Underwater_RockWall, TRUE
	setmetatile 32, 36, METATILE_Underwater_RockWall, TRUE
	end

Underwater_Route128_EventScript_RevealEntrance::
	setmetatile 30, 35, 0x265, TRUE
    setmetatile 30, 36, 0x26D, TRUE
	setmetatile 31, 35, 0x266, TRUE
	setmetatile 31, 36, 0x26E, FALSE
    setmetatile 32, 35, 0x267, TRUE
	setmetatile 32, 36, 0x26F, TRUE
	special DrawWholeMapView
	end
