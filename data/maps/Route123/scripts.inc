# 1 "data/maps/Route123/scripts.pory"

# 2 "data/maps/Route123/scripts.pory"
Route123_MapScripts::
# 3 "data/maps/Route123/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route123_OnResume
# 4 "data/maps/Route123/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route123_OnTransition
# 5 "data/maps/Route123/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route123_OnLoad
# 6 "data/maps/Route123/scripts.pory"
	.byte 0
# 7 "data/maps/Route123/scripts.pory"

# 8 "data/maps/Route123/scripts.pory"
Route123_OnResume:
# 9 "data/maps/Route123/scripts.pory"
	call_if_eq VAR_ROUTE123_STATE, 0, Route123_EventScript_CheckHasGracidea
# 10 "data/maps/Route123/scripts.pory"
	end
# 11 "data/maps/Route123/scripts.pory"

# 12 "data/maps/Route123/scripts.pory"
Route123_EventScript_CheckHasGracidea::
# 13 "data/maps/Route123/scripts.pory"
	checkitem ITEM_GRACIDEA
# 14 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_SetReadyToOpenEntrance
# 15 "data/maps/Route123/scripts.pory"
	return
# 16 "data/maps/Route123/scripts.pory"

# 17 "data/maps/Route123/scripts.pory"
Route123_EventScript_SetReadyToOpenEntrance::
# 18 "data/maps/Route123/scripts.pory"
	setvar VAR_ROUTE123_STATE, 1
# 19 "data/maps/Route123/scripts.pory"
	return
# 20 "data/maps/Route123/scripts.pory"

# 21 "data/maps/Route123/scripts.pory"
Route123_OnTransition:
# 22 "data/maps/Route123/scripts.pory"
	special SetRoute123Weather
# 23 "data/maps/Route123/scripts.pory"
	end
# 24 "data/maps/Route123/scripts.pory"

# 25 "data/maps/Route123/scripts.pory"
Route123_OnLoad:
# 26 "data/maps/Route123/scripts.pory"
	goto_if_le VAR_ROUTE123_STATE, 1, Route123_EventScript_ConcealEntrance
# 27 "data/maps/Route123/scripts.pory"
	end
# 28 "data/maps/Route123/scripts.pory"

# 29 "data/maps/Route123/scripts.pory"
Route123_EventScript_ConcealEntrance::
# 30 "data/maps/Route123/scripts.pory"
    setmetatile 22, 0, METATILE_General_TreeTopOverlapBase, TRUE
# 31 "data/maps/Route123/scripts.pory"
    setmetatile 23, 0, METATILE_General_TreeTopOverlapBase, TRUE
# 32 "data/maps/Route123/scripts.pory"
	setmetatile 22, 1, METATILE_General_TreeTopOverlapBase, TRUE
# 33 "data/maps/Route123/scripts.pory"
	setmetatile 23, 1, METATILE_General_TreeTopOverlapBase, TRUE
# 34 "data/maps/Route123/scripts.pory"
    setmetatile 22, 2, METATILE_General_TreeBottomBase, TRUE
# 35 "data/maps/Route123/scripts.pory"
	setmetatile 23, 2, METATILE_General_TreeBottomBase, TRUE
# 36 "data/maps/Route123/scripts.pory"
	end
# 37 "data/maps/Route123/scripts.pory"

# 38 "data/maps/Route123/scripts.pory"
Route123_EventScript_OpenEntrance::
# 39 "data/maps/Route123/scripts.pory"
	lockall
# 40 "data/maps/Route123/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 41 "data/maps/Route123/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 42 "data/maps/Route123/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 43 "data/maps/Route123/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 44 "data/maps/Route123/scripts.pory"
	special ShakeCamera
# 45 "data/maps/Route123/scripts.pory"
	waitstate
# 46 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_EarthShakingInResponseToGracidea, MSGBOX_DEFAULT
# 47 "data/maps/Route123/scripts.pory"
	closemessage
# 48 "data/maps/Route123/scripts.pory"
	setvar VAR_0x8004, 1   @ vertical pan
# 49 "data/maps/Route123/scripts.pory"
	setvar VAR_0x8005, 1   @ horizontal pan
# 50 "data/maps/Route123/scripts.pory"
	setvar VAR_0x8006, 16  @ num shakes
