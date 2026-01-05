# 1 "data/maps/Route118/scripts.pory"

# 2 "data/maps/Route118/scripts.pory"
Route118_MapScripts::
# 3 "data/maps/Route118/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route118_OnTransition
# 4 "data/maps/Route118/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route118_OnLoad
# 5 "data/maps/Route118/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route118_OnFrame
# 6 "data/maps/Route118/scripts.pory"
	.byte 0
# 7 "data/maps/Route118/scripts.pory"

# 8 "data/maps/Route118/scripts.pory"
Route118_OnTransition:
# 9 "data/maps/Route118/scripts.pory"
	call GabbyAndTy_EventScript_UpdateLocation
# 10 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
# 11 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_StartGroudonWeather
# 12 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_StartGroudonWeather
# 13 "data/maps/Route118/scripts.pory"
	end
# 14 "data/maps/Route118/scripts.pory"

# 15 "data/maps/Route118/scripts.pory"
Route118_OnLoad:
# 16 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_EAST, AbnormalWeather_EventScript_PlaceTilesRoute118East
# 17 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_118_WEST, AbnormalWeather_EventScript_PlaceTilesRoute118West
# 18 "data/maps/Route118/scripts.pory"
	end
# 19 "data/maps/Route118/scripts.pory"

# 20 "data/maps/Route118/scripts.pory"
Route118_OnFrame:
# 21 "data/maps/Route118/scripts.pory"
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
# 22 "data/maps/Route118/scripts.pory"
	.2byte 0
# 23 "data/maps/Route118/scripts.pory"

# 24 "data/maps/Route118/scripts.pory"
Route118_EventScript_GoodRodFisherman::
# 25 "data/maps/Route118/scripts.pory"
	lock
# 26 "data/maps/Route118/scripts.pory"
	faceplayer
# 27 "data/maps/Route118/scripts.pory"
	goto_if_set FLAG_RECEIVED_GOOD_ROD, Route118_EventScript_ReceivedGoodRod
# 28 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_YouAgreeGoodRodIsGood, MSGBOX_YESNO
# 29 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route118_EventScript_ReceiveGoodRod
# 30 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route118_EventScript_DeclineGoodRod
# 31 "data/maps/Route118/scripts.pory"
	end
# 32 "data/maps/Route118/scripts.pory"

# 33 "data/maps/Route118/scripts.pory"
Route118_EventScript_ReceiveGoodRod::
# 34 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_IdenticalMindsTakeThis, MSGBOX_DEFAULT
# 35 "data/maps/Route118/scripts.pory"
	giveitem ITEM_GOOD_ROD
# 36 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 37 "data/maps/Route118/scripts.pory"
	setflag FLAG_RECEIVED_GOOD_ROD
# 38 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_TryYourLuckFishing, MSGBOX_DEFAULT
# 39 "data/maps/Route118/scripts.pory"
	release
# 40 "data/maps/Route118/scripts.pory"
	end
# 41 "data/maps/Route118/scripts.pory"

# 42 "data/maps/Route118/scripts.pory"
Route118_EventScript_DeclineGoodRod::
# 43 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DontYouLikeToFish, MSGBOX_DEFAULT
# 44 "data/maps/Route118/scripts.pory"
	release
# 45 "data/maps/Route118/scripts.pory"
	end
# 46 "data/maps/Route118/scripts.pory"

# 47 "data/maps/Route118/scripts.pory"
Route118_EventScript_ReceivedGoodRod::
# 48 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_TryCatchingMonWithGoodRod, MSGBOX_DEFAULT
# 49 "data/maps/Route118/scripts.pory"
	release
# 50 "data/maps/Route118/scripts.pory"
	end
# 51 "data/maps/Route118/scripts.pory"

# 52 "data/maps/Route118/scripts.pory"
Route118_EventScript_Girl::
# 53 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_CanCrossRiversWithSurf, MSGBOX_NPC
# 54 "data/maps/Route118/scripts.pory"
	end
