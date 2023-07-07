#ifndef GUARD_CONSTANTS_FLAGS_H
#define GUARD_CONSTANTS_FLAGS_H

#include	"constants/opponents.h"

 // Temporary Flags
 // These temporary flags are are cleared every time a map is loaded. They are used
 // for things like shortening an NPCs introduction text if the player already spoke
 // to them once.
#define TEMP_FLAGS_START                                     0x0
#define FLAG_TEMP_1                                          (TEMP_FLAGS_START + 0x1)
#define FLAG_TEMP_2                                          (TEMP_FLAGS_START + 0x2)
#define FLAG_TEMP_3                                          (TEMP_FLAGS_START + 0x3)
#define FLAG_TEMP_4                                          (TEMP_FLAGS_START + 0x4)
#define FLAG_TEMP_5                                          (TEMP_FLAGS_START + 0x5)
#define FLAG_TEMP_6                                          (TEMP_FLAGS_START + 0x6)
#define FLAG_TEMP_7                                          (TEMP_FLAGS_START + 0x7)
#define FLAG_TEMP_8                                          (TEMP_FLAGS_START + 0x8)
#define FLAG_TEMP_9                                          (TEMP_FLAGS_START + 0x9)
#define FLAG_TEMP_A                                          (TEMP_FLAGS_START + 0xA)
#define FLAG_TEMP_B                                          (TEMP_FLAGS_START + 0xB)
#define FLAG_TEMP_C                                          (TEMP_FLAGS_START + 0xC)
#define FLAG_TEMP_D                                          (TEMP_FLAGS_START + 0xD)
#define FLAG_TEMP_E                                          (TEMP_FLAGS_START + 0xE)
#define FLAG_TEMP_F                                          (TEMP_FLAGS_START + 0xF)
#define FLAG_TEMP_10                                         (TEMP_FLAGS_START + 0x10)
#define FLAG_TEMP_11                                         (TEMP_FLAGS_START + 0x11)
#define FLAG_TEMP_12                                         (TEMP_FLAGS_START + 0x12)
#define FLAG_TEMP_13                                         (TEMP_FLAGS_START + 0x13)
#define FLAG_TEMP_14                                         (TEMP_FLAGS_START + 0x14)
#define FLAG_TEMP_15                                         (TEMP_FLAGS_START + 0x15)
#define FLAG_TEMP_16                                         (TEMP_FLAGS_START + 0x16)
#define FLAG_TEMP_17                                         (TEMP_FLAGS_START + 0x17)
#define FLAG_TEMP_18                                         (TEMP_FLAGS_START + 0x18)
#define FLAG_TEMP_19                                         (TEMP_FLAGS_START + 0x19)
#define FLAG_TEMP_1A                                         (TEMP_FLAGS_START + 0x1A)
#define FLAG_TEMP_1B                                         (TEMP_FLAGS_START + 0x1B)
#define FLAG_TEMP_1C                                         (TEMP_FLAGS_START + 0x1C)
#define FLAG_TEMP_1D                                         (TEMP_FLAGS_START + 0x1D)
#define FLAG_TEMP_1E                                         (TEMP_FLAGS_START + 0x1E)
#define FLAG_TEMP_1F                                         (TEMP_FLAGS_START + 0x1F)
#define TEMP_FLAGS_END                                       FLAG_TEMP_1F

#define FLAG_SYS_NO_COLLISION                                0x20
#define FLAG_SYS_NO_ENCOUNTER                                0x21
#define FLAG_SYS_NO_TRAINER_SEE                              0x22
#define FLAG_SYS_NO_BAG_USE                                  0x23
#define FLAG_SYS_NO_CATCHING                                 0x24
#define FLAG_SAVED_DAVID                                     0x25
#define FLAG_LOCKEDOUT_PLAYED                                0x26
#define FLAG_HIDE_MADISON                                    0x27
#define FLAG_MET_SOCIALMEDIA_REPORTER                        0x28
#define FLAG_START_MENU_MOVE_MODE                            0x29 // For the Start Menu
#define FLAG_DEFEATED_GARDEN_BOSS                            0x2A
#define FLAG_START_MENU_SETUP                                0x2B // Is used the first time you open the start menu to set up the app orders
#define FLAG_OPTION_MENU_SETUP                               0x2C // Is used the first time you open the options menu to set up the configuration
#define FLAG_FORCE_SHINY                                     0x2D //Mechanic
#define FLAG_INVERSE_BATTLE                                  0x2E //Mechanic
#define FLAG_FORCE_DOUBLE_WILD                               0x2F //Mechanic
#define FLAG_SMART_WILD_AI                                   0x30 //Mechanic
#define FLAG_SPAWN_INVISIBLE                                 0x31 //Mechanic
#define FLAG_QUEST_EMPLOYEDEVERAFTER_FOUND_BRIDE             0x32 //Quest
#define FLAG_QUEST_PERSUASIVE_SIBLING                        0x33 //Quest
#define FLAG_CONSTRUCTION_BREAKING_NEWS                      0x34 //Story
#define FLAG_ARCHER_CALL_ALCATRAZ                            0x35 //Story
#define FLAG_RECIEVED_LEFTOVERS                              0x36 //Item
#define FLAG_QUEST_PERSUASIVE_PASSENGER_PLAYER_KIDNAPPED     0x37 //Quest
#define FLAG_FOUND_STOLEN_GOODS                              0x38 //Quest Item
#define FLAG_ITEM_MARIN_RANGER_HEADPHONES                    0x39 //Quest Item
#define FLAG_ITEM_MARIN_RANGER_WIDE_LENS                     0x3A //Quest Item
#define FLAG_ITEM_MARIN_RANGER_ROCKY_HELMET                  0x3B //Quest Item
#define FLAG_ITEM_GLDNGTEWILDS_ENGAGEMENT_RING               0x3C //Quest Item
#define FLAG_QUEST_WAREHOUSE_WARFARE_EXPLAINED               0x3D //Quest
#define FLAG_QUEST_WAREHOUSEWARFARE_BARGE2_WORKERS_CLEAR     0x3E //Quest
#define FLAG_QUEST_WAREHOUSEWARFARE_BARGE2_ENGINE_CLEAR      0x3F //Quest
#define FLAG_QUEST_WAREHOUSEWARFARE_BARGE3_ENGINE_CLEAR      0x40 //Quest
#define FLAG_DISCOVERED_UNDERGROUNDLAB                       0x41 //Story
#define FLAG_TIMELINE_FALSE                                  0x42 //Story
#define FLAG_TIMELINE_TRUE                                   0x43 //Story
#define FLAG_TIMELINE_TIMETRAVEL                             0x44 //Story
#define FLAG_CHASECENTER_TOURNAMENT_HAPPENING                                                          0x45 //Story
#define FLAG_QUEST_ULTRAWORMHOLE_DONDOZO                     0x46 //Quest
#define FLAG_QUEST_ULTRAWORMHOLE_VOLCARONA                   0x47 //Quest
#define FLAG_QUEST_ULTRAWORMHOLE_DUSCLOPS                    0x48 //Quest
#define FLAG_QUEST_ULTRAWORMHOLE_CAMERUPT                    0x49 //Quest
#define FLAG_QUEST_ULTRAWORMHOLE_DEINO                       0x4A //Quest
#define FLAG_QUEST_ULTRAWORMHOLE_NOIVERN                     0x4B //Quest
#define FLAG_QUEST_ULTRAWORMHOLE_SHUCKLE                     0x4C //Quest
#define FLAG_QUEST_ULTRAWORMHOLE_KINGLER                     0x4D //Quest
#define FLAG_QUEST_ULTRAWORMHOLE_ORBEETLE                    0x4E //Quest
#define FLAG_QUEST_ULTRAWORMHOLE_DONPHAN                     0x4F //Quest
#define FLAG_QUEST_ULTRAWORMHOLE_FIRST_TOTEM                 FLAG_QUEST_ULTRAWORMHOLE_DONDOZO //Quest
#define FLAG_QUEST_ULTRAWORMHOLE_LAST_TOTEM                  FLAG_QUEST_ULTRAWORMHOLE_DONPHAN //Quest
#define FLAG_QUEST_ULTRAWORMHOLE_BATTLED_ULTRA_BEAST         0x50 //Quest
#define FLAG_CRAFTED_FIRST_GEM                               FLAG_CRAFTED_NORMAL_GEM //Quest
#define FLAG_CRAFTED_NORMAL_GEM                              0x51 //Quest
#define FLAG_CRAFTED_FIGHTING_GEM                            0x52 //Quest
#define FLAG_CRAFTED_FLYING_GEM                              0x53 //Quest
#define FLAG_CRAFTED_POISON_GEM                              0x54 //Quest
#define FLAG_CRAFTED_GROUND_GEM                              0x55 //Quest
#define FLAG_CRAFTED_ROCK_GEM                                0x56 //Quest
#define FLAG_CRAFTED_BUG_GEM                                 0x57 //Quest
#define FLAG_CRAFTED_GHOST_GEM                               0x58 //Quest
#define FLAG_CRAFTED_STEEL_GEM                               0x59 //Quest
#define FLAG_CRAFTED_FIRE_GEM                                0x5A //Quest
#define FLAG_CRAFTED_WATER_GEM                               0x5B //Quest
#define FLAG_CRAFTED_GRASS_GEM                               0x5C //Quest
#define FLAG_CRAFTED_ELECTRIC_GEM                            0x5D //Quest
#define FLAG_CRAFTED_PSYCHIC_GEM                             0x5E //Quest
#define FLAG_CRAFTED_ICE_GEM                                 0x5F //Quest
#define FLAG_CRAFTED_DRAGON_GEM                              0x60 //Quest
#define FLAG_CRAFTED_DARK_GEM                                0x61 //Quest
#define FLAG_CRAFTED_FAIRY_GEM                               0x62 //Quest
#define FLAG_RECIEVED_GEMARTIST_MEGASTONE                    0x63 //Quest
#define FLAG_ITEM_LAKEMERCED_STUFF1                          0x64 //Quest Item
#define FLAG_ITEM_LAKEMERCED_STUFF2                          0x65 //Quest Item
#define FLAG_ITEM_LAKEMERCED_STUFF3                          0x66 //Quest Item
#define FLAG_ITEM_LAKEMERCED_STUFF4                          0x67 //Quest Item
#define FLAG_ITEM_LAKEMERCED_STUFF5                          0x68 //Quest Item
#define FLAG_ITEM_LAKEMERCED_STUFF6                          0x69 //Quest Item
#define FLAG_ITEM_LAKEMERCED_STUFF7                          0x6A //Quest Item
#define FLAG_ITEM_LAKEMERCED_STUFF8                          0x6B //Quest Item
#define FLAG_ITEM_LAKEMERCED_STUFF9                          0x6C //Quest Item
#define FLAG_ITEM_ROCKCOLLECTOR_STONE_START                  FLAG_ITEM_ROCKCOLLECTOR_CAVE_FIRE_STONE //Quest
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_FIRE_STONE              0x6D //Quest Item
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_WATER_STONE             0x6E //Quest Item
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_THUNDER_STONE           0x6F //Quest Item
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_LEAF_STONE              0x70 //Quest Item
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_ICE_STONE               0x71 //Quest Item
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_SUN_STONE               0x72 //Quest Item
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_MOON_STONE              0x73 //Quest Item
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_SHINY_STONE             0x74 //Quest Item
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_DUSK_STONE              0x75 //Quest Item
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_DAWN_STONE              0x76 //Quest Item
#define FLAG_ITEM_ROCKCOLLECTOR_STONE_END                    FLAG_ITEM_ROCKCOLLECTOR_CAVE_DAWN_STONE //Quest Item
#define ROCKCOLLECTOR_STONES_COUNT                           (FLAG_ITEM_ROCKCOLLECTOR_STONE_END - FLAG_ITEM_ROCKCOLLECTOR_STONE_START + 1) //Quest
#define FLAG_QUEST_BODEGA_RESCUE_FLAGS_START                 FLAG_QUEST_BODEGA_RESCUE1 //Quest
#define FLAG_QUEST_BODEGA_RESCUE1                            0x77 //Quest
#define FLAG_QUEST_BODEGA_RESCUE2                            0x78 //Quest
#define FLAG_QUEST_BODEGA_RESCUE3                            0x79 //Quest
#define FLAG_QUEST_BODEGA_RESCUE4                            0x7A //Quest
#define FLAG_QUEST_BODEGA_RESCUE5                            0x7B //Quest
#define FLAG_QUEST_BODEGA_RESCUE6                            0x7C //Quest
#define FLAG_QUEST_BODEGA_RESCUE_FLAGS_END                   FLAG_QUEST_BODEGA_RESCUE6 //Quest
#define BODEGA_RESCUE_COUNT                                  (FLAG_QUEST_BODEGA_RESCUE_FLAGS_END - FLAG_QUEST_BODEGA_RESCUE_FLAGS_START + 1) //Quest
#define FLAG_HIDE_FACILITY_OPPONENT                          0x7D
#define FLAG_FACILITY_UNLOCK_FLAGS_START                     FLAG_FACILITY_UNLOCK_LIKO
#define FLAG_FACILITY_UNLOCK_LIKO                            0x7E
#define FLAG_FACILITY_UNLOCK_CHARLOTTE                       0x7F
#define FLAG_FACILITY_UNLOCK_AMI_ARGENTO                     0x80
#define FLAG_FACILITY_UNLOCK_TALA                            0x81
#define FLAG_FACILITY_UNLOCK_DIMU                            0x82
#define FLAG_FACILITY_UNLOCK_ADAORA                          0x83
#define FLAG_FACILITY_UNLOCK_EMRYS                           0x84
#define FLAG_FACILITY_UNLOCK_MAGNUS                          0x85
#define FLAG_FACILITY_UNLOCK_BD                              0x86
#define FLAG_FACILITY_UNLOCK_KAI                             0x87
#define FLAG_FACILITY_UNLOCK_NERIENE                         0x88
#define FLAG_FACILITY_UNLOCK_ARMANDO                         0x89
#define FLAG_FACILITY_UNLOCK_SHINZO                          0x8A
#define FLAG_FACILITY_UNLOCK_KEI_YING                        0x8B
#define FLAG_FACILITY_UNLOCK_BELEN                           0x8C
#define FLAG_FACILITY_UNLOCK_ELLEN                           0x8D
#define FLAG_FACILITY_UNLOCK_FLAGS_END                       FLAG_FACILITY_UNLOCK_ELLEN
#define FACILITY_UNLOCK_FLAGS_COUNT                          (FLAG_FACILITY_UNLOCK_FLAGS_END - FLAG_FACILITY_UNLOCK_FLAGS_START + 1)
#define FLAG_FOUGHT_FIRST_FACILITY_BOSS                      0x8E
#define PSF_FLAG_145                                         0x8F
#define PSF_FLAG_146                                         0x90
#define PSF_FLAG_147                                         0x91
#define PSF_FLAG_148                                         0x92
#define PSF_FLAG_149                                         0x93
#define PSF_FLAG_150                                         0x94
#define PSF_FLAG_151                                         0x95
#define PSF_FLAG_152                                         0x96
#define PSF_FLAG_153                                         0x97
#define PSF_FLAG_154                                         0x98
#define PSF_FLAG_155                                         0x99
#define PSF_FLAG_156                                         0x9A
#define PSF_FLAG_157                                         0x9B
#define PSF_FLAG_158                                         0x9C
#define PSF_FLAG_159                                         0x9D
#define PSF_FLAG_160                                         0x9E
#define PSF_FLAG_161                                         0x9F
#define PSF_FLAG_162                                         0xA0
#define PSF_FLAG_163                                         0xA1
#define PSF_FLAG_164                                         0xA2
#define PSF_FLAG_165                                         0xA3
#define PSF_FLAG_166                                         0xA4
#define PSF_FLAG_167                                         0xA5
#define PSF_FLAG_168                                         0xA6
#define PSF_FLAG_169                                         0xA7
#define PSF_FLAG_170                                         0xA8
#define PSF_FLAG_171                                         0xA9
#define PSF_FLAG_172                                         0xAA
#define PSF_FLAG_173                                         0xAB
#define PSF_FLAG_174                                         0xAC
#define PSF_FLAG_175                                         0xAD
#define PSF_FLAG_176                                         0xAE
#define PSF_FLAG_177                                         0xAF
#define PSF_FLAG_178                                         0xB0
#define PSF_FLAG_179                                         0xB1
#define PSF_FLAG_180                                         0xB2
#define PSF_FLAG_181                                         0xB3
#define PSF_FLAG_182                                         0xB4
#define PSF_FLAG_183                                         0xB5
#define PSF_FLAG_184                                         0xB6
#define PSF_FLAG_185                                         0xB7
#define PSF_FLAG_186                                         0xB8
#define PSF_FLAG_187                                         0xB9
#define PSF_FLAG_188                                         0xBA
#define PSF_FLAG_189                                         0xBB
#define PSF_FLAG_190                                         0xBC
#define PSF_FLAG_191                                         0xBD
#define PSF_FLAG_192                                         0xBE
#define PSF_FLAG_193                                         0xBF
#define PSF_FLAG_194                                         0xC0
#define PSF_FLAG_195                                         0xC1
#define PSF_FLAG_196                                         0xC2
#define PSF_FLAG_197                                         0xC3
#define PSF_FLAG_198                                         0xC4
#define PSF_FLAG_199                                         0xC5
#define PSF_FLAG_200                                         0xC6
#define PSF_FLAG_201                                         0xC7
#define PSF_FLAG_202                                         0xC8
#define PSF_FLAG_203                                         0xC9
#define PSF_FLAG_204                                         0xCA
#define PSF_FLAG_205                                         0xCB
#define PSF_FLAG_206                                         0xCC
#define PSF_FLAG_207                                         0xCD
#define PSF_FLAG_208                                         0xCE
#define PSF_FLAG_209                                         0xCF
#define PSF_FLAG_210                                         0xD0
#define PSF_FLAG_211                                         0xD1
#define PSF_FLAG_212                                         0xD2
#define PSF_FLAG_213                                         0xD3
#define PSF_FLAG_214                                         0xD4
#define PSF_FLAG_215                                         0xD5
#define PSF_FLAG_216                                         0xD6
#define PSF_FLAG_217                                         0xD7
#define PSF_FLAG_218                                         0xD8
#define PSF_FLAG_219                                         0xD9
#define PSF_FLAG_220                                         0xDA
#define PSF_FLAG_221                                         0xDB
#define PSF_FLAG_222                                         0xDC
#define PSF_FLAG_223                                         0xDD
#define PSF_FLAG_224                                         0xDE
#define PSF_FLAG_225                                         0xDF
#define PSF_FLAG_226                                         0xE0
#define PSF_FLAG_227                                         0xE1
#define PSF_FLAG_228                                         0xE2
#define PSF_FLAG_229                                         0xE3
#define PSF_FLAG_230                                         0xE4
#define PSF_FLAG_231                                         0xE5
#define PSF_FLAG_232                                         0xE6
#define PSF_FLAG_233                                         0xE7
#define PSF_FLAG_234                                         0xE8
#define PSF_FLAG_235                                         0xE9
#define PSF_FLAG_236                                         0xEA
#define PSF_FLAG_237                                         0xEB
#define PSF_FLAG_238                                         0xEC
#define PSF_FLAG_239                                         0xED
#define PSF_FLAG_240                                         0xEE
#define PSF_FLAG_241                                         0xEF
#define PSF_FLAG_242                                         0xF0
#define PSF_FLAG_243                                         0xF1
#define PSF_FLAG_244                                         0xF2
#define PSF_FLAG_245                                         0xF3
#define PSF_FLAG_246                                         0xF4
#define PSF_FLAG_247                                         0xF5
#define PSF_FLAG_248                                         0xF6
#define PSF_FLAG_249                                         0xF7
#define PSF_FLAG_250                                         0xF8
#define PSF_FLAG_251                                         0xF9
#define PSF_FLAG_252                                         0xFA
#define PSF_FLAG_253                                         0xFB
#define PSF_FLAG_254                                         0xFC
#define PSF_FLAG_255                                         0xFD
#define PSF_FLAG_256                                         0xFE
#define PSF_FLAG_257                                         0xFF
#define PSF_FLAG_258                                         0x100
#define PSF_FLAG_259                                         0x101
#define PSF_FLAG_260                                         0x102
#define PSF_FLAG_261                                         0x103
#define PSF_FLAG_262                                         0x104
#define PSF_FLAG_263                                         0x105
#define PSF_FLAG_264                                         0x106
#define PSF_FLAG_265                                         0x107
#define PSF_FLAG_266                                         0x108
#define PSF_FLAG_267                                         0x109
#define PSF_FLAG_268                                         0x10A
#define PSF_FLAG_269                                         0x10B
#define PSF_FLAG_270                                         0x10C
#define PSF_FLAG_271                                         0x10D
#define PSF_FLAG_272                                         0x10E
#define PSF_FLAG_273                                         0x10F
#define PSF_FLAG_274                                         0x110
#define PSF_FLAG_275                                         0x111
#define PSF_FLAG_276                                         0x112
#define PSF_FLAG_277                                         0x113
#define PSF_FLAG_278                                         0x114
#define PSF_FLAG_279                                         0x115
#define PSF_FLAG_280                                         0x116
#define PSF_FLAG_281                                         0x117
#define PSF_FLAG_282                                         0x118
#define PSF_FLAG_283                                         0x119
#define PSF_FLAG_284                                         0x11A
#define PSF_FLAG_285                                         0x11B
#define PSF_FLAG_286                                         0x11C
#define PSF_FLAG_287                                         0x11D
#define PSF_FLAG_288                                         0x11E
#define PSF_FLAG_289                                         0x11F
#define PSF_FLAG_290                                         0x120
#define PSF_FLAG_291                                         0x121
#define PSF_FLAG_292                                         0x122
#define PSF_FLAG_293                                         0x123
#define PSF_FLAG_294                                         0x124
#define PSF_FLAG_295                                         0x125
#define PSF_FLAG_296                                         0x126
#define PSF_FLAG_297                                         0x127
#define PSF_FLAG_298                                         0x128
#define PSF_FLAG_299                                         0x129
#define PSF_FLAG_300                                         0x12A
#define PSF_FLAG_301                                         0x12B
#define PSF_FLAG_302                                         0x12C
#define PSF_FLAG_303                                         0x12D
#define PSF_FLAG_304                                         0x12E
#define PSF_FLAG_305                                         0x12F
#define PSF_FLAG_306                                         0x130
#define PSF_FLAG_307                                         0x131
#define PSF_FLAG_308                                         0x132
#define PSF_FLAG_309                                         0x133
#define PSF_FLAG_310                                         0x134
#define PSF_FLAG_311                                         0x135
#define PSF_FLAG_312                                         0x136
#define PSF_FLAG_313                                         0x137
#define PSF_FLAG_314                                         0x138
#define PSF_FLAG_315                                         0x139
#define PSF_FLAG_316                                         0x13A
#define PSF_FLAG_317                                         0x13B
#define PSF_FLAG_318                                         0x13C
#define PSF_FLAG_319                                         0x13D
#define PSF_FLAG_320                                         0x13E
#define PSF_FLAG_321                                         0x13F
#define PSF_FLAG_322                                         0x140
#define PSF_FLAG_323                                         0x141
#define PSF_FLAG_324                                         0x142
#define PSF_FLAG_325                                         0x143
#define PSF_FLAG_326                                         0x144
#define PSF_FLAG_327                                         0x145
#define PSF_FLAG_328                                         0x146
#define PSF_FLAG_329                                         0x147
#define PSF_FLAG_330                                         0x148
#define PSF_FLAG_331                                         0x149
#define PSF_FLAG_332                                         0x14A
#define PSF_FLAG_333                                         0x14B
#define PSF_FLAG_334                                         0x14C
#define PSF_FLAG_335                                         0x14D
#define PSF_FLAG_336                                         (1 + FLAG_WONDER_CARD_UNUSED_17 - FLAG_RECEIVED_AURORA_TICKET)
#define PSF_FLAG_337                                         0x14E
#define PSF_FLAG_338                                         0x14F
#define PSF_FLAG_339                                         0x150
#define PSF_FLAG_340                                         0x151
#define PSF_FLAG_341                                         0x152
#define PSF_FLAG_342                                         0x153
#define PSF_FLAG_343                                         0x154
#define PSF_FLAG_344                                         0x155
#define PSF_FLAG_345                                         0x156
#define PSF_FLAG_346                                         0x157
#define PSF_FLAG_347                                         0x158
#define PSF_FLAG_348                                         0x159
#define PSF_FLAG_349                                         0x15A
#define PSF_FLAG_350                                         0x15B
#define PSF_FLAG_351                                         0x15C
#define PSF_FLAG_352                                         0x15D
#define PSF_FLAG_353                                         0x15E
#define PSF_FLAG_354                                         0x15F
#define PSF_FLAG_355                                         0x160
#define PSF_FLAG_356                                         0x161
#define PSF_FLAG_357                                         0x162
#define PSF_FLAG_358                                         0x163
#define PSF_FLAG_359                                         0x164
#define PSF_FLAG_360                                         0x165
#define PSF_FLAG_361                                         0x166
#define PSF_FLAG_362                                         0x167
#define PSF_FLAG_363                                         0x168
#define PSF_FLAG_364                                         0x169
#define PSF_FLAG_365                                         0x16A
#define PSF_FLAG_366                                         0x16B
#define PSF_FLAG_367                                         0x16C
#define PSF_FLAG_368                                         0x16D
#define PSF_FLAG_369                                         0x16E
#define PSF_FLAG_370                                         0x16F
#define PSF_FLAG_371                                         0x170
#define PSF_FLAG_372                                         0x171
#define PSF_FLAG_373                                         0x172
#define PSF_FLAG_374                                         0x173
#define PSF_FLAG_375                                         0x174
#define PSF_FLAG_376                                         0x175
#define PSF_FLAG_377                                         0x176
#define PSF_FLAG_378                                         0x177
#define PSF_FLAG_379                                         0x178
#define PSF_FLAG_380                                         0x179
#define PSF_FLAG_381                                         0x17A
#define PSF_FLAG_382                                         0x17B
#define PSF_FLAG_383                                         0x17C
#define PSF_FLAG_384                                         0x17D
#define PSF_FLAG_385                                         0x17E
#define PSF_FLAG_386                                         0x17F
#define PSF_FLAG_387                                         0x180
#define PSF_FLAG_388                                         0x181
#define PSF_FLAG_389                                         0x182
#define PSF_FLAG_390                                         0x183
#define PSF_FLAG_391                                         0x184
#define PSF_FLAG_392                                         0x185
#define PSF_FLAG_393                                         0x186
#define PSF_FLAG_394                                         0x187
#define PSF_FLAG_395                                         0x188
#define PSF_FLAG_396                                         0x189
#define PSF_FLAG_397                                         0x18A
#define PSF_FLAG_398                                         0x18B
#define PSF_FLAG_399                                         0x18C
#define PSF_FLAG_400                                         0x18D
#define PSF_FLAG_401                                         0x18E
#define PSF_FLAG_402                                         0x18F
#define PSF_FLAG_403                                         0x190
#define PSF_FLAG_404                                         0x191
#define PSF_FLAG_405                                         0x192
#define PSF_FLAG_406                                         0x193
#define PSF_FLAG_407                                         0x194
#define PSF_FLAG_408                                         0x195
#define PSF_FLAG_409                                         0x196
#define PSF_FLAG_410                                         0x197
#define PSF_FLAG_411                                         0x198
#define PSF_FLAG_412                                         0x199
#define PSF_FLAG_413                                         0x19A
#define PSF_FLAG_414                                         0x19B
#define PSF_FLAG_415                                         0x19C
#define PSF_FLAG_416                                         0x19D
#define PSF_FLAG_417                                         0x19E
#define PSF_FLAG_418                                         0x19F
#define PSF_FLAG_419                                         0x1A0
#define PSF_FLAG_420                                         0x1A1
#define PSF_FLAG_421                                         0x1A2
#define PSF_FLAG_422                                         0x1A3
#define PSF_FLAG_423                                         0x1A4
#define PSF_FLAG_424                                         0x1A5
#define PSF_FLAG_425                                         0x1A6
#define PSF_FLAG_426                                         0x1A7
#define PSF_FLAG_427                                         0x1A8
#define PSF_FLAG_428                                         0x1A9
#define PSF_FLAG_429                                         0x1AA
#define PSF_FLAG_430                                         0x1AB
#define PSF_FLAG_431                                         0x1AC
#define PSF_FLAG_432                                         0x1AD
#define PSF_FLAG_433                                         0x1AE
#define PSF_FLAG_434                                         0x1AF
#define PSF_FLAG_435                                         0x1B0
#define PSF_FLAG_436                                         0x1B1
#define PSF_FLAG_437                                         0x1B2
#define PSF_FLAG_438                                         0x1B3
#define PSF_FLAG_439                                         0x1B4
#define PSF_FLAG_440                                         0x1B5
#define PSF_FLAG_441                                         0x1B6
#define PSF_FLAG_442                                         0x1B7
#define PSF_FLAG_443                                         0x1B8
#define PSF_FLAG_444                                         0x1B9
#define PSF_FLAG_445                                         0x1BA
#define PSF_FLAG_446                                         0x1BB
#define PSF_FLAG_447                                         0x1BC
#define PSF_FLAG_448                                         0x1BD
#define PSF_FLAG_449                                         0x1BE
#define PSF_FLAG_450                                         0x1BF
#define PSF_FLAG_451                                         0x1C0
#define PSF_FLAG_452                                         0x1C1
#define PSF_FLAG_453                                         0x1C2
#define PSF_FLAG_454                                         0x1C3
#define PSF_FLAG_455                                         0x1C4
#define PSF_FLAG_456                                         0x1C5
#define PSF_FLAG_457                                         0x1C6
#define PSF_FLAG_458                                         0x1C7
#define PSF_FLAG_459                                         0x1C8
#define PSF_FLAG_460                                         0x1C9
#define PSF_FLAG_461                                         0x1CA
#define PSF_FLAG_462                                         0x1CB
#define PSF_FLAG_463                                         0x1CC
#define PSF_FLAG_464                                         0x1CD
#define PSF_FLAG_465                                         0x1CE
#define PSF_FLAG_466                                         0x1CF
#define PSF_FLAG_467                                         0x1D0
#define PSF_FLAG_468                                         0x1D1
#define PSF_FLAG_469                                         0x1D2
#define PSF_FLAG_470                                         0x1D3
#define PSF_FLAG_471                                         0x1D4
#define PSF_FLAG_472                                         0x1D5
#define PSF_FLAG_473                                         0x1D6
#define PSF_FLAG_474                                         0x1D7
#define PSF_FLAG_475                                         0x1D8
#define PSF_FLAG_476                                         0x1D9
#define PSF_FLAG_477                                         0x1DA
#define PSF_FLAG_478                                         0x1DB
#define PSF_FLAG_479                                         0x1DC
#define PSF_FLAG_480                                         0x1DD
#define PSF_FLAG_481                                         0x1DE
#define PSF_FLAG_482                                         0x1DF
#define PSF_FLAG_483                                         0x1E0
#define PSF_FLAG_484                                         0x1E1
#define PSF_FLAG_485                                         0x1E2
#define PSF_FLAG_486                                         0x1E3
#define PSF_FLAG_487                                         0x1E4
#define PSF_FLAG_488                                         0x1E5
#define PSF_FLAG_489                                         0x1E6
#define PSF_FLAG_490                                         0x1E7
#define PSF_FLAG_491                                         0x1E8
#define PSF_FLAG_492                                         0x1E9
#define PSF_FLAG_493                                         0x1EA
#define PSF_FLAG_494                                         0x1EB
#define PSF_FLAG_495                                         0x1EC
#define PSF_FLAG_496                                         0x1ED
#define PSF_FLAG_497                                         0x1EE
#define PSF_FLAG_498                                         0x1EF
#define PSF_FLAG_499                                         0x1F0
#define PSF_FLAG_500                                         0x1F1
#define PSF_FLAG_501                                         0x1F2
#define PSF_FLAG_502                                         0x1F3

 // Hidden Items