# 51 "data/maps/Route123/scripts.pory"
	setvar VAR_0x8007, 3   @ shake delay
# 52 "data/maps/Route123/scripts.pory"
	special ShakeCamera
# 53 "data/maps/Route123/scripts.pory"
	waitstate
# 54 "data/maps/Route123/scripts.pory"
	playse SE_EFFECTIVE
# 55 "data/maps/Route123/scripts.pory"
    setmetatile 22, 0, METATILE_Rustboro_TreeBaseEntrance, TRUE
# 56 "data/maps/Route123/scripts.pory"
    setmetatile 23, 0, METATILE_Rustboro_TreeBaseEntrance, TRUE
# 57 "data/maps/Route123/scripts.pory"
	setmetatile 22, 1, METATILE_Rustboro_EntrancetoWoods, FALSE
# 58 "data/maps/Route123/scripts.pory"
	setmetatile 23, 1, METATILE_Rustboro_EntrancetoWoods, FALSE
# 59 "data/maps/Route123/scripts.pory"
    setmetatile 22, 2, METATILE_Rustboro_TileBeforeEntrance, FALSE
# 60 "data/maps/Route123/scripts.pory"
	setmetatile 23, 2, METATILE_Rustboro_TileBeforeEntrance, FALSE
# 61 "data/maps/Route123/scripts.pory"
	special DrawWholeMapView
# 62 "data/maps/Route123/scripts.pory"
	delay 30
# 63 "data/maps/Route123/scripts.pory"
	setvar VAR_ROUTE123_STATE, 2
# 64 "data/maps/Route123/scripts.pory"
	waitse
# 65 "data/maps/Route123/scripts.pory"
	releaseall
# 66 "data/maps/Route123/scripts.pory"
	end    
# 67 "data/maps/Route123/scripts.pory"

# 68 "data/maps/Route123/scripts.pory"
Route123_EventScript_GigaDrainGirl::
# 69 "data/maps/Route123/scripts.pory"
	lock
# 70 "data/maps/Route123/scripts.pory"
	faceplayer
# 71 "data/maps/Route123/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_GIGA_DRAIN, Route123_EventScript_ReceivedGigaDrain
# 72 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_LoveGrassMonsHaveAny, MSGBOX_DEFAULT
# 73 "data/maps/Route123/scripts.pory"
	special IsGrassTypeInParty
# 74 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route123_EventScript_NoGrassMons
# 75 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_YouLikeGrassMonsTooHaveThis, MSGBOX_DEFAULT
# 76 "data/maps/Route123/scripts.pory"
	giveitem ITEM_TM_GIGA_DRAIN
# 77 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 78 "data/maps/Route123/scripts.pory"
	setflag FLAG_RECEIVED_TM_GIGA_DRAIN
# 79 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
# 80 "data/maps/Route123/scripts.pory"
	release
# 81 "data/maps/Route123/scripts.pory"
	end
# 82 "data/maps/Route123/scripts.pory"

# 83 "data/maps/Route123/scripts.pory"
Route123_EventScript_NoGrassMons::
# 84 "data/maps/Route123/scripts.pory"
	release
# 85 "data/maps/Route123/scripts.pory"
	end
# 86 "data/maps/Route123/scripts.pory"

# 87 "data/maps/Route123/scripts.pory"
Route123_EventScript_ReceivedGigaDrain::
# 88 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CheckTreesWithMyGrassMon, MSGBOX_DEFAULT
# 89 "data/maps/Route123/scripts.pory"
	release
# 90 "data/maps/Route123/scripts.pory"
	end
# 91 "data/maps/Route123/scripts.pory"

# 92 "data/maps/Route123/scripts.pory"
Route123_EventScript_RouteSign::
# 93 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_RouteSign, MSGBOX_SIGN
# 94 "data/maps/Route123/scripts.pory"
	end
# 95 "data/maps/Route123/scripts.pory"

# 96 "data/maps/Route123/scripts.pory"
Route123_EventScript_RouteSignMtPyre::
# 97 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_RouteSignMtPyre, MSGBOX_SIGN
# 98 "data/maps/Route123/scripts.pory"
	end
# 99 "data/maps/Route123/scripts.pory"

# 100 "data/maps/Route123/scripts.pory"
Route123_EventScript_BerryMastersHouseSign::
# 101 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_BerryMastersHouse, MSGBOX_SIGN
# 102 "data/maps/Route123/scripts.pory"
	end
