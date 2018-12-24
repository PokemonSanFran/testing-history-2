	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_80DCB78
sub_80DCB78: @ 80DCB78
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gSprites
	lsls r5, r0, 4
	adds r5, r0
	lsls r5, 2
	adds r5, r1
	ldrh r0, [r5, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	adds r4, r1
	adds r0, r4, 0
	bl FreeSpriteOamMatrix
	adds r0, r4, 0
	bl DestroySprite
	adds r0, r5, 0
	bl DestroySpriteAndFreeResources
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DCB78

	thumb_func_start sub_80DCBB4
sub_80DCBB4: @ 80DCBB4
	push {lr}
	movs r1, 0xFD
	lsls r1, 6
	movs r0, 0x50
	bl SetGpuReg
	ldr r1, =0x00000907
	movs r0, 0x52
	bl SetGpuReg
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DCBB4

	thumb_func_start sub_80DCBD0
sub_80DCBD0: @ 80DCBD0
	push {lr}
	movs r0, 0x50
	movs r1, 0
	bl SetGpuReg
	movs r0, 0x52
	movs r1, 0
	bl SetGpuReg
	pop {r0}
	bx r0
	thumb_func_end sub_80DCBD0

	thumb_func_start sub_80DCBE8
sub_80DCBE8: @ 80DCBE8
	push {r4-r6,lr}
	mov r6, r9
	mov r5, r8
	push {r5,r6}
	adds r4, r0, 0
	mov r9, r1
	lsls r4, 24
	lsrs r4, 24
	mov r0, r9
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	bl sub_80DCBB4
	ldr r0, =gContestResources
	ldr r1, [r0]
	ldr r2, =gSprites
	mov r8, r2
	lsls r6, r4, 4
	adds r6, r4
	lsls r6, 2
	adds r0, r6, r2
	movs r3, 0x30
	ldrsh r2, [r0, r3]
	ldr r1, [r1, 0x14]
	lsls r2, 2
	adds r2, r1
	ldrb r1, [r2, 0x2]
	movs r3, 0x2
	orrs r1, r3
	strb r1, [r2, 0x2]
	ldrh r5, [r0, 0x2E]
	lsls r5, 24
	lsrs r5, 24
	movs r1, 0x1
	bl StartSpriteAffineAnim
	lsls r4, r5, 4
	adds r4, r5
	lsls r4, 2
	mov r1, r8
	adds r0, r4, r1
	movs r1, 0x1
	bl StartSpriteAffineAnim
	movs r2, 0x1C
	add r8, r2
	add r6, r8
	ldr r0, =sub_80DCC84
	str r0, [r6]
	add r4, r8
	ldr r0, =SpriteCallbackDummy
	str r0, [r4]
	mov r3, r9
	cmp r3, 0
	bne _080DCC70
	movs r0, 0x65
	bl PlaySE
	b _080DCC76
	.pool
_080DCC70:
	movs r0, 0x2
	bl PlaySE
_080DCC76:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80DCBE8

	thumb_func_start sub_80DCC84
sub_80DCC84: @ 80DCC84
	push {lr}
	mov r12, r0
	adds r0, 0x3F
	ldrb r1, [r0]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080DCCCC
	mov r0, r12
	ldrh r1, [r0, 0x2E]
	lsls r1, 24
	lsrs r1, 24
	ldr r2, =gSprites
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r1, r0, r2
	adds r0, r1, 0
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 26
	cmp r0, 0
	bge _080DCCCC
	mov r3, r12
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r2, 0x4
	orrs r0, r2
	strb r0, [r3]
	adds r1, 0x3E
	ldrb r0, [r1]
	orrs r0, r2
	strb r0, [r1]
	ldr r0, =sub_80DCCD8
	mov r1, r12
	str r0, [r1, 0x1C]
_080DCCCC:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DCC84

	thumb_func_start sub_80DCCD8
sub_80DCCD8: @ 80DCCD8
	push {lr}
	ldr r1, =gContestResources
	ldr r1, [r1]
	movs r3, 0x30
	ldrsh r2, [r0, r3]
	ldr r1, [r1, 0x14]
	lsls r2, 2
	adds r2, r1
	ldrb r3, [r2, 0x2]
	movs r1, 0x3
	negs r1, r1
	ands r1, r3
	strb r1, [r2, 0x2]
	ldrh r0, [r0, 0x2E]
	lsls r0, 24
	lsrs r0, 24
	bl sub_80DCB78
	bl sub_80DCBD0
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DCCD8

	thumb_func_start sub_80DCD08
sub_80DCD08: @ 80DCD08
	push {lr}
	ldr r0, =gHeap
	movs r1, 0xD0
	lsls r1, 9
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r3, r0, 0
	cmp r1, 0x1
	bne _080DCD24
	movs r0, 0
	b _080DCD26
	.pool
_080DCD24:
	movs r0, 0x1
_080DCD26:
	strb r0, [r2]
	movs r1, 0xD0
	lsls r1, 9
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DCD3E
	bl sub_80DAEA4
	bl sub_80DB2BC
	b _080DCD42
_080DCD3E:
	bl sub_80DCD48
_080DCD42:
	pop {r0}
	bx r0
	thumb_func_end sub_80DCD08

	thumb_func_start sub_80DCD48
sub_80DCD48: @ 80DCD48
	push {r4,r5,lr}
	sub sp, 0xC
	ldr r0, =gUnknown_020322D5
	ldrb r0, [r0]
	cmp r0, 0
	beq _080DCE44
	ldr r0, =gHeap
	movs r1, 0xD0
	lsls r1, 9
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080DCE44
	cmp r0, 0
	blt _080DCD7C
	cmp r0, 0x3
	bgt _080DCD7C
	cmp r0, 0x2
	blt _080DCD7C
	bl sub_80DF750
	b _080DCE44
	.pool
_080DCD7C:
	movs r5, 0
_080DCD7E:
	adds r0, r5, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _080DCD7E
	movs r5, 0
_080DCD92:
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	adds r0, r1
	add r2, sp, 0x4
	ldrh r4, [r0, 0x4]
	movs r1, 0x4
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _080DCDBC
	negs r0, r0
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r2, 0
	ldr r1, =gText_OneDash
	bl StringCopy
	adds r2, r0, 0
_080DCDBC:
	lsls r1, r4, 16
	asrs r1, 16
	adds r0, r2, 0
	movs r2, 0
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r0, =gUnknown_02039F26
	adds r0, r5, r0
	ldrb r0, [r0]
	movs r1, 0x7
	str r1, [sp]
	add r1, sp, 0x4
	movs r2, 0x37
	movs r3, 0x1
	bl Contest_PrintTextToBg0WindowAt
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _080DCD92
	movs r5, 0
_080DCDEA:
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	lsls r0, r5, 3
	subs r0, r5
	lsls r0, 2
	adds r0, r1
	add r2, sp, 0x4
	ldrh r4, [r0, 0x2]
	movs r1, 0x2
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _080DCE14
	negs r0, r0
	lsls r0, 16
	lsrs r4, r0, 16
	adds r0, r2, 0
	ldr r1, =gText_OneDash
	bl StringCopy
	adds r2, r0, 0
_080DCE14:
	lsls r1, r4, 16
	asrs r1, 16
	adds r0, r2, 0
	movs r2, 0
	movs r3, 0x4
	bl ConvertIntToDecimalStringN
	ldr r0, =gUnknown_02039F26
	adds r0, r5, r0
	ldrb r0, [r0]
	movs r1, 0x7
	str r1, [sp]
	add r1, sp, 0x4
	movs r2, 0x5
	movs r3, 0x1
	bl Contest_PrintTextToBg0WindowAt
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
	cmp r5, 0x3
	bls _080DCDEA
	bl sub_80DB2BC
_080DCE44:
	add sp, 0xC
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DCD48

	thumb_func_start sub_80DCE58
sub_80DCE58: @ 80DCE58
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x14
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	add r4, sp, 0x4
	adds r0, r4, 0
	movs r1, 0
	movs r2, 0x8
	bl memset
	movs r5, 0
	add r4, sp, 0x4
	adds r6, r4, 0
	movs r7, 0
_080DCE7E:
	bl Random
	adds r1, r0, 0
	mov r0, sp
	adds r0, r7
	adds r0, 0x4
	strh r1, [r0]
	movs r2, 0
	cmp r2, r5
	bge _080DCEB6
	lsls r0, r1, 16
	lsrs r0, 16
	mov r1, sp
	ldrh r1, [r1, 0x4]
	cmp r0, r1
	beq _080DCEB0
_080DCE9E:
	adds r2, 0x1
	cmp r2, r5
	bge _080DCEB6
	lsls r0, r2, 1
	adds r0, r4, r0
	ldrh r1, [r6]
	ldrh r0, [r0]
	cmp r1, r0
	bne _080DCE9E
_080DCEB0:
	subs r6, 0x2
	subs r7, 0x2
	subs r5, 0x1
_080DCEB6:
	adds r6, 0x2
	adds r7, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DCE7E
	mov r2, r8
	cmp r2, 0
	bne _080DCF80
	movs r5, 0
	ldr r3, =gUnknown_02039F26
	mov r8, r3
_080DCECC:
	mov r6, r8
	strb r5, [r6]
	movs r4, 0
	cmp r4, r5
	bge _080DCF48
	ldr r7, =gContestMonConditions
	mov r9, r7
	lsls r0, r5, 1
	adds r1, r0, 0
	add r1, r9
	mov r12, r1
	mov r2, sp
	adds r2, 0x4
	str r2, [sp, 0xC]
	add r0, sp
	adds r0, 0x4
	str r0, [sp, 0x10]
	ldr r3, =gUnknown_02039F26
	adds r6, r3, 0
	mov r10, r6
_080DCEF4:
	ldrb r0, [r3]
	lsls r2, r0, 1
	mov r7, r9
	adds r0, r2, r7
	movs r6, 0
	ldrsh r1, [r0, r6]
	mov r7, r12
	movs r6, 0
	ldrsh r0, [r7, r6]
	cmp r1, r0
	blt _080DCF1C
	cmp r1, r0
	bne _080DCF40
	ldr r7, [sp, 0xC]
	adds r0, r7, r2
	ldrh r0, [r0]
	ldr r1, [sp, 0x10]
	ldrh r1, [r1]
	cmp r0, r1
	bcs _080DCF40
_080DCF1C:
	adds r2, r5, 0
	cmp r5, r4
	ble _080DCF34
	subs r0, r5, 0x1
	mov r6, r10
	adds r1, r0, r6
_080DCF28:
	ldrb r0, [r1]
	strb r0, [r1, 0x1]
	subs r1, 0x1
	subs r2, 0x1
	cmp r2, r4
	bgt _080DCF28
_080DCF34:
	strb r5, [r3]
	b _080DCF48
	.pool
_080DCF40:
	adds r3, 0x1
	adds r4, 0x1
	cmp r4, r5
	blt _080DCEF4
_080DCF48:
	cmp r4, r5
	bne _080DCF50
	mov r7, r8
	strb r5, [r7]
_080DCF50:
	movs r0, 0x1
	add r8, r0
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DCECC
	ldr r4, =gUnknown_02039F26
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x4
	bl memcpy
	movs r5, 0
_080DCF68:
	mov r1, sp
	adds r0, r1, r5
	ldrb r0, [r0]
	adds r0, r4
	strb r5, [r0]
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DCF68
	b _080DD034
	.pool
_080DCF80:
	mov r0, sp
	movs r1, 0xFF
	movs r2, 0x4
	bl memset
	movs r5, 0
	ldr r3, =gUnknown_02039F26
	movs r6, 0
_080DCF90:
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x4]
	adds r0, r6, r0
	ldrb r0, [r0, 0xB]
	lsls r0, 30
	lsrs r2, r0, 30
	mov r7, sp
	adds r1, r7, r2
	b _080DCFB6
	.pool
_080DCFAC:
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	mov r0, sp
	adds r1, r0, r2
_080DCFB6:
	ldrb r0, [r1]
	cmp r0, 0xFF
	bne _080DCFAC
	strb r5, [r1]
	strb r2, [r3]
	adds r3, 0x1
	adds r6, 0x1C
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DCF90
	movs r5, 0
_080DCFCC:
	movs r4, 0x3
	adds r1, r5, 0x1
	mov r10, r1
	cmp r4, r5
	ble _080DD02E
	mov r9, r4
	ldr r2, =gUnknown_02039F26
	mov r8, r2
	add r3, sp, 0x4
	mov r12, r3
_080DCFE0:
	ldr r6, =gContestResources
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r1
	adds r1, r0, 0
	subs r1, 0x1C
	ldrb r2, [r1, 0xB]
	ldrb r3, [r0, 0xB]
	mov r1, r9
	ands r1, r2
	mov r0, r9
	ands r0, r3
	subs r3, r4, 0x1
	cmp r1, r0
	bne _080DD028
	mov r0, r8
	adds r7, r3, r0
	adds r2, r4, r0
	ldrb r6, [r7]
	ldrb r1, [r2]
	cmp r6, r1
	bcs _080DD028
	lsls r0, r3, 1
	add r0, r12
	lsls r1, r4, 1
	add r1, r12
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bcs _080DD028
	ldrb r0, [r2]
	strb r6, [r2]
	strb r0, [r7]
_080DD028:
	adds r4, r3, 0
	cmp r4, r5
	bgt _080DCFE0
_080DD02E:
	mov r5, r10
	cmp r5, 0x2
	ble _080DCFCC
_080DD034:
	add sp, 0x14
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DCE58

	thumb_func_start sub_80DD04C
sub_80DD04C: @ 80DD04C
	push {r4,r5,lr}
	movs r4, 0
	movs r5, 0xA0
_080DD052:
	ldr r0, =gHeap+0x1A004
	adds r0, r5, r0
	ldr r1, =gUnknown_02039F26
	adds r1, r4, r1
	ldrb r1, [r1]
	adds r1, 0x5
	lsls r1, 4
	movs r2, 0x20
	bl LoadPalette
	adds r5, 0x20
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DD052
	bl sub_80DAEA4
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DD04C

	thumb_func_start sub_80DD080
sub_80DD080: @ 80DD080
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r4, =gContestResources
	ldr r3, [r4]
	ldr r1, [r3, 0x4]
	lsls r7, r6, 3
	subs r0, r7, r6
	lsls r5, r0, 2
	adds r1, r5, r1
	movs r2, 0
	strh r2, [r1, 0x2]
	ldr r0, [r3, 0x4]
	adds r0, r5, r0
	strh r2, [r0]
	adds r0, r6, 0
	bl sub_80DBA68
	lsls r0, 24
	mov r8, r4
	cmp r0, 0
	bne _080DD0B4
	b _080DD3C4
_080DD0B4:
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	adds r1, r5, r1
	ldrh r0, [r1, 0x6]
	ldr r2, =gContestMoves
	lsls r0, 3
	adds r0, r2
	ldrb r2, [r0]
	mov r9, r2
	ldrb r0, [r0, 0x1]
	lsls r0, 29
	lsrs r0, 29
	strb r0, [r1, 0xA]
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	adds r2, r5, r0
	ldrh r0, [r2, 0x6]
	ldrh r1, [r2, 0x8]
	cmp r0, r1
	bne _080DD110
	cmp r0, 0
	beq _080DD110
	ldrb r0, [r2, 0x15]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x15]
	ldr r0, [r4]
	ldr r2, [r0, 0x4]
	adds r2, r5, r2
	ldrb r3, [r2, 0xB]
	lsls r1, r3, 25
	lsrs r1, 29
	adds r1, 0x1
	movs r0, 0x7
	ands r1, r0
	lsls r1, 4
	movs r0, 0x71
	negs r0, r0
	ands r0, r3
	orrs r0, r1
	strb r0, [r2, 0xB]
	b _080DD12C
	.pool