# 55 "data/maps/Route118/scripts.pory"

# 56 "data/maps/Route118/scripts.pory"
Route118_EventScript_RouteSignMauville::
# 57 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RouteSignMauville, MSGBOX_SIGN
# 58 "data/maps/Route118/scripts.pory"
	end
# 59 "data/maps/Route118/scripts.pory"

# 60 "data/maps/Route118/scripts.pory"
Route118_EventScript_RouteSign119::
# 61 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RouteSign119, MSGBOX_SIGN
# 62 "data/maps/Route118/scripts.pory"
	end
# 63 "data/maps/Route118/scripts.pory"

# 64 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger0::
# 65 "data/maps/Route118/scripts.pory"
	lockall
# 66 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 0
# 67 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 68 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 69 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenApproachLedge0
# 70 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 71 "data/maps/Route118/scripts.pory"
	goto Route118_EventScript_StevenTrigger
# 72 "data/maps/Route118/scripts.pory"
	end
# 73 "data/maps/Route118/scripts.pory"

# 74 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger1::
# 75 "data/maps/Route118/scripts.pory"
	lockall
# 76 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 1
# 77 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 78 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 79 "data/maps/Route118/scripts.pory"
	goto Route118_EventScript_StevenTrigger
# 80 "data/maps/Route118/scripts.pory"
	end
# 81 "data/maps/Route118/scripts.pory"

# 82 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger2::
# 83 "data/maps/Route118/scripts.pory"
	lockall
# 84 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 2
# 85 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 86 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 87 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenApproachLedge2
# 88 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 89 "data/maps/Route118/scripts.pory"
	goto Route118_EventScript_StevenTrigger
# 90 "data/maps/Route118/scripts.pory"
	end
# 91 "data/maps/Route118/scripts.pory"

# 92 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenTrigger::
# 93 "data/maps/Route118/scripts.pory"
	playse SE_LEDGE
# 94 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenJumpLedge
# 95 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 96 "data/maps/Route118/scripts.pory"
	delay 30
# 97 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_StevenQuestions, MSGBOX_DEFAULT
# 98 "data/maps/Route118/scripts.pory"
	closemessage
# 99 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route118_EventScript_StevenExit0
# 100 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route118_EventScript_StevenExit1
# 101 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route118_EventScript_StevenExit2
# 102 "data/maps/Route118/scripts.pory"
	setvar VAR_ROUTE118_STATE, 1
# 103 "data/maps/Route118/scripts.pory"
	removeobject LOCALID_ROUTE118_STEVEN
# 104 "data/maps/Route118/scripts.pory"
	releaseall
# 105 "data/maps/Route118/scripts.pory"
	end
# 106 "data/maps/Route118/scripts.pory"

# 107 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenExit0::
# 108 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 109 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenExit0
# 110 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 111 "data/maps/Route118/scripts.pory"
	return
# 112 "data/maps/Route118/scripts.pory"

# 113 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenExit1::
# 114 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 115 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenExit1
# 116 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 117 "data/maps/Route118/scripts.pory"
	return
# 118 "data/maps/Route118/scripts.pory"

# 119 "data/maps/Route118/scripts.pory"
Route118_EventScript_StevenExit2::
# 120 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_PLAYER, Route118_Movement_PlayerWatchStevenExit
# 121 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_STEVEN, Route118_Movement_StevenExit2
# 122 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 123 "data/maps/Route118/scripts.pory"
	return
# 124 "data/maps/Route118/scripts.pory"

# 125 "data/maps/Route118/scripts.pory"
Route118_Movement_PlayerWatchStevenExit:
# 126 "data/maps/Route118/scripts.pory"
	delay_16
# 127 "data/maps/Route118/scripts.pory"
	walk_in_place_faster_right
# 128 "data/maps/Route118/scripts.pory"
	step_end
# 129 "data/maps/Route118/scripts.pory"

