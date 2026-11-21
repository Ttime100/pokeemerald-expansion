# 1 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 2 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_MapScripts::
# 3 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_2F_OnTransition
# 4 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.byte 0
# 5 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 6 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_OnTransition:
# 7 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 8 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_DEFEATED_GENESECT, RustboroCity_DevonCorp_2F_EventScript_ResetAfterGenesect
# 9 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_GENESECT_CALL, RustboroCity_DevonCorp_2F_EventScript_SetupGenesectEvent
# 10 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_HIDE_GENESECT_EVENT
# 11 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_HIDE_DEVON_CORP_2F_MR_STONE
# 12 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	clearflag FLAG_HIDE_DEVON_CORP_2F_STAFF
# 13 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 14 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 15 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_SetupGenesectEvent::
# 16 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	clearflag FLAG_HIDE_GENESECT_EVENT
# 17 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_HIDE_DEVON_CORP_2F_STAFF
# 18 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 19 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 20 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ResetAfterGenesect::
# 21 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_HIDE_GENESECT_EVENT
# 22 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	clearflag FLAG_HIDE_DEVON_CORP_2F_STAFF
# 23 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 24 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 25 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_SetFossilReady::
# 26 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 2
# 27 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 28 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 29 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TalkToPokemonScientist::
# 30 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 31 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 32 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 33 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon, MSGBOX_DEFAULT
# 34 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 35 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 36 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 37 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_BallScientist::
# 38 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 39 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 40 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 41 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls
# 42 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls, MSGBOX_DEFAULT
# 43 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 44 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 45 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 46 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_DevelopedBalls::
# 47 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls, MSGBOX_DEFAULT
# 48 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 49 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 50 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 51 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokenavScientist::
# 52 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 53 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 54 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 55 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_set FLAG_RECEIVED_POKENAV, RustboroCity_DevonCorp_2F_EventScript_HasPokenav
# 56 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_IMadePokenav, MSGBOX_DEFAULT
# 57 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 58 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 59 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 60 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_HasPokenav::
# 61 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav, MSGBOX_DEFAULT
# 62 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 63 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 64 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 65 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_PokemonDreamsScientist::
# 66 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 67 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 68 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 69 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams, MSGBOX_DEFAULT
# 70 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 71 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 72 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 73 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FossilScientist::
# 74 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 75 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 76 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 2, RustboroCity_DevonCorp_2F_EventScript_FossilMonReady
# 77 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_StillRegenerating
# 78 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
# 79 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 80 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil
# 81 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 82 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil
# 83 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 84 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 85 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 86 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ This whole section has needless duplication and could be condensed considerably
# 87 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_NoticeRootFossil::
# 88 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 89 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_PIN
# 90 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
# 91 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 92 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
# 93 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 94 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 95 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
# 96 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_CLAW_FOSSIL
# 97 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
# 98 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
# 99 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 100 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 101 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil::
# 102 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_ROOT_FOSSIL
# 103 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 104 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_ROOT_FOSSIL
# 105 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
# 106 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 1
# 107 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 108 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 109 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 110 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_NoticeClawFossil::
# 111 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 112 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_PIN
# 113 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
# 114 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 115 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
# 116 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 117 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 118 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil
# 119 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	checkitem ITEM_ROOT_FOSSIL
# 120 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_DevonCorp_2F_EventScript_ChooseFossil
# 121 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
# 122 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 123 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 124 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil::
# 125 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, ITEM_CLAW_FOSSIL
# 126 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 127 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem ITEM_CLAW_FOSSIL
# 128 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
# 129 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_WHICH_FOSSIL_REVIVED, 2
# 130 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 131 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 132 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 133 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_DeclineGiveFossil::
# 134 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
# 135 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 136 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 137 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 138 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_StillRegenerating::
# 139 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
# 140 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 141 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 142 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 143 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FossilMonReady::
# 144 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 1, RustboroCity_DevonCorp_2F_EventScript_LileepReady
# 145 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_WHICH_FOSSIL_REVIVED, 2, RustboroCity_DevonCorp_2F_EventScript_AnorithReady
# 146 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 147 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 148 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_LileepReady::
# 149 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
# 150 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 151 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep
# 152 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 153 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 154 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_AnorithReady::
# 155 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
# 156 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 157 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith
# 158 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 159 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 160 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileep::
# 161 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LILEEP
# 162 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_LILEEP, 20
# 163 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty
# 164 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC
# 165 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 166 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 167 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 168 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepParty::
# 169 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
# 170 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 171 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 172 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 173 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 174 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 175 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 176 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 177 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveLileepPC::
# 178 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare
# 179 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 180 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
# 181 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 182 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC
# 183 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 184 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 185 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TransferLileepToPC::
# 186 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 187 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep
# 188 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 189 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 190 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceivedLileepFanfare::
# 191 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_LILEEP
# 192 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 193 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
# 194 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 195 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 196 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_LILEEP
# 197 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 198 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 199 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FinishReceivingLileep::
# 200 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 201 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 202 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 203 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 204 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 205 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorith::
# 206 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ANORITH
# 207 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon SPECIES_ANORITH, 20
# 208 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty
# 209 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC
# 210 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
# 211 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 212 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 213 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithParty::
# 214 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
# 215 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 216 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 217 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 218 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
# 219 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 220 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 221 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 222 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceiveAnorithPC::
# 223 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare
# 224 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 225 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_eq VAR_RESULT, NO, RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
# 226 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
# 227 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC
# 228 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 229 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 230 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_TransferAnorithToPC::
# 231 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 232 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith
# 233 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 234 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 235 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ReceivedAnorithFanfare::
# 236 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, SPECIES_ANORITH
# 237 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 238 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
# 239 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 240 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 241 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_ANORITH
# 242 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	return
# 243 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 244 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_FinishReceivingAnorith::
# 245 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 246 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
# 247 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 248 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 249 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 250 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseFossil::
# 251 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne
# 252 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 253 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	multichoice 17, 6, MULTI_FOSSIL, FALSE
# 254 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	switch VAR_RESULT
# 255 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 0, RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil
# 256 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 1, RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil
# 257 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case 2, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
# 258 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	case MULTI_B_PRESSED, RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect
# 259 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 260 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 261 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseClawFossil::
# 262 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveClawFossil
# 263 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 264 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 265 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_ChooseRootFossil::
# 266 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto RustboroCity_DevonCorp_2F_EventScript_GiveRootFossil
# 267 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 268 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 269 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_CancelFossilSelect::
# 270 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 271 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 272 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 273 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_MatchCallScientist::
# 274 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 275 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 276 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call_if_eq VAR_FOSSIL_RESURRECTION_STATE, 1, RustboroCity_DevonCorp_2F_EventScript_SetFossilReady
# 277 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto_if_ge VAR_RUSTBORO_CITY_STATE, 6, RustboroCity_DevonCorp_2F_EventScript_WorkOnNext
# 278 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature, MSGBOX_DEFAULT
# 279 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 280 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 281 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 282 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_EventScript_WorkOnNext::
# 283 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext, MSGBOX_DEFAULT
# 284 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
# 285 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	end
# 286 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 287 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceForTalkingToPokemon:
# 288 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We're developing a device for talking\n"
# 289 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "with Pokémon.\p"
# 290 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But we haven't had much success…$"
# 291 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 292 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopingNewBalls:
# 293 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm developing new kinds of\n"
# 294 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Poké Balls…\p"
# 295 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But I've only made a little headway…$"
# 296 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 297 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WeFinallyMadeNewBalls:
# 298 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "We finally made new kinds of\n"
# 299 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Poké Balls!\p"
# 300 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The Repeat Ball makes it easier to\n"
# 301 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "catch Pokémon you've caught before.\p"
# 302 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The Timer Ball gets better at catching\n"
# 303 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Pokémon the longer a battle runs.\p"
# 304 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Both are proudly developed by\n"
# 305 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the Devon Corporation.\p"
# 306 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Please give them a try!$"
# 307 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 308 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_IMadePokenav:
# 309 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I made the PokéNav!\p"
# 310 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "As an engineer, I feel blessed to have\n"
# 311 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "made something so great!$"
# 312 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 313 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WowThatsAPokenav:
# 314 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, wow!\n"
# 315 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "That's a PokéNav!\p"
# 316 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "It came about as a result of our\n"
# 317 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "President's desire to learn about\l"
# 318 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the feelings of Pokémon.\p"
# 319 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like me to describe its\n"
# 320 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "features in detail?\p"
# 321 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "No, no. I think you'll find out just by\n"
# 322 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "trying the PokéNav out.$"
# 323 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 324 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DeviceToVisualizePokemonDreams:
# 325 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a device that\n"
# 326 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "visually reproduces the dreams of\l"
# 327 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Pokémon…\p"
# 328 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 329 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 330 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils:
# 331 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I've been trying to develop a device\n"
# 332 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "that resurrects Pokémon from fossils…\p"
# 333 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "And, it's working!$"
# 334 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 335 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife:
# 336 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Wait! That thing you have there…\n"
# 337 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Is that a Pokémon fossil?\p"
# 338 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like to bring that Pokémon\n"
# 339 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "back to life?\p"
# 340 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I can with my newly developed\n"
# 341 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Fossil Regenerator.$"
# 342 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 343 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_OhIsThatSo:
# 344 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, is that so?\p"
# 345 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Devon's technological expertise\n"
# 346 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "is outstanding, I tell you.$"
# 347 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 348 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_TwoFossilsPickOne:
# 349 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, now that's a surprise!\n"
# 350 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You have not one, but two, fossils?\p"
# 351 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Unfortunately, my machine can only\n"
# 352 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "regenerate one Pokémon at a time.\p"
# 353 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Would you like to pick one of your\n"
# 354 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "fossils for regeneration?$"
# 355 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 356 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher:
# 357 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Excellent!\n"
# 358 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Let's do this right away.\p"
# 359 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} handed the {STR_VAR_1} to\n"
# 360 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the Devon Researcher.$"
# 361 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 362 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime:
# 363 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The Fossil Regenerator, which I made,\n"
# 364 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "is incredible.\p"
# 365 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it has one drawback--it takes\n"
# 366 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "a long time to work.\p"
# 367 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "So, uh… How about you go for a stroll\n"
# 368 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "and look around for a while?$"
# 369 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 370 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife:
# 371 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Thanks for waiting!\p"
# 372 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Your fossilized Pokémon has been\n"
# 373 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "brought back to life!\p"
# 374 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "The fossil was an ancient Pokémon.\n"
# 375 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{STR_VAR_2}, it was!$"
# 376 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 377 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher:
# 378 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "{PLAYER} received {STR_VAR_2} from\n"
# 379 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "the Devon Researcher.$"
# 380 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 381 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
@ Unused
# 382 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_TooManyPokemon:
# 383 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Uh-oh, you've got too many Pokémon.\n"
# 384 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "You have no room for this one.$"
# 385 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 386 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_DevelopNewPokenavFeature:
# 387 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "I'm trying to develop a new feature\n"
# 388 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "for the PokéNav…\p"
# 389 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "But it's not going well.$"
# 390 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"

