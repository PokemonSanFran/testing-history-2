	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2
gUnknown_082ED608:: @ 82ED608
	.byte 0x04, 0x20, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00
	.byte 0x14, 0x2b, 0x02, 0x02, 0x22, 0x2b, 0x02, 0x02
	.byte 0x01, 0x00, 0x58, 0x02, 0x2c, 0x01, 0x00, 0x00

	.align 2
gUnknown_082ED620:: @ 82ED620
	.byte 0x00, 0x03, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082ED628:: @ 82ED628
	.4byte 0x00000000, 0x00000001, 0x00000003, 0x00000007
	.4byte 0x0000000f, 0x0000001f, 0x0000003f, 0x0000007f
	.4byte 0x000000ff, 0x000001ff, 0x000003ff, 0x000007ff
	.4byte 0x00000fff, 0x00001fff, 0x00003fff, 0x00007fff
	.4byte 0x0000ffff, 0x0001ffff, 0x0003ffff, 0x0007ffff
	.4byte 0x000fffff, 0x001fffff, 0x003fffff, 0x007fffff
	.4byte 0x00ffffff

gUnknown_082ED68C:: @ 82ED68C
	.byte 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02
	.byte 0x03

gUnknown_082ED695:: @ 82ED695
	.byte 0x00, 0x01, 0x01, 0x02, 0x01, 0x02, 0x02, 0x03
	.byte 0x01, 0x02, 0x02, 0x03, 0x02, 0x03, 0x03, 0x04

gUnknown_082ED6A5:: @ 82ED6A5
	.byte 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00
	.byte 0x03, 0x00, 0x01, 0x00, 0x02, 0x00, 0x01, 0x00
	.byte 0x00, 0x00, 0x00

	.align 2
gUnknown_082ED6B8:: @ 82ED6B8
    .4byte gBlockSendBuffer
	.4byte 0x000000c8
	.4byte gBlockSendBuffer
	.4byte 0x000000c8
	.4byte gBlockSendBuffer
	.4byte 0x00000064
	.4byte gBlockSendBuffer
	.4byte 0x000000dc
    .4byte gBlockSendBuffer
	.4byte 0x00000028

	.align 2
gUnknown_082ED6E0:: @ 82ED6E0
	.2byte 0x0002, 0x7f7d, 0x0000, 0xffff

	.ascii "RFU WAIT"
	.space 7

	.ascii "RFU BOOT"
	.space 7

	.ascii "RFU ERROR"
	.space 6

	.ascii "RFU RESET"
	.space 6

	.ascii "RFU CONFIG"
	.space 5

	.ascii "RFU START"
	.space 6

	.ascii "RFU SC POLL"
	.space 4

	.ascii "RFU SP POLL"
	.space 4

	.ascii "RFU START"
	.space 6

	.ascii "RFU SEND ERR"
	.space 3

	.ascii "RFU CP POLL"
	.space 4

	.ascii "              "
	.space 2

	.ascii "RECOVER START "
	.space 2

	.ascii "DISSCONECT    "
	.space 2

	.ascii "RECOVER SUUSES"
	.space 2

	.ascii "RECOVER FAILED"
	.space 2

	.align 2
gUnknown_082ED7E0:: @ 82ED7E0
	.4byte sub_801084C
	.4byte sub_8010AAC
	.4byte sub_8010D0C

	.align 2
gUnknown_082ED7EC:: @ 82ED7EC
	.ascii "PokemonSioInfo"

	.align 2
gUnknown_082ED7FC:: @ 82ED7FC
	.ascii "LINK LOSS DISCONNECT!"

	.align 2
gUnknown_082ED814:: @ 82ED814
	.ascii "LINK LOSS RECOVERY NOW"