# 130 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenApproachLedge0:
# 131 "data/maps/Route118/scripts.pory"
	walk_left
# 132 "data/maps/Route118/scripts.pory"
	step_end
# 133 "data/maps/Route118/scripts.pory"

# 134 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenApproachLedge2:
# 135 "data/maps/Route118/scripts.pory"
	walk_right
# 136 "data/maps/Route118/scripts.pory"
	step_end
# 137 "data/maps/Route118/scripts.pory"

# 138 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenJumpLedge:
# 139 "data/maps/Route118/scripts.pory"
	jump_2_down
# 140 "data/maps/Route118/scripts.pory"
	delay_16
# 141 "data/maps/Route118/scripts.pory"
	walk_down
# 142 "data/maps/Route118/scripts.pory"
	step_end
# 143 "data/maps/Route118/scripts.pory"

# 144 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenExit0:
# 145 "data/maps/Route118/scripts.pory"
	walk_right
# 146 "data/maps/Route118/scripts.pory"
	walk_right
# 147 "data/maps/Route118/scripts.pory"
	walk_right
# 148 "data/maps/Route118/scripts.pory"
	walk_right
# 149 "data/maps/Route118/scripts.pory"
	walk_right
# 150 "data/maps/Route118/scripts.pory"
	walk_right
# 151 "data/maps/Route118/scripts.pory"
	walk_right
# 152 "data/maps/Route118/scripts.pory"
	walk_right
# 153 "data/maps/Route118/scripts.pory"
	walk_right
# 154 "data/maps/Route118/scripts.pory"
	walk_right
# 155 "data/maps/Route118/scripts.pory"
	step_end
# 156 "data/maps/Route118/scripts.pory"

# 157 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenExit1:
# 158 "data/maps/Route118/scripts.pory"
	walk_right
# 159 "data/maps/Route118/scripts.pory"
	walk_right
# 160 "data/maps/Route118/scripts.pory"
	walk_right
# 161 "data/maps/Route118/scripts.pory"
	walk_right
# 162 "data/maps/Route118/scripts.pory"
	walk_right
# 163 "data/maps/Route118/scripts.pory"
	walk_right
# 164 "data/maps/Route118/scripts.pory"
	walk_right
# 165 "data/maps/Route118/scripts.pory"
	walk_right
# 166 "data/maps/Route118/scripts.pory"
	walk_right
# 167 "data/maps/Route118/scripts.pory"
	step_end
# 168 "data/maps/Route118/scripts.pory"

# 169 "data/maps/Route118/scripts.pory"
Route118_Movement_StevenExit2:
# 170 "data/maps/Route118/scripts.pory"
	walk_right
# 171 "data/maps/Route118/scripts.pory"
	walk_right
# 172 "data/maps/Route118/scripts.pory"
	walk_right
# 173 "data/maps/Route118/scripts.pory"
	walk_right
# 174 "data/maps/Route118/scripts.pory"
	walk_right
# 175 "data/maps/Route118/scripts.pory"
	walk_right
# 176 "data/maps/Route118/scripts.pory"
	walk_right
# 177 "data/maps/Route118/scripts.pory"
	walk_right
# 178 "data/maps/Route118/scripts.pory"
	step_end
# 179 "data/maps/Route118/scripts.pory"

# 180 "data/maps/Route118/scripts.pory"
Route118_EventScript_Rose::
# 181 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_ROSE_1, Route118_Text_RoseIntro, Route118_Text_RoseDefeat, Route118_EventScript_RegisterRose
# 182 "data/maps/Route118/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 183 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route118_EventScript_RematchRose
# 184 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RosePostBattle, MSGBOX_DEFAULT
# 185 "data/maps/Route118/scripts.pory"
	release
# 186 "data/maps/Route118/scripts.pory"
	end
# 187 "data/maps/Route118/scripts.pory"

