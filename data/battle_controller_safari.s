	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gSafariBufferCommands:: @ 85CDF20
	.4byte sub_81597AC
	.4byte sub_81597B8
	.4byte sub_81597C4
	.4byte sub_81597D0
	.4byte sub_81597DC
	.4byte sub_81597E8
	.4byte sub_81597F4
	.4byte sub_8159800
	.4byte sub_81598E0
	.4byte sub_81598EC
	.4byte sub_81598F8
	.4byte sub_8159904
	.4byte sub_8159910
	.4byte sub_8159964
	.4byte sub_81599C4
	.4byte sub_81599D0
	.4byte dp01t_10_6_message
	.4byte dp01t_11_6_message_for_player_only
	.4byte sub_8159A94
	.4byte sub_8159AFC
	.4byte sub_8159B08
	.4byte sub_8159B14
	.4byte sub_8159B54
	.4byte sub_8159B60
	.4byte sub_8159B6C
	.4byte sub_8159B78
	.4byte sub_8159B84
	.4byte sub_8159BC0
	.4byte sub_8159BCC
	.4byte sub_8159BD8
	.4byte sub_8159BE4
	.4byte sub_8159BF0
	.4byte sub_8159BFC
	.4byte sub_8159C08
	.4byte sub_8159C14
	.4byte sub_8159C20
	.4byte sub_8159C2C
	.4byte sub_8159C38
	.4byte sub_8159C44
	.4byte sub_8159C50
	.4byte sub_8159C5C
	.4byte sub_8159C68
	.4byte sub_8159C74
	.4byte sub_8159C80
	.4byte dp01t_34_6_move_anim_start_t3
	.4byte sub_8159D20
	.4byte dp01t_2E_6_battle_intro
	.4byte sub_8159D90
	.4byte sub_8159DEC
	.4byte sub_8159DF8
	.4byte sub_8159E04
	.4byte sub_8159E10
	.4byte sub_8159E1C
	.4byte sub_8159E78
	.4byte sub_8159E84
	.4byte sub_8159E90
	.4byte nullsub_115

	.align 2
gUnknown_085CE004:: @ 85CE004
	.2byte 0x0000, 0x0004, 0x0010, 0x0004
	.2byte 0x0020, 0x0004, 0x0030, 0x0004
	.2byte 0x0040, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_085CE01C:: @ 85CE01C
	.4byte gUnknown_085CE004

	.align 2
gUnknown_085CE020:: @ 85CE020
	.2byte 0x2799 @ tileTag
	.2byte 0x2799 @ paletteTag
	.4byte gUnknown_08524A34
	.4byte gUnknown_085CE01C
	.4byte NULL
	.4byte gDummySpriteAffineAnimTable
	.4byte sub_80A77C8

	.align 2
	.2byte 0x2720 @ tileTag
	.2byte 0x2720 @ paletteTag
	.4byte gUnknown_08524934
	.4byte gDummySpriteAnimTable
	.4byte NULL
	.4byte gDummySpriteAffineAnimTable
	.4byte sub_815A0D4

	.align 2
	.2byte 0x2721 @ tileTag
	.2byte 0x2721 @ paletteTag
	.4byte gUnknown_08524904
	.4byte gDummySpriteAnimTable
	.4byte NULL
	.4byte gDummySpriteAffineAnimTable
	.4byte sub_80A78AC

	.align 2
gUnknown_085CE068:: @ 85CE068
	.2byte 0x0000, 0x0028, 0x0010, 0x0008
	.2byte 0x0020, 0x0028, 0xffff, 0x0000

	.align 2
gUnknown_085CE078:: @ 85CE078
	.4byte gUnknown_085CE068

	.align 2
gUnknown_085CE07C:: @ 85CE07C
	.2byte 0x27ce @ tileTag
	.2byte 0x27ce @ paletteTag
	.4byte gUnknown_08524914
	.4byte gUnknown_085CE078
	.4byte NULL
	.4byte gDummySpriteAffineAnimTable
	.4byte sub_80A77C8

	.align 2
	.2byte 0x27cf @ tileTag
	.2byte 0x27cf @ paletteTag
	.4byte gUnknown_08524A3C
	.4byte gDummySpriteAnimTable
	.4byte NULL
	.4byte gDummySpriteAffineAnimTable
	.4byte sub_815A1B0

	.align 2
	.2byte 0x27cd @ tileTag
	.2byte 0x27cd @ paletteTag
	.4byte gUnknown_08524974
	.4byte gDummySpriteAnimTable
	.4byte NULL
	.4byte gDummySpriteAffineAnimTable
	.4byte sub_815A254

	.align 2
gUnknown_085CE0C4:: @ 85CE0C4
	.2byte 0x0180, 0x0180, 0x0000, 0x0000
	.2byte 0xffe0, 0x0018, 0x0500, 0x0000
	.2byte 0x0018, 0xffe0, 0x0500, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_085CE0E4:: @ 85CE0E4
	.2byte 0x0030, 0x0030, 0x0000, 0x0000
	.2byte 0x0020, 0x0020, 0x0600, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE0FC:: @ 85CE0FC
	.4byte gUnknown_085CE0C4
	.4byte gUnknown_085CE0E4

	.align 2