#define FLAG_HIDDEN_ITEMS_START                              0x1F4
#define PSF_FLAG_504                                         (FLAG_HIDDEN_ITEMS_START + 0x00)
#define PSF_FLAG_505                                         (FLAG_HIDDEN_ITEMS_START + 0x01)
#define PSF_FLAG_506                                         (FLAG_HIDDEN_ITEMS_START + 0x02)
#define PSF_FLAG_507                                         (FLAG_HIDDEN_ITEMS_START + 0x03)
#define PSF_FLAG_508                                         (FLAG_HIDDEN_ITEMS_START + 0x04)
#define PSF_FLAG_509                                         (FLAG_HIDDEN_ITEMS_START + 0x05)
#define PSF_FLAG_510                                         (FLAG_HIDDEN_ITEMS_START + 0x06)
#define PSF_FLAG_511                                         (FLAG_HIDDEN_ITEMS_START + 0x07)
#define PSF_FLAG_512                                         (FLAG_HIDDEN_ITEMS_START + 0x08)
#define PSF_FLAG_513                                         (FLAG_HIDDEN_ITEMS_START + 0x09)
#define PSF_FLAG_514                                         (FLAG_HIDDEN_ITEMS_START + 0x0A)
#define PSF_FLAG_515                                         (FLAG_HIDDEN_ITEMS_START + 0x0B)
#define PSF_FLAG_516                                         (FLAG_HIDDEN_ITEMS_START + 0x0C)
#define PSF_FLAG_517                                         (FLAG_HIDDEN_ITEMS_START + 0x0D)
#define PSF_FLAG_518                                         (FLAG_HIDDEN_ITEMS_START + 0x0E)
#define PSF_FLAG_519                                         (FLAG_HIDDEN_ITEMS_START + 0x0F)
#define PSF_FLAG_520                                         (FLAG_HIDDEN_ITEMS_START + 0x10)
#define PSF_FLAG_521                                         (FLAG_HIDDEN_ITEMS_START + 0x11)
#define PSF_FLAG_522                                         (FLAG_HIDDEN_ITEMS_START + 0x12)
#define PSF_FLAG_523                                         (FLAG_HIDDEN_ITEMS_START + 0x13)
#define PSF_FLAG_524                                         (FLAG_HIDDEN_ITEMS_START + 0x14)
#define PSF_FLAG_525                                         (FLAG_HIDDEN_ITEMS_START + 0x15)
#define PSF_FLAG_526                                         (FLAG_HIDDEN_ITEMS_START + 0x16)
#define PSF_FLAG_527                                         (FLAG_HIDDEN_ITEMS_START + 0x17)
#define PSF_FLAG_528                                         (FLAG_HIDDEN_ITEMS_START + 0x18)
#define PSF_FLAG_529                                         (FLAG_HIDDEN_ITEMS_START + 0x19)
#define PSF_FLAG_530                                         (FLAG_HIDDEN_ITEMS_START + 0x1A)
#define PSF_FLAG_531                                         (FLAG_HIDDEN_ITEMS_START + 0x1B)
#define PSF_FLAG_532                                         (FLAG_HIDDEN_ITEMS_START + 0x1C)
#define PSF_FLAG_533                                         (FLAG_HIDDEN_ITEMS_START + 0x1D)
#define PSF_FLAG_534                                         (FLAG_HIDDEN_ITEMS_START + 0x1E)
#define PSF_FLAG_535                                         (FLAG_HIDDEN_ITEMS_START + 0x1F)
#define PSF_FLAG_536                                         (FLAG_HIDDEN_ITEMS_START + 0x20)
#define PSF_FLAG_537                                         (FLAG_HIDDEN_ITEMS_START + 0x21)
#define PSF_FLAG_538                                         (FLAG_HIDDEN_ITEMS_START + 0x22)
#define PSF_FLAG_539                                         (FLAG_HIDDEN_ITEMS_START + 0x23)
#define PSF_FLAG_540                                         (FLAG_HIDDEN_ITEMS_START + 0x24)
#define PSF_FLAG_541                                         (FLAG_HIDDEN_ITEMS_START + 0x25)
#define PSF_FLAG_542                                         (FLAG_HIDDEN_ITEMS_START + 0x26)
#define PSF_FLAG_543                                         (FLAG_HIDDEN_ITEMS_START + 0x27)
#define PSF_FLAG_544                                         (FLAG_HIDDEN_ITEMS_START + 0x28)
#define PSF_FLAG_545                                         (FLAG_HIDDEN_ITEMS_START + 0x29)
#define PSF_FLAG_546                                         (FLAG_HIDDEN_ITEMS_START + 0x2A)
#define PSF_FLAG_547                                         (FLAG_HIDDEN_ITEMS_START + 0x2B)
#define PSF_FLAG_548                                         (FLAG_HIDDEN_ITEMS_START + 0x2C)
#define PSF_FLAG_549                                         (FLAG_HIDDEN_ITEMS_START + 0x2D)
#define PSF_FLAG_550                                         (FLAG_HIDDEN_ITEMS_START + 0x2E)
#define PSF_FLAG_551                                         (FLAG_HIDDEN_ITEMS_START + 0x2F)
#define PSF_FLAG_552                                         (FLAG_HIDDEN_ITEMS_START + 0x30)
#define PSF_FLAG_553                                         (FLAG_HIDDEN_ITEMS_START + 0x31)
#define PSF_FLAG_554                                         (FLAG_HIDDEN_ITEMS_START + 0x32)
#define PSF_FLAG_555                                         (FLAG_HIDDEN_ITEMS_START + 0x33)
#define PSF_FLAG_556                                         (FLAG_HIDDEN_ITEMS_START + 0x34)
#define PSF_FLAG_557                                         (FLAG_HIDDEN_ITEMS_START + 0x35)
#define PSF_FLAG_558                                         (FLAG_HIDDEN_ITEMS_START + 0x36)
#define PSF_FLAG_559                                         (FLAG_HIDDEN_ITEMS_START + 0x37)
#define PSF_FLAG_560                                         (FLAG_HIDDEN_ITEMS_START + 0x38)
#define PSF_FLAG_561                                         (FLAG_HIDDEN_ITEMS_START + 0x39)
#define PSF_FLAG_562                                         (FLAG_HIDDEN_ITEMS_START + 0x3A)
#define PSF_FLAG_563                                         (FLAG_HIDDEN_ITEMS_START + 0x3B)
#define PSF_FLAG_564                                         (FLAG_HIDDEN_ITEMS_START + 0x3C)
#define PSF_FLAG_565                                         (FLAG_HIDDEN_ITEMS_START + 0x3D)
#define PSF_FLAG_566                                         (FLAG_HIDDEN_ITEMS_START + 0x3E)
#define PSF_FLAG_567                                         (FLAG_HIDDEN_ITEMS_START + 0x3F)
#define PSF_FLAG_568                                         (FLAG_HIDDEN_ITEMS_START + 0x40)
#define PSF_FLAG_569                                         (FLAG_HIDDEN_ITEMS_START + 0x41)
#define PSF_FLAG_570                                         (FLAG_HIDDEN_ITEMS_START + 0x42)
#define PSF_FLAG_571                                         (FLAG_HIDDEN_ITEMS_START + 0x43)
#define PSF_FLAG_572                                         (FLAG_HIDDEN_ITEMS_START + 0x44)
#define PSF_FLAG_573                                         (FLAG_HIDDEN_ITEMS_START + 0x45)
#define PSF_FLAG_574                                         (FLAG_HIDDEN_ITEMS_START + 0x46)
#define PSF_FLAG_575                                         (FLAG_HIDDEN_ITEMS_START + 0x47)
#define PSF_FLAG_576                                         (FLAG_HIDDEN_ITEMS_START + 0x48)
#define PSF_FLAG_577                                         (FLAG_HIDDEN_ITEMS_START + 0x49)
#define PSF_FLAG_578                                         (FLAG_HIDDEN_ITEMS_START + 0x4A)
#define PSF_FLAG_579                                         (FLAG_HIDDEN_ITEMS_START + 0x4B)
#define PSF_FLAG_580                                         (FLAG_HIDDEN_ITEMS_START + 0x4C)
#define PSF_FLAG_581                                         (FLAG_HIDDEN_ITEMS_START + 0x4D)
#define PSF_FLAG_582                                         (FLAG_HIDDEN_ITEMS_START + 0x4E)
#define PSF_FLAG_583                                         (FLAG_HIDDEN_ITEMS_START + 0x4F)
#define PSF_FLAG_584                                         (FLAG_HIDDEN_ITEMS_START + 0x50)
#define PSF_FLAG_585                                         (FLAG_HIDDEN_ITEMS_START + 0x51)
#define PSF_FLAG_586                                         (FLAG_HIDDEN_ITEMS_START + 0x52)
#define PSF_FLAG_587                                         (FLAG_HIDDEN_ITEMS_START + 0x53)
#define PSF_FLAG_588                                         (FLAG_HIDDEN_ITEMS_START + 0x54)
#define PSF_FLAG_589                                         (FLAG_HIDDEN_ITEMS_START + 0x55)
#define PSF_FLAG_590                                         (FLAG_HIDDEN_ITEMS_START + 0x56)
#define PSF_FLAG_591                                         (FLAG_HIDDEN_ITEMS_START + 0x57)
#define PSF_FLAG_592                                         (FLAG_HIDDEN_ITEMS_START + 0x58)
#define PSF_FLAG_593                                         (FLAG_HIDDEN_ITEMS_START + 0x59)
#define PSF_FLAG_594                                         (FLAG_HIDDEN_ITEMS_START + 0x5A)
#define PSF_FLAG_595                                         (FLAG_HIDDEN_ITEMS_START + 0x5B)
#define PSF_FLAG_596                                         (FLAG_HIDDEN_ITEMS_START + 0x5C)
#define PSF_FLAG_597                                         (FLAG_HIDDEN_ITEMS_START + 0x5D)
#define PSF_FLAG_598                                         (FLAG_HIDDEN_ITEMS_START + 0x5E)
#define PSF_FLAG_599                                         (FLAG_HIDDEN_ITEMS_START + 0x5F)
#define PSF_FLAG_600                                         (FLAG_HIDDEN_ITEMS_START + 0x60)
#define PSF_FLAG_601                                         (FLAG_HIDDEN_ITEMS_START + 0x61)
#define PSF_FLAG_602                                         (FLAG_HIDDEN_ITEMS_START + 0x62)
#define PSF_FLAG_603                                         (FLAG_HIDDEN_ITEMS_START + 0x63)
#define PSF_FLAG_604                                         (FLAG_HIDDEN_ITEMS_START + 0x64)
#define PSF_FLAG_605                                         (FLAG_HIDDEN_ITEMS_START + 0x65)
#define PSF_FLAG_606                                         (FLAG_HIDDEN_ITEMS_START + 0x66)
#define PSF_FLAG_607                                         (FLAG_HIDDEN_ITEMS_START + 0x67)
#define PSF_FLAG_608                                         (FLAG_HIDDEN_ITEMS_START + 0x68)
#define PSF_FLAG_609                                         (FLAG_HIDDEN_ITEMS_START + 0x69)
#define PSF_FLAG_610                                         (FLAG_HIDDEN_ITEMS_START + 0x6A)
#define PSF_FLAG_611                                         (FLAG_HIDDEN_ITEMS_START + 0x6B)
#define PSF_FLAG_612                                         (FLAG_HIDDEN_ITEMS_START + 0x6C)
#define PSF_FLAG_613                                         (FLAG_HIDDEN_ITEMS_START + 0x6D)
#define PSF_FLAG_614                                         (FLAG_HIDDEN_ITEMS_START + 0x6E)
#define PSF_FLAG_615                                         (FLAG_HIDDEN_ITEMS_START + 0x6F)