# 188 "data/maps/Route118/scripts.pory"
Route118_EventScript_RegisterRose::
# 189 "data/maps/Route118/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 190 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 191 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RoseRegister, MSGBOX_DEFAULT
# 192 "data/maps/Route118/scripts.pory"
	register_matchcall TRAINER_ROSE_1
# 193 "data/maps/Route118/scripts.pory"
	release
# 194 "data/maps/Route118/scripts.pory"
	end
# 195 "data/maps/Route118/scripts.pory"

# 196 "data/maps/Route118/scripts.pory"
Route118_EventScript_RematchRose::
# 197 "data/maps/Route118/scripts.pory"
	trainerbattle_rematch TRAINER_ROSE_1, Route118_Text_RoseRematchIntro, Route118_Text_RoseRematchDefeat
# 198 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_RosePostRematch, MSGBOX_AUTOCLOSE
# 199 "data/maps/Route118/scripts.pory"
	end
# 200 "data/maps/Route118/scripts.pory"

# 201 "data/maps/Route118/scripts.pory"
Route118_EventScript_Barny::
# 202 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_BARNY, Route118_Text_BarnyIntro, Route118_Text_BarnyDefeat
# 203 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_BarnyPostBattle, MSGBOX_AUTOCLOSE
# 204 "data/maps/Route118/scripts.pory"
	end
# 205 "data/maps/Route118/scripts.pory"

# 206 "data/maps/Route118/scripts.pory"
Route118_EventScript_Wade::
# 207 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_WADE, Route118_Text_WadeIntro, Route118_Text_WadeDefeat
# 208 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_WadePostBattle, MSGBOX_AUTOCLOSE
# 209 "data/maps/Route118/scripts.pory"
	end
# 210 "data/maps/Route118/scripts.pory"

# 211 "data/maps/Route118/scripts.pory"
Route118_EventScript_Dalton::
# 212 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_DALTON_1, Route118_Text_DaltonIntro, Route118_Text_DaltonDefeat, Route118_EventScript_RegisterDalton
# 213 "data/maps/Route118/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 214 "data/maps/Route118/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route118_EventScript_RematchDalton
# 215 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonPostBattle, MSGBOX_DEFAULT
# 216 "data/maps/Route118/scripts.pory"
	release
# 217 "data/maps/Route118/scripts.pory"
	end
# 218 "data/maps/Route118/scripts.pory"

# 219 "data/maps/Route118/scripts.pory"
Route118_EventScript_RegisterDalton::
# 220 "data/maps/Route118/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 221 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 222 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonRegister, MSGBOX_DEFAULT
# 223 "data/maps/Route118/scripts.pory"
	register_matchcall TRAINER_DALTON_1
# 224 "data/maps/Route118/scripts.pory"
	release
# 225 "data/maps/Route118/scripts.pory"
	end
# 226 "data/maps/Route118/scripts.pory"

# 227 "data/maps/Route118/scripts.pory"
Route118_EventScript_RematchDalton::
# 228 "data/maps/Route118/scripts.pory"
	trainerbattle_rematch TRAINER_DALTON_1, Route118_Text_DaltonRematchIntro, Route118_Text_DaltonRematchDefeat
# 229 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DaltonPostRematch, MSGBOX_AUTOCLOSE
# 230 "data/maps/Route118/scripts.pory"
	end
# 231 "data/maps/Route118/scripts.pory"

# 232 "data/maps/Route118/scripts.pory"
Route118_EventScript_Perry::
# 233 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_PERRY, Route118_Text_PerryIntro, Route118_Text_PerryDefeat
# 234 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_PerryPostBattle, MSGBOX_AUTOCLOSE
# 235 "data/maps/Route118/scripts.pory"
	end
# 236 "data/maps/Route118/scripts.pory"

# 237 "data/maps/Route118/scripts.pory"
Route118_EventScript_Chester::
# 238 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_CHESTER, Route118_Text_ChesterIntro, Route118_Text_ChesterDefeat
# 239 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_ChesterPostBattle, MSGBOX_AUTOCLOSE
# 240 "data/maps/Route118/scripts.pory"
	end
