LibertyGarden_MapScripts::
	.byte 0

LibertyGarden_Harbor_EventScript_Sailor::
	lock
	faceplayer
	msgbox BirthIsland_Harbor_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LibertyGarden_Harbor_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat LOCALID_LIBERTY_GARDEN_SAILOR, MAP_LIBERTY_GARDEN
	setvar VAR_0x8004, LOCALID_LIBERTY_GARDEN_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

LibertyGarden_Harbor_EventScript_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

LibertyGarden_EventScript_BuildingSign::
	msgbox LibertyGarden_Text_BuildingSign, MSGBOX_SIGN
	release
	end

LibertyGarden_Text_BuildingSign:
	.string "Liberty Garden\p"
	.string "Purchased 200 years ago\n"
	.string "as a place where humans\n"
	.string "and Pokémon can live in freedom!$"
