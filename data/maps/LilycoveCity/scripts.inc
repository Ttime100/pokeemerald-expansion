# 1 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_MapScripts::
# 2 "data/maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
# 3 "data/maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
# 4 "data/maps/LilycoveCity/scripts.pory"
	.byte 0
# 5 "data/maps/LilycoveCity/scripts.pory"

# 6 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_OnTransition:
# 7 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_VISITED_LILYCOVE_CITY
# 8 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 9 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
# 10 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 11 "data/maps/LilycoveCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 12 "data/maps/LilycoveCity/scripts.pory"
	end
# 13 "data/maps/LilycoveCity/scripts.pory"

# 14 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_OnLoad:
# 15 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
# 16 "data/maps/LilycoveCity/scripts.pory"
	end
# 17 "data/maps/LilycoveCity/scripts.pory"

# 18 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SetWailmerMetatiles::
# 19 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
# 20 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
# 21 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
# 22 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
# 23 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 24 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 25 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
# 26 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
# 27 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 28 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 29 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
# 30 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
# 31 "data/maps/LilycoveCity/scripts.pory"
	return
# 32 "data/maps/LilycoveCity/scripts.pory"

# 33 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BerryGentleman::
# 34 "data/maps/LilycoveCity/scripts.pory"
	lock
# 35 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 36 "data/maps/LilycoveCity/scripts.pory"
	dotimebasedevents
# 37 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
# 38 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
# 39 "data/maps/LilycoveCity/scripts.pory"
	random 10
# 40 "data/maps/LilycoveCity/scripts.pory"
	addvar VAR_RESULT, FIRST_BERRY_INDEX
# 41 "data/maps/LilycoveCity/scripts.pory"
	giveitem VAR_RESULT
# 42 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 43 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
# 44 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
# 45 "data/maps/LilycoveCity/scripts.pory"
	release
# 46 "data/maps/LilycoveCity/scripts.pory"
	end
# 47 "data/maps/LilycoveCity/scripts.pory"

# 48 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ReceivedBerry::
# 49 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
# 50 "data/maps/LilycoveCity/scripts.pory"
	release
# 51 "data/maps/LilycoveCity/scripts.pory"
	end
# 52 "data/maps/LilycoveCity/scripts.pory"

# 53 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man3::
# 54 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
# 55 "data/maps/LilycoveCity/scripts.pory"
	end
# 56 "data/maps/LilycoveCity/scripts.pory"

# 57 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Girl::
# 58 "data/maps/LilycoveCity/scripts.pory"
	lock
# 59 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 60 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
# 61 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
# 62 "data/maps/LilycoveCity/scripts.pory"
	release
# 63 "data/maps/LilycoveCity/scripts.pory"
	end
# 64 "data/maps/LilycoveCity/scripts.pory"

# 65 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_GirlAquaGone::
# 66 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
# 67 "data/maps/LilycoveCity/scripts.pory"
	release
# 68 "data/maps/LilycoveCity/scripts.pory"
	end
# 69 "data/maps/LilycoveCity/scripts.pory"

# 70 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RichBoy::
# 71 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
# 72 "data/maps/LilycoveCity/scripts.pory"
	end
# 73 "data/maps/LilycoveCity/scripts.pory"

# 74 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2::
# 75 "data/maps/LilycoveCity/scripts.pory"
	lock
# 76 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 77 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
# 78 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
# 79 "data/maps/LilycoveCity/scripts.pory"
	release
# 80 "data/maps/LilycoveCity/scripts.pory"
	end
# 81 "data/maps/LilycoveCity/scripts.pory"

# 82 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2AquaGone::
# 83 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
# 84 "data/maps/LilycoveCity/scripts.pory"
	release
# 85 "data/maps/LilycoveCity/scripts.pory"
	end
# 86 "data/maps/LilycoveCity/scripts.pory"

# 87 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2::
# 88 "data/maps/LilycoveCity/scripts.pory"
	lock
# 89 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 90 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
# 91 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
# 92 "data/maps/LilycoveCity/scripts.pory"
	release
# 93 "data/maps/LilycoveCity/scripts.pory"
	end
# 94 "data/maps/LilycoveCity/scripts.pory"

# 95 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2AquaGone::
# 96 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
# 97 "data/maps/LilycoveCity/scripts.pory"
	release
# 98 "data/maps/LilycoveCity/scripts.pory"
	end
# 99 "data/maps/LilycoveCity/scripts.pory"

# 100 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man2::
# 101 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
# 102 "data/maps/LilycoveCity/scripts.pory"
	end
# 103 "data/maps/LilycoveCity/scripts.pory"

# 104 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM1::
# 105 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
# 106 "data/maps/LilycoveCity/scripts.pory"
	end
# 107 "data/maps/LilycoveCity/scripts.pory"

# 108 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertF::
# 109 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
# 110 "data/maps/LilycoveCity/scripts.pory"
	end
# 111 "data/maps/LilycoveCity/scripts.pory"

# 112 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2::
# 113 "data/maps/LilycoveCity/scripts.pory"
	lock
# 114 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 115 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
# 116 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
# 117 "data/maps/LilycoveCity/scripts.pory"
	release
# 118 "data/maps/LilycoveCity/scripts.pory"
	end
# 119 "data/maps/LilycoveCity/scripts.pory"

# 120 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2AquaGone::
# 121 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
# 122 "data/maps/LilycoveCity/scripts.pory"
	release
# 123 "data/maps/LilycoveCity/scripts.pory"
	end
# 124 "data/maps/LilycoveCity/scripts.pory"

# 125 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor1::
# 126 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
# 127 "data/maps/LilycoveCity/scripts.pory"
	end