# 241 "data/maps/Route118/scripts.pory"

# 242 "data/maps/Route118/scripts.pory"
Route118_EventScript_Deandre::
# 243 "data/maps/Route118/scripts.pory"
	trainerbattle_single TRAINER_DEANDRE, Route118_Text_DeandreIntro, Route118_Text_DeandreDefeat
# 244 "data/maps/Route118/scripts.pory"
	msgbox Route118_Text_DeandrePostBattle, MSGBOX_AUTOCLOSE
# 245 "data/maps/Route118/scripts.pory"
	end
# 246 "data/maps/Route118/scripts.pory"

# 247 "data/maps/Route118/scripts.pory"
Route118_Text_StevenQuestions:
# 248 "data/maps/Route118/scripts.pory"
	.string "Steven: Hi, {PLAYER}{KUN}!\p"
# 249 "data/maps/Route118/scripts.pory"
	.string "It's me, Steven!\n"
# 250 "data/maps/Route118/scripts.pory"
	.string "We met in the cave near Dewford.\p"
# 251 "data/maps/Route118/scripts.pory"
	.string "Have you met many kinds of Pokémon\n"
# 252 "data/maps/Route118/scripts.pory"
	.string "since I last saw you?\p"
# 253 "data/maps/Route118/scripts.pory"
	.string "There are many, many kinds of Pokémon\n"
# 254 "data/maps/Route118/scripts.pory"
	.string "in this wide world of ours.\p"
# 255 "data/maps/Route118/scripts.pory"
	.string "If you wanted to raise only your\n"
# 256 "data/maps/Route118/scripts.pory"
	.string "favorites, that's fine.\p"
# 257 "data/maps/Route118/scripts.pory"
	.string "Perhaps you find it more fun to raise\n"
# 258 "data/maps/Route118/scripts.pory"
	.string "all sorts of Pokémon.\p"
# 259 "data/maps/Route118/scripts.pory"
	.string "As a Trainer of Pokémon,\n"
# 260 "data/maps/Route118/scripts.pory"
	.string "what do you think?\p"
# 261 "data/maps/Route118/scripts.pory"
	.string "Of course, it's not any of my business.\p"
# 262 "data/maps/Route118/scripts.pory"
	.string "It would be nice if we were to meet\n"
# 263 "data/maps/Route118/scripts.pory"
	.string "again somewhere.$"
# 264 "data/maps/Route118/scripts.pory"

# 265 "data/maps/Route118/scripts.pory"
Route118_Text_YouAgreeGoodRodIsGood:
# 266 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
# 267 "data/maps/Route118/scripts.pory"
	.string "A Good Rod is really good!\p"
# 268 "data/maps/Route118/scripts.pory"
	.string "Wouldn't you agree?$"
# 269 "data/maps/Route118/scripts.pory"

# 270 "data/maps/Route118/scripts.pory"
Route118_Text_IdenticalMindsTakeThis:
# 271 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
# 272 "data/maps/Route118/scripts.pory"
	.string "We're of identical minds!\p"
# 273 "data/maps/Route118/scripts.pory"
	.string "Hmm!\n"
# 274 "data/maps/Route118/scripts.pory"
	.string "Take this Good Rod!$"
# 275 "data/maps/Route118/scripts.pory"

# 276 "data/maps/Route118/scripts.pory"
Route118_Text_TryYourLuckFishing:
# 277 "data/maps/Route118/scripts.pory"
	.string "Wherever there's water, try your luck\n"
# 278 "data/maps/Route118/scripts.pory"
	.string "at fishing.$"
# 279 "data/maps/Route118/scripts.pory"

# 280 "data/maps/Route118/scripts.pory"
Route118_Text_DontYouLikeToFish:
# 281 "data/maps/Route118/scripts.pory"
	.string "Don't you like to fish?$"
