	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0



	.align 2
gUnknown_0832C220:: @ 832C220
	.byte 0xf0, 0x00, 0x0d, 0x40, 0x30, 0x00, 0x08, 0x42
	.byte 0xf0, 0x20, 0x05, 0x43, 0x10, 0x20, 0x45, 0x43
	.byte 0x30, 0x20, 0x85, 0x43

	.align 2
gUnknown_0832C234:: @ 832C234
	.byte 0xf0, 0x00, 0x0d, 0x44, 0x30, 0x00, 0x08, 0x46
	.byte 0xf0, 0x20, 0x05, 0x47, 0x10, 0x20, 0x45, 0x47
	.byte 0x30, 0x20, 0x85, 0x47

	.align 2
gUnknown_0832C248:: @ 832C248
	.byte 0xf0, 0x00, 0x0d, 0x40, 0x30, 0x00, 0x08, 0x42

	.align 2
gUnknown_0832C250:: @ 832C250
	.byte 0xf0, 0x00, 0x0d, 0x40, 0x30, 0x00, 0x08, 0x42

	.align 2
gUnknown_0832C258:: @ 832C258
	.byte 0xf0, 0x00, 0x05, 0x40, 0x10, 0x00, 0x45, 0x40

	.align 2
gUnknown_0832C260:: @ 832C260
	.byte 0xf0, 0x00, 0x05, 0x40, 0x10, 0x00, 0x45, 0x40
	.byte 0xe0, 0x00, 0x80, 0x40

	.align 2
gUnknown_0832C26C:: @ 832C26C
	.4byte 0x00000005, gUnknown_0832C220
	.4byte 0x00000002, gUnknown_0832C248
	.4byte 0x00000005, gUnknown_0832C234
	.4byte 0x00000002, gUnknown_0832C250

	.align 2
gUnknown_0832C28C:: @ 832C28C
	.4byte 0x00000002, gUnknown_0832C258
	.4byte 0x00000003, gUnknown_0832C260

	.align 2
gUnknown_0832C29C:: @ 832C29C
	.byte 0xa0, 0x00, 0x05, 0x40, 0xc0, 0x00, 0x45, 0x40
	.byte 0xe0, 0x00, 0x85, 0x40, 0x00, 0x00, 0xc5, 0x40

	.align 2
gUnknown_0832C2AC:: @ 832C2AC
	.byte 0xa0, 0x00, 0x05, 0x40, 0xc0, 0x00, 0x45, 0x40
	.byte 0xe0, 0x00, 0x85, 0x40, 0x00, 0x00, 0x85, 0x40
	.byte 0x20, 0x00, 0x85, 0x40, 0x40, 0x00, 0xc5, 0x40

	.align 2
gUnknown_0832C2C4:: @ 832C2C4
	.4byte 0x00000004, gUnknown_0832C29C

	.align 2
gUnknown_0832C2CC:: @ 832C2CC
	.4byte 0x00000006, gUnknown_0832C2AC

	.align 2
gUnknown_0832C2D4:: @ 832C2D4
	.2byte 0x0000, 0x0000, 0x3333, 0x3333, 0x4444, 0x4444, 0x2222, 0x2222
	.2byte 0x7777, 0x7777, 0x7777, 0x7777, 0x7777, 0x7777, 0x7777, 0x7777

	.2byte 0x0000, 0x0000, 0x3333, 0x3333, 0x4444, 0x4444, 0x2222, 0x2222
	.2byte 0x7777, 0x7777, 0x7777, 0x7717, 0x1777, 0x7177, 0x7777, 0x7771

	.2byte 0x0000, 0x0000, 0x3333, 0x3333, 0x4444, 0x4444, 0x2222, 0x2222
	.2byte 0x7777, 0x7777, 0x7777, 0x7111, 0x7777, 0x7171, 0x7777, 0x7111

	.align 2
gUnknown_0832C334:: @ 832C334
	obj_tiles gBattleInterface_BallStatusBarGfx, 0x0200, 0xd70c

	.align 2
gUnknown_0832C33C:: @ 832C33C
	obj_pal gBattleInterface_BallStatusBarPal, 0xd710

	.align 2
gUnknown_0832C344:: @ 832C344
	obj_pal gBattleInterface_BallDisplayPal, 0xd712

	.align 2
gUnknown_0832C34C:: @ 832C34C
	obj_tiles gBattleInterface_BallDisplayGfx, 0x0080, 0xd714

	.align 2
gUnknown_0832C354:: @ 832C354
	.byte 0x00, 0x40, 0x00, 0xc0, 0x00, 0x04, 0x00, 0x00

	.align 2
gUnknown_0832C35C:: @ 832C35C
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00

	.align 2
gUnknown_0832C364:: @ 832C364
	spr_template 0xd70c, 0xd710, gUnknown_0832C138, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8074078

	.align 2
gUnknown_0832C37C:: @ 832C37C
	spr_template 0xd70c, 0xd710, gUnknown_0832C138, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8074078

	.align 2
gUnknown_0832C394:: @ 832C394
	spr_template 0xd714, 0xd712, gUnknown_0832C35C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_80740C4

	.align 2
gUnknown_0832C3AC:: @ 832C3AC
	spr_template 0xd714, 0xd712, gUnknown_0832C35C, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_80740C4

	.align 2
gUnknown_0832C3C4:: @ 832C3C4
	.byte 0xfc, 0x01, 0x01, 0xfc, 0x02, 0x02, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_0832C3D8:: @ 832C3D8
	.byte 0xfc, 0x01, 0x01, 0xfc, 0x02, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

	.align 2
gBattleInterfaceStatusIcons_DynPals:: @ 832C3EC
	.byte 0x98, 0x61, 0xf7, 0x0e, 0x94, 0x46, 0xd1, 0x72
	.byte 0xdc, 0x29, 0x00, 0x00

	.align 2
gUnknown_0832C3F8:: @ 832C3F8
	.byte 0x00, 0x00, 0x00, 0x08, 0x02, 0x00, 0x00, 0x00