gUnknown_085CE104:: @ 85CE104
	.2byte 0x27cb @ tileTag
	.2byte 0x27cb @ paletteTag
	.4byte gUnknown_08524AFC
	.4byte gDummySpriteAnimTable
	.4byte NULL
	.4byte gUnknown_085CE0FC
	.4byte sub_815A2F0

	.align 2
	.2byte 0x27a8 @ tileTag
	.2byte 0x27a8 @ paletteTag
	.4byte gUnknown_0852490C
	.4byte gDummySpriteAnimTable
	.4byte NULL
	.4byte gDummySpriteAffineAnimTable
	.4byte sub_815A6C4

	.align 2
gUnknown_085CE134:: @ 85CE134
	.2byte 0x0000, 0x0003, 0x0010, 0x0003
	.2byte 0x0020, 0x0003, 0x0030, 0x0003
	.2byte 0x0040, 0x0003, 0xffff, 0x0000

	.align 2
gUnknown_085CE14C:: @ 85CE14C
	.4byte gUnknown_085CE134

	.align 2
gUnknown_085CE150:: @ 85CE150
	.2byte 0x272b @ tileTag
	.2byte 0x272b @ paletteTag
	.4byte gUnknown_08524914
	.4byte gUnknown_085CE14C
	.4byte NULL
	.4byte gDummySpriteAffineAnimTable
	.4byte sub_815A7B0

	.align 2
gUnknown_085CE168:: @ 85CE168
	.2byte 0x0000, 0x0003, 0xffff, 0x0000

	.align 2
gUnknown_085CE170:: @ 85CE170
	.4byte gUnknown_085CE168

	.align 2
gUnknown_085CE174:: @ 85CE174
	.2byte 0xfff9, 0xfff9, 0x10fd, 0x0000
	.2byte 0x0007, 0x0007, 0x1003, 0x0000
	.2byte 0x7ffe, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE18C:: @ 85CE18C
	.4byte gUnknown_085CE174

	.align 2
gUnknown_085CE190:: @ 85CE190
	.2byte 0x27f4 @ tileTag
	.2byte 0x27f4 @ paletteTag
	.4byte gUnknown_08524974
	.4byte gUnknown_085CE170
	.4byte NULL
	.4byte gUnknown_085CE18C
	.4byte sub_815A7EC

	.align 2
gUnknown_085CE1A8:: @ 85CE1A8
	.2byte 0x0000, 0x0008, 0x0010, 0x0010, 0x0020, 0x0004, 0x0030, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_085CE1BC:: @ 85CE1BC
	.4byte gUnknown_085CE1A8

	.align 2
gUnknown_085CE1C0:: @ 85CE1C0
	.2byte 0x0200, 0x0200, 0x0000, 0x0000
	.2byte 0xffe0, 0xffe0, 0x0800, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE1D8:: @ 85CE1D8
	.4byte gUnknown_085CE1C0

	.align 2
gUnknown_085CE1DC:: @ 85CE1DC
	.2byte 0x27d0 @ tileTag
	.2byte 0x27d0 @ paletteTag
	.4byte gUnknown_085249D4
	.4byte gUnknown_085CE1BC
	.4byte NULL
	.4byte gUnknown_085CE1D8
	.4byte sub_815A8AC

	.align 2
gUnknown_085CE1F4:: @ 85CE1F4
	.2byte 0x0000, 0x0180, 0x0000, 0x0000
	.2byte 0x0010, 0x0000, 0x1400, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE20C:: @ 85CE20C
	.2byte 0x0140, 0x0180, 0x0000, 0x0000
	.2byte 0xfff0, 0x0000, 0x1300, 0x0000
	.2byte 0x7fff, 0x0000, 0x0000, 0x0000

	.align 2
gUnknown_085CE224:: @ 85CE224
	.4byte gUnknown_085CE1F4
	.4byte gUnknown_085CE20C

	.align 2
gUnknown_085CE22C:: @ 85CE22C
	.2byte 0x27f3 @ tileTag
	.2byte 0x27f3 @ paletteTag
	.4byte gUnknown_085249DC
	.4byte gDummySpriteAnimTable
	.4byte NULL
	.4byte gUnknown_085CE224
	.4byte sub_815A934

	.align 2
	.2byte 0x2807 @ tileTag
	.2byte 0x2807 @ paletteTag
	.4byte gUnknown_08524914
	.4byte gDummySpriteAnimTable
	.4byte NULL
	.4byte gDummySpriteAffineAnimTable
	.4byte sub_815AAA4

	.align 2
	.2byte 0x2807 @ tileTag
	.2byte 0x2807 @ paletteTag
	.4byte gUnknown_08524914
	.4byte gDummySpriteAnimTable
	.4byte NULL
	.4byte gDummySpriteAffineAnimTable
	.4byte sub_815ABD0

	.align 2
gUnknown_085CE274:: @ 85CE274
	.2byte 0x0000, 0x0002, 0x0008, 0x0002
	.2byte 0x0010, 0x0002, 0xfffe, 0x0000

	.align 2
gUnknown_085CE284:: @ 85CE284
	.4byte gUnknown_085CE274

	.align 2
gUnknown_085CE288:: @ 85CE288
	.2byte 0x27f5 @ tileTag
	.2byte 0x27f5 @ paletteTag
	.4byte gUnknown_08524934
	.4byte gUnknown_085CE284
	.4byte NULL
	.4byte gDummySpriteAffineAnimTable
	.4byte sub_815ACD0
	