#define PSF_FLAG_616                                         0x264
#define PSF_FLAG_617                                         0x265
#define PSF_FLAG_618                                         0x266
#define PSF_FLAG_619                                         0x267
#define PSF_FLAG_620                                         0x268
#define PSF_FLAG_621                                         0x269
#define PSF_FLAG_622                                         0x26A
#define PSF_FLAG_623                                         0x26B
#define PSF_FLAG_624                                         0x26C
#define PSF_FLAG_625                                         0x26D
#define PSF_FLAG_626                                         0x26E
#define PSF_FLAG_627                                         0x26F
#define PSF_FLAG_628                                         0x270
#define PSF_FLAG_629                                         0x271
#define PSF_FLAG_630                                         0x272
#define PSF_FLAG_631                                         0x273
#define PSF_FLAG_632                                         0x274
#define PSF_FLAG_633                                         0x275
#define PSF_FLAG_634                                         0x276
#define PSF_FLAG_635                                         0x277
#define PSF_FLAG_636                                         0x278
#define PSF_FLAG_637                                         0x279
#define PSF_FLAG_638                                         0x27A
#define PSF_FLAG_639                                         0x27B
#define PSF_FLAG_640                                         0x27C
#define PSF_FLAG_641                                         0x27D
#define PSF_FLAG_642                                         0x27E
#define PSF_FLAG_643                                         0x27F
#define PSF_FLAG_644                                         0x280
#define PSF_FLAG_645                                         0x281
#define PSF_FLAG_646                                         0x282
#define PSF_FLAG_647                                         0x283
#define PSF_FLAG_648                                         0x284
#define PSF_FLAG_649                                         0x285
#define PSF_FLAG_650                                         0x286
#define PSF_FLAG_651                                         0x287
#define PSF_FLAG_652                                         0x288
#define PSF_FLAG_653                                         0x289
#define PSF_FLAG_654                                         0x28A
#define PSF_FLAG_655                                         0x28B
#define PSF_FLAG_656                                         0x28C
#define PSF_FLAG_657                                         0x28D
#define PSF_FLAG_658                                         0x28E
#define PSF_FLAG_659                                         0x28F
#define PSF_FLAG_660                                         0x290
#define PSF_FLAG_661                                         0x291
#define PSF_FLAG_662                                         0x292
#define PSF_FLAG_663                                         0x293
#define PSF_FLAG_664                                         0x294
#define PSF_FLAG_665                                         0x295
#define PSF_FLAG_666                                         0x296
#define PSF_FLAG_667                                         0x297
#define PSF_FLAG_668                                         0x298
#define PSF_FLAG_669                                         0x299
#define PSF_FLAG_670                                         0x29A
#define PSF_FLAG_671                                         0x29B
#define PSF_FLAG_672                                         0x29C
#define PSF_FLAG_673                                         0x29D
#define PSF_FLAG_674                                         0x29E
#define PSF_FLAG_675                                         0x29F
#define PSF_FLAG_676                                         0x2A0
#define PSF_FLAG_677                                         0x2A1
#define PSF_FLAG_678                                         0x2A2
#define PSF_FLAG_679                                         0x2A3
#define PSF_FLAG_680                                         0x2A4
#define PSF_FLAG_681                                         0x2A5
#define PSF_FLAG_682                                         0x2A6
#define PSF_FLAG_683                                         0x2A7
#define PSF_FLAG_684                                         0x2A8
#define PSF_FLAG_685                                         0x2A9
#define PSF_FLAG_686                                         0x2AA
#define PSF_FLAG_687                                         0x2AB
#define PSF_FLAG_688                                         0x2AC
#define PSF_FLAG_689                                         0x2AD
#define PSF_FLAG_690                                         0x2AE
#define PSF_FLAG_691                                         0x2AF
#define PSF_FLAG_692                                         0x2B0
#define PSF_FLAG_693                                         0x2B1
#define PSF_FLAG_694                                         0x2B2
#define PSF_FLAG_695                                         0x2B3
#define PSF_FLAG_696                                         0x2B4
#define PSF_FLAG_697                                         0x2B5
#define PSF_FLAG_698                                         0x2B6
#define PSF_FLAG_699                                         0x2B7
#define PSF_FLAG_700                                         0x2B8
#define PSF_FLAG_701                                         0x2B9
#define PSF_FLAG_702                                         0x2BA
#define PSF_FLAG_703                                         0x2BB
#define PSF_FLAG_704                                         0x2BC
#define PSF_FLAG_705                                         0x2BD
#define PSF_FLAG_706                                         0x2BE
#define PSF_FLAG_707                                         0x2BF
#define PSF_FLAG_708                                         0x2C0
#define PSF_FLAG_709                                         0x2C1
#define PSF_FLAG_710                                         0x2C2
#define PSF_FLAG_711                                         0x2C3
#define PSF_FLAG_712                                         0x2C4
#define PSF_FLAG_713                                         0x2C5
#define PSF_FLAG_714                                         0x2C6
#define PSF_FLAG_715                                         0x2C7
#define PSF_FLAG_716                                         0x2C8
#define PSF_FLAG_717                                         0x2C9
#define PSF_FLAG_718                                         0x2CA
#define PSF_FLAG_719                                         0x2CB
#define PSF_FLAG_720                                         0x2CC
#define PSF_FLAG_721                                         0x2CD
#define PSF_FLAG_722                                         0x2CE
#define PSF_FLAG_723                                         0x2CF
#define PSF_FLAG_724                                         0x2D0
#define PSF_FLAG_725                                         0x2D1
#define PSF_FLAG_726                                         0x2D2
#define PSF_FLAG_727                                         0x2D3
#define PSF_FLAG_728                                         0x2D4
#define PSF_FLAG_729                                         0x2D5
#define PSF_FLAG_730                                         0x2D6
#define PSF_FLAG_731                                         0x2D7
#define PSF_FLAG_732                                         0x2D8
#define PSF_FLAG_734                                         0x2DA
#define PSF_FLAG_735                                         0x2DB
#define PSF_FLAG_736                                         0x2DC
#define PSF_FLAG_737                                         0x2DD
#define PSF_FLAG_738                                         0x2DE
#define PSF_FLAG_739                                         0x2DF
#define PSF_FLAG_740                                         0x2E0
#define PSF_FLAG_741                                         0x2E1
#define PSF_FLAG_742                                         0x2E2
#define PSF_FLAG_743                                         0x2E3
#define PSF_FLAG_744                                         0x2E4
#define PSF_FLAG_745                                         0x2E5
#define PSF_FLAG_746                                         0x2E6
#define PSF_FLAG_747                                         0x2E7
#define PSF_FLAG_748                                         0x2E8
#define PSF_FLAG_749                                         0x2E9
#define PSF_FLAG_750                                         0x2EA
#define PSF_FLAG_751                                         0x2EB
#define PSF_FLAG_752                                         0x2EC
#define PSF_FLAG_753                                         0x2ED
#define PSF_FLAG_754                                         0x2EE
#define PSF_FLAG_755                                         0x2EF
#define PSF_FLAG_756                                         0x2F0
#define PSF_FLAG_757                                         0x2F1
#define PSF_FLAG_758                                         0x2F2
#define PSF_FLAG_759                                         0x2F3
#define PSF_FLAG_760                                         0x2F4
#define PSF_FLAG_761                                         0x2F5
#define PSF_FLAG_762                                         0x2F6
#define PSF_FLAG_763                                         0x2F7
#define PSF_FLAG_764                                         0x2F8
#define PSF_FLAG_765                                         0x2F9
#define PSF_FLAG_766                                         0x2FA
#define PSF_FLAG_767                                         0x2FB
#define PSF_FLAG_768                                         0x2FC
#define PSF_FLAG_769                                         0x2FD
#define PSF_FLAG_770                                         0x2FE
#define PSF_FLAG_771                                         0x2FF
#define PSF_FLAG_772                                         0x300
#define PSF_FLAG_773                                         0x301
#define PSF_FLAG_774                                         0x302
#define PSF_FLAG_775                                         0x303
#define PSF_FLAG_776                                         0x304
#define PSF_FLAG_777                                         0x305
#define PSF_FLAG_778                                         0x306
#define PSF_FLAG_779                                         0x307
#define PSF_FLAG_780                                         0x308
#define PSF_FLAG_781                                         0x309
#define PSF_FLAG_782                                         0x30A
#define PSF_FLAG_783                                         0x30B
#define PSF_FLAG_784                                         0x30C
#define PSF_FLAG_785                                         0x30D
#define PSF_FLAG_786                                         0x30E
#define PSF_FLAG_787                                         0x30F
#define PSF_FLAG_788                                         0x310
#define PSF_FLAG_789                                         0x311
#define PSF_FLAG_790                                         0x312
#define PSF_FLAG_791                                         0x313
#define PSF_FLAG_792                                         0x314
#define PSF_FLAG_793                                         0x315
#define PSF_FLAG_794                                         0x316
#define PSF_FLAG_795                                         0x317
#define PSF_FLAG_796                                         0x318
#define PSF_FLAG_797                                         0x319
#define PSF_FLAG_798                                         0x31A
#define PSF_FLAG_799                                         0x31B
#define PSF_FLAG_800                                         0x31C
#define PSF_FLAG_801                                         0x31D
#define PSF_FLAG_802                                         0x31E
#define PSF_FLAG_803                                         0x31F
#define PSF_FLAG_804                                         0x320
#define PSF_FLAG_805                                         0x321
#define PSF_FLAG_806                                         0x322
#define PSF_FLAG_807                                         0x323
#define PSF_FLAG_808                                         0x324
#define PSF_FLAG_809                                         0x325
#define PSF_FLAG_810                                         0x326
#define PSF_FLAG_811                                         0x327
#define PSF_FLAG_812                                         0x328
#define PSF_FLAG_813                                         0x329
#define PSF_FLAG_814                                         0x32A
#define PSF_FLAG_815                                         0x32B
#define PSF_FLAG_816                                         0x32C
#define PSF_FLAG_817                                         0x32D
#define PSF_FLAG_818                                         0x32E
#define PSF_FLAG_819                                         0x32F
#define PSF_FLAG_820                                         0x330
#define PSF_FLAG_821                                         0x331
#define PSF_FLAG_822                                         0x332
#define PSF_FLAG_823                                         0x333
#define PSF_FLAG_824                                         0x334
#define PSF_FLAG_825                                         0x335
#define PSF_FLAG_826                                         0x336
#define PSF_FLAG_827                                         0x337
#define PSF_FLAG_828                                         0x338
#define PSF_FLAG_829                                         0x339
#define PSF_FLAG_830                                         0x33A
#define PSF_FLAG_831                                         0x33B
#define PSF_FLAG_832                                         0x33C
#define PSF_FLAG_833                                         0x33D
#define PSF_FLAG_834                                         0x33E
#define PSF_FLAG_835                                         0x33F
#define PSF_FLAG_836                                         0x340
#define PSF_FLAG_837                                         0x341
#define PSF_FLAG_838                                         0x342
#define PSF_FLAG_839                                         0x343
#define PSF_FLAG_840                                         0x344
#define PSF_FLAG_841                                         0x345
#define PSF_FLAG_842                                         0x346
#define PSF_FLAG_843                                         0x347
#define PSF_FLAG_844                                         0x348
#define PSF_FLAG_845                                         0x349
#define PSF_FLAG_846                                         0x34A
#define PSF_FLAG_847                                         0x34B
#define PSF_FLAG_848                                         0x34C
#define PSF_FLAG_849                                         0x34D
#define PSF_FLAG_850                                         0x34E
#define PSF_FLAG_851                                         0x34F
#define PSF_FLAG_852                                         0x350
#define PSF_FLAG_853                                         0x351
#define PSF_FLAG_854                                         0x352
#define PSF_FLAG_855                                         0x353
#define PSF_FLAG_856                                         0x354
#define PSF_FLAG_857                                         0x355
#define PSF_FLAG_858                                         0x356
#define PSF_FLAG_859                                         0x357
#define PSF_FLAG_860                                         0x358
#define PSF_FLAG_861                                         0x359
#define PSF_FLAG_862                                         0x35A
#define PSF_FLAG_863                                         0x35B
#define PSF_FLAG_864                                         0x35C
#define PSF_FLAG_865                                         0x35D
#define PSF_FLAG_866                                         0x35E
#define PSF_FLAG_867                                         0x35F
#define PSF_FLAG_868                                         0x360
#define PSF_FLAG_869                                         0x361
#define PSF_FLAG_870                                         0x362
#define PSF_FLAG_871                                         0x363
#define PSF_FLAG_872                                         0x364
#define PSF_FLAG_873                                         0x365
#define PSF_FLAG_874                                         0x366
#define PSF_FLAG_875                                         0x367
#define PSF_FLAG_876                                         0x368
#define PSF_FLAG_877                                         0x369
#define PSF_FLAG_878                                         0x36A
#define PSF_FLAG_879                                         0x36B
#define PSF_FLAG_880                                         0x36C
#define PSF_FLAG_881                                         0x36D
#define PSF_FLAG_882                                         0x36E
#define PSF_FLAG_883                                         0x36F
#define PSF_FLAG_884                                         0x370
#define PSF_FLAG_885                                         0x371
#define PSF_FLAG_886                                         0x372
#define PSF_FLAG_887                                         0x373
#define PSF_FLAG_888                                         0x374
#define PSF_FLAG_889                                         0x375
#define PSF_FLAG_890                                         0x376
#define PSF_FLAG_891                                         0x377
#define PSF_FLAG_892                                         0x378
#define PSF_FLAG_893                                         0x379
#define PSF_FLAG_894                                         0x37A
#define PSF_FLAG_895                                         0x37B
#define PSF_FLAG_896                                         0x37C
#define PSF_FLAG_897                                         0x37D
#define PSF_FLAG_898                                         0x37E
#define PSF_FLAG_899                                         0x37F
#define PSF_FLAG_900                                         0x380
#define PSF_FLAG_901                                         0x381
#define PSF_FLAG_902                                         0x382
#define PSF_FLAG_903                                         0x383
#define PSF_FLAG_904                                         0x384
#define PSF_FLAG_905                                         0x385
#define PSF_FLAG_906                                         0x386
#define PSF_FLAG_907                                         0x387
#define PSF_FLAG_908                                         0x388
#define PSF_FLAG_909                                         0x389
#define PSF_FLAG_910                                         0x38A
#define PSF_FLAG_911                                         0x38B
#define PSF_FLAG_912                                         0x38C
#define PSF_FLAG_913                                         0x38D
#define PSF_FLAG_914                                         0x38E
#define PSF_FLAG_915                                         0x38F
#define PSF_FLAG_916                                         0x390
#define PSF_FLAG_917                                         0x391
#define PSF_FLAG_918                                         0x392
#define PSF_FLAG_919                                         0x393
#define PSF_FLAG_920                                         0x394
#define PSF_FLAG_921                                         0x395
#define PSF_FLAG_922                                         0x396
#define PSF_FLAG_923                                         0x397
#define PSF_FLAG_924                                         0x398
#define PSF_FLAG_925                                         0x399
#define PSF_FLAG_926                                         0x39A
#define PSF_FLAG_927                                         0x39B
#define PSF_FLAG_928                                         0x39C
#define PSF_FLAG_929                                         0x39D
#define PSF_FLAG_930                                         0x39E
#define PSF_FLAG_931                                         0x39F
#define PSF_FLAG_932                                         0x3A0
#define PSF_FLAG_933                                         0x3A1
#define PSF_FLAG_934                                         0x3A2
#define PSF_FLAG_935                                         0x3A3
#define PSF_FLAG_936                                         0x3A4
#define PSF_FLAG_937                                         0x3A5
#define PSF_FLAG_938                                         0x3A6
#define PSF_FLAG_939                                         0x3A7
#define PSF_FLAG_940                                         0x3A8
#define PSF_FLAG_941                                         0x3A9
#define PSF_FLAG_942                                         0x3AA
#define PSF_FLAG_943                                         0x3AB
#define PSF_FLAG_944                                         0x3AC
#define PSF_FLAG_945                                         0x3AD
#define PSF_FLAG_946                                         0x3AE
#define PSF_FLAG_947                                         0x3AF
#define PSF_FLAG_948                                         0x3B0
#define PSF_FLAG_949                                         0x3B1
#define PSF_FLAG_950                                         0x3B2
#define PSF_FLAG_951                                         0x3B3
#define PSF_FLAG_952                                         0x3B4
#define PSF_FLAG_953                                         0x3B5
#define PSF_FLAG_954                                         0x3B6
#define PSF_FLAG_955                                         0x3B7
#define PSF_FLAG_956                                         0x3B8
#define PSF_FLAG_957                                         0x3B9
#define PSF_FLAG_958                                         0x3BA
#define PSF_FLAG_959                                         0x3BB
#define PSF_FLAG_960                                         0x3BC
#define PSF_FLAG_961                                         0x3BD
#define PSF_FLAG_962                                         0x3BE
#define PSF_FLAG_963                                         0x3BF
#define PSF_FLAG_964                                         0x3C0
#define PSF_FLAG_965                                         0x3C1
#define PSF_FLAG_966                                         0x3C2
#define PSF_FLAG_967                                         0x3C3
#define PSF_FLAG_968                                         0x3C4
#define PSF_FLAG_969                                         0x3C5
#define PSF_FLAG_970                                         0x3C6
#define PSF_FLAG_971                                         0x3C7
#define PSF_FLAG_972                                         0x3C8
#define PSF_FLAG_973                                         0x3C9
#define PSF_FLAG_974                                         0x3CA
#define PSF_FLAG_975                                         0x3CB
#define PSF_FLAG_976                                         0x3CC
#define PSF_FLAG_977                                         0x3CD
#define PSF_FLAG_978                                         0x3CE
#define PSF_FLAG_979                                         0x3CF
#define PSF_FLAG_980                                         0x3D0
#define PSF_FLAG_981                                         0x3D1
#define PSF_FLAG_982                                         0x3D2
#define PSF_FLAG_983                                         0x3D3
#define PSF_FLAG_984                                         0x3D4
#define PSF_FLAG_985                                         0x3D5
#define PSF_FLAG_986                                         0x3D6
#define PSF_FLAG_987                                         0x3D7
#define PSF_FLAG_988                                         0x3D8
#define PSF_FLAG_989                                         0x3D9
#define PSF_FLAG_990                                         0x3DA
#define PSF_FLAG_991                                         0x3DB
#define PSF_FLAG_992                                         0x3DC
#define PSF_FLAG_993                                         0x3DD
#define PSF_FLAG_994                                         0x3DE
#define PSF_FLAG_995                                         0x3DF
#define PSF_FLAG_996                                         0x3E0
#define PSF_FLAG_997                                         0x3E1
#define PSF_FLAG_998                                         0x3E2
#define PSF_FLAG_999                                         0x3E3
#define PSF_FLAG_1000                                        0x3E4
#define PSF_FLAG_1001                                        0x3E5
#define PSF_FLAG_1002                                        0x3E6
#define PSF_FLAG_1003                                        0x3E7
#define PSF_FLAG_1004                                        0x3E8
#define PSF_FLAG_1005                                        0x3E9
#define PSF_FLAG_1006                                        0x3EA
#define PSF_FLAG_1007                                        0x3EB
#define PSF_FLAG_1008                                        0x3EC
#define PSF_FLAG_1009                                        0x3ED
#define PSF_FLAG_1010                                        0x3EE
#define PSF_FLAG_1011                                        0x3EF
#define PSF_FLAG_1012                                        0x3F0
#define PSF_FLAG_1013                                        0x3F1
#define PSF_FLAG_1014                                        0x3F2
#define PSF_FLAG_1015                                        0x3F3
#define PSF_FLAG_1016                                        0x3F4
#define PSF_FLAG_1017                                        0x3F5
#define PSF_FLAG_1018                                        0x3F6
#define PSF_FLAG_1019                                        0x3F7
#define PSF_FLAG_1020                                        0x3F8
#define PSF_FLAG_1021                                        0x3F9
#define PSF_FLAG_1022                                        0x3FA
#define PSF_FLAG_1023                                        0x3FB
#define PSF_FLAG_1024                                        0x3FC
#define PSF_FLAG_1025                                        0x3FD
#define PSF_FLAG_1026                                        0x3FE
#define PSF_FLAG_1027                                        0x3FF
#define PSF_FLAG_1028                                        0x400
#define PSF_FLAG_1029                                        0x401
#define PSF_FLAG_1030                                        0x402
#define PSF_FLAG_1031                                        0x403
#define PSF_FLAG_1032                                        0x404
#define PSF_FLAG_1033                                        0x405
#define PSF_FLAG_1034                                        0x406
#define PSF_FLAG_1035                                        0x407
#define PSF_FLAG_1036                                        0x408
#define PSF_FLAG_1037                                        0x409
#define PSF_FLAG_1038                                        0x40A
#define PSF_FLAG_1039                                        0x40B
#define PSF_FLAG_1040                                        0x40C
#define PSF_FLAG_1041                                        0x40D
#define PSF_FLAG_1042                                        0x40E
#define PSF_FLAG_1043                                        0x40F
#define PSF_FLAG_1044                                        0x410
#define PSF_FLAG_1045                                        0x411
#define PSF_FLAG_1046                                        0x412
#define PSF_FLAG_1047                                        0x413
#define PSF_FLAG_1048                                        0x414
#define PSF_FLAG_1049                                        0x415
#define PSF_FLAG_1050                                        0x416
#define PSF_FLAG_1051                                        0x417
#define PSF_FLAG_1052                                        0x418
#define PSF_FLAG_1053                                        0x419
#define PSF_FLAG_1054                                        0x41A
#define PSF_FLAG_1055                                        0x41B
#define PSF_FLAG_1056                                        0x41C
#define PSF_FLAG_1057                                        0x41D
#define PSF_FLAG_1058                                        0x41E
#define PSF_FLAG_1059                                        0x41F
#define PSF_FLAG_1060                                        0x420
#define PSF_FLAG_1061                                        0x421
#define PSF_FLAG_1062                                        0x422
#define PSF_FLAG_1063                                        0x423
#define PSF_FLAG_1064                                        0x424
#define PSF_FLAG_1065                                        0x425
#define PSF_FLAG_1066                                        0x426
#define PSF_FLAG_1067                                        0x427
#define PSF_FLAG_1068                                        0x428
#define PSF_FLAG_1069                                        0x429
#define PSF_FLAG_1070                                        0x42A
#define PSF_FLAG_1071                                        0x42B
#define PSF_FLAG_1072                                        0x42C
#define PSF_FLAG_1073                                        0x42D
#define PSF_FLAG_1074                                        0x42E
#define PSF_FLAG_1075                                        0x42F
#define PSF_FLAG_1076                                        0x430
#define PSF_FLAG_1077                                        0x431
#define PSF_FLAG_1078                                        0x432
#define PSF_FLAG_1079                                        0x433
#define PSF_FLAG_1080                                        0x434
#define PSF_FLAG_1081                                        0x435
#define PSF_FLAG_1082                                        0x436
#define PSF_FLAG_1083                                        0x437
#define PSF_FLAG_1084                                        0x438
#define PSF_FLAG_1085                                        0x439
#define PSF_FLAG_1086                                        0x43A
#define PSF_FLAG_1087                                        0x43B
#define PSF_FLAG_1088                                        0x43C
#define PSF_FLAG_1089                                        0x43D
#define PSF_FLAG_1090                                        0x43E
#define PSF_FLAG_1091                                        0x43F
#define PSF_FLAG_1092                                        0x440
#define PSF_FLAG_1093                                        0x441
#define PSF_FLAG_1094                                        0x442
#define PSF_FLAG_1095                                        0x443
#define PSF_FLAG_1096                                        0x444
#define PSF_FLAG_1097                                        0x445
#define PSF_FLAG_1098                                        0x446
#define PSF_FLAG_1099                                        0x447
#define PSF_FLAG_1100                                        0x448
#define PSF_FLAG_1101                                        0x449
#define PSF_FLAG_1102                                        0x44A
#define PSF_FLAG_1103                                        0x44B
#define PSF_FLAG_1104                                        0x44C
#define PSF_FLAG_1105                                        0x44D
#define PSF_FLAG_1106                                        0x44E
#define PSF_FLAG_1107                                        0x44F
#define PSF_FLAG_1108                                        0x450
#define PSF_FLAG_1109                                        0x451
#define PSF_FLAG_1110                                        0x452
#define PSF_FLAG_1111                                        0x453
#define PSF_FLAG_1112                                        0x454
#define PSF_FLAG_1113                                        0x455
#define PSF_FLAG_1114                                        0x456
#define PSF_FLAG_1115                                        0x457
#define PSF_FLAG_1116                                        0x458
#define PSF_FLAG_1117                                        0x459
#define PSF_FLAG_1118                                        0x45A
#define PSF_FLAG_1119                                        0x45B
#define PSF_FLAG_1120                                        0x45C
#define PSF_FLAG_1121                                        0x45D
#define PSF_FLAG_1122                                        0x45E
#define PSF_FLAG_1123                                        0x45F
#define PSF_FLAG_1124                                        0x460
#define PSF_FLAG_1125                                        0x461
#define PSF_FLAG_1126                                        0x462
#define PSF_FLAG_1127                                        0x463
#define PSF_FLAG_1128                                        0x464
#define PSF_FLAG_1129                                        0x465
#define PSF_FLAG_1130                                        0x466
#define PSF_FLAG_1131                                        0x467
#define PSF_FLAG_1132                                        0x468
#define PSF_FLAG_1133                                        0x469
#define PSF_FLAG_1134                                        0x46A
#define PSF_FLAG_1135                                        0x46B
#define PSF_FLAG_1136                                        0x46C
#define PSF_FLAG_1137                                        0x46D
#define PSF_FLAG_1138                                        0x46E
#define PSF_FLAG_1139                                        0x46F
#define PSF_FLAG_1140                                        0x470
#define PSF_FLAG_1141                                        0x471
#define PSF_FLAG_1142                                        0x472
#define PSF_FLAG_1143                                        0x473
#define PSF_FLAG_1144                                        0x474
#define PSF_FLAG_1145                                        0x475
#define PSF_FLAG_1146                                        0x476
#define PSF_FLAG_1147                                        0x477
#define PSF_FLAG_1148                                        0x478
#define PSF_FLAG_1149                                        0x479
#define PSF_FLAG_1150                                        0x47A
#define PSF_FLAG_1151                                        0x47B
#define PSF_FLAG_1152                                        0x47C
#define PSF_FLAG_1153                                        0x47D
#define PSF_FLAG_1154                                        0x47E
#define PSF_FLAG_1155                                        0x47F
#define PSF_FLAG_1156                                        0x480
#define PSF_FLAG_1157                                        0x481
#define PSF_FLAG_1158                                        0x482
#define PSF_FLAG_1159                                        0x483
#define PSF_FLAG_1160                                        0x484
#define PSF_FLAG_1161                                        0x485
#define PSF_FLAG_1162                                        0x486
#define PSF_FLAG_1163                                        0x487
#define PSF_FLAG_1164                                        0x488
#define PSF_FLAG_1165                                        0x489
#define PSF_FLAG_1166                                        0x48A
#define PSF_FLAG_1167                                        0x48B
#define PSF_FLAG_1168                                        0x48C
#define PSF_FLAG_1169                                        0x48D
#define PSF_FLAG_1170                                        0x48E
#define PSF_FLAG_1171                                        0x48F
#define PSF_FLAG_1172                                        0x490
#define PSF_FLAG_1173                                        0x491
#define PSF_FLAG_1174                                        0x492
#define PSF_FLAG_1175                                        0x493
#define PSF_FLAG_1176                                        0x494
#define PSF_FLAG_1177                                        0x495
#define PSF_FLAG_1178                                        0x496
#define PSF_FLAG_1179                                        0x497
#define PSF_FLAG_1180                                        0x498
#define PSF_FLAG_1181                                        0x499
#define PSF_FLAG_1182                                        0x49A
#define PSF_FLAG_1183                                        0x49B
#define PSF_FLAG_1184                                        0x49C
#define PSF_FLAG_1185                                        0x49D
#define PSF_FLAG_1186                                        0x49E
#define PSF_FLAG_1187                                        0x49F
#define PSF_FLAG_1188                                        0x4A0
#define PSF_FLAG_1189                                        0x4A1
#define PSF_FLAG_1190                                        0x4A2
#define PSF_FLAG_1191                                        0x4A3
#define PSF_FLAG_1192                                        0x4A4
#define PSF_FLAG_1193                                        0x4A5
#define PSF_FLAG_1194                                        0x4A6
#define PSF_FLAG_1195                                        0x4A7
#define PSF_FLAG_1196                                        0x4A8
#define PSF_FLAG_1197                                        0x4A9
#define PSF_FLAG_1198                                        0x4AA
#define PSF_FLAG_1199                                        0x4AB
#define PSF_FLAG_1200                                        0x4AC
#define PSF_FLAG_1201                                        0x4AD
#define PSF_FLAG_1202                                        0x4AE
#define PSF_FLAG_1203                                        0x4AF
#define PSF_FLAG_1204                                        0x4B0
#define PSF_FLAG_1205                                        0x4B1
#define PSF_FLAG_1206                                        0x4B2
#define PSF_FLAG_1207                                        0x4B3
#define PSF_FLAG_1208                                        0x4B4
#define PSF_FLAG_1209                                        0x4B5
#define PSF_FLAG_1210                                        0x4B6
#define PSF_FLAG_1211                                        0x4B7
#define PSF_FLAG_1212                                        0x4B8
#define PSF_FLAG_1213                                        0x4B9
#define PSF_FLAG_1214                                        0x4BA
#define PSF_FLAG_1215                                        0x4BB
#define PSF_FLAG_1216                                        0x4BC
#define PSF_FLAG_1217                                        0x4BD
#define PSF_FLAG_1218                                        0x4BE
#define PSF_FLAG_1219                                        0x4BF
#define PSF_FLAG_1220                                        0x4C0
#define PSF_FLAG_1221                                        0x4C1
#define PSF_FLAG_1222                                        0x4C2
#define PSF_FLAG_1223                                        0x4C3
#define PSF_FLAG_1224                                        0x4C4
#define PSF_FLAG_1225                                        0x4C5
#define PSF_FLAG_1226                                        0x4C6
#define PSF_FLAG_1227                                        0x4C7
#define PSF_FLAG_1228                                        0x4C8
#define PSF_FLAG_1229                                        0x4C9
#define PSF_FLAG_1230                                        0x4CA
#define PSF_FLAG_1231                                        0x4CB
#define PSF_FLAG_1232                                        0x4CC
#define PSF_FLAG_1233                                        0x4CD
#define PSF_FLAG_1234                                        0x4CE
#define PSF_FLAG_1235                                        0x4CF
#define PSF_FLAG_1236                                        0x4D0
#define PSF_FLAG_1237                                        0x4D1
#define PSF_FLAG_1238                                        0x4D2
#define PSF_FLAG_1239                                        0x4D3
#define PSF_FLAG_1240                                        0x4D4
#define PSF_FLAG_1241                                        0x4D5
#define PSF_FLAG_1242                                        0x4D6
#define PSF_FLAG_1243                                        0x4D7
#define PSF_FLAG_1244                                        0x4D8
#define PSF_FLAG_1245                                        0x4D9
#define PSF_FLAG_1246                                        0x4DA
#define PSF_FLAG_1247                                        0x4DB
#define PSF_FLAG_1248                                        0x4DC
#define PSF_FLAG_1249                                        0x4DD
#define PSF_FLAG_1250                                        0x4DE
#define PSF_FLAG_1251                                        0x4DF
#define PSF_FLAG_1252                                        0x4E0
#define PSF_FLAG_1253                                        0x4E1
#define PSF_FLAG_1254                                        0x4E2
#define PSF_FLAG_1255                                        0x4E3
#define PSF_FLAG_1256                                        0x4E4
#define PSF_FLAG_1257                                        0x4E5
#define PSF_FLAG_1258                                        0x4E6
#define PSF_FLAG_1259                                        0x4E7
#define PSF_FLAG_1260                                        0x4E8
#define PSF_FLAG_1261                                        0x4E9
#define PSF_FLAG_1262                                        0x4EA
#define PSF_FLAG_1263                                        0x4EB
#define PSF_FLAG_1264                                        0x4EC
#define PSF_FLAG_1265                                        0x4ED
#define PSF_FLAG_1266                                        0x4EE
#define PSF_FLAG_1267                                        0x4EF
#define PSF_FLAG_1268                                        0x4F0
#define PSF_FLAG_1269                                        0x4F1
#define PSF_FLAG_1270                                        0x4F2
#define PSF_FLAG_1271                                        0x4F3
#define PSF_FLAG_1272                                        0x4F4
#define PSF_FLAG_1273                                        0x4F5
#define PSF_FLAG_1274                                        0x4F6
#define PSF_FLAG_1275                                        0x4F7
#define PSF_FLAG_1276                                        0x4F8
#define PSF_FLAG_1277                                        0x4F9
#define PSF_FLAG_1278                                        0x4FA
#define PSF_FLAG_1279                                        0x4FB
#define PSF_FLAG_1280                                        0x4FC
#define PSF_FLAG_1281                                        0x4FD
#define PSF_FLAG_1282                                        0x4FE
#define PSF_FLAG_1283                                        0x4FF

 // Trainer Flags
 // Trainer flags occupy 0x500 - 0x85F, the last 9 of which are unused
 // See constants/opponents.h. The values there + FLAG_TRAINER_FLAG_START are the flag IDs

#define TRAINER_FLAGS_START                                  0x500
#define TRAINER_FLAGS_END                                    (TRAINER_FLAGS_START + MAX_TRAINERS_COUNT - 1) // 0x85F

 // System Flags

#define SYSTEM_FLAGS                                         (TRAINER_FLAGS_END + 1)

#define FLAG_SYS_POKEMON_GET                                 (SYSTEM_FLAGS + 0x0)
#define FLAG_SYS_POKEDEX_GET                                 (SYSTEM_FLAGS + 0x1)
#define FLAG_SYS_POKENAV_GET                                 (SYSTEM_FLAGS + 0x2)
#define FLAG_SYS_QUEST_MENU_GET                              (SYSTEM_FLAGS + 0x3) // add QUESTS to start menu
#define FLAG_SYS_GAME_CLEAR                                  (SYSTEM_FLAGS + 0x4)
#define FLAG_SYS_CHAT_USED                                   (SYSTEM_FLAGS + 0x5)
#define FLAG_UNLOCKED_TRENDY_SAYINGS                         (SYSTEM_FLAGS + 0x6)

 // Badges
#define FLAG_BADGE01_GET                                     (SYSTEM_FLAGS + 0x7)
#define FLAG_BADGE02_GET                                     (SYSTEM_FLAGS + 0x8)
#define FLAG_BADGE03_GET                                     (SYSTEM_FLAGS + 0x9)
#define FLAG_BADGE04_GET                                     (SYSTEM_FLAGS + 0xA)
#define FLAG_BADGE05_GET                                     (SYSTEM_FLAGS + 0xB)
#define FLAG_BADGE06_GET                                     (SYSTEM_FLAGS + 0xC)
#define FLAG_BADGE07_GET                                     (SYSTEM_FLAGS + 0xD)
#define FLAG_BADGE08_GET                                     (SYSTEM_FLAGS + 0xE)
#define NUM_BADGES                                           (1 + FLAG_BADGE08_GET - FLAG_BADGE01_GET)