_080DD110:
	ldr r4, =gContestResources
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	lsls r3, r6, 3
	subs r1, r3, r6
	lsls r1, 2
	adds r1, r0
	ldrb r2, [r1, 0xB]
	movs r0, 0x71
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0xB]
	mov r8, r4
	adds r7, r3, 0
_080DD12C:
	mov r2, r8
	ldr r4, [r2]
	ldr r2, [r4, 0x4]
	subs r0, r7, r6
	lsls r0, 2
	adds r2, r0, r2
	ldr r3, =gContestEffects
	mov r1, r9
	lsls r5, r1, 2
	adds r3, r5, r3
	ldrb r1, [r3, 0x1]
	strh r1, [r2]
	ldr r1, [r4, 0x4]
	adds r0, r1
	ldrh r1, [r0]
	strh r1, [r0, 0x2]
	ldr r1, [r4, 0x8]
	ldrb r0, [r3, 0x2]
	strh r0, [r1, 0x4]
	ldr r1, [r4, 0x8]
	ldrh r0, [r1, 0x4]
	strh r0, [r1, 0x6]
	ldr r0, [r4, 0x8]
	strb r6, [r0, 0x11]
	movs r2, 0
	mov r9, r5
	mov r4, r8
	movs r3, 0
	movs r1, 0
_080DD166:
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	adds r0, r1, r0
	strb r3, [r0, 0xE]
	ldr r0, [r4]
	ldr r0, [r0, 0x8]
	adds r0, 0xD
	adds r0, r2
	strb r3, [r0]
	adds r1, 0x1C
	adds r2, 0x1
	cmp r2, 0x3
	ble _080DD166
	ldr r5, =gContestResources
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	subs r0, r7, r6
	lsls r4, r0, 2
	adds r2, r4, r1
	ldrb r1, [r2, 0x15]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080DD1B4
	ldrh r0, [r2, 0x8]
	ldrh r1, [r2, 0x6]
	bl AreMovesContestCombo
	lsls r0, 24
	cmp r0, 0
	bne _080DD1B4
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x15]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x15]
_080DD1B4:
	ldr r0, =gContestEffectFuncs
	add r0, r9
	ldr r0, [r0]
	bl _call_via_r0
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	subs r0, r7, r6
	lsls r0, 2
	adds r2, r0, r1
	ldrb r1, [r2, 0x10]
	movs r0, 0x30
	ands r0, r1
	cmp r0, 0x10
	bne _080DD1EC
	ldrh r1, [r2, 0x2]
	subs r1, 0xA
	movs r0, 0xD
	ldrsb r0, [r2, r0]
	b _080DD206
	.pool
_080DD1EC:
	ldrb r1, [r2, 0x11]
	movs r0, 0x20
	ands r0, r1
	cmp r0, 0
	beq _080DD200
	movs r1, 0xD
	ldrsb r1, [r2, r1]
	lsls r0, r1, 1
	adds r0, r1
	b _080DD204
_080DD200:
	movs r0, 0xD
	ldrsb r0, [r2, r0]
_080DD204:
	ldrh r1, [r2, 0x2]
_080DD206:
	adds r0, r1
	strh r0, [r2, 0x2]
	ldr r5, =gContestResources
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	subs r0, r7, r6
	lsls r4, r0, 2
	adds r1, r4, r1
	movs r0, 0
	strb r0, [r1, 0x16]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x15]
	movs r0, 0x41
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x15]
	adds r0, r6, 0
	bl sub_80DE1E8
	lsls r0, 24
	cmp r0, 0
	beq _080DD2E2
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrh r0, [r1, 0x8]
	ldrh r1, [r1, 0x6]
	bl AreMovesContestCombo
	lsls r0, 24
	lsrs r3, r0, 24
	cmp r3, 0
	beq _080DD29C
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r2, r4, r0
	ldrb r1, [r2, 0x15]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080DD29C
	strb r3, [r2, 0x16]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r0, [r1, 0x15]
	movs r2, 0x40
	orrs r0, r2
	strb r0, [r1, 0x15]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r2, [r1, 0x15]
	movs r0, 0x11
	negs r0, r0
	ands r0, r2
	strb r0, [r1, 0x15]
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	movs r1, 0
	ldrsh r2, [r0, r1]
	ldrb r1, [r0, 0x16]
	muls r1, r2
	strb r1, [r0, 0x17]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r0, [r1, 0x15]
	movs r2, 0x8
	b _080DD2C8
	.pool
_080DD29C:
	ldr r2, =gContestMoves
	ldr r5, =gContestResources
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	subs r0, r7, r6
	lsls r4, r0, 2
	adds r3, r4, r1
	ldrh r0, [r3, 0x6]
	lsls r0, 3
	adds r0, r2
	ldrb r0, [r0, 0x2]
	cmp r0, 0
	beq _080DD2D8
	ldrb r0, [r3, 0x15]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r3, 0x15]
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	adds r1, r4, r1
	ldrb r0, [r1, 0x15]
	movs r2, 0x40
_080DD2C8:
	orrs r0, r2
	strb r0, [r1, 0x15]
	b _080DD2E2
	.pool
_080DD2D8:
	ldrb r1, [r3, 0x15]
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
	strb r0, [r3, 0x15]
_080DD2E2:
	ldr r5, =gContestResources
	ldr r0, [r5]
	ldr r1, [r0, 0x4]
	subs r0, r7, r6
	lsls r4, r0, 2
	adds r2, r4, r1
	ldrb r1, [r2, 0x15]
	movs r0, 0x1
	mov r8, r0
	ands r0, r1
	cmp r0, 0
	beq _080DD30A
	ldrb r0, [r2, 0xB]
	lsls r0, 25
	lsrs r0, 29
	adds r0, 0x1
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 1
	strb r1, [r2, 0x18]
_080DD30A:
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r2, r4, r0
	ldrb r1, [r2, 0xC]
	mov r0, r8
	ands r0, r1
	cmp r0, 0
	beq _080DD334
	ldrb r1, [r2, 0x15]
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x15]
	ldr r2, [r5]
	ldr r0, [r2, 0x4]
	adds r0, r4, r0
	movs r1, 0
	strh r1, [r0, 0x2]
	ldr r0, [r2, 0x4]
	adds r0, r4, r0
	strh r1, [r0]
_080DD334:
	ldr r0, [r5]
	ldr r0, [r0, 0x4]
	adds r0, r4, r0
	ldrh r0, [r0, 0x6]
	bl Contest_GetMoveExcitement
	ldr r1, [r5]
	ldr r1, [r1, 0x10]
	strb r0, [r1]
	ldr r2, [r5]
	ldr r0, [r2, 0x4]
	adds r0, r4, r0
	ldrb r1, [r0, 0x11]
	movs r0, 0x10
	ands r0, r1
	cmp r0, 0
	beq _080DD35C
	ldr r0, [r2, 0x10]
	mov r1, r8
	strb r1, [r0]
_080DD35C:
	ldr r1, [r5]
	ldr r3, [r1, 0x10]
	movs r0, 0
	ldrsb r0, [r3, r0]
	cmp r0, 0
	ble _080DD388
	ldr r0, [r1]
	ldrb r0, [r0, 0x13]
	lsls r0, 24
	asrs r0, 24
	movs r1, 0
	ldrsb r1, [r3, r1]
	adds r0, r1
	cmp r0, 0x4
	ble _080DD384
	movs r0, 0x3C
	b _080DD38A
	.pool
_080DD384:
	movs r0, 0xA
	b _080DD38A
_080DD388:
	movs r0, 0
_080DD38A:
	strb r0, [r3, 0x2]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	movs r2, 0
	b _080DD3AE
_080DD3A2:
	subs r0, 0x1
	lsls r0, 24
	lsrs r0, 24
_080DD3A8:
	adds r2, 0x1
	cmp r2, 0x3
	bgt _080DD3B6
_080DD3AE:
	cmp r2, r6
	beq _080DD3A8
	cmp r0, 0
	bne _080DD3A2
_080DD3B6:
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r1, [r0, 0x4]
	subs r0, r7, r6
	lsls r0, 2
	adds r0, r1
	strb r2, [r0, 0x1B]
_080DD3C4:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DD080

	thumb_func_start SetContestantEffectStringID
SetContestantEffectStringID: @ 80DD3D4
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gContestResources
	ldr r2, [r2]
	ldr r3, [r2, 0x4]
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 2
	adds r2, r3
	strb r1, [r2, 0x13]
	bx lr
	.pool
	thumb_func_end SetContestantEffectStringID

	thumb_func_start SetContestantEffectStringID2
SetContestantEffectStringID2: @ 80DD3F0
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gContestResources
	ldr r2, [r2]
	ldr r3, [r2, 0x4]
	lsls r2, r0, 3
	subs r2, r0
	lsls r2, 2
	adds r2, r3
	strb r1, [r2, 0x14]
	bx lr
	.pool
	thumb_func_end SetContestantEffectStringID2

	thumb_func_start SetStartledString
SetStartledString: @ 80DD40C
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	adds r3, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r2, r1, 0
	cmp r1, 0x3B
	bls _080DD426
	movs r1, 0x35
	bl SetContestantEffectStringID
	b _080DD456
_080DD426:
	cmp r1, 0x27
	bls _080DD432
	movs r1, 0x34
	bl SetContestantEffectStringID
	b _080DD456
_080DD432:
	cmp r1, 0x1D
	bls _080DD43E
	movs r1, 0x33
	bl SetContestantEffectStringID
	b _080DD456
_080DD43E:
	cmp r1, 0x13
	bls _080DD44A
	movs r1, 0x32
	bl SetContestantEffectStringID
	b _080DD456
_080DD44A:
	cmp r2, 0x9
	bls _080DD456
	adds r0, r3, 0
	movs r1, 0x31
	bl SetContestantEffectStringID
_080DD456:
	pop {r0}
	bx r0
	thumb_func_end SetStartledString

	thumb_func_start sub_80DD45C
sub_80DD45C: @ 80DD45C
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r6, r1, 24
	ldr r0, =gStringVar1
	lsls r1, r4, 6
	ldr r2, =gContestMons + 2
	adds r1, r2
	bl StringCopy
	ldr r0, =gStringVar2
	ldr r5, =gContestResources
	ldr r1, [r5]
	ldr r2, [r1, 0x4]
	lsls r1, r4, 3
	subs r1, r4
	lsls r1, 2
	adds r1, r2
	ldrh r2, [r1, 0x6]
	movs r1, 0xD
	muls r1, r2
	ldr r2, =gMoveNames
	adds r1, r2
	bl StringCopy
	ldr r3, =gContestMoves
	ldr r1, [r5]
	ldr r0, [r1, 0x8]
	ldrb r2, [r0, 0x11]
	ldr r1, [r1, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x6]
	lsls r0, 3
	adds r0, r3
	ldrb r0, [r0, 0x1]
	lsls r1, r0, 29
	cmp r1, 0
	bne _080DD4DC
	ldr r0, =gStringVar3
	ldr r1, =gText_0827E837
	bl StringCopy
	b _080DD52C
	.pool
_080DD4DC:
	lsrs r0, r1, 29
	cmp r0, 0x1
	bne _080DD4F4
	ldr r0, =gStringVar3
	ldr r1, =gText_0827E83F
	bl StringCopy
	b _080DD52C
	.pool
_080DD4F4:
	lsrs r0, r1, 29
	cmp r0, 0x2
	bne _080DD50C
	ldr r0, =gStringVar3
	ldr r1, =gText_0827E847
	bl StringCopy
	b _080DD52C
	.pool
_080DD50C:
	lsrs r0, r1, 29
	cmp r0, 0x3
	bne _080DD524
	ldr r0, =gStringVar3
	ldr r1, =gText_0827E850
	bl StringCopy
	b _080DD52C
	.pool
_080DD524:
	ldr r0, =gStringVar3
	ldr r1, =gText_0827E85A
	bl StringCopy
_080DD52C:
	ldr r4, =gStringVar4
	ldr r1, =gUnknown_08587E10
	lsls r0, r6, 2
	adds r0, r1
	ldr r1, [r0]
	adds r0, r4, 0
	bl StringExpandPlaceholders
	bl sub_80DB89C
	adds r0, r4, 0
	movs r1, 0x1
	bl Contest_StartTextPrinter
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DD45C

	thumb_func_start MakeContestantNervous
MakeContestantNervous: @ 80DD560
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r4, =gContestResources
	ldr r1, [r4]
	ldr r3, [r1, 0x4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r3, r1, r3
	ldrb r0, [r3, 0xC]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r3, 0xC]
	ldr r0, [r4]
	ldr r0, [r0, 0x4]
	adds r1, r0
	movs r0, 0
	strh r0, [r1, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end MakeContestantNervous

	thumb_func_start sub_80DD590
sub_80DD590: @ 80DD590
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	sub sp, 0x8
	movs r0, 0
	mov r12, r0
	movs r4, 0
	ldr r1, =gUnknown_02039F26
	mov r9, r1
	add r2, sp, 0x4
	mov r6, r9
	movs r5, 0
	adds r3, r2, 0
_080DD5AC:
	mov r0, sp
	adds r1, r0, r4
	adds r0, r4, r6
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, r4
	strb r5, [r0]
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DD5AC
	movs r4, 0
	ldr r7, =gContestResources
	ldr r1, [r7]
	mov r8, r1
	adds r5, r2, 0
_080DD5CA:
	movs r2, 0
	mov r0, r8
	ldr r1, [r0, 0x4]
_080DD5D0:
	ldrb r0, [r1, 0x19]
	cmp r0, r4
	beq _080DD604
	adds r1, 0x1C
	adds r2, 0x1
	cmp r2, 0x3
	ble _080DD5D0
_080DD5DE:
	cmp r2, 0x4
	bne _080DD684
	movs r2, 0
	ldrb r0, [r5]
	cmp r0, 0
	bne _080DD612
	ldr r0, [r7]
	ldr r0, [r0, 0x4]
	ldrb r0, [r0, 0x19]
	cmp r0, 0xFF
	bne _080DD612
	mov r12, r2
	movs r2, 0x1
	b _080DD63A
	.pool
_080DD604:
	mov r1, sp
	adds r0, r1, r2
	strb r4, [r0]
	adds r1, r5, r2
	movs r0, 0x1
	strb r0, [r1]
	b _080DD5DE
_080DD612:
	adds r2, 0x1
	cmp r2, 0x3
	bgt _080DD676
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DD612
	ldr r0, [r7]
	ldr r1, [r0, 0x4]
	lsls r0, r2, 3
	subs r0, r2
	lsls r0, 2
	adds r0, r1
	ldrb r0, [r0, 0x19]
	cmp r0, 0xFF
	bne _080DD612
	lsls r0, r2, 24
	lsrs r0, 24
	mov r12, r0
	adds r2, 0x1
_080DD63A:
	cmp r2, 0x3
	bgt _080DD676
	ldr r6, =gUnknown_02039F26
	lsls r0, r2, 3
	subs r0, r2
	lsls r3, r0, 2
_080DD646:
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DD66E
	ldr r0, [r7]
	ldr r0, [r0, 0x4]
	adds r0, r3, r0
	ldrb r0, [r0, 0x19]
	cmp r0, 0xFF
	bne _080DD66E
	mov r1, r12
	adds r0, r1, r6
	adds r1, r2, r6
	ldrb r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	bls _080DD66E
	lsls r0, r2, 24
	lsrs r0, 24
	mov r12, r0
_080DD66E:
	adds r3, 0x1C
	adds r2, 0x1
	cmp r2, 0x3
	ble _080DD646
_080DD676:
	mov r0, sp
	add r0, r12
	strb r4, [r0]
	mov r0, r12
	adds r1, r5, r0
	movs r0, 0x1
	strb r0, [r1]
_080DD684:
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DD5CA
	movs r4, 0
	ldr r6, =gContestResources
	movs r5, 0
_080DD690:
	ldr r0, [r6]
	ldr r1, [r0, 0x8]
	adds r1, r4
	mov r0, sp
	adds r3, r0, r4
	ldrb r0, [r3]
	strb r0, [r1]
	ldr r0, [r6]
	ldr r0, [r0, 0x4]
	adds r0, r5, r0
	movs r1, 0xFF
	strb r1, [r0, 0x19]
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	adds r1, r5, r1
	ldrb r2, [r1, 0x10]
	movs r0, 0x3F
	ands r0, r2
	strb r0, [r1, 0x10]
	mov r0, r9
	adds r1, r4, r0
	ldrb r0, [r3]
	strb r0, [r1]
	adds r5, 0x1C
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DD690
	add sp, 0x8
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DD590

	thumb_func_start sub_80DD6DC
sub_80DD6DC: @ 80DD6DC
	push {lr}
	adds r2, r0, 0
	ldrh r0, [r2, 0x30]
	adds r1, r0, 0x1
	strh r1, [r2, 0x30]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x54
	ble _080DD712
	movs r0, 0
	strh r0, [r2, 0x30]
	adds r3, r2, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r3]
	ldr r0, =SpriteCallbackDummy
	str r0, [r2, 0x1C]
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	movs r0, 0x11
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x6]
_080DD712:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DD6DC

	thumb_func_start sub_80DD720
