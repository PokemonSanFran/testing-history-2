#include "constants/easy_chat.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/pokemon.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

@ 85CECB0
	.include "data/battle_frontier/battle_frontier_held_items.inc"

@ 85CED2E
	.include "data/battle_frontier/battle_frontier_trainer_mons.inc"

@ 85D5ACC
	.include "data/battle_frontier/battle_frontier_trainers.inc"

@ 85D97BC
	.include "data/battle_frontier/battle_frontier_mons.inc"

gTowerMaleFacilityClasses:: @ 85DCEDC
	.byte 0x0e, 0x11, 0x03, 0x15, 0x17, 0x07, 0x0a, 0x19, 0x1a, 0x1b, 0x1d, 0x1e, 0x20, 0x26, 0x29, 0x09, 0x2b, 0x2d, 0x2e, 0x30, 0x32, 0x34, 0x04, 0x35, 0x3a, 0x05, 0x42, 0x44, 0x43, 0x00

gTowerFemaleFacilityClasses:: @ 85DCEFA
	.byte 0x0d, 0x10, 0x12, 0x0c, 0x13, 0x14, 0x1f, 0x27, 0x2a, 0x16, 0x2f, 0x31, 0x33, 0x36, 0x37, 0x38, 0x1c, 0x02, 0x45, 0x47

gTowerMaleTrainerGfxIds:: @ 85DCF0E
	.byte 0x37, 0x36, 0x21, 0x0f, 0x27, 0x33, 0x2c, 0x42, 0x42, 0x1f, 0x27, 0x25, 0x30, 0x26, 0x19, 0x15, 0x23, 0x32, 0x38, 0x33, 0x33, 0x21, 0x42, 0x05, 0x31, 0x27, 0x41, 0x1f, 0x24, 0x37

gTowerFemaleTrainerGfxIds:: @ 85DCF2C
	.byte 0x14, 0x35, 0x22, 0x28, 0x14, 0x2d, 0x2f, 0x0e, 0x12, 0x16, 0x39, 0x34, 0x34, 0x0e, 0x22, 0x34, 0x20, 0x14, 0x20, 0x2f

sRubyFacilityClassToEmerald:: @ 85DCF40
	.byte 0x00, 0x0b, 0x01, 0x01, 0x02, 0x06, 0x03, 0x0d, 0x04, 0x0e, 0x05, 0x0f, 0x06, 0x10, 0x07, 0x11, 0x08, 0x03, 0x09, 0x12, 0x0a, 0x0c, 0x0b, 0x13, 0x0c, 0x14, 0x0d, 0x15, 0x0e, 0x17, 0x0f, 0x07
	.byte 0x10, 0x0a, 0x11, 0x19, 0x12, 0x1a, 0x13, 0x1b, 0x14, 0x1d, 0x15, 0x1e, 0x16, 0x1f, 0x17, 0x20, 0x18, 0x21, 0x19, 0x22, 0x1a, 0x23, 0x1b, 0x24, 0x1c, 0x25, 0x1d, 0x26, 0x1e, 0x27, 0x1f, 0x28
	.byte 0x20, 0x29, 0x21, 0x2a, 0x22, 0x09, 0x23, 0x16, 0x24, 0x2b, 0x25, 0x2c, 0x26, 0x2d, 0x27, 0x2e, 0x28, 0x2f, 0x29, 0x30, 0x2a, 0x31, 0x2b, 0x32, 0x2c, 0x33, 0x2d, 0x34, 0x2e, 0x04, 0x2f, 0x35
	.byte 0x30, 0x36, 0x31, 0x37, 0x32, 0x38, 0x33, 0x1c, 0x34, 0x39, 0x35, 0x3a, 0x38, 0x05, 0x39, 0x3b, 0x3a, 0x3c, 0x3b, 0x3d, 0x3c, 0x3e, 0x3d, 0x3f, 0x3e, 0x40, 0x3f, 0x41, 0x40, 0x42, 0x41, 0x02
	.byte 0x42, 0x44, 0x43, 0x45, 0x44, 0x46, 0x45, 0x08, 0x46, 0x18, 0x47, 0x47, 0x48, 0x43, 0x49, 0x00, 0x4a, 0x48, 0x4b, 0x49, 0x4c, 0x4a, 0x00, 0x00