#define FLAG_PHONE_NO_SERVICE                                (SYSTEM_FLAGS + 0xF) //Mechanic
#define FLAG_SYS_RESTORED_TOWER_SILVER                       (SYSTEM_FLAGS + 0x10)
#define FLAG_SYS_RESTORED_TOWER_GOLD                         (SYSTEM_FLAGS + 0x11)
#define FLAG_SYS_RESTORED_ARCADE_SILVER                      (SYSTEM_FLAGS + 0x12)
#define FLAG_SYS_RESTORED_ARCADE_GOLD                        (SYSTEM_FLAGS + 0x13)
#define FLAG_SYS_RESTORED_DOJO_SILVER                        (SYSTEM_FLAGS + 0x14)
#define FLAG_SYS_RESTORED_DOJO_GOLD                          (SYSTEM_FLAGS + 0x15)
#define FLAG_SYS_RESTORED_FACTORY_SILVER                     (SYSTEM_FLAGS + 0x16)
#define FLAG_SYS_RESTORED_FACTORY_GOLD                       (SYSTEM_FLAGS + 0x17)
#define PSF_FLAG_1312                                        (SYSTEM_FLAGS + 0x18)
#define PSF_FLAG_1313                                        (SYSTEM_FLAGS + 0x19)
#define PSF_FLAG_1314                                        (SYSTEM_FLAGS + 0x1A)
#define PSF_FLAG_1315                                        (SYSTEM_FLAGS + 0x1B)
#define PSF_FLAG_1316                                        (SYSTEM_FLAGS + 0x1C)
#define PSF_FLAG_1317                                        (SYSTEM_FLAGS + 0x1D)
#define PSF_FLAG_1318                                        (SYSTEM_FLAGS + 0x1E)
#define PSF_FLAG_1319                                        (SYSTEM_FLAGS + 0x1F)
#define PSF_FLAG_1320                                        (SYSTEM_FLAGS + 0x20)
#define PSF_FLAG_1321                                        (SYSTEM_FLAGS + 0x21)
#define PSF_FLAG_1322                                        (SYSTEM_FLAGS + 0x22)
#define PSF_FLAG_1323                                        (SYSTEM_FLAGS + 0x23)
#define PSF_FLAG_1324                                        (SYSTEM_FLAGS + 0x24)
#define PSF_FLAG_1325                                        (SYSTEM_FLAGS + 0x25)
#define PSF_FLAG_1326                                        (SYSTEM_FLAGS + 0x26)
#define PSF_FLAG_1327                                        (SYSTEM_FLAGS + 0x27)
#define PSF_FLAG_1328                                        (SYSTEM_FLAGS + 0x28)
#define PSF_FLAG_1329                                        (SYSTEM_FLAGS + 0x29)
#define PSF_FLAG_1330                                        (SYSTEM_FLAGS + 0x2A)
#define PSF_FLAG_1331                                        (SYSTEM_FLAGS + 0x2B)
#define PSF_FLAG_1332                                        (SYSTEM_FLAGS + 0x2C)
#define PSF_FLAG_1333                                        (SYSTEM_FLAGS + 0x2D)
#define PSF_FLAG_1334                                        (SYSTEM_FLAGS + 0x2E)
#define PSF_FLAG_1335                                        (SYSTEM_FLAGS + 0x2F)
#define PSF_FLAG_1336                                        (SYSTEM_FLAGS + 0x30)
#define PSF_FLAG_1337                                        (SYSTEM_FLAGS + 0x31)
#define PSF_FLAG_1338                                        (SYSTEM_FLAGS + 0x32)
#define PSF_FLAG_1339                                        (SYSTEM_FLAGS + 0x33)
#define PSF_FLAG_1340                                        (SYSTEM_FLAGS + 0x34)
#define PSF_FLAG_1341                                        (SYSTEM_FLAGS + 0x35)
#define PSF_FLAG_1342                                        (SYSTEM_FLAGS + 0x36)
#define PSF_FLAG_1343                                        (SYSTEM_FLAGS + 0x37)
#define PSF_FLAG_1344                                        (SYSTEM_FLAGS + 0x38)
#define PSF_FLAG_1345                                        (SYSTEM_FLAGS + 0x39)
#define PSF_FLAG_1346                                        (SYSTEM_FLAGS + 0x3A)
#define PSF_FLAG_1347                                        (SYSTEM_FLAGS + 0x3B)
#define PSF_FLAG_1348                                        (SYSTEM_FLAGS + 0x3C)
#define PSF_FLAG_1349                                        (SYSTEM_FLAGS + 0x3D)
#define PSF_FLAG_1350                                        (SYSTEM_FLAGS + 0x3E)
#define PSF_FLAG_1351                                        (SYSTEM_FLAGS + 0x3F)
#define PSF_FLAG_1352                                        (SYSTEM_FLAGS + 0x40)
#define PSF_FLAG_1353                                        (SYSTEM_FLAGS + 0x41)
#define PSF_FLAG_1354                                        (SYSTEM_FLAGS + 0x42)
#define PSF_FLAG_1355                                        (SYSTEM_FLAGS + 0x43)
#define PSF_FLAG_1356                                        (SYSTEM_FLAGS + 0x44)
#define PSF_FLAG_1357                                        (SYSTEM_FLAGS + 0x45)
#define PSF_FLAG_1358                                        (SYSTEM_FLAGS + 0x46)
#define PSF_FLAG_1359                                        (SYSTEM_FLAGS + 0x47)
#define PSF_FLAG_1360                                        (SYSTEM_FLAGS + 0x48)
#define PSF_FLAG_1361                                        (SYSTEM_FLAGS + 0x49)
#define PSF_FLAG_1362                                        (SYSTEM_FLAGS + 0x4A)
#define PSF_FLAG_1363                                        (SYSTEM_FLAGS + 0x4B)
#define PSF_FLAG_1364                                        (SYSTEM_FLAGS + 0x4C)
#define PSF_FLAG_1365                                        (SYSTEM_FLAGS + 0x4D)
#define PSF_FLAG_1366                                        (SYSTEM_FLAGS + 0x4E)
#define PSF_FLAG_1367                                        (SYSTEM_FLAGS + 0x4F)
#define PSF_FLAG_1368                                        (SYSTEM_FLAGS + 0x50)
#define PSF_FLAG_1369                                        (SYSTEM_FLAGS + 0x51)
#define PSF_FLAG_1370                                        (SYSTEM_FLAGS + 0x52)
#define PSF_FLAG_1371                                        (SYSTEM_FLAGS + 0x53)
#define PSF_FLAG_1372                                        (SYSTEM_FLAGS + 0x54)
#define PSF_FLAG_1373                                        (SYSTEM_FLAGS + 0x55)
#define PSF_FLAG_1374                                        (SYSTEM_FLAGS + 0x56)
#define PSF_FLAG_1375                                        (SYSTEM_FLAGS + 0x57)
#define PSF_FLAG_1376                                        (SYSTEM_FLAGS + 0x58)
#define PSF_FLAG_1377                                        (SYSTEM_FLAGS + 0x59)
#define PSF_FLAG_1378                                        (SYSTEM_FLAGS + 0x5A)
#define PSF_FLAG_1379                                        (SYSTEM_FLAGS + 0x5B)
#define PSF_FLAG_1380                                        (SYSTEM_FLAGS + 0x5C)
#define PSF_FLAG_1381                                        (SYSTEM_FLAGS + 0x5D)
#define PSF_FLAG_1382                                        (SYSTEM_FLAGS + 0x5E)
#define PSF_FLAG_1383                                        (SYSTEM_FLAGS + 0x5F)
#define PSF_FLAG_1384                                        (SYSTEM_FLAGS + 0x60)
#define PSF_FLAG_1385                                        (SYSTEM_FLAGS + 0x61)
#define PSF_FLAG_1386                                        (SYSTEM_FLAGS + 0x62)
#define PSF_FLAG_1387                                        (SYSTEM_FLAGS + 0x63)
#define PSF_FLAG_1388                                        (SYSTEM_FLAGS + 0x64)
#define PSF_FLAG_1389                                        (SYSTEM_FLAGS + 0x65)
#define PSF_FLAG_1390                                        (SYSTEM_FLAGS + 0x66)
#define PSF_FLAG_1391                                        (SYSTEM_FLAGS + 0x67)
#define PSF_FLAG_1392                                        (SYSTEM_FLAGS + 0x68)
#define PSF_FLAG_1393                                        (SYSTEM_FLAGS + 0x69)
#define PSF_FLAG_1394                                        (SYSTEM_FLAGS + 0x6A)
#define PSF_FLAG_1395                                        (SYSTEM_FLAGS + 0x6B)
#define PSF_FLAG_1396                                        (SYSTEM_FLAGS + 0x6C)
#define PSF_FLAG_1397                                        (SYSTEM_FLAGS + 0x6D)
#define PSF_FLAG_1398                                        (SYSTEM_FLAGS + 0x6E)
#define PSF_FLAG_1399                                        (SYSTEM_FLAGS + 0x6F)
#define PSF_FLAG_1400                                        (SYSTEM_FLAGS + 0x70)
#define PSF_FLAG_1401                                        (SYSTEM_FLAGS + 0x71)
#define PSF_FLAG_1402                                        (SYSTEM_FLAGS + 0x72)
#define PSF_FLAG_1403                                        (SYSTEM_FLAGS + 0x73)
#define PSF_FLAG_1404                                        (SYSTEM_FLAGS + 0x74)
#define PSF_FLAG_1405                                        (SYSTEM_FLAGS + 0x75)
#define PSF_FLAG_1406                                        (SYSTEM_FLAGS + 0x76)
#define PSF_FLAG_1407                                        (SYSTEM_FLAGS + 0x77)
#define PSF_FLAG_1408                                        (SYSTEM_FLAGS + 0x78)
#define PSF_FLAG_1409                                        (SYSTEM_FLAGS + 0x79)
#define PSF_FLAG_1410                                        (SYSTEM_FLAGS + 0x7A)
#define PSF_FLAG_1411                                        (SYSTEM_FLAGS + 0x7B)
#define PSF_FLAG_1412                                        (SYSTEM_FLAGS + 0x7C)
#define PSF_FLAG_1413                                        (SYSTEM_FLAGS + 0x7D)
#define PSF_FLAG_1414                                        (SYSTEM_FLAGS + 0x7E)
#define PSF_FLAG_1415                                        (SYSTEM_FLAGS + 0x7F)
#define PSF_FLAG_1416                                        (SYSTEM_FLAGS + 0x80)
#define PSF_FLAG_1417                                        (SYSTEM_FLAGS + 0x81)
#define PSF_FLAG_1418                                        (SYSTEM_FLAGS + 0x82)
#define PSF_FLAG_1419                                        (SYSTEM_FLAGS + 0x83)
#define PSF_FLAG_1420                                        (SYSTEM_FLAGS + 0x84)
#define PSF_FLAG_1421                                        (SYSTEM_FLAGS + 0x85)
#define PSF_FLAG_1422                                        (SYSTEM_FLAGS + 0x86)
#define PSF_FLAG_1423                                        (SYSTEM_FLAGS + 0x87)
#define PSF_FLAG_1424                                        (SYSTEM_FLAGS + 0x88)
#define PSF_FLAG_1425                                        (SYSTEM_FLAGS + 0x89)
#define PSF_FLAG_1426                                        (SYSTEM_FLAGS + 0x8A)
#define PSF_FLAG_1427                                        (SYSTEM_FLAGS + 0x8B)
#define PSF_FLAG_1428                                        (SYSTEM_FLAGS + 0x8C)
#define PSF_FLAG_1429                                        (SYSTEM_FLAGS + 0x8D)
#define PSF_FLAG_1430                                        (SYSTEM_FLAGS + 0x8E)
#define PSF_FLAG_1431                                        (SYSTEM_FLAGS + 0x8F)
#define PSF_FLAG_1432                                        (SYSTEM_FLAGS + 0x90)
#define PSF_FLAG_1433                                        (SYSTEM_FLAGS + 0x91)
#define PSF_FLAG_1434                                        (SYSTEM_FLAGS + 0x92)
#define PSF_FLAG_1435                                        (SYSTEM_FLAGS + 0x93)
#define PSF_FLAG_1436                                        (SYSTEM_FLAGS + 0x94)
#define PSF_FLAG_1437                                        (SYSTEM_FLAGS + 0x95)
#define PSF_FLAG_1438                                        (SYSTEM_FLAGS + 0x96)
#define PSF_FLAG_1439                                        (SYSTEM_FLAGS + 0x97)
#define PSF_FLAG_1440                                        (SYSTEM_FLAGS + 0x98)
#define PSF_FLAG_1441                                        (SYSTEM_FLAGS + 0x99)
#define PSF_FLAG_1442                                        (SYSTEM_FLAGS + 0x9A)
#define PSF_FLAG_1443                                        (SYSTEM_FLAGS + 0x9B)
#define PSF_FLAG_1444                                        (SYSTEM_FLAGS + 0x9C)
#define PSF_FLAG_1445                                        (SYSTEM_FLAGS + 0x9D)
#define PSF_FLAG_1446                                        (SYSTEM_FLAGS + 0x9E)
#define PSF_FLAG_1447                                        (SYSTEM_FLAGS + 0x9F)
#define PSF_FLAG_1448                                        (SYSTEM_FLAGS + 0xA0)
#define PSF_FLAG_1449                                        (SYSTEM_FLAGS + 0xA1)
#define PSF_FLAG_1450                                        (SYSTEM_FLAGS + 0xA2)
#define PSF_FLAG_1451                                        (SYSTEM_FLAGS + 0xA3)
#define PSF_FLAG_1452                                        (SYSTEM_FLAGS + 0xA4)
#define PSF_FLAG_1453                                        (SYSTEM_FLAGS + 0xA5)
#define PSF_FLAG_1454                                        (SYSTEM_FLAGS + 0xA6)
#define PSF_FLAG_1455                                        (SYSTEM_FLAGS + 0xA7)
#define PSF_FLAG_1456                                        (SYSTEM_FLAGS + 0xA8)
#define PSF_FLAG_1457                                        (SYSTEM_FLAGS + 0xA9)
#define PSF_FLAG_1458                                        (SYSTEM_FLAGS + 0xAA)
#define PSF_FLAG_1459                                        (SYSTEM_FLAGS + 0xAB)
#define PSF_FLAG_1460                                        (SYSTEM_FLAGS + 0xAC)
#define PSF_FLAG_1461                                        (SYSTEM_FLAGS + 0xAD)
#define PSF_FLAG_1462                                        (SYSTEM_FLAGS + 0xAE)
#define PSF_FLAG_1463                                        (SYSTEM_FLAGS + 0xAF)
#define PSF_FLAG_1464                                        (SYSTEM_FLAGS + 0xB0)
#define PSF_FLAG_1465                                        (SYSTEM_FLAGS + 0xB1)
#define PSF_FLAG_1466                                        (SYSTEM_FLAGS + 0xB2)
#define PSF_FLAG_1467                                        (SYSTEM_FLAGS + 0xB3)
#define PSF_FLAG_1468                                        (SYSTEM_FLAGS + 0xB4)
#define PSF_FLAG_1469                                        (SYSTEM_FLAGS + 0xB5)
#define PSF_FLAG_1470                                        (SYSTEM_FLAGS + 0xB6)
#define PSF_FLAG_1471                                        (SYSTEM_FLAGS + 0xB7)
#define PSF_FLAG_1472                                        (SYSTEM_FLAGS + 0xB8)
#define PSF_FLAG_1473                                        (SYSTEM_FLAGS + 0xB9)
#define PSF_FLAG_1474                                        (SYSTEM_FLAGS + 0xBA)
#define PSF_FLAG_1475                                        (SYSTEM_FLAGS + 0xBB)
#define PSF_FLAG_1476                                        (SYSTEM_FLAGS + 0xBC)
#define PSF_FLAG_1477                                        (SYSTEM_FLAGS + 0xBD)
#define PSF_FLAG_1478                                        (SYSTEM_FLAGS + 0xBE)
#define PSF_FLAG_1479                                        (SYSTEM_FLAGS + 0xBF)

 // Daily Flags
 // These flags are cleared once per day
 // The start and end are byte-aligned because the flags are cleared in byte increments
#define DAILY_FLAGS_START                                    (FLAG_UNUSED_0x91F + (8 - FLAG_UNUSED_0x91F % 8))
#define FLAG_DAILY_KITCHEN_VOLUNTEER                         (DAILY_FLAGS_START + 0x0)
#define PSF_FLAG_1482                                        (DAILY_FLAGS_START + 0x1)
#define PSF_FLAG_1483                                        (DAILY_FLAGS_START + 0x2)
#define PSF_FLAG_1484                                        (DAILY_FLAGS_START + 0x3)
#define PSF_FLAG_1485                                        (DAILY_FLAGS_START + 0x4)
#define PSF_FLAG_1486                                        (DAILY_FLAGS_START + 0x5)
#define PSF_FLAG_1487                                        (DAILY_FLAGS_START + 0x6)
#define PSF_FLAG_1488                                        (DAILY_FLAGS_START + 0x7)
#define PSF_FLAG_1489                                        (DAILY_FLAGS_START + 0x8)
#define PSF_FLAG_1490                                        (DAILY_FLAGS_START + 0x9)
#define PSF_FLAG_1491                                        (DAILY_FLAGS_START + 0xA)
#define PSF_FLAG_1492                                        (DAILY_FLAGS_START + 0xB)
#define PSF_FLAG_1493                                        (DAILY_FLAGS_START + 0xC)
#define PSF_FLAG_1494                                        (DAILY_FLAGS_START + 0xD)
#define PSF_FLAG_1495                                        (DAILY_FLAGS_START + 0xE)
#define PSF_FLAG_1496                                        (DAILY_FLAGS_START + 0xF)
#define PSF_FLAG_1497                                        (DAILY_FLAGS_START + 0x10)
#define PSF_FLAG_1498                                        (DAILY_FLAGS_START + 0x11)
#define PSF_FLAG_1499                                        (DAILY_FLAGS_START + 0x12)
#define PSF_FLAG_1500                                        (DAILY_FLAGS_START + 0x13)
#define PSF_FLAG_1501                                        (DAILY_FLAGS_START + 0x14)

#define PSF_FLAG_1502                                        (DAILY_FLAGS_START + 0x15)
#define PSF_FLAG_1503                                        (DAILY_FLAGS_START + 0x16)
#define PSF_FLAG_1504                                        (DAILY_FLAGS_START + 0x17)
#define PSF_FLAG_1505                                        (DAILY_FLAGS_START + 0x18)
#define PSF_FLAG_1506                                        (DAILY_FLAGS_START + 0x19)
#define PSF_FLAG_1507                                        (DAILY_FLAGS_START + 0x1A)
#define PSF_FLAG_1508                                        (DAILY_FLAGS_START + 0x1B)
#define PSF_FLAG_1509                                        (DAILY_FLAGS_START + 0x1C)
#define PSF_FLAG_1510                                        (DAILY_FLAGS_START + 0x1D)
#define PSF_FLAG_1511                                        (DAILY_FLAGS_START + 0x1E)
#define PSF_FLAG_1512                                        (DAILY_FLAGS_START + 0x1F)
#define PSF_FLAG_1513                                        (DAILY_FLAGS_START + 0x20)
#define PSF_FLAG_1514                                        (DAILY_FLAGS_START + 0x21)
#define PSF_FLAG_1515                                        (DAILY_FLAGS_START + 0x22)
#define PSF_FLAG_1516                                        (DAILY_FLAGS_START + 0x23)
#define PSF_FLAG_1517                                        (DAILY_FLAGS_START + 0x24)
#define PSF_FLAG_1518                                        (DAILY_FLAGS_START + 0x25)
#define PSF_FLAG_1519                                        (DAILY_FLAGS_START + 0x26)
#define PSF_FLAG_1520                                        (DAILY_FLAGS_START + 0x27)
#define PSF_FLAG_1521                                        (DAILY_FLAGS_START + 0x28)
#define PSF_FLAG_1522                                        (DAILY_FLAGS_START + 0x29)
#define PSF_FLAG_1523                                        (DAILY_FLAGS_START + 0x2A)
#define PSF_FLAG_1524                                        (DAILY_FLAGS_START + 0x2B)
#define PSF_FLAG_1525                                        (DAILY_FLAGS_START + 0x2C)
#define PSF_FLAG_1526                                        (DAILY_FLAGS_START + 0x2D)
#define PSF_FLAG_1527                                        (DAILY_FLAGS_START + 0x2E)
#define PSF_FLAG_1528                                        (DAILY_FLAGS_START + 0x2F)
#define PSF_FLAG_1529                                        (DAILY_FLAGS_START + 0x30)
#define PSF_FLAG_1530                                        (DAILY_FLAGS_START + 0x31)
#define PSF_FLAG_1531                                        (DAILY_FLAGS_START + 0x32)
#define PSF_FLAG_1532                                        (DAILY_FLAGS_START + 0x33)
#define PSF_FLAG_1533                                        (DAILY_FLAGS_START + 0x34)
#define PSF_FLAG_1534                                        (DAILY_FLAGS_START + 0x35)
#define PSF_FLAG_1535                                        (DAILY_FLAGS_START + 0x36)
#define PSF_FLAG_1536                                        (DAILY_FLAGS_START + 0x37)
#define PSF_FLAG_1537                                        (DAILY_FLAGS_START + 0x38)
#define PSF_FLAG_1538                                        (DAILY_FLAGS_START + 0x39)
#define PSF_FLAG_1539                                        (DAILY_FLAGS_START + 0x3A)
#define PSF_FLAG_1540                                        (DAILY_FLAGS_START + 0x3B)
#define PSF_FLAG_1541                                        (DAILY_FLAGS_START + 0x3C)
#define PSF_FLAG_1542                                        (DAILY_FLAGS_START + 0x3D)
#define PSF_FLAG_1543                                        (DAILY_FLAGS_START + 0x3E)
#define PSF_FLAG_1544                                        (DAILY_FLAGS_START + 0x3F)
#define DAILY_FLAGS_END                                      (FLAG_UNUSED_0x95F + (7 - FLAG_UNUSED_0x95F % 8))

#define FLAGS_COUNT                                          (DAILY_FLAGS_END + 1)

 // Special Flags (Stored in EWRAM (sSpecialFlags), not in the SaveBlock)
#define SPECIAL_FLAGS_START                                  0x4000
#define FLAG_HIDE_MAP_NAME_POPUP                             (SPECIAL_FLAGS_START + 0x0)
#define FLAG_DONT_TRANSITION_MUSIC                           (SPECIAL_FLAGS_START + 0x1)
#define FLAG_ENABLE_MULTI_CORRIDOR_DOOR                      (SPECIAL_FLAGS_START + 0x2)
#define FLAG_SPECIAL_FLAG_UNUSED_0x4003                      (SPECIAL_FLAGS_START + 0x3)
#define FLAG_STORING_ITEMS_IN_PYRAMID_BAG                    (SPECIAL_FLAGS_START + 0x4)
 // FLAG_SPECIAL_FLAG_0x4005 - 0x407F also exist and are unused
#define SPECIAL_FLAGS_END                                    (SPECIAL_FLAGS_START + 0x7F)

// ***********************************************************************
// DO NOT EDIT BELOW THIS LINE.
// Below this line is vanilla expansion's flags.h file and is only here for reference.
// ***********************************************************************
//*********************************

// Temporary Flags
// These temporary flags are are cleared every time a map is loaded. They are used
// for things like shortening an NPCs introduction text if the player already spoke
// to them once.
#define TEMP_FLAGS_START 0x0
#define FLAG_TEMP_1      (TEMP_FLAGS_START + 0x1)
#define FLAG_TEMP_2      (TEMP_FLAGS_START + 0x2)
#define FLAG_TEMP_3      (TEMP_FLAGS_START + 0x3)
#define FLAG_TEMP_4      (TEMP_FLAGS_START + 0x4)
#define FLAG_TEMP_5      (TEMP_FLAGS_START + 0x5)  // Unused Flag
#define FLAG_TEMP_6      (TEMP_FLAGS_START + 0x6)  // Unused Flag
#define FLAG_TEMP_7      (TEMP_FLAGS_START + 0x7)  // Unused Flag
#define FLAG_TEMP_8      (TEMP_FLAGS_START + 0x8)  // Unused Flag
#define FLAG_TEMP_9      (TEMP_FLAGS_START + 0x9)  // Unused Flag
#define FLAG_TEMP_A      (TEMP_FLAGS_START + 0xA)  // Unused Flag
#define FLAG_TEMP_B      (TEMP_FLAGS_START + 0xB)  // Unused Flag
#define FLAG_TEMP_C      (TEMP_FLAGS_START + 0xC)  // Unused Flag
#define FLAG_TEMP_D      (TEMP_FLAGS_START + 0xD)  // Unused Flag
#define FLAG_TEMP_E      (TEMP_FLAGS_START + 0xE)  // Unused Flag
#define FLAG_TEMP_F      (TEMP_FLAGS_START + 0xF)  // Unused Flag
#define FLAG_TEMP_10     (TEMP_FLAGS_START + 0x10) // Unused Flag
#define FLAG_TEMP_11     (TEMP_FLAGS_START + 0x11)
#define FLAG_TEMP_12     (TEMP_FLAGS_START + 0x12)
#define FLAG_TEMP_13     (TEMP_FLAGS_START + 0x13)
#define FLAG_TEMP_14     (TEMP_FLAGS_START + 0x14)
#define FLAG_TEMP_15     (TEMP_FLAGS_START + 0x15)
#define FLAG_TEMP_16     (TEMP_FLAGS_START + 0x16)
#define FLAG_TEMP_17     (TEMP_FLAGS_START + 0x17)
#define FLAG_TEMP_18     (TEMP_FLAGS_START + 0x18)
#define FLAG_TEMP_19     (TEMP_FLAGS_START + 0x19)
#define FLAG_TEMP_1A     (TEMP_FLAGS_START + 0x1A)
#define FLAG_TEMP_1B     (TEMP_FLAGS_START + 0x1B)
#define FLAG_TEMP_1C     (TEMP_FLAGS_START + 0x1C)
#define FLAG_TEMP_1D     (TEMP_FLAGS_START + 0x1D)
#define FLAG_TEMP_1E     (TEMP_FLAGS_START + 0x1E)
#define FLAG_TEMP_1F     (TEMP_FLAGS_START + 0x1F)
#define TEMP_FLAGS_END   FLAG_TEMP_1F

#define FLAG_UNUSED_0x020    0x20 // Unused Flag
#define FLAG_UNUSED_0x021    0x21 // Unused Flag
#define FLAG_UNUSED_0x022    0x22 // Unused Flag
#define FLAG_UNUSED_0x023    0x23 // Unused Flag
#define FLAG_UNUSED_0x024    0x24 // Unused Flag
#define FLAG_UNUSED_0x025    0x25 // Unused Flag
#define FLAG_UNUSED_0x026    0x26 // Unused Flag
#define FLAG_UNUSED_0x027    0x27 // Unused Flag
#define FLAG_UNUSED_0x028    0x28 // Unused Flag
#define FLAG_UNUSED_0x029    0x29 // Unused Flag
#define FLAG_UNUSED_0x02A    0x2A // Unused Flag
#define FLAG_UNUSED_0x02B    0x2B // Unused Flag
#define FLAG_UNUSED_0x02C    0x2C // Unused Flag
#define FLAG_UNUSED_0x02D    0x2D // Unused Flag
#define FLAG_UNUSED_0x02E    0x2E // Unused Flag
#define FLAG_UNUSED_0x02F    0x2F // Unused Flag
#define FLAG_UNUSED_0x030    0x30 // Unused Flag
#define FLAG_UNUSED_0x031    0x31 // Unused Flag
#define FLAG_UNUSED_0x032    0x32 // Unused Flag
#define FLAG_UNUSED_0x033    0x33 // Unused Flag
#define FLAG_UNUSED_0x034    0x34 // Unused Flag
#define FLAG_UNUSED_0x035    0x35 // Unused Flag
#define FLAG_UNUSED_0x036    0x36 // Unused Flag
#define FLAG_UNUSED_0x037    0x37 // Unused Flag
#define FLAG_UNUSED_0x038    0x38 // Unused Flag
#define FLAG_UNUSED_0x039    0x39 // Unused Flag
#define FLAG_UNUSED_0x03A    0x3A // Unused Flag
#define FLAG_UNUSED_0x03B    0x3B // Unused Flag
#define FLAG_UNUSED_0x03C    0x3C // Unused Flag
#define FLAG_UNUSED_0x03D    0x3D // Unused Flag
#define FLAG_UNUSED_0x03E    0x3E // Unused Flag
#define FLAG_UNUSED_0x03F    0x3F // Unused Flag
#define FLAG_UNUSED_0x040    0x40 // Unused Flag
#define FLAG_UNUSED_0x041    0x41 // Unused Flag
#define FLAG_UNUSED_0x042    0x42 // Unused Flag
#define FLAG_UNUSED_0x043    0x43 // Unused Flag
#define FLAG_UNUSED_0x044    0x44 // Unused Flag
#define FLAG_UNUSED_0x045    0x45 // Unused Flag
#define FLAG_UNUSED_0x046    0x46 // Unused Flag
#define FLAG_UNUSED_0x047    0x47 // Unused Flag
#define FLAG_UNUSED_0x048    0x48 // Unused Flag
#define FLAG_UNUSED_0x049    0x49 // Unused Flag
#define FLAG_UNUSED_0x04A    0x4A // Unused Flag
#define FLAG_UNUSED_0x04B    0x4B // Unused Flag
#define FLAG_UNUSED_0x04C    0x4C // Unused Flag
#define FLAG_UNUSED_0x04D    0x4D // Unused Flag
#define FLAG_UNUSED_0x04E    0x4E // Unused Flag
#define FLAG_UNUSED_0x04F    0x4F // Unused Flag

// Scripts
#define FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA_STILL  0x50
#define FLAG_SET_WALL_CLOCK                      0x51
#define FLAG_RESCUED_BIRCH                       0x52
#define FLAG_LEGENDARIES_IN_SOOTOPOLIS           0x53

#define FLAG_UNUSED_0x054                    0x54  // Unused Flag
#define FLAG_UNUSED_0x055                    0x55  // Unused Flag

#define FLAG_HIDE_CONTEST_POKE_BALL          0x56  // Always set after new game, object it hides is added directly
#define FLAG_MET_RIVAL_MOM                   0x57
#define FLAG_BIRCH_AIDE_MET                  0x58
#define FLAG_DECLINED_BIKE                   0x59
#define FLAG_RECEIVED_BIKE                   0x5A
#define FLAG_WATTSON_REMATCH_AVAILABLE       0x5B
#define FLAG_COLLECTED_ALL_SILVER_SYMBOLS    0x5C
#define FLAG_GOOD_LUCK_SAFARI_ZONE           0x5D // Set after talking to NPC blocking Safari Zone entrance/exit once.
#define FLAG_RECEIVED_WAILMER_PAIL           0x5E
#define FLAG_RECEIVED_POKEBLOCK_CASE         0x5F
#define FLAG_RECEIVED_SECRET_POWER           0x60
#define FLAG_MET_TEAM_AQUA_HARBOR            0x61
#define FLAG_TV_EXPLAINED                    0x62
#define FLAG_MAUVILLE_GYM_BARRIERS_STATE     0x63
#define FLAG_MOSSDEEP_GYM_SWITCH_1           0x64 // Leftover from the RS version of Mossdeep Gym, functionally unused
#define FLAG_MOSSDEEP_GYM_SWITCH_2           0x65 //
#define FLAG_MOSSDEEP_GYM_SWITCH_3           0x66 //
#define FLAG_MOSSDEEP_GYM_SWITCH_4           0x67 //

#define FLAG_UNUSED_0x068                    0x68  // Unused Flag

#define FLAG_OCEANIC_MUSEUM_MET_REPORTER     0x69
#define FLAG_RECEIVED_HM04                   0x6A
#define FLAG_RECEIVED_HM06                   0x6B
#define FLAG_WHITEOUT_TO_LAVARIDGE           0x6C // Set after defeating Flannery, so the player cant white out from poison before receiving Go Goggles
#define FLAG_RECEIVED_HM05                   0x6D
#define FLAG_RECEIVED_HM02                   0x6E
#define FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT  0x6F
#define FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE  0x70
#define FLAG_UNUSED_RS_LEGENDARY_BATTLE_DONE 0x71 // Unused Flag. Used in R/S to indicate whether player defeated or caught Groudon/Kyogre in Cave of Origin.
#define FLAG_SCOTT_CALL_BATTLE_FRONTIER      0x72 // Used in order to activate a phone call from Scott, inviting the player to the SS Tidal.
#define FLAG_RECEIVED_METEORITE              0x73
#define FLAG_ADVENTURE_STARTED               0x74 // RECEIVED Pokédex.
#define FLAG_DEFEATED_MAGMA_SPACE_CENTER     0x75 // Set when Team Magma is defeated at Mossdeep's Space Center.
#define FLAG_MET_HIDDEN_POWER_GIVER          0x76

#define FLAG_CANCEL_BATTLE_ROOM_CHALLENGE    0x77

#define FLAG_LANDMARK_MIRAGE_TOWER           0x78
#define FLAG_RECEIVED_TM31                   0x79
#define FLAG_RECEIVED_HM03                   0x7A
#define FLAG_RECEIVED_HM08                   0x7B
#define FLAG_REGISTER_RIVAL_POKENAV          0x7C
#define FLAG_DEFEATED_RIVAL_ROUTE_104        0x7D
#define FLAG_DEFEATED_WALLY_VICTORY_ROAD     0x7E
#define FLAG_MET_PRETTY_PETAL_SHOP_OWNER     0x7F
#define FLAG_ENABLE_ROXANNE_FIRST_CALL       0x80 // Set after defeating Brawly. This will activate a call with Roxanne in order to register her.
#define FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN  0x81
#define FLAG_DEFEATED_RIVAL_ROUTE103         0x82
#define FLAG_RECEIVED_DOLL_LANETTE           0x83
#define FLAG_RECEIVED_POTION_OLDALE          0x84
#define FLAG_RECEIVED_AMULET_COIN            0x85
#define FLAG_PENDING_DAYCARE_EGG             0x86
#define FLAG_THANKED_FOR_PLAYING_WITH_WALLY  0x87
#define FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL 0x88 // Set after defeating Wally outside Mauville Gym. Will activate a call later to register Wally.
#define FLAG_RECEIVED_HM01                   0x89
#define FLAG_SCOTT_CALL_FORTREE_GYM          0x8A // Triggers call from Scott after defeating Winona
#define FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY   0x8B
#define FLAG_RECEIVED_6_SODA_POP             0x8C
#define FLAG_DEFEATED_SEASHORE_HOUSE         0x8D
#define FLAG_DEVON_GOODS_STOLEN              0x8E
#define FLAG_RECOVERED_DEVON_GOODS           0x8F
#define FLAG_RETURNED_DEVON_GOODS            0x90
#define FLAG_CAUGHT_LUGIA                    0x91
#define FLAG_CAUGHT_HO_OH                    0x92
#define FLAG_MR_BRINEY_SAILING_INTRO         0x93
#define FLAG_DOCK_REJECTED_DEVON_GOODS       0x94
#define FLAG_DELIVERED_DEVON_GOODS           0x95
#define FLAG_RECEIVED_CONTEST_PASS           0x96 // Unused, leftover from R/S
#define FLAG_RECEIVED_CASTFORM               0x97
#define FLAG_RECEIVED_SUPER_ROD              0x98
#define FLAG_RUSTBORO_NPC_TRADE_COMPLETED    0x99
#define FLAG_PACIFIDLOG_NPC_TRADE_COMPLETED  0x9A
#define FLAG_FORTREE_NPC_TRADE_COMPLETED     0x9B
#define FLAG_BATTLE_FRONTIER_TRADE_DONE      0x9C
#define FLAG_FORCE_MIRAGE_TOWER_VISIBLE      0x9D
#define FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE   0x9E
#define FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN 0x9F
#define FLAG_COOL_PAINTING_MADE              0xA0
#define FLAG_BEAUTY_PAINTING_MADE            0xA1
#define FLAG_CUTE_PAINTING_MADE              0xA2
#define FLAG_SMART_PAINTING_MADE             0xA3
#define FLAG_TOUGH_PAINTING_MADE             0xA4
#define FLAG_RECEIVED_TM39                   0xA5
#define FLAG_RECEIVED_TM08                   0xA6
#define FLAG_RECEIVED_TM34                   0xA7
#define FLAG_RECEIVED_TM50                   0xA8
#define FLAG_RECEIVED_TM42                   0xA9
#define FLAG_RECEIVED_TM40                   0xAA
#define FLAG_RECEIVED_TM04                   0xAB
#define FLAG_RECEIVED_TM03                   0xAC
#define FLAG_HIDE_SECRET_BASE_TRAINER        0xAD
#define FLAG_DECORATION_1                    0xAE
#define FLAG_DECORATION_2                    0xAF
#define FLAG_DECORATION_3                    0xB0
#define FLAG_DECORATION_4                    0xB1
#define FLAG_DECORATION_5                    0xB2
#define FLAG_DECORATION_6                    0xB3
#define FLAG_DECORATION_7                    0xB4
#define FLAG_DECORATION_8                    0xB5
#define FLAG_DECORATION_9                    0xB6
#define FLAG_DECORATION_10                   0xB7
#define FLAG_DECORATION_11                   0xB8
#define FLAG_DECORATION_12                   0xB9
#define FLAG_DECORATION_13                   0xBA
#define FLAG_DECORATION_14                   0xBB
#define FLAG_RECEIVED_POKENAV                0xBC
#define FLAG_DELIVERED_STEVEN_LETTER         0xBD
#define FLAG_DEFEATED_WALLY_MAUVILLE         0xBE
#define FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F  0xBF
#define FLAG_RECEIVED_SUN_STONE_MOSSDEEP     0xC0
#define FLAG_WALLY_SPEECH                    0xC1
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_1   0xC2 // Leftover from the RS version of Puzzle Room 7, functionally unused
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_2   0xC3 //
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_3   0xC4 //
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_4   0xC5 //
#define FLAG_TRICK_HOUSE_PUZZLE_7_SWITCH_5   0xC6 //
#define FLAG_RUSTURF_TUNNEL_OPENED           0xC7
#define FLAG_RECEIVED_RED_SCARF              0xC8
#define FLAG_RECEIVED_BLUE_SCARF             0xC9
#define FLAG_RECEIVED_PINK_SCARF             0xCA
#define FLAG_RECEIVED_GREEN_SCARF            0xCB
#define FLAG_RECEIVED_YELLOW_SCARF           0xCC
#define FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER    0xCD
#define FLAG_ENCOUNTERED_LATIAS_OR_LATIOS    0xCE
#define FLAG_MET_ARCHIE_METEOR_FALLS         0xCF
#define FLAG_GOT_BASEMENT_KEY_FROM_WATTSON   0xD0
#define FLAG_GOT_TM24_FROM_WATTSON           0xD1
#define FLAG_FAN_CLUB_STRENGTH_SHARED        0xD2 // Set when you rate the strength of another trainer in Lilycove's Trainer Fan Club.
#define FLAG_DEFEATED_RIVAL_RUSTBORO         0xD3
#define FLAG_RECEIVED_RED_OR_BLUE_ORB        0xD4
#define FLAG_RECEIVED_PREMIER_BALL_RUSTBORO  0xD5
#define FLAG_ENABLE_WALLY_MATCH_CALL         0xD6
#define FLAG_ENABLE_SCOTT_MATCH_CALL         0xD7
#define FLAG_ENABLE_MOM_MATCH_CALL           0xD8
#define FLAG_MET_DIVING_TREASURE_HUNTER      0xD9
#define FLAG_MET_WAILMER_TRAINER             0xDA
#define FLAG_EVIL_LEADER_PLEASE_STOP         0xDB

