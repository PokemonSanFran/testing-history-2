#include "constants/species.h"
#include "constants/moves.h"
	.include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

	.align 2
gUnknown_08589904:: @ 8589904
	obj_tiles gBlankGfxCompressed, 0x1000, 0x80e8
	obj_tiles gBlankGfxCompressed, 0x1000, 0x80e9
	obj_tiles gBlankGfxCompressed, 0x1000, 0x80ea
	obj_tiles gBlankGfxCompressed, 0x1000, 0x80eb

	.align 2
gUnknown_08589924:: @ 8589924 Yup this is super dangerous but that's how it is here
	obj_pal gHeap + 0x1A0A4, 0x80e8
	obj_pal gHeap + 0x1A0C4, 0x80e9
	obj_pal gHeap + 0x1A0E4, 0x80ea
	obj_pal gHeap + 0x1A104, 0x80eb

	.align 2
gOamData_8589944:: @ 8589944
	.2byte 0x0700
	.2byte 0xC000
	.2byte 0x0000

	.align 2
gSpriteAffineAnim_858994C:: @ 858994C
	obj_rot_scal_anim_frame 0x100, 0x100, 0, 0
	obj_rot_scal_anim_end

	.align 2
gSpriteAffineAnim_858995C:: @ 858995C
	obj_rot_scal_anim_frame 0x3, 0x3, 0, 15
	obj_rot_scal_anim_frame 0xFFFD, 0xFFFD, 0, 15
	obj_rot_scal_anim_frame 0x3, 0x3, 0, 15
	obj_rot_scal_anim_frame 0xFFFD, 0xFFFD, 0, 15
	obj_rot_scal_anim_end

	.align 2
gSpriteAffineAnimTable_8589984:: @ 8589984
	.4byte gSpriteAffineAnim_858994C
	.4byte gSpriteAffineAnim_858995C

	.align 2
gSpriteTemplate_858998C:: @ 858998C
	spr_template 0x80e8, 0x80e8, gOamData_8589944, gDummySpriteAnimTable, NULL, gSpriteAffineAnimTable_8589984, SpriteCallbackDummy
	spr_template 0x80e9, 0x80e9, gOamData_8589944, gDummySpriteAnimTable, NULL, gSpriteAffineAnimTable_8589984, SpriteCallbackDummy
	spr_template 0x80ea, 0x80ea, gOamData_8589944, gDummySpriteAnimTable, NULL, gSpriteAffineAnimTable_8589984, SpriteCallbackDummy
	spr_template 0x80eb, 0x80eb, gOamData_8589944, gDummySpriteAnimTable, NULL, gSpriteAffineAnimTable_8589984, SpriteCallbackDummy

	.align 2
gContestExcitementTable:: @ 85899EC
	.2byte 0x0001, 0xffff, 0x0000, 0x0001, 0xffff, 0x00ff, 0x0001, 0xffff, 0x00ff, 0x0001, 0xff00, 0x00ff, 0x0001, 0x0000