# 128 "data/maps/LilycoveCity/scripts.pory"

# 129 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_FatMan::
# 130 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
# 131 "data/maps/LilycoveCity/scripts.pory"
	end
# 132 "data/maps/LilycoveCity/scripts.pory"

# 133 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man1::
# 134 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 135 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
# 136 "data/maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
# 137 "data/maps/LilycoveCity/scripts.pory"
	end
# 138 "data/maps/LilycoveCity/scripts.pory"

# 139 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman1::
# 140 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 141 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
# 142 "data/maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
# 143 "data/maps/LilycoveCity/scripts.pory"
	end
# 144 "data/maps/LilycoveCity/scripts.pory"

# 145 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CitySign::
# 146 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
# 147 "data/maps/LilycoveCity/scripts.pory"
	end
# 148 "data/maps/LilycoveCity/scripts.pory"

# 149 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ContestHallSign::
# 150 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
# 151 "data/maps/LilycoveCity/scripts.pory"
	end
# 152 "data/maps/LilycoveCity/scripts.pory"

# 153 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MotelSign::
# 154 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
# 155 "data/maps/LilycoveCity/scripts.pory"
	end
# 156 "data/maps/LilycoveCity/scripts.pory"

# 157 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSign::
# 158 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 159 "data/maps/LilycoveCity/scripts.pory"
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
# 160 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_0x8004
# 161 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
# 162 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
# 163 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 164 "data/maps/LilycoveCity/scripts.pory"
	end
# 165 "data/maps/LilycoveCity/scripts.pory"

# 166 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSignNoPaintings::
# 167 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
# 168 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 169 "data/maps/LilycoveCity/scripts.pory"
	end
# 170 "data/maps/LilycoveCity/scripts.pory"

# 171 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSign::
# 172 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 173 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
# 174 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
# 175 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 176 "data/maps/LilycoveCity/scripts.pory"
	end
# 177 "data/maps/LilycoveCity/scripts.pory"

# 178 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSignFerryReady::
# 179 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
# 180 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 181 "data/maps/LilycoveCity/scripts.pory"
	end
# 182 "data/maps/LilycoveCity/scripts.pory"

# 183 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_TrainerFanClubSign::
# 184 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
# 185 "data/maps/LilycoveCity/scripts.pory"
	end
# 186 "data/maps/LilycoveCity/scripts.pory"

# 187 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DepartmentStoreSign::
# 188 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
# 189 "data/maps/LilycoveCity/scripts.pory"
	end
# 190 "data/maps/LilycoveCity/scripts.pory"

# 191 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MoveDeletersHouseSign::
# 192 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
# 193 "data/maps/LilycoveCity/scripts.pory"
	end
# 194 "data/maps/LilycoveCity/scripts.pory"

# 195 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_WailmerTrainerGrunt::
# 196 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 197 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
# 198 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 199 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 200 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 201 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
# 202 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 203 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 204 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_WAILMER_TRAINER
# 205 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 206 "data/maps/LilycoveCity/scripts.pory"
	end
# 207 "data/maps/LilycoveCity/scripts.pory"

# 208 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MetWailmerTrainer::
# 209 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 210 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 211 "data/maps/LilycoveCity/scripts.pory"
	end
# 212 "data/maps/LilycoveCity/scripts.pory"

# 213 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt1::
# 214 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
# 215 "data/maps/LilycoveCity/scripts.pory"
	end
# 216 "data/maps/LilycoveCity/scripts.pory"

# 217 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt2::
# 218 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
# 219 "data/maps/LilycoveCity/scripts.pory"
	end
# 220 "data/maps/LilycoveCity/scripts.pory"

# 221 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt3::
# 222 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
# 223 "data/maps/LilycoveCity/scripts.pory"
	end
# 224 "data/maps/LilycoveCity/scripts.pory"

# 225 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt4::
# 226 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
# 227 "data/maps/LilycoveCity/scripts.pory"
	end
# 228 "data/maps/LilycoveCity/scripts.pory"

# 229 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Rival::
# 230 "data/maps/LilycoveCity/scripts.pory"
	lock
# 231 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 232 "data/maps/LilycoveCity/scripts.pory"
	checkplayergender
# 233 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
# 234 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
# 235 "data/maps/LilycoveCity/scripts.pory"
	end
# 236 "data/maps/LilycoveCity/scripts.pory"

# 237 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_May::
# 238 "data/maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 239 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
# 240 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
# 241 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
# 242 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
# 243 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 244 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_BattleMayTreecko
# 245 "data/maps/LilycoveCity/scripts.pory"
	case 1, LilycoveCity_EventScript_BattleMayTorchic
# 246 "data/maps/LilycoveCity/scripts.pory"
	case 2, LilycoveCity_EventScript_BattleMayMudkip
# 247 "data/maps/LilycoveCity/scripts.pory"
	end
# 248 "data/maps/LilycoveCity/scripts.pory"

# 249 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattleAgain::
# 250 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
# 251 "data/maps/LilycoveCity/scripts.pory"
	return
# 252 "data/maps/LilycoveCity/scripts.pory"

# 253 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattle::
# 254 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
# 255 "data/maps/LilycoveCity/scripts.pory"
	return
# 256 "data/maps/LilycoveCity/scripts.pory"

# 257 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineMayBattle::
# 258 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 259 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
# 260 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 261 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 262 "data/maps/LilycoveCity/scripts.pory"
	release
# 263 "data/maps/LilycoveCity/scripts.pory"
	end
# 264 "data/maps/LilycoveCity/scripts.pory"

