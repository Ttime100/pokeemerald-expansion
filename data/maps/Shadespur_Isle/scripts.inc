# 1 "data/maps/Shadespur_Isle/scripts.pory"

# 2 "data/maps/Shadespur_Isle/scripts.pory"
Shadespur_Isle_MapScripts::
# 3 "data/maps/Shadespur_Isle/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Shadespur_Isle_OnTransition
# 4 "data/maps/Shadespur_Isle/scripts.pory"
	.byte 0
# 5 "data/maps/Shadespur_Isle/scripts.pory"
	
# 6 "data/maps/Shadespur_Isle/scripts.pory"
Shadespur_Isle_OnTransition:
# 7 "data/maps/Shadespur_Isle/scripts.pory"
	setflag FLAG_LANDMARK_SHADESPUR_ISLE
# 8 "data/maps/Shadespur_Isle/scripts.pory"
	end

Shadespur_Isle_EventScript_Trader::
# 11 "data/maps/Shadespur_Isle/scripts.pory"
	lock
# 12 "data/maps/Shadespur_Isle/scripts.pory"
	faceplayer
# 13 "data/maps/Shadespur_Isle/scripts.pory"
	goto_if_set FLAG_SHADESPUR_NPC_TRADE_COMPLETED, Shadespur_Isle_EventScript_TradeCompleted
# 14 "data/maps/Shadespur_Isle/scripts.pory"
	ingame_trade INGAME_TRADE_DEINO, Shadespur_Isle_Text_WillingToTradeIt, Shadespur_Isle_EventScript_DeclineTrade, Shadespur_Isle_EventScript_NotRequestedMon, Shadespur_Isle_Text_TradeThankYou
# 15 "data/maps/Shadespur_Isle/scripts.pory"
	setflag FLAG_SHADESPUR_NPC_TRADE_COMPLETED
# 16 "data/maps/Shadespur_Isle/scripts.pory"
	release
	end


Shadespur_Isle_EventScript_DeclineTrade::
# 21 "data/maps/Shadespur_Isle/scripts.pory"
	lock
# 22 "data/maps/Shadespur_Isle/scripts.pory"
	faceplayer
# 23 "data/maps/Shadespur_Isle/scripts.pory"
	msgbox Shadespur_Isle_Text_NotDesperateOrAnything, MSGBOX_DEFAULT
# 24 "data/maps/Shadespur_Isle/scripts.pory"
	release
	end


Shadespur_Isle_EventScript_NotRequestedMon::
# 29 "data/maps/Shadespur_Isle/scripts.pory"
	lock
# 30 "data/maps/Shadespur_Isle/scripts.pory"
	faceplayer
# 31 "data/maps/Shadespur_Isle/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 32 "data/maps/Shadespur_Isle/scripts.pory"
	msgbox Shadespur_Isle_Text_WontAcceptAnythingElse, MSGBOX_DEFAULT
# 33 "data/maps/Shadespur_Isle/scripts.pory"
	release
	end


Shadespur_Isle_EventScript_TradeCompleted::
# 38 "data/maps/Shadespur_Isle/scripts.pory"
	lock
# 39 "data/maps/Shadespur_Isle/scripts.pory"
	faceplayer
# 40 "data/maps/Shadespur_Isle/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 41 "data/maps/Shadespur_Isle/scripts.pory"
	msgbox Shadespur_Isle_Text_ReallyWantedToGetAbsol, MSGBOX_DEFAULT
# 42 "data/maps/Shadespur_Isle/scripts.pory"
	release
	end


Shadespur_Isle_Text_WillingToTradeIt::
# 46 "data/maps/Shadespur_Isle/scripts.pory"
	.string "I feel like I've been trying to catch an\n"
	.string "{STR_VAR_1} forever, but I've had\l"
	.string "absolutely zero luck.\p"
	.string "Do you have one?\p"
	.string "Would you be willing to trade it for my\n"
	.string "{STR_VAR_2}?$"

Shadespur_Isle_Text_NotDesperateOrAnything::
# 54 "data/maps/Shadespur_Isle/scripts.pory"
	.string "No??\n"
	.string "That's fine...\p"
	.string "I didn't want your {STR_VAR_1}\n"
	.string "anyway.$"

Shadespur_Isle_Text_WontAcceptAnythingElse::
# 60 "data/maps/Shadespur_Isle/scripts.pory"
	.string "That's not {STR_VAR_1}!\n"
	.string "Come back if you actually find one.$"

Shadespur_Isle_Text_ReallyWantedToGetAbsol::
# 65 "data/maps/Shadespur_Isle/scripts.pory"
	.string "I am so glad that hunt is over.\n"
	.string "I've spent way too long on this island.$"

Shadespur_Isle_Text_TradeThankYou::
# 70 "data/maps/Shadespur_Isle/scripts.pory"
	.string "Thank goodness. I can finally stop\n"
	.string "looking for this thing.\p"
	.string "Hopefully my luck is on the upswing now!$"