# 103 "data/maps/Route123/scripts.pory"

# 104 "data/maps/Route123/scripts.pory"
Route123_EventScript_Wendy::
# 105 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_WENDY, Route123_Text_WendyIntro, Route123_Text_WendyDefeat
# 106 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_WendyPostBattle, MSGBOX_AUTOCLOSE
# 107 "data/maps/Route123/scripts.pory"
	end
# 108 "data/maps/Route123/scripts.pory"

# 109 "data/maps/Route123/scripts.pory"
Route123_EventScript_Braxton::
# 110 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_BRAXTON, Route123_Text_BraxtonIntro, Route123_Text_BraxtonDefeat
# 111 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_BraxtonPostBattle, MSGBOX_AUTOCLOSE
# 112 "data/maps/Route123/scripts.pory"
	end
# 113 "data/maps/Route123/scripts.pory"

# 114 "data/maps/Route123/scripts.pory"
Route123_EventScript_Violet::
# 115 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_VIOLET, Route123_Text_VioletIntro, Route123_Text_VioletDefeat
# 116 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_VioletPostBattle, MSGBOX_AUTOCLOSE
# 117 "data/maps/Route123/scripts.pory"
	end
# 118 "data/maps/Route123/scripts.pory"

# 119 "data/maps/Route123/scripts.pory"
Route123_EventScript_Cameron::
# 120 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_CAMERON_1, Route123_Text_CameronIntro, Route123_Text_CameronDefeat, Route123_EventScript_RegisterCameron
# 121 "data/maps/Route123/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 122 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchCameron
# 123 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronPostBattle, MSGBOX_DEFAULT
# 124 "data/maps/Route123/scripts.pory"
	release
# 125 "data/maps/Route123/scripts.pory"
	end
# 126 "data/maps/Route123/scripts.pory"

# 127 "data/maps/Route123/scripts.pory"
Route123_EventScript_RegisterCameron::
# 128 "data/maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 129 "data/maps/Route123/scripts.pory"
	waitmovement 0
# 130 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronRegister, MSGBOX_DEFAULT
# 131 "data/maps/Route123/scripts.pory"
	register_matchcall TRAINER_CAMERON_1
# 132 "data/maps/Route123/scripts.pory"
	release
# 133 "data/maps/Route123/scripts.pory"
	end
# 134 "data/maps/Route123/scripts.pory"

# 135 "data/maps/Route123/scripts.pory"
Route123_EventScript_RematchCameron::
# 136 "data/maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_CAMERON_1, Route123_Text_CameronRematchIntro, Route123_Text_CameronRematchDefeat
# 137 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_CameronPostRematch, MSGBOX_AUTOCLOSE
# 138 "data/maps/Route123/scripts.pory"
	end
# 139 "data/maps/Route123/scripts.pory"

# 140 "data/maps/Route123/scripts.pory"
Route123_EventScript_Jacki::
# 141 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_JACKI_1, Route123_Text_JackiIntro, Route123_Text_JackiDefeat, Route123_EventScript_RegisterJacki
# 142 "data/maps/Route123/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 143 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchJacki
# 144 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiPostBattle, MSGBOX_DEFAULT
# 145 "data/maps/Route123/scripts.pory"
	release
# 146 "data/maps/Route123/scripts.pory"
	end
# 147 "data/maps/Route123/scripts.pory"

# 148 "data/maps/Route123/scripts.pory"
Route123_EventScript_RegisterJacki::
# 149 "data/maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 150 "data/maps/Route123/scripts.pory"
	waitmovement 0
# 151 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiRegister, MSGBOX_DEFAULT
# 152 "data/maps/Route123/scripts.pory"
	register_matchcall TRAINER_JACKI_1
# 153 "data/maps/Route123/scripts.pory"
	release
# 154 "data/maps/Route123/scripts.pory"
	end
# 155 "data/maps/Route123/scripts.pory"

# 156 "data/maps/Route123/scripts.pory"
Route123_EventScript_RematchJacki::
# 157 "data/maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_JACKI_1, Route123_Text_JackiRematchIntro, Route123_Text_JackiRematchDefeat
# 158 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JackiPostRematch, MSGBOX_AUTOCLOSE
# 159 "data/maps/Route123/scripts.pory"
	end