#define FLAG_NEVER_SET_0x0DC                 0xDC // This flag is read, but never written to

#define FLAG_RECEIVED_GO_GOGGLES             0xDD
#define FLAG_WINGULL_SENT_ON_ERRAND          0xDE
#define FLAG_RECEIVED_MENTAL_HERB            0xDF
#define FLAG_WINGULL_DELIVERED_MAIL          0xE0
#define FLAG_RECEIVED_20_COINS               0xE1
#define FLAG_RECEIVED_STARTER_DOLL           0xE2
#define FLAG_RECEIVED_GOOD_ROD               0xE3
#define FLAG_REGI_DOORS_OPENED               0xE4
#define FLAG_RECEIVED_TM27                   0xE5
#define FLAG_RECEIVED_TM36                   0xE6
#define FLAG_RECEIVED_TM05                   0xE7
#define FLAG_RECEIVED_TM19                   0xE8

#define FLAG_UNUSED_0x0E9                    0xE9 // Unused Flag

#define FLAG_RECEIVED_TM44                   0xEA
#define FLAG_RECEIVED_TM45                   0xEB
#define FLAG_RECEIVED_GLASS_ORNAMENT         0xEC
#define FLAG_RECEIVED_SILVER_SHIELD          0xED
#define FLAG_RECEIVED_GOLD_SHIELD            0xEE
#define FLAG_USED_STORAGE_KEY                0xEF
#define FLAG_USED_ROOM_1_KEY                 0xF0
#define FLAG_USED_ROOM_2_KEY                 0xF1
#define FLAG_USED_ROOM_4_KEY                 0xF2
#define FLAG_USED_ROOM_6_KEY                 0xF3
#define FLAG_MET_PROF_COZMO                  0xF4
#define FLAG_RECEIVED_WAILMER_DOLL           0xF5
#define FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104 0xF6
#define FLAG_DEFEATED_SS_TIDAL_TRAINERS      0xF7
#define FLAG_RECEIVED_SPELON_BERRY           0xF8
#define FLAG_RECEIVED_PAMTRE_BERRY           0xF9
#define FLAG_RECEIVED_WATMEL_BERRY           0xFA
#define FLAG_RECEIVED_DURIN_BERRY            0xFB
#define FLAG_RECEIVED_BELUE_BERRY            0xFC
#define FLAG_ENABLE_RIVAL_MATCH_CALL         0xFD
#define FLAG_RECEIVED_CHARCOAL               0xFE
#define FLAG_LATIOS_OR_LATIAS_ROAMING        0xFF
#define FLAG_RECEIVED_REPEAT_BALL            0x100
#define FLAG_RECEIVED_OLD_ROD                0x101
#define FLAG_RECEIVED_COIN_CASE              0x102
#define FLAG_RETURNED_RED_OR_BLUE_ORB        0x103
#define FLAG_RECEIVED_TM49                   0x104
#define FLAG_RECEIVED_TM28                   0x105
#define FLAG_RECEIVED_TM09                   0x106
#define FLAG_ENTERED_ELITE_FOUR              0x107
#define FLAG_RECEIVED_TM10                   0x108
#define FLAG_RECEIVED_TM41                   0x109
#define FLAG_RECEIVED_LAVARIDGE_EGG          0x10A
#define FLAG_RECEIVED_REVIVED_FOSSIL_MON     0x10B
#define FLAG_SECRET_BASE_REGISTRY_ENABLED    0x10C
#define FLAG_RECEIVED_TM46                   0x10D
#define FLAG_CONTEST_SKETCH_CREATED          0x10E  // Set but never read
#define FLAG_EVIL_TEAM_ESCAPED_STERN_SPOKE   0x10F
#define FLAG_RECEIVED_EXP_SHARE              0x110
#define FLAG_POKERUS_EXPLAINED               0x111
#define FLAG_RECEIVED_RUNNING_SHOES          0x112
#define FLAG_RECEIVED_QUICK_CLAW             0x113
#define FLAG_RECEIVED_KINGS_ROCK             0x114
#define FLAG_RECEIVED_MACHO_BRACE            0x115
#define FLAG_RECEIVED_SOOTHE_BELL            0x116
#define FLAG_RECEIVED_WHITE_HERB             0x117
#define FLAG_RECEIVED_SOFT_SAND              0x118
#define FLAG_ENABLE_PROF_BIRCH_MATCH_CALL    0x119
#define FLAG_RECEIVED_CLEANSE_TAG            0x11A
#define FLAG_RECEIVED_FOCUS_BAND             0x11B
#define FLAG_DECLINED_WALLY_BATTLE_MAUVILLE  0x11C
#define FLAG_RECEIVED_DEVON_SCOPE            0x11D
#define FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE  0x11E
#define FLAG_MET_DEVON_EMPLOYEE              0x11F
#define FLAG_MET_RIVAL_RUSTBORO              0x120
#define FLAG_RECEIVED_SILK_SCARF             0x121
#define FLAG_NOT_READY_FOR_BATTLE_ROUTE_120  0x122
#define FLAG_RECEIVED_SS_TICKET              0x123
#define FLAG_MET_RIVAL_LILYCOVE              0x124
#define FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE 0x125
#define FLAG_EXCHANGED_SCANNER               0x126
#define FLAG_KECLEON_FLED_FORTREE            0x127
#define FLAG_PETALBURG_MART_EXPANDED_ITEMS   0x128
#define FLAG_RECEIVED_MIRACLE_SEED           0x129
#define FLAG_RECEIVED_BELDUM                 0x12A
#define FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK   0x12B
#define FLAG_MET_FANCLUB_YOUNGER_BROTHER     0x12C
#define FLAG_RIVAL_LEFT_FOR_ROUTE103         0x12D
#define FLAG_OMIT_DIVE_FROM_STEVEN_LETTER    0x12E
#define FLAG_HAS_MATCH_CALL                  0x12F
#define FLAG_ADDED_MATCH_CALL_TO_POKENAV     0x130
#define FLAG_REGISTERED_STEVEN_POKENAV       0x131
#define FLAG_ENABLE_NORMAN_MATCH_CALL        0x132
#define FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN 0x133 // Set after you follow Steven to the entrance of the Cave of Origin.
#define FLAG_MET_ARCHIE_SOOTOPOLIS           0x134
#define FLAG_MET_MAXIE_SOOTOPOLIS            0x135
#define FLAG_MET_SCOTT_RUSTBORO              0x136
#define FLAG_WALLACE_GOES_TO_SKY_PILLAR      0x137 // Set after speaking to Wallace within the Cave of Origin.
#define FLAG_RECEIVED_HM07                   0x138
#define FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS    0x139
#define FLAG_RECEIVED_AURORA_TICKET          0x13A
#define FLAG_RECEIVED_MYSTIC_TICKET          0x13B
#define FLAG_RECEIVED_OLD_SEA_MAP            0x13C
#define FLAG_WONDER_CARD_UNUSED_1            0x13D // These Wonder Card flags are referenced but never set
#define FLAG_WONDER_CARD_UNUSED_2            0x13E
#define FLAG_WONDER_CARD_UNUSED_3            0x13F
#define FLAG_WONDER_CARD_UNUSED_4            0x140
#define FLAG_WONDER_CARD_UNUSED_5            0x141
#define FLAG_WONDER_CARD_UNUSED_6            0x142
#define FLAG_WONDER_CARD_UNUSED_7            0x143
#define FLAG_WONDER_CARD_UNUSED_8            0x144
#define FLAG_WONDER_CARD_UNUSED_9            0x145
#define FLAG_WONDER_CARD_UNUSED_10           0x146
#define FLAG_WONDER_CARD_UNUSED_11           0x147
#define FLAG_WONDER_CARD_UNUSED_12           0x148
#define FLAG_WONDER_CARD_UNUSED_13           0x149
#define FLAG_WONDER_CARD_UNUSED_14           0x14A
#define FLAG_WONDER_CARD_UNUSED_15           0x14B
#define FLAG_WONDER_CARD_UNUSED_16           0x14C
#define FLAG_WONDER_CARD_UNUSED_17           0x14D
#define NUM_WONDER_CARD_FLAGS                (1 + FLAG_WONDER_CARD_UNUSED_17 - FLAG_RECEIVED_AURORA_TICKET)

#define FLAG_MIRAGE_TOWER_VISIBLE            0x14E
#define FLAG_CHOSE_ROOT_FOSSIL               0x14F
#define FLAG_CHOSE_CLAW_FOSSIL               0x150
#define FLAG_RECEIVED_POWDER_JAR             0x151

#define FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER 0x152

#define FLAG_MET_BATTLE_FRONTIER_BREEDER     0x153
#define FLAG_MET_BATTLE_FRONTIER_MANIAC      0x154
#define FLAG_ENTERED_CONTEST                 0x155
#define FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN  0x156
#define FLAG_MET_BATTLE_FRONTIER_GAMBLER     0x157
#define FLAG_ENABLE_MR_STONE_POKENAV         0x158
#define FLAG_NURSE_MENTIONS_GOLD_CARD        0x159
#define FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR  0x15A
#define FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR 0x15B

// Trainer Rematch Flags
#define FLAG_MATCH_CALL_REGISTERED           0x15C
#define FLAG_REMATCH_ROSE                    0x15D
#define FLAG_REMATCH_ANDRES                  0x15E
#define FLAG_REMATCH_DUSTY                   0x15F
#define FLAG_REMATCH_LOLA                    0x160
#define FLAG_REMATCH_RICKY                   0x161
#define FLAG_REMATCH_LILA_AND_ROY            0x162
#define FLAG_REMATCH_CRISTIN                 0x163
#define FLAG_REMATCH_BROOKE                  0x164
#define FLAG_REMATCH_WILTON                  0x165
#define FLAG_REMATCH_VALERIE                 0x166
#define FLAG_REMATCH_CINDY                   0x167
#define FLAG_REMATCH_THALIA                  0x168
#define FLAG_REMATCH_JESSICA                 0x169
#define FLAG_REMATCH_WINSTON                 0x16A
#define FLAG_REMATCH_STEVE                   0x16B
#define FLAG_REMATCH_TONY                    0x16C
#define FLAG_REMATCH_NOB                     0x16D
#define FLAG_REMATCH_KOJI                    0x16E
#define FLAG_REMATCH_FERNANDO                0x16F
#define FLAG_REMATCH_DALTON                  0x170
#define FLAG_REMATCH_BERNIE                  0x171
#define FLAG_REMATCH_ETHAN                   0x172
#define FLAG_REMATCH_JOHN_AND_JAY            0x173
#define FLAG_REMATCH_JEFFREY                 0x174
#define FLAG_REMATCH_CAMERON                 0x175
#define FLAG_REMATCH_JACKI                   0x176
#define FLAG_REMATCH_WALTER                  0x177
#define FLAG_REMATCH_KAREN                   0x178
#define FLAG_REMATCH_JERRY                   0x179
#define FLAG_REMATCH_ANNA_AND_MEG            0x17A
#define FLAG_REMATCH_ISABEL                  0x17B
#define FLAG_REMATCH_MIGUEL                  0x17C
#define FLAG_REMATCH_TIMOTHY                 0x17D
#define FLAG_REMATCH_SHELBY                  0x17E
#define FLAG_REMATCH_CALVIN                  0x17F
#define FLAG_REMATCH_ELLIOT                  0x180
#define FLAG_REMATCH_ISAIAH                  0x181
#define FLAG_REMATCH_MARIA                   0x182
#define FLAG_REMATCH_ABIGAIL                 0x183
#define FLAG_REMATCH_DYLAN                   0x184
#define FLAG_REMATCH_KATELYN                 0x185
#define FLAG_REMATCH_BENJAMIN                0x186
#define FLAG_REMATCH_PABLO                   0x187
#define FLAG_REMATCH_NICOLAS                 0x188
#define FLAG_REMATCH_ROBERT                  0x189
#define FLAG_REMATCH_LAO                     0x18A
#define FLAG_REMATCH_CYNDY                   0x18B
#define FLAG_REMATCH_MADELINE                0x18C
#define FLAG_REMATCH_JENNY                   0x18D
#define FLAG_REMATCH_DIANA                   0x18E
#define FLAG_REMATCH_AMY_AND_LIV             0x18F
#define FLAG_REMATCH_ERNEST                  0x190
#define FLAG_REMATCH_CORY                    0x191
#define FLAG_REMATCH_EDWIN                   0x192
#define FLAG_REMATCH_LYDIA                   0x193
#define FLAG_REMATCH_ISAAC                   0x194
#define FLAG_REMATCH_GABRIELLE               0x195
#define FLAG_REMATCH_CATHERINE               0x196
#define FLAG_REMATCH_JACKSON                 0x197
#define FLAG_REMATCH_HALEY                   0x198
#define FLAG_REMATCH_JAMES                   0x199
#define FLAG_REMATCH_TRENT                   0x19A
#define FLAG_REMATCH_SAWYER                  0x19B
#define FLAG_REMATCH_KIRA_AND_DAN            0x19C
#define FLAG_REMATCH_WALLY                   0x19D
#define FLAG_REMATCH_ROXANNE                 0x19E
#define FLAG_REMATCH_BRAWLY                  0x19F
#define FLAG_REMATCH_WATTSON                 0x1A0
#define FLAG_REMATCH_FLANNERY                0x1A1
#define FLAG_REMATCH_NORMAN                  0x1A2
#define FLAG_REMATCH_WINONA                  0x1A3
#define FLAG_REMATCH_TATE_AND_LIZA           0x1A4
// Note: FLAG_REMATCH_JUAN is handled by FLAG_ENABLE_JUAN_MATCH_CALL instead.
#define FLAG_REMATCH_SIDNEY                  0x1A5
#define FLAG_REMATCH_PHOEBE                  0x1A6
#define FLAG_REMATCH_GLACIA                  0x1A7
#define FLAG_REMATCH_DRAKE                   0x1A8
#define FLAG_REMATCH_WALLACE                 0x1A9

#define FLAG_UNUSED_0x1AA                    0x1AA // Unused Flag
#define FLAG_UNUSED_0x1AB                    0x1AB // Unused Flag

#define FLAG_DEFEATED_DEOXYS                 0x1AC
#define FLAG_BATTLED_DEOXYS                  0x1AD
#define FLAG_SHOWN_EON_TICKET                0x1AE
#define FLAG_SHOWN_AURORA_TICKET             0x1AF
#define FLAG_SHOWN_OLD_SEA_MAP               0x1B0
#define FLAG_MOVE_TUTOR_TAUGHT_SWAGGER       0x1B1
#define FLAG_MOVE_TUTOR_TAUGHT_ROLLOUT       0x1B2
#define FLAG_MOVE_TUTOR_TAUGHT_FURY_CUTTER   0x1B3
#define FLAG_MOVE_TUTOR_TAUGHT_MIMIC         0x1B4
#define FLAG_MOVE_TUTOR_TAUGHT_METRONOME     0x1B5
#define FLAG_MOVE_TUTOR_TAUGHT_SLEEP_TALK    0x1B6
#define FLAG_MOVE_TUTOR_TAUGHT_SUBSTITUTE    0x1B7
#define FLAG_MOVE_TUTOR_TAUGHT_DYNAMICPUNCH  0x1B8
#define FLAG_MOVE_TUTOR_TAUGHT_DOUBLE_EDGE   0x1B9
#define FLAG_MOVE_TUTOR_TAUGHT_EXPLOSION     0x1BA
#define FLAG_DEFEATED_REGIROCK               0x1BB
#define FLAG_DEFEATED_REGICE                 0x1BC
#define FLAG_DEFEATED_REGISTEEL              0x1BD
#define FLAG_DEFEATED_KYOGRE                 0x1BE
#define FLAG_DEFEATED_GROUDON                0x1BF
#define FLAG_DEFEATED_RAYQUAZA               0x1C0
#define FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE 0x1C1
#define FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE 0x1C2
#define FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE 0x1C3
#define FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT 0x1C4
#define FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT 0x1C5
#define FLAG_DEFEATED_SUDOWOODO              0x1C6
#define FLAG_DEFEATED_MEW                    0x1C7
#define FLAG_DEFEATED_LATIAS_OR_LATIOS       0x1C8
#define FLAG_CAUGHT_LATIAS_OR_LATIOS         0x1C9
#define FLAG_CAUGHT_MEW                      0x1CA
#define FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE 0x1CB
#define FLAG_MET_SCOTT_IN_VERDANTURF         0x1CC
#define FLAG_MET_SCOTT_IN_FALLARBOR          0x1CD
#define FLAG_MET_SCOTT_IN_LILYCOVE           0x1CE
#define FLAG_MET_SCOTT_IN_EVERGRANDE         0x1CF
#define FLAG_MET_SCOTT_ON_SS_TIDAL           0x1D0
#define FLAG_SCOTT_GIVES_BATTLE_POINTS       0x1D1
#define FLAG_COLLECTED_ALL_GOLD_SYMBOLS      0x1D2
#define FLAG_ENABLE_ROXANNE_MATCH_CALL       0x1D3
#define FLAG_ENABLE_BRAWLY_MATCH_CALL        0x1D4
#define FLAG_ENABLE_WATTSON_MATCH_CALL       0x1D5
#define FLAG_ENABLE_FLANNERY_MATCH_CALL      0x1D6
#define FLAG_ENABLE_WINONA_MATCH_CALL        0x1D7
#define FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL 0x1D8
#define FLAG_ENABLE_JUAN_MATCH_CALL          0x1D9

#define FLAG_UNUSED_0x1DA                    0x1DA // Unused Flag

#define FLAG_SHOWN_MYSTIC_TICKET             0x1DB
#define FLAG_DEFEATED_HO_OH                  0x1DC
#define FLAG_DEFEATED_LUGIA                  0x1DD

#define FLAG_UNUSED_0x1DE                    0x1DE // Unused Flag
#define FLAG_UNUSED_0x1DF                    0x1DF // Unused Flag
#define FLAG_UNUSED_0x1E0                    0x1E0 // Unused Flag
#define FLAG_UNUSED_0x1E1                    0x1E1 // Unused Flag
#define FLAG_UNUSED_0x1E2                    0x1E2 // Unused Flag
#define FLAG_UNUSED_0x1E3                    0x1E3 // Unused Flag

// Mystery Gift Flags (Unknown)
#define FLAG_MYSTERY_GIFT_DONE               0x1E4
#define FLAG_MYSTERY_GIFT_1                  0x1E5
#define FLAG_MYSTERY_GIFT_2                  0x1E6
#define FLAG_MYSTERY_GIFT_3                  0x1E7
#define FLAG_MYSTERY_GIFT_4                  0x1E8
#define FLAG_MYSTERY_GIFT_5                  0x1E9
#define FLAG_MYSTERY_GIFT_6                  0x1EA
#define FLAG_MYSTERY_GIFT_7                  0x1EB
#define FLAG_MYSTERY_GIFT_8                  0x1EC
#define FLAG_MYSTERY_GIFT_9                  0x1ED
#define FLAG_MYSTERY_GIFT_10                 0x1EE
#define FLAG_MYSTERY_GIFT_11                 0x1EF
#define FLAG_MYSTERY_GIFT_12                 0x1F0
#define FLAG_MYSTERY_GIFT_13                 0x1F1
#define FLAG_MYSTERY_GIFT_14                 0x1F2
#define FLAG_MYSTERY_GIFT_15                 0x1F3