# 265 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Brendan::
# 266 "data/maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 267 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
# 268 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
# 269 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
# 270 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
# 271 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 272 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
# 273 "data/maps/LilycoveCity/scripts.pory"
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
# 274 "data/maps/LilycoveCity/scripts.pory"
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
# 275 "data/maps/LilycoveCity/scripts.pory"
	end
# 276 "data/maps/LilycoveCity/scripts.pory"

# 277 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattleAgain::
# 278 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
# 279 "data/maps/LilycoveCity/scripts.pory"
	return
# 280 "data/maps/LilycoveCity/scripts.pory"

# 281 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattle::
# 282 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
# 283 "data/maps/LilycoveCity/scripts.pory"
	return
# 284 "data/maps/LilycoveCity/scripts.pory"

# 285 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineBrendanBattle::
# 286 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 287 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 288 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 289 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 290 "data/maps/LilycoveCity/scripts.pory"
	release
# 291 "data/maps/LilycoveCity/scripts.pory"
	end
# 292 "data/maps/LilycoveCity/scripts.pory"

# 293 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTreecko::
# 294 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
# 295 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 296 "data/maps/LilycoveCity/scripts.pory"
	end
# 297 "data/maps/LilycoveCity/scripts.pory"

# 298 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTorchic::
# 299 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
# 300 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 301 "data/maps/LilycoveCity/scripts.pory"
	end
# 302 "data/maps/LilycoveCity/scripts.pory"

# 303 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayMudkip::
# 304 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
# 305 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 306 "data/maps/LilycoveCity/scripts.pory"
	end
# 307 "data/maps/LilycoveCity/scripts.pory"

# 308 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTreecko::
# 309 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
# 310 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 311 "data/maps/LilycoveCity/scripts.pory"
	end
# 312 "data/maps/LilycoveCity/scripts.pory"

# 313 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTorchic::
# 314 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
# 315 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 316 "data/maps/LilycoveCity/scripts.pory"
	end
# 317 "data/maps/LilycoveCity/scripts.pory"

# 318 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanMudkip::
# 319 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
# 320 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 321 "data/maps/LilycoveCity/scripts.pory"
	end
# 322 "data/maps/LilycoveCity/scripts.pory"

# 323 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedMay::
# 324 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
# 325 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 326 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 327 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
# 328 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
# 329 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 330 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
# 331 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 332 "data/maps/LilycoveCity/scripts.pory"
	end
# 333 "data/maps/LilycoveCity/scripts.pory"

# 334 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CheckFinalBadge::
# 335 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
# 336 "data/maps/LilycoveCity/scripts.pory"
	return
# 337 "data/maps/LilycoveCity/scripts.pory"

# 338 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HasFinalBadge::
# 339 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, TRUE
# 340 "data/maps/LilycoveCity/scripts.pory"
	return
# 341 "data/maps/LilycoveCity/scripts.pory"

# 342 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayCollectBadges::
# 343 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
# 344 "data/maps/LilycoveCity/scripts.pory"
	return
# 345 "data/maps/LilycoveCity/scripts.pory"

# 346 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayPokemonLeague::
# 347 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
# 348 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 349 "data/maps/LilycoveCity/scripts.pory"
	return
# 350 "data/maps/LilycoveCity/scripts.pory"

# 351 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayBattleFrontier::
# 352 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 353 "data/maps/LilycoveCity/scripts.pory"
	return
# 354 "data/maps/LilycoveCity/scripts.pory"

# 355 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedBrendan::
# 356 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
# 357 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 358 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 359 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
# 360 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
# 361 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 362 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
# 363 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 364 "data/maps/LilycoveCity/scripts.pory"
	end
# 365 "data/maps/LilycoveCity/scripts.pory"

# 366 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanCollectBadges::
# 367 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
# 368 "data/maps/LilycoveCity/scripts.pory"
	return
# 369 "data/maps/LilycoveCity/scripts.pory"

# 370 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanPokemonLeague::
# 371 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
# 372 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 373 "data/maps/LilycoveCity/scripts.pory"
	return
# 374 "data/maps/LilycoveCity/scripts.pory"

# 375 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanBattleFrontier::
# 376 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 377 "data/maps/LilycoveCity/scripts.pory"
	return
# 378 "data/maps/LilycoveCity/scripts.pory"

# 379 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RivalFlyAway::
# 380 "data/maps/LilycoveCity/scripts.pory"
	closemessage
# 381 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 382 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 383 "data/maps/LilycoveCity/scripts.pory"
	delay 50
# 384 "data/maps/LilycoveCity/scripts.pory"
	setfieldeffectargument 0, 1
# 385 "data/maps/LilycoveCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 386 "data/maps/LilycoveCity/scripts.pory"
	delay 15
# 387 "data/maps/LilycoveCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 388 "data/maps/LilycoveCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 389 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 390 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 391 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_RIVAL_LILYCOVE
# 392 "data/maps/LilycoveCity/scripts.pory"
	release
# 393 "data/maps/LilycoveCity/scripts.pory"
	end
# 394 "data/maps/LilycoveCity/scripts.pory"

# 395 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SchoolKidM::
# 396 "data/maps/LilycoveCity/scripts.pory"
	lock
# 397 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 398 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
# 399 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
# 400 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
# 401 "data/maps/LilycoveCity/scripts.pory"
	release
# 402 "data/maps/LilycoveCity/scripts.pory"
	end
# 403 "data/maps/LilycoveCity/scripts.pory"

# 404 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_KnowAboutBerryBlender::
# 405 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
# 406 "data/maps/LilycoveCity/scripts.pory"
	return
# 407 "data/maps/LilycoveCity/scripts.pory"

# 408 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DontKnowAboutBerryBlender::
# 409 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
# 410 "data/maps/LilycoveCity/scripts.pory"
	return
# 411 "data/maps/LilycoveCity/scripts.pory"

