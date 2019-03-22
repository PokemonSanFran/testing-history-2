
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.syntax unified

	.text

	thumb_func_start sub_81D427C
sub_81D427C: @ 81D427C
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	bl sub_81D4258
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r2, =gEventObjects
	adds r5, r1, r2
	ldr r4, =gUnknown_030012F8
	ldr r3, =gPlayerAvatar
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x14]
	ldrh r1, [r5, 0x10]
	subs r0, r1
	strh r0, [r4]
	ldr r4, =gUnknown_030012FA
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	ldrh r0, [r0, 0x16]
	ldrh r1, [r5, 0x12]
	subs r0, r1
	strh r0, [r4]
	movs r0, 0
	mov r8, r0
	ldr r2, =gUnknown_030012FC
	movs r1, 0
_081D42CA:
	mov r3, r8
	adds r0, r3, r2
	strb r1, [r0]
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x3
	bls _081D42CA
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r2, r0, r2
	movs r4, 0x14
	ldrsh r1, [r2, r4]
	movs r6, 0x10
	ldrsh r0, [r2, r6]
	cmp r1, r0
	bne _081D4304
	movs r0, 0x16
	ldrsh r1, [r2, r0]
	movs r3, 0x12
	ldrsh r0, [r2, r3]
	cmp r1, r0
	beq _081D4356