# 391 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Text_WhatToWorkOnNext:
# 392 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Well, now what shall I work on\n"
# 393 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "developing next?\p"
# 394 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Our company allows us to make our\n"
# 395 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "inspirations into reality.\p"
# 396 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "One couldn't ask for a better\n"
# 397 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "environment as an engineer.$"

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom::
# 401 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 402 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 403 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FOSSIL_RESURRECTION_STATE, 2
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_2
# 408 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FOSSIL_RESURRECTION_STATE, 1
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_5
# 413 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_DevelopDeviceToResurrectFossils, MSGBOX_DEFAULT
# 414 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	specialvar VAR_TEMP_1, GetSpeciesFromFossil
# 415 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_TEMP_1, SPECIES_NONE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_8
# 419 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 420 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_PIN
# 421 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_ExclamationMark
# 422 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 423 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_FOSSIL_SCIENTIST, Common_Movement_Delay48
# 424 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 425 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	specialvar VAR_TEMP_3, GetHasMultipleFossils
# 426 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_TEMP_3, TRUE
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_11
# 459 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_WantToBringFossilBackToLife, MSGBOX_YESNO
# 460 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_18
# 465 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	copyvar VAR_WHICH_FOSSIL_REVIVED, VAR_TEMP_1
# 466 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	specialvar VAR_TEMP_2, GetFossilItemId
RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_10:
# 468 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferitemname STR_VAR_1, VAR_TEMP_2
# 469 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_HandedFossilToResearcher, MSGBOX_DEFAULT
# 470 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeitem VAR_TEMP_2, 1
# 471 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 1
# 472 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_2:
# 404 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom
# 405 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_5:
# 409 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilRegeneratorTakesTime, MSGBOX_DEFAULT
# 410 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_8:
# 416 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_11:
# 427 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_MultipleFossilsPickOne
# 428 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
	checkitem ITEM_ROOT_FOSSIL, 1