# 412 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayShoppingLetsBattle:
# 413 "data/maps/LilycoveCity/scripts.pory"
	.string "May: Oh, hey?\n"
# 414 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
# 415 "data/maps/LilycoveCity/scripts.pory"
	.string "I bought a whole bunch of Dolls and\n"
# 416 "data/maps/LilycoveCity/scripts.pory"
	.string "Posters.\p"
# 417 "data/maps/LilycoveCity/scripts.pory"
	.string "Of course, I've also caught a lot of\n"
# 418 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokémon, and I'm raising them\l"
# 419 "data/maps/LilycoveCity/scripts.pory"
	.string "properly, too.\p"
# 420 "data/maps/LilycoveCity/scripts.pory"
	.string "Actually, I'm more worried if you're\n"
# 421 "data/maps/LilycoveCity/scripts.pory"
	.string "raising Pokémon properly, {PLAYER}{KUN}.\p"
# 422 "data/maps/LilycoveCity/scripts.pory"
	.string "I'll battle with you, so you can show\n"
# 423 "data/maps/LilycoveCity/scripts.pory"
	.string "me your Pokémon, {PLAYER}{KUN}.$"
# 424 "data/maps/LilycoveCity/scripts.pory"

# 425 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayNotRaisingPokemon:
# 426 "data/maps/LilycoveCity/scripts.pory"
	.string "May: Oh, why? {PLAYER}{KUN}, haven't you\n"
# 427 "data/maps/LilycoveCity/scripts.pory"
	.string "been raising your Pokémon?\p"
# 428 "data/maps/LilycoveCity/scripts.pory"
	.string "That's not a very good showing as a\n"
# 429 "data/maps/LilycoveCity/scripts.pory"
	.string "Trainer…$"
# 430 "data/maps/LilycoveCity/scripts.pory"

# 431 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayBattleMe:
# 432 "data/maps/LilycoveCity/scripts.pory"
	.string "May: Come on, battle with me, so I can\n"
# 433 "data/maps/LilycoveCity/scripts.pory"
	.string "check out your Pokémon!$"
# 434 "data/maps/LilycoveCity/scripts.pory"

# 435 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayWontBeBeaten:
# 436 "data/maps/LilycoveCity/scripts.pory"
	.string "May: The Pokémon I raised won't be\n"
# 437 "data/maps/LilycoveCity/scripts.pory"
	.string "beaten by your Pokémon, {PLAYER}{KUN}!$"
# 438 "data/maps/LilycoveCity/scripts.pory"

# 439 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayDefeat:
# 440 "data/maps/LilycoveCity/scripts.pory"
	.string "… … … … … … … …\p"
# 441 "data/maps/LilycoveCity/scripts.pory"
	.string "I remember the battle I had with you,\n"
# 442 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, on Route 103.\p"
# 443 "data/maps/LilycoveCity/scripts.pory"
	.string "That battle helped you become this\n"
# 444 "data/maps/LilycoveCity/scripts.pory"
	.string "strong, {PLAYER}{KUN}, didn't it?$"
# 445 "data/maps/LilycoveCity/scripts.pory"

# 446 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayGoingBackToLittleroot:
# 447 "data/maps/LilycoveCity/scripts.pory"
	.string "May: I'm thinking of going back to\n"
# 448 "data/maps/LilycoveCity/scripts.pory"
	.string "Littleroot soon.\p"
# 449 "data/maps/LilycoveCity/scripts.pory"
	.string "I've caught a decent group of Pokémon,\n"
# 450 "data/maps/LilycoveCity/scripts.pory"
	.string "and my Pokédex is coming along, so\l"
# 451 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm going home to show my dad.$"
# 452 "data/maps/LilycoveCity/scripts.pory"

# 453 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToCollectBadges:
# 454 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 455 "data/maps/LilycoveCity/scripts.pory"
	.string "Collect all the Gym Badges and take\n"
# 456 "data/maps/LilycoveCity/scripts.pory"
	.string "the Pokémon League challenge?\p"
# 457 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, while you're collecting Badges,\n"
# 458 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
# 459 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokédex. I'll complete it before you!\p"
# 460 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 461 "data/maps/LilycoveCity/scripts.pory"

# 462 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToPokemonLeague:
# 463 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 464 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the Pokémon League\n"
# 465 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 466 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 467 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokédex?\p"
# 468 "data/maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 469 "data/maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my Pokédex before you!\p"
# 470 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 471 "data/maps/LilycoveCity/scripts.pory"

# 472 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToBattleFrontier:
# 473 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 474 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the Battle Frontier\n"
# 475 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 476 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 477 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokédex?\p"
# 478 "data/maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 479 "data/maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my Pokédex before you!\p"
# 480 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 481 "data/maps/LilycoveCity/scripts.pory"

# 482 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanShoppingLetsBattle:
# 483 "data/maps/LilycoveCity/scripts.pory"
	.string "Brendan: Oh, hey, it's {PLAYER}.\p"
# 484 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm running an errand for my dad.\n"
# 485 "data/maps/LilycoveCity/scripts.pory"
	.string "No, I'm not buying any Dolls.\p"
# 486 "data/maps/LilycoveCity/scripts.pory"
	.string "Anyways, it's been a while.\p"
# 487 "data/maps/LilycoveCity/scripts.pory"
	.string "Want to have a battle to see who's been\n"
# 488 "data/maps/LilycoveCity/scripts.pory"
	.string "raising Pokémon better?$"
# 489 "data/maps/LilycoveCity/scripts.pory"

# 490 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanNoConfidence:
# 491 "data/maps/LilycoveCity/scripts.pory"
	.string "Brendan: Oh, what's the matter?\n"