_081D4304:
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	movs r1, 0xE0
	lsls r1, 11
	ands r1, r0
	cmp r1, 0
	bne _081D4338
	ldrb r1, [r5, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	b _081D433E
	.pool
_081D4338:
	ldrb r0, [r5, 0x1]
	movs r1, 0x20
	orrs r0, r1
_081D433E:
	strb r0, [r5, 0x1]
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	movs r1, 0x9
	bl __umodsi3
	lsls r0, 16
	cmp r0, 0
	bne _081D4360
_081D4356:
	movs r0, 0
	b _081D4816
	.pool
_081D4360:
	movs r4, 0
	mov r8, r4
	ldr r6, =gEventObjects
	mov r10, r6
_081D4368:
	ldr r3, =gPlayerAvatar
	ldrb r1, [r3, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	mov r1, r10
	adds r4, r0, r1
	mov r2, r8
	lsls r1, r2, 2
	ldr r6, =gUnknown_0862608C
	adds r0, r1, r6
	movs r6, 0x14
	ldrsh r2, [r4, r6]
	movs r6, 0
	ldrsh r0, [r0, r6]
	ldr r6, =gEventObjects
	mov r9, r6
	mov r12, r3
	adds r7, r1, 0
	cmp r2, r0
	beq _081D4394
	b _081D449E
_081D4394:
	movs r3, 0
	ldr r1, =gUnknown_0862608C + 2
	adds r0, r7, r1
	movs r2, 0x16
	ldrsh r1, [r4, r2]
	movs r4, 0
	ldrsh r2, [r0, r4]
	cmp r1, r2
	bge _081D43C0
	movs r6, 0x12
	ldrsh r0, [r5, r6]
	cmp r0, r2
	bgt _081D43CA
	b _081D449E
	.pool
_081D43C0:
	movs r1, 0x12
	ldrsh r0, [r5, r1]
	cmp r0, r2
	blt _081D43CA
	movs r3, 0x1
_081D43CA:
	cmp r3, 0
	bne _081D449E
	ldr r0, =gUnknown_030012F8
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	ble _081D4410
	movs r3, 0x10
	ldrsh r2, [r5, r3]
	adds r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x14
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4446
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4446
_081D4408:
	movs r0, 0x4
	b _081D4816
	.pool
_081D4410:
	cmp r0, 0
	bge _081D4446
	movs r3, 0x10
	ldrsh r2, [r5, r3]
	subs r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x14
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4446
	ldrh r0, [r5, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4446
	b _081D45AA
_081D4446:
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r10
	movs r3, 0x10
	ldrsh r1, [r5, r3]
	movs r4, 0x14
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bne _081D449E
	ldr r0, =gUnknown_030012FA
	movs r6, 0
	ldrsh r0, [r0, r6]
	cmp r0, 0
	ble _081D4488
	adds r0, r1, 0
	ldrh r1, [r5, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D449E
_081D447C:
	movs r0, 0x2
	b _081D4816
	.pool
_081D4488:
	movs r2, 0x10
	ldrsh r0, [r5, r2]
	ldrh r1, [r5, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	bne _081D4538
_081D449E:
	ldr r2, =gPlayerAvatar
	ldrb r1, [r2, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	mov r3, r10
	adds r4, r0, r3
	ldr r6, =gUnknown_0862608C
	ldr r1, =gUnknown_0862608C + 2
	adds r0, r7, r1
	movs r3, 0x16
	ldrsh r1, [r4, r3]
	movs r3, 0
	ldrsh r0, [r0, r3]
	ldr r3, =gEventObjects
	mov r9, r3
	mov r12, r2
	cmp r1, r0
	beq _081D44C6
	b _081D45D0
_081D44C6:
	movs r3, 0
	adds r0, r7, r6
	movs r6, 0x14
	ldrsh r1, [r4, r6]
	movs r4, 0
	ldrsh r2, [r0, r4]
	cmp r1, r2
	bge _081D44F0
	movs r6, 0x10
	ldrsh r0, [r5, r6]
	cmp r0, r2
	bgt _081D44FA
	b _081D45D0
	.pool
_081D44F0:
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	cmp r0, r2
	blt _081D44FA
	movs r3, 0x1
_081D44FA:
	cmp r3, 0
	bne _081D45D0
	ldr r0, =gUnknown_030012FA
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	ble _081D4540
	movs r3, 0x12
	ldrsh r2, [r5, r3]
	adds r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x16
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4576
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4576
_081D4538:
	movs r0, 0x1
	b _081D4816
	.pool
_081D4540:
	cmp r0, 0
	bge _081D4576
	movs r3, 0x12
	ldrsh r2, [r5, r3]
	subs r2, 0x1
	mov r4, r12
	ldrb r1, [r4, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r9
	movs r6, 0x16
	ldrsh r0, [r0, r6]
	cmp r2, r0
	bne _081D4576
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4576
	b _081D447C
_081D4576:
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	add r0, r10
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	movs r3, 0x16
	ldrsh r0, [r0, r3]
	cmp r1, r0
	bne _081D45D0
	ldr r0, =gUnknown_030012F8
	movs r4, 0
	ldrsh r0, [r0, r4]
	cmp r0, 0
	ble _081D45B8
	ldrh r0, [r5, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D45D0
_081D45AA:
	movs r0, 0x3
	b _081D4816
	.pool
_081D45B8:
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D45D0
	b _081D4408
_081D45D0:
	mov r0, r8
	adds r0, 0x1
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0x3
	bhi _081D45E0
	b _081D4368
_081D45E0:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4C14
	lsls r0, 24
	cmp r0, 0
	beq _081D461C
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C58
	lsls r0, 24
	cmp r0, 0
	beq _081D4604
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4604:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4CE0
	lsls r0, 24
	cmp r0, 0
	bne _081D4614
	b _081D447C
_081D4614:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D461C:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4C9C
	lsls r0, 24
	cmp r0, 0
	beq _081D4658
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C58
	lsls r0, 24
	cmp r0, 0
	beq _081D4640
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4640:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4CE0
	lsls r0, 24
	cmp r0, 0
	bne _081D4650
	b _081D4538
_081D4650:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4658:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4C58
	lsls r0, 24
	cmp r0, 0
	beq _081D4694
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C14
	lsls r0, 24
	cmp r0, 0
	beq _081D467C
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D467C:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C9C
	lsls r0, 24
	cmp r0, 0
	bne _081D468C
	b _081D4408
_081D468C:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D4694:
	adds r0, r5, 0
	movs r1, 0
	bl sub_81D4CE0
	lsls r0, 24
	cmp r0, 0
	beq _081D46D0
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C14
	lsls r0, 24
	cmp r0, 0
	beq _081D46B8
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D46B8:
	adds r0, r5, 0
	movs r1, 0x1
	bl sub_81D4C9C
	lsls r0, 24
	cmp r0, 0
	bne _081D46C8
	b _081D45AA
_081D46C8:
	movs r0, 0x2
	bl sub_81D4D24
	b _081D4812
_081D46D0:
	ldr r0, =gUnknown_030012FA
	movs r3, 0
	ldrsh r0, [r0, r3]
	cmp r0, 0
	bne _081D476E
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r4, 0x12
	ldrsh r1, [r0, r4]
	ldrh r2, [r5, 0x12]
	movs r6, 0x12
	ldrsh r0, [r5, r6]
	cmp r1, r0
	ble _081D470C
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	subs r1, r2, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D470C
	b _081D447C
_081D470C:
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r2, 0x12
	ldrsh r1, [r0, r2]
	ldrh r2, [r5, 0x12]
	movs r3, 0x12
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bge _081D473E
	movs r4, 0x10
	ldrsh r0, [r5, r4]
	adds r1, r2, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D473E
	b _081D4538
_081D473E:
	movs r6, 0x10
	ldrsh r0, [r5, r6]
	ldrh r1, [r5, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4756
	b _081D447C
_081D4756:
	movs r1, 0x10
	ldrsh r0, [r5, r1]
	ldrh r1, [r5, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D476E
	b _081D4538
_081D476E:
	ldr r0, =gUnknown_030012F8
	movs r2, 0
	ldrsh r0, [r0, r2]
	cmp r0, 0
	bne _081D480C
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r3, 0x10
	ldrsh r1, [r0, r3]
	ldrh r2, [r5, 0x10]
	movs r4, 0x10
	ldrsh r0, [r5, r4]
	cmp r1, r0
	ble _081D47AA
	subs r0, r2, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r6, 0x12
	ldrsh r1, [r5, r6]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D47AA
	b _081D45AA
_081D47AA:
	ldr r2, =gEventObjects
	ldr r0, =gPlayerAvatar
	ldrb r1, [r0, 0x5]
	lsls r0, r1, 3
	adds r0, r1
	lsls r0, 2
	adds r0, r2
	movs r2, 0x10
	ldrsh r1, [r0, r2]
	ldrh r2, [r5, 0x10]
	movs r3, 0x10
	ldrsh r0, [r5, r3]
	cmp r1, r0
	bge _081D47DC
	adds r0, r2, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r4, 0x12
	ldrsh r1, [r5, r4]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D47DC
	b _081D4408
_081D47DC:
	ldrh r0, [r5, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r6, 0x12
	ldrsh r1, [r5, r6]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D47F4
	b _081D4408
_081D47F4:
	ldrh r0, [r5, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r5, r2]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D480C
	b _081D45AA
_081D480C:
	movs r0, 0
	bl sub_81D4890
_081D4812:
	lsls r0, 24
	lsrs r0, 24
_081D4816:
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D427C

	thumb_func_start sub_81D4834
sub_81D4834: @ 81D4834
	push {r4,lr}
	lsls r0, 16
	lsls r1, 16
	lsrs r4, r1, 16
	ldr r3, =gEventObjects
	ldr r1, =gPlayerAvatar
	ldrb r2, [r1, 0x5]
	lsls r1, r2, 3
	adds r1, r2
	lsls r1, 2
	adds r2, r1, r3
	movs r3, 0x10
	ldrsh r1, [r2, r3]
	lsrs r3, r0, 16
	asrs r0, 16
	cmp r1, r0
	bne _081D4870
	movs r0, 0x12
	ldrsh r1, [r2, r0]
	lsls r0, r4, 16
	asrs r0, 16
	cmp r1, r0
	bne _081D4870
	movs r0, 0
	b _081D4888
	.pool
_081D4870:
	lsls r0, r3, 16
	asrs r0, 16
	lsls r1, r4, 16
	asrs r1, 16
	bl MapGridGetMetatileBehaviorAt
	lsls r0, 24
	lsrs r0, 24
	bl MetatileBehavior_IsPokeGrass
	lsls r0, 24
	lsrs r0, 24
_081D4888:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4834

	thumb_func_start sub_81D4890
sub_81D4890: @ 81D4890
	push {r4-r6,lr}
	lsls r0, 24
	lsrs r6, r0, 24
	movs r5, 0
	bl sub_81D4258
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gEventObjects
	adds r4, r1, r0
	movs r1, 0
	ldr r3, =gUnknown_030012FC
	movs r2, 0
_081D48B0:
	adds r0, r1, r3
	strb r2, [r0]
	adds r0, r1, 0x1
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x3
	bls _081D48B0
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D48E8
	cmp r6, 0x2
	beq _081D48E8
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	movs r1, 0x2
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D48E8:
	ldrh r0, [r4, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	bl sub_81D4834
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D4912
	cmp r6, 0x4
	beq _081D4912
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	movs r1, 0x4
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D4912:
	movs r1, 0x10
	ldrsh r0, [r4, r1]
	ldrh r1, [r4, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	lsrs r1, r0, 24
	cmp r1, 0x1
	bne _081D493A
	cmp r6, 0x1
	beq _081D493A
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D493A:
	ldrh r0, [r4, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r2, 0x12
	ldrsh r1, [r4, r2]
	bl sub_81D4834
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bne _081D4964
	cmp r6, 0x3
	beq _081D4964
	ldr r0, =gUnknown_030012FC
	adds r0, r5, r0
	movs r1, 0x3
	strb r1, [r0]
	adds r0, r5, 0x1
	lsls r0, 24
	lsrs r5, r0, 24
_081D4964:
	cmp r5, 0x1
	bhi _081D4974
	ldr r0, =gUnknown_030012FC
	b _081D4988
	.pool
_081D4974:
	ldr r4, =gUnknown_030012FC
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	adds r1, r5, 0
	bl __modsi3
	adds r0, r4
_081D4988:
	ldrb r0, [r0]
	pop {r4-r6}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4890

	thumb_func_start sub_81D4998
sub_81D4998: @ 81D4998
	push {r4,lr}
	ldr r4, =0x0000403a
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000391a
	cmp r1, r0
	bne _081D49E0
	adds r0, r2, 0x1
	lsls r0, 16
	lsrs r2, r0, 16
	ldr r0, =0x0000270e
	cmp r2, r0
	bls _081D49D8
	adds r0, r4, 0
	movs r1, 0
	bl VarSet
	b _081D49E0
	.pool
_081D49D8:
	adds r0, r4, 0
	adds r1, r2, 0
	bl VarSet
_081D49E0:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_81D4998

	thumb_func_start EventObjectIsFarawayIslandMew
@ bool8 EventObjectIsFarawayIslandMew(struct npc_state *eventObject)
EventObjectIsFarawayIslandMew: @ 81D49E8
	push {lr}
	adds r2, r0, 0
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000391a
	cmp r1, r0
	bne _081D4A0C
	ldrb r0, [r2, 0x5]
	cmp r0, 0xE5
	bne _081D4A0C
	movs r0, 0x1
	b _081D4A0E
	.pool
_081D4A0C:
	movs r0, 0
_081D4A0E:
	pop {r1}
	bx r1
	thumb_func_end EventObjectIsFarawayIslandMew

	thumb_func_start IsMewPlayingHideAndSeek
IsMewPlayingHideAndSeek: @ 81D4A14
	push {lr}
	ldr r0, =gSaveBlock1Ptr
	ldr r0, [r0]
	ldrh r1, [r0, 0x4]
	ldr r0, =0x0000391a
	cmp r1, r0
	bne _081D4A50
	movs r0, 0xE5
	lsls r0, 1
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081D4A50
	ldr r0, =0x000002ce
	bl FlagGet
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	beq _081D4A50
	movs r0, 0x1
	b _081D4A52
	.pool
_081D4A50:
	movs r0, 0
_081D4A52:
	pop {r1}
	bx r1
	thumb_func_end IsMewPlayingHideAndSeek

	thumb_func_start sub_81D4A58
sub_81D4A58: @ 81D4A58
	push {r4,lr}
	ldr r4, =0x0000403a
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	ldr r1, =0xffff0000
	cmp r0, r1
	beq _081D4A88
	adds r0, r4, 0
	bl VarGet
	lsls r0, 16
	movs r1, 0xC0
	lsls r1, 10
	ands r1, r0
	cmp r1, 0
	bne _081D4A88
	movs r0, 0x1
	b _081D4A8A
	.pool
_081D4A88:
	movs r0, 0
_081D4A8A:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4A58

	thumb_func_start sub_81D4A90
sub_81D4A90: @ 81D4A90
	push {r4-r6,lr}
	sub sp, 0x4
	bl sub_81D4258
	lsls r0, 24
	lsrs r0, 24
	lsls r1, r0, 3
	adds r1, r0
	lsls r1, 2
	ldr r0, =gEventObjects
	adds r5, r1, r0
	ldrb r1, [r5, 0x1]
	movs r0, 0x21
	negs r0, r0
	ands r0, r1
	strb r0, [r5, 0x1]
	ldr r0, =gSpecialVar_0x8004
	ldrh r4, [r0]
	cmp r4, 0x1
	bne _081D4AF8
	ldrb r0, [r5, 0x3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r5, 0x3]
	ldr r3, =gSprites
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x42
	ldrb r2, [r0]
	movs r1, 0x3F
	ands r1, r2
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r3
	adds r0, 0x43
	strb r4, [r0]
	b _081D4BC4
	.pool
_081D4AF8:
	ldr r0, =0x0000403a
	ldr r1, =0x0000ffff
	bl VarSet
	ldrb r0, [r5, 0x3]
	movs r1, 0x4
	orrs r0, r1
	strb r0, [r5, 0x3]
	ldr r6, =gSprites
	ldrb r1, [r5, 0x4]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	adds r0, r6
	adds r0, 0x42
	ldrb r2, [r0]
	movs r1, 0x3F
	ands r1, r2
	movs r2, 0x80
	orrs r1, r2
	strb r1, [r0]
	ldr r0, =gSpecialVar_Facing
	ldrh r0, [r0]
	cmp r0, 0x2
	beq _081D4B3A
	ldrb r0, [r5, 0x4]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	adds r1, 0x43
	movs r0, 0x1
	strb r0, [r1]
_081D4B3A:
	ldr r4, =gFieldEffectObjectPaletteInfo1
	adds r0, r4, 0
	bl LoadSpritePalette
	ldrh r0, [r4, 0x4]
	bl IndexOfSpritePaletteTag
	lsls r0, 24
	lsrs r0, 24
	bl UpdateSpritePaletteWithWeather
	ldrh r1, [r5, 0x10]
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r5, 0x12]
	mov r4, sp
	adds r4, 0x2
	strh r0, [r4]
	mov r0, sp
	adds r1, r4, 0
	movs r2, 0x8
	movs r3, 0x8
	bl sub_80930E0
	ldr r0, =gFieldEffectObjectTemplatePointers
	ldr r0, [r0, 0x3C]
	mov r1, sp
	movs r2, 0
	ldrsh r1, [r1, r2]
	movs r3, 0
	ldrsh r2, [r4, r3]
	ldrb r4, [r5, 0x4]
	lsls r3, r4, 4
	adds r3, r4
	lsls r3, 2
	adds r3, r6
	adds r3, 0x43
	ldrb r3, [r3]
	subs r3, 0x1
	lsls r3, 24
	lsrs r3, 24
	bl CreateSpriteAtEnd
	ldr r1, =gUnknown_0203CF50
	strb r0, [r1]
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x40
	beq _081D4BC4
	ldrb r0, [r1]
	lsls r1, r0, 4
	adds r1, r0
	lsls r1, 2
	adds r1, r6
	adds r3, r1, 0
	adds r3, 0x3E
	ldrb r0, [r3]
	movs r2, 0x2
	orrs r0, r2
	strb r0, [r3]
	ldrb r2, [r1, 0x5]
	movs r0, 0xD
	negs r0, r0
	ands r0, r2
	movs r2, 0x8
	orrs r0, r2
	strb r0, [r1, 0x5]
	ldr r0, =SpriteCallbackDummy
	str r0, [r1, 0x1C]
_081D4BC4:
	add sp, 0x4
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4A90

	thumb_func_start sub_81D4BEC
sub_81D4BEC: @ 81D4BEC
	push {lr}
	ldr r1, =gUnknown_0203CF50
	ldrb r0, [r1]
	cmp r0, 0x40
	beq _081D4C06
	adds r1, r0, 0
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, =gSprites
	adds r0, r1
	bl DestroySprite
_081D4C06:
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4BEC

	thumb_func_start sub_81D4C14
sub_81D4C14: @ 81D4C14
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012FA
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	ble _081D4C50
	movs r1, 0x10
	ldrsh r0, [r2, r1]
	ldrh r1, [r2, 0x12]
	subs r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4C50
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x2
	strb r1, [r0]
	movs r0, 0x1
	b _081D4C52
	.pool
_081D4C50:
	movs r0, 0
_081D4C52:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4C14

	thumb_func_start sub_81D4C58
sub_81D4C58: @ 81D4C58
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012F8
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _081D4C94
	ldrh r0, [r2, 0x10]
	adds r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x12
	ldrsh r1, [r2, r3]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4C94
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x4
	strb r1, [r0]
	movs r0, 0x1
	b _081D4C96
	.pool
_081D4C94:
	movs r0, 0
_081D4C96:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4C58

	thumb_func_start sub_81D4C9C
sub_81D4C9C: @ 81D4C9C
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012FA
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	bge _081D4CD8
	movs r1, 0x10
	ldrsh r0, [r2, r1]
	ldrh r1, [r2, 0x12]
	adds r1, 0x1
	lsls r1, 16
	asrs r1, 16
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4CD8
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x1
	strb r1, [r0]
	movs r0, 0x1
	b _081D4CDA
	.pool
_081D4CD8:
	movs r0, 0
_081D4CDA:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4C9C

	thumb_func_start sub_81D4CE0
sub_81D4CE0: @ 81D4CE0
	push {r4,lr}
	adds r2, r0, 0
	lsls r1, 24
	lsrs r4, r1, 24
	ldr r0, =gUnknown_030012F8
	movs r1, 0
	ldrsh r0, [r0, r1]
	cmp r0, 0
	ble _081D4D1C
	ldrh r0, [r2, 0x10]
	subs r0, 0x1
	lsls r0, 16
	asrs r0, 16
	movs r3, 0x12
	ldrsh r1, [r2, r3]
	bl sub_81D4834
	lsls r0, 24
	cmp r0, 0
	beq _081D4D1C
	ldr r0, =gUnknown_030012FC
	adds r0, r4, r0
	movs r1, 0x3
	strb r1, [r0]
	movs r0, 0x1
	b _081D4D1E
	.pool
_081D4D1C:
	movs r0, 0
_081D4D1E:
	pop {r4}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4CE0

	thumb_func_start sub_81D4D24
sub_81D4D24: @ 81D4D24
	push {r4,r5,lr}
	adds r4, r0, 0
	lsls r4, 24
	lsrs r4, 24
	ldr r5, =gUnknown_030012FC
	ldr r0, =0x0000403a
	bl VarGet
	lsls r0, 16
	lsrs r0, 16
	adds r1, r4, 0
	bl __modsi3
	adds r0, r5
	ldrb r0, [r0]
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4D24

	thumb_func_start sub_81D4D50
sub_81D4D50: @ 81D4D50
	push {r4-r6,lr}
	mov r6, r8
	push {r6}
	sub sp, 0x4
	adds r5, r0, 0
	adds r6, r1, 0
	mov r8, r2
	mov r1, sp
	ldr r4, =0x04000208
	ldrh r0, [r4]
	strh r0, [r1]
	movs r0, 0
	strh r0, [r4]
	ldr r1, =gIntrTable
	ldr r0, =sub_81D3FAC
	str r0, [r1, 0x4]
	ldr r0, =sub_81D3F9C
	str r0, [r1, 0x8]
	bl sub_81D41A0
	bl sub_81D4238
	ldr r2, =0x04000200
	ldrh r0, [r2]
	movs r1, 0x4
	orrs r0, r1
	strh r0, [r2]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4]
	movs r0, 0
	strh r0, [r5]
	str r6, [r5, 0x4]
	mov r0, r8
	str r0, [r5, 0x8]
	add sp, 0x4
	pop {r3}
	mov r8, r3
	pop {r4-r6}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4D50

	thumb_func_start sub_81D4DB8
sub_81D4DB8: @ 81D4DB8
	push {r4,lr}
	sub sp, 0x4
	mov r1, sp
	ldr r4, =0x04000208
	ldrh r0, [r4]
	strh r0, [r1]
	movs r0, 0
	strh r0, [r4]
	bl sub_81D4238
	bl sub_81D41F4
	bl RestoreSerialTimer3IntrHandlers
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r4]
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4DB8

	thumb_func_start sub_81D4DE8
sub_81D4DE8: @ 81D4DE8
	push {r4,r5,lr}
	adds r4, r0, 0
	movs r5, 0
	ldr r1, [r4, 0x4]
	ldr r2, [r4, 0x8]
	movs r0, 0x1
	movs r3, 0
	bl sub_81D3D70
	adds r1, r0, 0
	strh r1, [r4]
	movs r0, 0x13
	ands r0, r1
	cmp r0, 0x10
	bne _081D4E08
	movs r5, 0x1
_081D4E08:
	movs r0, 0x8
	ands r0, r1
	cmp r0, 0
	beq _081D4E12
	movs r5, 0x2
_081D4E12:
	movs r0, 0x4
	ands r0, r1
	cmp r0, 0
	beq _081D4E1C
	movs r5, 0x3
_081D4E1C:
	ldr r1, =gShouldAdvanceLinkState
	movs r0, 0
	strb r0, [r1]
	adds r0, r5, 0
	pop {r4,r5}
	pop {r1}
	bx r1
	.pool
	thumb_func_end sub_81D4DE8

	thumb_func_start sub_81D4E30
sub_81D4E30: @ 81D4E30
	push {lr}
	ldr r0, =gDecompressionBuffer
	movs r2, 0x80
	lsls r2, 6
	movs r1, 0
	bl memset
	ldr r1, =gLinkType
	ldr r2, =0x00005503
	adds r0, r2, 0
	strh r0, [r1]
	bl OpenLink
	movs r0, 0x1
	bl SetSuppressLinkErrorMessage
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D4E30

	thumb_func_start sub_81D4E60
sub_81D4E60: @ 81D4E60
	push {lr}
	sub sp, 0xC
	mov r1, sp
	ldr r2, =0x04000208
	ldrh r0, [r2]
	strh r0, [r1]
	movs r0, 0
	strh r0, [r2]
	ldr r0, =gLink+0x4
	ldr r1, [r0, 0x4]
	ldr r0, [r0]
	str r0, [sp, 0x4]
	str r1, [sp, 0x8]
	mov r0, sp
	ldrh r0, [r0]
	strh r0, [r2]
	add r2, sp, 0x4
	ldrh r1, [r2]
	ldr r0, =0x0000b9a0
	cmp r1, r0
	bne _081D4EB8
	ldrh r1, [r2, 0x2]
	ldr r0, =0x0000ccd0
	cmp r1, r0
	bne _081D4EB8
	ldrh r1, [r2, 0x4]
	ldr r0, =0x0000ffff
	cmp r1, r0
	bne _081D4EB8
	ldrh r0, [r2, 0x6]
	cmp r0, r1
	bne _081D4EB8
	movs r0, 0x1
	b _081D4EBA
	.pool
_081D4EB8:
	movs r0, 0
_081D4EBA:
	add sp, 0xC
	pop {r1}
	bx r1
	thumb_func_end sub_81D4E60

	thumb_func_start sub_81D4EC0
sub_81D4EC0: @ 81D4EC0
	push {lr}
	bl IsLinkMaster
	lsls r0, 24
	cmp r0, 0
	beq _081D4EDC
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081D4EDC
	movs r0, 0x1
	b _081D4EDE
_081D4EDC:
	movs r0, 0
_081D4EDE:
	pop {r1}
	bx r1
	thumb_func_end sub_81D4EC0

	thumb_func_start sub_81D4EE4
sub_81D4EE4: @ 81D4EE4
	push {r4,r5,lr}
	adds r4, r0, 0
	adds r5, r1, 0
	ldrb r0, [r4]
	subs r0, 0x3
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bhi _081D4F08
	bl HasLinkErrorOccurred
	lsls r0, 24
	cmp r0, 0
	beq _081D4F08
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x3
	b _081D500E
_081D4F08:
	ldrb r0, [r4]
	cmp r0, 0x5
	bls _081D4F10
	b _081D500C
_081D4F10:
	lsls r0, 2
	ldr r1, =_081D4F20
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D4F20:
	.4byte _081D4F38
	.4byte _081D4F54
	.4byte _081D4F6C
	.4byte _081D4FA0
	.4byte _081D4FEC
	.4byte _081D4FF8
_081D4F38:
	bl IsLinkMaster
	lsls r0, 24
	cmp r0, 0
	beq _081D4F88
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _081D4F88
	movs r0, 0x1
	strb r0, [r4]
	b _081D500C
_081D4F54:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x5
	bls _081D500C
	movs r0, 0
	strh r0, [r5]
	movs r0, 0x2
	strb r0, [r4]
	b _081D500C
_081D4F6C:
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x2
	bne _081D4F88
	movs r0, 0x49
	bl PlaySE
	bl CheckShouldAdvanceLinkState
	movs r0, 0
	strh r0, [r5]
	b _081D4FE6
_081D4F88:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D500C
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x1
	b _081D500E
	.pool
_081D4FA0:
	ldrh r0, [r5]
	adds r0, 0x1
	strh r0, [r5]
	lsls r0, 16
	lsrs r0, 16
	cmp r0, 0x1E
	bls _081D4FB6
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x5
	b _081D500E
_081D4FB6:
	bl IsLinkConnectionEstablished
	lsls r0, 24
	cmp r0, 0
	beq _081D500C
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	beq _081D4FE6
	bl IsLinkPlayerDataExchangeComplete
	lsls r0, 24
	cmp r0, 0
	beq _081D4FE0
	movs r0, 0
	strb r0, [r4]
	movs r0, 0x2
	b _081D500E
	.pool
_081D4FE0:
	movs r0, 0x4
	strb r0, [r4]
	b _081D500C
_081D4FE6:
	movs r0, 0x3
	strb r0, [r4]
	b _081D500C
_081D4FEC:
	movs r0, 0
	bl sub_800ABF4
	movs r0, 0x5
	strb r0, [r4]
	b _081D500C
_081D4FF8:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D500C
	strb r0, [r4]
	movs r0, 0x4
	b _081D500E
	.pool
_081D500C:
	movs r0, 0
_081D500E:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_81D4EE4

	thumb_func_start sub_81D5014
sub_81D5014: @ 81D5014
	push {r4,lr}
	ldr r0, =sub_81D5084
	movs r1, 0
	bl CreateTask
	lsls r0, 24
	lsrs r0, 24
	lsls r4, r0, 2
	adds r4, r0
	lsls r4, 3
	ldr r0, =gTasks + 0x8
	adds r4, r0
	movs r0, 0
	strb r0, [r4, 0x8]
	strb r0, [r4, 0x9]
	strb r0, [r4, 0xA]
	strb r0, [r4, 0xB]
	strb r0, [r4, 0xC]
	strb r0, [r4, 0xD]
	movs r1, 0
	strh r0, [r4]
	strh r0, [r4, 0x2]
	strh r0, [r4, 0x4]
	strh r0, [r4, 0x6]
	strb r1, [r4, 0xE]
	movs r0, 0x40
	bl AllocZeroed
	str r0, [r4, 0x10]
	pop {r4}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5014

	thumb_func_start sub_81D505C
sub_81D505C: @ 81D505C
	movs r1, 0
	strh r1, [r0]
	bx lr
	thumb_func_end sub_81D505C

	thumb_func_start sub_81D5064
sub_81D5064: @ 81D5064
	push {lr}
	adds r2, r0, 0
	lsls r1, 16
	ldrh r0, [r2]
	adds r0, 0x1
	strh r0, [r2]
	lsls r0, 16
	cmp r0, r1
	bhi _081D507A
	movs r0, 0
	b _081D5080
_081D507A:
	movs r0, 0
	strh r0, [r2]
	movs r0, 0x1
_081D5080:
	pop {r1}
	bx r1
	thumb_func_end sub_81D5064

	thumb_func_start sub_81D5084
sub_81D5084: @ 81D5084
	push {r4,r5,lr}
	lsls r0, 24
	lsrs r5, r0, 24
	lsls r0, r5, 2
	adds r0, r5
	lsls r0, 3
	ldr r1, =gTasks + 0x8
	adds r4, r0, r1
	ldrb r0, [r4, 0x8]
	cmp r0, 0x1A
	bls _081D509C
	b _081D548A
_081D509C:
	lsls r0, 2
	ldr r1, =_081D50B0
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D50B0:
	.4byte _081D511C
	.4byte _081D5138
	.4byte _081D5148
	.4byte _081D515C
	.4byte _081D516C
	.4byte _081D5198
	.4byte _081D51D0
	.4byte _081D524C
	.4byte _081D5268
	.4byte _081D5290
	.4byte _081D52AC
	.4byte _081D52DC
	.4byte _081D52F2
	.4byte _081D5308
	.4byte _081D536A
	.4byte _081D5390
	.4byte _081D53A8
	.4byte _081D53C6
	.4byte _081D53F2
	.4byte _081D5418
	.4byte _081D5448
	.4byte _081D5454
	.4byte _081D5460
	.4byte _081D5430
	.4byte _081D548A
	.4byte _081D548A
	.4byte _081D5478
_081D511C:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EDFD6
	bl mevent_0814257C
	cmp r0, 0
	bne _081D512C
	b _081D548A
_081D512C:
	movs r0, 0x1
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5138:
	bl sub_81D4E30
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x2
	strb r0, [r4, 0x8]
	b _081D548A
_081D5148:
	adds r0, r4, 0
	movs r1, 0xA
	bl sub_81D5064
	cmp r0, 0
	bne _081D5156
	b _081D548A
_081D5156:
	movs r0, 0x3
	strb r0, [r4, 0x8]
	b _081D548A
_081D515C:
	bl sub_81D4EC0
	cmp r0, 0
	beq _081D5166
	b _081D52FC
_081D5166:
	bl CloseLink
	b _081D525C
_081D516C:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EDFF5
	bl mevent_0814257C
	cmp r0, 0
	bne _081D517C
	b _081D548A
_081D517C:
	ldr r0, =gUnknown_085EE014
	bl sub_8018884
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x5
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5198:
	adds r0, r4, 0
	movs r1, 0x5A
	bl sub_81D5064
	cmp r0, 0
	beq _081D51AE
	bl sub_81D4E30
	movs r0, 0x6
	strb r0, [r4, 0x8]
	b _081D548A
_081D51AE:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	bne _081D51BC
	b _081D548A
_081D51BC:
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x5
	bl PlaySE
	b _081D535A
	.pool
_081D51D0:
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x2
	ands r0, r1
	cmp r0, 0
	beq _081D51F4
	movs r0, 0x5
	bl PlaySE
	bl CloseLink
	adds r0, r4, 0
	bl sub_81D505C
	b _081D535A
	.pool
_081D51F4:
	bl GetLinkPlayerCount_2
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0x1
	bls _081D5210
	adds r0, r4, 0
	bl sub_81D505C
	bl CloseLink
	movs r0, 0x7
	strb r0, [r4, 0x8]
	b _081D548A
_081D5210:
	bl sub_81D4E60
	cmp r0, 0
	beq _081D522E
	movs r0, 0x5
	bl PlaySE
	bl CloseLink
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x8
	strb r0, [r4, 0x8]
	b _081D548A
_081D522E:
	adds r0, r4, 0
	movs r1, 0xA
	bl sub_81D5064
	cmp r0, 0
	bne _081D523C
	b _081D548A
_081D523C:
	bl CloseLink
	bl sub_81D4E30
	adds r0, r4, 0
	bl sub_81D505C
	b _081D548A
_081D524C:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE05C
	bl mevent_0814257C
	cmp r0, 0
	bne _081D525C
	b _081D548A
_081D525C:
	movs r0, 0x4
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5268:
	ldr r0, =gUnknown_085EE097
	bl sub_8018884
	ldr r0, =gUnknown_03006370
	ldr r1, =gMultiBootProgram_BerryGlitchFix_Start
	ldr r2, =gUnknown_089A3470
	subs r1, r2
	bl sub_81D4D50
	movs r0, 0x9
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5290:
	ldr r0, =gUnknown_03006370
	bl sub_81D4DE8
	strb r0, [r4, 0xE]
	lsls r0, 24
	cmp r0, 0
	bne _081D52A0
	b _081D548A
_081D52A0:
	movs r0, 0xA
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D52AC:
	ldr r0, =gUnknown_03006370
	bl sub_81D4DB8
	ldrb r0, [r4, 0xE]
	cmp r0, 0x3
	bne _081D52BA
	b _081D53C0
_081D52BA:
	cmp r0, 0x1
	beq _081D52C0
	b _081D546E
_081D52C0:
	adds r0, r4, 0
	bl sub_81D505C
	ldr r0, =gUnknown_085EE120
	bl sub_8018884
	movs r0, 0xB
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D52DC:
	movs r1, 0xD2
	lsls r1, 2
	adds r0, r4, 0
	bl sub_81D5064
	cmp r0, 0
	bne _081D52EC
	b _081D548A
_081D52EC:
	movs r0, 0xC
	strb r0, [r4, 0x8]
	b _081D548A
_081D52F2:
	bl sub_81D4E30
	ldr r0, =gUnknown_085EE0DC
	bl sub_8018884
_081D52FC:
	movs r0, 0xD
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5308:
	adds r0, r4, 0
	adds r0, 0x9
	adds r1, r4, 0
	bl sub_81D4EE4
	cmp r0, 0x5
	bls _081D5318
	b _081D548A
_081D5318:
	lsls r0, 2
	ldr r1, =_081D5328
	adds r0, r1
	ldr r0, [r0]
	mov pc, r0
	.pool
	.align 2, 0
_081D5328:
	.4byte _081D548A
	.4byte _081D5350
	.4byte _081D5340
	.4byte _081D5374
	.4byte _081D5374
	.4byte _081D5360
_081D5340:
	ldr r0, =gUnknown_085EE097
	bl sub_8018884
	movs r0, 0xE
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5350:
	movs r0, 0x5
	bl PlaySE
	bl CloseLink
_081D535A:
	movs r0, 0x17
	strb r0, [r4, 0x8]
	b _081D548A
_081D5360:
	bl CloseLink
	movs r0, 0x15
	strb r0, [r4, 0x8]
	b _081D548A
_081D536A:
	bl HasLinkErrorOccurred
	lsls r0, 24
	cmp r0, 0
	beq _081D537A
_081D5374:
	bl CloseLink
	b _081D53C0
_081D537A:
	bl GetBlockReceivedStatus
	lsls r0, 24
	cmp r0, 0
	bne _081D5386
	b _081D548A
_081D5386:
	bl ResetBlockReceivedFlags
	movs r0, 0xF
	strb r0, [r4, 0x8]
	b _081D548A
_081D5390:
	ldr r0, =gDecompressionBuffer
	bl sub_81D3920
	strb r0, [r4, 0xE]
	ldrb r0, [r4, 0xE]
	bl sub_800ABF4
	movs r0, 0x10
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D53A8:
	ldr r0, =gReceivedRemoteLinkPlayers
	ldrb r0, [r0]
	cmp r0, 0
	bne _081D548A
	ldrb r0, [r4, 0xE]
	cmp r0, 0x1
	bne _081D53C0
	movs r0, 0x11
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D53C0:
	movs r0, 0x14
	strb r0, [r4, 0x8]
	b _081D548A
_081D53C6:
	ldr r0, =gDecompressionBuffer
	bl sub_81D3AB0
	cmp r0, 0
	beq _081D53EC
	ldr r0, =gUnknown_085EE0FA
	bl sub_8018884
	adds r0, r4, 0
	bl sub_81D505C
	movs r0, 0x12
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D53EC:
	movs r0, 0x16
	strb r0, [r4, 0x8]
	b _081D548A
_081D53F2:
	adds r0, r4, 0
	movs r1, 0x78
	bl sub_81D5064
	cmp r0, 0
	beq _081D548A
	ldr r0, =gUnknown_085EE107
	bl sub_8018884
	movs r0, 0xB9
	lsls r0, 1
	bl PlayFanfare
	movs r0, 0x13
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5418:
	bl IsFanfareTaskInactive
	lsls r0, 24
	cmp r0, 0
	beq _081D548A
	ldr r0, =gMain
	ldrh r1, [r0, 0x2E]
	movs r0, 0x3
	ands r0, r1
	b _081D543A
	.pool
_081D5430:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE06B
	bl mevent_0814257C
_081D543A:
	cmp r0, 0
	beq _081D548A
	movs r0, 0x1A
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5448:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE0A3
	b _081D5466
	.pool
_081D5454:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE0BF
	b _081D5466
	.pool
_081D5460:
	adds r0, r4, 0
	adds r0, 0x9
	ldr r1, =gUnknown_085EE12D
_081D5466:
	bl mevent_0814257C
	cmp r0, 0
	beq _081D548A
_081D546E:
	movs r0, 0
	strb r0, [r4, 0x8]
	b _081D548A
	.pool
_081D5478:
	ldr r0, [r4, 0x10]
	bl Free
	adds r0, r5, 0
	bl DestroyTask
	ldr r0, =sub_80186A4
	bl SetMainCallback2
_081D548A:
	pop {r4,r5}
	pop {r0}
	bx r0
	.pool
	thumb_func_end sub_81D5084

	.align 2, 0 @ Don't pad with nop.
