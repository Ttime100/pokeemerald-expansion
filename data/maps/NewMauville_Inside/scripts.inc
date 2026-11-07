# 1 "data/maps/NewMauville_Inside/scripts.pory"

# 2 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_MapScripts::
# 3 "data/maps/NewMauville_Inside/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, NewMauville_Inside_OnResume
# 4 "data/maps/NewMauville_Inside/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Inside_OnTransition
# 5 "data/maps/NewMauville_Inside/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Inside_OnLoad
# 6 "data/maps/NewMauville_Inside/scripts.pory"
	.byte 0
# 7 "data/maps/NewMauville_Inside/scripts.pory"

# 8 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_OnResume:
# 9 "data/maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_SetBarrierState
# 10 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewMauville_Inside_EventScript_TryRemoveVoltorb
# 11 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 12 "data/maps/NewMauville_Inside/scripts.pory"

# 13 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_TryRemoveVoltorb::
# 14 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 15 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
# 16 "data/maps/NewMauville_Inside/scripts.pory"
	removeobject VAR_LAST_TALKED
# 17 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 18 "data/maps/NewMauville_Inside/scripts.pory"

# 19 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_OnTransition:
# 20 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_1, 0
# 21 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_2, 0
# 22 "data/maps/NewMauville_Inside/scripts.pory"
    setflag FLAG_HIDE_ZAPDOS_EMERALD
# 23 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_set FLAG_RECEIVED_ROAMER_CALL, NewMauville_Inside_EventScript_TryShowZapdos
# 24 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_unset FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb1
# 25 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_unset FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb2
# 26 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_unset FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb3
# 27 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 28 "data/maps/NewMauville_Inside/scripts.pory"

# 29 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_TryShowZapdos::
# 30 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_1, 1
# 31 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_set FLAG_CAUGHT_ZAPDOS, Common_EventScript_NopReturn
# 32 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_set FLAG_DEFEATED_ZAPDOS, Common_EventScript_NopReturn
# 33 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_1, 0
# 34 "data/maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_HIDE_ZAPDOS_EMERALD
# 35 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 36 "data/maps/NewMauville_Inside/scripts.pory"

# 37 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_ShowVoltorb1::
# 38 "data/maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_1
# 39 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 40 "data/maps/NewMauville_Inside/scripts.pory"

# 41 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_ShowVoltorb2::
# 42 "data/maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_2
# 43 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 44 "data/maps/NewMauville_Inside/scripts.pory"

# 45 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_ShowVoltorb3::
# 46 "data/maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_3
# 47 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 48 "data/maps/NewMauville_Inside/scripts.pory"

# 49 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_OnLoad:
# 50 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_eq VAR_NEW_MAUVILLE_STATE, 2, NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
# 51 "data/maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_CheckRotomEntrance
# 52 "data/maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_SetBarrierState
# 53 "data/maps/NewMauville_Inside/scripts.pory"
	call_if_unset FLAG_RECEIVED_ROAMER_CALL, NewMauville_Inside_EventScript_HideZapdosRoom
# 54 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 55 "data/maps/NewMauville_Inside/scripts.pory"

# 56 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_CheckRotomEntrance::
# 57 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, NewMauville_Inside_EventScript_OpenRotomEntrance
# 58 "data/maps/NewMauville_Inside/scripts.pory"
    goto NewMauville_Inside_EventScript_ConcealRotomEntrance
# 59 "data/maps/NewMauville_Inside/scripts.pory"
    return
# 60 "data/maps/NewMauville_Inside/scripts.pory"

# 61 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_SetBarrierState::
# 62 "data/maps/NewMauville_Inside/scripts.pory"
    goto_if_eq VAR_NEW_MAUVILLE_BARRIER_STATE, 1, NewMauville_Inside_EventScript_SetBarrierStateGreenButton
# 63 "data/maps/NewMauville_Inside/scripts.pory"
    goto NewMauville_Inside_EventScript_SetBarrierStateBlueButton
# 64 "data/maps/NewMauville_Inside/scripts.pory"
    return
# 65 "data/maps/NewMauville_Inside/scripts.pory"

# 66 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_BlueButton::
# 67 "data/maps/NewMauville_Inside/scripts.pory"
    goto_if_eq VAR_NEW_MAUVILLE_BARRIER_STATE, 0, NewMauville_Inside_EventScript_ButtonExit
