# 1 "data/maps/Umbra_Inlet/scripts.pory"

# 2 "data/maps/Umbra_Inlet/scripts.pory"
Umbra_Inlet_MapScripts::
# 3 "data/maps/Umbra_Inlet/scripts.pory"
	.byte 0

Umbra_Inlet_EventScript_Sidney::
# 6 "data/maps/Umbra_Inlet/scripts.pory"
	lock
# 7 "data/maps/Umbra_Inlet/scripts.pory"
	faceplayer
# 8 "data/maps/Umbra_Inlet/scripts.pory"
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, Sidney_EventScript_PostbattleSpeech
# 9 "data/maps/Umbra_Inlet/scripts.pory"
	trainerbattle_single TRAINER_SIDNEY, Sidney_Text_IntroSpeech, Sidney_Text_Defeat, Sidney_EventScript_Defeated
# 10 "data/maps/Umbra_Inlet/scripts.pory"
	msgbox Sidney_Text_PostBattleSpeech, MSGBOX_AUTOCLOSE
	end


Sidney_EventScript_Defeated::
# 15 "data/maps/Umbra_Inlet/scripts.pory"
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
# 16 "data/maps/Umbra_Inlet/scripts.pory"
	msgbox Sidney_Text_PostBattleSpeech
# 17 "data/maps/Umbra_Inlet/scripts.pory"
	release
	end


Sidney_EventScript_PostbattleSpeech::
# 22 "data/maps/Umbra_Inlet/scripts.pory"
	msgbox Sidney_Text_PostBattleSpeech
# 23 "data/maps/Umbra_Inlet/scripts.pory"
	release
	end


Sidney_Text_IntroSpeech::
# 27 "data/maps/Umbra_Inlet/scripts.pory"
	.string "Welcome... I'm Sidney,\n"
	.string "formerly of the Elite Four.\p"
	.string "I like that look you're giving me.\n"
	.string "I guess you'll give me a good match.\l"
	.string "That's good! Looking real good!\p"
	.string "All right! You and me, let's enjoy\n"
	.string "a battle that could rival\l"
	.string "the Pokémon League!$"

Sidney_Text_Defeat::
# 38 "data/maps/Umbra_Inlet/scripts.pory"
	.string "Well, how do you like that? I lost!\n"
	.string "Eh, it was fun, so it doesn't matter.$"

Sidney_Text_PostBattleSpeech::
# 43 "data/maps/Umbra_Inlet/scripts.pory"
	.string "Well, listen to what this loser has\n"
	.string "to say.\p"
	.string "You've got what it takes to go far.\n"
	.string "Now, go on to the Pokémon League and\l"
	.string "show them what a real trainer can do!$"
