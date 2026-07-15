# 1 "data/maps/SafariZone_North/scripts.pory"

# 2 "data/maps/SafariZone_North/scripts.pory"
SafariZone_North_MapScripts::
# 3 "data/maps/SafariZone_North/scripts.pory"
	.byte 0
# 4 "data/maps/SafariZone_North/scripts.pory"

# 5 "data/maps/SafariZone_North/scripts.pory"
SafariZone_North_EventScript_Fisherman::
# 6 "data/maps/SafariZone_North/scripts.pory"
	msgbox SafariZone_North_Text_Fisherman, MSGBOX_NPC
# 7 "data/maps/SafariZone_North/scripts.pory"
	end
# 8 "data/maps/SafariZone_North/scripts.pory"

# 9 "data/maps/SafariZone_North/scripts.pory"
SafariZone_North_EventScript_Man::
# 10 "data/maps/SafariZone_North/scripts.pory"
	msgbox SafariZone_North_Text_Man, MSGBOX_NPC
# 11 "data/maps/SafariZone_North/scripts.pory"
	end

SafariZone_North_EventScript_HeavyDutyBootsAndRockyHelmet::
# 15 "data/maps/SafariZone_North/scripts.pory"
	lock
# 16 "data/maps/SafariZone_North/scripts.pory"
	faceplayer
# 17 "data/maps/SafariZone_North/scripts.pory"
	goto_if_unset FLAG_RECEIVED_BOOTS_AND_HELMET, SafariZone_North_EventScript_HeavyDutyBootsAndRockyHelmet_2
SafariZone_North_EventScript_HeavyDutyBootsAndRockyHelmet_1:
# 23 "data/maps/SafariZone_North/scripts.pory"
	msgbox SafariZone_North_Text_TakeGoodCareOfMyEquipment
# 24 "data/maps/SafariZone_North/scripts.pory"
	release
	end

SafariZone_North_EventScript_HeavyDutyBootsAndRockyHelmet_2:
# 18 "data/maps/SafariZone_North/scripts.pory"
	msgbox SafariZone_North_Text_GiveBootsAndHelmet
# 19 "data/maps/SafariZone_North/scripts.pory"
	giveitem ITEM_HEAVY_DUTY_BOOTS
# 20 "data/maps/SafariZone_North/scripts.pory"
	giveitem ITEM_ROCKY_HELMET
# 21 "data/maps/SafariZone_North/scripts.pory"
	setflag FLAG_RECEIVED_BOOTS_AND_HELMET
	goto SafariZone_North_EventScript_HeavyDutyBootsAndRockyHelmet_1


SafariZone_North_Text_GiveBootsAndHelmet::
# 28 "data/maps/SafariZone_North/scripts.pory"
	.string "Phew!\n"
	.string "Clearing the area out here is brutal.\p"
	.string "Your Pokémon will need protection from\n"
	.string "this rough terrain and hostile wildlife.\p"
	.string "Here, take these.$"

SafariZone_North_Text_TakeGoodCareOfMyEquipment::
# 34 "data/maps/SafariZone_North/scripts.pory"
	.string "Heavy-Duty Boots shield your Pokémon\n"
	.string "from spikes and field hazards,\l"
	.string "while a Rocky Helmet deals payback\l"
	.string "damage on contact.\p"
	.string "Use them well!$"