# 68 "data/maps/NewMauville_Inside/scripts.pory"
    setvar VAR_NEW_MAUVILLE_BARRIER_STATE, 0
# 69 "data/maps/NewMauville_Inside/scripts.pory"
    playse SE_PIN
# 70 "data/maps/NewMauville_Inside/scripts.pory"
    call NewMauville_Inside_EventScript_SetBarrierStateBlueButton
# 71 "data/maps/NewMauville_Inside/scripts.pory"
    special DrawWholeMapView
# 72 "data/maps/NewMauville_Inside/scripts.pory"
    end
# 73 "data/maps/NewMauville_Inside/scripts.pory"

# 74 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_GreenButton::
# 75 "data/maps/NewMauville_Inside/scripts.pory"
    goto_if_eq VAR_NEW_MAUVILLE_BARRIER_STATE, 1, NewMauville_Inside_EventScript_ButtonExit
# 76 "data/maps/NewMauville_Inside/scripts.pory"
    setvar VAR_NEW_MAUVILLE_BARRIER_STATE, 1
# 77 "data/maps/NewMauville_Inside/scripts.pory"
    playse SE_PIN
# 78 "data/maps/NewMauville_Inside/scripts.pory"
    call NewMauville_Inside_EventScript_SetBarrierStateGreenButton
# 79 "data/maps/NewMauville_Inside/scripts.pory"
    special DrawWholeMapView
# 80 "data/maps/NewMauville_Inside/scripts.pory"
    end
# 81 "data/maps/NewMauville_Inside/scripts.pory"

# 82 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_ButtonExit::
# 83 "data/maps/NewMauville_Inside/scripts.pory"
    releaseall
# 84 "data/maps/NewMauville_Inside/scripts.pory"
    end
# 85 "data/maps/NewMauville_Inside/scripts.pory"

# 86 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_SetBarrierStateBlueButton::
# 87 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 88 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 89 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 36, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 90 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 37, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 91 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 92 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 93 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 18, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 94 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 19, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 95 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 96 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 97 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 2, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 98 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 3, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 99 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Green_Top, TRUE
# 100 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
# 101 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 35, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
# 102 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 36, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
# 103 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Green_Top, TRUE
# 104 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
# 105 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 24, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
# 106 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 25, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
# 107 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Green_Top, TRUE
# 108 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
# 109 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 26, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
# 110 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 27, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
# 111 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Green_Top, TRUE
# 112 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
# 113 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 4, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
# 114 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 5, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
# 115 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 6, 11, METATILE_BikeShop_Button_Pressed, FALSE
# 116 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 13, 10, METATILE_BikeShop_Button_Pressed, FALSE
# 117 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 16, 22, METATILE_BikeShop_Button_Pressed, FALSE
# 118 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 4, 26, METATILE_BikeShop_Button_Pressed, FALSE
# 119 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 38, METATILE_BikeShop_Button_Pressed, FALSE
# 120 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 2, 11, METATILE_BikeShop_Button_Green, FALSE
# 121 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 17, 10, METATILE_BikeShop_Button_Green, FALSE
# 122 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 25, 18, METATILE_BikeShop_Button_Green, FALSE
# 123 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 18, 36, METATILE_BikeShop_Button_Green, FALSE
# 124 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 125 "data/maps/NewMauville_Inside/scripts.pory"

# 126 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_SetBarrierStateGreenButton::
# 127 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Blue_Top, TRUE
# 128 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
# 129 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 36, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
# 130 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 23, 37, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
# 131 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Blue_Top, TRUE
# 132 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
# 133 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 18, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
# 134 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 19, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
# 135 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Blue_Top, TRUE
# 136 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
# 137 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 2, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
# 138 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 3, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
# 139 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 140 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 141 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 35, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 142 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 36, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 143 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 144 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 145 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 24, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 146 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 25, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 147 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 148 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 149 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 26, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 150 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 10, 27, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 151 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
# 152 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
# 153 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 4, METATILE_BikeShop_Floor_Shadow_Top, FALSE
# 154 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 21, 5, METATILE_BikeShop_Wall_Edge_Top, FALSE
# 155 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 2, 11, METATILE_BikeShop_Button_Pressed, FALSE
# 156 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 17, 10, METATILE_BikeShop_Button_Pressed, FALSE
# 157 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 25, 18, METATILE_BikeShop_Button_Pressed, FALSE
# 158 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 18, 36, METATILE_BikeShop_Button_Pressed, FALSE
# 159 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 6, 11, METATILE_BikeShop_Button_Blue, FALSE
# 160 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 13, 10, METATILE_BikeShop_Button_Blue, FALSE
# 161 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 16, 22, METATILE_BikeShop_Button_Blue, FALSE
# 162 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 4, 26, METATILE_BikeShop_Button_Blue, FALSE
# 163 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 38, METATILE_BikeShop_Button_Blue, FALSE
# 164 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 165 "data/maps/NewMauville_Inside/scripts.pory"