sub_80DD720: @ 80DD720
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r1, r0, 24
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r5, [r0, 0x12]
	cmp r1, 0x8
	bls _080DD734
	b _080DD8D4
_080DD734:
	lsls r0, r1, 2
	ldr r1, =_080DD748
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080DD748:
	.4byte _080DD76C
	.4byte _080DD76C
	.4byte _080DD79C
	.4byte _080DD7D0
	.4byte _080DD804
	.4byte _080DD838
	.4byte _080DD86C
	.4byte _080DD8D4
	.4byte _080DD8A0
_080DD76C:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r0, [r1, 0x2E]
	ldr r2, =0x000003ff
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0x20
	bl PlaySE
	b _080DD8F8
	.pool
_080DD79C:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r1, 0x2E]
	adds r2, 0x4
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0x1F
	bl PlaySE
	b _080DD8F8
	.pool
_080DD7D0:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r1, 0x2E]
	adds r2, 0x8
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0x1F
	bl PlaySE
	b _080DD8F8
	.pool
_080DD804:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r1, 0x2E]
	adds r2, 0xC
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0x2D
	bl PlaySE
	b _080DD8F8
	.pool
_080DD838:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r1, 0x2E]
	adds r2, 0xC
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0x2D
	bl PlaySE
	b _080DD8F8
	.pool
_080DD86C:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r1, 0x2E]
	adds r2, 0x10
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0x2D
	bl PlaySE
	b _080DD8F8
	.pool
_080DD8A0:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r1, 0x2E]
	adds r2, 0x18
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0xC3
	bl PlaySE
	b _080DD8F8
	.pool
_080DD8D4:
	ldr r0, =gSprites
	lsls r4, r5, 4
	adds r1, r4, r5
	lsls r1, 2
	adds r1, r0
	ldrh r2, [r1, 0x2E]
	adds r2, 0x14
	ldr r3, =0x000003ff
	adds r0, r3, 0
	ands r2, r0
	ldrh r3, [r1, 0x4]
	ldr r0, =0xfffffc00
	ands r0, r3
	orrs r0, r2
	strh r0, [r1, 0x4]
	movs r0, 0x2D
	bl PlaySE
_080DD8F8:
	adds r2, r4, 0
	ldr r4, =gSprites
	adds r2, r5
	lsls r2, 2
	adds r1, r2, r4
	movs r0, 0
	strh r0, [r1, 0x30]
	adds r1, 0x3E
	ldrb r3, [r1]
	subs r0, 0x5
	ands r0, r3
	strb r0, [r1]
	adds r4, 0x1C
	adds r2, r4
	ldr r0, =sub_80DD6DC
	str r0, [r2]
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, 0x6]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r2, 0x6]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DD720

	thumb_func_start sub_80DD940
sub_80DD940: @ 80DD940
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	movs r5, 0
	ldr r6, =gContestResources
	ldr r0, =gSprites
	mov r9, r0
	ldr r0, =0x06010000
	mov r8, r0
	ldr r7, =0x04000008
_080DD956:
	ldr r0, [r6]
	ldr r1, [r0]
	movs r0, 0x13
	ldrsb r0, [r1, r0]
	ldr r4, =gContestApplauseMeterGfx
	cmp r5, r0
	bge _080DD966
	adds r4, 0x40
_080DD966:
	adds r0, r1, 0
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	add r0, r9
	ldrh r1, [r0, 0x4]
	lsls r1, 22
	lsrs r1, 22
	adds r0, r5, 0
	adds r0, 0x11
	adds r1, r0
	lsls r1, 5
	add r1, r8
	adds r0, r4, 0
	adds r2, r7, 0
	bl CpuSet
	adds r0, r4, 0
	adds r0, 0x20
	ldr r1, [r6]
	ldr r1, [r1]
	adds r1, 0x58
	ldrb r2, [r1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	add r1, r9
	ldrh r1, [r1, 0x4]
	lsls r1, 22
	lsrs r1, 22
	adds r2, r5, 0
	adds r2, 0x19
	adds r1, r2
	lsls r1, 5
	add r1, r8
	adds r2, r7, 0
	bl CpuSet
	ldr r0, [r6]
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x4
	ble _080DD9C8
	bl sub_80DDA20
_080DD9C8:
	adds r5, 0x1
	cmp r5, 0x4
	ble _080DD956
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DD940

	thumb_func_start Contest_GetMoveExcitement
Contest_GetMoveExcitement: @ 80DD9F0
	lsls r0, 16
	ldr r3, =gUnknown_085899EC
	ldr r1, =gContestMoves
	lsrs r0, 13
	adds r0, r1
	ldrb r1, [r0, 0x1]
	lsls r1, 29
	lsrs r1, 29
	ldr r0, =gSpecialVar_ContestCategory
	ldrh r2, [r0]
	lsls r0, r2, 2
	adds r0, r2
	adds r1, r0
	adds r1, r3
	movs r0, 0
	ldrsb r0, [r1, r0]
	bx lr
	.pool
	thumb_func_end Contest_GetMoveExcitement

	thumb_func_start sub_80DDA20
sub_80DDA20: @ 80DDA20
	push {r4,r5,lr}
	ldr r0, =c3_08130B10
	movs r1, 0xA
	bl CreateTask
	adds r5, r0, 0
	lsls r5, 24
	lsrs r5, 24
	ldr r0, =gTasks
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r0
	movs r0, 0x1
	strh r0, [r4, 0xA]
	ldr r0, =0x0000abe2
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0xC]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DDA20

	thumb_func_start c3_08130B10
c3_08130B10: @ 80DDA60
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r2, r0, r1
	ldrh r0, [r2, 0x8]
	adds r0, 0x1
	strh r0, [r2, 0x8]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x1
	bne _080DDAFE
	movs r0, 0
	strh r0, [r2, 0x8]
	movs r3, 0xE
	ldrsh r0, [r2, r3]
	cmp r0, 0
	bne _080DDA94
	ldrh r0, [r2, 0x10]
	adds r0, 0x1
	b _080DDA98
	.pool
_080DDA94:
	ldrh r0, [r2, 0x10]
	subs r0, 0x1
_080DDA98:
	strh r0, [r2, 0x10]
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0xC
	ldrsh r0, [r4, r1]
	lsls r0, 4
	movs r3, 0x84
	lsls r3, 1
	adds r6, r3, 0
	adds r0, r6
	lsls r0, 16
	lsrs r0, 16
	ldrb r2, [r4, 0x10]
	ldr r3, =0x00007fff
	movs r1, 0x1
	bl BlendPalette
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	cmp r0, 0
	beq _080DDACA
	cmp r0, 0x10
	bne _080DDAFE
_080DDACA:
	ldrh r0, [r4, 0xE]
	movs r1, 0x1
	eors r0, r1
	strh r0, [r4, 0xE]
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r0, [r0, 0x13]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x4
	bgt _080DDAFE
	movs r3, 0xC
	ldrsh r0, [r4, r3]
	lsls r0, 4
	adds r0, r6
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x1
	movs r2, 0
	movs r3, 0x1F
	bl BlendPalette
	adds r0, r5, 0
	bl DestroyTask
_080DDAFE:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end c3_08130B10

	thumb_func_start sub_80DDB0C
sub_80DDB0C: @ 80DDB0C
	push {r4,lr}
	ldr r0, =sub_80DDB6C
	movs r1, 0xA
	bl CreateTask
	ldr r3, =gSprites
	ldr r4, =gContestResources
	ldr r2, [r4]
	ldr r0, [r2]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	ldr r1, =0x0000ffba
	strh r1, [r0, 0x24]
	ldr r0, [r2]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	ldr r0, [r4]
	ldr r2, [r0]
	ldrb r0, [r2, 0x6]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDB0C

	thumb_func_start sub_80DDB6C
sub_80DDB6C: @ 80DDB6C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r3, r0, 0
	ldr r4, =gContestResources
	ldr r0, [r4]
	ldr r0, [r0]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r2, r0, r1
	ldr r0, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r0
	movs r5, 0xD0
	lsls r5, 3
	adds r0, r5, 0
	ldrh r5, [r1, 0x1C]
	adds r0, r5
	strh r0, [r1, 0x1C]
	lsls r0, 16
	asrs r0, 24
	ldrh r5, [r2, 0x24]
	adds r0, r5
	strh r0, [r2, 0x24]
	ldrb r0, [r1, 0x1C]
	strh r0, [r1, 0x1C]
	movs r1, 0x24
	ldrsh r0, [r2, r1]
	cmp r0, 0
	ble _080DDBB8
	movs r0, 0
	strh r0, [r2, 0x24]
_080DDBB8:
	movs r5, 0x24
	ldrsh r0, [r2, r5]
	cmp r0, 0
	bne _080DDBD4
	ldr r0, [r4]
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x6]
	adds r0, r3, 0
	bl DestroyTask
_080DDBD4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDB6C

	thumb_func_start sub_80DDBE8
sub_80DDBE8: @ 80DDBE8
	push {r4,r5,lr}
	ldr r5, =gSprites
	ldr r4, =gContestResources
	ldr r0, [r4]
	ldr r2, [r0]
	adds r0, r2, 0
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r0, [r0]
	lsls r0, 29
	cmp r0, 0
	bge _080DDC1C
	ldrb r1, [r2, 0x6]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	b _080DDC40
	.pool
_080DDC1C:
	ldr r0, =task08_080CD1CC
	movs r1, 0xA
	bl CreateTask
	ldr r2, [r4]
	ldr r0, [r2]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	movs r1, 0
	strh r1, [r0, 0x24]
	ldr r2, [r2]
	ldrb r0, [r2, 0x6]
	movs r1, 0x40
	orrs r0, r1
_080DDC40:
	strb r0, [r2, 0x6]
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDBE8

	thumb_func_start task08_080CD1CC
task08_080CD1CC: @ 80DDC4C
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r0, 24
	adds r4, r0, 0
	ldr r5, =gContestResources
	ldr r0, [r5]
	ldr r0, [r0]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r3, r0, r1
	ldr r0, =gTasks
	lsls r2, r4, 2
	adds r2, r4
	lsls r2, 3
	adds r2, r0
	movs r1, 0xD0
	lsls r1, 3
	adds r0, r1, 0
	ldrh r1, [r2, 0x1C]
	adds r0, r1
	strh r0, [r2, 0x1C]
	lsls r0, 16
	asrs r0, 24
	ldrh r1, [r3, 0x24]
	subs r1, r0
	strh r1, [r3, 0x24]
	ldrb r0, [r2, 0x1C]
	strh r0, [r2, 0x1C]
	movs r2, 0x24
	ldrsh r0, [r3, r2]
	movs r1, 0x46
	negs r1, r1
	cmp r0, r1
	bge _080DDC9C
	ldr r0, =0x0000ffba
	strh r0, [r3, 0x24]
_080DDC9C:
	movs r2, 0x24
	ldrsh r0, [r3, r2]
	cmp r0, r1
	bne _080DDCC4
	adds r2, r3, 0
	adds r2, 0x3E
	ldrb r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2]
	ldr r0, [r5]
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	movs r0, 0x41
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x6]
	adds r0, r4, 0
	bl DestroyTask
_080DDCC4:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end task08_080CD1CC

	thumb_func_start sub_80DDCDC
sub_80DDCDC: @ 80DDCDC
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r0, =sub_80DDD20
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	lsls r4, 24
	asrs r4, 24
	strh r4, [r1, 0x8]
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, 0x6]
	movs r1, 0x20
	orrs r0, r1
	strb r0, [r2, 0x6]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDCDC

	thumb_func_start sub_80DDD20
sub_80DDD20: @ 80DDD20
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	movs r1, 0x1C
	ldrsh r0, [r4, r1]
	cmp r0, 0x1
	beq _080DDD54
	cmp r0, 0x1
	bgt _080DDD48
	cmp r0, 0
	beq _080DDD4E
	b _080DDD9C
	.pool
_080DDD48:
	cmp r0, 0x2
	beq _080DDD70
	b _080DDD9C
_080DDD4E:
	bl sub_80DDB0C
	b _080DDD64
_080DDD54:
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, 0x6]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	bne _080DDD9C
_080DDD64:
	ldrh r0, [r4, 0x1C]
	adds r0, 0x1
	strh r0, [r4, 0x1C]
	b _080DDD9C
	.pool
_080DDD70:
	ldrh r0, [r4, 0x1E]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1E]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x14
	ble _080DDD9C
	movs r0, 0
	strh r0, [r4, 0x1E]
	bl sub_80DD940
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x6]
	adds r0, r5, 0
	bl DestroyTask
_080DDD9C:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDD20

	thumb_func_start sub_80DDDA8
sub_80DDDA8: @ 80DDDA8
	ldr r3, =gSprites
	ldr r0, =gContestResources
	ldr r2, [r0]
	ldr r0, [r2]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	movs r1, 0
	strh r1, [r0, 0x24]
	ldr r0, [r2]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x3E
	ldrb r2, [r0]
	movs r1, 0x5
	negs r1, r1
	ands r1, r2
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_80DDDA8

	thumb_func_start sub_80DDDE4
sub_80DDDE4: @ 80DDDE4
	ldr r2, =gSprites
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0]
	adds r0, 0x58
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
	strb r1, [r0]
	bx lr
	.pool
	thumb_func_end sub_80DDDE4

	thumb_func_start sub_80DDE0C
sub_80DDE0C: @ 80DDE0C
	push {lr}
	ldr r0, =sub_80DDE30
	movs r1, 0xF
	bl CreateTask
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, 0x6]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x6]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDE0C

	thumb_func_start sub_80DDE30
sub_80DDE30: @ 80DDE30
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r4, r0, r1
	ldrh r0, [r4, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r4, 0x1C]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0x6
	ble _080DDEBA
	movs r0, 0
	strh r0, [r4, 0x1C]
	movs r1, 0x1E
	ldrsh r0, [r4, r1]
	cmp r0, 0
	bne _080DDE78
	ldr r0, =gHeap+0x19000
	ldr r1, =0x06002000
	movs r2, 0x80
	lsls r2, 5
	movs r3, 0x1
	bl RequestDma3Copy
	b _080DDE8C
	.pool
_080DDE78:
	ldr r0, =gHeap+0x18000
	ldr r1, =0x06002000
	movs r2, 0x80
	lsls r2, 5
	movs r3, 0x1
	bl RequestDma3Copy
	ldrh r0, [r4, 0x20]
	adds r0, 0x1
	strh r0, [r4, 0x20]
_080DDE8C:
	ldr r1, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r0, r1
	ldrh r1, [r0, 0x1E]
	movs r2, 0x1
	eors r1, r2
	strh r1, [r0, 0x1E]
	movs r1, 0x20
	ldrsh r0, [r0, r1]
	cmp r0, 0x9
	bne _080DDEBA
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, 0x6]
	movs r0, 0x7F
	ands r0, r1
	strb r0, [r2, 0x6]
	adds r0, r5, 0
	bl DestroyTask
