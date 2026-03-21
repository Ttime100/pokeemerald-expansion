LibertyGarden_MapScripts::
	.byte 0

LibertyGarden_Harbor_EventScript_Sailor::
	lock
	faceplayer
	goto_if_eq VAR_SS_TIDAL_STATE, 1, LibertyGarden_Harbor_EventScript_BufferSlateport
    bufferstring STR_VAR_1, LibertyGarden_Text_Lilycove
    goto LibertyGarden_Harbor_EventScript_AskReturn

LibertyGarden_Harbor_EventScript_BufferSlateport:
    bufferstring STR_VAR_1, LibertyGarden_Text_Slateport
	goto LibertyGarden_Harbor_EventScript_AskReturn

LibertyGarden_Harbor_EventScript_AskReturn::
	msgbox LibertyGarden_Harbor_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LibertyGarden_Harbor_EventScript_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 30
	hideobjectat LOCALID_LIBERTY_GARDEN_SAILOR, MAP_LIBERTY_GARDEN
	specialvar VAR_RESULT, GetPlayerFacingDirection
    goto_if_eq VAR_RESULT, DIR_NORTH, LibertyGarden_Harbor_EventScript_PlayerBoardNorth
	goto_if_eq VAR_RESULT, DIR_EAST, LibertyGarden_Harbor_EventScript_PlayerBoardEast
    goto_if_eq VAR_RESULT, DIR_WEST, LibertyGarden_Harbor_EventScript_PlayerBoardWest

LibertyGarden_Harbor_EventScript_PlayerBoardNorth:
    applymovement OBJ_EVENT_ID_PLAYER, LibertyGarden_Harbor_Movement_PlayerBoardNorth
    waitmovement 0
	goto LibertyGarden_Harbor_EventScript_Depart

LibertyGarden_Harbor_EventScript_PlayerBoardEast:
    applymovement OBJ_EVENT_ID_PLAYER, LibertyGarden_Harbor_Movement_PlayerBoardEast
    waitmovement 0
    goto LibertyGarden_Harbor_EventScript_Depart

LibertyGarden_Harbor_EventScript_PlayerBoardWest:
    applymovement OBJ_EVENT_ID_PLAYER, LibertyGarden_Harbor_Movement_PlayerBoardWest
    waitmovement 0
    goto LibertyGarden_Harbor_EventScript_Depart

LibertyGarden_Harbor_EventScript_Depart:
    hideplayer
    waitmovement 0
	setvar VAR_0x8004, LOCALID_LIBERTY_GARDEN_SS_TIDAL
	goto_if_eq VAR_SS_TIDAL_STATE, 1, LibertyGarden_Harbor_EventScript_ReturnToSlateport
    warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
    waitstate
    release
    end

LibertyGarden_Harbor_EventScript_ReturnToSlateport:
    warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
    waitstate
    release
    end

LibertyGarden_Harbor_Movement_PlayerBoardNorth:
    walk_up
    step_end

LibertyGarden_Harbor_Movement_PlayerBoardEast:
    walk_right
    walk_in_place_faster_up
    step_end

LibertyGarden_Harbor_Movement_PlayerBoardWest:
    walk_left
    walk_in_place_faster_up
    step_end

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

LibertyGarden_Harbor_Text_SailorReturn:
	.string "What an oddly shaped island, eh?\n"
	.string "Do you want to return to {STR_VAR_1}?$"

LibertyGarden_Text_Lilycove:
    .string "Lilycove$"

LibertyGarden_Text_Slateport:
    .string "Slateport$"