# 166 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_RedButton::
# 167 "data/maps/NewMauville_Inside/scripts.pory"
	lockall
# 168 "data/maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped, MSGBOX_DEFAULT
# 169 "data/maps/NewMauville_Inside/scripts.pory"
	closemessage
# 170 "data/maps/NewMauville_Inside/scripts.pory"
	call NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
# 171 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_NEW_MAUVILLE_STATE, 2
# 172 "data/maps/NewMauville_Inside/scripts.pory"
	playse SE_TRUCK_DOOR
# 173 "data/maps/NewMauville_Inside/scripts.pory"
    call NewMauville_Inside_EventScript_OpenRotomEntrance
# 174 "data/maps/NewMauville_Inside/scripts.pory"
    msgbox NewMauville_Inside_Text_SecretDoorMessage, MSGBOX_DEFAULT
# 175 "data/maps/NewMauville_Inside/scripts.pory"
	releaseall
# 176 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 177 "data/maps/NewMauville_Inside/scripts.pory"

# 178 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_SetGeneratorOffMetatiles::
# 179 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 6, METATILE_BikeShop_Button_Pressed, FALSE
# 180 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 2, METATILE_BikeShop_Generator_Off_Tile0, TRUE
# 181 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 2, METATILE_BikeShop_Generator_Off_Tile1, TRUE
# 182 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 2, METATILE_BikeShop_Generator_Off_Tile2, TRUE
# 183 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 2, METATILE_BikeShop_Generator_Off_Tile3, TRUE
# 184 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 3, METATILE_BikeShop_Generator_Off_Tile4, TRUE
# 185 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 3, METATILE_BikeShop_Generator_Off_Tile5, TRUE
# 186 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 3, METATILE_BikeShop_Generator_Off_Tile6, TRUE
# 187 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 3, METATILE_BikeShop_Generator_Off_Tile7, TRUE
# 188 "data/maps/NewMauville_Inside/scripts.pory"
	special DrawWholeMapView
# 189 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 190 "data/maps/NewMauville_Inside/scripts.pory"

# 191 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Generator::
# 192 "data/maps/NewMauville_Inside/scripts.pory"
	lockall
# 193 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, NewMauville_Inside_EventScript_GeneratorOff
# 194 "data/maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_GeneratorRadiatingHeat, MSGBOX_DEFAULT
# 195 "data/maps/NewMauville_Inside/scripts.pory"
	releaseall
# 196 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 197 "data/maps/NewMauville_Inside/scripts.pory"

# 198 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_GeneratorOff::
# 199 "data/maps/NewMauville_Inside/scripts.pory"
	msgbox NewMauville_Inside_Text_GeneratorQuietedDown, MSGBOX_DEFAULT
# 200 "data/maps/NewMauville_Inside/scripts.pory"
	releaseall
# 201 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 202 "data/maps/NewMauville_Inside/scripts.pory"

# 203 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Voltorb1::
# 204 "data/maps/NewMauville_Inside/scripts.pory"
	lock
# 205 "data/maps/NewMauville_Inside/scripts.pory"
	faceplayer
# 206 "data/maps/NewMauville_Inside/scripts.pory"
	setwildbattle SPECIES_VOLTORB, 25
# 207 "data/maps/NewMauville_Inside/scripts.pory"
	waitse
# 208 "data/maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
# 209 "data/maps/NewMauville_Inside/scripts.pory"
	delay 40
# 210 "data/maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 211 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 212 "data/maps/NewMauville_Inside/scripts.pory"
	dowildbattle