_080DDEBA:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDE30

	thumb_func_start sub_80DDED0
sub_80DDED0: @ 80DDED0
	push {r4-r7,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	lsls r1, 24
	lsrs r5, r1, 24
	ldr r0, =sub_80DDF80
	movs r1, 0xA
	bl CreateTask
	lsls r0, 24
	lsrs r6, r0, 24
	lsls r4, 24
	cmp r4, 0
	ble _080DDF38
	ldr r7, =0x0000237e
	lsls r0, r5, 24
	adds r4, r0, 0
	cmp r4, 0
	ble _080DDF1C
	movs r5, 0
	ldr r2, =gContestResources
	ldr r0, [r2]
	ldr r0, [r0]
	movs r1, 0x13
	ldrsb r1, [r0, r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 24
	lsrs r3, r0, 24
	b _080DDF4E
	.pool
_080DDF1C:
	ldr r2, =gContestResources
	ldr r0, [r2]
	ldr r0, [r0]
	movs r1, 0x13
	ldrsb r1, [r0, r1]
	lsls r0, r1, 1
	adds r0, r1
	lsls r0, 24
	lsrs r5, r0, 24
	movs r3, 0
	b _080DDF4E
	.pool
_080DDF38:
	movs r7, 0
	lsls r0, r5, 24
	adds r4, r0, 0
	cmp r4, 0
	ble _080DDF48
	movs r5, 0
	movs r3, 0xC
	b _080DDF4C
_080DDF48:
	movs r5, 0xC
	movs r3, 0
_080DDF4C:
	ldr r2, =gContestResources
_080DDF4E:
	ldr r1, =gTasks
	lsls r0, r6, 2
	adds r0, r6
	lsls r0, 3
	adds r0, r1
	strh r7, [r0, 0x8]
	strh r5, [r0, 0xA]
	asrs r1, r4, 24
	strh r1, [r0, 0xC]
	strh r3, [r0, 0xE]
	ldr r0, [r2]
	ldr r2, [r0]
	ldrb r1, [r2, 0x7]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x7]
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDED0

	thumb_func_start sub_80DDF80
sub_80DDF80: @ 80DDF80
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r2, =gTasks
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	adds r3, r0, r2
	ldrh r0, [r3, 0x1C]
	adds r1, r0, 0x1
	strh r1, [r3, 0x1C]
	lsls r0, 16
	cmp r0, 0
	blt _080DDFFC
	movs r0, 0
	strh r0, [r3, 0x1C]
	movs r1, 0xC
	ldrsh r0, [r3, r1]
	cmp r0, 0
	ble _080DDFB4
	ldrh r0, [r3, 0xA]
	adds r0, 0x1
	b _080DDFB8
	.pool
_080DDFB4:
	ldrh r0, [r3, 0xA]
	subs r0, 0x1
_080DDFB8:
	strh r0, [r3, 0xA]
	lsls r4, r5, 2
	adds r4, r5
	lsls r4, 3
	adds r4, r2
	ldrb r2, [r4, 0xA]
	ldrh r3, [r4, 0x8]
	movs r0, 0x11
	movs r1, 0x1
	bl BlendPalette
	ldrb r2, [r4, 0xA]
	ldrh r3, [r4, 0x8]
	movs r0, 0x1A
	movs r1, 0x1
	bl BlendPalette
	movs r2, 0xA
	ldrsh r1, [r4, r2]
	movs r2, 0xE
	ldrsh r0, [r4, r2]
	cmp r1, r0
	bne _080DDFFC
	adds r0, r5, 0
	bl DestroyTask
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r1, [r2, 0x7]
	movs r0, 0x2
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x7]
_080DDFFC:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DDF80

	thumb_func_start sub_80DE008
sub_80DE008: @ 80DE008
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
	movs r5, 0
	ldr r0, =gContestResources
	mov r9, r0
	mov r8, r9
	ldr r6, =gSprites
	movs r4, 0
	movs r7, 0
_080DE026:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, 0x4]
	adds r0, r7, r0
	ldrb r1, [r0, 0x10]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0
	beq _080DE0BC
	mov r2, r10
	cmp r2, 0
	beq _080DE0BC
	lsls r0, r5, 24
	lsrs r0, 24
	bl sub_80DE0F0
	mov r3, r8
	ldr r1, [r3]
	ldr r1, [r1, 0x14]
	adds r1, r4, r1
	ldrb r2, [r1, 0x1]
	lsls r1, r2, 4
	adds r1, r2
	lsls r1, 2
	adds r1, r6
	ldrh r1, [r1, 0x4]
	lsls r1, 22
	lsrs r1, 17
	ldr r2, =0x060100c0
	adds r1, r2
	ldr r2, =0x04000008
	bl CpuSet
	mov r0, r8
	ldr r3, [r0]
	ldr r0, [r3, 0x14]
	adds r0, r4, r0
	ldrb r0, [r0, 0x1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	ldr r2, =gUnknown_08587A70
	ldr r0, =gUnknown_02039F26
	adds r0, r5, r0
	ldrb r0, [r0]
	adds r0, r2
	ldrb r0, [r0]
	strh r0, [r1, 0x22]
	ldr r0, [r3, 0x14]
	adds r0, r4, r0
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x5
	negs r3, r3
	adds r2, r3, 0
	ands r1, r2
	b _080DE0D6
	.pool
_080DE0BC:
	mov r1, r9
	ldr r0, [r1]
	ldr r0, [r0, 0x14]
	adds r0, r4, r0
	ldrb r1, [r0, 0x1]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r2, 0x4
	orrs r1, r2
_080DE0D6:
	strb r1, [r0]
	adds r4, 0x4
	adds r7, 0x1C
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DE026
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80DE008

	thumb_func_start sub_80DE0F0
sub_80DE0F0: @ 80DE0F0
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gContestResources
	ldr r1, [r1]
	ldr r2, [r1, 0x4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r2, r1, r2
	ldrb r1, [r2, 0x10]
	movs r0, 0xC0
	ands r0, r1
	cmp r0, 0x40
	bne _080DE120
	ldrb r0, [r2, 0x19]
	lsls r0, 5
	ldr r1, =gUnknown_08D8E9B4
	adds r0, r1
	b _080DE122
	.pool
_080DE120:
	ldr r0, =gUnknown_08D8EA34
_080DE122:
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DE0F0

	thumb_func_start sub_80DE12C
sub_80DE12C: @ 80DE12C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x10
	movs r7, 0
	movs r0, 0x2
	mov r10, r0
	movs r0, 0x1
	mov r8, r0
	movs r0, 0x11
	mov r9, r0
_080DE146:
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	adds r0, 0xD
	adds r0, r7
	ldrb r0, [r0]
	cmp r0, 0
	beq _080DE1CA
	lsls r0, r7, 24
	lsrs r0, 24
	bl Contest_IsMonsTurnDisabled
	lsls r0, 24
	cmp r0, 0
	bne _080DE1CA
	ldr r0, =gUnknown_02039F26
	adds r0, r7, r0
	ldrb r0, [r0]
	lsls r5, r0, 2
	adds r5, r0
	adds r6, r5, 0x2
	movs r0, 0x3
	bl sub_80DB748
	adds r4, r0, 0
	lsls r4, 16
	lsrs r4, 16
	lsls r6, 24
	lsrs r6, 24
	mov r0, r10
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	mov r0, r8
	str r0, [sp, 0xC]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x14
	adds r3, r6, 0
	bl ContestBG_FillBoxWithIncrementingTile
	adds r4, 0x10
	lsls r4, 16
	lsrs r4, 16
	adds r5, 0x3
	lsls r5, 24
	lsrs r5, 24
	mov r0, r10
	str r0, [sp]
	mov r0, r8
	str r0, [sp, 0x4]
	mov r0, r9
	str r0, [sp, 0x8]
	mov r0, r8
	str r0, [sp, 0xC]
	movs r0, 0
	adds r1, r4, 0
	movs r2, 0x14
	adds r3, r5, 0
	bl ContestBG_FillBoxWithIncrementingTile
	movs r0, 0x63
	bl PlaySE
_080DE1CA:
	adds r7, 0x1
	cmp r7, 0x3
	ble _080DE146
	add sp, 0x10
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE12C

	thumb_func_start sub_80DE1E8
sub_80DE1E8: @ 80DE1E8
	push {lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r1, =gContestResources
	ldr r1, [r1]
	ldr r2, [r1, 0x4]
	lsls r1, r0, 3
	subs r1, r0
	lsls r1, 2
	adds r2, r1, r2
	ldrb r1, [r2, 0x15]
	movs r3, 0x1
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	bne _080DE212
	ldrb r1, [r2, 0xC]
	adds r0, r3, 0
	ands r0, r1
	cmp r0, 0
	beq _080DE21C
_080DE212:
	movs r0, 0
	b _080DE21E
	.pool
_080DE21C:
	movs r0, 0x1
_080DE21E:
	pop {r1}
	bx r1
	thumb_func_end sub_80DE1E8

	thumb_func_start sub_80DE224
sub_80DE224: @ 80DE224
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0xC
	movs r0, 0xA
	bl GetGpuReg
	mov r1, sp
	strh r0, [r1]
	mov r2, sp
	ldrb r1, [r2]
	movs r4, 0x4
	negs r4, r4
	adds r0, r4, 0
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r2, 0x1]
	movs r0, 0x3F
	ands r0, r1
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0x1]
	ldrb r1, [r2, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x1]
	ldrb r1, [r2]
	movs r0, 0xD
	negs r0, r0
	mov r8, r0
	ands r0, r1
	strb r0, [r2]
	mov r0, sp
	ldrh r1, [r0]
	movs r0, 0xA
	bl SetGpuReg
	movs r0, 0x8
	bl GetGpuReg
	mov r6, sp
	adds r6, 0x2
	strh r0, [r6]
	movs r0, 0xC
	bl GetGpuReg
	add r5, sp, 0x4
	strh r0, [r5]
	ldrb r1, [r6]
	adds r0, r4, 0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r6]
	ldrb r0, [r5]
	ands r4, r0
	orrs r4, r1
	strb r4, [r5]
	ldrh r1, [r6]
	movs r0, 0x8
	bl SetGpuReg
	ldrh r1, [r5]
	movs r0, 0xC
	bl SetGpuReg
	ldr r1, =gBattle_BG1_X
	movs r0, 0xF0
	strh r0, [r1]
	ldr r4, =gBattle_BG1_Y
	movs r0, 0xA0
	strh r0, [r4]
	movs r0, 0x14
	movs r1, 0xF0
	bl SetGpuReg
	ldrh r1, [r4]
	movs r0, 0x16
	bl SetGpuReg
	movs r0, 0
	str r0, [sp, 0x8]
	add r0, sp, 0x8
	ldr r4, =gContestResources
	ldr r1, [r4]
	ldr r1, [r1, 0x28]
	ldr r2, =0x05000400
	bl CpuSet
	ldr r1, =gUnknown_08C17980
	movs r0, 0x1
	movs r2, 0
	movs r3, 0
	bl CopyToBgTilemapBuffer
	movs r0, 0x1
	bl Contest_SetBgCopyFlags
	movs r5, 0
	ldr r7, =gSprites
	movs r6, 0x4
_080DE2F0:
	ldr r0, [r4]
	ldr r0, [r0, 0x14]
	lsls r3, r5, 2
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x5]
	mov r0, r8
	ands r0, r2
	orrs r0, r6
	strb r0, [r1, 0x5]
	ldr r0, [r4]
	ldr r0, [r0, 0x14]
	adds r3, r0
	ldrb r0, [r3, 0x1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x5]
	mov r0, r8
	ands r0, r2
	orrs r0, r6
	strb r0, [r1, 0x5]
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DE2F0
	add sp, 0xC
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE224

	thumb_func_start sub_80DE350
sub_80DE350: @ 80DE350
	push {r4-r7,lr}
	sub sp, 0x8
	ldr r1, =0x06008000
	movs r2, 0x80
	lsls r2, 6
	movs r0, 0
	movs r3, 0x1
	bl RequestDma3Fill
	movs r5, 0
	str r5, [sp]
	ldr r6, =gContestResources
	ldr r0, [r6]
	ldr r1, [r0, 0x28]
	ldr r2, =0x05000400
	mov r0, sp
	bl CpuSet
	movs r0, 0x1
	bl Contest_SetBgCopyFlags
	movs r0, 0xA
	bl GetGpuReg
	add r3, sp, 0x4
	strh r0, [r3]
	ldrb r1, [r3]
	movs r0, 0x4
	negs r0, r0
	ands r0, r1
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r3]
	mov r1, sp
	adds r1, 0x5
	ldrb r2, [r1]
	movs r0, 0x3F
	ands r0, r2
	strb r0, [r1]
	ldrb r2, [r1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r2
	strb r0, [r1]
	ldrb r1, [r3]
	movs r4, 0xD
	negs r4, r4
	adds r0, r4, 0
	ands r0, r1
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r3]
	ldrh r1, [r3]
	movs r0, 0xA
	bl SetGpuReg
	ldr r0, =gBattle_BG1_X
	strh r5, [r0]
	ldr r0, =gBattle_BG1_Y
	strh r5, [r0]
	ldr r7, =gSprites
_080DE3CA:
	ldr r0, [r6]
	ldr r0, [r0, 0x14]
	lsls r3, r5, 2
	adds r0, r3, r0
	ldrb r0, [r0]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x5]
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1, 0x5]
	ldr r0, [r6]
	ldr r0, [r0, 0x14]
	adds r3, r0
	ldrb r0, [r3, 0x1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r7
	ldrb r2, [r1, 0x5]
	adds r0, r4, 0
	ands r0, r2
	strb r0, [r1, 0x5]
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DE3CA
	add sp, 0x8
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE350

	thumb_func_start sub_80DE424
sub_80DE424: @ 80DE424
	push {r4,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r1, =gBattle_BG1_X
	movs r0, 0
	strh r0, [r1]
	ldr r1, =gBattle_BG1_Y
	movs r0, 0xA0
	strh r0, [r1]
	movs r0, 0x62
	movs r1, 0
	bl PlaySE12WithPanning
	ldr r1, =gTasks
	lsls r0, r4, 2
	adds r0, r4
	lsls r0, 3
	adds r0, r1
	ldr r1, =sub_80DE464
	str r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE424

	thumb_func_start sub_80DE464
sub_80DE464: @ 80DE464
	push {lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r1, =gBattle_BG1_Y
	ldrh r0, [r1]
	subs r0, 0x7
	strh r0, [r1]
	lsls r0, 16
	cmp r0, 0
	bge _080DE47C
	movs r0, 0
	strh r0, [r1]
_080DE47C:
	ldrh r2, [r1]
	cmp r2, 0
	bne _080DE496
	ldr r0, =gTasks
	lsls r1, r3, 2
	adds r1, r3
	lsls r1, 3
	adds r1, r0
	strh r2, [r1, 0x8]
	strh r2, [r1, 0xA]
	strh r2, [r1, 0xC]
	ldr r0, =sub_80DE4A8
	str r0, [r1]
_080DE496:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE464

	thumb_func_start sub_80DE4A8
sub_80DE4A8: @ 80DE4A8
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r1, =gTasks
	lsls r3, r4, 2
	adds r0, r3, r4
	lsls r0, 3
	adds r5, r0, r1
	movs r0, 0x8
	ldrsh r1, [r5, r0]
	cmp r1, 0x1
	beq _080DE52C
	cmp r1, 0x1
	bgt _080DE4D0
	cmp r1, 0
	beq _080DE4DA
	b _080DE5B4
	.pool
_080DE4D0:
	cmp r1, 0x2
	beq _080DE58A
	cmp r1, 0x3
	beq _080DE5A4
	b _080DE5B4
_080DE4DA:
	movs r2, 0
	adds r6, r3, 0
	ldr r5, =gContestResources
	ldr r3, =gUnknown_02039F26
_080DE4E2:
	ldr r0, [r5]
	ldr r1, [r0]
	adds r1, 0x14
	adds r1, r2
	adds r0, r2, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r2, 0x1
	cmp r2, 0x3
	ble _080DE4E2
	bl sub_80DBF90
	bl sub_80DC864
	bl sub_80DB69C
	bl sub_80DD04C
	movs r0, 0x1
	bl sub_80DE008
	bl sub_80DC44C
	ldr r0, =gTasks
	adds r1, r6, r4
	lsls r1, 3
	adds r1, r0
	movs r0, 0x1
	strh r0, [r1, 0x8]
	b _080DE5B4
	.pool
_080DE52C:
	ldr r0, =gIsLinkContest
	ldrb r0, [r0]
	ands r1, r0
	cmp r1, 0
	beq _080DE584
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, 0x7]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0x7]
	bl sub_80DA8A4
	lsls r0, 24
	cmp r0, 0
	beq _080DE552
	bl sub_80DBAA0
_080DE552:
	ldr r4, =sub_80FCC88
	adds r0, r4, 0
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =sub_80DA110
	adds r1, r4, 0
	bl SetTaskFuncWithFollowupFunc
	bl sub_80DBF68
	movs r0, 0x2
	strh r0, [r5, 0x8]
	b _080DE5B4
	.pool
_080DE584:
	bl sub_80DBAA0
	b _080DE59A
_080DE58A:
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0]
	ldrb r1, [r0, 0x7]
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	bne _080DE5B4
_080DE59A:
	movs r0, 0x3
	strh r0, [r5, 0x8]
	b _080DE5B4
	.pool
