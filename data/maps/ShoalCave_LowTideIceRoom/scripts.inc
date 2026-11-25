ShoalCave_LowTideIceRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideIceRoom_OnLoad
	.byte 0

ShoalCave_LowTideIceRoom_OnLoad:
	checkspecies SPECIES_RESHIRAM
	goto_if_eq VAR_RESULT, FALSE, ShoalCave_LowTideIceRoom_EventScript_HideIceCaveEntrance
	checkspecies SPECIES_ZEKROM
	goto_if_eq VAR_RESULT, FALSE, ShoalCave_LowTideIceRoom_EventScript_HideIceCaveEntrance
	end

ShoalCave_LowTideIceRoom_EventScript_HideIceCaveEntrance:
	setmetatile 6, 0, 0x389, TRUE
	setmetatile 6, 1, 0x389, TRUE
	setmetatile 7, 0, 0x389, TRUE
	setmetatile 7, 1, 0x389, TRUE
	setmetatile 8, 0, 0x389, TRUE
	setmetatile 8, 1, 0x389, TRUE
	return