# 213 "data/maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 214 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 215 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb1
# 216 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb1
# 217 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb1
# 218 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
# 219 "data/maps/NewMauville_Inside/scripts.pory"
	release
# 220 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 221 "data/maps/NewMauville_Inside/scripts.pory"

# 222 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_DefeatedVoltorb1::
# 223 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
# 224 "data/maps/NewMauville_Inside/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 225 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 226 "data/maps/NewMauville_Inside/scripts.pory"

# 227 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Voltorb2::
# 228 "data/maps/NewMauville_Inside/scripts.pory"
	lock
# 229 "data/maps/NewMauville_Inside/scripts.pory"
	faceplayer
# 230 "data/maps/NewMauville_Inside/scripts.pory"
	setwildbattle SPECIES_VOLTORB, 25
# 231 "data/maps/NewMauville_Inside/scripts.pory"
	waitse
# 232 "data/maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
# 233 "data/maps/NewMauville_Inside/scripts.pory"
	delay 40
# 234 "data/maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 235 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 236 "data/maps/NewMauville_Inside/scripts.pory"
	dowildbattle
# 237 "data/maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 238 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 239 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb2
# 240 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb2
# 241 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb2
# 242 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
# 243 "data/maps/NewMauville_Inside/scripts.pory"
	release
# 244 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 245 "data/maps/NewMauville_Inside/scripts.pory"

# 246 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_DefeatedVoltorb2::
# 247 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
# 248 "data/maps/NewMauville_Inside/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 249 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 250 "data/maps/NewMauville_Inside/scripts.pory"

# 251 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_Voltorb3::
# 252 "data/maps/NewMauville_Inside/scripts.pory"
	lock
# 253 "data/maps/NewMauville_Inside/scripts.pory"
	faceplayer
# 254 "data/maps/NewMauville_Inside/scripts.pory"
	setwildbattle SPECIES_VOLTORB, 25
# 255 "data/maps/NewMauville_Inside/scripts.pory"
	waitse
# 256 "data/maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
# 257 "data/maps/NewMauville_Inside/scripts.pory"
	delay 40
# 258 "data/maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 259 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 260 "data/maps/NewMauville_Inside/scripts.pory"
	dowildbattle
# 261 "data/maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 262 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 263 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb3
# 264 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb3
# 265 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb3
# 266 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
# 267 "data/maps/NewMauville_Inside/scripts.pory"
	release
# 268 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 269 "data/maps/NewMauville_Inside/scripts.pory"

# 270 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_DefeatedVoltorb3::
# 271 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
# 272 "data/maps/NewMauville_Inside/scripts.pory"
	goto Common_EventScript_RemoveStaticPokemon
# 273 "data/maps/NewMauville_Inside/scripts.pory"
	end
# 274 "data/maps/NewMauville_Inside/scripts.pory"

# 275 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_GeneratorRadiatingHeat:
# 276 "data/maps/NewMauville_Inside/scripts.pory"
	.string "The generator is radiating heat that\n"
# 277 "data/maps/NewMauville_Inside/scripts.pory"
	.string "can be felt even at a distance.\p"
# 278 "data/maps/NewMauville_Inside/scripts.pory"
	.string "It looks like it should be turned off\n"
# 279 "data/maps/NewMauville_Inside/scripts.pory"
	.string "as soon as possible.$"
# 280 "data/maps/NewMauville_Inside/scripts.pory"

# 281 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_GeneratorQuietedDown:
# 282 "data/maps/NewMauville_Inside/scripts.pory"
	.string "The generator quieted down.$"
# 283 "data/maps/NewMauville_Inside/scripts.pory"

# 284 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped:
# 285 "data/maps/NewMauville_Inside/scripts.pory"
	.string "{PLAYER} stepped on the switch.\p"
# 286 "data/maps/NewMauville_Inside/scripts.pory"
	.string "Click…\p"
# 287 "data/maps/NewMauville_Inside/scripts.pory"
	.string "… … … … … … … …\n"
# 288 "data/maps/NewMauville_Inside/scripts.pory"
	.string "… … … … … … … …\p"
# 289 "data/maps/NewMauville_Inside/scripts.pory"
	.string "The generator appears to have\n"
# 290 "data/maps/NewMauville_Inside/scripts.pory"
	.string "stopped…$"