_080DE5A4:
	bl sub_80DB884
	bl sub_80DB2BC
	movs r0, 0
	strh r0, [r5, 0x8]
	ldr r0, =sub_80DE5F4
	str r0, [r5]
_080DE5B4:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE4A8

	thumb_func_start sub_80DE5C0
sub_80DE5C0: @ 80DE5C0
	push {lr}
	lsls r0, 24
	lsrs r2, r0, 24
	ldr r1, =gBattle_BG1_Y
	ldrh r0, [r1]
	adds r0, 0x7
	strh r0, [r1]
	lsls r0, 16
	asrs r0, 16
	cmp r0, 0xA0
	ble _080DE5E4
	ldr r0, =gTasks
	lsls r1, r2, 2
	adds r1, r2
	lsls r1, 3
	adds r1, r0
	ldr r0, =sub_80DA4F4
	str r0, [r1]
_080DE5E4:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE5C0

	thumb_func_start sub_80DE5F4
sub_80DE5F4: @ 80DE5F4
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	ldrh r2, [r1, 0xC]
	movs r3, 0xC
	ldrsh r0, [r1, r3]
	cmp r0, 0x9
	bgt _080DE618
	adds r0, r2, 0x1
	strh r0, [r1, 0xC]
	b _080DE654
	.pool
_080DE618:
	ldrh r3, [r1, 0xA]
	movs r4, 0xA
	ldrsh r0, [r1, r4]
	cmp r0, 0
	bne _080DE636
	ldrh r2, [r1, 0x8]
	movs r4, 0x8
	ldrsh r0, [r1, r4]
	cmp r0, 0x10
	bne _080DE632
	adds r0, r3, 0x1
	strh r0, [r1, 0xA]
	b _080DE654
_080DE632:
	adds r0, r2, 0x1
	b _080DE652
_080DE636:
	ldrh r0, [r1, 0x8]
	movs r3, 0x8
	ldrsh r2, [r1, r3]
	cmp r2, 0
	bne _080DE650
	strh r2, [r1, 0xA]
	strh r2, [r1, 0xC]
	ldr r0, =sub_80DE65C
	str r0, [r1]
	b _080DE654
	.pool
_080DE650:
	subs r0, 0x1
_080DE652:
	strh r0, [r1, 0x8]
_080DE654:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80DE5F4

	thumb_func_start sub_80DE65C
sub_80DE65C: @ 80DE65C
	push {r4,lr}
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r4, r1, r2
	ldrh r1, [r4, 0xC]
	movs r2, 0xC
	ldrsh r0, [r4, r2]
	cmp r0, 0x9
	bgt _080DE680
	adds r0, r1, 0x1
	strh r0, [r4, 0xC]
	b _080DE690
	.pool
_080DE680:
	movs r0, 0
	strh r0, [r4, 0xC]
	movs r0, 0x61
	movs r1, 0
	bl PlaySE12WithPanning
	ldr r0, =sub_80DE5C0
	str r0, [r4]
_080DE690:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE65C

	thumb_func_start sub_80DE69C
sub_80DE69C: @ 80DE69C
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r7, 0
	ldr r6, =gSprites
	ldr r5, =gContestResources
_080DE6AE:
	bl AllocOamMatrix
	ldr r1, [r5]
	ldr r1, [r1, 0x14]
	lsls r4, r7, 2
	adds r1, r4, r1
	ldrb r1, [r1]
	lsls r3, r1, 4
	adds r3, r1
	lsls r3, 2
	adds r3, r6
	lsls r0, 24
	lsrs r0, 24
	movs r1, 0x1F
	ands r0, r1
	lsls r0, 1
	ldrb r1, [r3, 0x3]
	movs r2, 0x3F
	negs r2, r2
	mov r12, r2
	mov r2, r12
	ands r1, r2
	orrs r1, r0
	strb r1, [r3, 0x3]
	ldr r0, [r5]
	ldr r0, [r0, 0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	ldrb r2, [r0, 0x1]
	movs r3, 0x4
	negs r3, r3
	adds r1, r3, 0
	ands r2, r1
	movs r1, 0x1
	orrs r2, r1
	strb r2, [r0, 0x1]
	ldr r0, [r5]
	ldr r0, [r0, 0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	mov r1, r8
	bl StartSpriteAffineAnim
	mov r0, r8
	cmp r0, 0x2
	bne _080DE74C
	ldr r0, [r5]
	ldr r0, [r0, 0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	bl AnimateSprite
	ldr r0, [r5]
	ldr r0, [r0, 0x14]
	adds r0, r4, r0
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x3E
	ldrb r1, [r0]
	movs r3, 0x5
	negs r3, r3
	adds r2, r3, 0
	ands r1, r2
	strb r1, [r0]
_080DE74C:
	adds r7, 0x1
	cmp r7, 0x3
	ble _080DE6AE
	ldr r0, =sub_80DE794
	movs r1, 0x5
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	ldr r2, =gTasks
	lsls r1, r0, 2
	adds r1, r0
	lsls r1, 3
	adds r1, r2
	mov r0, r8
	strh r0, [r1, 0x8]
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r2, [r0]
	ldrb r0, [r2, 0x7]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0x7]
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE69C

	thumb_func_start sub_80DE794
sub_80DE794: @ 80DE794
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	ldr r2, =gSprites
	ldr r3, =gContestResources
	ldr r0, [r3]
	ldr r0, [r0, 0x14]
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	adds r0, 0x3F
	ldrb r0, [r0]
	lsls r0, 26
	cmp r0, 0
	bge _080DE822
	ldr r0, =gTasks
	lsls r1, r6, 2
	adds r1, r6
	lsls r1, 3
	adds r1, r0
	ldrb r0, [r1, 0x8]
	cmp r0, 0x1
	bne _080DE7EC
	movs r4, 0
	adds r5, r2, 0
	movs r2, 0x4
_080DE7CC:
	ldr r0, [r3]
	ldr r1, [r0, 0x14]
	lsls r0, r4, 2
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r5
	adds r0, 0x3E
	ldrb r1, [r0]
	orrs r1, r2
	strb r1, [r0]
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DE7CC
_080DE7EC:
	movs r4, 0
_080DE7EE:
	ldr r5, =gContestResources
	ldr r0, [r5]
	ldr r1, [r0, 0x14]
	lsls r0, r4, 2
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl FreeSpriteOamMatrix
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DE7EE
	ldr r0, [r5]
	ldr r2, [r0]
	ldrb r1, [r2, 0x7]
	movs r0, 0x3
	negs r0, r0
	ands r0, r1
	strb r0, [r2, 0x7]
	adds r0, r6, 0
	bl DestroyTask
_080DE822:
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE794

	thumb_func_start sub_80DE834
sub_80DE834: @ 80DE834
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	movs r0, 0xB1
	lsls r0, 1
	cmp r1, r0
	bls _080DE844
	movs r1, 0x1
_080DE844:
	adds r0, r1, 0
	pop {r1}
	bx r1
	thumb_func_end sub_80DE834

	thumb_func_start sub_80DE84C
sub_80DE84C: @ 80DE84C
	push {lr}
	lsls r0, 16
	lsrs r1, r0, 16
	ldr r0, =0x0000019b
	cmp r1, r0
	bls _080DE85A
	movs r1, 0
_080DE85A:
	adds r0, r1, 0
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DE84C

	thumb_func_start sub_80DE864
sub_80DE864: @ 80DE864
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r7, r0, 24
	ldr r4, =gContestResources
	ldr r0, [r4]
	ldr r1, [r0, 0x4]
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r1
	ldrh r0, [r0, 0x6]
	bl sub_80DE834
	lsls r0, 16
	lsrs r5, r0, 16
	ldr r1, =gContestMons
	lsls r0, r7, 6
	adds r0, r1
	ldrh r0, [r0]
	bl sub_80DE84C
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	movs r1, 0
	movs r2, 0x14
	bl memset
	bl ClearBattleAnimationVars
	ldr r1, =gBattleMonForms
	movs r2, 0
	adds r0, r1, 0x3
_080DE8A8:
	strb r2, [r0]
	subs r0, 0x1
	cmp r0, r1
	bge _080DE8A8
	cmp r5, 0x90
	beq _080DE920
	cmp r5, 0x90
	bgt _080DE8DE
	cmp r5, 0x4C
	beq _080DE978
	cmp r5, 0x4C
	bgt _080DE8D4
	cmp r5, 0xD
	beq _080DE978
	b _080DE9A2
	.pool
_080DE8D4:
	cmp r5, 0x82
	beq _080DE978
	cmp r5, 0x8F
	beq _080DE978
	b _080DE9A2
_080DE8DE:
	cmp r5, 0xD8
	beq _080DE960
	cmp r5, 0xD8
	bgt _080DE8EC
	cmp r5, 0xAE
	beq _080DE8FA
	b _080DE9A2
_080DE8EC:
	cmp r5, 0xDA
	beq _080DE96C
	movs r0, 0x88
	lsls r0, 1
	cmp r5, r0
	beq _080DE920
	b _080DE9A2
_080DE8FA:
	ldr r0, =gBaseStats
	lsls r1, r6, 3
	subs r1, r6
	lsls r1, 2
	adds r1, r0
	ldrb r0, [r1, 0x6]
	cmp r0, 0x7
	beq _080DE910
	ldrb r0, [r1, 0x7]
	cmp r0, 0x7
	bne _080DE99C
_080DE910:
	ldr r1, =gAnimMoveTurn
	movs r0, 0
	b _080DE9A0
	.pool
_080DE920:
	ldr r6, =gContestResources
	ldr r0, [r6]
	ldr r1, [r0, 0x4]
	lsls r0, r7, 3
	subs r0, r7
	lsls r0, 2
	adds r0, r1
	ldrb r4, [r0, 0x1B]
	ldr r5, =gContestMons
	lsls r4, 6
	adds r0, r4, r5
	ldrh r0, [r0]
	bl sub_80DE84C
	ldr r2, [r6]
	ldr r1, [r2, 0x18]
	strh r0, [r1, 0x2]
	ldr r2, [r2, 0x18]
	adds r5, 0x38
	adds r4, r5
	ldr r0, [r4]
	str r0, [r2, 0x10]
	ldrb r0, [r2, 0x4]
	movs r1, 0x1
	orrs r0, r1
	strb r0, [r2, 0x4]
	b _080DE9A2
	.pool
_080DE960:
	ldr r1, =gAnimFriendship
	movs r0, 0xFF
	b _080DE9A0
	.pool
_080DE96C:
	ldr r1, =gAnimFriendship
	movs r0, 0
	b _080DE9A0
	.pool
_080DE978:
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0]
	adds r2, r0, 0
	adds r2, 0x5A
	ldrb r1, [r2]
	cmp r1, 0
	bne _080DE99C
	movs r0, 0x2
	strb r0, [r2]
	ldr r0, =gAnimMoveTurn
	strb r1, [r0]
	b _080DE9A2
	.pool
_080DE99C:
	ldr r1, =gAnimMoveTurn
	movs r0, 0x1
_080DE9A0:
	strb r0, [r1]
_080DE9A2:
	bl sub_80DEA5C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE864

	thumb_func_start sub_80DE9B0
sub_80DE9B0: @ 80DE9B0
	push {r4,lr}
	ldr r4, =gContestResources
	ldr r0, [r4]
	ldr r0, [r0, 0x18]
	movs r1, 0
	movs r2, 0x14
	bl memset
	ldr r0, [r4]
	ldr r0, [r0]
	adds r1, r0, 0
	adds r1, 0x5A
	ldrb r0, [r1]
	cmp r0, 0
	beq _080DE9D2
	subs r0, 0x1
	strb r0, [r1]
_080DE9D2:
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE9B0

	thumb_func_start sub_80DE9DC
sub_80DE9DC: @ 80DE9DC
	push {r4-r6,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r6, =gContestResources
	ldr r0, [r6]
	ldr r0, [r0, 0x18]
	strb r4, [r0, 0x5]
	ldr r5, =gContestMons
	lsls r4, 6
	adds r0, r4, r5
	ldrh r0, [r0]
	bl sub_80DE84C
	ldr r2, [r6]
	ldr r1, [r2, 0x18]
	strh r0, [r1]
	ldr r1, [r2, 0x18]
	adds r0, r5, 0
	adds r0, 0x38
	adds r0, r4, r0
	ldr r0, [r0]
	str r0, [r1, 0x8]
	adds r5, 0x3C
	adds r4, r5
	ldr r0, [r4]
	str r0, [r1, 0xC]
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DE9DC

	thumb_func_start sub_80DEA20
sub_80DEA20: @ 80DEA20
	push {lr}
	ldr r0, =SpriteCallbackDummy
	bl CreateInvisibleSpriteWithCallback
	ldr r1, =gBattlerSpriteIds
	strb r0, [r1, 0x3]
	ldr r0, =gBattlerTarget
	ldrb r0, [r0]
	adds r0, r1
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl InitSpriteAffineAnim
	bl sub_80DEA5C
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DEA20

	thumb_func_start sub_80DEA5C
sub_80DEA5C: @ 80DEA5C
	push {r4,lr}
	ldr r0, =gBattlerSpriteIds
	ldrb r0, [r0, 0x3]
	lsls r4, r0, 4
	adds r4, r0
	lsls r4, 2
	ldr r0, =gSprites
	adds r4, r0
	movs r0, 0
	strh r0, [r4, 0x24]
	strh r0, [r4, 0x26]
	movs r0, 0x3
	movs r1, 0
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x20]
	movs r0, 0x3
	movs r1, 0x1
	bl GetBattlerSpriteCoord
	lsls r0, 24
	lsrs r0, 24
	strh r0, [r4, 0x22]
	adds r4, 0x3E
	ldrb r0, [r4]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DEA5C

	thumb_func_start sub_80DEAA8
sub_80DEAA8: @ 80DEAA8
	push {lr}
	lsls r0, 16
	lsrs r0, 16
	ldr r2, =gBattleMoves
	lsls r1, r0, 1
	adds r1, r0
	lsls r1, 2
	adds r1, r2
	ldrb r0, [r1, 0x6]
	cmp r0, 0x20
	bhi _080DEB60
	lsls r0, 2
	ldr r1, =_080DEAD0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080DEAD0:
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB54
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB54
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
	.4byte _080DEB60
_080DEB54:
	ldr r1, =gBattlerTarget
	movs r0, 0x2
	b _080DEB64
	.pool
_080DEB60:
	ldr r1, =gBattlerTarget
	movs r0, 0x3
_080DEB64:
	strb r0, [r1]
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DEAA8

	thumb_func_start Contest_PrintTextToBg0WindowStd
Contest_PrintTextToBg0WindowStd: @ 80DEB70
	push {r4,lr}
	sub sp, 0x10
	adds r4, r0, 0
	str r1, [sp]
	mov r0, sp
	movs r2, 0
	strb r4, [r0, 0x4]
	movs r1, 0x1
	strb r1, [r0, 0x5]
	strb r2, [r0, 0x6]
	strb r1, [r0, 0x7]
	strb r2, [r0, 0x8]
	strb r1, [r0, 0x9]
	strb r2, [r0, 0xA]
	strb r2, [r0, 0xB]
	mov r3, sp
	ldrb r2, [r3, 0xC]
	subs r1, 0x11
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0xC]
	mov r2, sp
	movs r0, 0xF0
	strb r0, [r2, 0xC]
	ldrb r0, [r2, 0xD]
	ands r1, r0
	strb r1, [r2, 0xD]
	mov r1, sp
	movs r0, 0x80
	strb r0, [r1, 0xD]
	mov r0, sp
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	lsls r4, 24
	lsrs r4, 24
	adds r0, r4, 0
	bl PutWindowTilemap
	movs r0, 0
	bl Contest_SetBgCopyFlags
	add sp, 0x10
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end Contest_PrintTextToBg0WindowStd

	thumb_func_start Contest_PrintTextToBg0WindowAt