# 492 "data/maps/LilycoveCity/scripts.pory"
	.string "Don't have the confidence?$"
# 493 "data/maps/LilycoveCity/scripts.pory"

# 494 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanBattleMe:
# 495 "data/maps/LilycoveCity/scripts.pory"
	.string "Brendan: Want to battle to see who's\n"
# 496 "data/maps/LilycoveCity/scripts.pory"
	.string "been raising Pokémon better?$"
# 497 "data/maps/LilycoveCity/scripts.pory"

# 498 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanWontBeBeaten:
# 499 "data/maps/LilycoveCity/scripts.pory"
	.string "Brendan: Aww, but you know I'm not\n"
# 500 "data/maps/LilycoveCity/scripts.pory"
	.string "going to lose to no {PLAYER}.$"
# 501 "data/maps/LilycoveCity/scripts.pory"

# 502 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanDefeat:
# 503 "data/maps/LilycoveCity/scripts.pory"
	.string "Humph…\n"
# 504 "data/maps/LilycoveCity/scripts.pory"
	.string "You've done a lot of raising.\p"
# 505 "data/maps/LilycoveCity/scripts.pory"
	.string "That stings a bit--I had a head start\n"
# 506 "data/maps/LilycoveCity/scripts.pory"
	.string "on you as a Trainer…$"
# 507 "data/maps/LilycoveCity/scripts.pory"

# 508 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanGoingBackToLittleroot:
# 509 "data/maps/LilycoveCity/scripts.pory"
	.string "Brendan: I…\n"
# 510 "data/maps/LilycoveCity/scripts.pory"
	.string "I plan on going home to Littleroot.\p"
# 511 "data/maps/LilycoveCity/scripts.pory"
	.string "You know I'm helping out my dad on his\n"
# 512 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokédex. It's coming together pretty\l"
# 513 "data/maps/LilycoveCity/scripts.pory"
	.string "decently, so I should go show him.$"
# 514 "data/maps/LilycoveCity/scripts.pory"

# 515 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToCollectBadges:
# 516 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 517 "data/maps/LilycoveCity/scripts.pory"
	.string "Collect all the Gym Badges and take\n"
# 518 "data/maps/LilycoveCity/scripts.pory"
	.string "the Pokémon League challenge?\p"
# 519 "data/maps/LilycoveCity/scripts.pory"
	.string "Maybe I'll do that, too…\p"
# 520 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 521 "data/maps/LilycoveCity/scripts.pory"

# 522 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
# 523 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 524 "data/maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, are you\n"
# 525 "data/maps/LilycoveCity/scripts.pory"
	.string "taking the Pokémon League challenge?\p"
# 526 "data/maps/LilycoveCity/scripts.pory"
	.string "Heh, even me--if I trained my Pokémon\n"
# 527 "data/maps/LilycoveCity/scripts.pory"
	.string "a bit more, I should be stronger than\l"
# 528 "data/maps/LilycoveCity/scripts.pory"
	.string "you, {PLAYER}.\p"
# 529 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 530 "data/maps/LilycoveCity/scripts.pory"

# 531 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
# 532 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 533 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the Battle Frontier\n"
# 534 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 535 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 536 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokédex?\p"
# 537 "data/maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, you should\n"
# 538 "data/maps/LilycoveCity/scripts.pory"
	.string "consider the Battle Frontier.\p"
# 539 "data/maps/LilycoveCity/scripts.pory"
	.string "Heh, if I train my Pokémon a bit more,\n"
# 540 "data/maps/LilycoveCity/scripts.pory"
	.string "I'll get stronger than you, {PLAYER}.\p"
# 541 "data/maps/LilycoveCity/scripts.pory"
	.string "Maybe I should go to the Battle\n"
# 542 "data/maps/LilycoveCity/scripts.pory"
	.string "Frontier.\p"
# 543 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 544 "data/maps/LilycoveCity/scripts.pory"

# 545 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MovedLootIntoHideoutToday:
# 546 "data/maps/LilycoveCity/scripts.pory"
	.string "Fufufu…\p"
# 547 "data/maps/LilycoveCity/scripts.pory"
	.string "We moved more loot into our secret\n"
# 548 "data/maps/LilycoveCity/scripts.pory"
	.string "Hideout today…\p"
# 549 "data/maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 550 "data/maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 551 "data/maps/LilycoveCity/scripts.pory"

# 552 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ChanceToDoBigThings:
# 553 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm just a Grunt, so I don't know what\n"
# 554 "data/maps/LilycoveCity/scripts.pory"
	.string "the boss is thinking…\p"
# 555 "data/maps/LilycoveCity/scripts.pory"
	.string "But being on Team Aqua, I know I'll get\n"
# 556 "data/maps/LilycoveCity/scripts.pory"
	.string "the chance to do big things!\p"
# 557 "data/maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 558 "data/maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 559 "data/maps/LilycoveCity/scripts.pory"

# 560 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DontGoNearCaveInCove:
# 561 "data/maps/LilycoveCity/scripts.pory"
	.string "Hey, you!\p"
# 562 "data/maps/LilycoveCity/scripts.pory"
	.string "Don't go near the cave in the cove!\p"
# 563 "data/maps/LilycoveCity/scripts.pory"
	.string "Why? You don't need a reason why!\n"
# 564 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm an adult, so you just listen to me!$"
# 565 "data/maps/LilycoveCity/scripts.pory"

# 566 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_IfWorldBecomesOurs:
# 567 "data/maps/LilycoveCity/scripts.pory"
	.string "If this whole wide world becomes ours,\n"
# 568 "data/maps/LilycoveCity/scripts.pory"
	.string "Team Aqua's, it will be a happier\l"