# 291 "data/maps/NewMauville_Inside/scripts.pory"

# 292 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_ConcealRotomEntrance::
# 293 "data/maps/NewMauville_Inside/scripts.pory"
    setmetatile 26, 0, 0x21F, TRUE
# 294 "data/maps/NewMauville_Inside/scripts.pory"
    setmetatile 26, 1, 0x227, TRUE
# 295 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 296 "data/maps/NewMauville_Inside/scripts.pory"

# 297 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_OpenRotomEntrance::
# 298 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile	26, 0, 0x26E, TRUE
# 299 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 26, 1, 0x276, FALSE
# 300 "data/maps/NewMauville_Inside/scripts.pory"
	special DrawWholeMapView
# 301 "data/maps/NewMauville_Inside/scripts.pory"
	delay 30
# 302 "data/maps/NewMauville_Inside/scripts.pory"
	return
# 303 "data/maps/NewMauville_Inside/scripts.pory"

# 304 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_Text_SecretDoorMessage:
# 305 "data/maps/NewMauville_Inside/scripts.pory"
	.string "A secret entrance opened nearby!$"
# 306 "data/maps/NewMauville_Inside/scripts.pory"

# 307 "data/maps/NewMauville_Inside/scripts.pory"
NewMauville_Inside_EventScript_HideZapdosRoom:
# 308 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 26, 14, 0x272, TRUE
# 309 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 26, 15, 0x272, TRUE
# 310 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 26, 16, 0x272, TRUE
# 311 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 26, 17, 0x272, TRUE
# 312 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 27, 14, 0x208, TRUE
# 313 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 27, 15, 0x208, TRUE
# 314 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 27, 16, 0x208, TRUE
# 315 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 27, 17, 0x208, TRUE
# 316 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 14, 0x208, TRUE
# 317 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 15, 0x208, TRUE
# 318 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 16, 0x208, TRUE
# 319 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 28, 17, 0x208, TRUE
# 320 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 29, 14, 0x208, TRUE
# 321 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 29, 15, 0x208, TRUE
# 322 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 29, 16, 0x208, TRUE
# 323 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 29, 17, 0x208, TRUE
# 324 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 12, 0x208, TRUE
# 325 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 13, 0x208, TRUE
# 326 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 14, 0x208, TRUE
# 327 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 15, 0x208, TRUE
# 328 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 16, 0x208, TRUE
# 329 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 17, 0x208, TRUE
# 330 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 18, 0x208, TRUE
# 331 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 30, 19, 0x208, TRUE
# 332 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 31, 12, 0x208, TRUE
# 333 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 31, 13, 0x208, TRUE
# 334 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 31, 14, 0x208, TRUE
# 335 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 31, 15, 0x208, TRUE
# 336 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 31, 16, 0x208, TRUE
# 337 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 31, 17, 0x208, TRUE
# 338 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 31, 18, 0x208, TRUE
# 339 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 31, 19, 0x208, TRUE
# 340 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 12, 0x208, TRUE
# 341 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 13, 0x208, TRUE
# 342 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 14, 0x208, TRUE
# 343 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 15, 0x208, TRUE
# 344 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 16, 0x208, TRUE
# 345 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 17, 0x208, TRUE
# 346 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 18, 0x208, TRUE
# 347 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 32, 19, 0x208, TRUE
# 348 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 12, 0x208, TRUE
# 349 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 13, 0x208, TRUE
# 350 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 14, 0x208, TRUE
# 351 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 15, 0x208, TRUE
# 352 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 16, 0x208, TRUE
# 353 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 17, 0x208, TRUE
# 354 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 18, 0x208, TRUE
# 355 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 33, 19, 0x208, TRUE
# 356 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 12, 0x208, TRUE
# 357 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 13, 0x208, TRUE
# 358 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 14, 0x208, TRUE
# 359 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 15, 0x208, TRUE
# 360 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 16, 0x208, TRUE
# 361 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 17, 0x208, TRUE
# 362 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 18, 0x208, TRUE
# 363 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 34, 19, 0x208, TRUE
# 364 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 12, 0x208, TRUE
# 365 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 13, 0x208, TRUE
# 366 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 14, 0x208, TRUE
# 367 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 15, 0x208, TRUE
# 368 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 16, 0x208, TRUE
# 369 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 17, 0x208, TRUE
# 370 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 18, 0x208, TRUE
# 371 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 35, 19, 0x208, TRUE
# 372 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 36, 12, 0x208, TRUE
# 373 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 36, 13, 0x208, TRUE
# 374 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 36, 14, 0x208, TRUE
# 375 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 36, 15, 0x208, TRUE
# 376 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 36, 16, 0x208, TRUE
# 377 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 36, 17, 0x208, TRUE
# 378 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 36, 18, 0x208, TRUE
# 379 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 36, 19, 0x208, TRUE
# 380 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 12, 0x208, TRUE
# 381 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 13, 0x208, TRUE
# 382 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 14, 0x208, TRUE
# 383 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 15, 0x208, TRUE
# 384 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 16, 0x208, TRUE
# 385 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 17, 0x208, TRUE
# 386 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 18, 0x208, TRUE
# 387 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 37, 19, 0x208, TRUE
# 388 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 38, 12, 0x208, TRUE
# 389 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 38, 13, 0x208, TRUE
# 390 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 38, 14, 0x208, TRUE
# 391 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 38, 15, 0x208, TRUE
# 392 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 38, 16, 0x208, TRUE
# 393 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 38, 17, 0x208, TRUE
# 394 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 38, 18, 0x208, TRUE
# 395 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 38, 19, 0x208, TRUE
# 396 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 39, 12, 0x208, TRUE
# 397 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 39, 13, 0x208, TRUE
# 398 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 39, 14, 0x208, TRUE
# 399 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 39, 15, 0x208, TRUE
# 400 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 39, 16, 0x208, TRUE
# 401 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 39, 17, 0x208, TRUE
# 402 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 39, 18, 0x208, TRUE
# 403 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 39, 19, 0x208, TRUE
# 404 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 40, 12, 0x208, TRUE
# 405 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 40, 13, 0x208, TRUE
# 406 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 40, 14, 0x208, TRUE
# 407 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 40, 15, 0x208, TRUE
# 408 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 40, 16, 0x208, TRUE
# 409 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 40, 17, 0x208, TRUE
# 410 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 40, 18, 0x208, TRUE
# 411 "data/maps/NewMauville_Inside/scripts.pory"
	setmetatile 40, 19, 0x208, TRUE