# 0 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_15
RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_14:
	checkitem ITEM_CLAW_FOSSIL, 1
# 0 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_21
RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_20:
	checkitem ITEM_HELIX_FOSSIL, 1
# 0 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_24
RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_23:
	checkitem ITEM_DOME_FOSSIL, 1
# 0 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_27
RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_26:
	checkitem ITEM_OLD_AMBER, 1
# 0 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_30
RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_29:
	checkitem ITEM_ARMOR_FOSSIL, 1
# 0 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_33
RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_32:
	checkitem ITEM_SKULL_FOSSIL, 1
# 0 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_36
RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_35:
# 450 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	dynmultistack 18, 0, FALSE, 6, FALSE, 0, 0
# 451 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_39
# 456 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	specialvar VAR_TEMP_2, GetFossilItemIdFromIndex
# 457 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	specialvar VAR_WHICH_FOSSIL_REVIVED, GetSpeciesFromFossilIndex
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_10

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_15:
# 430 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	dynmultipush RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_Text_0, 0
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_14

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_18:
# 461 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
# 462 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_21:
# 433 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	dynmultipush RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_Text_1, 1
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_20

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_24:
# 436 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	dynmultipush RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_Text_2, 2
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_23

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_27:
# 439 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	dynmultipush RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_Text_3, 3
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_26

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_30:
# 442 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	dynmultipush RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_Text_4, 4
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_29

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_33:
# 445 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	dynmultipush RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_Text_5, 5
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_32

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_36:
# 448 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	dynmultipush RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_Text_6, 6
	goto RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_35

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_39:
# 452 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_OhIsThatSo, MSGBOX_DEFAULT
# 453 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
	end


RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom::
# 477 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_2, VAR_WHICH_FOSSIL_REVIVED
# 478 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_FossilizedMonBroughtBackToLife, MSGBOX_DEFAULT
# 479 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	copyvar VAR_TEMP_TRANSFERRED_SPECIES, VAR_WHICH_FOSSIL_REVIVED
# 480 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	givemon VAR_WHICH_FOSSIL_REVIVED, 20
# 481 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom_2
# 495 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom_3
# 510 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	goto Common_EventScript_NoMoreRoomForPokemon
RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom_1:
# 512 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
	end

RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom_2:
# 482 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 483 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
# 484 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 485 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 486 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_WHICH_FOSSIL_REVIVED
# 487 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 488 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom_8
RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom_7:
# 492 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 493 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	goto RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom_1

RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom_3:
# 496 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 497 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	message RustboroCity_DevonCorp_2F_Text_ReceivedMonFromResearcher
# 498 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmessage
# 499 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitfanfare
# 500 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_WHICH_FOSSIL_REVIVED
# 501 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
# 502 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom_11
RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom_10:
# 505 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_TransferredToPC
# 506 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setvar VAR_FOSSIL_RESURRECTION_STATE, 0
# 507 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_RECEIVED_REVIVED_FOSSIL_MON
	goto RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom_1

RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom_8:
# 489 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_GetGiftMonPartySlot
# 490 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedPartyMon
	goto RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom_7

RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom_11:
# 503 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	call Common_EventScript_NameReceivedBoxMon
	goto RustboroCity_DevonCorp_2F_EventScript_FossilMonReady_Custom_10


RustboroCity_DevonCorp_2F_EventScript_Genesect::
# 526 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 527 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playmoncry SPECIES_GENESECT, CRY_MODE_NORMAL
# 528 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_EventScript_Genesect_Text_0
# 529 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
	end


RustboroCity_DevonCorp_2F_EventScript_RogueScientist::
# 534 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	lock
# 535 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	faceplayer
# 536 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_ScientistMonologue
# 537 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 538 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_RogueScientist_2
RustboroCity_DevonCorp_2F_EventScript_RogueScientist_1:
# 543 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FACING, DIR_WEST
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_RogueScientist_5
RustboroCity_DevonCorp_2F_EventScript_RogueScientist_4:
# 548 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playmoncry SPECIES_GENESECT, CRY_MODE_ENCOUNTER
# 549 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	delay 40
# 550 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmoncry
# 551 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setwildbattle SPECIES_GENESECT, 85, ITEM_DOUSE_DRIVE
# 552 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 553 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_DEFEATED_GENESECT
# 554 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeobject LOCALID_GENESECT
# 555 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	delay 20
# 556 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	clearflag FLAG_HIDE_DEVON_CORP_2F_MR_STONE
# 557 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	playse SE_EXIT
# 558 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	addobject LOCALID_MR_STONE
# 559 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	delay 10
# 560 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_MAD_SCIENTIST, RustboroCity_DevonCorp_2F_Movement_MadScientistStepLeft
# 561 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 562 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_MR_STONE, RustboroCity_DevonCorp_2F_Movement_MrStoneEnter
# 563 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 564 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_RogueScientist_8
RustboroCity_DevonCorp_2F_EventScript_RogueScientist_7:
# 567 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FACING, DIR_WEST
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_RogueScientist_11
RustboroCity_DevonCorp_2F_EventScript_RogueScientist_10:
# 570 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 571 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	delay 10
# 572 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_MrStoneScoldScientist
# 573 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FACING, DIR_NORTH
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_RogueScientist_14
RustboroCity_DevonCorp_2F_EventScript_RogueScientist_13:
# 576 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	compare VAR_FACING, DIR_WEST
	goto_if_eq RustboroCity_DevonCorp_2F_EventScript_RogueScientist_17
RustboroCity_DevonCorp_2F_EventScript_RogueScientist_16:
# 579 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 580 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	delay 10
# 581 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_MrStoneToPlayer
# 582 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_MR_STONE, Common_Movement_FaceLeft
# 583 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 584 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	delay 10
# 585 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	msgbox RustboroCity_DevonCorp_2F_Text_MrStoneLetsGo
# 586 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	closemessage
# 587 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	delay 20
# 588 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 589 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_HIDE_GENESECT_EVENT
# 590 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	setflag FLAG_HIDE_DEVON_CORP_2F_MR_STONE
# 591 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeobject LOCALID_MAD_SCIENTIST
# 592 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	removeobject LOCALID_MR_STONE
# 593 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	delay 20
# 594 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 595 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	release
	end

RustboroCity_DevonCorp_2F_EventScript_RogueScientist_2:
# 539 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_GENESECT, RustboroCity_DevonCorp_2F_Movement_GenesectAttackOnSouth
# 540 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 541 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	goto RustboroCity_DevonCorp_2F_EventScript_RogueScientist_1