// Hidden Items
#define FLAG_HIDDEN_ITEMS_START                                                         0x1F4
#define FLAG_HIDDEN_ITEM_LAVARIDGE_TOWN_ICE_HEAL             (FLAG_HIDDEN_ITEMS_START + 0x00)
#define FLAG_HIDDEN_ITEM_TRICK_HOUSE_NUGGET                  (FLAG_HIDDEN_ITEMS_START + 0x01)
#define FLAG_HIDDEN_ITEM_ROUTE_111_STARDUST                  (FLAG_HIDDEN_ITEMS_START + 0x02)
#define FLAG_HIDDEN_ITEM_ROUTE_113_ETHER                     (FLAG_HIDDEN_ITEMS_START + 0x03)
#define FLAG_HIDDEN_ITEM_ROUTE_114_CARBOS                    (FLAG_HIDDEN_ITEMS_START + 0x04)
#define FLAG_HIDDEN_ITEM_ROUTE_119_CALCIUM                   (FLAG_HIDDEN_ITEMS_START + 0x05)
#define FLAG_HIDDEN_ITEM_ROUTE_119_ULTRA_BALL                (FLAG_HIDDEN_ITEMS_START + 0x06)
#define FLAG_HIDDEN_ITEM_ROUTE_123_SUPER_REPEL               (FLAG_HIDDEN_ITEMS_START + 0x07)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_CARBOS               (FLAG_HIDDEN_ITEMS_START + 0x08)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_GREEN_SHARD          (FLAG_HIDDEN_ITEMS_START + 0x09)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_PEARL                (FLAG_HIDDEN_ITEMS_START + 0x0A)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_BIG_PEARL            (FLAG_HIDDEN_ITEMS_START + 0x0B)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_BLUE_SHARD           (FLAG_HIDDEN_ITEMS_START + 0x0C)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_HEART_SCALE_1        (FLAG_HIDDEN_ITEMS_START + 0x0D)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_HEART_SCALE          (FLAG_HIDDEN_ITEMS_START + 0x0E)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_ULTRA_BALL           (FLAG_HIDDEN_ITEMS_START + 0x0F)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_STARDUST             (FLAG_HIDDEN_ITEMS_START + 0x10)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_PEARL                (FLAG_HIDDEN_ITEMS_START + 0x11)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_YELLOW_SHARD         (FLAG_HIDDEN_ITEMS_START + 0x12)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_IRON                 (FLAG_HIDDEN_ITEMS_START + 0x13)
#define FLAG_HIDDEN_ITEM_UNDERWATER_126_BIG_PEARL            (FLAG_HIDDEN_ITEMS_START + 0x14)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_STAR_PIECE           (FLAG_HIDDEN_ITEMS_START + 0x15)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_HP_UP                (FLAG_HIDDEN_ITEMS_START + 0x16)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_HEART_SCALE          (FLAG_HIDDEN_ITEMS_START + 0x17)
#define FLAG_HIDDEN_ITEM_UNDERWATER_127_RED_SHARD            (FLAG_HIDDEN_ITEMS_START + 0x18)
#define FLAG_HIDDEN_ITEM_UNDERWATER_128_PROTEIN              (FLAG_HIDDEN_ITEMS_START + 0x19)
#define FLAG_HIDDEN_ITEM_UNDERWATER_128_PEARL                (FLAG_HIDDEN_ITEMS_START + 0x1A)
#define FLAG_HIDDEN_ITEM_LILYCOVE_CITY_HEART_SCALE           (FLAG_HIDDEN_ITEMS_START + 0x1B)
#define FLAG_HIDDEN_ITEM_FALLARBOR_TOWN_NUGGET               (FLAG_HIDDEN_ITEMS_START + 0x1C)
#define FLAG_HIDDEN_ITEM_MT_PYRE_EXTERIOR_ULTRA_BALL         (FLAG_HIDDEN_ITEMS_START + 0x1D)
#define FLAG_HIDDEN_ITEM_ROUTE_113_TM32                      (FLAG_HIDDEN_ITEMS_START + 0x1E)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_1_KEY             (FLAG_HIDDEN_ITEMS_START + 0x1F)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_2_KEY             (FLAG_HIDDEN_ITEMS_START + 0x20)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_4_KEY             (FLAG_HIDDEN_ITEMS_START + 0x21)
#define FLAG_HIDDEN_ITEM_ABANDONED_SHIP_RM_6_KEY             (FLAG_HIDDEN_ITEMS_START + 0x22)
#define FLAG_HIDDEN_ITEM_SS_TIDAL_LOWER_DECK_LEFTOVERS       (FLAG_HIDDEN_ITEMS_START + 0x23)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_CALCIUM              (FLAG_HIDDEN_ITEMS_START + 0x24)
#define FLAG_HIDDEN_ITEM_ROUTE_104_POTION                    (FLAG_HIDDEN_ITEMS_START + 0x25)
#define FLAG_HIDDEN_ITEM_UNDERWATER_124_HEART_SCALE_2        (FLAG_HIDDEN_ITEMS_START + 0x26)
#define FLAG_HIDDEN_ITEM_ROUTE_121_HP_UP                     (FLAG_HIDDEN_ITEMS_START + 0x27)
#define FLAG_HIDDEN_ITEM_ROUTE_121_NUGGET                    (FLAG_HIDDEN_ITEMS_START + 0x28)
#define FLAG_HIDDEN_ITEM_ROUTE_123_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x29)
#define FLAG_HIDDEN_ITEM_ROUTE_114_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x2A)
#define FLAG_HIDDEN_ITEM_LILYCOVE_CITY_PP_UP                 (FLAG_HIDDEN_ITEMS_START + 0x2B)
#define FLAG_HIDDEN_ITEM_ROUTE_104_SUPER_POTION              (FLAG_HIDDEN_ITEMS_START + 0x2C)
#define FLAG_HIDDEN_ITEM_ROUTE_116_SUPER_POTION              (FLAG_HIDDEN_ITEMS_START + 0x2D)
#define FLAG_HIDDEN_ITEM_ROUTE_106_STARDUST                  (FLAG_HIDDEN_ITEMS_START + 0x2E)
#define FLAG_HIDDEN_ITEM_ROUTE_106_HEART_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x2F)
#define FLAG_HIDDEN_ITEM_GRANITE_CAVE_B2F_EVERSTONE_1        (FLAG_HIDDEN_ITEMS_START + 0x30)
#define FLAG_HIDDEN_ITEM_GRANITE_CAVE_B2F_EVERSTONE_2        (FLAG_HIDDEN_ITEMS_START + 0x31)
#define FLAG_HIDDEN_ITEM_ROUTE_109_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x32)
#define FLAG_HIDDEN_ITEM_ROUTE_109_GREAT_BALL                (FLAG_HIDDEN_ITEMS_START + 0x33)
#define FLAG_HIDDEN_ITEM_ROUTE_109_HEART_SCALE_1             (FLAG_HIDDEN_ITEMS_START + 0x34)
#define FLAG_HIDDEN_ITEM_ROUTE_110_GREAT_BALL                (FLAG_HIDDEN_ITEMS_START + 0x35)
#define FLAG_HIDDEN_ITEM_ROUTE_110_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x36)
#define FLAG_HIDDEN_ITEM_ROUTE_110_FULL_HEAL                 (FLAG_HIDDEN_ITEMS_START + 0x37)
#define FLAG_HIDDEN_ITEM_ROUTE_111_PROTEIN                   (FLAG_HIDDEN_ITEMS_START + 0x38)
#define FLAG_HIDDEN_ITEM_ROUTE_111_RARE_CANDY                (FLAG_HIDDEN_ITEMS_START + 0x39)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_POTION              (FLAG_HIDDEN_ITEMS_START + 0x3A)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_TINY_MUSHROOM_1     (FLAG_HIDDEN_ITEMS_START + 0x3B)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_TINY_MUSHROOM_2     (FLAG_HIDDEN_ITEMS_START + 0x3C)
#define FLAG_HIDDEN_ITEM_PETALBURG_WOODS_POKE_BALL           (FLAG_HIDDEN_ITEMS_START + 0x3D)
#define FLAG_HIDDEN_ITEM_ROUTE_104_POKE_BALL                 (FLAG_HIDDEN_ITEMS_START + 0x3E)
#define FLAG_HIDDEN_ITEM_ROUTE_106_POKE_BALL                 (FLAG_HIDDEN_ITEMS_START + 0x3F)
#define FLAG_HIDDEN_ITEM_ROUTE_109_ETHER                     (FLAG_HIDDEN_ITEMS_START + 0x40)
#define FLAG_HIDDEN_ITEM_ROUTE_110_POKE_BALL                 (FLAG_HIDDEN_ITEMS_START + 0x41)
#define FLAG_HIDDEN_ITEM_ROUTE_118_HEART_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x42)
#define FLAG_HIDDEN_ITEM_ROUTE_118_IRON                      (FLAG_HIDDEN_ITEMS_START + 0x43)
#define FLAG_HIDDEN_ITEM_ROUTE_119_FULL_HEAL                 (FLAG_HIDDEN_ITEMS_START + 0x44)
#define FLAG_HIDDEN_ITEM_ROUTE_120_RARE_CANDY_2              (FLAG_HIDDEN_ITEMS_START + 0x45)
#define FLAG_HIDDEN_ITEM_ROUTE_120_ZINC                      (FLAG_HIDDEN_ITEMS_START + 0x46)
#define FLAG_HIDDEN_ITEM_ROUTE_120_RARE_CANDY_1              (FLAG_HIDDEN_ITEMS_START + 0x47)
#define FLAG_HIDDEN_ITEM_ROUTE_117_REPEL                     (FLAG_HIDDEN_ITEMS_START + 0x48)
#define FLAG_HIDDEN_ITEM_ROUTE_121_FULL_HEAL                 (FLAG_HIDDEN_ITEMS_START + 0x49)
#define FLAG_HIDDEN_ITEM_ROUTE_123_HYPER_POTION              (FLAG_HIDDEN_ITEMS_START + 0x4A)
#define FLAG_HIDDEN_ITEM_LILYCOVE_CITY_POKE_BALL             (FLAG_HIDDEN_ITEMS_START + 0x4B)
#define FLAG_HIDDEN_ITEM_JAGGED_PASS_GREAT_BALL              (FLAG_HIDDEN_ITEMS_START + 0x4C)
#define FLAG_HIDDEN_ITEM_JAGGED_PASS_FULL_HEAL               (FLAG_HIDDEN_ITEMS_START + 0x4D)
#define FLAG_HIDDEN_ITEM_MT_PYRE_EXTERIOR_MAX_ETHER          (FLAG_HIDDEN_ITEMS_START + 0x4E)
#define FLAG_HIDDEN_ITEM_MT_PYRE_SUMMIT_ZINC                 (FLAG_HIDDEN_ITEMS_START + 0x4F)
#define FLAG_HIDDEN_ITEM_MT_PYRE_SUMMIT_RARE_CANDY           (FLAG_HIDDEN_ITEMS_START + 0x50)
#define FLAG_HIDDEN_ITEM_VICTORY_ROAD_1F_ULTRA_BALL          (FLAG_HIDDEN_ITEMS_START + 0x51)
#define FLAG_HIDDEN_ITEM_VICTORY_ROAD_B2F_ELIXIR             (FLAG_HIDDEN_ITEMS_START + 0x52)
#define FLAG_HIDDEN_ITEM_VICTORY_ROAD_B2F_MAX_REPEL          (FLAG_HIDDEN_ITEMS_START + 0x53)
#define FLAG_HIDDEN_ITEM_ROUTE_120_REVIVE                    (FLAG_HIDDEN_ITEMS_START + 0x54)
#define FLAG_HIDDEN_ITEM_ROUTE_104_ANTIDOTE                  (FLAG_HIDDEN_ITEMS_START + 0x55)
#define FLAG_HIDDEN_ITEM_ROUTE_108_RARE_CANDY                (FLAG_HIDDEN_ITEMS_START + 0x56)
#define FLAG_HIDDEN_ITEM_ROUTE_119_MAX_ETHER                 (FLAG_HIDDEN_ITEMS_START + 0x57)
#define FLAG_HIDDEN_ITEM_ROUTE_104_HEART_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x58)
#define FLAG_HIDDEN_ITEM_ROUTE_105_HEART_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x59)
#define FLAG_HIDDEN_ITEM_ROUTE_109_HEART_SCALE_2             (FLAG_HIDDEN_ITEMS_START + 0x5A)
#define FLAG_HIDDEN_ITEM_ROUTE_109_HEART_SCALE_3             (FLAG_HIDDEN_ITEMS_START + 0x5B)
#define FLAG_HIDDEN_ITEM_ROUTE_128_HEART_SCALE_1             (FLAG_HIDDEN_ITEMS_START + 0x5C)
#define FLAG_HIDDEN_ITEM_ROUTE_128_HEART_SCALE_2             (FLAG_HIDDEN_ITEMS_START + 0x5D)
#define FLAG_HIDDEN_ITEM_ROUTE_128_HEART_SCALE_3             (FLAG_HIDDEN_ITEMS_START + 0x5E)
#define FLAG_HIDDEN_ITEM_PETALBURG_CITY_RARE_CANDY           (FLAG_HIDDEN_ITEMS_START + 0x5F)
#define FLAG_HIDDEN_ITEM_ROUTE_116_BLACK_GLASSES             (FLAG_HIDDEN_ITEMS_START + 0x60)
#define FLAG_HIDDEN_ITEM_ROUTE_115_HEART_SCALE               (FLAG_HIDDEN_ITEMS_START + 0x61)
#define FLAG_HIDDEN_ITEM_ROUTE_113_NUGGET                    (FLAG_HIDDEN_ITEMS_START + 0x62)
#define FLAG_HIDDEN_ITEM_ROUTE_123_PP_UP                     (FLAG_HIDDEN_ITEMS_START + 0x63)
#define FLAG_HIDDEN_ITEM_ROUTE_121_MAX_REVIVE                (FLAG_HIDDEN_ITEMS_START + 0x64)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_CALCIUM            (FLAG_HIDDEN_ITEMS_START + 0x65)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_ZINC               (FLAG_HIDDEN_ITEMS_START + 0x66)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_PROTEIN            (FLAG_HIDDEN_ITEMS_START + 0x67)
#define FLAG_HIDDEN_ITEM_ARTISAN_CAVE_B1F_IRON               (FLAG_HIDDEN_ITEMS_START + 0x68)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_SOUTH_EAST_FULL_RESTORE (FLAG_HIDDEN_ITEMS_START + 0x69)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_NORTH_EAST_RARE_CANDY   (FLAG_HIDDEN_ITEMS_START + 0x6A)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_NORTH_EAST_ZINC         (FLAG_HIDDEN_ITEMS_START + 0x6B)
#define FLAG_HIDDEN_ITEM_SAFARI_ZONE_SOUTH_EAST_PP_UP        (FLAG_HIDDEN_ITEMS_START + 0x6C)
#define FLAG_HIDDEN_ITEM_NAVEL_ROCK_TOP_SACRED_ASH           (FLAG_HIDDEN_ITEMS_START + 0x6D)
#define FLAG_HIDDEN_ITEM_ROUTE_123_RARE_CANDY                (FLAG_HIDDEN_ITEMS_START + 0x6E)
#define FLAG_HIDDEN_ITEM_ROUTE_105_BIG_PEARL                 (FLAG_HIDDEN_ITEMS_START + 0x6F)

#define FLAG_UNUSED_0x264  0x264 // Unused Flag
#define FLAG_UNUSED_0x265  0x265 // Unused Flag
#define FLAG_UNUSED_0x266  0x266 // Unused Flag
#define FLAG_UNUSED_0x267  0x267 // Unused Flag
#define FLAG_UNUSED_0x268  0x268 // Unused Flag
#define FLAG_UNUSED_0x269  0x269 // Unused Flag
#define FLAG_UNUSED_0x26A  0x26A // Unused Flag
#define FLAG_UNUSED_0x26B  0x26B // Unused Flag
#define FLAG_UNUSED_0x26C  0x26C // Unused Flag
#define FLAG_UNUSED_0x26D  0x26D // Unused Flag
#define FLAG_UNUSED_0x26E  0x26E // Unused Flag
#define FLAG_UNUSED_0x26F  0x26F // Unused Flag
#define FLAG_UNUSED_0x270  0x270 // Unused Flag
#define FLAG_UNUSED_0x271  0x271 // Unused Flag
#define FLAG_UNUSED_0x272  0x272 // Unused Flag
#define FLAG_UNUSED_0x273  0x273 // Unused Flag
#define FLAG_UNUSED_0x274  0x274 // Unused Flag
#define FLAG_UNUSED_0x275  0x275 // Unused Flag
#define FLAG_UNUSED_0x276  0x276 // Unused Flag
#define FLAG_UNUSED_0x277  0x277 // Unused Flag
#define FLAG_UNUSED_0x278  0x278 // Unused Flag
#define FLAG_UNUSED_0x279  0x279 // Unused Flag
#define FLAG_UNUSED_0x27A  0x27A // Unused Flag
#define FLAG_UNUSED_0x27B  0x27B // Unused Flag
#define FLAG_UNUSED_0x27C  0x27C // Unused Flag
#define FLAG_UNUSED_0x27D  0x27D // Unused Flag
#define FLAG_UNUSED_0x27E  0x27E // Unused Flag
#define FLAG_UNUSED_0x27F  0x27F // Unused Flag
#define FLAG_UNUSED_0x280  0x280 // Unused Flag
#define FLAG_UNUSED_0x281  0x281 // Unused Flag
#define FLAG_UNUSED_0x282  0x282 // Unused Flag
#define FLAG_UNUSED_0x283  0x283 // Unused Flag
#define FLAG_UNUSED_0x284  0x284 // Unused Flag
#define FLAG_UNUSED_0x285  0x285 // Unused Flag
#define FLAG_UNUSED_0x286  0x286 // Unused Flag
#define FLAG_UNUSED_0x287  0x287 // Unused Flag
#define FLAG_UNUSED_0x288  0x288 // Unused Flag
#define FLAG_UNUSED_0x289  0x289 // Unused Flag
#define FLAG_UNUSED_0x28A  0x28A // Unused Flag
#define FLAG_UNUSED_0x28B  0x28B // Unused Flag
#define FLAG_UNUSED_0x28C  0x28C // Unused Flag
#define FLAG_UNUSED_0x28D  0x28D // Unused Flag
#define FLAG_UNUSED_0x28E  0x28E // Unused Flag
#define FLAG_UNUSED_0x28F  0x28F // Unused Flag
#define FLAG_UNUSED_0x290  0x290 // Unused Flag
#define FLAG_UNUSED_0x291  0x291 // Unused Flag
#define FLAG_UNUSED_0x292  0x292 // Unused Flag
#define FLAG_UNUSED_0x293  0x293 // Unused Flag
#define FLAG_UNUSED_0x294  0x294 // Unused Flag
#define FLAG_UNUSED_0x295  0x295 // Unused Flag
#define FLAG_UNUSED_0x296  0x296 // Unused Flag
#define FLAG_UNUSED_0x297  0x297 // Unused Flag
#define FLAG_UNUSED_0x298  0x298 // Unused Flag
#define FLAG_UNUSED_0x299  0x299 // Unused Flag
#define FLAG_UNUSED_0x29A  0x29A // Unused Flag
#define FLAG_UNUSED_0x29B  0x29B // Unused Flag
#define FLAG_UNUSED_0x29C  0x29C // Unused Flag
#define FLAG_UNUSED_0x29D  0x29D // Unused Flag
#define FLAG_UNUSED_0x29E  0x29E // Unused Flag
#define FLAG_UNUSED_0x29F  0x29F // Unused Flag
#define FLAG_UNUSED_0x2A0  0x2A0 // Unused Flag
#define FLAG_UNUSED_0x2A1  0x2A1 // Unused Flag
#define FLAG_UNUSED_0x2A2  0x2A2 // Unused Flag
#define FLAG_UNUSED_0x2A3  0x2A3 // Unused Flag
#define FLAG_UNUSED_0x2A4  0x2A4 // Unused Flag
#define FLAG_UNUSED_0x2A5  0x2A5 // Unused Flag
#define FLAG_UNUSED_0x2A6  0x2A6 // Unused Flag
#define FLAG_UNUSED_0x2A7  0x2A7 // Unused Flag
#define FLAG_UNUSED_0x2A8  0x2A8 // Unused Flag
#define FLAG_UNUSED_0x2A9  0x2A9 // Unused Flag
#define FLAG_UNUSED_0x2AA  0x2AA // Unused Flag
#define FLAG_UNUSED_0x2AB  0x2AB // Unused Flag
#define FLAG_UNUSED_0x2AC  0x2AC // Unused Flag
#define FLAG_UNUSED_0x2AD  0x2AD // Unused Flag
#define FLAG_UNUSED_0x2AE  0x2AE // Unused Flag
#define FLAG_UNUSED_0x2AF  0x2AF // Unused Flag
#define FLAG_UNUSED_0x2B0  0x2B0 // Unused Flag
#define FLAG_UNUSED_0x2B1  0x2B1 // Unused Flag
#define FLAG_UNUSED_0x2B2  0x2B2 // Unused Flag
#define FLAG_UNUSED_0x2B3  0x2B3 // Unused Flag
#define FLAG_UNUSED_0x2B4  0x2B4 // Unused Flag
#define FLAG_UNUSED_0x2B5  0x2B5 // Unused Flag
#define FLAG_UNUSED_0x2B6  0x2B6 // Unused Flag
#define FLAG_UNUSED_0x2B7  0x2B7 // Unused Flag
#define FLAG_UNUSED_0x2B8  0x2B8 // Unused Flag
#define FLAG_UNUSED_0x2B9  0x2B9 // Unused Flag
#define FLAG_UNUSED_0x2BA  0x2BA // Unused Flag
#define FLAG_UNUSED_0x2BB  0x2BB // Unused Flag

// Event Flags
#define FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG                      0x2BC
#define FLAG_HIDE_APPRENTICE                                        0x2BD
#define FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN                0x2BE
#define FLAG_HIDE_UNION_ROOM_PLAYER_1                               0x2BF
#define FLAG_HIDE_UNION_ROOM_PLAYER_2                               0x2C0
#define FLAG_HIDE_UNION_ROOM_PLAYER_3                               0x2C1
#define FLAG_HIDE_UNION_ROOM_PLAYER_4                               0x2C2
#define FLAG_HIDE_UNION_ROOM_PLAYER_5                               0x2C3
#define FLAG_HIDE_UNION_ROOM_PLAYER_6                               0x2C4
#define FLAG_HIDE_UNION_ROOM_PLAYER_7                               0x2C5
#define FLAG_HIDE_UNION_ROOM_PLAYER_8                               0x2C6
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1               0x2C7
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2               0x2C8
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3               0x2C9
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4               0x2CA
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5               0x2CB
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6               0x2CC
#define FLAG_HIDE_SAFARI_ZONE_SOUTH_CONSTRUCTION_WORKERS            0x2CD
#define FLAG_HIDE_MEW                                               0x2CE
#define FLAG_HIDE_ROUTE_104_RIVAL                                   0x2CF
#define FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE                  0x2D0
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH                  0x2D1
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM          0x2D2
#define FLAG_HIDE_ROUTE_103_RIVAL                                   0x2D3
#define FLAG_HIDE_PETALBURG_WOODS_DEVON_EMPLOYEE                    0x2D4
#define FLAG_HIDE_PETALBURG_WOODS_AQUA_GRUNT                        0x2D5
#define FLAG_HIDE_PETALBURG_CITY_WALLY                              0x2D6
#define FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_INVISIBLE_NINJA_BOY   0x2D7
#define FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM                         0x2D8

#define FLAG_UNUSED_0x2D9                                           0x2D9 // Unused Flag

#define FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER                     0x2DA
#define FLAG_HIDE_RUSTBORO_CITY_AQUA_GRUNT                          0x2DB
#define FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1                    0x2DC
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE_ASLEEP              0x2DD
#define FLAG_HIDE_PLAYERS_HOUSE_DAD                                 0x2DE
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING      0x2DF
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING          0x2E0
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE             0x2E1
#define FLAG_HIDE_ROUTE_104_MR_BRINEY                               0x2E2
#define FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY                           0x2E3
#define FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN                            0x2E4
#define FLAG_HIDE_ROUTE_109_MR_BRINEY                               0x2E5
#define FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT                          0x2E6
#define FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN                       0x2E7
#define FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT                          0x2E8
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN            0x2E9
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY                    0x2EA
#define FLAG_HIDE_SAFARI_ZONE_SOUTH_EAST_EXPANSION                  0x2EB
#define FLAG_HIDE_LILYCOVE_HARBOR_EVENT_TICKET_TAKER                0x2EC
#define FLAG_HIDE_SLATEPORT_CITY_SCOTT                              0x2ED
#define FLAG_HIDE_ROUTE_101_ZIGZAGOON                               0x2EE
#define FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY                           0x2EF
#define FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE                       0x2F0
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN              0x2F1
#define FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1          0x2F2
#define FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2          0x2F3
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA          0x2F4
#define FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_BEDROOM_MOM               0x2F5
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM                0x2F6
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM                    0x2F7
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM      0x2F8
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK              0x2F9
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK                  0x2FA
#define FLAG_HIDE_DEOXYS                                            0x2FB
#define FLAG_HIDE_BIRTH_ISLAND_DEOXYS_TRIANGLE                      0x2FC
#define FLAG_HIDE_MAUVILLE_CITY_SCOTT                               0x2FD
#define FLAG_HIDE_VERDANTURF_TOWN_SCOTT                             0x2FE
#define FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT                  0x2FF
#define FLAG_HIDE_ROUTE_111_VICTOR_WINSTRATE                        0x300
#define FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE                      0x301
#define FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE                          0x302
#define FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE                         0x303
#define FLAG_HIDE_PETALBURG_GYM_NORMAN                              0x304
#define FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA                           0x305
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_1         0x306
#define FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR                           0x307
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_1                          0x308
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_2                          0x309
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_3                          0x30A
#define FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_4                          0x30B
#define FLAG_HIDE_LILYCOVE_MUSEUM_TOURISTS                          0x30C
#define FLAG_HIDE_PETALBURG_GYM_GREETER                             0x30D
#define FLAG_HIDE_MARINE_CAVE_KYOGRE                                0x30E
#define FLAG_HIDE_TERRA_CAVE_GROUDON                                0x30F
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM          0x310
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM              0x311
#define FLAG_HIDE_ROUTE_119_SCOTT                                   0x312
#define FLAG_HIDE_LILYCOVE_MOTEL_SCOTT                              0x313
#define FLAG_HIDE_MOSSDEEP_CITY_SCOTT                               0x314
#define FLAG_HIDE_FANCLUB_OLD_LADY                                  0x315
#define FLAG_HIDE_FANCLUB_BOY                                       0x316
#define FLAG_HIDE_FANCLUB_LITTLE_BOY                                0x317
#define FLAG_HIDE_FANCLUB_LADY                                      0x318
#define FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT               0x319
#define FLAG_HIDE_LITTLEROOT_TOWN_RIVAL                             0x31A
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCH                             0x31B
#define FLAG_HIDE_ROUTE_111_GABBY_AND_TY_1                          0x31C
#define FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1                          0x31D
#define FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1                          0x31E
#define FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3                          0x31F
#define FLAG_HIDE_LUGIA                                             0x320
#define FLAG_HIDE_HO_OH                                             0x321
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER                    0x322
#define FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER                   0x323
#define FLAG_HIDE_MAUVILLE_CITY_WALLY                               0x324
#define FLAG_HIDE_MAUVILLE_CITY_WALLYS_UNCLE                        0x325
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY                0x326
#define FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND                   0x327
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDAS_BOYFRIEND     0x328
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE         0x329
#define FLAG_HIDE_SS_TIDAL_CORRIDOR_SCOTT                           0x32A
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CYNDAQUIL     0x32B
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_TOTODILE      0x32C
#define FLAG_HIDE_ROUTE_116_DROPPED_GLASSES_MAN                     0x32D
#define FLAG_HIDE_RUSTBORO_CITY_RIVAL                               0x32E
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL     0x32F
#define FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE                           0x330
#define FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL       0x331
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL           0x332
#define FLAG_HIDE_ROUTE_112_TEAM_MAGMA                              0x333
#define FLAG_HIDE_CAVE_OF_ORIGIN_B1F_WALLACE                        0x334
#define FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE         0x335
#define FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE         0x336
#define FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA                          0x337
#define FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD                          0x338
#define FLAG_HIDE_LEGEND_MON_CAVE_OF_ORIGIN                         0x339 // Unused, leftover from R/S
#define FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE                            0x33A
#define FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE                             0x33B
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE                     0x33C
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE                      0x33D
#define FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD                         0x33E
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS               0x33F
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER                0x340
#define FLAG_HIDE_GRANITE_CAVE_STEVEN                               0x341
#define FLAG_HIDE_ROUTE_128_STEVEN                                  0x342
#define FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY                       0x343
#define FLAG_HIDE_BATTLE_FRONTIER_RECEPTION_GATE_SCOTT              0x344
#define FLAG_HIDE_ROUTE_110_BIRCH                                   0x345
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CHIKORITA     0x346
#define FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1                             0x347
#define FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN                      0x348
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN               0x349
#define FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO                         0x34A
#define FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY                      0x34B
#define FLAG_HIDE_RUSTBORO_CITY_SCIENTIST                           0x34C
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT                  0x34D
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE                      0x34E
#define FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD                           0x34F
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW            0x350
#define FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL          0x351
#define FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON_ASLEEP                   0x352
#define FLAG_HIDE_ROUTE_119_RIVAL                                   0x353
#define FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS                         0x354
#define FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON                          0x355
#define FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS                         0x356
#define FLAG_HIDE_SKY_PILLAR_WALLACE                                0x357
#define FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE                              0x358
#define FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS                              0x359
#define FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY                       0x35A
#define FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE                     0x35B
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL                    0x35C
#define FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL                           0x35D
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA          0x35E
#define FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN              0x35F
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1           0x360
#define FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2           0x361
#define FLAG_HIDE_PETALBURG_GYM_WALLY                               0x362
#define FLAG_UNKNOWN_0x363                                          0x363 // Set, however has no purpose.
#define FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN                           0x364
#define FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY          0x365
#define FLAG_HIDE_LANETTES_HOUSE_LANETTE                            0x366
#define FLAG_HIDE_FALLORBOR_POKEMON_CENTER_LANETTE                  0x367
#define FLAG_HIDE_TRICK_HOUSE_ENTRANCE_MAN                          0x368
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_REPLACEMENT    0x369
#define FLAG_HIDE_DESERT_UNDERPASS_FOSSIL                           0x36A
#define FLAG_HIDE_ROUTE_111_PLAYER_DESCENT                          0x36B
#define FLAG_HIDE_ROUTE_111_DESERT_FOSSIL                           0x36C
#define FLAG_HIDE_MT_CHIMNEY_TRAINERS                               0x36D
#define FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT                         0x36E
#define FLAG_HIDE_RUSTURF_TUNNEL_BRINEY                             0x36F
#define FLAG_HIDE_RUSTURF_TUNNEL_PEEKO                              0x370
#define FLAG_HIDE_BRINEYS_HOUSE_PEEKO                               0x371
#define FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA                          0x372
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS         0x373
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_1     0x374
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_2     0x375
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_ARCHIE           0x376
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_CAPTAIN_STERN    0x377
#define FLAG_HIDE_BATTLE_TOWER_OPPONENT                             0x378
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL                  0x379
#define FLAG_HIDE_ROUTE_119_TEAM_AQUA                               0x37A
#define FLAG_HIDE_ROUTE_116_MR_BRINEY                               0x37B
#define FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS                      0x37C
#define FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS                      0x37D
#define FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND                        0x37E
#define FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_2         0x37F
#define FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380          0x380
#define FLAG_HIDE_ROUTE_101_BIRCH                                   0x381
#define FLAG_HIDE_ROUTE_103_BIRCH                                   0x382
#define FLAG_HIDE_TRICK_HOUSE_END_MAN                               0x383
#define FLAG_HIDE_ROUTE_110_TEAM_AQUA                               0x384
#define FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2                          0x385
#define FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2                          0x386
#define FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2                          0x387
#define FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3                          0x388
#define FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS                     0x389
#define FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST                      0x38A
#define FLAG_HIDE_FALLARBOR_AZURILL                                 0x38B
#define FLAG_HIDE_LILYCOVE_HARBOR_FERRY_ATTENDANT                   0x38C
#define FLAG_HIDE_LILYCOVE_HARBOR_FERRY_SAILOR                      0x38D
#define FLAG_HIDE_SOUTHERN_ISLAND_EON_STONE                         0x38E
#define FLAG_HIDE_SOUTHERN_ISLAND_UNCHOSEN_EON_DUO_MON              0x38F
#define FLAG_HIDE_MAUVILLE_CITY_WATTSON                             0x390
#define FLAG_HIDE_MAUVILLE_GYM_WATTSON                              0x391
#define FLAG_HIDE_ROUTE_121_TEAM_AQUA_GRUNTS                        0x392
#define FLAG_UNKNOWN_0x393                                          0x393 // Set, however has no purpose.
#define FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE                             0x394
#define FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA                          0x395
#define FLAG_HIDE_BATTLE_TOWER_REPORTER                             0x396
#define FLAG_HIDE_ROUTE_110_RIVAL                                   0x397
#define FLAG_HIDE_CHAMPIONS_ROOM_RIVAL                              0x398
#define FLAG_HIDE_CHAMPIONS_ROOM_BIRCH                              0x399
#define FLAG_HIDE_ROUTE_110_RIVAL_ON_BIKE                           0x39A
#define FLAG_HIDE_ROUTE_119_RIVAL_ON_BIKE                           0x39B
#define FLAG_HIDE_AQUA_HIDEOUT_GRUNTS                               0x39C
#define FLAG_HIDE_LILYCOVE_MOTEL_GAME_DESIGNERS                     0x39D
#define FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA                              0x39E
#define FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA                             0x39F
#define FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO                        0x3A0
#define FLAG_HIDE_LAVARIDGE_TOWN_RIVAL                              0x3A1
#define FLAG_HIDE_LAVARIDGE_TOWN_RIVAL_ON_BIKE                      0x3A2
#define FLAG_HIDE_RUSTURF_TUNNEL_ROCK_1                             0x3A3
#define FLAG_HIDE_RUSTURF_TUNNEL_ROCK_2                             0x3A4
#define FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL                      0x3A5
#define FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL                     0x3A6
#define FLAG_HIDE_REGIROCK                                          0x3A7
#define FLAG_HIDE_REGICE                                            0x3A8
#define FLAG_HIDE_REGISTEEL                                         0x3A9
#define FLAG_HIDE_METEOR_FALLS_TEAM_AQUA                            0x3AA
#define FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA                           0x3AB
#define FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN                      0x3AC
#define FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT               0x3AD
#define FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO                          0x3AE
#define FLAG_HIDE_AQUA_HIDEOUT_B2F_SUBMARINE_SHADOW                 0x3AF
#define FLAG_HIDE_ROUTE_128_ARCHIE                                  0x3B0
#define FLAG_HIDE_ROUTE_128_MAXIE                                   0x3B1
#define FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS                       0x3B2
#define FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE                          0x3B3
#define FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN                        0x3B4
#define FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE              0x3B5
#define FLAG_HIDE_SS_TIDAL_CORRIDOR_MR_BRINEY                       0x3B6
#define FLAG_HIDE_SS_TIDAL_ROOMS_SNATCH_GIVER                       0x3B7
#define FLAG_RECEIVED_SHOAL_SALT_1                                  0x3B8
#define FLAG_RECEIVED_SHOAL_SALT_2                                  0x3B9
#define FLAG_RECEIVED_SHOAL_SALT_3                                  0x3BA
#define FLAG_RECEIVED_SHOAL_SALT_4                                  0x3BB
#define FLAG_RECEIVED_SHOAL_SHELL_1                                 0x3BC
#define FLAG_RECEIVED_SHOAL_SHELL_2                                 0x3BD
#define FLAG_RECEIVED_SHOAL_SHELL_3                                 0x3BE
#define FLAG_RECEIVED_SHOAL_SHELL_4                                 0x3BF
#define FLAG_HIDE_ROUTE_111_SECRET_POWER_MAN                        0x3C0
#define FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION                       0x3C1
#define FLAG_HIDE_LILYCOVE_DEPARTMENT_STORE_ROOFTOP_SALE_WOMAN      0x3C2
#define FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL                          0x3C3
#define FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL                          0x3C4
#define FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT 0x3C5
#define FLAG_HIDE_ROUTE_118_STEVEN                                  0x3C6
#define FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN                0x3C7
#define FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL       0x3C8
#define FLAG_HIDE_FORTREE_CITY_KECLEON                              0x3C9
#define FLAG_HIDE_ROUTE_120_KECLEON_BRIDGE                          0x3CA
#define FLAG_HIDE_LILYCOVE_CITY_RIVAL                               0x3CB
#define FLAG_HIDE_ROUTE_120_STEVEN                                  0x3CC
#define FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN                            0x3CD
#define FLAG_HIDE_NEW_MAUVILLE_VOLTORB_1                            0x3CE
#define FLAG_HIDE_NEW_MAUVILLE_VOLTORB_2                            0x3CF
#define FLAG_HIDE_NEW_MAUVILLE_VOLTORB_3                            0x3D0
#define FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1                      0x3D1
#define FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2                      0x3D2
#define FLAG_HIDE_OLDALE_TOWN_RIVAL                                 0x3D3
#define FLAG_HIDE_UNDERWATER_SEA_FLOOR_CAVERN_STOLEN_SUBMARINE      0x3D4
#define FLAG_HIDE_ROUTE_120_KECLEON_BRIDGE_SHADOW                   0x3D5
#define FLAG_HIDE_ROUTE_120_KECLEON_1                               0x3D6
#define FLAG_HIDE_RUSTURF_TUNNEL_WANDA                              0x3D7
#define FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDA                0x3D8
#define FLAG_HIDE_ROUTE_120_KECLEON_2                               0x3D9
#define FLAG_HIDE_ROUTE_120_KECLEON_3                               0x3DA
#define FLAG_HIDE_ROUTE_120_KECLEON_4                               0x3DB
#define FLAG_HIDE_ROUTE_120_KECLEON_5                               0x3DC
#define FLAG_HIDE_ROUTE_119_KECLEON_1                               0x3DD
#define FLAG_HIDE_ROUTE_119_KECLEON_2                               0x3DE
#define FLAG_HIDE_ROUTE_101_BOY                                     0x3DF
#define FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M                 0x3E0
#define FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON          0x3E1
#define FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY                       0x3E2
#define FLAG_HIDE_PETALBURG_CITY_SCOTT                              0x3E3
#define FLAG_HIDE_SOOTOPOLIS_CITY_RAYQUAZA                          0x3E4
#define FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE                            0x3E5
#define FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON                           0x3E6
#define FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT                0x3E7