# 412 "data/maps/NewMauville_Inside/scripts.pory"
	return

NewMauville_Inside_BattleZapdos::
# 416 "data/maps/NewMauville_Inside/scripts.pory"
	lock
# 417 "data/maps/NewMauville_Inside/scripts.pory"
	faceplayer
# 418 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_TEMP_1, 1
# 419 "data/maps/NewMauville_Inside/scripts.pory"
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
# 420 "data/maps/NewMauville_Inside/scripts.pory"
	delay 30
# 421 "data/maps/NewMauville_Inside/scripts.pory"
	waitmoncry
# 422 "data/maps/NewMauville_Inside/scripts.pory"
	seteventmon SPECIES_ZAPDOS, 50
# 423 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_SYS_CTRL_OBJ_DELETE
# 424 "data/maps/NewMauville_Inside/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 425 "data/maps/NewMauville_Inside/scripts.pory"
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
# 426 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_NEW_MAUVILLE_INSIDE_ZAPDOS
# 427 "data/maps/NewMauville_Inside/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 428 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedZapdos
# 429 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_RanFromZapdos
# 430 "data/maps/NewMauville_Inside/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_RanFromZapdos
# 431 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_CAUGHT_ZAPDOS
# 432 "data/maps/NewMauville_Inside/scripts.pory"
	release
	end


NewMauville_Inside_EventScript_DefeatedZapdos::
# 437 "data/maps/NewMauville_Inside/scripts.pory"
	setflag FLAG_DEFEATED_ZAPDOS
# 438 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 439 "data/maps/NewMauville_Inside/scripts.pory"
	call Common_EventScript_LegendaryFlewAway
# 440 "data/maps/NewMauville_Inside/scripts.pory"
	release
	end


NewMauville_Inside_EventScript_RanFromZapdos::
# 445 "data/maps/NewMauville_Inside/scripts.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 446 "data/maps/NewMauville_Inside/scripts.pory"
	call Common_EventScript_LegendaryFlewAway
# 447 "data/maps/NewMauville_Inside/scripts.pory"
	release
	end