# 282 "data/maps/Route118/scripts.pory"

# 283 "data/maps/Route118/scripts.pory"
Route118_Text_TryCatchingMonWithGoodRod:
# 284 "data/maps/Route118/scripts.pory"
	.string "Try catching all sorts of Pokémon\n"
# 285 "data/maps/Route118/scripts.pory"
	.string "with your Good Rod.$"
# 286 "data/maps/Route118/scripts.pory"

# 287 "data/maps/Route118/scripts.pory"
Route118_Text_CanCrossRiversWithSurf:
# 288 "data/maps/Route118/scripts.pory"
	.string "Even if there isn't a boat, you can\n"
# 289 "data/maps/Route118/scripts.pory"
	.string "cross rivers and the sea if you have\l"
# 290 "data/maps/Route118/scripts.pory"
	.string "a Pokémon that knows Surf.\p"
# 291 "data/maps/Route118/scripts.pory"
	.string "Pokémon can be counted on to do so\n"
# 292 "data/maps/Route118/scripts.pory"
	.string "much!$"
# 293 "data/maps/Route118/scripts.pory"

# 294 "data/maps/Route118/scripts.pory"
Route118_Text_RouteSignMauville:
# 295 "data/maps/Route118/scripts.pory"
	.string "Route 118\n"
# 296 "data/maps/Route118/scripts.pory"
	.string "{LEFT_ARROW} Mauville City$"
# 297 "data/maps/Route118/scripts.pory"

# 298 "data/maps/Route118/scripts.pory"
Route118_Text_RouteSign119:
# 299 "data/maps/Route118/scripts.pory"
	.string "Route 118\n"
# 300 "data/maps/Route118/scripts.pory"
	.string "{UP_ARROW} Route 119$"

Route118_EventScript_WallyTrigger0::
# 305 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 0
# 306 "data/maps/Route118/scripts.pory"
	call Route118_EventScript_Wally
	end


Route118_EventScript_WallyTrigger1::
# 311 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 1
# 312 "data/maps/Route118/scripts.pory"
	call Route118_EventScript_Wally
	end


Route118_EventScript_WallyTrigger2::
# 317 "data/maps/Route118/scripts.pory"
	setvar VAR_0x8008, 2
# 318 "data/maps/Route118/scripts.pory"
	call Route118_EventScript_Wally
	end


Route118_EventScript_Wally::
# 323 "data/maps/Route118/scripts.pory"
	lockall
# 324 "data/maps/Route118/scripts.pory"
	playbgm MUS_ENCOUNTER_MALE, FALSE
# 325 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_WALLY, Common_Movement_ExclamationMark
# 326 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 327 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_WALLY, Common_Movement_Delay48
# 328 "data/maps/Route118/scripts.pory"
	waitmovement 0
# 329 "data/maps/Route118/scripts.pory"
	delay 30
# 330 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route110_EventScript_WallyApproachPlayer0
# 331 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route110_EventScript_WallyApproachPlayer1
# 332 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route110_EventScript_WallyApproachPlayer2
# 333 "data/maps/Route118/scripts.pory"
	msgbox Route118_Wally_Intro
# 334 "data/maps/Route118/scripts.pory"
	trainerbattle_no_intro TRAINER_WALLY_ROUTE_118, Route118_Wally_Defeat
# 335 "data/maps/Route118/scripts.pory"
	msgbox Route118_Wally_PostBattle
# 336 "data/maps/Route118/scripts.pory"
	closemessage
# 337 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 0, Route118_EventScript_WallyExit0
# 338 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 1, Route118_EventScript_WallyExit1
# 339 "data/maps/Route118/scripts.pory"
	call_if_eq VAR_0x8008, 2, Route118_EventScript_WallyExit2
# 340 "data/maps/Route118/scripts.pory"
	setvar VAR_ROUTE118_STATE, 2
# 341 "data/maps/Route118/scripts.pory"
	removeobject LOCALID_ROUTE118_WALLY