Contest_PrintTextToBg0WindowAt: @ 80DEBD0
	push {r4,r5,lr}
	sub sp, 0x10
	adds r5, r0, 0
	ldr r4, [sp, 0x1C]
	str r1, [sp]
	mov r0, sp
	movs r1, 0
	strb r5, [r0, 0x4]
	strb r4, [r0, 0x5]
	strb r2, [r0, 0x6]
	strb r3, [r0, 0x7]
	strb r2, [r0, 0x8]
	strb r3, [r0, 0x9]
	strb r1, [r0, 0xA]
	strb r1, [r0, 0xB]
	mov r3, sp
	ldrb r2, [r3, 0xC]
	subs r1, 0x10
	adds r0, r1, 0
	ands r0, r2
	strb r0, [r3, 0xC]
	mov r2, sp
	movs r0, 0xF0
	strb r0, [r2, 0xC]
	ldrb r0, [r2, 0xD]
	ands r1, r0
	strb r1, [r2, 0xD]
	mov r1, sp
	movs r0, 0x80
	strb r0, [r1, 0xD]
	mov r0, sp
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	lsls r5, 24
	lsrs r5, 24
	adds r0, r5, 0
	bl PutWindowTilemap
	movs r0, 0
	bl Contest_SetBgCopyFlags
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end Contest_PrintTextToBg0WindowAt

	thumb_func_start Contest_StartTextPrinter
Contest_StartTextPrinter: @ 80DEC30
	push {r4,r5,lr}
	sub sp, 0x10
	str r0, [sp]
	mov r2, sp
	movs r3, 0
	movs r0, 0x4
	strb r0, [r2, 0x4]
	mov r0, sp
	movs r5, 0x1
	strb r5, [r0, 0x5]
	strb r3, [r0, 0x6]
	strb r5, [r0, 0x7]
	strb r3, [r0, 0x8]
	strb r5, [r0, 0x9]
	strb r3, [r0, 0xA]
	strb r3, [r0, 0xB]
	mov r4, sp
	ldrb r3, [r4, 0xC]
	movs r2, 0x10
	negs r2, r2
	adds r0, r2, 0
	ands r0, r3
	strb r0, [r4, 0xC]
	mov r3, sp
	movs r0, 0x10
	strb r0, [r3, 0xC]
	ldrb r0, [r3, 0xD]
	ands r2, r0
	strb r2, [r3, 0xD]
	mov r2, sp
	movs r0, 0x80
	strb r0, [r2, 0xD]
	cmp r1, 0
	bne _080DEC80
	mov r0, sp
	movs r1, 0
	movs r2, 0
	bl AddTextPrinter
	b _080DECA4
_080DEC80:
	ldr r0, =gIsLinkContest
	ldrb r1, [r0]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080DEC94
	movs r1, 0x4
	b _080DEC9C
	.pool
_080DEC94:
	bl GetPlayerTextSpeedDelay
	lsls r0, 24
	lsrs r1, r0, 24
_080DEC9C:
	mov r0, sp
	movs r2, 0
	bl AddTextPrinter
_080DECA4:
	movs r0, 0x4
	bl PutWindowTilemap
	movs r0, 0
	bl Contest_SetBgCopyFlags
	add sp, 0x10
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end Contest_StartTextPrinter

	thumb_func_start ContestBG_FillBoxWithIncrementingTile
ContestBG_FillBoxWithIncrementingTile: @ 80DECB8
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	sub sp, 0x10
	mov r8, r0
	ldr r0, [sp, 0x28]
	ldr r4, [sp, 0x2C]
	ldr r5, [sp, 0x30]
	ldr r6, [sp, 0x34]
	mov r7, r8
	lsls r7, 24
	lsrs r7, 24
	mov r8, r7
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r0, 24
	lsrs r0, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	str r0, [sp]
	str r4, [sp, 0x4]
	str r5, [sp, 0x8]
	lsls r6, 16
	asrs r6, 16
	str r6, [sp, 0xC]
	mov r0, r8
	bl WriteSequenceToBgTilemapBuffer
	mov r0, r8
	bl Contest_SetBgCopyFlags
	add sp, 0x10
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end ContestBG_FillBoxWithIncrementingTile

	thumb_func_start ContestBG_FillBoxWithTile
ContestBG_FillBoxWithTile: @ 80DED10
	push {r4-r6,lr}
	sub sp, 0x10
	ldr r4, [sp, 0x20]
	ldr r5, [sp, 0x24]
	ldr r6, [sp, 0x28]
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 16
	lsrs r1, 16
	lsls r2, 24
	lsrs r2, 24
	lsls r3, 24
	lsrs r3, 24
	lsls r4, 24
	lsrs r4, 24
	lsls r5, 24
	lsrs r5, 24
	lsls r6, 24
	lsrs r6, 24
	str r4, [sp]
	str r5, [sp, 0x4]
	str r6, [sp, 0x8]
	movs r4, 0
	str r4, [sp, 0xC]
	bl ContestBG_FillBoxWithIncrementingTile
	add sp, 0x10
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end ContestBG_FillBoxWithTile

	thumb_func_start Contest_RunTextPrinters
Contest_RunTextPrinters: @ 80DED4C
	push {lr}
	bl RunTextPrinters
	movs r0, 0x4
	bl IsTextPrinterActive
	lsls r0, 16
	lsrs r0, 16
	pop {r1}
	bx r1
	thumb_func_end Contest_RunTextPrinters

	thumb_func_start Contest_SetBgCopyFlags
Contest_SetBgCopyFlags: @ 80DED60
	ldr r2, =sContestBgCopyFlags
	movs r1, 0x1
	lsls r1, r0
	ldrb r0, [r2]
	orrs r1, r0
	strb r1, [r2]
	bx lr
	.pool
	thumb_func_end Contest_SetBgCopyFlags

	thumb_func_start ResetContestLinkResults
ResetContestLinkResults: @ 80DED74
	push {r4-r6,lr}
	movs r0, 0
	ldr r6, =gSaveBlock2Ptr
	ldr r5, =0x00000624
	movs r4, 0
_080DED7E:
	adds r3, r0, 0x1
	lsls r1, r0, 3
	movs r2, 0x3
_080DED84:
	ldr r0, [r6]
	adds r0, r5
	adds r0, r1
	strh r4, [r0]
	adds r1, 0x2
	subs r2, 0x1
	cmp r2, 0
	bge _080DED84
	adds r0, r3, 0
	cmp r0, 0x4
	ble _080DED7E
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ResetContestLinkResults

	thumb_func_start sub_80DEDA8
sub_80DEDA8: @ 80DEDA8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	lsls r0, 24
	lsrs r0, 24
	str r0, [sp]
	bl Random
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x3
	bl __umodsi3
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	movs r5, 0
	ldr r1, =gContestFinalStandings
	ldrb r0, [r1]
	cmp r0, 0
	beq _080DEDE6
_080DEDD8:
	adds r5, 0x1
	cmp r5, 0x2
	bgt _080DEDE6
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DEDD8
_080DEDE6:
	ldr r0, [sp]
	cmp r0, 0xFF
	bne _080DEE00
	ldr r0, =gContestPlayerMonIndex
	ldrb r0, [r0]
	cmp r5, r0
	beq _080DEE00
	movs r0, 0
	b _080DEF90
	.pool
_080DEE00:
	ldr r0, =gSpecialVar_ContestCategory
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _080DEE4C
	lsls r0, 2
	ldr r1, =_080DEE1C
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080DEE1C:
	.4byte _080DEE4C
	.4byte _080DEE30
	.4byte _080DEE36
	.4byte _080DEE3C
	.4byte _080DEE42
_080DEE30:
	mov r0, r8
	adds r0, 0x3
	b _080DEE46
_080DEE36:
	mov r0, r8
	adds r0, 0x6
	b _080DEE46
_080DEE3C:
	mov r0, r8
	adds r0, 0x9
	b _080DEE46
_080DEE42:
	mov r0, r8
	adds r0, 0xC
_080DEE46:
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
_080DEE4C:
	ldr r1, [sp]
	cmp r1, 0xFE
	bne _080DEE54
	b _080DEF50
_080DEE54:
	adds r0, r1, 0
	movs r1, 0x1
	bl sub_80DEFA8
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
	ldr r2, =gSaveBlock1Ptr
	mov r10, r2
	ldr r0, [r2]
	mov r3, r9
	lsls r7, r3, 5
	ldr r6, =0x00002e90
	adds r2, r0, r6
	adds r2, r7
	ldr r4, =gContestMons
	lsls r5, 6
	adds r1, r4, 0
	adds r1, 0x38
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r2]
	adds r1, r0, r7
	adds r2, r5, r4
	ldrh r2, [r2]
	ldr r3, =0x00002e98
	adds r1, r3
	strh r2, [r1]
	ldr r1, =0x00002e94
	adds r2, r0, r1
	adds r2, r7
	adds r1, r4, 0
	adds r1, 0x3C
	adds r1, r5, r1
	ldr r1, [r1]
	str r1, [r2]
	adds r6, r7, r6
	adds r0, r6
	adds r0, 0xB
	adds r1, r4, 0x2
	adds r1, r5, r1
	bl StringCopy
	mov r2, r10
	ldr r0, [r2]
	adds r0, r6
	adds r0, 0x16
	adds r4, 0xD
	adds r5, r4
	adds r1, r5, 0
	bl StringCopy
	ldr r0, =gIsLinkContest
	ldrb r1, [r0]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080DEEF4
	mov r3, r10
	ldr r0, [r3]
	adds r0, r7
	ldr r1, =0x00002eae
	adds r0, r1
	movs r1, 0x4
	b _080DEF02
	.pool
_080DEEF4:
	mov r2, r10
	ldr r0, [r2]
	adds r0, r7
	ldr r1, =gSpecialVar_ContestRank
	ldrh r1, [r1]
	ldr r3, =0x00002eae
	adds r0, r3
_080DEF02:
	strb r1, [r0]
	ldr r0, [sp]
	cmp r0, 0xFF
	beq _080DEF34
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	mov r2, r9
	lsls r1, r2, 5
	adds r0, r1
	ldr r1, =gSpecialVar_ContestCategory
	ldrh r1, [r1]
	ldr r3, =0x00002e9a
	adds r0, r3
	strb r1, [r0]
	b _080DEF8E
	.pool
_080DEF34:
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	mov r2, r9
	lsls r1, r2, 5
	adds r0, r1
	ldr r3, =0x00002e9a
	adds r0, r3
	mov r1, r8
	strb r1, [r0]
	b _080DEF8E
	.pool
_080DEF50:
	ldr r6, =gUnknown_02039F3C
	ldr r4, =gContestMons
	lsls r5, 6
	adds r0, r4, 0
	adds r0, 0x38
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [r6]
	adds r0, r4, 0
	adds r0, 0x3C
	adds r0, r5, r0
	ldr r0, [r0]
	str r0, [r6, 0x4]
	adds r0, r5, r4
	ldrh r0, [r0]
	strh r0, [r6, 0x8]
	adds r0, r6, 0
	adds r0, 0xB
	adds r1, r4, 0x2
	adds r1, r5, r1
	bl StringCopy
	adds r0, r6, 0
	adds r0, 0x16
	adds r4, 0xD
	adds r5, r4
	adds r1, r5, 0
	bl StringCopy
	mov r2, r8
	strb r2, [r6, 0xA]
_080DEF8E:
	movs r0, 0x1
_080DEF90:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_80DEDA8

	thumb_func_start sub_80DEFA8
sub_80DEFA8: @ 80DEFA8
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	lsls r1, 24
	lsrs r1, 24
	cmp r0, 0x3
	bgt _080DEFF8
	cmp r0, 0
	blt _080DEFF8
	cmp r1, 0
	beq _080DEFE6
	movs r2, 0x5
	ldr r0, =gSaveBlock1Ptr
	mov r12, r0
	ldr r4, =0x00002e90
	ldr r3, =0x00002e70
_080DEFC8:
	mov r1, r12
	ldr r0, [r1]
	lsls r1, r2, 5
	adds r1, r0
	adds r0, r1, r4
	adds r1, r3
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5,r6}
	stm r0!, {r5,r6}
	subs r2, 0x1
	cmp r2, 0
	bgt _080DEFC8
_080DEFE6:
	movs r0, 0
	b _080DF03A
	.pool
_080DEFF8:
	ldr r0, =gSpecialVar_ContestCategory
	ldrh r0, [r0]
	cmp r0, 0x4
	bhi _080DF038
	lsls r0, 2
	ldr r1, =_080DF014
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_080DF014:
	.4byte _080DF028
	.4byte _080DF02C
	.4byte _080DF030
	.4byte _080DF034
	.4byte _080DF038
_080DF028:
	movs r0, 0x8
	b _080DF03A
_080DF02C:
	movs r0, 0x9
	b _080DF03A
_080DF030:
	movs r0, 0xA
	b _080DF03A
_080DF034:
	movs r0, 0xB
	b _080DF03A
_080DF038:
	movs r0, 0xC
_080DF03A:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_80DEFA8

	thumb_func_start ClearContestWinnerPicsInContestHall
ClearContestWinnerPicsInContestHall: @ 80DF040
	push {r4-r7,lr}
	movs r2, 0
	ldr r0, =gSaveBlock1Ptr
	mov r12, r0
	ldr r4, =0x00002e90
	ldr r3, =gUnknown_08587FA4
_080DF04C:
	mov r1, r12
	ldr r0, [r1]
	lsls r1, r2, 5
	adds r0, r1
	adds r0, r4
	adds r1, r3, 0
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5-r7}
	stm r0!, {r5-r7}
	ldm r1!, {r5,r6}
	stm r0!, {r5,r6}
	adds r3, 0x20
	adds r2, 0x1
	cmp r2, 0x7
	ble _080DF04C
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end ClearContestWinnerPicsInContestHall

	thumb_func_start sub_80DF080
