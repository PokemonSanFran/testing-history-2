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

// Script Flags
// Trainer Rematch Flags
// Hidden Items
#define FLAG_HIDDEN_ITEMS_START                                                         0x1F4
#define FLAG_HIDDEN_ITEM_LAVARIDGE_TOWN_ICE_HEAL             (FLAG_HIDDEN_ITEMS_START + 0x00)
#define FLAG_HIDDEN_ITEM_ROUTE_105_BIG_PEARL                 (FLAG_HIDDEN_ITEMS_START + 0x6F)

//Event Flags

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
// Location Flags
#define FLAG_VISITED_LITTLEROOT_TOWN                (SYSTEM_FLAGS + 0xF)

// Daily Flags
// These flags are cleared once per day
// The start and end are byte-aligned because the flags are cleared in byte increments
#define DAILY_FLAGS_START                           (FLAG_UNUSED_0x91F + (8 - FLAG_UNUSED_0x91F % 8))
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

#define FLAG_SYS_NO_COLLISION	0x20	//DEBUG
#define FLAG_SYS_NO_ENCOUNTER	0x21	//DEBUG
#define FLAG_SYS_NO_TRAINER_SEE	0x22	//DEBUG
#define FLAG_SYS_NO_BAG_USE	0x23	//DEBUG
#define FLAG_SYS_NO_CATCHING	0x24	//DEBUG
#define FLAG_CHASECENTER_TOURNAMENT_HAPPENING	0x25
#define FLAG_SAVED_DAVID	0x26
#define FLAG_LOCKEDOUT_PLAYED	0x27
#define FLAG_HIDE_MADISON	0x28
#define FLAG_UNUSED_0x29	0x29
#define FLAG_MET_SOCIALMEDIA_REPORTER	0x29
#define FLAG_START_MENU_MOVE_MODE	0x2A	// For the Start Menu
#define FLAG_DEFEATED_GARDEN_BOSS	0x2A
#define FLAG_START_MENU_SETUP	0x2B	// Is used the first time you open the start menu to set up the app orders
#define FLAG_OPTION_MENU_SETUP	0x2C	// Is used the first time you open the options menu to set up the configuration
#define FLAG_UNUSED_0x2D	0x2D
#define FLAG_FORCE_SHINY	0x2D
#define FLAG_INVERSE_BATTLE	0x2E
#define FLAG_UNUSED_0x2E	0x2E
#define FLAG_FORCE_DOUBLE_WILD	0x2F
#define FLAG_UNUSED_0x2F	0x2F
#define FLAG_SMART_WILD_AI	0x30
#define FLAG_UNUSED_0x30	0x30
#define FLAG_UNUSED_0x31	0x31
#define FLAG_UNUSED_0x32	0x32
#define FLAG_UNUSED_0x33	0x33
#define FLAG_UNUSED_0x34	0x34
#define FLAG_UNSUED_0x35	0x35
#define FLAG_UNUSED_0x36	0x36
#define FLAG_UNSUED_0x37	0x37
#define FLAG_UNUSED_0x38	0x38
#define FLAG_SPAWN_INVISIBLE	0x39
#define FLAG_QUEST_ULTRAWORMHOLE_FIRST_TOTEM	FLAG_QUEST_ULTRAWORMHOLE_DONDOZO
#define FLAG_QUEST_ULTRAWORMHOLE_DONDOZO	0x3A
#define FLAG_QUEST_ULTRAWORMHOLE_VOLCARONA	0x3B
#define FLAG_QUEST_ULTRAWORMHOLE_DUSCLOPS	0x3C
#define FLAG_QUEST_ULTRAWORMHOLE_CAMERUPT	0x3D
#define FLAG_QUEST_ULTRAWORMHOLE_DEINO	0x3E
#define FLAG_QUEST_ULTRAWORMHOLE_NOIVERN	0x3F
#define FLAG_QUEST_ULTRAWORMHOLE_SHUCKLE	0x40
#define FLAG_QUEST_ULTRAWORMHOLE_KINGLER	0x41
#define FLAG_QUEST_ULTRAWORMHOLE_ORBEETLE	0x42
#define FLAG_QUEST_ULTRAWORMHOLE_DONPHAN	0x43
#define FLAG_QUEST_ULTRAWORMHOLE_LAST_TOTEM	FLAG_QUEST_ULTRAWORMHOLE_DONPHAN
#define FLAG_QUEST_ULTRAWORMHOLE_BATTLED_ULTRA_BEAST	0x44
#define FLAG_QUEST_EMPLOYEDEVERAFTER_FOUND_BRIDE	0x45
#define FLAG_UNUSED_0x46	0x46
#define FLAG_UNUSED_0x47	0x47
#define FLAG_UNUSED_0x48	0x48
#define FLAG_QUEST_PERSUASIVE_SIBLING	0x5E
#define FLAG_CONSTRUCTION_BREAKING_NEWS	0x88
#define FLAG_ARCHER_CALL_ALCATRAZ	0x8A
#define FLAG_RECIEVED_LEFTOVERS	0x264
#define FLAG_CRAFTED_FIRST_GEM	FLAG_CRAFTED_NORMAL_GEM
#define FLAG_CRAFTED_NORMAL_GEM	0x265
#define FLAG_CRAFTED_FIGHTING_GEM	0x266
#define FLAG_CRAFTED_FLYING_GEM	0x267
#define FLAG_CRAFTED_POISON_GEM	0x268
#define FLAG_CRAFTED_GROUND_GEM	0x269
#define FLAG_CRAFTED_ROCK_GEM	0x26A
#define FLAG_CRAFTED_BUG_GEM	0x26B
#define FLAG_CRAFTED_GHOST_GEM	0x26C
#define FLAG_CRAFTED_STEEL_GEM	0x26D
#define FLAG_CRAFTED_FIRE_GEM	0x26E
#define FLAG_CRAFTED_WATER_GEM	0x26F
#define FLAG_CRAFTED_GRASS_GEM	0x270
#define FLAG_CRAFTED_ELECTRIC_GEM	0x271
#define FLAG_CRAFTED_PSYCHIC_GEM	0x272
#define FLAG_CRAFTED_ICE_GEM	0x273
#define FLAG_CRAFTED_DRAGON_GEM	0x274
#define FLAG_CRAFTED_DARK_GEM	0x275
#define FLAG_CRAFTED_FAIRY_GEM	0x276
#define FLAG_RECIEVED_GEMARTIST_MEGASTONE	0x277
#define FLAG_UNSUED_0x277	0x277
#define FLAG_UNSUED_0x278	0x278
#define FLAG_UNSUED_0x279	0x279
#define FLAG_UNSUED_0x27A	0x27A
#define FLAG_UNSUED_0x27B	0x27B
#define FLAG_UNSUED_0x27C	0x27C
#define FLAG_FOUND_STOLEN_GOODS	0x13A
#define FLAG_ITEM_MARIN_RANGER_HEADPHONES	0x3E8
#define FLAG_ITEM_MARIN_RANGER_WIDE_LENS	0x3E9
#define FLAG_ITEM_MARIN_RANGER_ROCKY_HELMET	0x3EA
#define FLAG_ITEM_LAKEMERCED_STUFF1	0x3EB
#define FLAG_ITEM_LAKEMERCED_STUFF2	0x3EC
#define FLAG_ITEM_LAKEMERCED_STUFF3	0x3ED
#define FLAG_ITEM_LAKEMERCED_STUFF4	0x3EE
#define FLAG_ITEM_LAKEMERCED_STUFF5	0x3EF
#define FLAG_ITEM_LAKEMERCED_STUFF6	0x3F0
#define FLAG_ITEM_LAKEMERCED_STUFF7	0x3F1
#define FLAG_ITEM_LAKEMERCED_STUFF8	0x3F2
#define FLAG_ITEM_LAKEMERCED_STUFF9	0x3F3
#define FLAG_ITEM_GLDNGTEWILDS_ENGAGEMENT_RING	0x3F4
#define FLAG_ITEM_ROCKCOLLECTOR_STONE_START	FLAG_ITEM_ROCKCOLLECTOR_CAVE_FIRE_STONE
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_FIRE_STONE	0x3F5
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_WATER_STONE	0x3F6
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_THUNDER_STONE	0x3F7
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_LEAF_STONE	0x3F8
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_ICE_STONE	0x3F9
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_SUN_STONE	0x3FA
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_MOON_STONE	0x3FB
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_SHINY_STONE	0x3FC
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_DUSK_STONE	0x3FD
#define FLAG_ITEM_ROCKCOLLECTOR_CAVE_DAWN_STONE	0x3FE
#define FLAG_ITEM_ROCKCOLLECTOR_STONE_END	FLAG_ITEM_ROCKCOLLECTOR_CAVE_DAWN_STONE
#define ROCKCOLLECTOR_STONES_COUNT	(FLAG_ITEM_ROCKCOLLECTOR_STONE_END - FLAG_ITEM_ROCKCOLLECTOR_STONE_START + 1)
#define FLAG_QUEST_BODEGA_RESCUE_FLAGS_START	FLAG_QUEST_BODEGA_RESCUE1
#define FLAG_QUEST_BODEGA_RESCUE1	0x493
#define FLAG_QUEST_BODEGA_RESCUE2	0x494
#define FLAG_QUEST_BODEGA_RESCUE3	0x495
#define FLAG_QUEST_BODEGA_RESCUE4	0x496
#define FLAG_QUEST_BODEGA_RESCUE5	0x497
#define FLAG_QUEST_BODEGA_RESCUE6	0x498
#define FLAG_QUEST_BODEGA_RESCUE_FLAGS_END	FLAG_QUEST_BODEGA_RESCUE6
#define BODEGA_RESCUE_COUNT	(FLAG_QUEST_BODEGA_RESCUE_FLAGS_END - FLAG_QUEST_BODEGA_RESCUE_FLAGS_START + 1)
#define FLAG_QUEST_WAREHOUSE_WARFARE_EXPLAINED	0x499
#define FLAG_QUEST_WAREHOUSEWARFARE_BARGE2_WORKERS_CLEAR 	0x49A
#define FLAG_QUEST_WAREHOUSEWARFARE_BARGE2_ENGINE_CLEAR	0x49B
#define FLAG_QUEST_WAREHOUSEWARFARE_BARGE3_ENGINE_CLEAR	0x49C
#define FLAG_SYS_QUEST_MENU_GET	(SYSTEM_FLAGS + 0x3)	// add QUESTS to start menu
#define FLAG_DISCOVERED_UNDERGROUNDLAB	(SYSTEM_FLAGS + 0x4F)
#define FLAG_TIMELINE_FALSE	(SYSTEM_FLAGS + 0x85)
#define FLAG_TIMELINE_TRUE	(SYSTEM_FLAGS + 0x86)
#define FLAG_HIDE_TOWER2_KOGA	(SYSTEM_FLAGS + 0x87)
#define FLAG_TIMELINE_TIMETRAVEL	(SYSTEM_FLAGS + 0x88)
#define FLAG_PHONE_NO_SERVICE	(SYSTEM_FLAGS + 0x89)
#define FLAG_DAILY_KITCHEN_VOLUNTEER	(DAILY_FLAGS_START + 0x3)