# 569 "data/maps/LilycoveCity/scripts.pory"
	.string "place for Pokémon, too.$"
# 570 "data/maps/LilycoveCity/scripts.pory"

# 571 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_WailmerLeapOutOfWater:
# 572 "data/maps/LilycoveCity/scripts.pory"
	.string "There! Wailmer!\n"
# 573 "data/maps/LilycoveCity/scripts.pory"
	.string "Leap out of the water now!$"
# 574 "data/maps/LilycoveCity/scripts.pory"

# 575 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GetLostMessingUpTraining:
# 576 "data/maps/LilycoveCity/scripts.pory"
	.string "Hunh? What do you want?\p"
# 577 "data/maps/LilycoveCity/scripts.pory"
	.string "You're messing up our training,\n"
# 578 "data/maps/LilycoveCity/scripts.pory"
	.string "so can you, like, get lost?$"
# 579 "data/maps/LilycoveCity/scripts.pory"

# 580 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallInTown:
# 581 "data/maps/LilycoveCity/scripts.pory"
	.string "There's a Pokémon Contest Hall\n"
# 582 "data/maps/LilycoveCity/scripts.pory"
	.string "right in this here town. \p"
# 583 "data/maps/LilycoveCity/scripts.pory"
	.string "That means well-raised Pokémon will\n"
# 584 "data/maps/LilycoveCity/scripts.pory"
	.string "come from all over the country.\p"
# 585 "data/maps/LilycoveCity/scripts.pory"
	.string "My heart swells with excitement!$"
# 586 "data/maps/LilycoveCity/scripts.pory"

# 587 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_StrangeCaveInCove:
# 588 "data/maps/LilycoveCity/scripts.pory"
	.string "Have you seen that strange cave in\n"
# 589 "data/maps/LilycoveCity/scripts.pory"
	.string "the cove at the edge of town?$"
# 590 "data/maps/LilycoveCity/scripts.pory"

# 591 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GoingToMoveDeleterForHMs:
# 592 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm going to teach my Pokémon some new\n"
# 593 "data/maps/LilycoveCity/scripts.pory"
	.string "moves for entering a Contest.\p"
# 594 "data/maps/LilycoveCity/scripts.pory"
	.string "So, I'm going to see the Move Deleter\n"
# 595 "data/maps/LilycoveCity/scripts.pory"
	.string "and make it forget HM moves.$"
# 596 "data/maps/LilycoveCity/scripts.pory"

# 597 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImFromKanto:
# 598 "data/maps/LilycoveCity/scripts.pory"
	.string "I came from Kanto.\p"
# 599 "data/maps/LilycoveCity/scripts.pory"
	.string "The Hoenn region is beautiful with\n"
# 600 "data/maps/LilycoveCity/scripts.pory"
	.string "all its water and verdant nature.\p"
# 601 "data/maps/LilycoveCity/scripts.pory"
	.string "Hunh? Wait a second…\p"
# 602 "data/maps/LilycoveCity/scripts.pory"
	.string "Could there be rare Pokémon that live\n"
# 603 "data/maps/LilycoveCity/scripts.pory"
	.string "only in this area?$"
# 604 "data/maps/LilycoveCity/scripts.pory"

# 605 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
# 606 "data/maps/LilycoveCity/scripts.pory"
	.string "Team Aqua's been training their\n"
# 607 "data/maps/LilycoveCity/scripts.pory"
	.string "Wailmer in the cove.\p"
# 608 "data/maps/LilycoveCity/scripts.pory"
	.string "We Sailors can't get our boats out\n"
# 609 "data/maps/LilycoveCity/scripts.pory"
	.string "to sea with them in the way!$"
# 610 "data/maps/LilycoveCity/scripts.pory"

# 611 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeonePuntedTeamAquaOut:
# 612 "data/maps/LilycoveCity/scripts.pory"
	.string "Ahoy, did you know?\p"
# 613 "data/maps/LilycoveCity/scripts.pory"
	.string "Someone punted Team Aqua out of\n"
# 614 "data/maps/LilycoveCity/scripts.pory"
	.string "the way for us!\p"
# 615 "data/maps/LilycoveCity/scripts.pory"
	.string "That got the Wailmer out of the cove,\n"
# 616 "data/maps/LilycoveCity/scripts.pory"
	.string "so we can get our boats out again.$"
# 617 "data/maps/LilycoveCity/scripts.pory"

# 618 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeoneStoleMyPokemon:
# 619 "data/maps/LilycoveCity/scripts.pory"
	.string "I was taking a relaxing snooze at the\n"
# 620 "data/maps/LilycoveCity/scripts.pory"
	.string "seaside inn to the sound of waves…\p"
# 621 "data/maps/LilycoveCity/scripts.pory"
	.string "When someone stole my Pokémon!\p"
# 622 "data/maps/LilycoveCity/scripts.pory"
	.string "Who's the abductor?\n"
# 623 "data/maps/LilycoveCity/scripts.pory"
	.string "Team Aqua? Is it Team Aqua?$"
# 624 "data/maps/LilycoveCity/scripts.pory"

# 625 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MissingPokemonCameBack:
# 626 "data/maps/LilycoveCity/scripts.pory"
	.string "My missing Pokémon…\n"
# 627 "data/maps/LilycoveCity/scripts.pory"
	.string "It came back without me noticing!$"
# 628 "data/maps/LilycoveCity/scripts.pory"

# 629 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImArtDealer:
# 630 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm an art dealer.\p"
# 631 "data/maps/LilycoveCity/scripts.pory"
	.string "I buy and sell fine art,\n"
# 632 "data/maps/LilycoveCity/scripts.pory"
	.string "especially paintings.\p"