sub_80DF080: @ 80DF080
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r4, r0, 24
	ldr r2, =gContestResources
	ldr r3, [r2]
	ldr r5, [r3, 0x10]
	ldrb r1, [r5, 0x1]
	movs r7, 0x1
	adds r0, r7, 0
	ands r0, r1
	adds r6, r2, 0
	cmp r0, 0
	bne _080DF0D2
	movs r0, 0
	ldrsb r0, [r5, r0]
	cmp r0, 0
	ble _080DF0D2
	ldr r1, [r3, 0x4]
	lsls r0, r4, 3
	subs r0, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x15]
	adds r0, r7, 0
	ands r0, r1
	cmp r0, 0
	bne _080DF0D2
	ldr r1, [r3, 0x1C]
	lsls r2, r4, 4
	adds r1, r2, r1
	ldrb r3, [r1, 0xC]
	movs r0, 0x1
	orrs r0, r3
	strb r0, [r1, 0xC]
	ldr r0, [r6]
	ldr r0, [r0, 0x1C]
	adds r2, r0
	ldrb r0, [r2, 0xE]
	movs r1, 0x2
	orrs r0, r1
	strb r0, [r2, 0xE]
_080DF0D2:
	ldr r3, [r6]
	ldr r1, [r3, 0x4]
	lsls r2, r4, 3
	subs r0, r2, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0xC]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	adds r7, r2, 0
	cmp r0, 0
	beq _080DF0FA
	ldr r0, [r3, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xC]
	movs r0, 0x2
	orrs r0, r2
	strb r0, [r1, 0xC]
_080DF0FA:
	ldr r3, [r6]
	ldr r2, [r3, 0x10]
	ldrb r1, [r2, 0x1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _080DF126
	movs r0, 0
	ldrsb r0, [r2, r0]
	cmp r0, 0
	beq _080DF126
	movs r0, 0x2
	ldrsb r0, [r2, r0]
	cmp r0, 0x3C
	bne _080DF126
	ldr r0, [r3, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xC]
	movs r0, 0x4
	orrs r0, r2
	strb r0, [r1, 0xC]
_080DF126:
	ldr r3, [r6]
	ldr r1, [r3, 0x4]
	subs r0, r7, r4
	lsls r0, 2
	adds r2, r0, r1
	ldrb r1, [r2, 0x15]
	movs r0, 0x40
	ands r0, r1
	cmp r0, 0
	beq _080DF14E
	ldrb r0, [r2, 0x16]
	cmp r0, 0
	beq _080DF14E
	ldr r0, [r3, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xC]
	movs r0, 0x8
	orrs r0, r2
	strb r0, [r1, 0xC]
_080DF14E:
	movs r3, 0
	movs r5, 0
_080DF152:
	cmp r3, r4
	beq _080DF180
	ldr r1, [r6]
	ldr r0, [r1, 0x4]
	adds r0, r5, r0
	ldrb r0, [r0, 0xE]
	cmp r0, 0
	beq _080DF180
	ldr r0, [r1, 0x1C]
	lsls r2, r4, 4
	adds r2, r0
	ldrb r0, [r2, 0xC]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r2, 0xC]
	ldr r0, [r6]
	ldr r0, [r0, 0x1C]
	lsls r2, r3, 4
	adds r2, r0
	ldrb r0, [r2, 0xC]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2, 0xC]
_080DF180:
	adds r5, 0x1C
	adds r3, 0x1
	cmp r3, 0x3
	ble _080DF152
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	subs r0, r7, r4
	lsls r5, r0, 2
	adds r1, r5, r1
	ldrb r3, [r1, 0xC]
	movs r0, 0x6
	ands r0, r3
	cmp r0, 0
	bne _080DF1A6
	ldrb r1, [r1, 0xB]
	movs r0, 0x80
	ands r0, r1
	cmp r0, 0
	beq _080DF1BC
_080DF1A6:
	ldr r0, [r2, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xC]
	movs r0, 0x20
	orrs r0, r2
	strb r0, [r1, 0xC]
	b _080DF1F6
	.pool
_080DF1BC:
	movs r0, 0x1
	ands r0, r3
	cmp r0, 0
	bne _080DF1F6
	ldr r2, [r2, 0x1C]
	lsls r3, r4, 4
	adds r2, r3, r2
	ldrb r0, [r2, 0xC]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0xC]
	ldr r0, [r6]
	ldr r1, [r0, 0x1C]
	adds r1, r3, r1
	ldrb r0, [r1, 0xE]
	movs r2, 0x1
	orrs r0, r2
	strb r0, [r1, 0xE]
	ldr r1, [r6]
	ldr r0, [r1, 0x1C]
	adds r3, r0
	ldr r0, [r1]
	ldrb r0, [r0, 0x1]
	lsls r0, 1
	adds r3, r0
	ldr r0, [r1, 0x4]
	adds r0, r5, r0
	ldrh r0, [r0, 0x6]
	strh r0, [r3]
_080DF1F6:
	ldr r2, [r6]
	ldr r1, [r2, 0x4]
	subs r0, r7, r4
	lsls r0, 2
	adds r0, r1
	ldrb r1, [r0, 0x15]
	movs r5, 0x1
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	beq _080DF21A
	ldr r0, [r2, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xD]
	movs r0, 0x2
	orrs r0, r2
	strb r0, [r1, 0xD]
_080DF21A:
	ldr r2, [r6]
	ldr r0, [r2]
	ldrb r0, [r0, 0x13]
	lsls r0, 24
	asrs r0, 24
	cmp r0, 0x4
	bne _080DF24A
	ldr r3, [r2, 0x10]
	ldrb r1, [r3, 0x1]
	adds r0, r5, 0
	ands r0, r1
	cmp r0, 0
	bne _080DF24A
	movs r0, 0
	ldrsb r0, [r3, r0]
	cmp r0, 0
	bge _080DF24A
	ldr r0, [r2, 0x1C]
	lsls r1, r4, 4
	adds r1, r0
	ldrb r2, [r1, 0xD]
	movs r0, 0x20
	orrs r0, r2
	strb r0, [r1, 0xD]
_080DF24A:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80DF080

	thumb_func_start sub_80DF250
sub_80DF250: @ 80DF250
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x38
	movs r1, 0
	movs r0, 0
	str r0, [sp, 0x20]
	movs r4, 0
	ldr r6, =gContestResources
	mov r2, sp
	adds r2, 0xC
	str r2, [sp, 0x28]
	mov r3, sp
	adds r3, 0x14
	str r3, [sp, 0x2C]
	mov r7, sp
	adds r7, 0x2
	str r7, [sp, 0x24]
	ldr r5, =gContestFinalStandings
	movs r2, 0
	movs r3, 0x80
	lsls r3, 17
_080DF280:
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DF298
	lsrs r0, r2, 24
	str r0, [sp, 0x20]
	b _080DF29E
	.pool
_080DF298:
	cmp r0, 0x3
	bne _080DF29E
	lsrs r1, r2, 24
_080DF29E:
	adds r2, r3
	adds r4, 0x1
	cmp r4, 0x3
	ble _080DF280
	ldr r0, [r6]
	ldr r0, [r0, 0x1C]
	lsls r1, 4
	adds r1, r0
	ldrb r2, [r1, 0xD]
	movs r0, 0x1
	orrs r0, r2
	strb r0, [r1, 0xD]
	movs r4, 0
	ldr r1, [sp, 0x20]
	lsls r1, 4
	str r1, [sp, 0x30]
	mov r9, r4
	mov r10, r4
_080DF2C2:
	ldr r2, [sp, 0x20]
	cmp r4, r2
	beq _080DF2EE
	ldr r1, =gUnknown_02039F08
	lsls r0, r2, 1
	adds r0, r1
	movs r3, 0
	ldrsh r2, [r0, r3]
	add r1, r10
	movs r6, 0
	ldrsh r0, [r1, r6]
	subs r2, r0
	cmp r2, 0x32
	bgt _080DF2EE
	ldr r7, =gContestResources
	ldr r0, [r7]
	ldr r2, [r0, 0x1C]
	add r2, r9
	ldrb r0, [r2, 0xD]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r2, 0xD]
_080DF2EE:
	ldr r1, =gContestResources
	ldr r0, [r1]
	ldr r0, [r0, 0x1C]
	mov r3, r9
	adds r2, r3, r0
	ldrb r1, [r2, 0xE]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _080DF30A
	ldrb r0, [r2, 0xD]
	movs r1, 0x8
	orrs r0, r1
	strb r0, [r2, 0xD]
_080DF30A:
	movs r5, 0
	ldr r2, =gContestMonConditions
	add r2, r10
	movs r6, 0
	ldrsh r1, [r2, r6]
	ldr r7, =gContestMonConditions
	movs r3, 0
	ldrsh r0, [r7, r3]
	cmp r1, r0
	blt _080DF336
	adds r3, r2, 0
	adds r2, r7, 0
_080DF322:
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	bgt _080DF336
	movs r6, 0
	ldrsh r1, [r3, r6]
	movs r7, 0
	ldrsh r0, [r2, r7]
	cmp r1, r0
	bge _080DF322
_080DF336:
	cmp r5, 0x4
	bne _080DF354
	ldr r1, =gContestFinalStandings
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080DF354
	ldr r2, =gContestResources
	ldr r0, [r2]
	ldr r2, [r0, 0x1C]
	add r2, r9
	ldrb r0, [r2, 0xD]
	movs r1, 0x10
	orrs r0, r1
	strb r0, [r2, 0xD]
_080DF354:
	movs r3, 0
	mov r12, r3
	mov r8, r3
	movs r5, 0
	ldr r0, =gContestMonConditions
	add r0, r10
	movs r7, 0
	ldrsh r6, [r0, r7]
	str r6, [sp, 0x34]
	ldr r2, =gContestMonConditions
	ldr r0, =gUnknown_02039F18
	mov r1, r10
	adds r6, r1, r0
	adds r3, r0, 0
_080DF370:
	movs r7, 0
	ldrsh r0, [r2, r7]
	ldr r1, [sp, 0x34]
	cmp r1, r0
	ble _080DF37E
	movs r7, 0x1
	mov r12, r7
_080DF37E:
	movs r0, 0
	ldrsh r1, [r6, r0]
	movs r7, 0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	ble _080DF38E
	movs r0, 0x1
	mov r8, r0
_080DF38E:
	adds r2, 0x2
	adds r3, 0x2
	adds r5, 0x1
	cmp r5, 0x3
	ble _080DF370
	mov r1, r12
	cmp r1, 0
	bne _080DF3B4
	mov r2, r8
	cmp r2, 0
	bne _080DF3B4
	ldr r3, =gContestResources
	ldr r0, [r3]
	ldr r2, [r0, 0x1C]
	add r2, r9
	ldrb r0, [r2, 0xD]
	movs r1, 0x40
	orrs r0, r1
	strb r0, [r2, 0xD]
_080DF3B4:
	ldr r6, =gContestResources
	ldr r0, [r6]
	ldr r0, [r0, 0x1C]
	mov r7, r9
	adds r2, r7, r0
	ldrb r1, [r2, 0xE]
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	bne _080DF3D0
	ldrb r0, [r2, 0xD]
	movs r1, 0x80
	orrs r0, r1
	strb r0, [r2, 0xD]
_080DF3D0:
	movs r0, 0x10
	add r9, r0
	movs r1, 0x2
	add r10, r1
	adds r4, 0x1
	cmp r4, 0x3
	bgt _080DF3E0
	b _080DF2C2
_080DF3E0:
	movs r4, 0
	movs r5, 0
	movs r3, 0
	ldr r2, [sp, 0x28]
	mov r1, sp
_080DF3EA:
	strh r3, [r1]
	adds r0, r2, r4
	strb r5, [r0]
	adds r1, 0x2
	adds r4, 0x1
	cmp r4, 0x4
	ble _080DF3EA
	mov r1, sp
	ldr r0, =0x0000ffff
	strh r0, [r1, 0xA]
	movs r0, 0
	ldr r2, [sp, 0x28]
	strb r0, [r2, 0x5]
	movs r4, 0
	ldr r0, =gContestResources
	ldr r0, [r0]
	mov r8, r0
	ldr r7, [sp, 0x30]
_080DF40E:
	mov r3, r8
	ldr r0, [r3, 0x1C]
	adds r0, r7, r0
	lsls r1, r4, 1
	adds r0, r1
	ldrh r0, [r0]
	adds r4, 0x1
	mov r12, r4
	cmp r0, 0
	beq _080DF450
	ldr r0, =gContestResources
	ldr r6, [r0]
	ldr r3, [sp, 0x28]
	mov r4, sp
	movs r5, 0x4
_080DF42C:
	ldr r0, [r6, 0x1C]
	adds r0, r7, r0
	adds r0, r1
	ldrh r0, [r0]
	ldrh r2, [r4]
	cmp r0, r2
	beq _080DF440
	cmp r2, 0
	bne _080DF446
	strh r0, [r4]
_080DF440:
	ldrb r0, [r3]
	adds r0, 0x1
	strb r0, [r3]
_080DF446:
	adds r3, 0x1
	adds r4, 0x2
	subs r5, 0x1
	cmp r5, 0
	bge _080DF42C
_080DF450:
	mov r4, r12
	cmp r4, 0x4
	ble _080DF40E
	mov r0, sp
	ldrh r0, [r0]
	ldr r6, [sp, 0x2C]
	strh r0, [r6]
	ldr r7, [sp, 0x28]
	ldrb r3, [r7]
	movs r6, 0
	movs r4, 0x1
	ldr r1, [sp, 0x24]
	ldrh r0, [r1]
	ldr r1, =0x0000ffff
	cmp r0, r1
	beq _080DF4C0
	ldr r5, [sp, 0x2C]
	adds r7, r1, 0
	mov r2, sp
	adds r2, 0x2
_080DF478:
	ldr r0, [sp, 0x28]
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r3, r0
	bcs _080DF4A4
	ldrh r0, [r2]
	strh r0, [r5]
	ldrb r3, [r1]
	movs r6, 0x1
	b _080DF4B6
	.pool
_080DF4A4:
	cmp r3, r0
	bne _080DF4B6
	lsls r0, r6, 1
	adds r0, r5, r0
	ldrh r1, [r2]
	strh r1, [r0]
	adds r0, r6, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
_080DF4B6:
	adds r2, 0x2
	adds r4, 0x1
	ldrh r0, [r2]
	cmp r0, r7
	bne _080DF478
_080DF4C0:
	bl Random
	ldr r1, =gContestResources
	ldr r1, [r1]
	ldr r4, [r1, 0x1C]
	ldr r1, [sp, 0x30]
	adds r4, r1, r4
	lsls r0, 16
	lsrs r0, 16
	adds r1, r6, 0
	bl __modsi3
	lsls r0, 1
	ldr r2, [sp, 0x2C]
	adds r0, r2, r0
	ldrh r0, [r0]
	strh r0, [r4, 0xA]
	add sp, 0x38
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DF250

	thumb_func_start sub_80DF4F8
sub_80DF4F8: @ 80DF4F8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0xC
	ldr r1, =gContestFinalStandings
	ldr r0, =gContestPlayerMonIndex
	ldrb r0, [r0]
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0
	beq _080DF514
	b _080DF6EE
_080DF514:
	movs r7, 0
	movs r3, 0
	ldr r0, =gContestResources
	mov r12, r0
_080DF51C:
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DF528
	lsls r0, r3, 24
	lsrs r7, r0, 24
_080DF528:
	adds r3, 0x1
	cmp r3, 0x3
	ble _080DF51C
	movs r1, 0
	mov r9, r1
	mov r10, r1
	movs r3, 0
	lsls r2, r7, 1
	lsls r4, r7, 4
	mov r8, r4
	ldr r1, =gContestMonConditions
	adds r0, r2, r1
	movs r6, 0
	ldrsh r5, [r0, r6]
	str r5, [sp, 0x8]
	adds r5, r1, 0
	ldr r0, =gUnknown_02039F18
	adds r2, r0
	adds r4, r0, 0