// Item Ball Flags
#define FLAG_ITEM_ROUTE_102_POTION                                  0x3E8
#define FLAG_ITEM_ROUTE_116_X_SPECIAL                               0x3E9
#define FLAG_ITEM_ROUTE_104_PP_UP                                   0x3EA
#define FLAG_ITEM_ROUTE_105_IRON                                    0x3EB
#define FLAG_ITEM_ROUTE_106_PROTEIN                                 0x3EC
#define FLAG_ITEM_ROUTE_109_PP_UP                                   0x3ED
#define FLAG_ITEM_ROUTE_110_RARE_CANDY                              0x3EE
#define FLAG_ITEM_ROUTE_110_DIRE_HIT                                0x3EF
#define FLAG_ITEM_ROUTE_111_TM37                                    0x3F0
#define FLAG_ITEM_ROUTE_111_STARDUST                                0x3F1
#define FLAG_ITEM_ROUTE_111_HP_UP                                   0x3F2
#define FLAG_ITEM_ROUTE_112_NUGGET                                  0x3F3
#define FLAG_ITEM_ROUTE_113_MAX_ETHER                               0x3F4
#define FLAG_ITEM_ROUTE_113_SUPER_REPEL                             0x3F5
#define FLAG_ITEM_ROUTE_114_RARE_CANDY                              0x3F6
#define FLAG_ITEM_ROUTE_114_PROTEIN                                 0x3F7
#define FLAG_ITEM_ROUTE_115_SUPER_POTION                            0x3F8
#define FLAG_ITEM_ROUTE_115_TM01                                    0x3F9
#define FLAG_ITEM_ROUTE_115_IRON                                    0x3FA
#define FLAG_ITEM_ROUTE_116_ETHER                                   0x3FB
#define FLAG_ITEM_ROUTE_116_REPEL                                   0x3FC
#define FLAG_ITEM_ROUTE_116_HP_UP                                   0x3FD
#define FLAG_ITEM_ROUTE_117_GREAT_BALL                              0x3FE
#define FLAG_ITEM_ROUTE_117_REVIVE                                  0x3FF
#define FLAG_ITEM_ROUTE_119_SUPER_REPEL                             0x400
#define FLAG_ITEM_ROUTE_119_ZINC                                    0x401
#define FLAG_ITEM_ROUTE_119_ELIXIR_1                                0x402
#define FLAG_ITEM_ROUTE_119_LEAF_STONE                              0x403
#define FLAG_ITEM_ROUTE_119_RARE_CANDY                              0x404
#define FLAG_ITEM_ROUTE_119_HYPER_POTION_1                          0x405
#define FLAG_ITEM_ROUTE_120_NUGGET                                  0x406
#define FLAG_ITEM_ROUTE_120_FULL_HEAL                               0x407
#define FLAG_ITEM_ROUTE_123_CALCIUM                                 0x408
#define FLAG_ITEM_ROUTE_123_RARE_CANDY                              0x409 // Unused Flag, leftover from R/S. In Emerald this is a hidden item and uses a different flag
#define FLAG_ITEM_ROUTE_127_ZINC                                    0x40A
#define FLAG_ITEM_ROUTE_127_CARBOS                                  0x40B
#define FLAG_ITEM_ROUTE_132_RARE_CANDY                              0x40C
#define FLAG_ITEM_ROUTE_133_BIG_PEARL                               0x40D
#define FLAG_ITEM_ROUTE_133_STAR_PIECE                              0x40E
#define FLAG_ITEM_PETALBURG_CITY_MAX_REVIVE                         0x40F
#define FLAG_ITEM_PETALBURG_CITY_ETHER                              0x410
#define FLAG_ITEM_RUSTBORO_CITY_X_DEFEND                            0x411
#define FLAG_ITEM_LILYCOVE_CITY_MAX_REPEL                           0x412
#define FLAG_ITEM_MOSSDEEP_CITY_NET_BALL                            0x413
#define FLAG_ITEM_METEOR_FALLS_1F_1R_TM23                           0x414
#define FLAG_ITEM_METEOR_FALLS_1F_1R_FULL_HEAL                      0x415
#define FLAG_ITEM_METEOR_FALLS_1F_1R_MOON_STONE                     0x416
#define FLAG_ITEM_METEOR_FALLS_1F_1R_PP_UP                          0x417
#define FLAG_ITEM_RUSTURF_TUNNEL_POKE_BALL                          0x418
#define FLAG_ITEM_RUSTURF_TUNNEL_MAX_ETHER                          0x419
#define FLAG_ITEM_GRANITE_CAVE_1F_ESCAPE_ROPE                       0x41A
#define FLAG_ITEM_GRANITE_CAVE_B1F_POKE_BALL                        0x41B
#define FLAG_ITEM_MT_PYRE_5F_LAX_INCENSE                            0x41C
#define FLAG_ITEM_GRANITE_CAVE_B2F_REPEL                            0x41D
#define FLAG_ITEM_GRANITE_CAVE_B2F_RARE_CANDY                       0x41E
#define FLAG_ITEM_PETALBURG_WOODS_X_ATTACK                          0x41F
#define FLAG_ITEM_PETALBURG_WOODS_GREAT_BALL                        0x420
#define FLAG_ITEM_ROUTE_104_POKE_BALL                               0x421
#define FLAG_ITEM_PETALBURG_WOODS_ETHER                             0x422
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_3R_ECAPE_ROPE                    0x423
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_1_ORANGE_MAIL                  0x424
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_HARBOR_MAIL                  0x425
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_2_WAVE_MAIL                    0x426
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_SHADOW_MAIL                  0x427
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_3_WOOD_MAIL                    0x428
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_4_MECH_MAIL                    0x429
#define FLAG_ITEM_ROUTE_124_YELLOW_SHARD                            0x42A
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_6_GLITTER_MAIL                 0x42B
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_7_TROPIC_MAIL                  0x42C
#define FLAG_ITEM_TRICK_HOUSE_PUZZLE_8_BEAD_MAIL                    0x42D
#define FLAG_ITEM_JAGGED_PASS_BURN_HEAL                             0x42E
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_MAX_ELIXIR                       0x42F
#define FLAG_ITEM_AQUA_HIDEOUT_B2F_NEST_BALL                        0x430
#define FLAG_ITEM_MT_PYRE_EXTERIOR_MAX_POTION                       0x431
#define FLAG_ITEM_MT_PYRE_EXTERIOR_TM48                             0x432
#define FLAG_ITEM_NEW_MAUVILLE_ULTRA_BALL                           0x433
#define FLAG_ITEM_NEW_MAUVILLE_ESCAPE_ROPE                          0x434
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_6_LUXURY_BALL    0x435
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_2_SCANNER        0x436
#define FLAG_ITEM_SCORCHED_SLAB_TM11                                0x437
#define FLAG_ITEM_METEOR_FALLS_B1F_2R_TM02                          0x438
#define FLAG_ITEM_SHOAL_CAVE_ENTRANCE_BIG_PEARL                     0x439
#define FLAG_ITEM_SHOAL_CAVE_INNER_ROOM_RARE_CANDY                  0x43A
#define FLAG_ITEM_SHOAL_CAVE_STAIRS_ROOM_ICE_HEAL                   0x43B
#define FLAG_ITEM_VICTORY_ROAD_1F_MAX_ELIXIR                        0x43C
#define FLAG_ITEM_VICTORY_ROAD_1F_PP_UP                             0x43D
#define FLAG_ITEM_VICTORY_ROAD_B1F_TM29                             0x43E
#define FLAG_ITEM_VICTORY_ROAD_B1F_FULL_RESTORE                     0x43F
#define FLAG_ITEM_VICTORY_ROAD_B2F_FULL_HEAL                        0x440
#define FLAG_ITEM_MT_PYRE_6F_TM30                                   0x441
#define FLAG_ITEM_SEAFLOOR_CAVERN_ROOM_9_TM26                       0x442
#define FLAG_ITEM_FIERY_PATH_TM06                                   0x443
#define FLAG_ITEM_ROUTE_124_RED_SHARD                               0x444
#define FLAG_ITEM_ROUTE_124_BLUE_SHARD                              0x445
#define FLAG_ITEM_SAFARI_ZONE_NORTH_WEST_TM22                       0x446
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_1F_HARBOR_MAIL               0x447
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_ESCAPE_ROPE              0x448
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_B1F_DIVE_BALL              0x449
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_B1F_TM13                     0x44A
#define FLAG_ITEM_ABANDONED_SHIP_ROOMS_2_1F_REVIVE                  0x44B
#define FLAG_ITEM_ABANDONED_SHIP_CAPTAINS_OFFICE_STORAGE_KEY        0x44C
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_3_WATER_STONE    0x44D
#define FLAG_ITEM_ABANDONED_SHIP_HIDDEN_FLOOR_ROOM_1_TM18           0x44E
#define FLAG_ITEM_ROUTE_121_CARBOS                                  0x44F
#define FLAG_ITEM_ROUTE_123_ULTRA_BALL                              0x450
#define FLAG_ITEM_ROUTE_126_GREEN_SHARD                             0x451
#define FLAG_ITEM_ROUTE_119_HYPER_POTION_2                          0x452
#define FLAG_ITEM_ROUTE_120_HYPER_POTION                            0x453
#define FLAG_ITEM_ROUTE_120_NEST_BALL                               0x454
#define FLAG_ITEM_ROUTE_123_ELIXIR                                  0x455
#define FLAG_ITEM_NEW_MAUVILLE_THUNDER_STONE                        0x456
#define FLAG_ITEM_FIERY_PATH_FIRE_STONE                             0x457
#define FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_TM07                          0x458
#define FLAG_ITEM_SHOAL_CAVE_ICE_ROOM_NEVER_MELT_ICE                0x459
#define FLAG_ITEM_ROUTE_103_GUARD_SPEC                              0x45A
#define FLAG_ITEM_ROUTE_104_X_ACCURACY                              0x45B
#define FLAG_ITEM_MAUVILLE_CITY_X_SPEED                             0x45C
#define FLAG_ITEM_PETALBURG_WOODS_PARALYZE_HEAL                     0x45D
#define FLAG_ITEM_ROUTE_115_GREAT_BALL                              0x45E
#define FLAG_ITEM_SAFARI_ZONE_NORTH_CALCIUM                         0x45F
#define FLAG_ITEM_MT_PYRE_3F_SUPER_REPEL                            0x460
#define FLAG_ITEM_ROUTE_118_HYPER_POTION                            0x461
#define FLAG_ITEM_NEW_MAUVILLE_FULL_HEAL                            0x462
#define FLAG_ITEM_NEW_MAUVILLE_PARALYZE_HEAL                        0x463
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_MASTER_BALL                      0x464
#define FLAG_ITEM_OLD_MAGMA_HIDEOUT_B1F_MASTER_BALL                 0x465 // Unused Flag, leftover from the Ruby Magma hideout
#define FLAG_ITEM_OLD_MAGMA_HIDEOUT_B1F_MAX_ELIXIR                  0x466 // Unused Flag, leftover from the Ruby Magma hideout
#define FLAG_ITEM_OLD_MAGMA_HIDEOUT_B2F_NEST_BALL                   0x467 // Unused Flag, leftover from the Ruby Magma hideout
#define FLAG_UNUSED_0x468                                           0x468 // Unused Flag
#define FLAG_ITEM_MT_PYRE_2F_ULTRA_BALL                             0x469
#define FLAG_ITEM_MT_PYRE_4F_SEA_INCENSE                            0x46A
#define FLAG_ITEM_SAFARI_ZONE_SOUTH_WEST_MAX_REVIVE                 0x46B
#define FLAG_ITEM_AQUA_HIDEOUT_B1F_NUGGET                           0x46C
#define FLAG_ITEM_MOSSDEEP_STEVENS_HOUSE_HM08                       0x46D // Unused Flag, leftover from R/S. HM08 is given to the player directly in Emerald
#define FLAG_ITEM_ROUTE_119_NUGGET                                  0x46E
#define FLAG_ITEM_ROUTE_104_POTION                                  0x46F
#define FLAG_UNUSED_0x470                                           0x470 // Unused Flag
#define FLAG_ITEM_ROUTE_103_PP_UP                                   0x471
#define FLAG_UNUSED_0x472                                           0x472 // Unused Flag
#define FLAG_ITEM_ROUTE_108_STAR_PIECE                              0x473
#define FLAG_ITEM_ROUTE_109_POTION                                  0x474
#define FLAG_ITEM_ROUTE_110_ELIXIR                                  0x475
#define FLAG_ITEM_ROUTE_111_ELIXIR                                  0x476
#define FLAG_ITEM_ROUTE_113_HYPER_POTION                            0x477
#define FLAG_ITEM_ROUTE_115_HEAL_POWDER                             0x478
#define FLAG_UNUSED_0x479                                           0x479 // Unused Flag
#define FLAG_ITEM_ROUTE_116_POTION                                  0x47A
#define FLAG_ITEM_ROUTE_119_ELIXIR_2                                0x47B
#define FLAG_ITEM_ROUTE_120_REVIVE                                  0x47C
#define FLAG_ITEM_ROUTE_121_REVIVE                                  0x47D
#define FLAG_ITEM_ROUTE_121_ZINC                                    0x47E
#define FLAG_ITEM_MAGMA_HIDEOUT_1F_RARE_CANDY                       0x47F
#define FLAG_ITEM_ROUTE_123_PP_UP                                   0x480
#define FLAG_ITEM_ROUTE_123_REVIVAL_HERB                            0x481
#define FLAG_ITEM_ROUTE_125_BIG_PEARL                               0x482
#define FLAG_ITEM_ROUTE_127_RARE_CANDY                              0x483
#define FLAG_ITEM_ROUTE_132_PROTEIN                                 0x484
#define FLAG_ITEM_ROUTE_133_MAX_REVIVE                              0x485
#define FLAG_ITEM_ROUTE_134_CARBOS                                  0x486
#define FLAG_ITEM_ROUTE_134_STAR_PIECE                              0x487
#define FLAG_ITEM_ROUTE_114_ENERGY_POWDER                           0x488
#define FLAG_ITEM_ROUTE_115_PP_UP                                   0x489
#define FLAG_ITEM_ARTISAN_CAVE_B1F_HP_UP                            0x48A
#define FLAG_ITEM_ARTISAN_CAVE_1F_CARBOS                            0x48B
#define FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_MAX_ELIXIR                    0x48C
#define FLAG_ITEM_MAGMA_HIDEOUT_2F_2R_FULL_RESTORE                  0x48D
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_1R_NUGGET                        0x48E
#define FLAG_ITEM_MAGMA_HIDEOUT_3F_2R_PP_MAX                        0x48F
#define FLAG_ITEM_MAGMA_HIDEOUT_4F_MAX_REVIVE                       0x490
#define FLAG_ITEM_SAFARI_ZONE_NORTH_EAST_NUGGET                     0x491
#define FLAG_ITEM_SAFARI_ZONE_SOUTH_EAST_BIG_PEARL                  0x492

#define FLAG_UNUSED_0x493                                           0x493 // Unused Flag
#define FLAG_UNUSED_0x494                                           0x494 // Unused Flag
#define FLAG_UNUSED_0x495                                           0x495 // Unused Flag
#define FLAG_UNUSED_0x496                                           0x496 // Unused Flag
#define FLAG_UNUSED_0x497                                           0x497 // Unused Flag
#define FLAG_UNUSED_0x498                                           0x498 // Unused Flag
#define FLAG_UNUSED_0x499                                           0x499 // Unused Flag
#define FLAG_UNUSED_0x49A                                           0x49A // Unused Flag
#define FLAG_UNUSED_0x49B                                           0x49B // Unused Flag
#define FLAG_UNUSED_0x49C                                           0x49C // Unused Flag
#define FLAG_UNUSED_0x49D                                           0x49D // Unused Flag
#define FLAG_UNUSED_0x49E                                           0x49E // Unused Flag
#define FLAG_UNUSED_0x49F                                           0x49F // Unused Flag
#define FLAG_UNUSED_0x4A0                                           0x4A0 // Unused Flag
#define FLAG_UNUSED_0x4A1                                           0x4A1 // Unused Flag
#define FLAG_UNUSED_0x4A2                                           0x4A2 // Unused Flag
#define FLAG_UNUSED_0x4A3                                           0x4A3 // Unused Flag
#define FLAG_UNUSED_0x4A4                                           0x4A4 // Unused Flag
#define FLAG_UNUSED_0x4A5                                           0x4A5 // Unused Flag
#define FLAG_UNUSED_0x4A6                                           0x4A6 // Unused Flag
#define FLAG_UNUSED_0x4A7                                           0x4A7 // Unused Flag
#define FLAG_UNUSED_0x4A8                                           0x4A8 // Unused Flag
#define FLAG_UNUSED_0x4A9                                           0x4A9 // Unused Flag
#define FLAG_UNUSED_0x4AA                                           0x4AA // Unused Flag
#define FLAG_UNUSED_0x4AB                                           0x4AB // Unused Flag
#define FLAG_UNUSED_0x4AC                                           0x4AC // Unused Flag
#define FLAG_UNUSED_0x4AD                                           0x4AD // Unused Flag
#define FLAG_UNUSED_0x4AE                                           0x4AE // Unused Flag
#define FLAG_UNUSED_0x4AF                                           0x4AF // Unused Flag
#define FLAG_UNUSED_0x4B0                                           0x4B0 // Unused Flag
#define FLAG_UNUSED_0x4B1                                           0x4B1 // Unused Flag
#define FLAG_UNUSED_0x4B2                                           0x4B2 // Unused Flag
#define FLAG_UNUSED_0x4B3                                           0x4B3 // Unused Flag
#define FLAG_UNUSED_0x4B4                                           0x4B4 // Unused Flag
#define FLAG_UNUSED_0x4B5                                           0x4B5 // Unused Flag
#define FLAG_UNUSED_0x4B6                                           0x4B6 // Unused Flag
#define FLAG_UNUSED_0x4B7                                           0x4B7 // Unused Flag
#define FLAG_UNUSED_0x4B8                                           0x4B8 // Unused Flag
#define FLAG_UNUSED_0x4B9                                           0x4B9 // Unused Flag
#define FLAG_UNUSED_0x4BA                                           0x4BA // Unused Flag
#define FLAG_UNUSED_0x4BB                                           0x4BB // Unused Flag
#define FLAG_UNUSED_0x4BC                                           0x4BC // Unused Flag
#define FLAG_UNUSED_0x4BD                                           0x4BD // Unused Flag
#define FLAG_UNUSED_0x4BE                                           0x4BE // Unused Flag
#define FLAG_UNUSED_0x4BF                                           0x4BF // Unused Flag
#define FLAG_UNUSED_0x4C0                                           0x4C0 // Unused Flag
#define FLAG_UNUSED_0x4C1                                           0x4C1 // Unused Flag
#define FLAG_UNUSED_0x4C2                                           0x4C2 // Unused Flag
#define FLAG_UNUSED_0x4C3                                           0x4C3 // Unused Flag
#define FLAG_UNUSED_0x4C4                                           0x4C4 // Unused Flag
#define FLAG_UNUSED_0x4C5                                           0x4C5 // Unused Flag
#define FLAG_UNUSED_0x4C6                                           0x4C6 // Unused Flag
#define FLAG_UNUSED_0x4C7                                           0x4C7 // Unused Flag
#define FLAG_UNUSED_0x4C8                                           0x4C8 // Unused Flag
#define FLAG_UNUSED_0x4C9                                           0x4C9 // Unused Flag
#define FLAG_UNUSED_0x4CA                                           0x4CA // Unused Flag
#define FLAG_UNUSED_0x4CB                                           0x4CB // Unused Flag
#define FLAG_UNUSED_0x4CC                                           0x4CC // Unused Flag
#define FLAG_UNUSED_0x4CD                                           0x4CD // Unused Flag
#define FLAG_UNUSED_0x4CE                                           0x4CE // Unused Flag
#define FLAG_UNUSED_0x4CF                                           0x4CF // Unused Flag
#define FLAG_UNUSED_0x4D0                                           0x4D0 // Unused Flag
#define FLAG_UNUSED_0x4D1                                           0x4D1 // Unused Flag
#define FLAG_UNUSED_0x4D2                                           0x4D2 // Unused Flag
#define FLAG_UNUSED_0x4D3                                           0x4D3 // Unused Flag
#define FLAG_UNUSED_0x4D4                                           0x4D4 // Unused Flag
#define FLAG_UNUSED_0x4D5                                           0x4D5 // Unused Flag
#define FLAG_UNUSED_0x4D6                                           0x4D6 // Unused Flag
#define FLAG_UNUSED_0x4D7                                           0x4D7 // Unused Flag
#define FLAG_UNUSED_0x4D8                                           0x4D8 // Unused Flag
#define FLAG_UNUSED_0x4D9                                           0x4D9 // Unused Flag
#define FLAG_UNUSED_0x4DA                                           0x4DA // Unused Flag
#define FLAG_UNUSED_0x4DB                                           0x4DB // Unused Flag
#define FLAG_UNUSED_0x4DC                                           0x4DC // Unused Flag
#define FLAG_UNUSED_0x4DD                                           0x4DD // Unused Flag
#define FLAG_UNUSED_0x4DE                                           0x4DE // Unused Flag
#define FLAG_UNUSED_0x4DF                                           0x4DF // Unused Flag
#define FLAG_UNUSED_0x4E0                                           0x4E0 // Unused Flag
#define FLAG_UNUSED_0x4E1                                           0x4E1 // Unused Flag
#define FLAG_UNUSED_0x4E2                                           0x4E2 // Unused Flag
#define FLAG_UNUSED_0x4E3                                           0x4E3 // Unused Flag
#define FLAG_UNUSED_0x4E4                                           0x4E4 // Unused Flag
#define FLAG_UNUSED_0x4E5                                           0x4E5 // Unused Flag
#define FLAG_UNUSED_0x4E6                                           0x4E6 // Unused Flag
#define FLAG_UNUSED_0x4E7                                           0x4E7 // Unused Flag
#define FLAG_UNUSED_0x4E8                                           0x4E8 // Unused Flag
#define FLAG_UNUSED_0x4E9                                           0x4E9 // Unused Flag
#define FLAG_UNUSED_0x4EA                                           0x4EA // Unused Flag
#define FLAG_UNUSED_0x4EB                                           0x4EB // Unused Flag
#define FLAG_UNUSED_0x4EC                                           0x4EC // Unused Flag
#define FLAG_UNUSED_0x4ED                                           0x4ED // Unused Flag
#define FLAG_UNUSED_0x4EE                                           0x4EE // Unused Flag
#define FLAG_UNUSED_0x4EF                                           0x4EF // Unused Flag

#define FLAG_DEFEATED_RUSTBORO_GYM                                  0x4F0
#define FLAG_DEFEATED_DEWFORD_GYM                                   0x4F1
#define FLAG_DEFEATED_MAUVILLE_GYM                                  0x4F2
#define FLAG_DEFEATED_LAVARIDGE_GYM                                 0x4F3
#define FLAG_DEFEATED_PETALBURG_GYM                                 0x4F4
#define FLAG_DEFEATED_FORTREE_GYM                                   0x4F5
#define FLAG_DEFEATED_MOSSDEEP_GYM                                  0x4F6
#define FLAG_DEFEATED_SOOTOPOLIS_GYM                                0x4F7
#define FLAG_DEFEATED_METEOR_FALLS_STEVEN                           0x4F8

#define FLAG_UNUSED_0x4F9                                           0x4F9 // Unused Flag
#define FLAG_UNUSED_0x4FA                                           0x4FA // Unused Flag

#define FLAG_DEFEATED_ELITE_4_SIDNEY                                0x4FB
#define FLAG_DEFEATED_ELITE_4_PHOEBE                                0x4FC
#define FLAG_DEFEATED_ELITE_4_GLACIA                                0x4FD
#define FLAG_DEFEATED_ELITE_4_DRAKE                                 0x4FE

#define FLAG_UNUSED_0x4FF                                           0x4FF // Unused Flag

// Trainer Flags
// Trainer flags occupy 0x500 - 0x85F, the last 9 of which are unused
// See constants/opponents.h. The values there + FLAG_TRAINER_FLAG_START are the flag IDs

#define TRAINER_FLAGS_START                                         0x500
#define TRAINER_FLAGS_END                                           (TRAINER_FLAGS_START + MAX_TRAINERS_COUNT - 1) // 0x85F

// System Flags

#define SYSTEM_FLAGS                                   (TRAINER_FLAGS_END + 1) // 0x860

#define FLAG_SYS_POKEMON_GET                         (SYSTEM_FLAGS + 0x0) // FLAG_0x860
#define FLAG_SYS_POKEDEX_GET                         (SYSTEM_FLAGS + 0x1)
#define FLAG_SYS_POKENAV_GET                         (SYSTEM_FLAGS + 0x2)
#define FLAG_UNUSED_0x863                            (SYSTEM_FLAGS + 0x3) // Unused Flag
#define FLAG_SYS_GAME_CLEAR                          (SYSTEM_FLAGS + 0x4)
#define FLAG_SYS_CHAT_USED                           (SYSTEM_FLAGS + 0x5)
#define FLAG_UNLOCKED_TRENDY_SAYINGS                 (SYSTEM_FLAGS + 0x6)

// Badges
#define FLAG_BADGE01_GET                             (SYSTEM_FLAGS + 0x7)
#define FLAG_BADGE02_GET                             (SYSTEM_FLAGS + 0x8)
#define FLAG_BADGE03_GET                             (SYSTEM_FLAGS + 0x9)
#define FLAG_BADGE04_GET                             (SYSTEM_FLAGS + 0xA)
#define FLAG_BADGE05_GET                             (SYSTEM_FLAGS + 0xB)
#define FLAG_BADGE06_GET                             (SYSTEM_FLAGS + 0xC)
#define FLAG_BADGE07_GET                             (SYSTEM_FLAGS + 0xD)
#define FLAG_BADGE08_GET                             (SYSTEM_FLAGS + 0xE)
#define NUM_BADGES                                   (1 + FLAG_BADGE08_GET - FLAG_BADGE01_GET)