RustboroCity_DevonCorp_2F_EventScript_RogueScientist_5:
# 544 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_GENESECT, RustboroCity_DevonCorp_2F_Movement_GenesectAttackOnEast
# 545 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	waitmovement 0
# 546 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	goto RustboroCity_DevonCorp_2F_EventScript_RogueScientist_4

RustboroCity_DevonCorp_2F_EventScript_RogueScientist_8:
# 565 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	goto RustboroCity_DevonCorp_2F_EventScript_RogueScientist_7

RustboroCity_DevonCorp_2F_EventScript_RogueScientist_11:
# 568 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	goto RustboroCity_DevonCorp_2F_EventScript_RogueScientist_10

RustboroCity_DevonCorp_2F_EventScript_RogueScientist_14:
# 574 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_MR_STONE, Common_Movement_FaceDown
	goto RustboroCity_DevonCorp_2F_EventScript_RogueScientist_13

RustboroCity_DevonCorp_2F_EventScript_RogueScientist_17:
# 577 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	applymovement LOCALID_MR_STONE, Common_Movement_FaceRight
	goto RustboroCity_DevonCorp_2F_EventScript_RogueScientist_16


# 599 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Movement_GenesectAttackOnSouth:
# 600 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	face_down
# 601 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	walk_down
# 602 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	face_right
# 603 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	step_end

# 606 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Movement_GenesectAttackOnEast:
# 607 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	face_down
# 608 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	walk_down
# 609 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	walk_right
# 610 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	walk_right
# 611 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	face_up
# 612 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	step_end

# 615 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Movement_MadScientistStepLeft:
# 616 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	walk_left
# 617 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	face_right
# 618 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	step_end

# 621 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
RustboroCity_DevonCorp_2F_Movement_MrStoneEnter:
# 622 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	walk_down
# 623 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	face_left
# 624 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	step_end

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_Text_0:
# 430 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Root Fossil$"

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_Text_1:
# 433 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Claw Fossil$"

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_Text_2:
# 436 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Helix Fossil$"

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_Text_3:
# 439 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Dome Fossil$"

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_Text_4:
# 442 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Old Amber$"

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_Text_5:
# 445 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Armor Fossil$"

RustboroCity_DevonCorp_2F_EventScript_FossilScientist_Custom_Text_6:
# 448 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Skull Fossil$"

RustboroCity_DevonCorp_2F_EventScript_Genesect_Text_0:
# 528 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Bzzzt-whirrr…$"

RustboroCity_DevonCorp_2F_Text_MultipleFossilsPickOne::
# 516 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Oh, now that's a surprise!\n"
	.string "You have more than one fossil?!\p"
	.string "Unfortunately, my machine can only\n"
	.string "regenerate one Pokémon at a time.\p"
	.string "Would you like to pick one of your\n"
	.string "fossils for regeneration?$"

RustboroCity_DevonCorp_2F_Text_ScientistMonologue::
# 627 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Three hundred million years of\n"
	.string "predatory instincts…\l"
	.string "perfected by modern engineering.\p"
	.string "My colleagues called it dangerous.\n"
	.string "I call it art.\p"
	.string "Let us see how your strength\n"
	.string "fares against an unfiltered weapon.$"

RustboroCity_DevonCorp_2F_Text_MrStoneScoldScientist::
# 637 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Mr. Stone: Unbelievable…\n"
	.string "What on Earth were you thinking,\l"
	.string "putting lives at risk?!\p"
	.string "I'll deal with you later.$"

RustboroCity_DevonCorp_2F_Text_MrStoneToPlayer::
# 644 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "…Ah, {PLAYER}.\n"
	.string "Thank goodness you were here.\p"
	.string "He has gone entirely mad\n"
	.string "in the pursuit of science.\p"
	.string "Devon Corp owes you a debt\n"
	.string "we can never fully repay.$"

RustboroCity_DevonCorp_2F_Text_MrStoneLetsGo::
# 653 "data/maps/RustboroCity_DevonCorp_2F/scripts.pory"
	.string "Let's go. We have much to discuss\n"
	.string "regarding your reckless behavior.$"