_080DF54E:
	movs r1, 0
	ldrsh r0, [r5, r1]
	ldr r6, [sp, 0x8]
	cmp r6, r0
	bge _080DF562
	mov r0, r9
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r9, r0
_080DF562:
	movs r0, 0
	ldrsh r1, [r2, r0]
	movs r6, 0
	ldrsh r0, [r4, r6]
	cmp r1, r0
	bge _080DF578
	mov r0, r10
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r10, r0
_080DF578:
	adds r5, 0x2
	adds r4, 0x2
	adds r3, 0x1
	cmp r3, 0x3
	ble _080DF54E
	mov r1, r12
	ldr r0, [r1]
	ldr r0, [r0, 0x1C]
	add r0, r8
	ldrb r1, [r0, 0xC]
	movs r4, 0
	movs r2, 0x1
	movs r3, 0x7
_080DF592:
	adds r0, r1, 0
	ands r0, r2
	cmp r0, 0
	beq _080DF5A0
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080DF5A0:
	lsrs r1, 1
	subs r3, 0x1
	cmp r3, 0
	bge _080DF592
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl __modsi3
	lsls r0, 24
	lsrs r5, r0, 24
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x1C]
	add r0, r8
	ldrb r1, [r0, 0xC]
	movs r4, 0
	movs r2, 0
	movs r3, 0
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080DF5DC
	cmp r5, 0
	beq _080DF5F6
_080DF5D6:
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
_080DF5DC:
	lsrs r1, 1
	adds r0, r2, 0x1
	lsls r0, 24
	lsrs r2, r0, 24
	adds r3, 0x1
	cmp r3, 0x7
	bgt _080DF5F6
	movs r0, 0x1
	ands r0, r1
	cmp r0, 0
	beq _080DF5DC
	cmp r5, r4
	bne _080DF5D6
_080DF5F6:
	movs r1, 0x1
	adds r0, r1, 0
	lsls r0, r2
	lsls r0, 16
	lsrs r2, r0, 16
	cmp r7, 0
	bne _080DF628
	mov r0, sp
	strb r1, [r0]
	ldr r1, =gContestResources
	ldr r0, [r1]
	ldr r0, [r0, 0x1C]
	ldrb r4, [r0, 0x1D]
	movs r3, 0x2
	b _080DF638
	.pool
_080DF628:
	mov r1, sp
	movs r0, 0
	strb r0, [r1]
	ldr r1, =gContestResources
	ldr r0, [r1]
	ldr r0, [r0, 0x1C]
	ldrb r4, [r0, 0xD]
	movs r3, 0x1
_080DF638:
	mov r12, r1
	movs r5, 0x1
	lsls r2, 24
	str r2, [sp, 0x4]
	cmp r3, 0x3
	bgt _080DF682
_080DF644:
	cmp r3, r7
	beq _080DF67C
	mov r6, r12
	ldr r2, [r6]
	ldr r0, [r2, 0x1C]
	lsls r1, r3, 4
	adds r0, r1, r0
	ldrb r0, [r0, 0xD]
	cmp r4, r0
	bcs _080DF66C
	mov r0, sp
	strb r3, [r0]
	ldr r0, [r2, 0x1C]
	adds r0, r1, r0
	ldrb r4, [r0, 0xD]
	movs r5, 0x1
	b _080DF67C
	.pool
_080DF66C:
	cmp r4, r0
	bne _080DF67C
	mov r1, sp
	adds r0, r1, r5
	strb r3, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_080DF67C:
	adds r3, 0x1
	cmp r3, 0x3
	ble _080DF644
_080DF682:
	bl Random
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl __modsi3
	add r0, sp
	ldrb r6, [r0]
	movs r2, 0x80
	movs r3, 0
	ldr r5, =gContestResources
	ldr r0, [r5]
	ldr r0, [r0, 0x1C]
	lsls r1, r6, 4
	adds r0, r1, r0
	ldrb r0, [r0, 0xD]
	ands r0, r2
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, 0
	bne _080DF6C4
_080DF6AE:
	lsrs r2, 1
	adds r3, 0x1
	cmp r3, 0x7
	bgt _080DF6C4
	ldr r0, [r5]
	ldr r0, [r0, 0x1C]
	adds r0, r1, r0
	ldrb r4, [r0, 0xD]
	ands r4, r2
	cmp r4, 0
	beq _080DF6AE
_080DF6C4:
	mov r0, r9
	bl ContestLiveUpdates_BeforeInterview_1
	mov r0, r10
	bl ContestLiveUpdates_BeforeInterview_2
	ldr r5, [sp, 0x4]
	lsrs r0, r5, 24
	bl ContestLiveUpdates_BeforeInterview_3
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r0, [r0, 0x1C]
	add r0, r8
	ldrh r0, [r0, 0xA]
	bl ContestLiveUpdates_BeforeInterview_4
	adds r0, r4, 0
	adds r1, r6, 0
	bl ContestLiveUpdates_BeforeInterview_5
_080DF6EE:
	add sp, 0xC
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DF4F8

	thumb_func_start sub_80DF704
sub_80DF704: @ 80DF704
	push {r4,lr}
	lsls r0, 24
	lsrs r3, r0, 24
	ldr r0, =gHeap
	movs r1, 0xD0
	lsls r1, 9
	adds r2, r0, r1
	ldrb r1, [r2]
	adds r4, r0, 0
	cmp r1, 0
	bne _080DF72C
	cmp r3, 0
	bne _080DF728
	movs r0, 0x2
	b _080DF72E
	.pool
_080DF728:
	movs r0, 0x3
	b _080DF72E
_080DF72C:
	movs r0, 0
_080DF72E:
	strb r0, [r2]
	movs r1, 0xD0
	lsls r1, 9
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DF746
	bl sub_80DAEA4
	bl sub_80DB2BC
	b _080DF74A
_080DF746:
	bl sub_80DF750
_080DF74A:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80DF704

	thumb_func_start sub_80DF750
sub_80DF750: @ 80DF750
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x34
	ldr r0, =gUnknown_020322D5
	ldrb r0, [r0]
	cmp r0, 0
	bne _080DF766
	b _080DF924
_080DF766:
	ldr r0, =gHeap
	movs r1, 0xD0
	lsls r1, 9
	adds r0, r1
	ldrb r0, [r0]
	subs r0, 0x2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _080DF77C
	b _080DF924
_080DF77C:
	movs r7, 0
	mov r2, sp
	adds r2, 0x18
	str r2, [sp, 0x30]
_080DF784:
	adds r0, r7, 0
	movs r1, 0
	bl FillWindowPixelBuffer
	adds r0, r7, 0x1
	lsls r0, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _080DF784
	ldr r0, =gHeap
	movs r1, 0xD0
	lsls r1, 9
	adds r0, r1
	ldrb r0, [r0]
	cmp r0, 0x2
	bne _080DF874
	movs r7, 0
	movs r2, 0x7
	mov r10, r2
	ldr r0, [sp, 0x30]
	mov r9, r0
_080DF7AE:
	add r0, sp, 0x4
	ldr r1, =gText_CDot
	bl StringCopy
	adds r5, r0, 0
	ldr r0, =gUnknown_02039F26
	adds r0, r7, r0
	ldrb r0, [r0]
	mov r1, r10
	str r1, [sp]
	add r1, sp, 0x4
	movs r2, 0x5
	movs r3, 0x1
	bl Contest_PrintTextToBg0WindowAt
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r1, [r0, 0x1C]
	lsls r0, r7, 4
	adds r0, r1
	ldrb r4, [r0, 0xC]
	movs r6, 0x7
	adds r2, r7, 0x1
	mov r8, r2
_080DF7DE:
	movs r1, 0x1
	ands r1, r4
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	adds r5, r0, 0
	lsrs r4, 1
	lsls r0, r6, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r6, r0, 24
	asrs r0, 24
	movs r2, 0x1
	negs r2, r2
	cmp r0, r2
	bgt _080DF7DE
	movs r6, 0
	ldr r4, =gUnknown_02039F26
	ldr r3, [sp, 0x30]
_080DF80A:
	lsls r0, r6, 24
	asrs r0, 24
	adds r2, r3, r0
	mov r1, sp
	adds r1, r0
	adds r1, 0x4
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	asrs r5, r0, 24
	cmp r5, 0x4
	ble _080DF80A
	mov r0, r9
	adds r1, r0, r5
	movs r0, 0xFF
	strb r0, [r1]
	adds r4, r7, r4
	ldrb r0, [r4]
	mov r1, r10
	str r1, [sp]
	mov r1, r9
	movs r2, 0x5
	movs r3, 0x1
	bl Contest_PrintTextToBg0WindowAt
	ldrb r0, [r4]
	mov r1, sp
	adds r1, r5
	adds r1, 0x4
	mov r2, r10
	str r2, [sp]
	movs r2, 0x37
	movs r3, 0x1
	bl Contest_PrintTextToBg0WindowAt
	mov r1, r8
	lsls r0, r1, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _080DF7AE
	b _080DF920
	.pool
_080DF874:
	movs r7, 0
	mov r2, sp
	adds r2, 0x6
	str r2, [sp, 0x2C]
	ldr r0, [sp, 0x30]
	mov r9, r0
	movs r1, 0x7
	mov r10, r1
_080DF884:
	add r0, sp, 0x4
	ldr r1, =gText_BDot
	bl StringCopy
	ldr r0, =gContestResources
	ldr r0, [r0]
	ldr r1, [r0, 0x1C]
	lsls r0, r7, 4
	adds r0, r1
	ldrb r4, [r0, 0xD]
	ldr r5, [sp, 0x2C]
	movs r6, 0x7
	adds r2, r7, 0x1
	mov r8, r2
_080DF8A0:
	movs r1, 0x1
	ands r1, r4
	adds r0, r5, 0
	movs r2, 0
	movs r3, 0x1
	bl ConvertIntToDecimalStringN
	adds r5, r0, 0
	lsrs r4, 1
	lsls r0, r6, 24
	movs r1, 0xFF
	lsls r1, 24
	adds r0, r1
	lsrs r6, r0, 24
	asrs r0, 24
	movs r2, 0x1
	negs r2, r2
	cmp r0, r2
	bgt _080DF8A0
	movs r6, 0
	ldr r4, =gUnknown_02039F26
	ldr r3, [sp, 0x30]
_080DF8CC:
	lsls r0, r6, 24
	asrs r0, 24
	adds r2, r3, r0
	mov r1, sp
	adds r1, r0
	adds r1, 0x4
	ldrb r1, [r1]
	strb r1, [r2]
	adds r0, 0x1
	lsls r0, 24
	lsrs r6, r0, 24
	asrs r5, r0, 24
	cmp r5, 0x4
	ble _080DF8CC
	mov r0, r9
	adds r1, r0, r5
	movs r0, 0xFF
	strb r0, [r1]
	adds r4, r7, r4
	ldrb r0, [r4]
	mov r1, r10
	str r1, [sp]
	mov r1, r9
	movs r2, 0x5
	movs r3, 0x1
	bl Contest_PrintTextToBg0WindowAt
	ldrb r0, [r4]
	mov r1, sp
	adds r1, r5
	adds r1, 0x4
	mov r2, r10
	str r2, [sp]
	movs r2, 0x37
	movs r3, 0x1
	bl Contest_PrintTextToBg0WindowAt
	mov r1, r8
	lsls r0, r1, 24
	lsrs r7, r0, 24
	cmp r7, 0x3
	bls _080DF884
_080DF920:
	bl sub_80DB2BC
_080DF924:
	add sp, 0x34
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_80DF750

	thumb_func_start sub_80DF940
sub_80DF940: @ 80DF940
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0x2
	ldrb r0, [r4]
	cmp r0, 0xFC
	bne _080DF956
	ldrb r0, [r4, 0x1]
	cmp r0, 0x15
	bne _080DF956
	movs r0, 0x2
	b _080DF9CC
_080DF956:
	adds r0, r4, 0
	bl StringLength
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bhi _080DF9CA
	ldrb r0, [r4]
	cmp r0, 0xFF
	beq _080DF9CA
_080DF96A:
	ldrb r1, [r4]
	adds r0, r1, 0
	adds r0, 0x45
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x33
	bls _080DF9BE
	adds r0, r1, 0
	adds r0, 0x5F
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x9
	bls _080DF9BE
	adds r0, r1, 0
	cmp r0, 0
	beq _080DF9BE
	cmp r0, 0xAD
	beq _080DF9BE
	cmp r0, 0xB8
	beq _080DF9BE
	cmp r0, 0xAB
	beq _080DF9BE
	cmp r0, 0xAC
	beq _080DF9BE
	cmp r0, 0xB5
	beq _080DF9BE
	cmp r0, 0xB6
	beq _080DF9BE
	cmp r0, 0xBA
	beq _080DF9BE
	cmp r0, 0xAE
	beq _080DF9BE
	cmp r0, 0xB0
	beq _080DF9BE
	cmp r0, 0xB1
	beq _080DF9BE
	cmp r0, 0xB2
	beq _080DF9BE
	cmp r0, 0xB3
	beq _080DF9BE
	cmp r0, 0xB1
	bne _080DF9C8
_080DF9BE:
	adds r4, 0x1
	ldrb r0, [r4]
	cmp r0, 0xFF
	bne _080DF96A
	b _080DF9CA
_080DF9C8:
	movs r5, 0x1
_080DF9CA:
	adds r0, r5, 0
_080DF9CC:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_80DF940

	thumb_func_start sub_80DF9D4
sub_80DF9D4: @ 80DF9D4
	ldrb r2, [r0, 0x5]
	movs r1, 0xFF
	strb r1, [r0, 0x5]
	strb r2, [r0, 0x7]
	bx lr
	thumb_func_end sub_80DF9D4

	thumb_func_start sub_80DF9E0
sub_80DF9E0: @ 80DF9E0
	push {r4,r5,lr}
	adds r5, r0, 0
	adds r4, r1, 0
	bl StripExtCtrlCodes
	cmp r4, 0x1
	bne _080DF9F8
	movs r0, 0xFF
	strb r0, [r5, 0x5]
	movs r0, 0xFC
	strb r0, [r5, 0xA]
	b _080DFA00
_080DF9F8:
	ldrb r1, [r5, 0x5]
	movs r0, 0xFF
	strb r0, [r5, 0x5]
	strb r1, [r5, 0xA]
_080DFA00:
	pop {r4,r5}
	pop {r0}
	bx r0
	thumb_func_end sub_80DF9E0

	thumb_func_start sub_80DFA08
sub_80DFA08: @ 80DFA08
	push {r4-r6,lr}
	adds r5, r0, 0
	adds r6, r1, 0
	adds r4, r5, 0x2
	cmp r6, 0x1
	bne _080DFA28
	adds r0, r4, 0
	bl sub_80DF940
	adds r1, r0, 0
	lsls r1, 24
	lsrs r1, 24
	adds r0, r4, 0
	bl ConvertInternationalString
	b _080DFA3E
_080DFA28:
	ldrb r0, [r4, 0xA]
	cmp r0, 0xFC
	bne _080DFA38
	adds r0, r4, 0
	movs r1, 0x1
	bl ConvertInternationalString
	b _080DFA3E
_080DFA38:
	strb r0, [r4, 0x5]
	movs r0, 0xFF
	strb r0, [r4, 0xA]
_080DFA3E:
	adds r4, r5, 0
	adds r4, 0xD
	cmp r6, 0x1
	bne _080DFA68
	movs r0, 0xFF
	strb r0, [r4, 0x7]
	ldrb r0, [r4, 0x4]
	strb r0, [r4, 0x6]
	ldrb r0, [r4, 0x3]
	strb r0, [r4, 0x5]
	ldrb r0, [r4, 0x2]
	strb r0, [r4, 0x4]
	ldrb r0, [r4, 0x1]
	strb r0, [r4, 0x3]
	ldrb r0, [r5, 0xD]
	strb r0, [r4, 0x2]
	movs r0, 0x15
	strb r0, [r4, 0x1]
	movs r0, 0xFC
	strb r0, [r5, 0xD]
	b _080DFA70
_080DFA68:
	ldrb r0, [r4, 0x7]
	strb r0, [r4, 0x5]
	movs r0, 0xFF
	strb r0, [r4, 0x7]
_080DFA70:
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_80DFA08

	.align 2, 0 @ Don't pad with nop.