# 342 "data/maps/Route118/scripts.pory"
	releaseall
	end


Route110_EventScript_WallyApproachPlayer0::
# 347 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_WALLY, Route118_Movement_WallyApproachPlayer0
# 348 "data/maps/Route118/scripts.pory"
	waitmovement 0
	return


Route110_EventScript_WallyApproachPlayer1::
# 353 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_WALLY, Route118_Movement_WallyApproachPlayer1
# 354 "data/maps/Route118/scripts.pory"
	waitmovement 0
	return


Route110_EventScript_WallyApproachPlayer2::
# 359 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_WALLY, Route118_Movement_WallyApproachPlayer2
# 360 "data/maps/Route118/scripts.pory"
	waitmovement 0
	return


Route118_EventScript_WallyExit0::
# 365 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_PLAYER, Route118_Movement_PlayerWatchWallyExit
# 366 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_WALLY, Route118_Movement_WallyExit0
# 367 "data/maps/Route118/scripts.pory"
	waitmovement 0
	return


Route118_EventScript_WallyExit1::
# 372 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_PLAYER, Route118_Movement_PlayerWatchWallyExit
# 373 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_WALLY, Route118_Movement_WallyExit1
# 374 "data/maps/Route118/scripts.pory"
	waitmovement 0
	return


Route118_EventScript_WallyExit2::
# 379 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_PLAYER, Route118_Movement_PlayerWatchWallyExit2
# 380 "data/maps/Route118/scripts.pory"
	applymovement LOCALID_ROUTE118_WALLY, Route118_Movement_WallyExit2
# 381 "data/maps/Route118/scripts.pory"
	waitmovement 0
	return


# 406 "data/maps/Route118/scripts.pory"
Route118_Movement_WallyApproachPlayer0:
# 407 "data/maps/Route118/scripts.pory"
	walk_down
# 408 "data/maps/Route118/scripts.pory"
	walk_left
# 409 "data/maps/Route118/scripts.pory"
	walk_down
# 410 "data/maps/Route118/scripts.pory"
	walk_in_place_faster_down
# 411 "data/maps/Route118/scripts.pory"
	step_end

# 414 "data/maps/Route118/scripts.pory"
Route118_Movement_WallyApproachPlayer1:
# 415 "data/maps/Route118/scripts.pory"
	walk_down
# 416 "data/maps/Route118/scripts.pory"
	walk_down
# 417 "data/maps/Route118/scripts.pory"
	step_end

# 420 "data/maps/Route118/scripts.pory"
Route118_Movement_WallyApproachPlayer2:
# 421 "data/maps/Route118/scripts.pory"
	walk_down
# 422 "data/maps/Route118/scripts.pory"
	walk_right
# 423 "data/maps/Route118/scripts.pory"
	walk_down
# 424 "data/maps/Route118/scripts.pory"
	walk_in_place_faster_down
# 425 "data/maps/Route118/scripts.pory"
	step_end

# 428 "data/maps/Route118/scripts.pory"
Route118_Movement_WallyExit0:
# 429 "data/maps/Route118/scripts.pory"
	walk_right
# 430 "data/maps/Route118/scripts.pory"
	walk_down
# 431 "data/maps/Route118/scripts.pory"
	walk_down
# 432 "data/maps/Route118/scripts.pory"
	walk_down
# 433 "data/maps/Route118/scripts.pory"
	walk_down
# 434 "data/maps/Route118/scripts.pory"
	walk_down
# 435 "data/maps/Route118/scripts.pory"
	walk_down
# 436 "data/maps/Route118/scripts.pory"
	walk_down
# 437 "data/maps/Route118/scripts.pory"
	walk_down
	step_end

# 440 "data/maps/Route118/scripts.pory"
Route118_Movement_WallyExit1:
# 441 "data/maps/Route118/scripts.pory"
	walk_right
# 442 "data/maps/Route118/scripts.pory"
	walk_down
