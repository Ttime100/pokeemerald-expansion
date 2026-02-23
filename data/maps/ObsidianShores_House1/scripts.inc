# 1 "data/maps/ObsidianShores_House1/scripts.pory"

# 2 "data/maps/ObsidianShores_House1/scripts.pory"
ObsidianShores_House1_MapScripts::
# 3 "data/maps/ObsidianShores_House1/scripts.pory"
    map_script MAP_SCRIPT_ON_TRANSITION, ObsidianShores_House1_OnTransition
# 4 "data/maps/ObsidianShores_House1/scripts.pory"
	.byte 0

ObsidianShores_House1_OnTransition::
# 8 "data/maps/ObsidianShores_House1/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, ObsidianShores_House1_OnTransition_4
ObsidianShores_House1_OnTransition_3:
# 13 "data/maps/ObsidianShores_House1/scripts.pory"
	setflag FLAG_HIDE_RS_MALE
# 14 "data/maps/ObsidianShores_House1/scripts.pory"
	setflag FLAG_HIDE_RS_FEMALE
ObsidianShores_House1_OnTransition_1:
	end

ObsidianShores_House1_OnTransition_2:
# 9 "data/maps/ObsidianShores_House1/scripts.pory"
	checkplayergender
# 10 "data/maps/ObsidianShores_House1/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, ObsidianShores_House1_EventScript_ShowMale
# 11 "data/maps/ObsidianShores_House1/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, ObsidianShores_House1_EventScript_ShowFemale
	goto ObsidianShores_House1_OnTransition_1

ObsidianShores_House1_OnTransition_4:
# 8 "data/maps/ObsidianShores_House1/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MEMBER_CARD, ObsidianShores_House1_OnTransition_2
	goto ObsidianShores_House1_OnTransition_3


ObsidianShores_House1_EventScript_ShowMale::
# 20 "data/maps/ObsidianShores_House1/scripts.pory"
	clearflag FLAG_HIDE_RS_MALE
# 21 "data/maps/ObsidianShores_House1/scripts.pory"
	setflag FLAG_HIDE_RS_FEMALE
	end


ObsidianShores_House1_EventScript_ShowFemale::
# 26 "data/maps/ObsidianShores_House1/scripts.pory"
	clearflag FLAG_HIDE_RS_FEMALE
# 27 "data/maps/ObsidianShores_House1/scripts.pory"
	setflag FLAG_HIDE_RS_MALE
	end


ObsidianShores_House1_EventScript_PastSelf::
# 32 "data/maps/ObsidianShores_House1/scripts.pory"
	lock
# 33 "data/maps/ObsidianShores_House1/scripts.pory"
	faceplayer
# 34 "data/maps/ObsidianShores_House1/scripts.pory"
	goto_if_unset FLAG_RECEIVED_MEMBER_CARD, ObsidianShores_House1_EventScript_PastSelf_2
ObsidianShores_House1_EventScript_PastSelf_1:
# 42 "data/maps/ObsidianShores_House1/scripts.pory"
	msgbox ObsidianShores_House1_EventScript_PastSelf_Text_1
# 46 "data/maps/ObsidianShores_House1/scripts.pory"
	closemessage
# 47 "data/maps/ObsidianShores_House1/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 48 "data/maps/ObsidianShores_House1/scripts.pory"
	waitmovement 0
# 49 "data/maps/ObsidianShores_House1/scripts.pory"
	release
	end

ObsidianShores_House1_EventScript_PastSelf_2:
# 35 "data/maps/ObsidianShores_House1/scripts.pory"
	msgbox ObsidianShores_House1_EventScript_PastSelf_Text_0
# 38 "data/maps/ObsidianShores_House1/scripts.pory"
	closemessage
# 39 "data/maps/ObsidianShores_House1/scripts.pory"
	giveitem ITEM_MEMBER_CARD
# 40 "data/maps/ObsidianShores_House1/scripts.pory"
	setflag FLAG_RECEIVED_MEMBER_CARD
	goto ObsidianShores_House1_EventScript_PastSelf_1


ObsidianShores_House1_EventScript_PastSelf_Text_0:
# 35 "data/maps/ObsidianShores_House1/scripts.pory"
	.string "I've been holding onto this for a very\n"
	.string "long time.\p"
	.string "I left in such a hurry that I forgot to\n"
	.string "check out.\p"
	.string "I feel like I haven't slept a day since.$"

ObsidianShores_House1_EventScript_PastSelf_Text_1:
# 42 "data/maps/ObsidianShores_House1/scripts.pory"
	.string "That card will get you into the suite in\n"
	.string "the Cove Lily.\p"
	.string "If you're heading that way...\n"
	.string "perhaps you can put it to use again.\p"
	.string "Just... try not to stay too long.$"