# 160 "data/maps/Route123/scripts.pory"

# 161 "data/maps/Route123/scripts.pory"
Route123_EventScript_Miu::
# 162 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_MiuIntro, Route123_Text_MiuDefeat, Route123_Text_MiuNotEnoughMons
# 163 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_MiuPostBattle, MSGBOX_AUTOCLOSE
# 164 "data/maps/Route123/scripts.pory"
	end
# 165 "data/maps/Route123/scripts.pory"

# 166 "data/maps/Route123/scripts.pory"
Route123_EventScript_Yuki::
# 167 "data/maps/Route123/scripts.pory"
	trainerbattle_double TRAINER_MIU_AND_YUKI, Route123_Text_YukiIntro, Route123_Text_YukiDefeat, Route123_Text_YukiNotEnoughMons
# 168 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_YukiPostBattle, MSGBOX_AUTOCLOSE
# 169 "data/maps/Route123/scripts.pory"
	end
# 170 "data/maps/Route123/scripts.pory"

# 171 "data/maps/Route123/scripts.pory"
Route123_EventScript_Kindra::
# 172 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_KINDRA, Route123_Text_KindraIntro, Route123_Text_KindraDefeat
# 173 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_KindraPostBattle, MSGBOX_AUTOCLOSE
# 174 "data/maps/Route123/scripts.pory"
	end
# 175 "data/maps/Route123/scripts.pory"

# 176 "data/maps/Route123/scripts.pory"
Route123_EventScript_Frederick::
# 177 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_FREDRICK, Route123_Text_FrederickIntro, Route123_Text_FrederickDefeat
# 178 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FrederickPostBattle, MSGBOX_AUTOCLOSE
# 179 "data/maps/Route123/scripts.pory"
	end
# 180 "data/maps/Route123/scripts.pory"

# 181 "data/maps/Route123/scripts.pory"
Route123_EventScript_Alberto::
# 182 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_ALBERTO, Route123_Text_AlbertoIntro, Route123_Text_AlbertoDefeat
# 183 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_AlbertoPostBattle, MSGBOX_AUTOCLOSE
# 184 "data/maps/Route123/scripts.pory"
	end
# 185 "data/maps/Route123/scripts.pory"

# 186 "data/maps/Route123/scripts.pory"
Route123_EventScript_Ed::
# 187 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_ED, Route123_Text_EdIntro, Route123_Text_EdDefeat
# 188 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_EdPostBattle, MSGBOX_AUTOCLOSE
# 189 "data/maps/Route123/scripts.pory"
	end
# 190 "data/maps/Route123/scripts.pory"

# 191 "data/maps/Route123/scripts.pory"
Route123_EventScript_Kayley::
# 192 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_KAYLEY, Route123_Text_KayleyIntro, Route123_Text_KayleyDefeat
# 193 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_KayleyPostBattle, MSGBOX_AUTOCLOSE
# 194 "data/maps/Route123/scripts.pory"
	end
# 195 "data/maps/Route123/scripts.pory"

# 196 "data/maps/Route123/scripts.pory"
Route123_EventScript_Jonas::
# 197 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_JONAS, Route123_Text_JonasIntro, Route123_Text_JonasDefeat
# 198 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JonasPostBattle, MSGBOX_AUTOCLOSE
# 199 "data/maps/Route123/scripts.pory"
	end
# 200 "data/maps/Route123/scripts.pory"

# 201 "data/maps/Route123/scripts.pory"
Route123_EventScript_Jazmyn::
# 202 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_JAZMYN, Route123_Text_JazmynIntro, Route123_Text_JazmynDefeat
# 203 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_JazmynPostBattle, MSGBOX_AUTOCLOSE
# 204 "data/maps/Route123/scripts.pory"
	end
# 205 "data/maps/Route123/scripts.pory"

# 206 "data/maps/Route123/scripts.pory"
Route123_EventScript_Davis::
# 207 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_DAVIS, Route123_Text_DavisIntro, Route123_Text_DavisDefeat
# 208 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_DavisPostBattle, MSGBOX_AUTOCLOSE
# 209 "data/maps/Route123/scripts.pory"
	end
# 210 "data/maps/Route123/scripts.pory"

