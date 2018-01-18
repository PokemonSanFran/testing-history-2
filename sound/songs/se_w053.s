	.include "MPlayDef.s"

	.equ	se_w053_grp, voicegroup_869D6F4
	.equ	se_w053_pri, 4
	.equ	se_w053_rev, reverb_set+50
	.equ	se_w053_mvl, 127
	.equ	se_w053_key, 0
	.equ	se_w053_tbs, 1
	.equ	se_w053_exg, 0
	.equ	se_w053_cmp, 1

	.section .rodata
	.global	se_w053
	.align	2

@********************** Track  1 **********************@

se_w053_1:
	.byte	KEYSH , se_w053_key+0
	.byte	TEMPO , 150*se_w053_tbs/2
	.byte		VOICE , 29
	.byte		BENDR , 12
	.byte		VOL   , 110*se_w053_mvl/mxv
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+50
	.byte		TIE   , Cn3 , v127
	.byte	W01
	.byte		BEND  , c_v+32
	.byte	W02
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v+16
	.byte	W02
	.byte		        c_v-8
	.byte	W02
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v-15
	.byte	W02
	.byte		        c_v-10
	.byte	W01
	.byte		PAN   , c_v-9
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		PAN   , c_v+4
	.byte		BEND  , c_v+2
	.byte	W04
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v+10
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+16
	.byte	W03
	.byte		PAN   , c_v+4
	.byte	W01
	.byte		BEND  , c_v+21
	.byte	W02
	.byte		PAN   , c_v-5
	.byte	W04
	.byte		        c_v+8
	.byte	W03
	.byte		        c_v-9
	.byte	W04
	.byte		        c_v+4
	.byte	W04
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v+0
	.byte	W03
se_w053_1_000:
	.byte		PAN   , c_v+4
	.byte	W03
	.byte		        c_v-5
	.byte	W04
	.byte		        c_v+8
	.byte	W03
	.byte		        c_v-9
	.byte	W04
	.byte		        c_v+4
	.byte	W04
	.byte		        c_v-5
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	se_w053_1_000
	.byte	PATT
	 .word	se_w053_1_000
	.byte	PATT
	 .word	se_w053_1_000
	.byte		PAN   , c_v+4
	.byte	W03
	.byte		        c_v-5
	.byte	W03
	.byte		VOL   , 103*se_w053_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+8
	.byte	W03
	.byte		VOL   , 96*se_w053_mvl/mxv
	.byte		PAN   , c_v-9
	.byte	W04
	.byte		        c_v+4
	.byte	W02
	.byte		VOL   , 88*se_w053_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-5
	.byte	W03
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 73*se_w053_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+4
	.byte	W03
	.byte		VOL   , 62*se_w053_mvl/mxv
	.byte		PAN   , c_v-5
	.byte	W04
	.byte		        c_v+8
	.byte	W01
	.byte		VOL   , 47*se_w053_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-9
	.byte	W03
	.byte		VOL   , 27*se_w053_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+4
	.byte	W04
	.byte		VOL   , 10*se_w053_mvl/mxv
	.byte		PAN   , c_v-5
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte		EOT   , Cn3 
	.byte	FINE

@********************** Track  2 **********************@

se_w053_2:
	.byte	KEYSH , se_w053_key+0
	.byte		VOICE , 27
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_w053_mvl/mxv
	.byte		N24   , Fn2 , v060
	.byte	W10
	.byte		VOL   , 99*se_w053_mvl/mxv
	.byte	W05
	.byte		        82*se_w053_mvl/mxv
	.byte	W04
	.byte		        54*se_w053_mvl/mxv
	.byte	W02
	.byte		        25*se_w053_mvl/mxv
	.byte	W03
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_w053:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w053_pri	@ Priority
	.byte	se_w053_rev	@ Reverb.

	.word	se_w053_grp

	.word	se_w053_1
	.word	se_w053_2

	.end
