    .include "asm/macros.inc"
    .include "constants/constants.inc"

    .section .rodata
    .align 2, 0

gMapPopUp_Table:: @ 857C684
	.incbin "graphics/interface/map_popup/wood.4bpp"
	.incbin "graphics/interface/map_popup/marble.4bpp"
	.incbin "graphics/interface/map_popup/stone.4bpp"
	.incbin "graphics/interface/map_popup/brick.4bpp"
	.incbin "graphics/interface/map_popup/underwater.4bpp"
	.incbin "graphics/interface/map_popup/stone2.4bpp"

gMapPopUp_Outline_Table:: @ 857DD04
	.incbin "graphics/interface/map_popup/wood_outline.4bpp"
	.incbin "graphics/interface/map_popup/marble_outline.4bpp"
	.incbin "graphics/interface/map_popup/stone_outline.4bpp"
	.incbin "graphics/interface/map_popup/brick_outline.4bpp"
	.incbin "graphics/interface/map_popup/underwater_outline.4bpp"
	.incbin "graphics/interface/map_popup/stone2_outline.4bpp"

gMapPopUp_Palette_Table:: @ 857F384
	.incbin "graphics/interface/map_popup/wood.gbapal"
	.incbin "graphics/interface/map_popup/marble.gbapal"
	.incbin "graphics/interface/map_popup/stone.gbapal"
	.incbin "graphics/interface/map_popup/brick.gbapal"
	.incbin "graphics/interface/map_popup/underwater.gbapal"
	.incbin "graphics/interface/map_popup/stone2.gbapal"

gUnknown_0857F444:: @ 857F444
	.incbin "graphics/interface/map_popup/857F444.gbapal"