// Towns and Cities
#define FLAG_VISITED_LITTLEROOT_TOWN                (SYSTEM_FLAGS + 0xF)
#define FLAG_VISITED_OLDALE_TOWN                    (SYSTEM_FLAGS + 0x10)
#define FLAG_VISITED_DEWFORD_TOWN                   (SYSTEM_FLAGS + 0x11)
#define FLAG_VISITED_LAVARIDGE_TOWN                 (SYSTEM_FLAGS + 0x12)
#define FLAG_VISITED_FALLARBOR_TOWN                 (SYSTEM_FLAGS + 0x13)
#define FLAG_VISITED_VERDANTURF_TOWN                (SYSTEM_FLAGS + 0x14)
#define FLAG_VISITED_PACIFIDLOG_TOWN                (SYSTEM_FLAGS + 0x15)
#define FLAG_VISITED_PETALBURG_CITY                 (SYSTEM_FLAGS + 0x16)
#define FLAG_VISITED_SLATEPORT_CITY                 (SYSTEM_FLAGS + 0x17)
#define FLAG_VISITED_MAUVILLE_CITY                  (SYSTEM_FLAGS + 0x18)
#define FLAG_VISITED_RUSTBORO_CITY                  (SYSTEM_FLAGS + 0x19)
#define FLAG_VISITED_FORTREE_CITY                   (SYSTEM_FLAGS + 0x1A)
#define FLAG_VISITED_LILYCOVE_CITY                  (SYSTEM_FLAGS + 0x1B)
#define FLAG_VISITED_MOSSDEEP_CITY                  (SYSTEM_FLAGS + 0x1C)
#define FLAG_VISITED_SOOTOPOLIS_CITY                (SYSTEM_FLAGS + 0x1D)
#define FLAG_VISITED_EVER_GRANDE_CITY               (SYSTEM_FLAGS + 0x1E)

#define FLAG_IS_CHAMPION                            (SYSTEM_FLAGS + 0x1F) // Seems to be related to linking.
#define FLAG_NURSE_UNION_ROOM_REMINDER              (SYSTEM_FLAGS + 0x20)

#define FLAG_UNUSED_0x881                           (SYSTEM_FLAGS + 0x21) // Unused Flag
#define FLAG_UNUSED_0x882                           (SYSTEM_FLAGS + 0x22) // Unused Flag
#define FLAG_UNUSED_0x883                           (SYSTEM_FLAGS + 0x23) // Unused Flag
#define FLAG_UNUSED_0x884                           (SYSTEM_FLAGS + 0x24) // Unused Flag
#define FLAG_UNUSED_0x885                           (SYSTEM_FLAGS + 0x25) // Unused Flag
#define FLAG_UNUSED_0x886                           (SYSTEM_FLAGS + 0x26) // Unused Flag
#define FLAG_UNUSED_0x887                           (SYSTEM_FLAGS + 0x27) // Unused Flag

#define FLAG_SYS_USE_FLASH                          (SYSTEM_FLAGS + 0x28)
#define FLAG_SYS_USE_STRENGTH                       (SYSTEM_FLAGS + 0x29)
#define FLAG_SYS_WEATHER_CTRL                       (SYSTEM_FLAGS + 0x2A)
#define FLAG_SYS_CYCLING_ROAD                       (SYSTEM_FLAGS + 0x2B)
#define FLAG_SYS_SAFARI_MODE                        (SYSTEM_FLAGS + 0x2C)
#define FLAG_SYS_CRUISE_MODE                        (SYSTEM_FLAGS + 0x2D)

#define FLAG_UNUSED_0x88E                           (SYSTEM_FLAGS + 0x2E) // Unused Flag
#define FLAG_UNUSED_0x88F                           (SYSTEM_FLAGS + 0x2F) // Unused Flag

#define FLAG_SYS_TV_HOME                            (SYSTEM_FLAGS + 0x30)
#define FLAG_SYS_TV_WATCH                           (SYSTEM_FLAGS + 0x31)
#define FLAG_SYS_TV_START                           (SYSTEM_FLAGS + 0x32)
#define FLAG_SYS_CHANGED_DEWFORD_TREND              (SYSTEM_FLAGS + 0x33)
#define FLAG_SYS_MIX_RECORD                         (SYSTEM_FLAGS + 0x34)
#define FLAG_SYS_CLOCK_SET                          (SYSTEM_FLAGS + 0x35)
#define FLAG_SYS_NATIONAL_DEX                       (SYSTEM_FLAGS + 0x36)
#define FLAG_SYS_CAVE_SHIP                          (SYSTEM_FLAGS + 0x37) // Unused Flag, leftover from R/S debug, presumably used by Emerald's debug too
#define FLAG_SYS_CAVE_WONDER                        (SYSTEM_FLAGS + 0x38) // Unused Flag, same as above
#define FLAG_SYS_CAVE_BATTLE                        (SYSTEM_FLAGS + 0x39) // Unused Flag, same as above
#define FLAG_SYS_SHOAL_TIDE                         (SYSTEM_FLAGS + 0x3A)
#define FLAG_SYS_RIBBON_GET                         (SYSTEM_FLAGS + 0x3B)

#define FLAG_LANDMARK_FLOWER_SHOP                   (SYSTEM_FLAGS + 0x3C)
#define FLAG_LANDMARK_MR_BRINEY_HOUSE               (SYSTEM_FLAGS + 0x3D)
#define FLAG_LANDMARK_ABANDONED_SHIP                (SYSTEM_FLAGS + 0x3E)
#define FLAG_LANDMARK_SEASHORE_HOUSE                (SYSTEM_FLAGS + 0x3F)
#define FLAG_LANDMARK_NEW_MAUVILLE                  (SYSTEM_FLAGS + 0x40)
#define FLAG_LANDMARK_OLD_LADY_REST_SHOP            (SYSTEM_FLAGS + 0x41)
#define FLAG_LANDMARK_TRICK_HOUSE                   (SYSTEM_FLAGS + 0x42)
#define FLAG_LANDMARK_WINSTRATE_FAMILY              (SYSTEM_FLAGS + 0x43)
#define FLAG_LANDMARK_GLASS_WORKSHOP                (SYSTEM_FLAGS + 0x44)
#define FLAG_LANDMARK_LANETTES_HOUSE                (SYSTEM_FLAGS + 0x45)
#define FLAG_LANDMARK_POKEMON_DAYCARE               (SYSTEM_FLAGS + 0x46)
#define FLAG_LANDMARK_SEAFLOOR_CAVERN               (SYSTEM_FLAGS + 0x47)
#define FLAG_LANDMARK_BATTLE_FRONTIER               (SYSTEM_FLAGS + 0x48)
#define FLAG_LANDMARK_SOUTHERN_ISLAND               (SYSTEM_FLAGS + 0x49)
#define FLAG_LANDMARK_FIERY_PATH                    (SYSTEM_FLAGS + 0x4A)

#define FLAG_SYS_PC_LANETTE                         (SYSTEM_FLAGS + 0x4B)
#define FLAG_SYS_MYSTERY_EVENT_ENABLE               (SYSTEM_FLAGS + 0x4C)
#define FLAG_SYS_ENC_UP_ITEM                        (SYSTEM_FLAGS + 0x4D)
#define FLAG_SYS_ENC_DOWN_ITEM                      (SYSTEM_FLAGS + 0x4E)
#define FLAG_SYS_BRAILLE_DIG                        (SYSTEM_FLAGS + 0x4F)
#define FLAG_SYS_REGIROCK_PUZZLE_COMPLETED          (SYSTEM_FLAGS + 0x50)
#define FLAG_SYS_BRAILLE_REGICE_COMPLETED           (SYSTEM_FLAGS + 0x51)
#define FLAG_SYS_REGISTEEL_PUZZLE_COMPLETED         (SYSTEM_FLAGS + 0x52)
#define FLAG_ENABLE_SHIP_SOUTHERN_ISLAND            (SYSTEM_FLAGS + 0x53)

#define FLAG_LANDMARK_POKEMON_LEAGUE                (SYSTEM_FLAGS + 0x54)
#define FLAG_LANDMARK_ISLAND_CAVE                   (SYSTEM_FLAGS + 0x55)
#define FLAG_LANDMARK_DESERT_RUINS                  (SYSTEM_FLAGS + 0x56)
#define FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE          (SYSTEM_FLAGS + 0x57)
#define FLAG_LANDMARK_SCORCHED_SLAB                 (SYSTEM_FLAGS + 0x58)
#define FLAG_LANDMARK_ANCIENT_TOMB                  (SYSTEM_FLAGS + 0x59)
#define FLAG_LANDMARK_TUNNELERS_REST_HOUSE          (SYSTEM_FLAGS + 0x5A)
#define FLAG_LANDMARK_HUNTERS_HOUSE                 (SYSTEM_FLAGS + 0x5B)
#define FLAG_LANDMARK_SEALED_CHAMBER                (SYSTEM_FLAGS + 0x5C)

#define FLAG_SYS_TV_LATIAS_LATIOS                   (SYSTEM_FLAGS + 0x5D)

#define FLAG_LANDMARK_SKY_PILLAR                    (SYSTEM_FLAGS + 0x5E)

#define FLAG_SYS_SHOAL_ITEM                         (SYSTEM_FLAGS + 0x5F)
#define FLAG_SYS_B_DASH                             (SYSTEM_FLAGS + 0x60) // RECEIVED Running Shoes
#define FLAG_SYS_CTRL_OBJ_DELETE                    (SYSTEM_FLAGS + 0x61)
#define FLAG_SYS_RESET_RTC_ENABLE                   (SYSTEM_FLAGS + 0x62)

#define FLAG_LANDMARK_BERRY_MASTERS_HOUSE           (SYSTEM_FLAGS + 0x63)

#define FLAG_SYS_TOWER_SILVER                       (SYSTEM_FLAGS + 0x64)
#define FLAG_SYS_TOWER_GOLD                         (SYSTEM_FLAGS + 0x65)
#define FLAG_SYS_DOME_SILVER                        (SYSTEM_FLAGS + 0x66)
#define FLAG_SYS_DOME_GOLD                          (SYSTEM_FLAGS + 0x67)
#define FLAG_SYS_PALACE_SILVER                      (SYSTEM_FLAGS + 0x68)
#define FLAG_SYS_PALACE_GOLD                        (SYSTEM_FLAGS + 0x69)
#define FLAG_SYS_ARENA_SILVER                       (SYSTEM_FLAGS + 0x6A)
#define FLAG_SYS_ARENA_GOLD                         (SYSTEM_FLAGS + 0x6B)
#define FLAG_SYS_FACTORY_SILVER                     (SYSTEM_FLAGS + 0x6C)
#define FLAG_SYS_FACTORY_GOLD                       (SYSTEM_FLAGS + 0x6D)
#define FLAG_SYS_PIKE_SILVER                        (SYSTEM_FLAGS + 0x6E)
#define FLAG_SYS_PIKE_GOLD                          (SYSTEM_FLAGS + 0x6F)
#define FLAG_SYS_PYRAMID_SILVER                     (SYSTEM_FLAGS + 0x70)
#define FLAG_SYS_PYRAMID_GOLD                       (SYSTEM_FLAGS + 0x71)
#define FLAG_SYS_FRONTIER_PASS                      (SYSTEM_FLAGS + 0x72)

#define FLAG_MAP_SCRIPT_CHECKED_DEOXYS              (SYSTEM_FLAGS + 0x73)
#define FLAG_DEOXYS_ROCK_COMPLETE                   (SYSTEM_FLAGS + 0x74)
#define FLAG_ENABLE_SHIP_BIRTH_ISLAND               (SYSTEM_FLAGS + 0x75)
#define FLAG_ENABLE_SHIP_FARAWAY_ISLAND             (SYSTEM_FLAGS + 0x76)

#define FLAG_SHOWN_BOX_WAS_FULL_MESSAGE             (SYSTEM_FLAGS + 0x77)

#define FLAG_ARRIVED_ON_FARAWAY_ISLAND              (SYSTEM_FLAGS + 0x78)
#define FLAG_ARRIVED_AT_MARINE_CAVE_EMERGE_SPOT     (SYSTEM_FLAGS + 0x79)
#define FLAG_ARRIVED_AT_TERRA_CAVE_ENTRANCE         (SYSTEM_FLAGS + 0x7A)

#define FLAG_SYS_MYSTERY_GIFT_ENABLE                (SYSTEM_FLAGS + 0x7B)

#define FLAG_ENTERED_MIRAGE_TOWER                   (SYSTEM_FLAGS + 0x7C)
#define FLAG_LANDMARK_ALTERING_CAVE                 (SYSTEM_FLAGS + 0x7D)
#define FLAG_LANDMARK_DESERT_UNDERPASS              (SYSTEM_FLAGS + 0x7E)
#define FLAG_LANDMARK_ARTISAN_CAVE                  (SYSTEM_FLAGS + 0x7F)
#define FLAG_ENABLE_SHIP_NAVEL_ROCK                 (SYSTEM_FLAGS + 0x80)
#define FLAG_ARRIVED_AT_NAVEL_ROCK                  (SYSTEM_FLAGS + 0x81)
#define FLAG_LANDMARK_TRAINER_HILL                  (SYSTEM_FLAGS + 0x82)

#define FLAG_UNUSED_0x8E3                           (SYSTEM_FLAGS + 0x83) // Unused Flag

#define FLAG_RECEIVED_POKEDEX_FROM_BIRCH            (SYSTEM_FLAGS + 0x84)

#define FLAG_UNUSED_0x8E5                           (SYSTEM_FLAGS + 0x85) // Unused Flag
#define FLAG_UNUSED_0x8E6                           (SYSTEM_FLAGS + 0x86) // Unused Flag
#define FLAG_UNUSED_0x8E7                           (SYSTEM_FLAGS + 0x87) // Unused Flag
#define FLAG_UNUSED_0x8E8                           (SYSTEM_FLAGS + 0x88) // Unused Flag
#define FLAG_UNUSED_0x8E9                           (SYSTEM_FLAGS + 0x89) // Unused Flag
#define FLAG_UNUSED_0x8EA                           (SYSTEM_FLAGS + 0x8A) // Unused Flag
#define FLAG_UNUSED_0x8EB                           (SYSTEM_FLAGS + 0x8B) // Unused Flag
#define FLAG_UNUSED_0x8EC                           (SYSTEM_FLAGS + 0x8C) // Unused Flag
#define FLAG_UNUSED_0x8ED                           (SYSTEM_FLAGS + 0x8D) // Unused Flag
#define FLAG_UNUSED_0x8EE                           (SYSTEM_FLAGS + 0x8E) // Unused Flag
#define FLAG_UNUSED_0x8EF                           (SYSTEM_FLAGS + 0x8F) // Unused Flag
#define FLAG_UNUSED_0x8F0                           (SYSTEM_FLAGS + 0x90) // Unused Flag
#define FLAG_UNUSED_0x8F1                           (SYSTEM_FLAGS + 0x91) // Unused Flag
#define FLAG_UNUSED_0x8F2                           (SYSTEM_FLAGS + 0x92) // Unused Flag
#define FLAG_UNUSED_0x8F3                           (SYSTEM_FLAGS + 0x93) // Unused Flag
#define FLAG_UNUSED_0x8F4                           (SYSTEM_FLAGS + 0x94) // Unused Flag
#define FLAG_UNUSED_0x8F5                           (SYSTEM_FLAGS + 0x95) // Unused Flag
#define FLAG_UNUSED_0x8F6                           (SYSTEM_FLAGS + 0x96) // Unused Flag
#define FLAG_UNUSED_0x8F7                           (SYSTEM_FLAGS + 0x97) // Unused Flag
#define FLAG_UNUSED_0x8F8                           (SYSTEM_FLAGS + 0x98) // Unused Flag
#define FLAG_UNUSED_0x8F9                           (SYSTEM_FLAGS + 0x99) // Unused Flag
#define FLAG_UNUSED_0x8FA                           (SYSTEM_FLAGS + 0x9A) // Unused Flag
#define FLAG_UNUSED_0x8FB                           (SYSTEM_FLAGS + 0x9B) // Unused Flag
#define FLAG_UNUSED_0x8FC                           (SYSTEM_FLAGS + 0x9C) // Unused Flag
#define FLAG_UNUSED_0x8FD                           (SYSTEM_FLAGS + 0x9D) // Unused Flag
#define FLAG_UNUSED_0x8FE                           (SYSTEM_FLAGS + 0x9E) // Unused Flag
#define FLAG_UNUSED_0x8FF                           (SYSTEM_FLAGS + 0x9F) // Unused Flag
#define FLAG_UNUSED_0x900                           (SYSTEM_FLAGS + 0xA0) // Unused Flag
#define FLAG_UNUSED_0x901                           (SYSTEM_FLAGS + 0xA1) // Unused Flag
#define FLAG_UNUSED_0x902                           (SYSTEM_FLAGS + 0xA2) // Unused Flag
#define FLAG_UNUSED_0x903                           (SYSTEM_FLAGS + 0xA3) // Unused Flag
#define FLAG_UNUSED_0x904                           (SYSTEM_FLAGS + 0xA4) // Unused Flag
#define FLAG_UNUSED_0x905                           (SYSTEM_FLAGS + 0xA5) // Unused Flag
#define FLAG_UNUSED_0x906                           (SYSTEM_FLAGS + 0xA6) // Unused Flag
#define FLAG_UNUSED_0x907                           (SYSTEM_FLAGS + 0xA7) // Unused Flag
#define FLAG_UNUSED_0x908                           (SYSTEM_FLAGS + 0xA8) // Unused Flag
#define FLAG_UNUSED_0x909                           (SYSTEM_FLAGS + 0xA9) // Unused Flag
#define FLAG_UNUSED_0x90A                           (SYSTEM_FLAGS + 0xAA) // Unused Flag
#define FLAG_UNUSED_0x90B                           (SYSTEM_FLAGS + 0xAB) // Unused Flag
#define FLAG_UNUSED_0x90C                           (SYSTEM_FLAGS + 0xAC) // Unused Flag
#define FLAG_UNUSED_0x90D                           (SYSTEM_FLAGS + 0xAD) // Unused Flag
#define FLAG_UNUSED_0x90E                           (SYSTEM_FLAGS + 0xAE) // Unused Flag
#define FLAG_UNUSED_0x90F                           (SYSTEM_FLAGS + 0xAF) // Unused Flag
#define FLAG_UNUSED_0x910                           (SYSTEM_FLAGS + 0xB0) // Unused Flag
#define FLAG_UNUSED_0x911                           (SYSTEM_FLAGS + 0xB1) // Unused Flag
#define FLAG_UNUSED_0x912                           (SYSTEM_FLAGS + 0xB2) // Unused Flag
#define FLAG_UNUSED_0x913                           (SYSTEM_FLAGS + 0xB3) // Unused Flag
#define FLAG_UNUSED_0x914                           (SYSTEM_FLAGS + 0xB4) // Unused Flag
#define FLAG_UNUSED_0x915                           (SYSTEM_FLAGS + 0xB5) // Unused Flag
#define FLAG_UNUSED_0x916                           (SYSTEM_FLAGS + 0xB6) // Unused Flag
#define FLAG_UNUSED_0x917                           (SYSTEM_FLAGS + 0xB7) // Unused Flag
#define FLAG_UNUSED_0x918                           (SYSTEM_FLAGS + 0xB8) // Unused Flag
#define FLAG_UNUSED_0x919                           (SYSTEM_FLAGS + 0xB9) // Unused Flag
#define FLAG_UNUSED_0x91A                           (SYSTEM_FLAGS + 0xBA) // Unused Flag
#define FLAG_UNUSED_0x91B                           (SYSTEM_FLAGS + 0xBB) // Unused Flag
#define FLAG_UNUSED_0x91C                           (SYSTEM_FLAGS + 0xBC) // Unused Flag
#define FLAG_UNUSED_0x91D                           (SYSTEM_FLAGS + 0xBD) // Unused Flag
#define FLAG_UNUSED_0x91E                           (SYSTEM_FLAGS + 0xBE) // Unused Flag
#define FLAG_UNUSED_0x91F                           (SYSTEM_FLAGS + 0xBF) // Unused Flag

// Daily Flags
// These flags are cleared once per day
// The start and end are byte-aligned because the flags are cleared in byte increments
#define DAILY_FLAGS_START                           (FLAG_UNUSED_0x91F + (8 - FLAG_UNUSED_0x91F % 8))
#define FLAG_UNUSED_0x920                           (DAILY_FLAGS_START + 0x0)  // Unused Flag
#define FLAG_DAILY_CONTEST_LOBBY_RECEIVED_BERRY     (DAILY_FLAGS_START + 0x1)
#define FLAG_DAILY_SECRET_BASE                      (DAILY_FLAGS_START + 0x2)
#define FLAG_UNUSED_0x923                           (DAILY_FLAGS_START + 0x3)  // Unused Flag
#define FLAG_UNUSED_0x924                           (DAILY_FLAGS_START + 0x4)  // Unused Flag
#define FLAG_UNUSED_0x925                           (DAILY_FLAGS_START + 0x5)  // Unused Flag
#define FLAG_UNUSED_0x926                           (DAILY_FLAGS_START + 0x6)  // Unused Flag
#define FLAG_UNUSED_0x927                           (DAILY_FLAGS_START + 0x7)  // Unused Flag
#define FLAG_UNUSED_0x928                           (DAILY_FLAGS_START + 0x8)  // Unused Flag
#define FLAG_UNUSED_0x929                           (DAILY_FLAGS_START + 0x9)  // Unused Flag
#define FLAG_DAILY_PICKED_LOTO_TICKET               (DAILY_FLAGS_START + 0xA)
#define FLAG_DAILY_ROUTE_114_RECEIVED_BERRY         (DAILY_FLAGS_START + 0xB)
#define FLAG_DAILY_ROUTE_111_RECEIVED_BERRY         (DAILY_FLAGS_START + 0xC)
#define FLAG_DAILY_BERRY_MASTER_RECEIVED_BERRY      (DAILY_FLAGS_START + 0xD)
#define FLAG_DAILY_ROUTE_120_RECEIVED_BERRY         (DAILY_FLAGS_START + 0xE)
#define FLAG_DAILY_LILYCOVE_RECEIVED_BERRY          (DAILY_FLAGS_START + 0xF)
#define FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY       (DAILY_FLAGS_START + 0x10)
#define FLAG_DAILY_BERRY_MASTERS_WIFE               (DAILY_FLAGS_START + 0x11)
#define FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY        (DAILY_FLAGS_START + 0x12)
#define FLAG_UNUSED_0x933                           (DAILY_FLAGS_START + 0x13) // Unused Flag
#define FLAG_DAILY_APPRENTICE_LEAVES                (DAILY_FLAGS_START + 0x14)

#define FLAG_UNUSED_0x935                           (DAILY_FLAGS_START + 0x15) // Unused Flag
#define FLAG_UNUSED_0x936                           (DAILY_FLAGS_START + 0x16) // Unused Flag
#define FLAG_UNUSED_0x937                           (DAILY_FLAGS_START + 0x17) // Unused Flag
#define FLAG_UNUSED_0x938                           (DAILY_FLAGS_START + 0x18) // Unused Flag
#define FLAG_UNUSED_0x939                           (DAILY_FLAGS_START + 0x19) // Unused Flag
#define FLAG_UNUSED_0x93A                           (DAILY_FLAGS_START + 0x1A) // Unused Flag
#define FLAG_UNUSED_0x93B                           (DAILY_FLAGS_START + 0x1B) // Unused Flag
#define FLAG_UNUSED_0x93C                           (DAILY_FLAGS_START + 0x1C) // Unused Flag
#define FLAG_UNUSED_0x93D                           (DAILY_FLAGS_START + 0x1D) // Unused Flag
#define FLAG_UNUSED_0x93E                           (DAILY_FLAGS_START + 0x1E) // Unused Flag
#define FLAG_UNUSED_0x93F                           (DAILY_FLAGS_START + 0x1F) // Unused Flag
#define FLAG_UNUSED_0x940                           (DAILY_FLAGS_START + 0x20) // Unused Flag
#define FLAG_UNUSED_0x941                           (DAILY_FLAGS_START + 0x21) // Unused Flag
#define FLAG_UNUSED_0x942                           (DAILY_FLAGS_START + 0x22) // Unused Flag
#define FLAG_UNUSED_0x943                           (DAILY_FLAGS_START + 0x23) // Unused Flag
#define FLAG_UNUSED_0x944                           (DAILY_FLAGS_START + 0x24) // Unused Flag
#define FLAG_UNUSED_0x945                           (DAILY_FLAGS_START + 0x25) // Unused Flag
#define FLAG_UNUSED_0x946                           (DAILY_FLAGS_START + 0x26) // Unused Flag
#define FLAG_UNUSED_0x947                           (DAILY_FLAGS_START + 0x27) // Unused Flag
#define FLAG_UNUSED_0x948                           (DAILY_FLAGS_START + 0x28) // Unused Flag
#define FLAG_UNUSED_0x949                           (DAILY_FLAGS_START + 0x29) // Unused Flag
#define FLAG_UNUSED_0x94A                           (DAILY_FLAGS_START + 0x2A) // Unused Flag
#define FLAG_UNUSED_0x94B                           (DAILY_FLAGS_START + 0x2B) // Unused Flag
#define FLAG_UNUSED_0x94C                           (DAILY_FLAGS_START + 0x2C) // Unused Flag
#define FLAG_UNUSED_0x94D                           (DAILY_FLAGS_START + 0x2D) // Unused Flag
#define FLAG_UNUSED_0x94E                           (DAILY_FLAGS_START + 0x2E) // Unused Flag
#define FLAG_UNUSED_0x94F                           (DAILY_FLAGS_START + 0x2F) // Unused Flag
#define FLAG_UNUSED_0x950                           (DAILY_FLAGS_START + 0x30) // Unused Flag
#define FLAG_UNUSED_0x951                           (DAILY_FLAGS_START + 0x31) // Unused Flag
#define FLAG_UNUSED_0x952                           (DAILY_FLAGS_START + 0x32) // Unused Flag
#define FLAG_UNUSED_0x953                           (DAILY_FLAGS_START + 0x33) // Unused Flag
#define FLAG_UNUSED_0x954                           (DAILY_FLAGS_START + 0x34) // Unused Flag
#define FLAG_UNUSED_0x955                           (DAILY_FLAGS_START + 0x35) // Unused Flag
#define FLAG_UNUSED_0x956                           (DAILY_FLAGS_START + 0x36) // Unused Flag
#define FLAG_UNUSED_0x957                           (DAILY_FLAGS_START + 0x37) // Unused Flag
#define FLAG_UNUSED_0x958                           (DAILY_FLAGS_START + 0x38) // Unused Flag
#define FLAG_UNUSED_0x959                           (DAILY_FLAGS_START + 0x39) // Unused Flag
#define FLAG_UNUSED_0x95A                           (DAILY_FLAGS_START + 0x3A) // Unused Flag
#define FLAG_UNUSED_0x95B                           (DAILY_FLAGS_START + 0x3B) // Unused Flag
#define FLAG_UNUSED_0x95C                           (DAILY_FLAGS_START + 0x3C) // Unused Flag
#define FLAG_UNUSED_0x95D                           (DAILY_FLAGS_START + 0x3D) // Unused Flag
#define FLAG_UNUSED_0x95E                           (DAILY_FLAGS_START + 0x3E) // Unused Flag
#define FLAG_UNUSED_0x95F                           (DAILY_FLAGS_START + 0x3F) // Unused Flag
#define DAILY_FLAGS_END                             (FLAG_UNUSED_0x95F + (7 - FLAG_UNUSED_0x95F % 8))

#define FLAGS_COUNT (DAILY_FLAGS_END + 1)

// Special Flags (Stored in EWRAM (sSpecialFlags), not in the SaveBlock)
#define SPECIAL_FLAGS_START                     0x4000
#define FLAG_HIDE_MAP_NAME_POPUP                (SPECIAL_FLAGS_START + 0x0)
#define FLAG_DONT_TRANSITION_MUSIC              (SPECIAL_FLAGS_START + 0x1)
#define FLAG_ENABLE_MULTI_CORRIDOR_DOOR         (SPECIAL_FLAGS_START + 0x2)
#define FLAG_SPECIAL_FLAG_UNUSED_0x4003         (SPECIAL_FLAGS_START + 0x3) // Unused Flag
#define FLAG_STORING_ITEMS_IN_PYRAMID_BAG       (SPECIAL_FLAGS_START + 0x4)
// FLAG_SPECIAL_FLAG_0x4005 - 0x407F also exist and are unused
#define SPECIAL_FLAGS_END                       (SPECIAL_FLAGS_START + 0x7F)

#endif // GUARD_CONSTANTS_FLAGS_H