# 633 "data/maps/LilycoveCity/scripts.pory"
	.string "I've heard that the Museum here has\n"
# 634 "data/maps/LilycoveCity/scripts.pory"
	.string "magnificent works on exhibit…$"
# 635 "data/maps/LilycoveCity/scripts.pory"

# 636 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SeaRemainsForeverYoung:
# 637 "data/maps/LilycoveCity/scripts.pory"
	.string "Even as we grow old and wrinkled,\n"
# 638 "data/maps/LilycoveCity/scripts.pory"
	.string "the sea remains forever young with\l"
# 639 "data/maps/LilycoveCity/scripts.pory"
	.string "the vivid brilliance of life…\p"
# 640 "data/maps/LilycoveCity/scripts.pory"
	.string "Fwohoho fwohohohoho…$"
# 641 "data/maps/LilycoveCity/scripts.pory"

# 642 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
# 643 "data/maps/LilycoveCity/scripts.pory"
	.string "It was sixty years ago that my husband\n"
# 644 "data/maps/LilycoveCity/scripts.pory"
	.string "proposed to me here.\l"
# 645 "data/maps/LilycoveCity/scripts.pory"
	.string "The sea remains as beautiful as ever.\p"
# 646 "data/maps/LilycoveCity/scripts.pory"
	.string "Mufufufu mufufufufufu…$"
# 647 "data/maps/LilycoveCity/scripts.pory"

# 648 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaRenovatedCavern:
# 649 "data/maps/LilycoveCity/scripts.pory"
	.string "Hm, you know of the peculiar cavern\n"
# 650 "data/maps/LilycoveCity/scripts.pory"
	.string "in this cove?\p"
# 651 "data/maps/LilycoveCity/scripts.pory"
	.string "That had been a natural formation,\n"
# 652 "data/maps/LilycoveCity/scripts.pory"
	.string "but then that Team Aqua lot came\l"
# 653 "data/maps/LilycoveCity/scripts.pory"
	.string "along and made their renovations.\p"
# 654 "data/maps/LilycoveCity/scripts.pory"
	.string "They call themselves\n"
# 655 "data/maps/LilycoveCity/scripts.pory"
	.string "the “nature-loving Team Aqua”!\p"
# 656 "data/maps/LilycoveCity/scripts.pory"
	.string "But what they do and what they say\n"
# 657 "data/maps/LilycoveCity/scripts.pory"
	.string "don't match at all!$"
# 658 "data/maps/LilycoveCity/scripts.pory"

# 659 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaLotGoneForGood:
# 660 "data/maps/LilycoveCity/scripts.pory"
	.string "That cave in the cove…\p"
# 661 "data/maps/LilycoveCity/scripts.pory"
	.string "I didn't notice it right away,\n"
# 662 "data/maps/LilycoveCity/scripts.pory"
	.string "but it's completely empty now.\p"
# 663 "data/maps/LilycoveCity/scripts.pory"
	.string "That Team Aqua lot, they must\n"
# 664 "data/maps/LilycoveCity/scripts.pory"
	.string "have gone away for good.$"
# 665 "data/maps/LilycoveCity/scripts.pory"

# 666 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_CitySign:
# 667 "data/maps/LilycoveCity/scripts.pory"
	.string "Lilycove City\p"
# 668 "data/maps/LilycoveCity/scripts.pory"
	.string "“Where the land ends and the\n"
# 669 "data/maps/LilycoveCity/scripts.pory"
	.string "sea begins.”$"
# 670 "data/maps/LilycoveCity/scripts.pory"

# 671 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallSign:
# 672 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokémon Contest Hall\n"
# 673 "data/maps/LilycoveCity/scripts.pory"
	.string "“The gathering place for Trainers!”$"
# 674 "data/maps/LilycoveCity/scripts.pory"

# 675 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MotelSign:
# 676 "data/maps/LilycoveCity/scripts.pory"
	.string "Cove Lily Motel\p"
# 677 "data/maps/LilycoveCity/scripts.pory"
	.string "“Remember us as Cove Lily of\n"
# 678 "data/maps/LilycoveCity/scripts.pory"
	.string "Lilycove.”$"
# 679 "data/maps/LilycoveCity/scripts.pory"

# 680 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSign:
# 681 "data/maps/LilycoveCity/scripts.pory"
	.string "Lilycove Museum\p"
# 682 "data/maps/LilycoveCity/scripts.pory"
	.string "“Pokémon Masterpiece Collection\n"
# 683 "data/maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 684 "data/maps/LilycoveCity/scripts.pory"

# 685 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSignPlayersExhibit:
# 686 "data/maps/LilycoveCity/scripts.pory"
	.string "Lilycove Museum\p"
# 687 "data/maps/LilycoveCity/scripts.pory"
	.string "“{PLAYER}'s Pokémon Collection\n"
# 688 "data/maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 689 "data/maps/LilycoveCity/scripts.pory"

# 690 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSignUnderConstruction:
# 691 "data/maps/LilycoveCity/scripts.pory"
	.string "Lilycove City Harbor\p"
# 692 "data/maps/LilycoveCity/scripts.pory"
	.string "“The ferry S.S. Tidal is under\n"
# 693 "data/maps/LilycoveCity/scripts.pory"
	.string "construction in Slateport City.\p"
# 694 "data/maps/LilycoveCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 695 "data/maps/LilycoveCity/scripts.pory"
	.string "shortly.”$"
# 696 "data/maps/LilycoveCity/scripts.pory"

# 697 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSign:
# 698 "data/maps/LilycoveCity/scripts.pory"
	.string "Lilycove City Harbor\p"