# 443 "data/maps/Route118/scripts.pory"
	walk_down
# 444 "data/maps/Route118/scripts.pory"
	walk_left
# 445 "data/maps/Route118/scripts.pory"
	walk_down
# 446 "data/maps/Route118/scripts.pory"
	walk_down
# 447 "data/maps/Route118/scripts.pory"
	walk_down
# 448 "data/maps/Route118/scripts.pory"
	walk_down
# 449 "data/maps/Route118/scripts.pory"
	walk_down
# 450 "data/maps/Route118/scripts.pory"
	walk_down
	step_end

# 453 "data/maps/Route118/scripts.pory"
Route118_Movement_WallyExit2:
# 454 "data/maps/Route118/scripts.pory"
	walk_left
# 455 "data/maps/Route118/scripts.pory"
	walk_down
# 456 "data/maps/Route118/scripts.pory"
	walk_down
# 457 "data/maps/Route118/scripts.pory"
	walk_down
# 458 "data/maps/Route118/scripts.pory"
	walk_down
# 459 "data/maps/Route118/scripts.pory"
	walk_down
# 460 "data/maps/Route118/scripts.pory"
	walk_down
# 461 "data/maps/Route118/scripts.pory"
	walk_down
# 462 "data/maps/Route118/scripts.pory"
	walk_down
	step_end

# 465 "data/maps/Route118/scripts.pory"
Route118_Movement_PlayerWatchWallyExit:
# 466 "data/maps/Route118/scripts.pory"
	delay_16
# 467 "data/maps/Route118/scripts.pory"
	walk_in_place_faster_right
# 468 "data/maps/Route118/scripts.pory"
	step_end

# 471 "data/maps/Route118/scripts.pory"
Route118_Movement_PlayerWatchWallyExit2:
# 472 "data/maps/Route118/scripts.pory"
	delay_16
# 473 "data/maps/Route118/scripts.pory"
	walk_in_place_faster_left
# 474 "data/maps/Route118/scripts.pory"
	step_end

Route118_Wally_Intro::
# 385 "data/maps/Route118/scripts.pory"
	.string "Oh! {PLAYER}! I… I didn't expect to\n"
	.string "see you here.\p"
	.string "Since we last met in Mauville, I’ve been\n"
	.string "thinking a lot about what it means to be\l"
	.string "a Trainer.\p"
	.string "I used to think catching a Pokémon was\n"
	.string "the end of the journey, but it was just\l"
	.string "the beginning.\p"
	.string "My lungs feel clearer, and my heart\n"
	.string "beats stronger whenever I’m with my\l"
	.string "team.\p"
	.string "The road ahead looks much steeper and\n"
	.string "the grass much taller than I imagined…\l"
	.string "but we’re ready to face it.\p"
	.string "{PLAYER}, you’re the one who showed me\n"
	.string "how to catch my first Pokémon. Please…\l"
	.string "let me show you how much we’ve grown\l"
	.string "together!$"

Route118_Wally_Defeat::
# 394 "data/maps/Route118/scripts.pory"
	.string "I see… Even now, I can feel the\n"
	.string "distance between us.$"

Route118_Wally_PostBattle::
# 398 "data/maps/Route118/scripts.pory"
	.string "Thank you, {PLAYER}. That battle… it\n"
	.string "told me everything I needed to know.\p"
	.string "I’m still not quite at your level, am I?\n"
	.string "But that’s okay. Seeing your strength\l"
	.string "only makes me want to work harder.\p"
	.string "The path ahead is wild and untamed, but\n"
	.string "I’m not afraid of it anymore. My Pokémon\l"
	.string "and I will find our own way through.\p"
	.string "I’ll keep training. I’ll get every badge,\n"
	.string "just like you. And one day… I’ll be the\l"
	.string "one waiting for you at the very end of\l"
	.string "the road!\p"
	.string "Take care, {PLAYER}. I’ll see you\n"
	.string "again!$"