# 211 "data/maps/Route123/scripts.pory"
Route123_EventScript_Fernando::
# 212 "data/maps/Route123/scripts.pory"
	trainerbattle_single TRAINER_FERNANDO_1, Route123_Text_FernandoIntro, Route123_Text_FernandoDefeat, Route123_EventScript_RegisterFernando
# 213 "data/maps/Route123/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 214 "data/maps/Route123/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route123_EventScript_RematchFernando
# 215 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoPostBattle, MSGBOX_DEFAULT
# 216 "data/maps/Route123/scripts.pory"
	release
# 217 "data/maps/Route123/scripts.pory"
	end
# 218 "data/maps/Route123/scripts.pory"

# 219 "data/maps/Route123/scripts.pory"
Route123_EventScript_RegisterFernando::
# 220 "data/maps/Route123/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 221 "data/maps/Route123/scripts.pory"
	waitmovement 0
# 222 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoRegister, MSGBOX_DEFAULT
# 223 "data/maps/Route123/scripts.pory"
	register_matchcall TRAINER_FERNANDO_1
# 224 "data/maps/Route123/scripts.pory"
	release
# 225 "data/maps/Route123/scripts.pory"
	end
# 226 "data/maps/Route123/scripts.pory"

# 227 "data/maps/Route123/scripts.pory"
Route123_EventScript_RematchFernando::
# 228 "data/maps/Route123/scripts.pory"
	trainerbattle_rematch TRAINER_FERNANDO_1, Route123_Text_FernandoRematchIntro, Route123_Text_FernandoRematchDefeat
# 229 "data/maps/Route123/scripts.pory"
	msgbox Route123_Text_FernandoPostRematch, MSGBOX_AUTOCLOSE
# 230 "data/maps/Route123/scripts.pory"
	end
# 231 "data/maps/Route123/scripts.pory"

# 232 "data/maps/Route123/scripts.pory"
Route123_Text_LoveGrassMonsHaveAny:
# 233 "data/maps/Route123/scripts.pory"
	.string "I love Grass-type Pokémon!\p"
# 234 "data/maps/Route123/scripts.pory"
	.string "Do you have any Grass-type Pokémon?$"
# 235 "data/maps/Route123/scripts.pory"

# 236 "data/maps/Route123/scripts.pory"
Route123_Text_YouLikeGrassMonsTooHaveThis:
# 237 "data/maps/Route123/scripts.pory"
	.string "Oh?\p"
# 238 "data/maps/Route123/scripts.pory"
	.string "You like Grass-type Pokémon, too,\n"
# 239 "data/maps/Route123/scripts.pory"
	.string "don't you?\p"
# 240 "data/maps/Route123/scripts.pory"
	.string "I'm so happy, you can have this!\n"
# 241 "data/maps/Route123/scripts.pory"
	.string "It's a token of our friendship.$"
# 242 "data/maps/Route123/scripts.pory"

# 243 "data/maps/Route123/scripts.pory"
Route123_Text_CheckTreesWithMyGrassMon:
# 244 "data/maps/Route123/scripts.pory"
	.string "I check trees with my Grass-type\n"
# 245 "data/maps/Route123/scripts.pory"
	.string "Pokémon. I'm like a tree doctor.$"
# 246 "data/maps/Route123/scripts.pory"

# 247 "data/maps/Route123/scripts.pory"
Route123_Text_RouteSign:
# 248 "data/maps/Route123/scripts.pory"
	.string "{RIGHT_ARROW} Route 123\n"
# 249 "data/maps/Route123/scripts.pory"
	.string "{LEFT_ARROW} Route 118$"
# 250 "data/maps/Route123/scripts.pory"

# 251 "data/maps/Route123/scripts.pory"
Route123_Text_RouteSignMtPyre:
# 252 "data/maps/Route123/scripts.pory"
	.string "{UP_ARROW} Mt. Pyre\n"
# 253 "data/maps/Route123/scripts.pory"
	.string "“Forbidden to the faint of heart.”$"
# 254 "data/maps/Route123/scripts.pory"

# 255 "data/maps/Route123/scripts.pory"
Route123_Text_BerryMastersHouse:
# 256 "data/maps/Route123/scripts.pory"
	.string "Berry Master's House$"

Route123_Text_EarthShakingInResponseToGracidea::
# 262 "data/maps/Route123/scripts.pory"
	.string "Oh! The forest is responding\n"
	.string "to the Gracidea!$"