# 699 "data/maps/LilycoveCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 700 "data/maps/LilycoveCity/scripts.pory"
	.string "the ferry S.S. Tidal.”$"
# 701 "data/maps/LilycoveCity/scripts.pory"

# 702 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TrainerFanClubSign:
# 703 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokémon Trainer Fan Club\p"
# 704 "data/maps/LilycoveCity/scripts.pory"
	.string "The names of Trainers are scribbled\n"
# 705 "data/maps/LilycoveCity/scripts.pory"
	.string "all over the sign…$"
# 706 "data/maps/LilycoveCity/scripts.pory"

# 707 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DepartmentStoreSign:
# 708 "data/maps/LilycoveCity/scripts.pory"
	.string "Lilycove Department Store\p"
# 709 "data/maps/LilycoveCity/scripts.pory"
	.string "“Overflowing with great merchandise\n"
# 710 "data/maps/LilycoveCity/scripts.pory"
	.string "and excitement!\p"
# 711 "data/maps/LilycoveCity/scripts.pory"
	.string "“A great place to find that something\n"
# 712 "data/maps/LilycoveCity/scripts.pory"
	.string "you need!”$"
# 713 "data/maps/LilycoveCity/scripts.pory"

# 714 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MoveDeletersHouseSign:
# 715 "data/maps/LilycoveCity/scripts.pory"
	.string "Move Deleter's House\p"
# 716 "data/maps/LilycoveCity/scripts.pory"
	.string "“Unwanted Pokémon moves deleted.”$"
# 717 "data/maps/LilycoveCity/scripts.pory"

# 718 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DoYouKnowAboutBerryBlender:
# 719 "data/maps/LilycoveCity/scripts.pory"
	.string "Do you know about the machine\n"
# 720 "data/maps/LilycoveCity/scripts.pory"
	.string "Berry Blender?$"
# 721 "data/maps/LilycoveCity/scripts.pory"

# 722 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_FasterSpinBetterPokeblocks:
# 723 "data/maps/LilycoveCity/scripts.pory"
	.string "People have to work together to get it\n"
# 724 "data/maps/LilycoveCity/scripts.pory"
	.string "to spin faster.\p"
# 725 "data/maps/LilycoveCity/scripts.pory"
	.string "The faster you can make it spin, the\n"
# 726 "data/maps/LilycoveCity/scripts.pory"
	.string "better {POKEBLOCK}s you can get, I've heard.$"
# 727 "data/maps/LilycoveCity/scripts.pory"

# 728 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ExplainBerryBlender:
# 729 "data/maps/LilycoveCity/scripts.pory"
	.string "It's used for making a kind of candy\n"
# 730 "data/maps/LilycoveCity/scripts.pory"
	.string "called a {POKEBLOCK}.\p"
# 731 "data/maps/LilycoveCity/scripts.pory"
	.string "If you give a good {POKEBLOCK} to a Pokémon,\n"
# 732 "data/maps/LilycoveCity/scripts.pory"
	.string "its condition will improve by a lot.$"
# 733 "data/maps/LilycoveCity/scripts.pory"

# 734 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HeardTowerCalledSkyPillar:
# 735 "data/maps/LilycoveCity/scripts.pory"
	.string "I heard there's a tower somewhere out\n"
# 736 "data/maps/LilycoveCity/scripts.pory"
	.string "on the sea routes.\p"
# 737 "data/maps/LilycoveCity/scripts.pory"
	.string "It's called the Sky Pillar, I hear.$"
# 738 "data/maps/LilycoveCity/scripts.pory"

# 739 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SawTallTowerOnRoute131:
# 740 "data/maps/LilycoveCity/scripts.pory"
	.string "I saw this tall tower somewhere\n"
# 741 "data/maps/LilycoveCity/scripts.pory"
	.string "around Route 131.\p"
# 742 "data/maps/LilycoveCity/scripts.pory"
	.string "Could that possibly be…?$"
# 743 "data/maps/LilycoveCity/scripts.pory"

# 744 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_JustArrivedAndSawRarePokemon:
# 745 "data/maps/LilycoveCity/scripts.pory"
	.string "We just arrived here on our\n"
# 746 "data/maps/LilycoveCity/scripts.pory"
	.string "honeymoon vacation.\p"
# 747 "data/maps/LilycoveCity/scripts.pory"
	.string "We happened to see a Dragon-type\n"
# 748 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokémon flying way up in the sky.\p"
# 749 "data/maps/LilycoveCity/scripts.pory"
	.string "Do cool Pokémon like that live in\n"
# 750 "data/maps/LilycoveCity/scripts.pory"
	.string "the Hoenn region?$"
# 751 "data/maps/LilycoveCity/scripts.pory"

# 752 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
# 753 "data/maps/LilycoveCity/scripts.pory"
	.string "On our honeymoon, we vowed to see as\n"
# 754 "data/maps/LilycoveCity/scripts.pory"
	.string "many rare Pokémon as we can.\p"
# 755 "data/maps/LilycoveCity/scripts.pory"
	.string "So we were delighted to see a rare\n"
# 756 "data/maps/LilycoveCity/scripts.pory"
	.string "Pokémon as soon as we arrived.\p"
# 757 "data/maps/LilycoveCity/scripts.pory"
	.string "I mean, we are totally happy!$"

_LilycoveCity_EventScript_MoveDeletersHouseSign::
# 761 "data/maps/LilycoveCity/scripts.pory"
	msgbox _LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end


_LilycoveCity_Text_MoveDeletersHouseSign::
# 765 "data/maps/LilycoveCity/scripts.pory"
	.string "Someone tried to scratch the old name\n"
	.string "plate off the sign...\p"
	.string "The phrase “Pokémon moves deleted.”\n"
	.string "is barely legible underneath.$"
