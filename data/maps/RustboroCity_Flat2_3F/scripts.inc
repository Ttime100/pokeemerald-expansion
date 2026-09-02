# 1 "data/maps/RustboroCity_Flat2_3F/scripts.pory"

# 2 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
RustboroCity_Flat2_3F_MapScripts::
# 3 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	.byte 0
# 4 "data/maps/RustboroCity_Flat2_3F/scripts.pory"

# 5 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
RustboroCity_Flat2_3F_EventScript_DevonEmployee::
# 6 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	msgbox RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones, MSGBOX_NPC
# 7 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	end
# 8 "data/maps/RustboroCity_Flat2_3F/scripts.pory"

# 9 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
RustboroCity_Flat2_3F_EventScript_Woman::
# 10 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones, MSGBOX_NPC
# 11 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	end
# 12 "data/maps/RustboroCity_Flat2_3F/scripts.pory"

# 13 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones:
# 14 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	.string "Devon's President likes to collect\n"
# 15 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	.string "rare stones.$"
# 16 "data/maps/RustboroCity_Flat2_3F/scripts.pory"

# 17 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones:
# 18 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	.string "I think the President's son also\n"
# 19 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	.string "collects rare stones.$"

_RustboroCity_Flat2_3F_EventScript_DevonEmployee::
# 23 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	lock
# 24 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	faceplayer
# 25 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	msgbox RustboroCity_Flat2_3F_Text_PresidentCollectsRareStones
# 26 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	msgbox RustboroCity_Flat2_3F_Text_PresidentsSonAlsoCollectsRareStones
# 27 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	release
	end


RustboroCity_Flat2_3F_EventScript_ElementalMonkeyTrader::
# 32 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	lock
# 33 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	faceplayer
# 34 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	goto_if_set FLAG_MONKEY_TRADE_COMPLETE, RustboroCity_Flat2_3F_EventScript_TradeCompleted
# 35 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	switch VAR_STARTER_MON
# 36 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	case 0, RustboroCity_Flat2_3F_EventScript_ElementalMonkeyTrader_3
# 37 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	case 1, RustboroCity_Flat2_3F_EventScript_ElementalMonkeyTrader_4
# 38 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	case 2, RustboroCity_Flat2_3F_EventScript_ElementalMonkeyTrader_5
RustboroCity_Flat2_3F_EventScript_ElementalMonkeyTrader_1:
# 40 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	setflag FLAG_MONKEY_TRADE_COMPLETE
# 41 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	release
	end

RustboroCity_Flat2_3F_EventScript_ElementalMonkeyTrader_3:
# 36 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	ingame_trade_for_anything INGAME_TRADE_PANSEAR, RustboroCity_Flat2_3F_Text_WantThisMonkey, RustboroCity_Flat2_3F_EventScript_DeclineTrade, RustboroCity_Flat2_3F_Text_TradeThankYou
	goto RustboroCity_Flat2_3F_EventScript_ElementalMonkeyTrader_1

RustboroCity_Flat2_3F_EventScript_ElementalMonkeyTrader_4:
# 37 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	ingame_trade_for_anything INGAME_TRADE_PANPOUR, RustboroCity_Flat2_3F_Text_WantThisMonkey, RustboroCity_Flat2_3F_EventScript_DeclineTrade, RustboroCity_Flat2_3F_Text_TradeThankYou
	goto RustboroCity_Flat2_3F_EventScript_ElementalMonkeyTrader_1

RustboroCity_Flat2_3F_EventScript_ElementalMonkeyTrader_5:
# 38 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	ingame_trade_for_anything INGAME_TRADE_PANSAGE, RustboroCity_Flat2_3F_Text_WantThisMonkey, RustboroCity_Flat2_3F_EventScript_DeclineTrade, RustboroCity_Flat2_3F_Text_TradeThankYou
	goto RustboroCity_Flat2_3F_EventScript_ElementalMonkeyTrader_1


RustboroCity_Flat2_3F_EventScript_DeclineTrade::
# 46 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	lock
# 47 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	faceplayer
# 48 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	msgbox RustboroCity_Flat2_3F_Text_IfYouChangeYourMind
# 49 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	release
	end


RustboroCity_Flat2_3F_EventScript_TradeCompleted::
# 54 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	lock
# 55 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	faceplayer
# 56 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	switch VAR_STARTER_MON
# 57 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	case 0, RustboroCity_Flat2_3F_EventScript_TradeCompleted_3
# 58 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	case 1, RustboroCity_Flat2_3F_EventScript_TradeCompleted_4
# 59 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	case 2, RustboroCity_Flat2_3F_EventScript_TradeCompleted_5
RustboroCity_Flat2_3F_EventScript_TradeCompleted_1:
# 61 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	msgbox RustboroCity_Flat2_3F_Text_GreatCompanion
# 62 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	release
	end

RustboroCity_Flat2_3F_EventScript_TradeCompleted_3:
# 57 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PANSEAR
	goto RustboroCity_Flat2_3F_EventScript_TradeCompleted_1

RustboroCity_Flat2_3F_EventScript_TradeCompleted_4:
# 58 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PANPOUR
	goto RustboroCity_Flat2_3F_EventScript_TradeCompleted_1

RustboroCity_Flat2_3F_EventScript_TradeCompleted_5:
# 59 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_PANSAGE
	goto RustboroCity_Flat2_3F_EventScript_TradeCompleted_1


RustboroCity_Flat2_3F_Text_WantThisMonkey::
# 66 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	.string "Hi there!\n"
	.string "Are you a new trainer?\p"
	.string "I love seeing new trainers\n"
	.string "get started on their adventure.\p"
	.string "Have you tried trading\n"
	.string "with anyone yet?\p"
	.string "Trading is a great way to make friends\n"
	.string "and get new Pokémon!\p"
	.string "Oh! I have a {STR_VAR_2} that\n"
	.string "I could trade you.\p"
	.string "Would you like to trade with me?$"

RustboroCity_Flat2_3F_Text_IfYouChangeYourMind::
# 75 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	.string "That's okay! If you change your mind,\n"
	.string "come back and see me!$"

RustboroCity_Flat2_3F_Text_TradeThankYou::
# 80 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	.string "Thank you for the trade!\p"
	.string "Try trading with other trainers too!\n"
	.string "It's a great way to make friends and\l"
	.string "get new Pokémon!$"

RustboroCity_Flat2_3F_Text_GreatCompanion::
# 86 "data/maps/RustboroCity_Flat2_3F/scripts.pory"
	.string "I hope {STR_VAR_1} is a great\n"
	.string "companion for you on your journey!$"
