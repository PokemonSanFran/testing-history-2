	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata
	.align 2, 0

sBallSpriteSheets:: @ 832C400
	.incbin "baserom.gba", 0x32c400, 0x60

sBallSpritePalettes:: @ 832C460
	.incbin "baserom.gba", 0x32c460, 0x128

gBallSpriteTemplates:: @ 832C588
	.incbin "baserom.gba", 0x32c588, 0x138
