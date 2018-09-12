#include "constants/battle.h"
#include "constants/battle_anim.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/moves.h"
	.include "asm/macros.inc"
	.include "asm/macros/battle_anim_script.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.align 2
gMovesWithQuietBGM::
	.2byte MOVE_SING, MOVE_PERISH_SONG, MOVE_GRASS_WHISTLE, 0xFFFF

	.align 2
gBattleAnims_Moves::
	.4byte Move_NONE
	.4byte Move_POUND
	.4byte Move_KARATE_CHOP
	.4byte Move_DOUBLE_SLAP
	.4byte Move_COMET_PUNCH
	.4byte Move_MEGA_PUNCH
	.4byte Move_PAY_DAY
	.4byte Move_FIRE_PUNCH
	.4byte Move_ICE_PUNCH
	.4byte Move_THUNDER_PUNCH
	.4byte Move_SCRATCH
	.4byte Move_VICE_GRIP
	.4byte Move_GUILLOTINE
	.4byte Move_RAZOR_WIND
	.4byte Move_SWORDS_DANCE
	.4byte Move_CUT
	.4byte Move_GUST
	.4byte Move_WING_ATTACK
	.4byte Move_WHIRLWIND
	.4byte Move_FLY
	.4byte Move_BIND
	.4byte Move_SLAM
	.4byte Move_VINE_WHIP
	.4byte Move_STOMP
	.4byte Move_DOUBLE_KICK
	.4byte Move_MEGA_KICK
	.4byte Move_JUMP_KICK
	.4byte Move_ROLLING_KICK
	.4byte Move_SAND_ATTACK
	.4byte Move_HEADBUTT
	.4byte Move_HORN_ATTACK
	.4byte Move_FURY_ATTACK
	.4byte Move_HORN_DRILL
	.4byte Move_TACKLE
	.4byte Move_BODY_SLAM
	.4byte Move_WRAP
	.4byte Move_TAKE_DOWN
	.4byte Move_THRASH
	.4byte Move_DOUBLE_EDGE
	.4byte Move_TAIL_WHIP
	.4byte Move_POISON_STING
	.4byte Move_TWINEEDLE
	.4byte Move_PIN_MISSILE
	.4byte Move_LEER
	.4byte Move_BITE
	.4byte Move_GROWL
	.4byte Move_ROAR
	.4byte Move_SING
	.4byte Move_SUPERSONIC
	.4byte Move_SONIC_BOOM
	.4byte Move_DISABLE
	.4byte Move_ACID
	.4byte Move_EMBER
	.4byte Move_FLAMETHROWER
	.4byte Move_MIST
	.4byte Move_WATER_GUN
	.4byte Move_HYDRO_PUMP
	.4byte Move_SURF
	.4byte Move_ICE_BEAM
	.4byte Move_BLIZZARD
	.4byte Move_PSYBEAM
	.4byte Move_BUBBLE_BEAM
	.4byte Move_AURORA_BEAM
	.4byte Move_HYPER_BEAM
	.4byte Move_PECK
	.4byte Move_DRILL_PECK
	.4byte Move_SUBMISSION
	.4byte Move_LOW_KICK
	.4byte Move_COUNTER
	.4byte Move_SEISMIC_TOSS
	.4byte Move_STRENGTH
	.4byte Move_ABSORB
	.4byte Move_MEGA_DRAIN
	.4byte Move_LEECH_SEED
	.4byte Move_GROWTH
	.4byte Move_RAZOR_LEAF
	.4byte Move_SOLAR_BEAM
	.4byte Move_POISON_POWDER
	.4byte Move_STUN_SPORE
	.4byte Move_SLEEP_POWDER
	.4byte Move_PETAL_DANCE
	.4byte Move_STRING_SHOT
	.4byte Move_DRAGON_RAGE
	.4byte Move_FIRE_SPIN
	.4byte Move_THUNDER_SHOCK
	.4byte Move_THUNDERBOLT
	.4byte Move_THUNDER_WAVE
	.4byte Move_THUNDER
	.4byte Move_ROCK_THROW
	.4byte Move_EARTHQUAKE
	.4byte Move_FISSURE
	.4byte Move_DIG
	.4byte Move_TOXIC
	.4byte Move_CONFUSION
	.4byte Move_PSYCHIC
	.4byte Move_HYPNOSIS
	.4byte Move_MEDITATE
	.4byte Move_AGILITY
	.4byte Move_QUICK_ATTACK
	.4byte Move_RAGE
	.4byte Move_TELEPORT
	.4byte Move_NIGHT_SHADE
	.4byte Move_MIMIC
	.4byte Move_SCREECH
	.4byte Move_DOUBLE_TEAM
	.4byte Move_RECOVER
	.4byte Move_HARDEN
	.4byte Move_MINIMIZE
	.4byte Move_SMOKESCREEN
	.4byte Move_CONFUSE_RAY
	.4byte Move_WITHDRAW
	.4byte Move_DEFENSE_CURL
	.4byte Move_BARRIER
	.4byte Move_LIGHT_SCREEN
	.4byte Move_HAZE
	.4byte Move_REFLECT
	.4byte Move_FOCUS_ENERGY
	.4byte Move_BIDE
	.4byte Move_METRONOME
	.4byte Move_MIRROR_MOVE @ doesn't have an actual animation
	.4byte Move_SELF_DESTRUCT
	.4byte Move_EGG_BOMB
	.4byte Move_LICK
	.4byte Move_SMOG
	.4byte Move_SLUDGE
	.4byte Move_BONE_CLUB
	.4byte Move_FIRE_BLAST
	.4byte Move_WATERFALL
	.4byte Move_CLAMP
	.4byte Move_SWIFT
	.4byte Move_SKULL_BASH
	.4byte Move_SPIKE_CANNON
	.4byte Move_CONSTRICT
	.4byte Move_AMNESIA
	.4byte Move_KINESIS
	.4byte Move_SOFT_BOILED
	.4byte Move_HI_JUMP_KICK
	.4byte Move_GLARE
	.4byte Move_DREAM_EATER
	.4byte Move_POISON_GAS
	.4byte Move_BARRAGE
	.4byte Move_LEECH_LIFE
	.4byte Move_LOVELY_KISS
	.4byte Move_SKY_ATTACK
	.4byte Move_TRANSFORM
	.4byte Move_BUBBLE
	.4byte Move_DIZZY_PUNCH
	.4byte Move_SPORE
	.4byte Move_FLASH
	.4byte Move_PSYWAVE
	.4byte Move_SPLASH
	.4byte Move_ACID_ARMOR
	.4byte Move_CRABHAMMER
	.4byte Move_EXPLOSION
	.4byte Move_FURY_SWIPES
	.4byte Move_BONEMERANG
	.4byte Move_REST
	.4byte Move_ROCK_SLIDE
	.4byte Move_HYPER_FANG
	.4byte Move_SHARPEN
	.4byte Move_CONVERSION
	.4byte Move_TRI_ATTACK
	.4byte Move_SUPER_FANG
	.4byte Move_SLASH
	.4byte Move_SUBSTITUTE
	.4byte Move_STRUGGLE
	.4byte Move_SKETCH
	.4byte Move_TRIPLE_KICK
	.4byte Move_THIEF
	.4byte Move_SPIDER_WEB
	.4byte Move_MIND_READER
	.4byte Move_NIGHTMARE
	.4byte Move_FLAME_WHEEL
	.4byte Move_SNORE
	.4byte Move_CURSE
	.4byte Move_FLAIL
	.4byte Move_CONVERSION_2
	.4byte Move_AEROBLAST
	.4byte Move_COTTON_SPORE
	.4byte Move_REVERSAL
	.4byte Move_SPITE
	.4byte Move_POWDER_SNOW
	.4byte Move_PROTECT
	.4byte Move_MACH_PUNCH
	.4byte Move_SCARY_FACE
	.4byte Move_FAINT_ATTACK
	.4byte Move_SWEET_KISS
	.4byte Move_BELLY_DRUM
	.4byte Move_SLUDGE_BOMB
	.4byte Move_MUD_SLAP
	.4byte Move_OCTAZOOKA
	.4byte Move_SPIKES
	.4byte Move_ZAP_CANNON
	.4byte Move_FORESIGHT
	.4byte Move_DESTINY_BOND
	.4byte Move_PERISH_SONG
	.4byte Move_ICY_WIND
	.4byte Move_DETECT
	.4byte Move_BONE_RUSH
	.4byte Move_LOCK_ON
	.4byte Move_OUTRAGE
	.4byte Move_SANDSTORM
	.4byte Move_GIGA_DRAIN
	.4byte Move_ENDURE
	.4byte Move_CHARM
	.4byte Move_ROLLOUT
	.4byte Move_FALSE_SWIPE
	.4byte Move_SWAGGER
	.4byte Move_MILK_DRINK
	.4byte Move_SPARK
	.4byte Move_FURY_CUTTER
	.4byte Move_STEEL_WING
	.4byte Move_MEAN_LOOK
	.4byte Move_ATTRACT
	.4byte Move_SLEEP_TALK
	.4byte Move_HEAL_BELL
	.4byte Move_RETURN
	.4byte Move_PRESENT
	.4byte Move_FRUSTRATION
	.4byte Move_SAFEGUARD
	.4byte Move_PAIN_SPLIT
	.4byte Move_SACRED_FIRE
	.4byte Move_MAGNITUDE
	.4byte Move_DYNAMIC_PUNCH
	.4byte Move_MEGAHORN
	.4byte Move_DRAGON_BREATH
	.4byte Move_BATON_PASS
	.4byte Move_ENCORE
	.4byte Move_PURSUIT
	.4byte Move_RAPID_SPIN
	.4byte Move_SWEET_SCENT
	.4byte Move_IRON_TAIL
	.4byte Move_METAL_CLAW
	.4byte Move_VITAL_THROW
	.4byte Move_MORNING_SUN
	.4byte Move_SYNTHESIS
	.4byte Move_MOONLIGHT
	.4byte Move_HIDDEN_POWER
	.4byte Move_CROSS_CHOP
	.4byte Move_TWISTER
	.4byte Move_RAIN_DANCE
	.4byte Move_SUNNY_DAY
	.4byte Move_CRUNCH
	.4byte Move_MIRROR_COAT
	.4byte Move_PSYCH_UP
	.4byte Move_EXTREME_SPEED
	.4byte Move_ANCIENT_POWER
	.4byte Move_SHADOW_BALL
	.4byte Move_FUTURE_SIGHT
	.4byte Move_ROCK_SMASH
	.4byte Move_WHIRLPOOL
	.4byte Move_BEAT_UP
	.4byte Move_FAKE_OUT
	.4byte Move_UPROAR
	.4byte Move_STOCKPILE
	.4byte Move_SPIT_UP
	.4byte Move_SWALLOW
	.4byte Move_HEAT_WAVE
	.4byte Move_HAIL
	.4byte Move_TORMENT
	.4byte Move_FLATTER
	.4byte Move_WILL_O_WISP
	.4byte Move_MEMENTO
	.4byte Move_FACADE
	.4byte Move_FOCUS_PUNCH
	.4byte Move_SMELLING_SALT
	.4byte Move_FOLLOW_ME
	.4byte Move_NATURE_POWER @ doesnt have an actual animation
	.4byte Move_CHARGE
	.4byte Move_TAUNT
	.4byte Move_HELPING_HAND
	.4byte Move_TRICK
	.4byte Move_ROLE_PLAY
	.4byte Move_WISH
	.4byte Move_ASSIST
	.4byte Move_INGRAIN
	.4byte Move_SUPERPOWER
	.4byte Move_MAGIC_COAT
	.4byte Move_RECYCLE
	.4byte Move_REVENGE
	.4byte Move_BRICK_BREAK
	.4byte Move_YAWN
	.4byte Move_KNOCK_OFF
	.4byte Move_ENDEAVOR
	.4byte Move_ERUPTION
	.4byte Move_SKILL_SWAP
	.4byte Move_IMPRISON
	.4byte Move_REFRESH
	.4byte Move_GRUDGE
	.4byte Move_SNATCH
	.4byte Move_SECRET_POWER
	.4byte Move_DIVE
	.4byte Move_ARM_THRUST
	.4byte Move_CAMOUFLAGE
	.4byte Move_TAIL_GLOW
	.4byte Move_LUSTER_PURGE
	.4byte Move_MIST_BALL
	.4byte Move_FEATHER_DANCE
	.4byte Move_TEETER_DANCE
	.4byte Move_BLAZE_KICK
	.4byte Move_MUD_SPORT
	.4byte Move_ICE_BALL
	.4byte Move_NEEDLE_ARM
	.4byte Move_SLACK_OFF
	.4byte Move_HYPER_VOICE
	.4byte Move_POISON_FANG
	.4byte Move_CRUSH_CLAW
	.4byte Move_BLAST_BURN
	.4byte Move_HYDRO_CANNON
	.4byte Move_METEOR_MASH
	.4byte Move_ASTONISH
	.4byte Move_WEATHER_BALL
	.4byte Move_AROMATHERAPY
	.4byte Move_FAKE_TEARS
	.4byte Move_AIR_CUTTER
	.4byte Move_OVERHEAT
	.4byte Move_ODOR_SLEUTH
	.4byte Move_ROCK_TOMB
	.4byte Move_SILVER_WIND
	.4byte Move_METAL_SOUND
	.4byte Move_GRASS_WHISTLE
	.4byte Move_TICKLE
	.4byte Move_COSMIC_POWER
	.4byte Move_WATER_SPOUT
	.4byte Move_SIGNAL_BEAM
	.4byte Move_SHADOW_PUNCH
	.4byte Move_EXTRASENSORY
	.4byte Move_SKY_UPPERCUT
	.4byte Move_SAND_TOMB
	.4byte Move_SHEER_COLD
	.4byte Move_MUDDY_WATER
	.4byte Move_BULLET_SEED
	.4byte Move_AERIAL_ACE
	.4byte Move_ICICLE_SPEAR
	.4byte Move_IRON_DEFENSE
	.4byte Move_BLOCK
	.4byte Move_HOWL
	.4byte Move_DRAGON_CLAW
	.4byte Move_FRENZY_PLANT
	.4byte Move_BULK_UP
	.4byte Move_BOUNCE
	.4byte Move_MUD_SHOT
	.4byte Move_POISON_TAIL
	.4byte Move_COVET
	.4byte Move_VOLT_TACKLE
	.4byte Move_MAGICAL_LEAF
	.4byte Move_WATER_SPORT
	.4byte Move_CALM_MIND
	.4byte Move_LEAF_BLADE
	.4byte Move_DRAGON_DANCE
	.4byte Move_ROCK_BLAST
	.4byte Move_SHOCK_WAVE
	.4byte Move_WATER_PULSE
	.4byte Move_DOOM_DESIRE
	.4byte Move_PSYCHO_BOOST
	.4byte Move_COUNT @ cannot be reached, because last move is Psycho Boost

	.align 2
gBattleAnims_StatusConditions::
	.4byte Status_Poison
	.4byte Status_Confusion
	.4byte Status_Burn
	.4byte Status_Infatuation
	.4byte Status_Sleep
	.4byte Status_Paralysis
	.4byte Status_Freeze
	.4byte Status_Curse
	.4byte Status_Nightmare

	.align 2
gBattleAnims_General::
	.4byte General_CastformChange
	.4byte General_StatsChange
	.4byte General_SubstituteFade
	.4byte General_SubstituteAppear
	.4byte General_PokeblockThrow
	.4byte General_ItemKnockoff
	.4byte General_TurnTrap
	.4byte General_ItemEffect
	.4byte General_SmokeballEscape
	.4byte General_HangedOn
	.4byte General_Rain
	.4byte General_Sun
	.4byte General_Sandstorm
	.4byte General_Hail
	.4byte General_LeechSeedDrain
	.4byte General_MonHit
	.4byte General_ItemSteal
	.4byte General_SnatchMove
	.4byte General_FutureSightHit
	.4byte General_DoomDesireHit
	.4byte General_FocusPunchSetUp
	.4byte General_IngrainHeal
	.4byte General_WishHeal

	.align 2
gBattleAnims_Special::
	.4byte Special_LevelUp
	.4byte Special_SwitchOutPlayerMon
	.4byte Special_SwitchOutOpponentMon
	.4byte Special_BallThrow
	.4byte Special_SafariBallThrow
	.4byte Special_SubstituteToMon
	.4byte Special_MonToSubstitute

Move_NONE:
Move_MIRROR_MOVE:
Move_POUND:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W003, +63
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_DOUBLE_SLAP:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	setalpha 12, 8
	choosetwoturnanim DoubleSlapLeft, DoubleSlapRight
DoubleSlapContinue:
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W003, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
DoubleSlapLeft:
	createsprite gBasicHitSplatSpriteTemplate, 2, -8, 0, 1, 2
	goto DoubleSlapContinue
DoubleSlapRight:
	createsprite gBasicHitSplatSpriteTemplate, 2, 8, 0, 1, 2
	goto DoubleSlapContinue

Move_POISON_POWDER:
	loadspritegfx 0x2751
	loadspritegfx 0x27A6
	loopsewithpan SE_W077, +63, 10, 6
	createsprite gPoisonPowderParticleSpriteTemplate, 130, -30, -22, 117, 80, 5, 1
	createsprite gPoisonPowderParticleSpriteTemplate, 130, 10, -22, 117, 80, -5, 1
	createsprite gPoisonPowderParticleSpriteTemplate, 130, -25, -22, 117, 112, 5, 3
	delay 15
	createsprite gPoisonPowderParticleSpriteTemplate, 130, -5, -22, 117, 80, -5, 1
	createsprite gPoisonPowderParticleSpriteTemplate, 130, 5, -22, 117, 96, 5, 1
	createsprite gPoisonPowderParticleSpriteTemplate, 130, 0, -22, 117, 69, -5, 1
	createsprite gPoisonPowderParticleSpriteTemplate, 130, -15, -22, 117, 112, 5, 2
	delay 30
	createsprite gPoisonPowderParticleSpriteTemplate, 130, -15, -22, 117, 112, 5, 2
	createsprite gPoisonPowderParticleSpriteTemplate, 130, 15, -22, 117, 80, -5, 1
	createsprite gPoisonPowderParticleSpriteTemplate, 130, -10, -22, 117, 96, 7, 2
	createsprite gPoisonPowderParticleSpriteTemplate, 130, -5, -22, 117, 90, -8, 0
	delay 20
	createsprite gPoisonPowderParticleSpriteTemplate, 130, -10, -22, 117, 80, -5, 1
	createsprite gPoisonPowderParticleSpriteTemplate, 130, 0, -22, 117, 89, 5, 2
	createsprite gPoisonPowderParticleSpriteTemplate, 130, 20, -22, 117, 112, -8, 2
	createsprite gPoisonPowderParticleSpriteTemplate, 130, 5, -22, 117, 80, 5, 1
	waitforvisualfinish
	end

Move_STUN_SPORE:
	loadspritegfx 0x2754
	loopsewithpan SE_W077, +63, 10, 6
	createsprite gStunSporeParticleSpriteTemplate, 130, -30, -22, 117, 80, 5, 1
	createsprite gStunSporeParticleSpriteTemplate, 130, 10, -22, 117, 80, -5, 1
	createsprite gStunSporeParticleSpriteTemplate, 130, -25, -22, 117, 112, 5, 3
	delay 15
	createsprite gStunSporeParticleSpriteTemplate, 130, -5, -22, 117, 80, -5, 1
	createsprite gStunSporeParticleSpriteTemplate, 130, 5, -22, 117, 96, 5, 1
	createsprite gStunSporeParticleSpriteTemplate, 130, 0, -22, 117, 69, -5, 1
	createsprite gStunSporeParticleSpriteTemplate, 130, -15, -22, 117, 112, 5, 2
	delay 30
	createsprite gStunSporeParticleSpriteTemplate, 130, -15, -22, 117, 112, 5, 2
	createsprite gStunSporeParticleSpriteTemplate, 130, 15, -22, 117, 80, -5, 1
	createsprite gStunSporeParticleSpriteTemplate, 130, -10, -22, 117, 96, 7, 2
	createsprite gStunSporeParticleSpriteTemplate, 130, -5, -22, 117, 90, -8, 0
	delay 20
	createsprite gStunSporeParticleSpriteTemplate, 130, -10, -22, 117, 80, -5, 1
	createsprite gStunSporeParticleSpriteTemplate, 130, 0, -22, 117, 89, 5, 2
	createsprite gStunSporeParticleSpriteTemplate, 130, 20, -22, 117, 112, -8, 2
	createsprite gStunSporeParticleSpriteTemplate, 130, 5, -22, 117, 80, 5, 1
	waitforvisualfinish
	end

Move_SLEEP_POWDER:
	loadspritegfx 0x2753
	loopsewithpan SE_W077, +63, 10, 6
	createsprite gSleepPowderParticleSpriteTemplate, 130, -30, -22, 117, 80, 5, 1
	createsprite gSleepPowderParticleSpriteTemplate, 130, 10, -22, 117, 80, -5, 1
	createsprite gSleepPowderParticleSpriteTemplate, 130, -25, -22, 117, 112, 5, 3
	delay 15
	createsprite gSleepPowderParticleSpriteTemplate, 130, -5, -22, 117, 80, -5, 1
	createsprite gSleepPowderParticleSpriteTemplate, 130, 5, -22, 117, 96, 5, 1
	createsprite gSleepPowderParticleSpriteTemplate, 130, 0, -22, 117, 69, -5, 1
	createsprite gSleepPowderParticleSpriteTemplate, 130, -15, -22, 117, 112, 5, 2
	delay 30
	createsprite gSleepPowderParticleSpriteTemplate, 130, -15, -22, 117, 112, 5, 2
	createsprite gSleepPowderParticleSpriteTemplate, 130, 15, -22, 117, 80, -5, 1
	createsprite gSleepPowderParticleSpriteTemplate, 130, -10, -22, 117, 96, 7, 2
	createsprite gSleepPowderParticleSpriteTemplate, 130, -5, -22, 117, 90, -8, 0
	delay 20
	createsprite gSleepPowderParticleSpriteTemplate, 130, -10, -22, 117, 80, -5, 1
	createsprite gSleepPowderParticleSpriteTemplate, 130, 0, -22, 117, 89, 5, 2
	createsprite gSleepPowderParticleSpriteTemplate, 130, 20, -22, 117, 112, -8, 2
	createsprite gSleepPowderParticleSpriteTemplate, 130, 5, -22, 117, 80, 5, 1
	waitforvisualfinish
	end

Move_SWIFT:
	loadspritegfx 0x27BE
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W129, -64
	createsprite gSwiftStarSpriteTemplate, 131, 20, -10, 20, 0, 22, 20, 1
	delay 5
	playsewithpan SE_W129, -64
	createsprite gSwiftStarSpriteTemplate, 131, 20, -10, 20, 5, 22, -18, 1
	delay 5
	playsewithpan SE_W129, -64
	createsprite gSwiftStarSpriteTemplate, 131, 20, -10, 20, -10, 22, 15, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 18, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 2, 0, 18, 1
	delay 5
	playsewithpan SE_W129, -64
	createsprite gSwiftStarSpriteTemplate, 131, 20, -10, 20, 0, 22, -20, 1
	delay 5
	playsewithpan SE_W129, -64
	createsprite gSwiftStarSpriteTemplate, 131, 20, -10, 20, 0, 22, 12, 1
	delay 5
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_STRENGTH:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W036, -64
	createvisualtask AnimTask_ShakeAndSinkMon, 5, ANIM_ATTACKER, 2, 0, 96, 30
	waitforvisualfinish
	delay 10
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 4
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_TARGET, 18, 6, 2, 4
	delay 4
	playsewithpan SE_W025B, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, 16, 12, 1, 1
	delay 4
	playsewithpan SE_W025B, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, -16, -12, 1, 1
	delay 4
	playsewithpan SE_W025B, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, 3, 4, 1, 1
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_TACKLE:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, 2, 4, 4
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W004, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_BODY_SLAM:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W036, -64
	createsprite gVerticalDipSpriteTemplate, 2, 6, 1, ANIM_ATTACKER
	waitforvisualfinish
	delay 11
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, 26, 0, 0, 5
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, 4, -10, 0, 1, 0
	loopsewithpan SE_W025B, +63, 10, 2
	delay 1
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 1, -28, 0, 0, 3
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 12, 1
	waitforvisualfinish
	delay 10
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 6
	delay 5
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 1, 0, 6
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SUPERSONIC:
	loadspritegfx 0x27B3
	monbg ANIM_ATK_PARTNER
	monbgprio_2A ANIM_ATTACKER
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 2, 0, 8, 1
	call Supersonic1
	call Supersonic1
	call Supersonic1
	call Supersonic1
	call Supersonic1
	call Supersonic1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end
Supersonic1:
	playsewithpan SE_W048, -64
	createsprite gSupersonicWaveSpriteTemplate, 130, 16, 0, 0, 0, 30, 0
	delay 2
	return

Move_SCREECH:
	loadspritegfx 0x27B4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 3, 0, 2, 1
	call Screech1
	call Screech1
	delay 16
	createvisualtask AnimTask_SwayMon, 5, 0, 6, 2048, 2, ANIM_TARGET
	waitforvisualfinish
	end
Screech1:
	playsewithpan SE_W103, -64
	createsprite gScreechWaveSpriteTemplate, 130, 16, 0, 0, 0, 30, 0
	delay 2
	return

Move_FLAME_WHEEL:
	loadspritegfx 0x272D
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	createsprite gBattleAnimSpriteTemplate_8595584, 3, 0, 0, 56, 0
	playsewithpan SE_W172, -64
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, 3, 0, 0, 56, 4
	playsewithpan SE_W172, -64
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, 3, 0, 0, 56, 8
	playsewithpan SE_W172, -64
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, 3, 0, 0, 56, 12
	playsewithpan SE_W172, -64
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, 3, 0, 0, 56, 16
	playsewithpan SE_W172, -64
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, 3, 0, 0, 56, 20
	playsewithpan SE_W172, -64
	delay 2
	createsprite gBattleAnimSpriteTemplate_8595584, 3, 0, 0, 56, 24
	playsewithpan SE_W172, -64
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, 24, 0, 0, 6
	delay 4
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 8, 1
	createvisualtask AnimTask_BlendMonInAndOut, 3, ANIM_TARGET, RGB_RED, 12, 1, 1
	playsewithpan SE_W172B, +63
	call FireMoveEffect
	delay 7
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 9
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

FlameWheel1: @ Unused
	createsprite gBattleAnimSpriteTemplate_8595584, 3, 0, 0, 50
	delay 4
	return

Move_PIN_MISSILE:
	loadspritegfx 0x27B1
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W026, -64
	createsprite gPinMissileSpriteTemplate, 2, 20, -8, -8, -8, 20, -32
	delay 15
	createsprite gPinMissileSpriteTemplate, 2, 20, -8, 8, 8, 20, -40
	delay 4
	playsewithpan SE_W030, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, -8, -8, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	delay 0x9
	createsprite gPinMissileSpriteTemplate, 2, 20, -8, 0, 0, 20, -32
	delay 4
	playsewithpan SE_W030, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, 8, 8, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	delay 14
	playsewithpan SE_W030, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_ICICLE_SPEAR:
	loadspritegfx 0x2816
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W196, -64
	createsprite gIcicleSpearSpriteTemplate, 2, 20, -8, -8, -8, 20, -32
	delay 15
	createsprite gIcicleSpearSpriteTemplate, 2, 20, -8, 8, 8, 20, -40
	delay 4
	playsewithpan SE_W030, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, -8, -8, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	delay 0x9
	createsprite gIcicleSpearSpriteTemplate, 2, 20, -8, 0, 0, 20, -32
	delay 4
	playsewithpan SE_W030, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, 8, 8, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	delay 14
	playsewithpan SE_W030, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 2, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_TAKE_DOWN:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_WindUpLunge, 5, ANIM_ATTACKER, -24, 8, 23, 10, 40, 10
	delay 35
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 31, 3, 1, 0, 10, 0, 0
	createsprite gBasicHitSplatSpriteTemplate, 4, -10, 0, 1, 0
	playsewithpan SE_W025B, +63
	delay 1
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 1, -16, 0, 0, 4
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 12, 1
	waitforvisualfinish
	delay 2
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 5
	delay 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 1, 0, 7
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_DOUBLE_EDGE:
	loadspritegfx ANIM_TAG_135
	playsewithpan SE_W129, -64
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 2, 4, 2, 0x7FFF, 10, 0, 0
	waitforvisualfinish
	delay 10
	playsewithpan SE_W207, -64
	waitplaysewithpan SE_W207, -64, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 18, 6, 2, 4
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 0, 16, 16, RGB_WHITE
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, 20, 0, 0, 4
	delay 3
	waitforvisualfinish
	playsewithpan SE_W025B, +63
	createsprite gBasicHitSplatSpriteTemplate, 132, -10, 0, 1, 0
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 1, -32, 0, 0, 3
	waitforvisualfinish
	createvisualtask sub_80D6134, 2, 8, -256, 0, 0
	createvisualtask sub_80D6134, 2, 8, -256, 1, 0
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 4, 0, 12, 1
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 12, 1
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 16, 0, RGB_WHITE
	waitforvisualfinish
	createvisualtask sub_80D6134, 2, 8, -256, 0, 1
	createvisualtask sub_80D6134, 2, 8, -256, 1, 1
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 5
	delay 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 1, 0, 7
	waitforvisualfinish
	end

Move_POISON_STING:
	loadspritegfx 0x27B1
	loadspritegfx ANIM_TAG_135
	loadspritegfx 0x27A6
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W013B, -64
	createsprite gLinearStingerSpriteTemplate, 130, 20, 0, -8, 0, 20
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 5, 1
	playsewithpan SE_W030, +63
	waitforvisualfinish
	call PoisonBubblesEffect
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_TWINEEDLE:
	loadspritegfx 0x27B1
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	loopsewithpan SE_W013B, -64, 6, 2
	createsprite gLinearStingerSpriteTemplate, 130, 10, -4, 0, -4, 20
	createsprite gLinearStingerSpriteTemplate, 130, 20, 12, 10, 12, 20
	delay 20
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 5, 1
	createsprite gBattleAnimSpriteTemplate_8597370, 3, 0, -4, 1, 3
	loopsewithpan SE_W030, +63, 5, 2
	delay 1
	createsprite gBattleAnimSpriteTemplate_8597370, 3, 10, 12, 1, 3
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_FIRE_BLAST:
	loadspritegfx 0x272D
	createsoundtask sub_8158B30, 144, 145
	call FireBlast1
	call FireBlast1
	call FireBlast1
	delay 24
	createvisualtask sub_8116620, 10, 1, 3, 0, 8, RGB_BLACK
	waitforvisualfinish
	delay 19
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 20, 1
	call FireBlast2
	delay 3
	call FireBlast2
	delay 3
	call FireBlast2
	delay 3
	call FireBlast2
	delay 3
	call FireBlast2
	delay 3
	call FireBlast2
	delay 3
	call FireBlast2
	delay 3
	call FireBlast2
	delay 3
	call FireBlast2
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 1, 2, 8, 0, RGB_BLACK
	waitforvisualfinish
	end

FireBlast1:
	createsprite gUnknown_0859551C, 130, 0, 0, 0
	createsprite gUnknown_0859551C, 130, 0, 0, 51
	createsprite gUnknown_0859551C, 130, 0, 0, 102
	createsprite gUnknown_0859551C, 130, 0, 0, 153
	createsprite gUnknown_0859551C, 130, 0, 0, 204
	delay 5
	return

FireBlast2:
	createsprite gUnknown_0859556C, 130, 0, 0, 10, 0, -2
	createsprite gUnknown_0859556C, 130, 0, 0, 13, -2, 0
	createsprite gUnknown_0859556C, 130, 0, 0, 13, 2, 0
	createsprite gUnknown_0859556C, 130, 0, 0, 15, -2, 2
	createsprite gUnknown_0859556C, 130, 0, 0, 15, 2, 2
	return

Move_LEECH_SEED:
	loadspritegfx 0x2716
	playsewithpan SE_W077, -64
	createsprite gLeechSeedSpriteTemplate, 130, 15, 0, 0, 24, 35, -32
	delay 8
	playsewithpan SE_W077, -64
	createsprite gLeechSeedSpriteTemplate, 130, 15, 0, -16, 24, 35, -40
	delay 8
	playsewithpan SE_W077, -64
	createsprite gLeechSeedSpriteTemplate, 130, 15, 0, 16, 24, 35, -37
	delay 12
	loopsewithpan SE_W039, +63, 10, 8
	waitforvisualfinish
	end

Move_EMBER:
	loadspritegfx 0x272D
	loopsewithpan SE_W052, -64, 5, 2
	createsprite gEmberSpriteTemplate, 130, 20, 0, -16, 24, 20, 1
	delay 4
	createsprite gEmberSpriteTemplate, 130, 20, 0, 0, 24, 20, 1
	delay 4
	createsprite gEmberSpriteTemplate, 130, 20, 0, 16, 24, 20, 1
	delay 16
	playsewithpan SE_W172, +63
	call Ember1
	call Ember1
	call Ember1
	end

Ember1:
	createsprite gEmberFlareSpriteTemplate, 130, -24, 24, 24, 24, 20, 1, 1
	delay 4
	return

Move_MEGA_PUNCH:
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	monbg ANIM_TARGET
	delay 2
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 0, 0, 16, RGB_BLACK
	setalpha 12, 8
	playsewithpan SE_W025, +63
	createsprite gMegaPunchKickSpriteTemplate, 3, 0, 0, 0, 50
	createvisualtask sub_8116620, 10, 4, 2, 0, 7, RGB_WHITE
	delay 50
	call SetImpactBackground
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 22, 1
	createvisualtask sub_8116620, 10, 4, 2, 0, 0, RGB_WHITE
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 31, 3, 1, 0, 8, 0, 0
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 2
	restorebg
	waitbgfadein
	end
SetImpactBackground:
	delay 2
	createvisualtask AnimTask_IsContest, 2
	jumprettrue SetImpactContestsBG
	createvisualtask AnimTask_IsTargetPlayerSide, 2
	jumpretfalse SetImpactOpponentBG
	jumprettrue SetImpactPlayerBG
SetImpactBackgroundRet:
	return
SetImpactOpponentBG:
	changebg BG_IMPACT_OPPONENT
	goto SetImpactBackgroundRet
SetImpactPlayerBG:
	changebg BG_IMPACT_PLAYER
	goto SetImpactBackgroundRet
SetImpactContestsBG:
	changebg BG_IMPACT_CONTESTS
	goto SetImpactBackgroundRet

Move_MEGA_KICK:
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	monbg ANIM_TARGET
	delay 2
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 0, 0, 16, RGB_BLACK
	setalpha 12, 8
	playsewithpan SE_W025, +63
	createsprite gMegaPunchKickSpriteTemplate, 3, 0, 0, 1, 50
	createvisualtask sub_8116620, 10, 4, 2, 0, 7, RGB_WHITE
	delay 50
	playsewithpan SE_W025B, +63
	call SetImpactBackground
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 22, 1
	createvisualtask sub_8116620, 10, 4, 2, 0, 0, RGB_WHITE
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 31, 3, 1, 0, 8, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 2
	restorebg
	waitbgfadein
	end

Move_COMET_PUNCH:
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	monbg ANIM_TARGET
	setalpha 12, 8
	choosetwoturnanim CometPunchLeft, CometPunchRight
CometPunchContinue:
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W004, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
CometPunchLeft:
	createsprite gBasicHitSplatSpriteTemplate, 2, -8, -8, 1, 2
	createsprite gFistFootSpriteTemplate, 3, -8, 0, 8, 1, 0
	goto CometPunchContinue
CometPunchRight:
	createsprite gBasicHitSplatSpriteTemplate, 2, 8, -8, 1, 2
	createsprite gFistFootSpriteTemplate, 3, 8, 0, 8, 1, 0
	goto CometPunchContinue

Move_SONIC_BOOM:
	loadspritegfx ANIM_TAG_003
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	call SonicBoom1
	call SonicBoom1
	call SonicBoom1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 10, 1
	call SonicBoom2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
SonicBoom1:
	playsewithpan SE_W013B, -64
	createsprite gSonicBoomSpriteTemplate, 130, 16, 0, 0, 0, 15
	delay 4
	return
SonicBoom2:
	createsprite gBasicHitSplatSpriteTemplate, 131, 0, 0, 1, 2
	delay 4
	return

Move_THUNDER_SHOCK:
	loadspritegfx ANIM_TAG_001
	loadspritegfx ANIM_TAG_011
	createvisualtask sub_8116620, 10, 1, 0, 0, 6, RGB_BLACK
	waitforvisualfinish
	delay 10
	createvisualtask sub_810A7DC, 5, 0, -44, 0
	playsewithpan SE_W085, +63
	delay 0x9
	createvisualtask sub_8116620, 10, 4, 0, 0, 13, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 4, 0, 13, 0, RGB_BLACK
	waitforvisualfinish
	delay 20
	call ElectricityEffect
	waitforvisualfinish
	delay 20
	createvisualtask sub_8116620, 10, 1, 0, 6, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_THUNDERBOLT:
	loadspritegfx ANIM_TAG_001
	loadspritegfx ANIM_TAG_282
	loadspritegfx ANIM_TAG_011
	createvisualtask sub_8116620, 10, 1, 0, 0, 6, RGB_BLACK
	waitforvisualfinish
	delay 10
	createvisualtask sub_810A7DC, 5, 24, -52, 0
	playsewithpan SE_W085, +63
	delay 7
	createvisualtask sub_810A7DC, 5, -24, -52, 0
	playsewithpan SE_W085, +63
	delay 7
	createvisualtask sub_810A7DC, 5, 0, -60, 1
	playsewithpan SE_W085, +63
	delay 0x9
	createvisualtask sub_8116620, 10, 4, 0, 0, 13, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 4, 0, 13, 0, RGB_BLACK
	waitforvisualfinish
	delay 20
	createsprite gBattleAnimSpriteTemplate_85957E0, 131, 44, 0, 0, 3
	createsprite gBattleAnimSpriteTemplate_85957F8, 132, 0, 0, 32, 44, 0, 40, 0, -32765
	createsprite gBattleAnimSpriteTemplate_85957F8, 132, 0, 0, 32, 44, 64, 40, 1, -32765
	createsprite gBattleAnimSpriteTemplate_85957F8, 132, 0, 0, 32, 44, 128, 40, 0, -32765
	createsprite gBattleAnimSpriteTemplate_85957F8, 132, 0, 0, 32, 44, 192, 40, 2, -32765
	createsprite gBattleAnimSpriteTemplate_85957F8, 132, 0, 0, 16, 44, 32, 40, 0, -32765
	createsprite gBattleAnimSpriteTemplate_85957F8, 132, 0, 0, 16, 44, 96, 40, 1, -32765
	createsprite gBattleAnimSpriteTemplate_85957F8, 132, 0, 0, 16, 44, 160, 40, 0, -32765
	createsprite gBattleAnimSpriteTemplate_85957F8, 132, 0, 0, 16, 44, 224, 40, 2, -32765
	playsewithpan SE_W063, +63
	delay 0
	createvisualtask sub_8116620, 10, 1, 0, 2, 2, RGB_BLACK
	delay 6
	createvisualtask sub_8116620, 10, 1, 0, 6, 6, RGB_BLACK
	delay 6
	createvisualtask sub_8116620, 10, 1, 0, 2, 2, RGB_BLACK
	delay 6
	createvisualtask sub_8116620, 10, 1, 0, 6, 6, RGB_BLACK
	waitforvisualfinish
	delay 20
	waitplaysewithpan SE_W085B, +63, 19
	call ElectricityEffect
	waitforvisualfinish
	delay 20
	createvisualtask sub_8116620, 10, 1, 0, 6, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_THUNDER_WAVE:
	loadspritegfx ANIM_TAG_001
	loadspritegfx ANIM_TAG_011
	loadspritegfx 0x27BD
	createvisualtask sub_8116620, 10, 1, 0, 0, 6, RGB_BLACK
	waitforvisualfinish
	delay 10
	createvisualtask sub_810A7DC, 5, 0, -48, 0
	playsewithpan SE_W086, +63
	delay 20
	loopsewithpan SE_W085B, +63, 10, 4
	createsprite gUnknown_08595840, 130, -16, -16
	delay 4
	createsprite gUnknown_08595840, 130, -16, 0
	delay 4
	createsprite gUnknown_08595840, 130, -16, 16
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 1, 0, 6, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_BEAT_UP:
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	monbg ANIM_TARGET
	setalpha 12, 8
	choosetwoturnanim BeatUpLeft, BeatUpRight
BeatUpContinue:
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
BeatUpLeft:
	createsprite gBasicHitSplatSpriteTemplate, 130, -20, -20, 1, 2
	createsprite gFistFootSpriteTemplate, 131, -20, -12, 8, 1, 0
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W233B, +63
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, 130, 8, 0, 1, 2
	createsprite gFistFootSpriteTemplate, 131, 8, 8, 8, 1, 0
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W233B, +63
	goto BeatUpContinue
BeatUpRight:
	createsprite gBasicHitSplatSpriteTemplate, 130, 12, -20, 1, 2
	createsprite gFistFootSpriteTemplate, 131, 12, -12, 8, 1, 0
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W233B, +63
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, 130, -12, 0, 1, 2
	createsprite gFistFootSpriteTemplate, 131, -12, 8, 8, 1, 0
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W233B, +63
	goto BeatUpContinue

Move_STOMP:
	loadspritegfx ANIM_TAG_143
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W104, +63
	createsprite gUnknown_08595F60, 3, 0, -32, 15
	delay 19
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, -8, 1, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 4, 9, 1
	playsewithpan SE_W025B, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_TAIL_WHIP:
	loopsewithpan SE_W039, -64, 24, 3
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 12, 4, 2, 3
	waitforvisualfinish
	end

Move_CUT:
	loadspritegfx ANIM_TAG_138
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W015, +63
	createsprite gCuttingSliceSpriteTemplate, 2, 40, -32, 0
	delay 5
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 10, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end

Move_HIDDEN_POWER:
	loadspritegfx 0x27E9
	playsewithpan SE_W036, -64
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -7, -7, 11, ANIM_ATTACKER, 0
	waitforvisualfinish
	delay 30
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB(31, 31, 19), 12, 5, 1
	delay 4
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -7, -7, 11, ANIM_ATTACKER, 0
	playsewithpan SE_W179, -64
	createsprite gHiddenPowerOrbSpriteTemplate, 2, 26, 0
	createsprite gHiddenPowerOrbSpriteTemplate, 2, 26, 42
	createsprite gHiddenPowerOrbSpriteTemplate, 2, 26, 84
	createsprite gHiddenPowerOrbSpriteTemplate, 2, 26, 126
	createsprite gHiddenPowerOrbSpriteTemplate, 2, 26, 168
	createsprite gHiddenPowerOrbSpriteTemplate, 2, 26, 210
	delay 52
	setarg 7, 0xFFFF
	playsewithpan SE_W115, -64
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -7, -7, 11, ANIM_ATTACKER, 0
	createsprite gHiddenPowerOrbScatterSpriteTemplate, 130, 0
	createsprite gHiddenPowerOrbScatterSpriteTemplate, 130, 32
	createsprite gHiddenPowerOrbScatterSpriteTemplate, 130, 64
	createsprite gHiddenPowerOrbScatterSpriteTemplate, 130, 96
	createsprite gHiddenPowerOrbScatterSpriteTemplate, 130, 128
	createsprite gHiddenPowerOrbScatterSpriteTemplate, 130, 160
	createsprite gHiddenPowerOrbScatterSpriteTemplate, 130, 192
	createsprite gHiddenPowerOrbScatterSpriteTemplate, 130, 224
	end

Move_REVERSAL:
	loadspritegfx 0x27FC
	loadspritegfx ANIM_TAG_143
	loadspritegfx ANIM_TAG_135
	playsewithpan SE_W197, -64
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 31, 3, 3, 0x7FFF, 8, 0, 0
	waitforvisualfinish
	delay 30
	createvisualtask sub_8115A04, 2, 31, 3, 2, 0, 10, RGB_WHITE
	delay 10
	playsewithpan SE_W179, -64
	createsprite gBattleAnimSpriteTemplate_85CE5D8, 2, 26, 0
	createsprite gBattleAnimSpriteTemplate_85CE5D8, 2, 26, 42
	createsprite gBattleAnimSpriteTemplate_85CE5D8, 2, 26, 84
	createsprite gBattleAnimSpriteTemplate_85CE5D8, 2, 26, 126
	createsprite gBattleAnimSpriteTemplate_85CE5D8, 2, 26, 168
	createsprite gBattleAnimSpriteTemplate_85CE5D8, 2, 26, 210
	waitforvisualfinish
	delay 20
	createsprite gHorizontalLungeSpriteTemplate, 2, 6, 4
	delay 8
	playsewithpan SE_W233B, +63
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 31, 3, 1, 0x7FFF, 8, 0, 0
	createsprite gFistFootSpriteTemplate, 132, 0, 0, 10, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, 131, 0, 0, 1, 1
	createvisualtask sub_80D6388, 5, 0, 1, 8, 1, 0
	end

Move_PURSUIT:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	fadetobg BG_DARK
	waitbgfadein
	delay 0
	setalpha 12, 8
	choosetwoturnanim PursuitNormal, PursuitOnSwitchout
PursuitContinue:
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 0
	restorebg
	waitbgfadein
	end
PursuitNormal:
	playsewithpan SE_W004, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 2
	createvisualtask sub_80D6388, 5, 0, 1, 6, 1, 0
	goto PursuitContinue
PursuitOnSwitchout:
	playsewithpan SE_W004, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 1
	createvisualtask sub_80D6388, 5, 0, 1, 6, 1, 0
	goto PursuitContinue

Move_SPIKE_CANNON:
	loadspritegfx 0x27B1
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_WindUpLunge, 5, ANIM_ATTACKER, -4, 0, 4, 6, 8, 4
	waitforvisualfinish
	loopsewithpan SE_W013B, -64, 5, 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 5
	createsprite gLinearStingerSpriteTemplate, 2, 10, -8, -8, -8, 20
	createsprite gLinearStingerSpriteTemplate, 2, 18, 0, 0, 0, 20
	createsprite gLinearStingerSpriteTemplate, 2, 26, 8, 8, 8, 20
	waitforvisualfinish
	createsprite gBattleAnimSpriteTemplate_8597370, 3, -8, -8, 1, 2
	createsprite gBattleAnimSpriteTemplate_8597370, 3, 0, 0, 1, 2
	createsprite gBattleAnimSpriteTemplate_8597370, 3, 8, 8, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 7, 1
	loopsewithpan SE_W030, +63, 5, 3
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SWORDS_DANCE:
	loadspritegfx 0x2715
	monbg ANIM_ATTACKER
	setalpha 12, 8
	playsewithpan SE_W014, -64
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 16, 6, 1, 4
	createsprite gBattleAnimSpriteTemplate_8593380, 2, 0, 0
	delay 0x16
	createvisualtask sub_8115D94, 2, 0x2715, 2, 2, RGB(18, 31, 31), 16, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	delay 1
	end

Move_PSYCH_UP:
	loadspritegfx 0x27D4
	monbg ANIM_ATK_PARTNER
	createvisualtask sub_8115B0C, 2, 1, 2, 6, 1, 11, 0
	setalpha 12, 8
	loopsewithpan SE_W060B, -64, 5, 10
	createsprite gUnknown_08596548, 2, 0, 0, 0, 0
	createvisualtask AnimTask_SwayMon, 5, 0, 5, 2560, 8, ANIM_ATTACKER
	delay 127
	delay 4
	playsewithpan SE_W060, -64
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -5, -5, 10, ANIM_ATTACKER, 1
	createvisualtask sub_8116620, 0x9, 2, 2, 10, 0, RGB_YELLOW
	delay 30
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	waitforvisualfinish
	end

Move_DIZZY_PUNCH:
	loadspritegfx ANIM_TAG_073
	loadspritegfx ANIM_TAG_143
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	setalpha 12, 8
	call DizzyPunch1
	createsprite gFistFootSpriteTemplate, 0x85, 16, 8, 20, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, 132, 16, 0, 1, 1
	playsewithpan SE_W004, +63
	createsprite gUnknown_08595F78, 131, 16, 8, 160, -32
	createsprite gUnknown_08595F78, 131, 16, 8, -256, -40
	createsprite gUnknown_08595F78, 131, 16, 8, 128, -16
	createsprite gUnknown_08595F78, 131, 16, 8, 416, -38
	createsprite gUnknown_08595F78, 131, 16, 8, -128, -22
	createsprite gUnknown_08595F78, 131, 16, 8, -384, -31
	delay 10
	call DizzyPunch1
	createsprite gFistFootSpriteTemplate, 0x85, -16, -8, 20, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, 132, -16, -16, 1, 1
	playsewithpan SE_W233B, +63
	createsprite gUnknown_08595F78, 131, -16, -8, 160, -32
	createsprite gUnknown_08595F78, 131, -16, -8, -256, -40
	createsprite gUnknown_08595F78, 131, -16, -8, 128, -16
	createsprite gUnknown_08595F78, 131, -16, -8, 416, -38
	createsprite gUnknown_08595F78, 131, -16, -8, -128, -22
	createsprite gUnknown_08595F78, 131, -16, -8, -384, -31
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

DizzyPunch1:
	createsprite gHorizontalLungeSpriteTemplate, 2, 6, 4
	delay 6
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 7, 1
	return

Move_FIRE_SPIN:
	loadspritegfx 0x272D
	playsewithpan SE_W221B, +63
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 2, 47, 1
	call FireSpinEffect
	call FireSpinEffect
	call FireSpinEffect
	waitforvisualfinish
	end

FireSpinEffect:
	createsprite gUnknown_08596B88, 130, 0, 28, 528, 30, 13, 50, 1
	delay 2
	createsprite gUnknown_08596B88, 130, 0, 32, 480, 20, 16, -46, 1
	delay 2
	createsprite gUnknown_08596B88, 130, 0, 33, 576, 20, 8, 42, 1
	delay 2
	createsprite gUnknown_08596B88, 130, 0, 31, 400, 25, 11, -42, 1
	delay 2
	createsprite gUnknown_08596B88, 130, 0, 28, 512, 25, 16, 46, 1
	delay 2
	createsprite gUnknown_08596B88, 130, 0, 33, 464, 30, 15, -50, 1
	delay 2
	return

Move_FURY_CUTTER:
	loadspritegfx ANIM_TAG_138
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W013, +63
	createvisualtask AnimTask_IsFuryCutterHitRight, 2
	jumpretfalse FuryCutterLeft
	goto FuryCutterRight
FuryCutterContinue:
	createvisualtask AnimTask_GetFuryCutterHitCount, 2
	jumpreteq 1, FuryCutterContinue2
	jumpreteq 2, FuryCutterMedium
	jumpreteq 3, FuryCutterStrong
	goto FuryCutterStrongest
FuryCutterContinue2:
	delay 5
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 10, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end
FuryCutterLeft:
	createsprite gCuttingSliceSpriteTemplate, 2, 40, -32, 0
	goto FuryCutterContinue
FuryCutterRight:
	createsprite gCuttingSliceSpriteTemplate, 2, 40, -32, 1
	goto FuryCutterContinue
FuryCutterMedium:
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 31, 3, 1, 10505, 4, 0, 0
	goto FuryCutterContinue2
FuryCutterStrong:
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 31, 3, 3, 10505, 4, 0, 0
	goto FuryCutterContinue2
FuryCutterStrongest:
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 31, 3, 3, 10505, 4, 0, 0
	goto FuryCutterContinue2

Move_SELF_DESTRUCT:
	loadspritegfx 0x27D6
	createvisualtask sub_8116620, 10, 2, 1, 0, 9, RGB_RED
	createvisualtask AnimTask_ShakeMon2, 5, 4, 6, 0, 38, 1
	createvisualtask AnimTask_ShakeMon2, 5, 5, 6, 0, 38, 1
	createvisualtask AnimTask_ShakeMon2, 5, 6, 6, 0, 38, 1
	createvisualtask AnimTask_ShakeMon2, 5, 7, 6, 0, 38, 1
	createvisualtask AnimTask_ShakeMon2, 5, 8, 6, 0, 38, 1
	call SelfDestruct1
	call SelfDestruct1
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 2, 1, 9, 0, RGB_RED
	end
SelfDestruct1:
	playsewithpan SE_W120, -64
	createsprite gBattleAnimSpriteTemplate_859371C, 3, 0, 0, 0, 1
	delay 6
	playsewithpan SE_W120, -64
	createsprite gBattleAnimSpriteTemplate_859371C, 3, 24, -24, 0, 1
	delay 6
	playsewithpan SE_W120, -64
	createsprite gBattleAnimSpriteTemplate_859371C, 3, -16, 16, 0, 1
	delay 6
	playsewithpan SE_W120, -64
	createsprite gBattleAnimSpriteTemplate_859371C, 3, -24, -12, 0, 1
	delay 6
	playsewithpan SE_W120, -64
	createsprite gBattleAnimSpriteTemplate_859371C, 3, 16, 16, 0, 1
	delay 6
	return

Move_SLAM:
	loadspritegfx 0x2748
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W004, -64
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, 20, 3, 0, 4
	delay 1
	createsprite gUnknown_085928D0, 2, 0, 0
	delay 3
	playsewithpan SE_W025B, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 1
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 1, -12, 10, 0, 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 5
	delay 3
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 0, 3, 6, 1
	waitforvisualfinish
	delay 5
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 1, 0, 6
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_VINE_WHIP:
	loadspritegfx 0x282F
	playsewithpan SE_W026, -64
	createsprite gHorizontalLungeSpriteTemplate, 2, 4, 6
	delay 6
	playsewithpan SE_W010, +63
	createsprite gUnknown_085928E8, 130, 0, 0
	delay 6
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 6, 1
	end

Move_DRILL_PECK:
	loadspritegfx ANIM_TAG_135
	loadspritegfx 0x27B2
	createsprite gUnknown_08592CD8, 2, 0
	playsewithpan SE_W029, -64
	waitforvisualfinish
	delay 2
	createsprite gUnknown_08592CD8, 2, 1
	delay 2
	loopsewithpan SE_W030, +63, 4, 8
	createvisualtask sub_810EB88, 5
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 18, 1
	waitforvisualfinish
	createsprite gUnknown_08592CD8, 2, 2
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 6
	waitforvisualfinish
	end

Move_WATERFALL:
	loadspritegfx 0x27A4
	loadspritegfx ANIM_TAG_155
	loadspritegfx ANIM_TAG_141
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 0, 2, 23, 1
	delay 5
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 2, 10, 10, 25, 0
	delay 4
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 2, -15, 0, 25, 0
	delay 4
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 2, 20, 10, 25, 0
	delay 4
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 2, 0, -10, 25, 0
	delay 4
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 2, -10, 15, 25, 0
	delay 4
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 2, 25, 20, 25, 0
	delay 4
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 2, -20, 20, 25, 0
	delay 4
	playsewithpan SE_W152, -64
	createsprite gUnknown_08595238, 2, 12, 0, 25, 0
	waitforvisualfinish
	delay 10
	createsprite gHorizontalLungeSpriteTemplate, 2, 6, 5
	delay 6
	call UnderWaterAttack1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

UnderWaterAttack1:
	playsewithpan SE_W127, +63
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 17, 1
	createsprite gUnknown_08597388, 3, 0, 20, 1, 1
	createsprite gUnknown_08595250, 4, 0, 20
	createsprite gUnknown_08595250, 4, 0, 20
	delay 2
	createsprite gUnknown_08597388, 3, 0, 15, 1, 1
	createsprite gUnknown_08595250, 4, 0, 15
	createsprite gUnknown_08595250, 4, 0, 15
	delay 2
	createsprite gUnknown_08597388, 3, 0, 10, 1, 1
	createsprite gUnknown_08595250, 4, 0, 10
	createsprite gUnknown_08595250, 4, 0, 10
	delay 2
	createsprite gUnknown_08597388, 3, 0, 5, 1, 1
	createsprite gUnknown_08595250, 4, 0, 5
	createsprite gUnknown_08595250, 4, 0, 5
	delay 2
	createsprite gUnknown_08597388, 3, 0, 0, 1, 1
	createsprite gUnknown_08595250, 4, 0, 0
	createsprite gUnknown_08595250, 4, 0, 0
	delay 2
	createsprite gUnknown_08597388, 3, 0, -5, 1, 1
	createsprite gUnknown_08595250, 4, 0, -5
	createsprite gUnknown_08595250, 4, 0, -5
	delay 2
	createsprite gUnknown_08597388, 3, 0, -10, 1, 1
	createsprite gUnknown_08595250, 4, 0, -10
	createsprite gUnknown_08595250, 4, 0, -10
	delay 2
	createsprite gUnknown_08597388, 3, 0, -15, 1, 1
	createsprite gUnknown_08595250, 4, 0, -15
	createsprite gUnknown_08595250, 4, 0, -15
	delay 2
	createsprite gUnknown_08597388, 3, 0, -20, 1, 1
	createsprite gUnknown_08595250, 4, 0, -20
	createsprite gUnknown_08595250, 4, 0, -20
	return

Move_EXPLOSION:
	loadspritegfx 0x27D6
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 1, 8, 9, 8474, 8, 0, 8
	createvisualtask AnimTask_ShakeMon2, 5, 4, 8, 0, 40, 1
	createvisualtask AnimTask_ShakeMon2, 5, 5, 8, 0, 40, 1
	createvisualtask AnimTask_ShakeMon2, 5, 6, 8, 0, 40, 1
	createvisualtask AnimTask_ShakeMon2, 5, 7, 8, 0, 40, 1
	createvisualtask AnimTask_ShakeMon2, 5, 8, 8, 0, 40, 1
	call Explosion1
	call Explosion1
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 1, 1, 16, 16, RGB_WHITE
	delay 50
	createvisualtask sub_8116620, 10, 1, 3, 16, 0, RGB_WHITE
	end

Explosion1:
	playsewithpan SE_W153, -64
	createsprite gBattleAnimSpriteTemplate_859371C, 3, 0, 0, 0, 1
	delay 6
	playsewithpan SE_W153, -64
	createsprite gBattleAnimSpriteTemplate_859371C, 3, 24, -24, 0, 1
	delay 6
	playsewithpan SE_W153, -64
	createsprite gBattleAnimSpriteTemplate_859371C, 3, -16, 16, 0, 1
	delay 6
	playsewithpan SE_W153, -64
	createsprite gBattleAnimSpriteTemplate_859371C, 3, -24, -12, 0, 1
	delay 6
	playsewithpan SE_W153, -64
	createsprite gBattleAnimSpriteTemplate_859371C, 3, 16, 16, 0, 1
	delay 6
	return

Move_DEFENSE_CURL:
	loadspritegfx 0x27FA
	loopsewithpan SE_W161, -64, 0x12, 3
	createvisualtask sub_811489C, 5, 0, 0
	createvisualtask sub_815B338, 5
	waitforvisualfinish
	createsprite gUnknown_085CE338, 2, 0, 6, 0, 1
	waitforvisualfinish
	createvisualtask sub_811489C, 5, 0, 1
	waitforvisualfinish
	end

Move_PROTECT:
	loadspritegfx 0x2828
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	waitplaysewithpan SE_W115, -64, 16
	createsprite gUnknown_08592ADC, 2, 24, 0, 90
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	end

Move_DETECT:
	loadspritegfx 0x2757
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 0, 9, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 2, 1, 0, 9, RGB_WHITE
	delay 0x12
	playsewithpan SE_W197, -64
	createsprite gUnknown_0853EE84, 0xD, 20, -20
	waitforvisualfinish
	delay 10
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 9, 0, RGB_BLACK
	createvisualtask sub_8116620, 10, 2, 2, 9, 0, RGB_WHITE
	waitforvisualfinish
	end

Move_FRUSTRATION:
	loadspritegfx ANIM_TAG_135
	loadspritegfx 0x2767
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_GetFrustrationPowerLevel, 1
	jumpreteq 0, Frustration_Strongest
	jumpreteq 1, Frustration_Strong
	jumpreteq 2, Frustration_Medium
	goto Frustration_Weak
Frustration_Continue:
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
Frustration_Strongest:
	playsewithpan SE_W082, -64
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_ATTACKER, 1, 0, 15, 1
	createvisualtask sub_8116620, 10, 2, 3, 0, 9, 31
	waitforvisualfinish
	delay 20
	playsewithpan SE_W207B, -64
	createsprite gUnknown_0859368C, 2, 0, 20, -28
	waitforvisualfinish
	playsewithpan SE_W207B, -64
	createsprite gUnknown_0859368C, 2, 0, 20, -28
	waitforvisualfinish
	delay 10
	createvisualtask AnimTask_SwayMon, 5, 0, 16, 6144, 8, ANIM_ATTACKER
	delay 5
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 30, 1
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 0
	playsewithpan SE_W004, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, 3, 24, 8, 1, 0
	playsewithpan SE_W004, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, 3, -24, -16, 1, 0
	playsewithpan SE_W004, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, 3, 8, 4, 1, 0
	playsewithpan SE_W004, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, 3, -16, 19, 1, 0
	playsewithpan SE_W004, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, 3, 18, -18, 1, 0
	playsewithpan SE_W004, +63
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 2, 3, 9, 0, 31
	goto Frustration_Continue
Frustration_Strong:
	playsewithpan SE_W082, -64
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_ATTACKER, 1, 0, 15, 1
	createvisualtask sub_8116620, 10, 2, 3, 0, 9, 31
	waitforvisualfinish
	delay 20
	playsewithpan SE_W207B, -64
	createsprite gUnknown_0859368C, 2, 0, 20, -28
	waitforvisualfinish
	delay 5
	createvisualtask sub_815C3A8, 5
	delay 7
	playsewithpan SE_W004, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 8, 1, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 6, 1
	delay 14
	playsewithpan SE_W004, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, 12, -6, 1, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 6, 1
	delay 14
	playsewithpan SE_W004, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, -12, -6, 1, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 6, 1
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 2, 3, 9, 0, 31
	goto Frustration_Continue
Frustration_Medium:
	playsewithpan SE_W207B, -64
	createsprite gUnknown_0859368C, 2, 0, 20, -28
	waitforvisualfinish
	delay 5
	createsprite gHorizontalLungeSpriteTemplate, 2, 4, 4
	delay 6
	playsewithpan SE_W004, +63
	createsprite gBasicHitSplatSpriteTemplate, 2, 10, 4, 1, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	createsprite gHorizontalLungeSpriteTemplate, 2, 4, 4
	delay 6
	playsewithpan SE_W004, +63
	createsprite gBasicHitSplatSpriteTemplate, 2, -10, -4, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 6, 1
	goto Frustration_Continue
Frustration_Weak:
	createsprite gUnknown_085CE4D0, 2, 20, -28
	waitforvisualfinish
	delay 10
	createsprite gHorizontalLungeSpriteTemplate, 2, 10, 2
	delay 12
	playsewithpan SE_W004, +63
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 6, 1
	goto Frustration_Continue

Move_SAFEGUARD:
	loadspritegfx 0x2804
	monbg ANIM_ATK_PARTNER
	setalpha 8, 8
	playsewithpan SE_W208, -64
	createsprite gUnknown_08593C64, 2
	delay 4
	createsprite gUnknown_08593C64, 2
	delay 4
	createsprite gUnknown_08593C64, 2
	waitforvisualfinish
	playsewithpan SE_REAPOKE, -64
	createvisualtask sub_8115A04, 2, 10, 0, 2, 0, 10, RGB_WHITE
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

Move_PAIN_SPLIT:
	loadspritegfx 0x27FF
	createsprite gUnknown_085CE590, 2, -8, -42, 0
	createsprite gUnknown_085CE590, 130, -8, -42, 1
	delay 10
	playsewithpan SE_W207B, 0
	createvisualtask sub_815CA20, 2, 0, 0
	createvisualtask sub_815CA20, 2, 1, 0
	waitforvisualfinish
	createsprite gUnknown_085CE590, 2, -24, -42, 0
	createsprite gUnknown_085CE590, 130, -24, -42, 1
	delay 10
	playsewithpan SE_W207B, 0
	createvisualtask sub_815CA20, 2, 0, 1
	createvisualtask sub_815CA20, 2, 1, 1
	waitforvisualfinish
	createsprite gUnknown_085CE590, 2, 8, -42, 0
	createsprite gUnknown_085CE590, 130, 8, -42, 1
	delay 10
	playsewithpan SE_W207B, 0
	createvisualtask sub_815CA20, 2, 0, 2
	createvisualtask sub_815CA20, 2, 1, 2
	end

Move_VICE_GRIP:
	loadspritegfx ANIM_TAG_138
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W011, +63
	createsprite gUnknown_08593590, 2, 0
	createsprite gUnknown_08593590, 2, 1
	delay 0x9
	createsprite gBasicHitSplatSpriteTemplate, 1, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 2, 0, 5, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_GUILLOTINE:
	loadspritegfx ANIM_TAG_138
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	fadetobgfromset BG_GUILLOTINE_OPPONENT, BG_GUILLOTINE_PLAYER, BG_GUILLOTINE_CONTESTS
	waitbgfadein
	playsewithpan SE_W011, +63
	createsprite gUnknown_085935D0, 2, 0
	createsprite gUnknown_085935D0, 2, 1
	createvisualtask sub_8116620, 10, 4, 2, 0, 16, RGB_BLACK
	delay 0x9
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 2, 0, 23, 1
	delay 0x2E
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 4, 0, 8, 1
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 0
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 31, 3, 1, 0, 8, 0, 0
	playsewithpan SE_W013, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	restorebg
	waitbgfadein
	end

Move_PAY_DAY:
	loadspritegfx 0x2774
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W013B, -64
	createsprite gUnknown_085934D8, 2, 20, 0, 0, 0, 1152
	waitforvisualfinish
	playsewithpan SE_W006, +63
	createsprite gBasicHitSplatSpriteTemplate, 1, 0, 0, 1, 2
	createsprite gUnknown_085934F0, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_OUTRAGE:
	loadspritegfx 0x272D
	loopsewithpan SE_W082, -64, 8, 3
	createvisualtask sub_8115A04, 2, 7, 2, 5, 3, 8, RGB(14, 13, 0)
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 12, 6, 5, 4
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, 1280, 0, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, -1280, 0, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, 0, 1280, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, 0, -1280, 3
	delay 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 40, 1
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, 1280, 768, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, -1280, 768, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, 1280, -768, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, -1280, -768, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, 1280, 0, 3
	call Outrage1
	call Outrage1
	waitforvisualfinish
	end
Outrage1:
	delay 3
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, -1280, 0, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, 0, 1280, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, 0, -1280, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, 1280, 768, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, -1280, 768, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, 1280, -768, 3
	delay 0
	createsprite gBattleAnimSpriteTemplate_8596E7C, 130, 0, 0, 30, -1280, -768, 3
	return

Move_SPARK:
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_011
	delay 0
	createvisualtask sub_8115A04, 2, 3, -31, 1, 5, 5, RGB(31, 31, 22)
	playsewithpan SE_W085B, -64
	createsprite gBattleAnimSpriteTemplate_859574C, 0, 32, 24, 190, 12, 0, 1, 0
	delay 0
	createsprite gBattleAnimSpriteTemplate_859574C, 0, 80, 24, 22, 12, 0, 1, 0
	createsprite gBattleAnimSpriteTemplate_859574C, 0, 156, 24, 121, 13, 0, 1, 1
	delay 0
	createvisualtask sub_8115A04, 2, 3, -31, 1, 0, 0, RGB(31, 31, 22)
	delay 10
	createvisualtask sub_8115A04, 2, 3, -31, 1, 5, 5, RGB(31, 31, 22)
	playsewithpan SE_W085B, -64
	createsprite gBattleAnimSpriteTemplate_859574C, 0, 100, 24, 60, 10, 0, 1, 0
	createsprite gBattleAnimSpriteTemplate_859574C, 0, 170, 24, 42, 11, 0, 1, 1
	delay 0
	createsprite gBattleAnimSpriteTemplate_859574C, 0, 238, 24, 165, 10, 0, 1, 1
	delay 0
	createvisualtask sub_8115A04, 2, 3, -31, 1, 0, 0, RGB(31, 31, 22)
	delay 20
	createvisualtask sub_8115A04, 2, 3, -31, 1, 7, 7, RGB(31, 31, 22)
	playsewithpan SE_W085B, -64
	createsprite gBattleAnimSpriteTemplate_85957F8, 4, 0, 0, 32, 12, 0, 20, 0, 0
	createsprite gBattleAnimSpriteTemplate_85957F8, 4, 0, 0, 32, 12, 64, 20, 1, 0
	createsprite gBattleAnimSpriteTemplate_85957F8, 4, 0, 0, 32, 12, 128, 20, 0, 0
	createsprite gBattleAnimSpriteTemplate_85957F8, 4, 0, 0, 32, 12, 192, 20, 2, 0
	createsprite gBattleAnimSpriteTemplate_85957F8, 4, 0, 0, 16, 12, 32, 20, 0, 0
	createsprite gBattleAnimSpriteTemplate_85957F8, 4, 0, 0, 16, 12, 96, 20, 1, 0
	createsprite gBattleAnimSpriteTemplate_85957F8, 4, 0, 0, 16, 12, 160, 20, 0, 0
	createsprite gBattleAnimSpriteTemplate_85957F8, 4, 0, 0, 16, 12, 224, 20, 2, 0
	delay 4
	waitforvisualfinish
	createvisualtask sub_8115A04, 2, 3, -31, 1, 0, 0, RGB(31, 31, 22)
	createsprite gHorizontalLungeSpriteTemplate, 2, 4, 4
	delay 4
	playsewithpan SE_W063, +63
	createsprite gBasicHitSplatSpriteTemplate, 130, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	createvisualtask sub_8115A04, 2, 4, -31, 2, 0, 6, RGB(31, 31, 22)
	call ElectricityEffect
	waitforvisualfinish
	end

Move_ATTRACT:
	loadspritegfx 0x27E8
	loopsewithpan SE_W204, -64, 12, 3
	createvisualtask AnimTask_SwayMon, 5, 0, 12, 4096, 4, ANIM_ATTACKER
	delay 15
	createsprite gUnknown_085939A0, 131, 20, -8
	waitforvisualfinish
	playsewithpan SE_W213, +63
	createsprite gBattleAnimSpriteTemplate_85939B8, 131, 160, -32
	createsprite gBattleAnimSpriteTemplate_85939B8, 131, -256, -40
	createsprite gBattleAnimSpriteTemplate_85939B8, 131, 128, -16
	createsprite gBattleAnimSpriteTemplate_85939B8, 131, 416, -38
	createsprite gBattleAnimSpriteTemplate_85939B8, 131, -128, -22
	createsprite gBattleAnimSpriteTemplate_85939B8, 131, -384, -31
	waitforvisualfinish
	waitplaysewithpan SE_W213B, 0, 15
	createvisualtask sub_81062E8, 5
	createsprite gUnknown_085939D0, 0x28, 16, 256, 0
	createsprite gUnknown_085939D0, 0x28, 224, 240, 15
	createsprite gUnknown_085939D0, 0x28, 126, 272, 30
	createsprite gUnknown_085939D0, 0x28, 80, 224, 45
	createsprite gUnknown_085939D0, 0x28, 170, 272, 60
	createsprite gUnknown_085939D0, 0x28, 40, 256, 75
	createsprite gUnknown_085939D0, 0x28, 112, 256, 90
	createsprite gUnknown_085939D0, 0x28, 200, 272, 90
	delay 0x4B
	createvisualtask sub_8115A04, 2, 4, 4, 4, 0, 10, RGB(31, 25, 27)
	end

Move_GROWTH:
	call Growth1
	waitforvisualfinish
	call Growth1
	waitforvisualfinish
	end
Growth1:
	createvisualtask sub_8115A04, 2, 2, 0, 2, 0, 8, RGB_WHITE
	playsewithpan SE_W036, -64
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -3, -3, 16, ANIM_ATTACKER, 0
	return

Move_WHIRLWIND:
	loadspritegfx 0x27B2
	createsprite gUnknown_085963D4, 2, 0, -8, 1, 60, 0
	createsprite gUnknown_085963D4, 2, 0, 0, 1, 60, 1
	createsprite gUnknown_085963D4, 2, 0, 8, 1, 60, 2
	createsprite gUnknown_085963D4, 2, 0, 16, 1, 60, 3
	createsprite gUnknown_085963D4, 2, 0, 24, 1, 60, 4
	createsprite gUnknown_085963D4, 2, 0, 32, 1, 60, 0
	delay 5
	loopsewithpan SE_W104, +63, 10, 4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 15, 1
	delay 0x1D
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_TARGET, 12, 6, 1, 5
	delay 7
	playsewithpan SE_W081, +63
	createvisualtask sub_80D5DB0, 5, 1, 8
	waitforvisualfinish
	end

Move_CONFUSE_RAY:
	loadspritegfx 0x271D
	monbg ANIM_DEF_PARTNER
	fadetobg BG_GHOST
	waitbgfadein
	createvisualtask sub_8159278, 2, -64, 63, 2, 0
	createvisualtask sub_8115C80, 2, 10013, 0, 6, 0, 14, 351
	createsprite gUnknown_08596D14, 130, 28, 0, 288
	waitforvisualfinish
	setalpha 8, 8
	playsewithpan SE_W081B, +63
	createsprite gUnknown_08596D2C, 130, 0, -16
	waitforvisualfinish
	delay 0
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	restorebg
	waitbgfadein
	end

Move_LOCK_ON:
	loadspritegfx 0x271E
	createsprite gUnknown_08592CA0, 0x28
	createsprite gUnknown_08592CB8, 0x28, 1
	createsprite gUnknown_08592CB8, 0x28, 2
	createsprite gUnknown_08592CB8, 0x28, 3
	createsprite gUnknown_08592CB8, 0x28, 4
	delay 120
	setarg 7, 0xFFFF
	waitforvisualfinish
	end

Move_MEAN_LOOK:
	loadspritegfx 0x27CB
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W060, -64
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 0, 16, RGB_BLACK
	loopsewithpan SE_W109, +63, 15, 4
	waitplaysewithpan SE_W043, +63, 0x55
	createsprite gUnknown_085CE104, 2
	delay 120
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 16, 0, RGB_BLACK
	delay 30
	clearmonbg ANIM_DEF_PARTNER
	waitforvisualfinish
	end

Move_ROCK_THROW:
	loadspritegfx ANIM_TAG_058
	createsprite gBattleAnimSpriteTemplate_85972D8, 130, 6, 1, 15, 1
	createsprite gUnknown_08596B04, 130, 0, 1, 0, 0
	playsewithpan SE_W088, +63
	delay 6
	createsprite gUnknown_08596B04, 130, 19, 1, 10, 0
	playsewithpan SE_W088, +63
	delay 6
	createsprite gUnknown_08596B04, 130, -23, 2, -10, 0
	playsewithpan SE_W088, +63
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 5, 20, 1
	delay 6
	createsprite gUnknown_08596B04, 130, -15, 1, -10, 0
	playsewithpan SE_W088, +63
	delay 6
	createsprite gUnknown_08596B04, 130, 23, 2, 10, 0
	playsewithpan SE_W088, +63
	waitforvisualfinish
	end

Move_ROCK_SLIDE:
	loadspritegfx ANIM_TAG_058
	monbg ANIM_DEF_PARTNER
	createsprite gBattleAnimSpriteTemplate_85972D8, 2, 7, 1, 11, 1
	createsprite gUnknown_08596B04, 130, -5, 1, -5, 1
	playsewithpan SE_W088, +63
	delay 2
	createsprite gUnknown_08596B04, 130, 5, 0, 6, 1
	playsewithpan SE_W088, +63
	delay 2
	createsprite gUnknown_08596B04, 130, 19, 1, 10, 1
	playsewithpan SE_W088, +63
	delay 2
	createsprite gUnknown_08596B04, 130, -23, 2, -10, 1
	playsewithpan SE_W088, +63
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 5, 50, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_DEF_PARTNER, 0, 5, 50, 1
	delay 2
	call RockSlide1
	call RockSlide1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

RockSlide1:
	createsprite gUnknown_08596B04, 130, -20, 0, -10, 1
	playsewithpan SE_W088, +63
	delay 2
	createsprite gUnknown_08596B04, 130, 28, 1, 10, 1
	playsewithpan SE_W088, +63
	delay 2
	createsprite gUnknown_08596B04, 130, -10, 1, -5, 1
	playsewithpan SE_W088, +63
	delay 2
	createsprite gUnknown_08596B04, 130, 10, 0, 6, 1
	playsewithpan SE_W088, +63
	delay 2
	createsprite gUnknown_08596B04, 130, 24, 1, 10, 1
	playsewithpan SE_W088, +63
	delay 2
	createsprite gUnknown_08596B04, 130, -32, 2, -10, 1
	playsewithpan SE_W088, +63
	delay 2
	createsprite gUnknown_08596B04, 130, -20, 0, -10, 1
	playsewithpan SE_W088, +63
	delay 2
	createsprite gUnknown_08596B04, 130, 30, 2, 10, 1
	playsewithpan SE_W088, +63
	delay 2
	return

Move_THIEF:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	delay 1
	fadetobg BG_DARK
	waitbgfadein
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, 2, 6, 4
	delay 6
	playsewithpan SE_W233, +63
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 8, 1
	waitforvisualfinish
	delay 20
	clearmonbg ANIM_TARGET
	blendoff
	restorebg
	waitbgfadein
	end

Move_BUBBLE_BEAM:
	loadspritegfx 0x27A2
	loadspritegfx ANIM_TAG_155
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	delay 1
	call Bulbblebeam1
	createvisualtask AnimTask_SwayMon, 5, 0, 3, 3072, 8, ANIM_TARGET
	call Bulbblebeam1
	call Bulbblebeam1
	waitforvisualfinish
	call WaterBubbleEffect
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end
Bulbblebeam1:
	createsprite gBattleAnimSpriteTemplate_8595068, 2, 18, 0, 35, 70, 0, 256, 50
	playsewithpan SE_W145, -64
	delay 3
	createsprite gBattleAnimSpriteTemplate_8595068, 2, 18, 0, 20, 40, -10, 256, 50
	playsewithpan SE_W145, -64
	delay 3
	createsprite gBattleAnimSpriteTemplate_8595068, 2, 18, 0, 10, -60, 0, 256, 50
	playsewithpan SE_W145, -64
	delay 3
	createsprite gBattleAnimSpriteTemplate_8595068, 2, 18, 0, 15, -15, 10, 256, 50
	playsewithpan SE_W145, -64
	delay 3
	createsprite gBattleAnimSpriteTemplate_8595068, 2, 18, 0, 30, 10, -10, 256, 50
	playsewithpan SE_W145, -64
	delay 3
	createsprite gBattleAnimSpriteTemplate_8595068, 2, 18, 0, 25, -30, 10, 256, 50
	playsewithpan SE_W145, -64
	delay 3
	return

Move_ICY_WIND:
	loadspritegfx ANIM_TAG_141
	loadspritegfx 0x279E
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8116620, 10, 11, 4, 0, 4, RGB_BLACK
	fadetobg BG_ICE
	waitbgfadeout
	playsewithpan SE_W196, 0
	waitbgfadein
	waitforvisualfinish
	panse_1B SE_W016, -64, +63, +2, 0
	call IcyWind1
	delay 5
	call IcyWind1
	playsewithpan SE_W016B, +63
	delay 0x37
	call IcyWindEffect2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	restorebg
	waitbgfadeout
	createvisualtask sub_8116620, 10, 11, 4, 4, 0, RGB_BLACK
	waitbgfadein
	end
IcyWind1:
	createsprite gUnknown_08595B98, 0xA8, 0, 0, 0, 0, 72, 1
	delay 5
	createsprite gUnknown_08595B98, 0xA8, 0, 10, 0, 10, 72, 1
	delay 5
	createsprite gUnknown_08595B98, 0xA8, 0, -10, 0, -10, 72, 1
	delay 5
	createsprite gUnknown_08595B98, 0xA8, 0, 15, 0, 15, 72, 1
	delay 5
	createsprite gUnknown_08595B98, 0xA8, 0, -5, 0, -5, 72, 1
	return

Move_SMOKESCREEN:
	loadspritegfx 0x2720
	loadspritegfx 0x2721
	playsewithpan SE_W104, -64
	createsprite gUnknown_085CE050, 130, 20, 0, 0, 0, 35, -25
	waitforvisualfinish
	createvisualtask sub_815A160, 2
	delay 2
	playsewithpan SE_W028, +63
	createsprite gUnknown_085CE038, 132, 0, -12, 104, 0, 75
	createsprite gUnknown_085CE038, 132, 0, -12, 72, 1, 75
	createsprite gUnknown_085CE038, 132, 0, -6, 56, 1, 75
	createsprite gUnknown_085CE038, 132, 0, -6, 88, 0, 75
	createsprite gUnknown_085CE038, 132, 0, 0, 56, 0, 75
	createsprite gUnknown_085CE038, 132, 0, 0, 88, 1, 75
	createsprite gUnknown_085CE038, 132, 0, 6, 72, 0, 75
	createsprite gUnknown_085CE038, 132, 0, 6, 104, 1, 75
	createsprite gUnknown_085CE038, 132, 0, 12, 72, 0, 75
	createsprite gUnknown_085CE038, 132, 0, 12, 56, 1, 75
	createsprite gUnknown_085CE038, 132, 0, 18, 80, 0, 75
	createsprite gUnknown_085CE038, 132, 0, 18, 72, 1, 75
	waitforvisualfinish
	end

Move_CONVERSION:
	loadspritegfx 0x2722
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	setalpha 16, 0
	delay 0
	playsewithpan SE_W129, -64
	createsprite gUnknown_08592E74, 2, -24, -24
	delay 3
	createsprite gUnknown_08592E74, 2, -8, -24
	delay 3
	createsprite gUnknown_08592E74, 2, 8, -24
	delay 3
	createsprite gUnknown_08592E74, 2, 24, -24
	delay 3
	playsewithpan SE_W129, -64
	createsprite gUnknown_08592E74, 2, -24, -8
	delay 3
	createsprite gUnknown_08592E74, 2, -8, -8
	delay 3
	createsprite gUnknown_08592E74, 2, 8, -8
	delay 3
	createsprite gUnknown_08592E74, 2, 24, -8
	delay 3
	playsewithpan SE_W129, -64
	createsprite gUnknown_08592E74, 2, -24, 8
	delay 3
	createsprite gUnknown_08592E74, 2, -8, 8
	delay 3
	createsprite gUnknown_08592E74, 2, 8, 8
	delay 3
	createsprite gUnknown_08592E74, 2, 24, 8
	delay 3
	playsewithpan SE_W129, -64
	createsprite gUnknown_08592E74, 2, -24, 24
	delay 3
	createsprite gUnknown_08592E74, 2, -8, 24
	delay 3
	createsprite gUnknown_08592E74, 2, 8, 24
	delay 3
	createsprite gUnknown_08592E74, 2, 24, 24
	delay 20
	playsewithpan SE_W112, -64
	createvisualtask sub_8115D94, 2, 10018, 1, 1, 14335, 12, 0, 0
	delay 6
	createvisualtask sub_81022D4, 5
	waitforvisualfinish
	delay 1
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

Move_CONVERSION_2:
	loadspritegfx 0x2722
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 0, 16
	delay 0
	playsewithpan SE_W112, +63
	createsprite gUnknown_08592EA4, 2, -24, -24, 60
	createsprite gUnknown_08592EA4, 2, -8, -24, 65
	createsprite gUnknown_08592EA4, 2, 8, -24, 70
	createsprite gUnknown_08592EA4, 2, 24, -24, 75
	createsprite gUnknown_08592EA4, 2, -24, -8, 80
	createsprite gUnknown_08592EA4, 2, -8, -8, 85
	createsprite gUnknown_08592EA4, 2, 8, -8, 90
	createsprite gUnknown_08592EA4, 2, 24, -8, 95
	createsprite gUnknown_08592EA4, 2, -24, 8, 100
	createsprite gUnknown_08592EA4, 2, -8, 8, 105
	createsprite gUnknown_08592EA4, 2, 8, 8, 110
	createsprite gUnknown_08592EA4, 2, 24, 8, 115
	createsprite gUnknown_08592EA4, 2, -24, 24, 120
	createsprite gUnknown_08592EA4, 2, -8, 24, 125
	createsprite gUnknown_08592EA4, 2, 8, 24, 130
	createsprite gUnknown_08592EA4, 2, 24, 24, 135
	createvisualtask sub_81023E0, 5
	delay 60
	playsewithpan SE_W129, +63
	delay 10
	playsewithpan SE_W129, +63
	delay 10
	playsewithpan SE_W129, +63
	delay 10
	playsewithpan SE_W129, +63
	delay 10
	playsewithpan SE_W129, +63
	delay 10
	playsewithpan SE_W129, +63
	delay 10
	playsewithpan SE_W129, +63
	delay 10
	playsewithpan SE_W129, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_ROLLING_KICK:
	loadspritegfx ANIM_TAG_143
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 18, 6, 1, 4
	playsewithpan SE_W104, -64
	delay 6
	playsewithpan SE_W104, -64
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, 20, 0, 0, 4
	createsprite gUnknown_08595EE0, 2, -24, 0, 48, 10, 160, 0
	delay 5
	playsewithpan SE_W233B, +63
	createsprite gBasicHitSplatSpriteTemplate, 2, -8, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 1, 8
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_HEADBUTT:
	loadspritegfx ANIM_TAG_135
	createsprite gUnknown_08592CD8, 2, 0
	playsewithpan SE_W029, -64
	waitforvisualfinish
	delay 2
	createsprite gUnknown_08592CD8, 2, 1
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 4, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	createsprite gUnknown_08592CD8, 2, 2
	createsprite gUnknown_085973E8, 131, 0, 0, 1, 1
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	end

Move_HORN_ATTACK:
	loadspritegfx ANIM_TAG_135
	loadspritegfx 0x2724
	createsprite gUnknown_08592CD8, 2, 0
	playsewithpan SE_W029, -64
	waitforvisualfinish
	delay 2
	createsprite gUnknown_08592CD8, 2, 1
	createsprite gUnknown_08592F44, 132, 0, 0, 10
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 4, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	createsprite gUnknown_08592CD8, 2, 2
	createsprite gUnknown_085973E8, 131, 0, 0, 1, 1
	playsewithpan SE_W030, +63
	waitforvisualfinish
	end

Move_FURY_ATTACK:
	loadspritegfx ANIM_TAG_135
	loadspritegfx 0x2724
	createvisualtask sub_80D6134, 2, 4, 256, 0, 2
	choosetwoturnanim FuryAttackRight, FuryAttackLeft
FuryAttackContinue:
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	waitforvisualfinish
	end

FuryAttackRight:
	createsprite gUnknown_08592F44, 132, 8, 8, 10
	waitforvisualfinish
	createsprite gUnknown_085973E8, 131, 0, 0, 1, 1
	playsewithpan SE_W030, +63
	goto FuryAttackContinue

FuryAttackLeft:
	createsprite gUnknown_08592F44, 132, -8, -8, 10
	waitforvisualfinish
	createsprite gUnknown_085973E8, 131, 0, 0, 1, 1
	playsewithpan SE_W030, +63
	goto FuryAttackContinue

Move_HORN_DRILL:
	loadspritegfx ANIM_TAG_135
	loadspritegfx 0x2724
	jumpifcontest HornDrillInContest
	fadetobg BG_DRILL
	waitbgfadeout
	createvisualtask sub_8117660, 5, -2304, 768, 1, -1
HornDrillContinue:
	waitbgfadein
	setalpha 12, 8
	createsprite gUnknown_08592CD8, 2, 0
	playsewithpan SE_W029, -64
	waitforvisualfinish
	delay 2
	createsprite gUnknown_08592CD8, 2, 1
	createsprite gUnknown_08592F44, 132, 0, 0, 12
	waitforvisualfinish
	playse SE_BAN
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 40, 1
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 10, 0, 40, 1
	createsprite gUnknown_085973E8, 131, 0, 0, 1, 3
	playsewithpan SE_W030, +63
	delay 4
	createsprite gUnknown_085973E8, 131, 0, 2, 1, 3
	playsewithpan SE_W030, +63
	delay 4
	createsprite gUnknown_085973E8, 131, -4, 3, 1, 3
	playsewithpan SE_W030, +63
	delay 4
	createsprite gUnknown_085973E8, 131, -8, -5, 1, 3
	playsewithpan SE_W030, +63
	delay 4
	createsprite gUnknown_085973E8, 131, 4, -12, 1, 3
	playsewithpan SE_W030, +63
	delay 4
	createsprite gUnknown_085973E8, 131, 16, 0, 1, 3
	playsewithpan SE_W030, +63
	delay 4
	createsprite gUnknown_085973E8, 131, 5, 18, 1, 3
	playsewithpan SE_W030, +63
	delay 4
	createsprite gUnknown_085973E8, 131, -17, 12, 1, 2
	playsewithpan SE_W030, +63
	delay 4
	createsprite gUnknown_085973E8, 131, -21, -15, 1, 2
	playsewithpan SE_W030, +63
	delay 4
	createsprite gUnknown_085973E8, 131, 8, -27, 1, 2
	playsewithpan SE_W030, +63
	delay 4
	createsprite gUnknown_085973E8, 131, 32, 0, 1, 2
	playsewithpan SE_W030, +63
	delay 4
	createsprite gUnknown_08592CD8, 2, 2
	waitforvisualfinish
	restorebg
	waitbgfadeout
	setarg 7, 0xFFFF
	waitbgfadein
	end

HornDrillInContest:
	fadetobg BG_DRILL_CONTESTS
	waitbgfadeout
	createvisualtask sub_8117660, 5, 2304, 768, 0, -1
	goto HornDrillContinue

Move_THRASH:
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	createvisualtask sub_8104C38, 2
	createvisualtask sub_8104CA4, 2
	createsprite gUnknown_08595EB0, 131, 1, 10, 0
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 7, 1
	playsewithpan SE_W004, +63
	delay 0x1C
	createsprite gUnknown_08595EB0, 131, 1, 10, 1
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 4, 0, 7, 1
	playsewithpan SE_W233B, +63
	delay 0x1C
	createsprite gUnknown_08595EB0, 131, 1, 10, 3
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 8, 0, 16, 1
	playsewithpan SE_W025B, +63
	end

Move_SING:
	loadspritegfx ANIM_TAG_072
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8102BE8, 2
	waitforvisualfinish
	panse_1B SE_W047, -64, +63, +2, 0
	createsprite gUnknown_08593008, 130, 7, 0, 12
	delay 5
	createsprite gUnknown_08593008, 130, 6, 1, 12
	delay 5
	createsprite gUnknown_08593008, 130, 1, 2, 12
	delay 5
	createsprite gUnknown_08593008, 130, 2, 3, 12
	delay 5
	createsprite gUnknown_08593008, 130, 3, 0, 12
	delay 4
	createsprite gUnknown_08593008, 130, 2, 1, 12
	delay 4
	createsprite gUnknown_08593008, 130, 5, 2, 12
	delay 4
	createsprite gUnknown_08593008, 130, 6, 3, 12
	delay 4
	createsprite gUnknown_08593008, 130, 2, 0, 12
	delay 4
	createsprite gUnknown_08593008, 130, 2, 1, 12
	delay 4
	createsprite gUnknown_08593008, 130, 1, 2, 12
	delay 4
	createsprite gUnknown_08593008, 130, 5, 3, 12
	delay 4
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	createvisualtask sub_8102CA0, 2
	waitforvisualfinish
	end

Move_LOW_KICK:
	loadspritegfx ANIM_TAG_143
	loadspritegfx ANIM_TAG_135
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, 20, 0, 0, 4
	createsprite gUnknown_08595EE0, 130, -24, 28, 40, 8, 160, 0
	delay 4
	createsprite gBasicHitSplatSpriteTemplate, 130, -8, 8, 1, 2
	createvisualtask sub_80D6134, 2, 6, 384, 1, 2
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 1, 4
	end

Move_EARTHQUAKE:
	createvisualtask sub_81152DC, 5, 5, 10, 50
	createvisualtask sub_81152DC, 5, 4, 10, 50
	playsewithpan SE_W089, 0
	delay 10
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 1, 3, 1, 0, 14, 0x7FFF, 14
	delay 16
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 1, 3, 1, 0, 14, 0x7FFF, 14
	end

Move_FISSURE:
	loadspritegfx ANIM_TAG_074
	createvisualtask sub_81152DC, 3, 5, 10, 50
	createvisualtask sub_81152DC, 3, 1, 10, 50
	playsewithpan SE_W089, +63
	delay 8
	call Fissure1
	delay 15
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 1, 3, 1, 0, 14, 0x7FFF, 14
	delay 15
	call Fissure2
	delay 15
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 1, 3, 1, 0, 14, 0x7FFF, 14
	delay 15
	call Fissure1
	delay 50
	fadetobg BG_FISSURE
	waitbgfadeout
	createvisualtask sub_8115628, 5, 1, 5, -1
	waitbgfadein
	delay 0x28
	restorebg
	waitbgfadeout
	setarg 7, 0xFFFF
	waitbgfadein
	end

Fissure1:
	createsprite gUnknown_085971FC, 130, 1, 0, 12, -48, -16, 24
	createsprite gUnknown_085971FC, 130, 1, 0, 16, -16, -10, 24
	createsprite gUnknown_085971FC, 130, 1, 1, 14, -52, -18, 24
	createsprite gUnknown_085971FC, 130, 1, 1, 12, -32, -16, 24
	playsewithpan SE_W091, +63
	return

Fissure2:
	createsprite gUnknown_085971FC, 130, 1, 0, 12, -24, -16, 24
	createsprite gUnknown_085971FC, 130, 1, 0, 16, -38, -10, 24
	createsprite gUnknown_085971FC, 130, 1, 1, 14, -20, -18, 24
	createsprite gUnknown_085971FC, 130, 1, 1, 12, -36, -16, 24
	playsewithpan SE_W091, +63
	return

Move_DIG:
	choosetwoturnanim DigSetUp, DigUnleash
DigEnd:
	end
DigSetUp:
	loadspritegfx ANIM_TAG_074
	loadspritegfx 0x2829
	createsprite gUnknown_08597214, 1, 0, 0, 180
	createsprite gUnknown_08597214, 1, 0, 1, 180
	monbg_22 ANIM_ATTACKER
	delay 1
	createvisualtask sub_8114CBC, 2, 0
	delay 6
	call DigSetUp1
	call DigSetUp1
	call DigSetUp1
	call DigSetUp1
	call DigSetUp1
	waitforvisualfinish
	clearmonbg_23 ANIM_ATTACKER
	delay 1
	createvisualtask sub_8114CBC, 2, 1
	goto DigEnd
DigUnleash:
	loadspritegfx ANIM_TAG_135
	loadspritegfx 0x2829
	createvisualtask sub_8114F14, 2, 0
	waitforvisualfinish
	monbg ANIM_ATTACKER
	createsprite gUnknown_08597214, 1, 0, 0, 48
	createsprite gUnknown_08597214, 1, 0, 1, 48
	delay 1
	createvisualtask sub_8114F14, 2, 1
	delay 16
	createsprite gBasicHitSplatSpriteTemplate, 2, -8, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	playsewithpan SE_W025B, -64
	clearmonbg ANIM_ATTACKER
	goto DigEnd
DigSetUp1:
	createsprite gUnknown_085971FC, 2, 0, 0, 12, 4, -16, 18
	createsprite gUnknown_085971FC, 2, 0, 0, 16, 4, -10, 18
	createsprite gUnknown_085971FC, 2, 0, 1, 14, 4, -18, 18
	createsprite gUnknown_085971FC, 2, 0, 1, 12, 4, -16, 18
	playsewithpan SE_W091, -64
	delay 0x20
	return

Move_MEDITATE:
	call SetPsychicBackground
	createvisualtask sub_810F7D4, 2
	playsewithpan SE_W029, -64
	delay 16
	playsewithpan SE_W036, -64
	waitforvisualfinish
	call UnsetPsychicBackground
	end

Move_AGILITY:
	monbg ANIM_ATK_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 24, 6, 4, 4
	createvisualtask sub_81169C0, 2, 0, 4, 7, 10
	playsewithpan SE_W104, -64
	delay 12
	playsewithpan SE_W104, -64
	delay 12
	playsewithpan SE_W104, -64
	delay 12
	playsewithpan SE_W104, -64
	delay 12
	playsewithpan SE_W104, -64
	delay 12
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 1
	end

Move_QUICK_ATTACK:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_ATK_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 24, 6, 1, 5
	createvisualtask sub_81169C0, 2, 0, 4, 7, 3
	playsewithpan SE_W026, -64
	delay 4
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	createsprite gBasicHitSplatSpriteTemplate, 132, 0, 0, 1, 1
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	waitforvisualfinish
	end

Move_RAGE:
	loadspritegfx ANIM_TAG_135
	loadspritegfx 0x2767
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_BlendMonInAndOut, 3, ANIM_ATTACKER, RGB_RED, 10, 0, 2
	createsprite gUnknown_0859368C, 2, 0, -20, -28
	playsewithpan SE_W207B, -64
	delay 20
	createsprite gUnknown_0859368C, 2, 0, 20, -28
	playsewithpan SE_W207B, -64
	waitforvisualfinish
	createsprite gHorizontalLungeSpriteTemplate, 2, 4, 6
	delay 4
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
	createvisualtask sub_80D6388, 2, 1, 1, 10, 1, 0
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	end

Move_TELEPORT:
	call SetPsychicBackground
	createvisualtask sub_810F83C, 2
	playsewithpan SE_W100, -64
	delay 15
	call UnsetPsychicBackground
	waitforvisualfinish
	end

Move_DOUBLE_TEAM:
	createvisualtask sub_81029B4, 2
	setalpha 12, 8
	monbg ANIM_ATK_PARTNER
	playsewithpan SE_W104, -64
	delay 0x20
	playsewithpan SE_W104, -64
	delay 24
	playsewithpan SE_W104, -64
	delay 16
	playsewithpan SE_W104, -64
	delay 8
	playsewithpan SE_W104, -64
	delay 8
	playsewithpan SE_W104, -64
	delay 8
	playsewithpan SE_W104, -64
	delay 8
	playsewithpan SE_W104, -64
	delay 8
	playsewithpan SE_W104, -64
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 1
	end

Move_MINIMIZE:
	setalpha 10, 8
	createvisualtask sub_8104674, 2
	loopsewithpan SE_W107, -64, 0x22, 3
	waitforvisualfinish
	blendoff
	end

Move_METRONOME:
	loadspritegfx 0x2750
	loadspritegfx ANIM_TAG_209
	createsprite gUnknown_08593114, 11, 0, 100
	playsewithpan SE_W118, -64
	delay 6
	createsprite gUnknown_085931BC, 12, 0
	delay 24
	loopsewithpan SE_W039, -64, 0x16, 3
	waitforvisualfinish
	end

Move_SKULL_BASH:
	choosetwoturnanim SkullBashSetUp, SkullBashAttack
SkullBashEnd:
	end

SkullBashSetUp:
	call SkullBashSetUp1
	call SkullBashSetUp1
	waitforvisualfinish
	goto SkullBashEnd

SkullBashSetUp1:
	createsprite gUnknown_0857FE88, 2, 0, -24, 0, 0, 10, 0
	playsewithpan SE_W036, -64
	waitforvisualfinish
	createvisualtask sub_80D6134, 2, 16, 96, 0, 2
	waitforvisualfinish
	createsprite gUnknown_0857FE88, 2, 0, 24, 0, 0, 10, 1
	waitforvisualfinish
	return

SkullBashAttack:
	loadspritegfx ANIM_TAG_135
	createvisualtask sub_8101C94, 2, 0
	playsewithpan SE_W036, -64
	waitforvisualfinish
	playse SE_BAN
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 1, 3, 1, 0, 14, 0x7FFF, 14
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 40, 1
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 10, 0, 40, 1
	createsprite gUnknown_085973E8, 132, 0, 0, 1, 0
	loopsewithpan SE_W025B, +63, 8, 3
	waitforvisualfinish
	createvisualtask sub_8101C94, 2, 1
	goto SkullBashEnd

Move_AMNESIA:
	loadspritegfx 0x276D
	call SetPsychicBackground
	delay 8
	createsprite gUnknown_08596744, 20
	playsewithpan SE_W118, -64
	delay 0x36
	loopsewithpan SE_W118, -64, 16, 3
	waitforvisualfinish
	call UnsetPsychicBackground
	end

Move_KINESIS:
	loadspritegfx 0x275B
	loadspritegfx 0x2771
	playsewithpan SE_W060, -64
	call SetPsychicBackground
	createsprite gUnknown_085966DC, 20
	createsprite gUnknown_08593344, 19, 32, -8, 0
	createsprite gUnknown_08593344, 19, 32, 16, 1
	loopsewithpan SE_W109, -64, 0x15, 2
	delay 60
	playsewithpan SE_W146, -64
	delay 30
	loopsewithpan SE_W146, -64, 20, 2
	delay 70
	playsewithpan SE_W207B, -64
	waitforvisualfinish
	call UnsetPsychicBackground
	end

Move_GLARE:
	loadspritegfx 0x2808
	loadspritegfx 0x27EA
	createvisualtask sub_815E114, 5, 0
	playsewithpan SE_W060B, -64
	waitforvisualfinish
	createvisualtask sub_8116620, 5, 1, 0, 0, 16, RGB_BLACK
	waitforvisualfinish
	createsprite gUnknown_08593A84, 0, -16, -8
	createsprite gUnknown_08593A84, 0, 16, -8
	createvisualtask sub_81064F8, 5
	playsewithpan SE_W043, -64
	delay 2
	createvisualtask sub_810A094, 3, 20, 1, 0
	waitforvisualfinish
	createvisualtask sub_8116620, 5, 1, 0, 16, 0, RGB_BLACK
	end

Move_BARRAGE:
	loadspritegfx 0x280E
	createvisualtask sub_815E47C, 3
	playsewithpan SE_W207, -64
	delay 24
	createsprite gBattleAnimSpriteTemplate_85972D8, 2, 8, 1, 40, 1
	createvisualtask AnimTask_ShakeMon, 3, ANIM_TARGET, 0, 4, 20, 1
	createvisualtask AnimTask_ShakeMon, 3, ANIM_DEF_PARTNER, 0, 4, 20, 1
	loopsewithpan SE_W070, +63, 8, 2
	end

Move_SKY_ATTACK:
	choosetwoturnanim SkyAttackSetUp, SkyAttackUnleash
SkyAttackEnd:
	end
SkyAttackSetUp:
	monbg ANIM_DEF_PARTNER
	setalpha 12, 11
	createvisualtask AnimTask_IsTargetPartner, 5, ARG_RET_ID
	jumpretfalse SkyAttackSetUpAgainstOpponent
	goto SkyAttackSetUpAgainstPartner
SkyAttackSetUpAgainstOpponent:
	createvisualtask sub_8116620, 10, 27, 1, 0, 12, RGB_BLACK
	waitforvisualfinish
	delay 12
	createvisualtask sub_8116620, 10, 2, 1, 8, 0, RGB_BLACK
	createvisualtask sub_81152DC, 5, 0, 2, 16
	loopsewithpan SE_W287, -64, 4, 8
	createvisualtask sub_8116620, 10, 2, 1, 0, 15, RGB_WHITE
	delay 20
	createvisualtask sub_8116620, 10, 2, 1, 15, 0, RGB_WHITE
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 25, 1, 8, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto SkyAttackEnd
SkyAttackSetUpAgainstPartner:
	createvisualtask sub_8116664, 10, 1, 1, 0, 12, 0
	waitforvisualfinish
	delay 12
	createvisualtask sub_8116620, 10, 2, 1, 8, 0, RGB_BLACK
	createvisualtask sub_81152DC, 5, 0, 2, 16
	playsewithpan SE_W287, -64
	delay 8
	createvisualtask sub_8116620, 10, 2, 1, 0, 15, RGB_WHITE
	delay 20
	createvisualtask sub_8116620, 10, 2, 1, 15, 0, RGB_WHITE
	waitforvisualfinish
	createvisualtask sub_8116664, 10, 4, 1, 8, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto SkyAttackEnd
SkyAttackUnleash:
	loadspritegfx ANIM_TAG_135
	loadspritegfx 0x282C
	call SetFlyingBg
	monbg ANIM_ATTACKER
	createvisualtask sub_8116620, 10, 2, 0, 0, 16, RGB_WHITE
	delay 4
	createvisualtask sub_81136E8, 5, 0
	waitforvisualfinish
	createvisualtask sub_8159244, 5, 238, -64
	createsprite gUnknown_08596514, 130
	delay 14
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 10, 0, 18, 1
	createvisualtask sub_8159210, 5, 141, 63
	delay 20
	createvisualtask sub_81137E4, 5, 1
	delay 2
	createvisualtask sub_8116620, 10, 2, 0, 15, 0, RGB_WHITE
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	call UnsetFlyingBg
	goto SkyAttackEnd

Move_FLASH:
	playsewithpan SE_W043, -64
	createvisualtask sub_8117494, 2
	waitforvisualfinish
	end

Move_SPLASH:
	createvisualtask sub_8104938, 2, 0, 3
	delay 8
	loopsewithpan SE_W039, -64, 0x26, 3
	waitforvisualfinish
	end

Move_ACID_ARMOR:
	monbg ANIM_ATTACKER
	setalpha 15, 0
	createvisualtask sub_815D240, 2, 0
	playsewithpan SE_W151, -64
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_ATTACKER
	delay 1
	end

Move_SHARPEN:
	loadspritegfx 0x27C9
	createsprite gUnknown_08592DE4, 2
	waitforvisualfinish
	end

Move_SUPER_FANG:
	loadspritegfx 0x27D0
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 1, 0, 20, 1
	playsewithpan SE_W082, -64
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 3, 0, 48, 1
	createvisualtask AnimTask_BlendMonInAndOut, 2, ANIM_ATTACKER, RGB(31, 6, 1), 12, 4, 1
	waitforvisualfinish
	delay 20
	createsprite gHorizontalLungeSpriteTemplate, 2, 4, 4
	delay 4
	createsprite gUnknown_08592F74, 130
	playsewithpan SE_W044, +63
	delay 8
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 1, 3, 1, 2143, 14, 0x7FFF, 14
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 7, 12, 1
	waitforvisualfinish
	blendoff
	end

Move_SLASH:
	loadspritegfx 0x27C7
	createsprite gUnknown_08592D2C, 130, 1, -8, 0
	playsewithpan SE_W013, +63
	delay 4
	createsprite gUnknown_08592D2C, 130, 1, 8, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 18, 1
	playsewithpan SE_W013, +63
	waitforvisualfinish
	end

Move_STRUGGLE:
	loadspritegfx ANIM_TAG_135
	loadspritegfx 0x27E7
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 3, 0, 12, 4
	createsprite gUnknown_08593B80, 2, 0, 0, 2
	createsprite gUnknown_08593B80, 2, 0, 1, 2
	loopsewithpan SE_W029, -64, 12, 4
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W025B, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SKETCH:
	loadspritegfx 0x2712
	monbg ANIM_TARGET
	createvisualtask sub_8104E74, 2
	createsprite gUnknown_085936D4, 130
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	createvisualtask sub_8104938, 2, 0, 2
	loopsewithpan SE_W039, -64, 0x26, 2
	end

Move_NIGHTMARE:
	fadetobg BG_GHOST
	waitbgfadein
	jumpifcontest NightmareInContest
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8111C50, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 40, 1
	playsewithpan SE_W171, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	restorebg
	waitbgfadein
	end
NightmareInContest:
	createvisualtask AnimTask_BlendMonInAndOut, 2, ANIM_ATTACKER, RGB_WHITE, 10, 2, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATTACKER, 3, 0, 32, 1
	playsewithpan SE_W171, +63
	waitforvisualfinish
	restorebg
	waitbgfadein
	end

Move_FLAIL:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask sub_815C770, 2, 0
	loopsewithpan SE_W029, -64, 8, 2
	waitforvisualfinish
	createsprite gUnknown_085973A0, 131, 1, 3
	createvisualtask sub_80D6388, 2, 0, 1, 30, 1, 0
	playsewithpan SE_W025B, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SPITE:
	fadetobg BG_GHOST
	playsewithpan SE_W060, -64
	waitbgfadein
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8115A04, 2, 2, 2, 6, 0, 8, RGB_WHITE
	createvisualtask sub_8111E50, 2
	loopsewithpan SE_W060, +63, 20, 3
	waitforvisualfinish
	restorebg
	waitbgfadein
	clearmonbg ANIM_TARGET
	end

Move_MACH_PUNCH:
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	monbg ANIM_ATK_PARTNER
	createvisualtask AnimTask_IsAttackerOpponentSide, 2
	jumprettrue MachPunchAgainstPlayer
	fadetobg BG_HIGHSPEED_OPPONENT
MachPunchContinue:
	waitbgfadeout
	createvisualtask sub_8117660, 5, -2304, 0, 1, -1
	waitbgfadein
	delay 0
	setalpha 9, 8
	createvisualtask sub_80A8BC4, 2, 28968, 10
	playsewithpan SE_W026, -64
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, 131, 0, 0, 1, 1
	createsprite gFistFootSpriteTemplate, 132, 0, 0, 8, 1, 0
	playsewithpan SE_W004, +63
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	restorebg
	waitbgfadeout
	setarg 7, 0xFFFF
	waitbgfadein
	end
MachPunchAgainstPlayer:
	fadetobg BG_HIGHSPEED_PLAYER
	goto MachPunchContinue

Move_FORESIGHT:
	loadspritegfx 0x2812
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 16, 0
	createsprite gUnknown_085CE8C4, 130, 1
	delay 17
	loopsewithpan SE_W166, +63, 16, 4
	delay 48
	delay 24
	playsewithpan SE_W166, +63
	delay 10
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_TARGET, RGB_WHITE, 12, 2, 1
	playsewithpan SE_W197, +63
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	end

Move_DESTINY_BOND:
	loadspritegfx 0x27CC
	fadetobg BG_GHOST
	playsewithpan SE_W060, -64
	waitbgfadein
	createvisualtask sub_81123C4, 5, 0, 48
	playsewithpan SE_W109, -64
	delay 48
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 24, 1
	createvisualtask sub_8116664, 2, 6, 1, 0, 12, 30653
	delay 24
	createvisualtask sub_8116664, 2, 6, 1, 12, 0, 30653
	playsewithpan SE_W171, +63
	waitforvisualfinish
	restorebg
	waitbgfadein
	blendoff
	clearmonbg 5
	end

Move_ENDURE:
	loadspritegfx 0x27C8
	playsewithpan SE_W082, -64
	call EndureEffect
	delay 8
	createvisualtask sub_8115A04, 2, 2, 2, 2, 0, 11, RGB_RED
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 32, 1
	call EndureEffect
	delay 8
	call EndureEffect
	waitforvisualfinish
	end

EndureEffect:
	createsprite gUnknown_08592D8C, 2, 0, -24, 26, 2
	delay 4
	createsprite gUnknown_08592D8C, 2, 0, 14, 28, 1
	delay 4
	createsprite gUnknown_08592D8C, 2, 0, -5, 10, 2
	delay 4
	createsprite gUnknown_08592D8C, 2, 0, 28, 26, 3
	delay 4
	createsprite gUnknown_08592D8C, 2, 0, -12, 0, 1
	return

Move_CHARM:
	loadspritegfx 0x27E2
	createvisualtask sub_815C478, 5, 0, 2, 0
	createsprite gUnknown_08593970, 3, 0, 20
	playsewithpan SE_W204, -64
	delay 15
	createsprite gUnknown_08593970, 3, -20, 20
	playsewithpan SE_W204, -64
	delay 15
	createsprite gUnknown_08593970, 3, 20, 20
	playsewithpan SE_W204, -64
	waitforvisualfinish
	end

Move_ROLLOUT:
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_074
	loadspritegfx ANIM_TAG_058
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createvisualtask sub_8110F74, 2
	waitforvisualfinish
	createvisualtask sub_80D6388, 2, 0, 1, 30, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, 4, 0, 0, 1, 2
	playsewithpan SE_W025B, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_FALSE_SWIPE:
	loadspritegfx 0x282E
	loadspritegfx ANIM_TAG_135
	createsprite gUnknown_08592D44, 130
	playsewithpan SE_W233, +63
	delay 16
	createsprite gUnknown_08592D5C, 130, 0
	playsewithpan SE_W104, +63
	delay 2
	createsprite gUnknown_08592D5C, 130, 16
	delay 2
	createsprite gUnknown_08592D5C, 130, 32
	playsewithpan SE_W104, +63
	delay 2
	createsprite gUnknown_08592D5C, 130, 48
	delay 2
	createsprite gUnknown_08592D5C, 130, 64
	playsewithpan SE_W104, +63
	delay 2
	createsprite gUnknown_08592D5C, 130, 80
	delay 2
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 6, 1
	createsprite gBasicHitSplatSpriteTemplate, 132, 0, 0, 1, 3
	playsewithpan SE_W004, +63
	end

Move_SWAGGER:
	loadspritegfx 0x2766
	loadspritegfx 0x2767
	createvisualtask sub_8104AB4, 2
	playsewithpan SE_W207, -64
	waitforvisualfinish
	createsprite gUnknown_08593658, 2
	loopsewithpan SE_W207, -64, 4, 2
	waitforvisualfinish
	delay 24
	createsprite gUnknown_0859368C, 130, 1, -20, -28
	playsewithpan SE_W207B, +63
	delay 12
	createsprite gUnknown_0859368C, 130, 1, 20, -28
	playsewithpan SE_W207B, +63
	waitforvisualfinish
	end

Move_MILK_DRINK:
	loadspritegfx 0x2773
	loadspritegfx ANIM_TAG_203
	loadspritegfx ANIM_TAG_031
	monbg ANIM_TARGET
	createsprite gUnknown_08592B3C, 2
	delay 0x28
	playsewithpan SE_W152, -64
	delay 12
	playsewithpan SE_W152, -64
	delay 20
	playsewithpan SE_W152, -64
	waitforvisualfinish
	createsprite gUnknown_0859381C, 3, 0, 0, 1, 0
	playsewithpan SE_W208, -64
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	call HealingEffect2
	waitforvisualfinish
	end

Move_MAGNITUDE:
	createvisualtask AnimTask_IsPowerOver99, 2
	waitforvisualfinish
	jumpargeq 15, FALSE, MagnitudeRegular
	jumpargeq 15, TRUE, MagnitudeIntense
MagnitudeEnd:
	end
MagnitudeRegular:
	createvisualtask sub_81152DC, 5, 5, 0, 50
	createvisualtask sub_81152DC, 5, 4, 0, 50
	loopsewithpan SE_W070, +63, 8, 10
	goto MagnitudeEnd
MagnitudeIntense:
	createvisualtask sub_81152DC, 5, 5, 0, 50
	createvisualtask sub_81152DC, 5, 4, 0, 50
	loopsewithpan SE_W070, +63, 8, 10
	delay 10
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 1, 3, 1, 0, 14, 0x7FFF, 14
	delay 16
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 1, 3, 1, 0, 14, 0x7FFF, 14
	goto MagnitudeEnd

Move_RAPID_SPIN:
	loadspritegfx ANIM_TAG_135
	loadspritegfx 0x27F5
	monbg ANIM_ATTACKER
	createsprite gUnknown_085CE288, 2, 0, 0, 32, -32, 40, -2
	createvisualtask sub_815ADB0, 2, 0, 2, 0
	loopsewithpan SE_W013B, -64, 8, 4
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, 130, 0, 0, 1, 2
	createvisualtask sub_80D6388, 2, 0, 1, 10, 1, 0
	playsewithpan SE_W003, +63
	waitforvisualfinish
	delay 8
	createvisualtask sub_815ADB0, 2, 0, 2, 1
	loopsewithpan SE_W013B, -64, 8, 4
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	end

Move_MOONLIGHT:
	loadspritegfx 0x27D2
	loadspritegfx 0x27D3
	loadspritegfx ANIM_TAG_031
	setalpha 0, 16
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 0, 16, RGB_BLACK
	waitforvisualfinish
	createsprite gUnknown_08592EBC, 2, 120, 56
	createvisualtask sub_80A7A74, 3, 0, 16, 16, 0, 1
	playsewithpan SE_W236, 0
	delay 30
	createsprite gBattleAnimSpriteTemplate_8592EEC, 0x28, -12, 0
	delay 30
	createsprite gBattleAnimSpriteTemplate_8592EEC, 0x28, -24, 0
	delay 30
	createsprite gBattleAnimSpriteTemplate_8592EEC, 0x28, 21, 0
	delay 30
	createsprite gBattleAnimSpriteTemplate_8592EEC, 0x28, 0, 0
	delay 30
	createsprite gBattleAnimSpriteTemplate_8592EEC, 0x28, 10, 0
	delay 20
	createvisualtask sub_81025C0, 2
	waitforvisualfinish
	call HealingEffect
	waitforvisualfinish
	end

Move_EXTREME_SPEED:
	loadspritegfx 0x27DF
	loadspritegfx ANIM_TAG_135
	createvisualtask AnimTask_IsAttackerOpponentSide, 2
	jumprettrue ExtremeSpeedAgainstPlayer
	fadetobg BG_HIGHSPEED_OPPONENT
ExtremeSpeedContinue:
	waitbgfadeout
	createvisualtask sub_8117660, 5, -2304, 0, 1, -1
	waitbgfadein
	createvisualtask sub_810577C, 2
	loopsewithpan SE_W013B, -64, 8, 3
	waitforvisualfinish
	delay 1
	createvisualtask sub_8117F60, 2
	monbg ANIM_TARGET
	setalpha 12, 8
	delay 0x12
	createvisualtask sub_8105810, 2
	delay 2
	playsewithpan SE_W004, +63
	createsprite gBattleAnimSpriteTemplate_85973B8, 130, 1, 0, -12, 3
	delay 10
	playsewithpan SE_W004, +63
	createsprite gBattleAnimSpriteTemplate_85973B8, 130, 1, 0, 12, 3
	delay 10
	playsewithpan SE_W233B, +63
	createsprite gBattleAnimSpriteTemplate_85973B8, 130, 1, 0, 0, 3
	waitforvisualfinish
	createvisualtask sub_8105AAC, 2
	delay 10
	createvisualtask sub_810599C, 2
	loopsewithpan SE_W104, -64, 8, 4
	waitforvisualfinish
	restorebg
	waitbgfadeout
	setarg 7, 0xFFFF
	waitbgfadein
	clearmonbg ANIM_TARGET
	blendoff
	delay 1
	setarg 7, 0x1000
	delay 1
	end
ExtremeSpeedAgainstPlayer:
	fadetobg BG_HIGHSPEED_PLAYER
	goto ExtremeSpeedContinue

Move_UPROAR:
	loadspritegfx 0x27F1
	loadspritegfx ANIM_TAG_203
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_8106D90, 2, 0
	createsprite gBattleAnimSpriteTemplate_8593898, 3, 0, 0, 0, 0, 31, 8
	playsewithpan SE_W253, -64
	createsprite gBattleAnimSpriteTemplate_8593BB8, 2, 0, 29, -12, 0
	createsprite gBattleAnimSpriteTemplate_8593BB8, 2, 0, -12, -29, 1
	delay 16
	createvisualtask sub_8106D90, 2, 0
	createsprite gBattleAnimSpriteTemplate_8593898, 3, 0, 0, 0, 0, 31, 8
	playsewithpan SE_W253, -64
	createsprite gBattleAnimSpriteTemplate_8593BB8, 2, 0, 12, -29, 1
	createsprite gBattleAnimSpriteTemplate_8593BB8, 2, 0, -29, -12, 0
	delay 16
	createvisualtask sub_8106D90, 2, 0
	createsprite gBattleAnimSpriteTemplate_8593898, 3, 0, 0, 0, 0, 31, 8
	playsewithpan SE_W253, -64
	createsprite gBattleAnimSpriteTemplate_8593BB8, 2, 0, 24, -24, 1
	createsprite gBattleAnimSpriteTemplate_8593BB8, 2, 0, -24, -24, 0
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_HEAT_WAVE:
	loadspritegfx 0x2815
	createvisualtask sub_8116848, 5, 10261, 0, 6, 6, RGB_RED
	createvisualtask sub_8110BCC, 5, 1
	createvisualtask sub_810A060, 6, 6, 31
	panse_1B SE_W257, -64, +63, +2, 0
	delay 4
	createvisualtask sub_8109DBC, 5
	delay 12
	createsprite gBattleAnimSpriteTemplate_8596BA0, 0x28, 10, 2304, 96, 1
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, 0x28, 90, 2048, 96, 1
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, 0x28, 50, 2560, 96, 1
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, 0x28, 20, 2304, 96, 1
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, 0x28, 70, 1984, 96, 1
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, 0x28, 0, 2816, 96, 1
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, 0x28, 60, 2560, 96, 1
	end

Move_HAIL:
	loadspritegfx ANIM_TAG_263
	loadspritegfx ANIM_TAG_141
	createvisualtask sub_8116620, 10, 1, 3, 0, 6, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_810C918, 5
	loopsewithpan SE_W258, 0, 8, 10
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 1, 3, 6, 0, RGB_BLACK
	end

Move_TORMENT:
	loadspritegfx 0x2767
	loadspritegfx ANIM_TAG_209
	createvisualtask sub_815AFF0, 2
	waitforvisualfinish
	createvisualtask AnimTask_BlendMonInAndOut, 2, ANIM_TARGET, RGB_RED, 10, 1, 1
	createsprite gUnknown_0859368C, 130, 1, -20, -28
	playsewithpan SE_W207B, +63
	delay 20
	createsprite gUnknown_0859368C, 130, 1, 20, -28
	playsewithpan SE_W207B, +63
	end

Move_MEMENTO:
	setalpha 0, 16
	delay 1
	createvisualtask sub_81143C0, 2
	delay 1
	createvisualtask sub_8113BAC, 5
	playsewithpan SE_W060, -64
	delay 48
	playsewithpan SE_W060B, -64
	waitforvisualfinish
	createvisualtask sub_8114470, 2
	delay 12
	setalpha 0, 16
	delay 1
	monbg_22 ANIM_TARGET
	createvisualtask sub_8113E78, 5
	playsewithpan SE_W060, +63
	waitforvisualfinish
	clearmonbg_23 ANIM_TARGET
	delay 1
	blendoff
	delay 1
	end

Move_FACADE:
	loadspritegfx 0x2803
	createvisualtask sub_815DCA4, 2, 0, 3
	createvisualtask sub_815DF0C, 2, 0, 72
	loopsewithpan SE_W207, -64, 24, 3
	end

Move_SMELLING_SALT:
	loadspritegfx 0x2807
	loadspritegfx 0x280F
	createsprite gUnknown_085CE864, 130, 1, 0, 2
	createsprite gUnknown_085CE864, 130, 1, 1, 2
	delay 0x20
	createvisualtask sub_815E840, 3, 1, 2
	loopsewithpan SE_W003, +63, 12, 2
	waitforvisualfinish
	delay 4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 6, 2
	createsprite gUnknown_085CE894, 130, 1, 8, 3
	loopsewithpan SE_W207B, +63, 16, 3
	end

Move_FOLLOW_ME:
	loadspritegfx 0x2750
	createsprite gUnknown_085931D4, 2, 0
	playsewithpan SE_W039, -64
	delay 0x12
	playsewithpan SE_W213, -64
	delay 0x47
	loopsewithpan SE_W039, -64, 0x16, 3
	end

Move_CHARGE:
	loadspritegfx 0x27E3
	loadspritegfx 0x27E4
	loadspritegfx 0x27E5
	monbg ANIM_ATTACKER
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 0, 4, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_810AAFC, 2, 0, 60, 2, 12
	playsewithpan SE_W268, -64
	delay 30
	playsewithpan SE_W268, -64
	delay 30
	playsewithpan SE_W268, -64
	createsprite gUnknown_0859595C, 2, 0
	delay 25
	playsewithpan SE_W268, -64
	delay 20
	playsewithpan SE_W268, -64
	delay 15
	playsewithpan SE_W268, -64
	delay 10
	delay 6
	loopsewithpan SE_W268, -64, 6, 5
	waitforvisualfinish
	createsprite gUnknown_0859598C, 2, 0, 16, 16
	delay 2
	createsprite gUnknown_0859598C, 2, 0, -16, -16
	playsewithpan SE_W085B, -64
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 4, 4, 0, RGB_BLACK
	clearmonbg ANIM_ATTACKER
	blendoff
	end

Move_TAUNT:
	loadspritegfx 0x27E6
	loadspritegfx ANIM_TAG_209
	loadspritegfx 0x2767
	createsprite gUnknown_08593114, 11, 0, 45
	playsewithpan SE_W118, -64
	delay 6
	createsprite gUnknown_0859324C, 12, 0
	delay 4
	loopsewithpan SE_W039, -64, 16, 2
	waitforvisualfinish
	delay 8
	createsprite gUnknown_0859368C, 130, 1, -20, -28
	playsewithpan SE_W207B, +63
	waitforvisualfinish
	delay 12
	createsprite gUnknown_0859368C, 130, 1, 20, -28
	playsewithpan SE_W207B, +63
	end

Move_HELPING_HAND:
	loadspritegfx 0x2807
	createvisualtask sub_815EC48, 5
	createsprite gUnknown_085CE8AC, 0x28, 0
	createsprite gUnknown_085CE8AC, 0x28, 1
	delay 19
	playsewithpan SE_W227, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATK_PARTNER, 2, 0, 5, 1
	delay 14
	playsewithpan SE_W227, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATK_PARTNER, 2, 0, 5, 1
	delay 20
	playsewithpan SE_W227, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATK_PARTNER, 3, 0, 10, 1
	createvisualtask AnimTask_BlendMonInAndOut, 2, ANIM_ATK_PARTNER, RGB_YELLOW, 12, 1, 1
	end

Move_ASSIST:
	loadspritegfx 0x280C
	createsprite gUnknown_085CE804, 50, 112, -16, 140, 128, 36
	delay 2
	createsprite gUnknown_085CE804, 50, 208, 128, -16, 48, 36
	playsewithpan SE_W010, 0
	delay 2
	createsprite gUnknown_085CE804, 50, -16, 112, 256, -16, 36
	playsewithpan SE_W010, 0
	delay 2
	createsprite gUnknown_085CE804, 50, 108, 128, 84, -16, 36
	playsewithpan SE_W010, 0
	delay 2
	createsprite gUnknown_085CE804, 50, -16, 56, 256, 56, 36
	playsewithpan SE_W010, 0
	end

Move_SUPERPOWER:
	loadspritegfx 0x27E4
	loadspritegfx 0x2810
	loadspritegfx 0x2811
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	setalpha 12, 8
	createsprite gUnknown_08595FEC, 130, 0
	playsewithpan SE_W025, -64
	delay 20
	createsprite gBattleAnimSpriteTemplate_85972D8, 2, 4, 1, 180, 1
	createvisualtask sub_8159244, 5, 234, 0
	delay 0x28
	createsprite gUnknown_08596004, 0x29, 200, 96, 1, 120
	delay 8
	createsprite gUnknown_08596004, 0x29, 20, 248, 4, 112
	delay 8
	createsprite gUnknown_08596004, 0x29, 130, 160, 2, 104
	delay 8
	createsprite gUnknown_08596004, 0x29, 160, 192, 0, 96
	delay 8
	createsprite gUnknown_08596004, 0x29, 60, 288, 3, 88
	delay 0x4A
	createsprite gUnknown_0859601C, 131, 0
	playsewithpan SE_W207, -64
	delay 16
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 8, 0, 16, 1
	playsewithpan SE_W025B, +63
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 1
	end

Move_RECYCLE:
	loadspritegfx 0x2826
	monbg ANIM_ATTACKER
	setalpha 0, 16
	delay 1
	createsprite gUnknown_085CE9B0, 2
	loopsewithpan SE_W036, -64, 24, 3
	waitforvisualfinish
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB_WHITE, 12, 2, 1
	playsewithpan SE_W036, -64
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_ATTACKER
	delay 1
	end

Move_BRICK_BREAK:
	loadspritegfx ANIM_TAG_167
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	loadspritegfx ANIM_TAG_208
	choosetwoturnanim BrickBreakNormal, BrickBreakShatteredWall
BrickBreakNormal:
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, 2, 3, 8
	delay 4
	delay 1
	createsprite gBasicHitSplatSpriteTemplate, 3, -18, -18, 1, 1
	playsewithpan SE_W233, +63
	delay 20
	createsprite gHorizontalLungeSpriteTemplate, 2, 3, 8
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, 3, 18, 18, 1, 1
	playsewithpan SE_W233, +63
	delay 20
	createvisualtask AnimTask_WindUpLunge, 2, ANIM_ATTACKER, -24, 0, 24, 10, 24, 3
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 0, 6, RGB_BLACK
	delay 0x25
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 1
	createsprite gFistFootSpriteTemplate, 4, 0, 0, 10, 1, 0
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 6, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	end

BrickBreakShatteredWall:
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, 2, 3, 8
	delay 4
	createsprite gUnknown_08595F90, 3, 1, 0, 0, 90, 10
	delay 1
	createsprite gBasicHitSplatSpriteTemplate, 3, -18, -18, 1, 1
	playsewithpan SE_W233, +63
	delay 20
	createsprite gHorizontalLungeSpriteTemplate, 2, 3, 8
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, 3, 18, 18, 1, 1
	playsewithpan SE_W233, +63
	delay 20
	createvisualtask AnimTask_WindUpLunge, 2, ANIM_ATTACKER, -24, 0, 24, 10, 24, 3
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 0, 6, RGB_BLACK
	delay 0x25
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 1
	createsprite gFistFootSpriteTemplate, 4, 0, 0, 10, 1, 0
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	createsprite gUnknown_08595FA8, 2, 1, 0, -8, -12
	createsprite gUnknown_08595FA8, 2, 1, 1, 8, -12
	createsprite gUnknown_08595FA8, 2, 1, 2, -8, 12
	createsprite gUnknown_08595FA8, 2, 1, 3, 8, 12
	playsewithpan SE_W280, +63
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 6, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	end

Move_YAWN:
	loadspritegfx 0x2802
	createvisualtask sub_815D64C, 2, 0
	playsewithpan SE_W281, -64
	waitforvisualfinish
	createsprite gUnknown_085CE68C, 0x85, 2
	playsewithpan SE_W255, -64
	delay 4
	createsprite gUnknown_085CE68C, 0x85, 1
	delay 4
	createsprite gUnknown_085CE68C, 0x85, 0
	waitforvisualfinish
	createvisualtask sub_815D64C, 2, 1
	playsewithpan SE_W281, +63
	end

Move_ENDEAVOR:
	loadspritegfx 0x2803
	loadspritegfx ANIM_TAG_135
	createvisualtask sub_815DCA4, 2, 0, 2
	loopsewithpan SE_W039, -64, 24, 2
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB(31, 21, 0), 12, 1, 2
	delay 6
	createvisualtask sub_80D6388, 5, 0, 1, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, 130, 12, -12, 1, 2
	playsewithpan SE_W003, +63
	delay 24
	createvisualtask sub_80D6388, 5, 0, 1, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, 130, -12, 12, 1, 2
	playsewithpan SE_W004, +63
	end

Move_ERUPTION:
	loadspritegfx 0x27D9
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 31, 2, 0, 4, RGB_RED
	waitforvisualfinish
	createvisualtask sub_8109460, 2
	waitplaysewithpan SE_W153, -64, 60
	waitforvisualfinish
	createvisualtask sub_8109460, 2
	waitplaysewithpan SE_W153, -64, 60
	waitforvisualfinish
	delay 30
	createsprite gUnknown_085955E8, 0x28, 200, -32, 0, 100, 0
	createsprite gUnknown_085955E8, 0x28, 30, -32, 16, 90, 1
	createsprite gUnknown_085955E8, 0x28, 150, -32, 32, 60, 2
	createsprite gUnknown_085955E8, 0x28, 90, -32, 48, 80, 3
	createsprite gUnknown_085955E8, 0x28, 110, -32, 64, 50, 0
	createsprite gUnknown_085955E8, 0x28, 60, -32, 80, 70, 1
	delay 0x16
	createvisualtask sub_81152DC, 5, 5, 8, 60
	createvisualtask sub_81152DC, 5, 4, 8, 60
	loopsewithpan SE_W088, +63, 16, 12
	delay 0x50
	createsprite gSimplePaletteBlendSpriteTemplate, 0x28, 31, 4, 4, 0, RGB_RED
	end

Move_SKILL_SWAP:
	loadspritegfx 0x280B
	call SetPsychicBackground
	createvisualtask sub_810FBF0, 3, 1
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_TARGET, RGB_WHITE, 12, 3, 1
	loopsewithpan SE_W179, -64, 24, 3
	delay 16
	createvisualtask sub_810FBF0, 3, 0
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB_WHITE, 12, 3, 1
	waitforvisualfinish
	call UnsetPsychicBackground
	end

Move_IMPRISON:
	loadspritegfx 0x2809
	loadspritegfx ANIM_TAG_250
	call SetPsychicBackground
	monbg ANIM_DEF_PARTNER
	createvisualtask sub_810F940, 5
	delay 8
	loopsewithpan SE_W030, -64, 8, 5
	waitforvisualfinish
	delay 4
	createsprite gUnknown_085967AC, 5, 0, 40
	createvisualtask sub_81152DC, 5, 4, 1, 10
	playsewithpan SE_W063, -64
	clearmonbg ANIM_DEF_PARTNER
	call UnsetPsychicBackground
	end

Move_GRUDGE:
	loadspritegfx 0x280D
	monbg ANIM_ATTACKER
	monbgprio_29
	fadetobg BG_GHOST
	playsewithpan SE_W060, -64
	waitbgfadein
	createvisualtask sub_8112C6C, 3
	loopsewithpan SE_W052, -64, 16, 4
	delay 10
	delay 0x50
	playsewithpan SE_W171, +63
	waitforvisualfinish
	restorebg
	waitbgfadein
	clearmonbg ANIM_ATTACKER
	end

Move_CAMOUFLAGE:
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	setalpha 16, 0
	createvisualtask sub_811675C, 5, 2, 3, 0, 14
	delay 16
	createvisualtask sub_81136E8, 2, 4
	playsewithpan SE_W185, -64
	waitforvisualfinish
	delay 8
	createvisualtask sub_811675C, 5, 2, 0, 0, 0
	waitforvisualfinish
	createvisualtask sub_81137E4, 2, 1
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_ATK_PARTNER
	end

Move_TAIL_GLOW:
	loadspritegfx 0x27E4
	monbg ANIM_ATTACKER
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 0, 4, RGB_BLACK
	waitforvisualfinish
	createsprite gUnknown_08596AC8, 66, 0
	delay 0x12
	loopsewithpan SE_W234, -64, 16, 6
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 4, 4, 0, RGB_BLACK
	clearmonbg ANIM_ATTACKER
	blendoff
	delay 1
	end

Move_LUSTER_PURGE:
	loadspritegfx 0x281B
	loadspritegfx ANIM_TAG_135
	fadetobg BG_PSYCHIC
	waitbgfadeout
	createvisualtask sub_815A5C8, 5
	waitbgfadein
	monbg ANIM_ATTACKER
	setalpha 12, 8
	playsewithpan SE_W076, -64
	createsprite gUnknown_08596898, 0x29, 0, 0, 0, 0
	delay 20
	createvisualtask sub_8116664, 5, 5, 2, 0, 16, -1
	createvisualtask sub_8116848, 5, 10267, 2, 0, 16, -1
	waitforvisualfinish
	createvisualtask sub_8116848, 5, 10135, 0, 12, 12, 23552
	waitforvisualfinish
	createsprite gUnknown_085973A0, 131, 1, 2
	createvisualtask sub_8159210, 5, 215, 63
	delay 3
	createsprite gUnknown_085973A0, 131, 1, 2
	createvisualtask sub_8159210, 5, 215, 63
	delay 3
	createsprite gUnknown_085973A0, 131, 1, 2
	createvisualtask sub_8159210, 5, 215, 63
	delay 3
	createsprite gUnknown_085973A0, 131, 1, 2
	createvisualtask sub_8159210, 5, 215, 63
	delay 3
	createsprite gUnknown_085973A0, 131, 1, 2
	createvisualtask sub_8159210, 5, 215, 63
	delay 3
	createsprite gUnknown_085973A0, 131, 1, 2
	createvisualtask sub_8159210, 5, 215, 63
	waitforvisualfinish
	createvisualtask sub_8116664, 5, 5, 2, 16, 0, -1
	createvisualtask sub_81152DC, 5, 1, 5, 14
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	call UnsetPsychicBackground
	end

Move_MIST_BALL:
	loadspritegfx ANIM_TAG_155
	loadspritegfx 0x281E
	delay 0
	playsewithpan SE_W081, -64
	createsprite gUnknown_08595C70, 0x80, 0, 0, 0, 0, 30, 0
	waitforvisualfinish
	playsewithpan SE_W028, +63
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 10, 0
	createsprite gBattleAnimSpriteTemplate_859728C, 0, 1, 1, 1, 32279, 16, 0x7FFF, 16
	delay 0
	playsewithpan SE_W114, 0
	createvisualtask sub_810C324, 5
	createvisualtask sub_8116620, 10, 4, 3, 0, 16, RGB_WHITE
	delay 8
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 4, 0, 70, 0
	delay 70
	createvisualtask sub_8116620, 10, 4, 2, 16, 0, RGB_WHITE
	end

Move_FEATHER_DANCE:
	loadspritegfx 0x281E
	monbg ANIM_DEF_PARTNER
	monbgprio_29
	playsewithpan SE_W080, +63
	delay 0
	createsprite gUnknown_08596388, 0x80, 0, -16, 64, 2, 104, 11304, 32, 1
	delay 6
	createsprite gUnknown_08596388, 0x80, 0, -16, 32, 2, 104, 11304, 32, 1
	createsprite gUnknown_08596388, 0x80, 0, -16, 0, 2, 104, 11304, 32, 1
	delay 6
	createsprite gUnknown_08596388, 0x80, 0, -16, 224, 2, 104, 11304, 32, 1
	createsprite gUnknown_08596388, 0x80, 0, -16, 128, 2, 104, 11304, 32, 1
	delay 6
	createsprite gUnknown_08596388, 0x80, 0, -16, 192, 2, 104, 11304, 32, 1
	createsprite gUnknown_08596388, 0x80, 0, -16, 160, 2, 104, 11304, 32, 1
	delay 6
	createsprite gUnknown_08596388, 0x80, 0, -16, 96, 2, 104, 11304, 32, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_TEETER_DANCE:
	loadspritegfx ANIM_TAG_072
	loadspritegfx ANIM_TAG_073
	createvisualtask sub_8160164, 5
	createsprite gUnknown_08593050, 2, 0, 16, -2
	playsewithpan SE_W298, -64
	delay 24
	createsprite gUnknown_08593050, 2, 0, 0, -2
	playsewithpan SE_W298, -64
	delay 24
	createsprite gUnknown_08593050, 2, 0, -16, -2
	playsewithpan SE_W298, -64
	delay 24
	createsprite gUnknown_08593050, 2, 1, -8, -2
	playsewithpan SE_W298, -64
	delay 24
	createsprite gUnknown_08593050, 2, 2, 8, -2
	playsewithpan SE_W298, -64
	end

Move_MUD_SPORT:
	loadspritegfx ANIM_TAG_074
	createvisualtask sub_8104938, 2, 0, 6
	delay 24
	createsprite gUnknown_085971E4, 130, 0, -4, -16
	createsprite gUnknown_085971E4, 130, 0, 4, -12
	playsewithpan SE_W091, -64
	delay 0x20
	createsprite gUnknown_085971E4, 130, 0, -3, -12
	createsprite gUnknown_085971E4, 130, 0, 5, -14
	playsewithpan SE_W091, -64
	delay 0x20
	createsprite gUnknown_085971E4, 130, 0, -5, -18
	createsprite gUnknown_085971E4, 130, 0, 3, -14
	playsewithpan SE_W091, -64
	delay 16
	createsprite gUnknown_085971E4, 130, 1, 220, 60
	waitplaysewithpan SE_W145B, 0, 15
	delay 2
	createsprite gUnknown_085971E4, 130, 1, 60, 100
	waitplaysewithpan SE_W145B, 0, 25
	delay 2
	createsprite gUnknown_085971E4, 130, 1, 140, 55
	waitplaysewithpan SE_W145B, 0, 14
	delay 2
	createsprite gUnknown_085971E4, 130, 1, 180, 50
	waitplaysewithpan SE_W145B, 0, 10
	delay 2
	createsprite gUnknown_085971E4, 130, 1, 20, 90
	waitplaysewithpan SE_W145B, 0, 0x16
	delay 2
	createsprite gUnknown_085971E4, 130, 1, 90, 90
	waitplaysewithpan SE_W145B, 0, 0x16
	delay 2
	createsprite gUnknown_085971E4, 130, 1, 160, 60
	waitplaysewithpan SE_W145B, 0, 15
	delay 2
	createsprite gUnknown_085971E4, 130, 1, 30, 90
	waitplaysewithpan SE_W145B, 0, 0x16
	delay 2
	createsprite gUnknown_085971E4, 130, 1, 120, 60
	waitplaysewithpan SE_W145B, 0, 15
	delay 2
	createsprite gUnknown_085971E4, 130, 1, 200, 40
	waitplaysewithpan SE_W145B, 0, 10
	end

Move_NEEDLE_ARM:
	loadspritegfx ANIM_TAG_266
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	loopsewithpan SE_W030, +63, 2, 16
	createsprite gUnknown_08592888, 130, 1, 0, 0, -32, 16
	delay 2
	createsprite gUnknown_08592888, 130, 1, 0, 22, -22, 16
	delay 2
	createsprite gUnknown_08592888, 130, 1, 0, 30, 0, 16
	delay 2
	createsprite gUnknown_08592888, 130, 1, 0, 20, 20, 16
	delay 2
	createsprite gUnknown_08592888, 130, 1, 0, 0, 28, 16
	delay 2
	createsprite gUnknown_08592888, 130, 1, 0, -19, 19, 16
	delay 2
	createsprite gUnknown_08592888, 130, 1, 0, -27, 0, 16
	delay 2
	createsprite gUnknown_08592888, 130, 1, 0, -18, -18, 16
	delay 2
	createsprite gUnknown_08592888, 130, 1, 0, 0, -25, 16
	delay 2
	createsprite gUnknown_08592888, 130, 1, 0, 17, -17, 16
	delay 2
	createsprite gUnknown_08592888, 130, 1, 0, 23, 0, 16
	delay 2
	createsprite gUnknown_08592888, 130, 1, 0, 16, 16, 16
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 18, 1
	createsprite gBasicHitSplatSpriteTemplate, 131, 0, 0, 1, 1
	createsprite gFistFootSpriteTemplate, 132, 0, 0, 8, 1, 0
	playsewithpan SE_W233B, +63
	createsprite gUnknown_08592888, 130, 1, 1, 0, -24, 10
	createsprite gUnknown_08592888, 130, 1, 1, 17, -17, 10
	createsprite gUnknown_08592888, 130, 1, 1, 24, 0, 10
	createsprite gUnknown_08592888, 130, 1, 1, 17, 17, 10
	createsprite gUnknown_08592888, 130, 1, 1, 0, 24, 10
	createsprite gUnknown_08592888, 130, 1, 1, -17, 17, 10
	createsprite gUnknown_08592888, 130, 1, 1, -24, 0, 10
	createsprite gUnknown_08592888, 130, 1, 1, -17, -17, 10
	end

Move_SLACK_OFF:
	loadspritegfx ANIM_TAG_031
	createvisualtask sub_8160544, 2, 0
	playsewithpan SE_W281, -64
	waitforvisualfinish
	call HealingEffect
	waitforvisualfinish
	end

Move_CRUSH_CLAW:
	loadspritegfx ANIM_TAG_167
	loadspritegfx ANIM_TAG_039
	loadspritegfx ANIM_TAG_208
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, 2, 6, 4
	delay 4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 18, 1
	createsprite gBattleAnimSpriteTemplate_8597138, 130, -10, -10, 0
	createsprite gBattleAnimSpriteTemplate_8597138, 130, -10, 10, 0
	playsewithpan SE_W013, +63
	delay 12
	createsprite gBattleAnimSpriteTemplate_8597138, 130, 10, -10, 1
	createsprite gBattleAnimSpriteTemplate_8597138, 130, 10, 10, 1
	playsewithpan SE_W013, +63
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_TARGET
	end

Move_AROMATHERAPY:
	playsewithpan SE_W080, 0
	loadspritegfx ANIM_TAG_159
	loadspritegfx ANIM_TAG_203
	loadspritegfx ANIM_TAG_049
	createsprite gSimplePaletteBlendSpriteTemplate, 0, 1, 0, 0, 7, RGB(13, 31, 12)
	delay 1
	monbg ANIM_ATTACKER
	delay 1
	createsprite gUnknown_085927AC, 0, 24, 16, 0, 2, 2, 0, 0
	createsprite gUnknown_085927AC, 66, 64, 24, 0, 3, 1, 1, 0
	createsprite gUnknown_085927C4, 0, 16, 24, 0, 2, 1, 0, 0
	delay 20
	createsprite gUnknown_085927AC, 66, 48, 12, 0, 4, 3, 1, 0
	createsprite gUnknown_085927AC, 0, 100, 16, 0, 3, 2, 0, 0
	createsprite gUnknown_085927AC, 0, 74, 24, 180, 3, 2, 0, 0
	delay 10
	createsprite gUnknown_085927AC, 66, 80, 30, 0, 4, 1, 1, 0
	createsprite gUnknown_085927AC, 0, 128, 12, 0, 3, 3, 0, 0
	createsprite gUnknown_085927C4, 0, 90, 16, 0, 2, 1, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, 0, 1, 0, 7, 0, RGB(13, 31, 12)
	delay 1
	playsewithpan SE_W287, -64
	createvisualtask sub_815DFCC, 2, 1
	waitforvisualfinish
	playsewithpan SE_W234, -64
	createsprite gUnknown_08592B94, 16, -15, 0, 0, 0, 32, 60, 1
	delay 8
	createsprite gUnknown_08592B94, 16, 12, -5, 0, 0, 32, 60, 1
	waitforvisualfinish
	playsewithpan SE_REAPOKE, -64
	createsprite gSimplePaletteBlendSpriteTemplate, 0, 43, 3, 10, 0, RGB(13, 31, 12)
	createsprite gUnknown_08593868, 16, 0, 0, 0, 1
	waitforvisualfinish
	end

Move_FAKE_TEARS:
	loadspritegfx ANIM_TAG_155
	loadspritegfx ANIM_TAG_209
	loadspritegfx ANIM_TAG_072
	createvisualtask sub_8116848, 5, 10155, 0, 4, 4, RGB(12, 11, 31)
	waitforvisualfinish
	createvisualtask sub_815C478, 5, 0, 2, 1
	loopsewithpan SE_W039, -64, 12, 4
	delay 8
	createsprite gUnknown_085970E8, 2, 0, 0
	createsprite gUnknown_085970E8, 2, 0, 1
	delay 8
	createsprite gUnknown_085970E8, 2, 0, 2
	createsprite gUnknown_085970E8, 2, 0, 3
	delay 8
	createsprite gUnknown_085970E8, 2, 0, 0
	createsprite gUnknown_085970E8, 2, 0, 1
	delay 8
	createsprite gUnknown_085970E8, 2, 0, 2
	createsprite gUnknown_085970E8, 2, 0, 3
	waitforvisualfinish
	end

Move_AIR_CUTTER:
	loadspritegfx ANIM_TAG_003
	loadspritegfx ANIM_TAG_138
	loadspritegfx ANIM_TAG_135
	delay 0
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	delay 0
	createvisualtask sub_8103CF0, 2, 32, -24, 1536, 2, 128
	waitforvisualfinish
	playsewithpan SE_W015, +63
	createsprite gUnknown_08592A34, 2, 40, -32, 0, 2
	delay 5
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 2, 0, 8, 1
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	delay 0
	end

Move_ODOR_SLEUTH:
	monbg ANIM_TARGET
	createvisualtask sub_815F620, 5
	delay 24
	createsprite gHorizontalLungeSpriteTemplate, 2, 3, 4
	playsewithpan SE_W207, -64
	delay 6
	createsprite gHorizontalLungeSpriteTemplate, 2, 3, 4
	playsewithpan SE_W207, -64
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	delay 1
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 1, 3, 1, -1, 16, -1, 0
	playsewithpan SE_W043, -64
	end

Move_GRASS_WHISTLE:
	loadspritegfx ANIM_TAG_072
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 0, 4, RGB(18, 31, 12)
	waitforvisualfinish
	createvisualtask sub_8102BE8, 2
	waitforvisualfinish
	panse_1B SE_W320, -64, +63, +2, 0
	createsprite gUnknown_08593008, 130, 7, 1, 0
	delay 5
	createsprite gUnknown_08593008, 130, 6, 1, 0
	delay 5
	createsprite gUnknown_08593008, 130, 1, 1, 0
	delay 5
	createsprite gUnknown_08593008, 130, 2, 1, 0
	delay 5
	createsprite gUnknown_08593008, 130, 3, 1, 0
	delay 4
	createsprite gUnknown_08593008, 130, 2, 1, 0
	delay 4
	createsprite gUnknown_08593008, 130, 5, 1, 0
	delay 4
	createsprite gUnknown_08593008, 130, 6, 1, 0
	delay 4
	createsprite gUnknown_08593008, 130, 2, 1, 0
	delay 4
	createsprite gUnknown_08593008, 130, 2, 1, 0
	delay 4
	createsprite gUnknown_08593008, 130, 1, 1, 0
	delay 4
	createsprite gUnknown_08593008, 130, 5, 1, 0
	delay 4
	waitforvisualfinish
	createvisualtask sub_8102CA0, 2
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 4, 4, 0, RGB(18, 31, 12)
	waitforvisualfinish
	end

Move_TICKLE:
	loadspritegfx 0x27EA
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 2, 0, 0, 16, RGB_BLACK
	waitforvisualfinish
	createsprite gUnknown_08593A84, 0, -16, -8
	createsprite gUnknown_08593A84, 0, 16, -8
	playsewithpan SE_W197, -64
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 2, 0, 16, 0, RGB_BLACK
	waitforvisualfinish
	delay 20
	createvisualtask AnimTask_SwayMon, 3, 0, 6, 1280, 3, ANIM_ATTACKER
	delay 12
	createvisualtask sub_815C478, 3, 1, 6, 2
	loopsewithpan SE_W039, +63, 8, 8
	waitforvisualfinish
	end

Move_WATER_SPOUT:
	loadspritegfx 0x281C
	loadspritegfx 0x27A4
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask sub_81080E4, 5
	playsewithpan SE_W029, -64
	delay 0x2C
	playsewithpan SE_W291, -64
	waitforvisualfinish
	delay 16
	createvisualtask sub_81085C8, 5
	playsewithpan SE_W057, +63
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SHADOW_PUNCH:
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	fadetobg BG_GHOST
	waitbgfadein
	monbg ANIM_ATK_PARTNER
	setalpha 9, 8
	createvisualtask sub_80A8BC4, 2, 0, 13
	playsewithpan SE_W026, -64
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, 131, 0, 0, 1, 1
	createsprite gFistFootSpriteTemplate, 132, 0, 0, 8, 1, 0
	playsewithpan SE_W004, +63
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	restorebg
	waitbgfadein
	end

Move_EXTRASENSORY:
	call SetPsychicBackground
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB(27, 27, 0), 12, 1, 1
	createvisualtask sub_810FE14, 5, 0
	playsewithpan SE_W020, +63
	waitforvisualfinish
	createvisualtask AnimTask_BlendMonInAndOut, 5, ANIM_ATTACKER, RGB(27, 27, 0), 12, 1, 1
	createvisualtask sub_810FE14, 5, 1
	playsewithpan SE_W020, +63
	waitforvisualfinish
	createvisualtask sub_8110034, 5, 0
	createvisualtask sub_810FE14, 5, 2
	playsewithpan SE_W043, -64
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	call UnsetPsychicBackground
	end

Move_AERIAL_ACE:
	loadspritegfx ANIM_TAG_138
	monbg ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 24, 6, 1, 5
	createvisualtask sub_81169C0, 2, 0, 4, 7, 3
	createsprite gCuttingSliceSpriteTemplate, 2, 40, -32, 0
	playsewithpan SE_W013B, -64
	delay 5
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 10, 1
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 31, 3, 1, 0, 10, 0, 0
	playsewithpan SE_W013, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_IRON_DEFENSE:
	loopsewithpan SE_REAPOKE, -64, 0x1C, 2
	createvisualtask sub_81144F8, 5, 0, 0, 0
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 1, 8, 2, -1, 14, -1, 0
	waitforvisualfinish
	end

Move_BLOCK:
	loadspritegfx ANIM_TAG_250
	createsprite gUnknown_085CE90C, 0xC2
	playsewithpan SE_W207, +63
	end

Move_HOWL:
	loadspritegfx 0x2745
	createvisualtask sub_815D64C, 2, 0
	delay 12
	call RoarEffect
	createvisualtask sub_8158D8C, 2, 0, 3
	waitforvisualfinish
	delay 30
	end

Move_BULK_UP:
	loadspritegfx 0x2766
	createvisualtask sub_8104AB4, 2
	playsewithpan SE_W207, -64
	waitforvisualfinish
	createsprite gUnknown_08593658, 2
	loopsewithpan SE_W207, -64, 4, 2
	waitforvisualfinish
	end

Move_COVET:
	loadspritegfx 0x27E2
	loadspritegfx 0x27F0
	createvisualtask sub_815C478, 5, 0, 2, 0
	createsprite gUnknown_08593970, 3, 0, 20
	playsewithpan SE_W204, -64
	delay 15
	createsprite gUnknown_08593970, 3, -20, 20
	playsewithpan SE_W204, -64
	delay 15
	createsprite gUnknown_08593970, 3, 20, 20
	playsewithpan SE_W204, -64
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	loopsewithpan SE_W146, +63, 4, 3
	end

Move_VOLT_TACKLE:
	loadspritegfx ANIM_TAG_001
	loadspritegfx 0x27E4
	loadspritegfx 0x27E5
	monbg ANIM_ATTACKER
	setalpha 12, 8
	createvisualtask sub_8116620, 10, 1, 0, 0, 8, RGB_BLACK
	waitforvisualfinish
	createsprite gUnknown_085959A4, 1
	playsewithpan SE_W268, -64
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	delay 8
	createvisualtask sub_810AFCC, 5, 0
	playsewithpan SE_W085, -64
	waitforvisualfinish
	createvisualtask sub_810AFCC, 5, 1
	playsewithpan SE_W085, +63
	waitforvisualfinish
	createvisualtask sub_810AFCC, 5, 2
	playsewithpan SE_W085, -64
	waitforvisualfinish
	createvisualtask sub_810AFCC, 5, 3
	playsewithpan SE_W085, +63
	waitforvisualfinish
	createvisualtask sub_810AFCC, 5, 4
	playsewithpan SE_W085, -64
	delay 8
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 10, 0, 18, 1
	playsewithpan SE_W120, +63
	createsprite gUnknown_0859598C, 2, 1, 16, 16
	delay 2
	createsprite gUnknown_0859598C, 2, 1, -16, -16
	delay 8
	createvisualtask sub_810AE5C, 5
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 3, 0, 9, 1
	playsewithpan SE_W085B, -64
	createsprite gUnknown_0859598C, 2, 0, 16, 16
	delay 2
	createsprite gUnknown_0859598C, 2, 0, -16, -16
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 1, 0, 8, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_WATER_SPORT:
	loadspritegfx 0x281C
	createvisualtask sub_81088E4, 5
	delay 8
	playsewithpan SE_W057, -64
	delay 0x2C
	playsewithpan SE_W057, -64
	delay 0x2C
	playsewithpan SE_W057, -64
	delay 0x2C
	panse_1B SE_W057, -64, +63, +2, 0
	end

Move_CALM_MIND:
	loadspritegfx ANIM_TAG_203
	monbg ANIM_ATK_PARTNER
	createvisualtask sub_8116664, 5, 0, 0, 0, 16, 0
	waitforvisualfinish
	createvisualtask sub_81177E4, 5, 1
	waitforvisualfinish
	createsprite gUnknown_08593850, 0x28, 0, 0, 0, 0
	playsewithpan SE_W048, -64
	delay 14
	createsprite gUnknown_08593850, 0x28, 0, 0, 0, 0
	playsewithpan SE_W048, -64
	delay 14
	createsprite gUnknown_08593850, 0x28, 0, 0, 0, 0
	playsewithpan SE_W048, -64
	waitforvisualfinish
	createvisualtask sub_81177E4, 5, 0
	waitforvisualfinish
	createvisualtask sub_8116664, 5, 0, 0, 16, 0, 0
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	end

Move_LEAF_BLADE:
	loadspritegfx 0x274F
	loadspritegfx 0x282D
	createvisualtask sub_80FFFC0, 5
	delay 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	playsewithpan SE_W015, +63
	delay 50
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	playsewithpan SE_W015, +63
	delay 50
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	playsewithpan SE_W015, +63
	waitforvisualfinish
	monbg ANIM_TARGET
	setalpha 12, 8
	delay 12
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 8, 0, 18, 1
	createsprite gUnknown_085973D0, 130, 0, 0, 1, 36
	playsewithpan SE_W043, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_DRAGON_DANCE:
	loadspritegfx 0x2809
	monbg ANIM_ATTACKER
	monbgprio_28 ANIM_ATTACKER
	delay 1
	createvisualtask sub_81133E8, 5
	playsewithpan SE_W100, -64
	delay 8
	createvisualtask sub_80A7CB4, 5, 10249, 19456, 14, 0, 3
	createsprite gUnknown_08596F98, 2, 0
	createsprite gUnknown_08596F98, 2, 43
	createsprite gUnknown_08596F98, 2, 85
	createsprite gUnknown_08596F98, 2, 128
	createsprite gUnknown_08596F98, 2, 170
	createsprite gUnknown_08596F98, 2, 213
	delay 30
	playsewithpan SE_W100, -64
	delay 30
	playsewithpan SE_W100, -64
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	delay 1
	end

Move_SHOCK_WAVE:
	loadspritegfx 0x27E3
	loadspritegfx 0x27E4
	loadspritegfx ANIM_TAG_001
	loadspritegfx 0x2735
	monbg ANIM_ATTACKER
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 0, 4, RGB_BLACK
	waitforvisualfinish
	createvisualtask sub_810AAFC, 2, 0, 20, 0, 2
	playsewithpan SE_W268, -64
	delay 12
	createsprite gUnknown_08595A18, 2
	delay 30
	createvisualtask sub_810B29C, 5
	delay 12
	waitforvisualfinish
	createvisualtask sub_810B55C, 5
	playsewithpan SE_W161B, +63
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 6, 18, 1
	createvisualtask sub_8116620, 5, 1, 3, 16, 0, RGB_WHITE
	createvisualtask sub_8116620, 5, 4, 0, 16, 16, RGB_BLACK
	delay 4
	createvisualtask sub_8116620, 5, 4, 0, 0, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	end

Move_HARDEN:
	loopsewithpan SE_W231, -64, 0x1C, 2
	createvisualtask sub_81144F8, 5, 0, 0, 0
	waitforvisualfinish
	end

Move_BELLY_DRUM:
	loadspritegfx ANIM_TAG_072
	loadspritegfx 0x27D1
	createvisualtask sub_8102BE8, 2
	waitforvisualfinish
	call BellyDrum1
	createsprite gUnknown_0859309C, 2, 0, 0, 0, 0
	playsewithpan SE_W187, -64
	delay 15
	call BellyDrum2
	createsprite gUnknown_0859309C, 2, 1, 1, 1, 0
	playsewithpan SE_W187, -64
	delay 15
	call BellyDrum1
	createsprite gUnknown_0859309C, 2, 0, 3, 3, 128
	playsewithpan SE_W187, -64
	delay 7
	call BellyDrum2
	createsprite gUnknown_0859309C, 2, 1, 2, 0, 128
	playsewithpan SE_W187, -64
	delay 7
	call BellyDrum1
	createsprite gUnknown_0859309C, 2, 0, 1, 1, 0
	playsewithpan SE_W187, -64
	delay 7
	call BellyDrum2
	createsprite gUnknown_0859309C, 2, 1, 0, 3, 0
	playsewithpan SE_W187, -64
	waitforvisualfinish
	createvisualtask sub_8102CA0, 2
	waitforvisualfinish
	end

BellyDrum2:
	createsprite gUnknown_08593068, 3, 0
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATTACKER, 0, 8, 2, 1
	return

BellyDrum1:
	createsprite gUnknown_08593068, 3, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATTACKER, 0, 8, 2, 1
	return

Move_MIND_READER:
	loadspritegfx 0x27CD
	loadspritegfx 0x27CE
	loadspritegfx 0x27CF
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W109, +63
	createsprite gUnknown_085CE07C, 5, 0, 0, 1, 0
	createsprite gUnknown_085CE094, 5
	delay 0x28
	playsewithpan SE_W043, +63
	createvisualtask sub_8115A04, 2, 1, 1, 2, 0, 10, RGB_BLACK
	call MindReaderEffect
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

MindReaderEffect:
	createsprite gUnknown_085CE0AC, 4, 70, 0, 6
	createsprite gUnknown_085CE0AC, 4, 40, 40, 6
	createsprite gUnknown_085CE0AC, 4, 10, -60, 6
	createsprite gUnknown_085CE0AC, 4, -50, -40, 6
	createsprite gUnknown_085CE0AC, 4, -40, 40, 6
	createsprite gUnknown_085CE0AC, 4, 50, -50, 6
	delay 2
	createsprite gUnknown_085CE0AC, 4, 50, -30, 6
	createsprite gUnknown_085CE0AC, 4, 60, 10, 6
	createsprite gUnknown_085CE0AC, 4, 0, 60, 6
	createsprite gUnknown_085CE0AC, 4, 0, -40, 6
	createsprite gUnknown_085CE0AC, 4, -60, 20, 6
	createsprite gUnknown_085CE0AC, 4, -60, -30, 6
	delay 2
	createsprite gUnknown_085CE0AC, 4, -50, 50, 6
	createsprite gUnknown_085CE0AC, 4, -60, 20, 6
	createsprite gUnknown_085CE0AC, 4, -40, -40, 6
	createsprite gUnknown_085CE0AC, 4, 20, -60, 6
	createsprite gUnknown_085CE0AC, 4, 50, -50, 6
	createsprite gUnknown_085CE0AC, 4, 35, 40, 6
	delay 2
	return

Move_ICE_PUNCH:
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	loadspritegfx ANIM_TAG_141
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 0, 7, RGB_BLACK
	createvisualtask sub_8116620, 10, 4, 2, 0, 9, RGB(12, 26, 31)
	delay 20
	playsewithpan SE_W081, +63
	createsprite gUnknown_08595AE8, 2, 0
	createsprite gUnknown_08595AE8, 2, 64
	createsprite gUnknown_08595AE8, 2, 128
	createsprite gUnknown_08595AE8, 2, 192
	delay 5
	createsprite gUnknown_08595AD0, 2, 32
	createsprite gUnknown_08595AD0, 2, 96
	createsprite gUnknown_08595AD0, 2, 160
	createsprite gUnknown_08595AD0, 2, 224
	delay 17
	createsprite gFistFootSpriteTemplate, 4, 0, -10, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, -10, 1, 1
	playsewithpan SE_W004, +63
	delay 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 5, 3, 1
	waitforvisualfinish
	delay 15
	call FreezeEffect1
	delay 5
	createvisualtask sub_8116620, 10, 4, 2, 9, 0, RGB(12, 26, 31)
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 0, 7, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_REST:
	playsewithpan SE_W173, -64
	loadspritegfx 0x27F4
	createsprite gUnknown_08592C88, 2, 4, -10, 16, 0, 0
	delay 20
	createsprite gUnknown_08592C88, 2, 4, -10, 16, 0, 0
	delay 20
	createsprite gUnknown_08592C88, 2, 4, -10, 16, 0, 0
	waitforvisualfinish
	end

Move_CONFUSION:
	monbg ANIM_DEF_PARTNER
	call SetPsychicBackground
	setalpha 8, 8
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 10, 1
	createvisualtask sub_8115A04, 2, 2, 0, 2, 0, 8, RGB_WHITE
	waitforvisualfinish
	playsewithpan SE_W048, +63
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 15, 1
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -4, -4, 15, ANIM_TARGET, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	delay 1
	call UnsetPsychicBackground
	end

Move_PSYCHIC:
	monbg ANIM_DEF_PARTNER
	call SetPsychicBackground
	setalpha 8, 8
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 10, 1
	createvisualtask sub_8115A04, 2, 2, 0, 2, 0, 8, RGB(31, 23, 0)
	waitforvisualfinish
	loopsewithpan SE_W048, +63, 10, 3
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 15, 1
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -6, -6, 15, ANIM_TARGET, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	delay 1
	call UnsetPsychicBackground
	end

Move_FUTURE_SIGHT:
	goto FutureSight
FutureSightContinue:
	waitforvisualfinish
	delay 1
	call UnsetPsychicBackground
	end
FutureSight:
	monbg ANIM_ATK_PARTNER
	playsewithpan SE_W060, -64
	call SetPsychicBackground
	setalpha 8, 8
	playsewithpan SE_W048, -64
	createvisualtask sub_8115A04, 2, 2, 0, 2, 0, 8, RGB_WHITE
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -4, -4, 15, ANIM_ATTACKER, 1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	goto FutureSightContinue

Move_THUNDER:
	loadspritegfx 0x2735
	fadetobg BG_THUNDER
	waitbgfadeout
	createvisualtask sub_8117660, 5, -256, 0, 1, -1
	waitbgfadein
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 0, 16, RGB_BLACK
	delay 16
	createvisualtask sub_8115F10, 2, 257, 257, 257
	playsewithpan SE_W086, +63
	delay 1
	createsprite gUnknown_085956C0, 130, 16, -36
	delay 1
	createsprite gUnknown_085956C0, 130, 16, -20
	delay 1
	createsprite gUnknown_085956C0, 130, 16, 12
	delay 20
	createsprite gUnknown_085956C0, 0x86, -16, -32
	playsewithpan SE_W086, +63
	delay 1
	createsprite gUnknown_085956C0, 0x86, -16, -16
	delay 1
	createsprite gUnknown_085956C0, 0x86, -16, 16
	playsewithpan SE_W086, +63
	delay 5
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	createsprite gUnknown_085956C0, 130, 24, -32
	delay 1
	createsprite gUnknown_085956C0, 130, 24, -16
	delay 1
	createsprite gUnknown_085956C0, 130, 24, 16
	delay 30
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 5
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	createsprite gUnknown_085956C0, 130, 0, -32
	playsewithpan SE_W161B, +63
	delay 1
	createsprite gUnknown_085956C0, 130, 0, -16
	delay 1
	createsprite gUnknown_085956C0, 130, 0, 16
	delay 10
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	createvisualtask sub_810A094, 2, 30, 3, 1, 0
	delay 2
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, 130, 1, 2, 16, 0, RGB_BLACK
	waitforvisualfinish
	restorebg
	waitbgfadeout
	setarg 7, 0xFFFF
	waitbgfadein
	end

Move_THUNDER_PUNCH:
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	loadspritegfx 0x2735
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 0, 16, RGB_BLACK
	waitforvisualfinish
	playsewithpan SE_W004, +63
	createsprite gFistFootSpriteTemplate, 132, 0, 0, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, 131, 0, 0, 1, 1
	delay 1
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	createsprite gUnknown_085956C0, 130, 0, -48
	delay 1
	createsprite gUnknown_085956C0, 2, 0, -16
	delay 1
	createsprite gUnknown_085956C0, 2, 0, 16
	delay 1
	playsewithpan SE_W161B, +63
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 15, 1
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 2
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 16, 0, RGB_BLACK
	delay 20
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SACRED_FIRE:
	loadspritegfx 0x2731
	loadspritegfx ANIM_TAG_035
	loopsewithpan SE_W221, -64, 7, 5
	createsprite gUnknown_08595428, 2, -32, 0, 50, 5, -2, 0
	delay 1
	createsprite gUnknown_08595428, 66, -20, -10, 50, 5, -1, -1
	delay 1
	createsprite gUnknown_08595428, 66, 0, -16, 50, 5, 0, -1
	delay 1
	createsprite gUnknown_08595428, 66, 20, -10, 50, 5, 1, -1
	delay 1
	createsprite gUnknown_08595428, 2, 32, 0, 50, 5, 2, 0
	delay 1
	createsprite gUnknown_08595428, 2, 20, 10, 50, 5, 1, 1
	delay 1
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	createsprite gUnknown_08595428, 2, 0, 16, 50, 5, 0, 1
	delay 1
	createsprite gUnknown_08595428, 2, -20, 10, 50, 5, -1, 1
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	waitforvisualfinish
	playsewithpan SE_W221B, +63
	createsprite gUnknown_085953F8, 130, -16, 0, 70, 16, 0, 1
	delay 10
	playsewithpan SE_W221B, +63
	createsprite gUnknown_085953F8, 130, 0, 0, 70, 16, 0, 1
	delay 10
	playsewithpan SE_W221B, +63
	createsprite gUnknown_085953F8, 130, 16, 0, 80, 16, 0, 1
	delay 1
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	waitforvisualfinish
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 1
	playsewithpan SE_W172B, +63
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, -1, 0
	delay 1
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, 0, 1
	delay 1
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, -1, -1
	delay 1
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, 2, 1
	delay 1
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, 1, -1
	delay 1
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, -1, 1
	delay 1
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, 1, -2
	delay 1
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, 3, 1
	waitforvisualfinish
	end

Move_SCRATCH:
	loadspritegfx 0x2799
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W010, +63
	createsprite gUnknown_085CE020, 2, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end

Move_DRAGON_BREATH:
	loadspritegfx 0x272D
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	loopsewithpan SE_W172, -64, 7, 7
	createsprite gUnknown_08596EF4, 130, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, 130, 0, 0, 0, 0, 20
	delay 2
	createvisualtask sub_8116620, 10, 4, 1, 0, 9, RGB_RED
	createsprite gUnknown_08596EF4, 130, 0, 0, 0, 0, 20
	delay 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 21, 1
	createsprite gUnknown_08596EF4, 130, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, 130, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, 130, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, 130, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, 130, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, 130, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, 130, 0, 0, 0, 0, 20
	delay 2
	createsprite gUnknown_08596EF4, 130, 0, 0, 0, 0, 20
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 4, 1, 9, 0, RGB_RED
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_ROAR:
	loadspritegfx 0x2745
	monbg ANIM_ATTACKER
	monbgprio_28 ANIM_ATTACKER
	setalpha 8, 8
	createvisualtask sub_8158E9C, 2, 0, 2
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -5, -5, 10, ANIM_ATTACKER, 1
	call RoarEffect
	delay 20
	createvisualtask sub_80D5DB0, 5, 1, 2
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	waitforvisualfinish
	createvisualtask sub_8159078, 5
	waitforvisualfinish
	end

RoarEffect:
	createsprite gUnknown_085CE7D4, 2, 24, -8, 0
	createsprite gUnknown_085CE7D4, 2, 24, 0, 2
	createsprite gUnknown_085CE7D4, 2, 24, 8, 1
	delay 15
	createsprite gUnknown_085CE7D4, 2, 24, -8, 0
	createsprite gUnknown_085CE7D4, 2, 24, 0, 2
	createsprite gUnknown_085CE7D4, 2, 24, 8, 1
	return

Move_GROWL:
	loadspritegfx 0x2745
	createvisualtask sub_8158E9C, 2, 0, 255
	call RoarEffect
	delay 10
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 9, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 1, 0, 9, 1
	waitforvisualfinish
	createvisualtask sub_8159078, 5
	waitforvisualfinish
	end

Move_SNORE:
	loadspritegfx 0x27D5
	monbg ANIM_ATK_PARTNER
	setalpha 8, 8
	call Snore1
	delay 30
	call Snore1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end
Snore1:
	playsewithpan SE_W173, -64
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -7, -7, 7, ANIM_ATTACKER, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 7, 1
	createsprite gBattleAnimSpriteTemplate_85972D8, 2, 6, 1, 14, 0, 0
	createsprite gUnknown_085936EC, 2, 0, 0, -42, -38, 24, 0, 0
	createsprite gUnknown_085936EC, 2, 0, 0, 0, -42, 24, 0, 0
	createsprite gUnknown_085936EC, 2, 0, 0, 42, -38, 24, 0, 0
	return

Move_LIGHT_SCREEN:
	loadspritegfx 0x2756
	loadspritegfx 0x27B6
	setalpha 0, 16
	waitplaysewithpan SE_W115, -64, 15
	createsprite gUnknown_08596560, 1, 40, 0, 10166
	delay 10
	call SpecialScreenEffect
	waitforvisualfinish
	delay 1
	blendoff
	end

SpecialScreenEffect:
	createsprite gUnknown_08596624, 2, 23, 0, 0, 1
	delay 6
	createsprite gUnknown_08596624, 2, 31, -8, 0, 1
	delay 5
	createsprite gUnknown_08596624, 2, 30, 20, 0, 1
	delay 7
	createsprite gUnknown_08596624, 2, 10, -15, 0, 1
	delay 6
	createsprite gUnknown_08596624, 2, 20, 10, 0, 1
	delay 6
	createsprite gUnknown_08596624, 2, 10, 18, 0, 1
	return

Move_MIRROR_COAT:
	loadspritegfx 0x2756
	loadspritegfx 0x27B8
	setalpha 0, 16
	createsprite gUnknown_08596590, 1, 40, 0, 10168
	delay 10
	playsewithpan SE_W115, -64
	call SpecialScreenEffect
	waitforvisualfinish
	delay 1
	blendoff
	end

Move_REFLECT:
	loadspritegfx 0x2757
	loadspritegfx ANIM_TAG_167
	setalpha 0, 16
	waitplaysewithpan SE_W115, -64, 15
	createsprite gUnknown_08596578, 1, 40, 0, 10167
	delay 20
	createsprite gUnknown_085965F4, 2, 30, 0, 0, 1
	delay 7
	createsprite gUnknown_085965F4, 2, 19, -12, 0, 1
	delay 7
	createsprite gUnknown_085965F4, 2, 10, 20, 0, 1
	waitforvisualfinish
	delay 1
	blendoff
	end

Move_BARRIER:
	loadspritegfx 0x27B9
	setalpha 0, 16
	waitplaysewithpan SE_W112, -64, 15
	createsprite gUnknown_085965A8, 3, 40, 0, 10169
	waitforvisualfinish
	delay 1
	blendoff
	end

Move_BUBBLE:
	loadspritegfx 0x27A2
	loadspritegfx ANIM_TAG_155
	monbg ANIM_TARGET
	setalpha 12, 8
	delay 1
	createsprite gBattleAnimSpriteTemplate_8595068, 2, 18, 0, 15, -15, 10, 128, 100
	playsewithpan SE_W145, -64
	waitplaysewithpan SE_W145B, +63, 0x64
	delay 6
	createsprite gBattleAnimSpriteTemplate_8595068, 2, 18, 0, 35, 37, 40, 128, 100
	playsewithpan SE_W145, -64
	waitplaysewithpan SE_W145B, +63, 0x64
	delay 6
	createsprite gBattleAnimSpriteTemplate_8595068, 2, 18, 0, 10, -37, 30, 128, 100
	playsewithpan SE_W145, -64
	waitplaysewithpan SE_W145B, +63, 0x64
	delay 6
	createsprite gBattleAnimSpriteTemplate_8595068, 2, 18, 0, 30, 10, 15, 128, 100
	playsewithpan SE_W145, -64
	waitplaysewithpan SE_W145B, +63, 0x64
	delay 6
	createsprite gBattleAnimSpriteTemplate_8595068, 2, 18, 0, 20, 33, 20, 128, 100
	playsewithpan SE_W145, -64
	waitplaysewithpan SE_W145B, +63, 0x64
	delay 6
	createsprite gBattleAnimSpriteTemplate_8595068, 2, 18, 0, 25, -30, 10, 128, 100
	playsewithpan SE_W145, -64
	waitplaysewithpan SE_W145B, +63, 0x64
	waitforvisualfinish
	call WaterBubbleEffect2
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_SMOG:
	loadspritegfx 0x27BC
	monbg ANIM_DEF_PARTNER
	monbgprio_29
	setalpha 12, 8
	loopsewithpan SE_W054, +63, 17, 10
	call Smog1
	call Smog1
	call Smog1
	call Smog1
	call Smog1
	call Smog1
	call Smog1
	delay 120
	loopsewithpan SE_W092, +63, 0x12, 2
	createvisualtask sub_8115A04, 2, 4, 2, 2, 0, 12, RGB(26, 0, 26)
	delay 10
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 15, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Smog1:
	createsprite gUnknown_08595C44, 2, 0, -24, 48, 240, 1, 0
	delay 7
	return

Move_FAINT_ATTACK:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_ATTACKER
	fadetobg BG_DARK
	waitbgfadein
	delay 0
	playsewithpan SE_W185, -64
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 18, 6, 1, 3
	createvisualtask sub_81136E8, 2, 1
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	invisible ANIM_ATTACKER
	delay 1
	createvisualtask sub_8117F60, 2
	setalpha 12, 8
	monbg ANIM_TARGET
	delay 1
	playsewithpan SE_W233B, +63
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 9, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 1
	setarg 7, 0x1000
	delay 0x20
	createvisualtask sub_8113888, 2
	monbg ANIM_ATTACKER
	createvisualtask sub_81137E4, 2, 1
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	delay 1
	restorebg
	waitbgfadein
	end

Move_SAND_ATTACK:
	loadspritegfx ANIM_TAG_074
	monbg ANIM_ATK_PARTNER
	monbgprio_28 ANIM_ATTACKER
	setalpha 12, 8
	playsewithpan SE_W028, -64
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, -10, 0, 0, 3
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 2
	call SandAttack1
	call SandAttack1
	call SandAttack1
	call SandAttack1
	call SandAttack1
	call SandAttack1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

SandAttack1:
	createsprite gUnknown_085971A8, 130, 15, 15, 20, 0, 0
	createsprite gUnknown_085971A8, 130, 15, 15, 20, 10, 10
	createsprite gUnknown_085971A8, 130, 15, 15, 20, -10, -10
	createsprite gUnknown_085971A8, 130, 15, 15, 20, 20, 5
	createsprite gUnknown_085971A8, 130, 15, 15, 20, -20, -5
	delay 2
	return

Move_MUD_SLAP:
	loadspritegfx ANIM_TAG_074
	playsewithpan SE_W028, -64
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, -10, 0, 0, 3
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 2
	call MudSlap1
	call MudSlap1
	call MudSlap1
	call MudSlap1
	call MudSlap1
	call MudSlap1
	waitforvisualfinish
	end

MudSlap1:
	createsprite gUnknown_085971CC, 130, 15, 15, 20, 0, 0
	createsprite gUnknown_085971CC, 130, 15, 15, 20, 10, 5
	createsprite gUnknown_085971CC, 130, 15, 15, 20, -10, -5
	createsprite gUnknown_085971CC, 130, 15, 15, 20, 20, 10
	createsprite gUnknown_085971CC, 130, 15, 15, 20, -20, -10
	delay 2
	return

Move_DRAGON_RAGE:
	loadspritegfx 0x272D
	loadspritegfx ANIM_TAG_035
	playsewithpan SE_W082, -64
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 0, 2, 40, 1
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, 130, 0, 15, 0, 0, 4
	waitforvisualfinish
	createsprite gUnknown_08596F80, 130, 30, 15, 0, 10, 10
	waitforvisualfinish
	loopsewithpan SE_W172B, +63, 11, 3
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 3, 25, 1
	createsprite gUnknown_08596F28, 0xC2, 1, 5, 0
	delay 1
	createsprite gUnknown_08596F28, 0xC2, 1, -10, -15
	delay 1
	createsprite gUnknown_08596F28, 130, 1, 0, 25
	delay 1
	createsprite gUnknown_08596F28, 0xC2, 1, 15, 5
	delay 1
	createsprite gUnknown_08596F28, 0xC2, 1, -25, 0
	delay 1
	createsprite gUnknown_08596F28, 130, 1, 30, 30
	delay 1
	createsprite gUnknown_08596F28, 130, 1, -27, 25
	delay 1
	createsprite gUnknown_08596F28, 0xC2, 1, 0, 8
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, 0xC2, 0, 0, 4
	waitforvisualfinish
	end

Move_RAIN_DANCE:
	loadspritegfx 0x2783
	playsewithpan SE_W240, -64
	createvisualtask sub_8116620, 10, 0x781, 2, 0, 4, RGB_BLACK
	waitforvisualfinish
	createvisualtask AnimTask_CreateRaindrops, 2, 0, 3, 120
	createvisualtask AnimTask_CreateRaindrops, 2, 0, 3, 120
	delay 120
	delay 30
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 0x781, 2, 4, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_BITE:
	loadspritegfx 0x279B
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W044, +63
	createsprite gUnknown_08597080, 2, 0, -32, 0, 0, 819, 10
	createsprite gUnknown_08597080, 2, 0, 32, 4, 0, -819, 10
	delay 10
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 4, 7, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 1
	end

Move_CRUNCH:
	loadspritegfx 0x279B
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	fadetobg BG_DARK
	waitbgfadein
	setalpha 12, 8
	playsewithpan SE_W044, +63
	createsprite gUnknown_08597080, 2, -32, -32, 1, 819, 819, 10
	createsprite gUnknown_08597080, 2, 32, 32, 5, -819, -819, 10
	delay 10
	createsprite gBasicHitSplatSpriteTemplate, 2, -8, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 7, 5, 2
	waitforvisualfinish
	playsewithpan SE_W044, +63
	createsprite gUnknown_08597080, 2, 32, -32, 7, -819, 819, 10
	createsprite gUnknown_08597080, 2, -32, 32, 3, 819, -819, 10
	delay 10
	createsprite gBasicHitSplatSpriteTemplate, 2, 8, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 8, 4, 2
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	delay 1
	restorebg
	waitbgfadein
	end

Move_CLAMP:
	loadspritegfx 0x27A1
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W011, +63
	createsprite gUnknown_08597098, 2, -32, 0, 2, 819, 0, 10
	createsprite gUnknown_08597098, 2, 32, 0, 6, -819, 0, 10
	delay 10
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 5, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end

Move_ICE_BEAM:
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	loadspritegfx ANIM_TAG_141
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 0, 7, RGB_BLACK
	waitforvisualfinish
	createsoundtask sub_8158C58, 183, -64, 63, 4, 4, 0, 10
	createsprite gUnknown_08595B2C, 2, 20, 12, 0, 12, 20
	createsprite gUnknown_08595B2C, 2, 20, -12, 0, -12, 20
	delay 1
	call IceBeam1
	call IceBeam1
	call IceBeam1
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 4, -31, 0, 7, RGB(0, 20, 31)
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 25, 1
	call IceBeam1
	call IceBeam1
	call IceBeam1
	call IceBeam1
	call IceBeam1
	call IceBeam1
	call IceBeam1
	call IceBeam1
	createsprite gUnknown_08595B14, 2, 20, 0, 0, 0, 11
	delay 1
	createsprite gUnknown_08595B14, 2, 20, 0, 0, 0, 11
	waitforvisualfinish
	delay 20
	call FreezeEffect1
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 4, 5, 7, 0, RGB(0, 20, 31)
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 0, 7, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

IceBeam1:
	createsprite gUnknown_08595B2C, 2, 20, 12, 0, 12, 20
	createsprite gUnknown_08595B2C, 2, 20, -12, 0, -12, 20
	createsprite gUnknown_08595B14, 2, 20, 0, 0, 0, 11
	delay 1
	return

Move_WITHDRAW:
	playsewithpan SE_W029, -64
	createvisualtask sub_81036A0, 5
	waitforvisualfinish
	end

Move_AURORA_BEAM:
	loadspritegfx 0x279C
	fadetobg BG_AURORABEAM
	waitbgfadein
	playsewithpan SE_W062, -64
	setarg 7, 0
	createvisualtask sub_8107528, 10, 130
	call AuroraBeam1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 1, 0, 17, 1
	call AuroraBeam1
	call AuroraBeam1
	call AuroraBeam1
	setarg 7, 0xFFFF
	createsoundtask sub_8158C58, 183, -64, 63, 3, 6, 0, 10
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 2, 0, 40, 1
	call AuroraBeam1
	call AuroraBeam1
	call AuroraBeam1
	call AuroraBeam1
	call AuroraBeam1
	call AuroraBeam1
	waitforvisualfinish
	restorebg
	waitbgfadein
	end

AuroraBeam1:
	createsprite gUnknown_085950B4, 130, 20, 0, 0, 0, 17
	delay 1
	createsprite gUnknown_085950B4, 130, 20, 0, 0, 0, 17
	delay 1
	createsprite gUnknown_085950B4, 130, 20, 0, 0, 0, 17
	delay 1
	createsprite gUnknown_085950B4, 130, 20, 0, 0, 0, 17
	delay 1
	return

Move_SOLAR_BEAM:
	loadspritegfx 0x27A3
	choosetwoturnanim SolarBeamSetUp, SolarBeamUnleash
SolarBeamEnd:
	waitforvisualfinish
	end

SolarBeamSetUp:
	monbg ANIM_ATK_PARTNER
	setalpha 12, 8
	createvisualtask sub_8115A04, 2, 2, 1, 4, 0, 11, RGB(31, 31, 11)
	playsewithpan SE_W025, -64
	call SolarBeamSetUp1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	goto SolarBeamEnd

SolarBeamSetUp1:
	createsprite gUnknown_085921E0, 2, 40, 40, 16
	delay 2
	createsprite gUnknown_085921E0, 2, -40, -40, 16
	delay 2
	createsprite gUnknown_085921E0, 2, 0, 40, 16
	delay 2
	createsprite gUnknown_085921E0, 2, 0, -40, 16
	delay 2
	createsprite gUnknown_085921E0, 2, 40, -20, 16
	delay 2
	createsprite gUnknown_085921E0, 2, 40, 20, 16
	delay 2
	createsprite gUnknown_085921E0, 2, -40, -20, 16
	delay 2
	createsprite gUnknown_085921E0, 2, -40, 20, 16
	delay 2
	createsprite gUnknown_085921E0, 2, -20, 30, 16
	delay 2
	createsprite gUnknown_085921E0, 2, 20, -30, 16
	delay 2
	createsprite gUnknown_085921E0, 2, -20, -30, 16
	delay 2
	createsprite gUnknown_085921E0, 2, 20, 30, 16
	delay 2
	createsprite gUnknown_085921E0, 2, -40, 0, 16
	delay 2
	createsprite gUnknown_085921E0, 2, 40, 0, 16
	delay 2
	return

SolarBeamUnleash:
	call SetSolarbeamBg
	panse_1B SE_W076, -64, +63, +2, 0
	createvisualtask sub_80FEA58, 5
	createsprite gUnknown_085921F8, 131, 15, 0, 20, 0
	delay 4
	createsprite gUnknown_085921F8, 131, 15, 0, 20, 1
	delay 4
	createvisualtask sub_8116620, 10, 4, 1, 0, 10, RGB(25, 31, 0)
	createsprite gUnknown_085921F8, 131, 15, 0, 20, 2
	delay 4
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 2, 0, 65, 1
	createsprite gUnknown_085921F8, 131, 15, 0, 20, 3
	delay 4
	createsprite gUnknown_085921F8, 131, 15, 0, 20, 4
	delay 4
	createsprite gUnknown_085921F8, 131, 15, 0, 20, 5
	delay 4
	createsprite gUnknown_085921F8, 131, 15, 0, 20, 6
	delay 4
	call SolarBeamUnleash1
	call SolarBeamUnleash1
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 4, 1, 10, 0, RGB(25, 31, 0)
	call UnsetSolarbeamBg
	goto SolarBeamEnd

SolarBeamUnleash1:
	createsprite gUnknown_085921F8, 131, 15, 0, 20, 0
	delay 4
	createsprite gUnknown_085921F8, 131, 15, 0, 20, 1
	delay 4
	createsprite gUnknown_085921F8, 131, 15, 0, 20, 2
	delay 4
	createsprite gUnknown_085921F8, 131, 15, 0, 20, 3
	delay 4
	createsprite gUnknown_085921F8, 131, 15, 0, 20, 4
	delay 4
	createsprite gUnknown_085921F8, 131, 15, 0, 20, 5
	delay 4
	createsprite gUnknown_085921F8, 131, 15, 0, 20, 6
	delay 4
	return

Move_BLIZZARD:
	loadspritegfx ANIM_TAG_141
	monbg ANIM_DEF_PARTNER
	createvisualtask AnimTask_IsAttackerOpponentSide, 2
	jumprettrue BlizzardAgainstPlayer
	fadetobg BG_HIGHSPEED_OPPONENT
BlizzardContinue:
	waitbgfadeout
	createvisualtask sub_8117660, 5, -2304, 0, 1, -1
	waitbgfadein
	waitforvisualfinish
	panse_1B SE_W059, -64, +63, +2, 0
	call Blizzard1
	call Blizzard1
	playsewithpan SE_W059B, +63
	waitforvisualfinish
	call FreezeEffect2
	waitforvisualfinish
	delay 20
	restorebg
	waitbgfadeout
	setarg 7, 0xFFFF
	waitbgfadein
	clearmonbg ANIM_DEF_PARTNER
	end

Blizzard1:
	createsprite gUnknown_08595B98, 0x28, 0, -10, 0, -10, 72, 1
	createsprite gUnknown_08595BB0, 0x28, 0, 0, 0, 0, 80, 0, 0, 1
	delay 3
	createsprite gUnknown_08595B98, 0x28, 0, -15, 0, -15, 72, 1
	createsprite gUnknown_08595BB0, 0x28, 0, -10, 0, -10, 80, 0, 0, 1
	delay 3
	createsprite gUnknown_08595B98, 0x28, 0, -5, 0, -5, 72, 1
	createsprite gUnknown_08595BB0, 0x28, 0, 10, 0, 10, 80, 0, 0, 1
	delay 3
	createsprite gUnknown_08595B98, 0x28, 0, -10, 0, -10, 72, 1
	createsprite gUnknown_08595BB0, 0x28, 0, -20, 0, -20, 80, 0, 0, 1
	delay 3
	createsprite gUnknown_08595B98, 0x28, 0, -20, 0, -20, 72, 1
	createsprite gUnknown_08595BB0, 0x28, 0, 15, 0, 15, 80, 0, 0, 1
	delay 3
	createsprite gUnknown_08595B98, 0x28, 0, -15, 0, -15, 72, 1
	createsprite gUnknown_08595BB0, 0x28, 0, -20, 0, -20, 80, 0, 0, 1
	delay 3
	createsprite gUnknown_08595B98, 0x28, 0, -25, 0, -25, 72, 1
	createsprite gUnknown_08595BB0, 0x28, 0, 20, 0, 20, 80, 0, 0, 1
	delay 3
	return

BlizzardAgainstPlayer:
	fadetobg BG_HIGHSPEED_PLAYER
	goto BlizzardContinue

Move_POWDER_SNOW:
	loadspritegfx ANIM_TAG_141
	monbg ANIM_DEF_PARTNER
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 31, 1, 0, 3, RGB_BLACK
	waitforvisualfinish
	panse_1B SE_W016, -64, +63, +2, 0
	call PowderSnow1
	call PowderSnow1
	playsewithpan SE_W016B, +63
	waitforvisualfinish
	waitsound
	call FreezeEffect2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	delay 20
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 31, 1, 3, 0, RGB_BLACK
	end

PowderSnow1:
	createsprite gUnknown_08595BC8, 0x28, 0, 0, 0, 0, 56, 4, 4, 1
	delay 3
	createsprite gUnknown_08595BC8, 0x28, 0, -10, 0, -10, 56, 4, 4, 1
	delay 3
	createsprite gUnknown_08595BC8, 0x28, 0, 10, 0, 10, 56, -4, 3, 1
	delay 3
	createsprite gUnknown_08595BC8, 0x28, 0, -20, 0, -20, 56, -4, 5, 1
	delay 3
	createsprite gUnknown_08595BC8, 0x28, 0, 15, 0, 15, 56, 4, 4, 1
	delay 3
	createsprite gUnknown_08595BC8, 0x28, 0, -20, 0, -20, 56, 4, 4, 1
	delay 3
	createsprite gUnknown_08595BC8, 0x28, 0, 20, 0, 20, 56, 4, 4, 1
	delay 3
	return

Move_HYDRO_PUMP:
	loadspritegfx 0x27A5
	loadspritegfx 0x27A4
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 0, 2, 40, 1
	delay 6
	panse_1B SE_W056, -64, +63, +2, 0
	createvisualtask sub_81076C8, 5, 100
	call HydroPump1
	call HydroPump1
	call HydroPump1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 37, 1
	call HydroPump2
	call HydroPump1
	call HydroPump1
	call HydroPump2
	call HydroPump1
	call HydroPump1
	call HydroPump2
	call HydroPump1
	call HydroPump1
	call HydroPump2
	call HydroPump1
	call HydroPump1
	call HydroPump2
	delay 1
	delay 1
	call HydroPump2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

HydroPump1:
	createsprite gUnknown_085950E4, 3, 10, 10, 0, 16
	createsprite gUnknown_085950E4, 3, 10, 10, 0, -16
	delay 1
	createsprite gUnknown_085950E4, 3, 10, 10, 0, 16
	createsprite gUnknown_085950E4, 3, 10, 10, 0, -16
	delay 1
	return

HydroPump2:
	createsprite gUnknown_08597388, 4, 0, 15, 1, 1
	createsprite gUnknown_08597388, 4, 0, -15, 1, 1
	return

Move_SIGNAL_BEAM:
	loadspritegfx 0x2818
	loadspritegfx 0x2819
	loadspritegfx ANIM_TAG_073
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 0, 2, 25, 1
	delay 6
	panse_1B SE_W062, -64, +63, +1, 0
	createvisualtask sub_81076C8, 5, 100
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 25, 1
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 4, 8, 5, 31, 8, 961, 8
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	call SignalBeam1
	waitforvisualfinish
	end

SignalBeam1:
	createsprite gUnknown_08595114, 131, 10, 10, 0, 16
	createsprite gUnknown_0859512C, 131, 10, 10, 0, -16
	delay 1
	return

Move_ABSORB:
	loadspritegfx 0x27A3
	loadspritegfx ANIM_TAG_031
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 0, 4, RGB(13, 31, 12)
	waitforvisualfinish
	playsewithpan SE_W071, +63
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
	delay 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 5, 5, 1
	waitforvisualfinish
	delay 3
	call AbsorbEffect
	waitforvisualfinish
	delay 15
	call HealingEffect
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 4, 0, RGB(13, 31, 12)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

AbsorbEffect:
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	delay 4
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 3, 10, -5, -8, 26
	delay 4
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 3, -5, 15, 16, 33
	delay 4
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 3, 0, -15, -16, 36
	delay 4
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	delay 4
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 3, 10, -5, -8, 26
	delay 4
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 3, -10, 20, 20, 39
	delay 4
	playsewithpan SE_W152, +63
	createsprite gUnknown_08592270, 3, 5, -18, -20, 35
	delay 4
	return

Move_MEGA_DRAIN:
	loadspritegfx 0x27A3
	loadspritegfx ANIM_TAG_031
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 0, 8, RGB(13, 31, 12)
	waitforvisualfinish
	playsewithpan SE_W071, +63
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 1
	delay 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 5, 5, 1
	waitforvisualfinish
	delay 3
	call MegaDrainEffect
	waitforvisualfinish
	delay 15
	call HealingEffect
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 8, 0, RGB(13, 31, 12)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

MegaDrainEffect:
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 3, 5, -18, -20, 35
	delay 4
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 3, -10, 20, 20, 39
	delay 4
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 3, -5, 15, 16, 33
	createsprite gUnknown_08592270, 3, 10, -5, -8, 26
	delay 4
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 3, 0, -15, -16, 36
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	delay 4
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 3, 0, -15, -16, 36
	delay 4
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 3, -5, 15, 16, 33
	delay 4
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 3, -10, 20, 20, 39
	createsprite gUnknown_08592270, 3, 10, -5, -8, 26
	delay 4
	playsewithpan SE_W145C, +63
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 3, 5, -18, -20, 35
	delay 4
	return

Move_GIGA_DRAIN:
	loadspritegfx 0x27A3
	loadspritegfx ANIM_TAG_031
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 0, 12, RGB(13, 31, 12)
	waitforvisualfinish
	playsewithpan SE_W071, +63
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 0
	delay 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 5, 5, 1
	waitforvisualfinish
	delay 3
	call GigaDrainEffect
	waitforvisualfinish
	delay 15
	call HealingEffect
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 12, 0, RGB(13, 31, 12)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

GigaDrainEffect:
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 3, 5, -18, -40, 35
	createsprite gUnknown_08592270, 3, -10, 20, 20, 39
	delay 4
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 3, 0, 5, 28, 26
	createsprite gUnknown_08592270, 3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 3, -10, 20, 40, 39
	delay 4
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 3, -5, 15, 16, 33
	createsprite gUnknown_08592270, 3, 10, -5, -32, 26
	delay 4
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 3, 0, -15, -16, 36
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 3, 10, -5, -8, 26
	delay 4
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 3, -5, 15, 16, 33
	createsprite gUnknown_08592270, 3, 0, -15, -16, 36
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	delay 4
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 3, -5, 15, 16, 33
	createsprite gUnknown_08592270, 3, 10, -5, -40, 26
	delay 4
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 3, -5, 15, 36, 33
	createsprite gUnknown_08592270, 3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 3, -10, 20, 20, 39
	delay 4
	playsewithpan SE_W202, +63
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 3, 5, -18, -20, 35
	delay 4
	return

Move_LEECH_LIFE:
	loadspritegfx 0x27B1
	loadspritegfx 0x27A3
	delay 1
	loadspritegfx ANIM_TAG_031
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	setalpha 12, 8
	delay 1
	createsprite gUnknown_085969C8, 2, -20, 15, 12
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
	playsewithpan SE_W071, +63
	delay 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 5, 5, 1
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 0, 7, RGB_BLACK
	waitforvisualfinish
	call AbsorbEffect
	waitforvisualfinish
	delay 15
	call HealingEffect
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 7, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SYNTHESIS:
	loadspritegfx ANIM_TAG_049
	createvisualtask sub_8115A04, 2, 2, 2, 2, 0, 16, RGB(27, 31, 18)
	playsewithpan SE_W025, -64
	call GrantingStarsEffect
	waitforvisualfinish
	unloadspritegfx ANIM_TAG_049
	delay 1
	loadspritegfx ANIM_TAG_031
	call HealingEffect
	waitforvisualfinish
	end

Move_TOXIC:
	loadspritegfx 0x27A7
	loadspritegfx 0x27A6
	call Toxic1
	call Toxic1
	waitforvisualfinish
	delay 15
	call PoisonBubblesEffect
	waitforvisualfinish
	end

Toxic1:
	createsprite gUnknown_08596134, 130, -24, 16, 1, 1
	playsewithpan SE_W092, +63
	delay 15
	createsprite gUnknown_08596134, 130, 8, 16, 1, 1
	playsewithpan SE_W092, +63
	delay 15
	createsprite gUnknown_08596134, 130, -8, 16, 1, 1
	playsewithpan SE_W092, +63
	delay 15
	createsprite gUnknown_08596134, 130, 24, 16, 1, 1
	playsewithpan SE_W092, +63
	delay 15
	return

Move_SLUDGE:
	loadspritegfx 0x27A6
	playsewithpan SE_W145C, -64
	createsprite gUnknown_085961A8, 130, 20, 0, 40, 0
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 5, 1
	createvisualtask sub_8115A04, 2, 4, 1, 2, 0, 12, RGB(30, 0, 31)
	call PoisonBubblesEffect
	waitforvisualfinish
	end

Move_SLUDGE_BOMB:
	loadspritegfx 0x27A6
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	call SludgeBomb1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 3, 0, 15, 1
	createvisualtask sub_8115A04, 2, 4, 1, 2, 0, 12, RGB(30, 0, 31)
	createsprite gUnknown_085961D8, 130, 42, 27, 20
	createsprite gUnknown_085961D8, 130, -27, 44, 20
	createsprite gUnknown_085961D8, 130, 39, -28, 20
	createsprite gUnknown_085961D8, 130, -42, -42, 20
	playsewithpan SE_W091, +63
	delay 5
	createsprite gUnknown_085961D8, 130, 0, 40, 20
	createsprite gUnknown_085961D8, 130, -8, -44, 20
	createsprite gUnknown_085961D8, 130, -46, -28, 20
	createsprite gUnknown_085961D8, 130, 46, 9, 20
	playsewithpan SE_W091, +63
	delay 5
	createsprite gUnknown_085961D8, 130, 42, 0, 20
	createsprite gUnknown_085961D8, 130, -43, -12, 20
	createsprite gUnknown_085961D8, 130, 16, -46, 20
	createsprite gUnknown_085961D8, 130, -16, 44, 20
	playsewithpan SE_W091, +63
	delay 0
	waitsound
	waitforvisualfinish
	call PoisonBubblesEffect
	waitforvisualfinish
	end

SludgeBomb1:
	playsewithpan SE_W145C, -64
	createsprite gUnknown_085961A8, 130, 20, 0, 40, 0
	delay 3
	return

Move_ACID:
	loadspritegfx 0x27A6
	monbg ANIM_DEF_PARTNER
	createsprite gUnknown_085961C0, 130, 20, 0, 40, 1, 0, 0
	playsewithpan SE_W145C, -64
	delay 5
	createsprite gUnknown_085961C0, 130, 20, 0, 40, 1, 24, 0
	playsewithpan SE_W145C, -64
	delay 5
	createsprite gUnknown_085961C0, 130, 20, 0, 40, 1, -24, 0
	playsewithpan SE_W145C, -64
	delay 15
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 2, 0, 10, 1
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_DEF_PARTNER, 2, 0, 10, 1
	createvisualtask sub_8115A04, 2, 20, 2, 2, 0, 12, RGB(30, 0, 31)
	createsprite gUnknown_0859620C, 130, 0, -22, 0, 15, 55
	playsewithpan SE_W145, +63
	delay 10
	createsprite gUnknown_0859620C, 130, -26, -24, 0, 15, 55
	playsewithpan SE_W145, +63
	delay 10
	createsprite gUnknown_0859620C, 130, 15, -27, 0, 15, 50
	playsewithpan SE_W145, +63
	delay 10
	createsprite gUnknown_0859620C, 130, -15, -17, 0, 10, 45
	playsewithpan SE_W145, +63
	delay 10
	createsprite gUnknown_0859620C, 130, 27, -22, 0, 15, 50
	playsewithpan SE_W145, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_BONEMERANG:
	loadspritegfx 0x2710
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W155, -64
	createsprite gUnknown_08597178, 2
	delay 20
	playsewithpan SE_W030, +63
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 5, 0, 5, 1
	delay 17
	playsewithpan SE_W233, -64
	createsprite gHorizontalLungeSpriteTemplate, 2, 6, -4
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_BONE_CLUB:
	loadspritegfx 0x2710
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W155, +63
	createsprite gUnknown_08597190, 2, -42, -25, 0, 0, 15
	delay 12
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 5, 5, 1
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 7, 5, 1, 0, 10, 0, 0
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_BONE_RUSH:
	loadspritegfx 0x2710
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W155, +63
	createsprite gUnknown_08597190, 2, -42, -25, 0, 0, 15
	delay 12
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 3, 5, 1
	playsewithpan SE_W030, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SPIKES:
	loadspritegfx 0x27A8
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W026, -64
	waitplaysewithpan SE_W030, +63, 0x1C
	createsprite gUnknown_085CE11C, 130, 20, 0, 0, 24, 30
	delay 10
	playsewithpan SE_W026, -64
	waitplaysewithpan SE_W030, +63, 0x1C
	createsprite gUnknown_085CE11C, 130, 20, 0, -24, 24, 30
	delay 10
	waitplaysewithpan SE_W030, +63, 0x1C
	createsprite gUnknown_085CE11C, 130, 20, 0, 24, 24, 30
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_MEGAHORN:
	loadspritegfx 0x27A9
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W082, -64
	jumpifcontest MegahornInContest
	fadetobg BG_DRILL
	waitbgfadeout
	createvisualtask sub_8117660, 5, -2304, 768, 1, -1
MegahornContinue:
	waitbgfadein
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 2, 0, 15, 1
	waitforvisualfinish
	delay 10
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, 24, 0, 0, 6
	delay 3
	createsprite gUnknown_08596974, 3, -42, 25, 0, 0, 6
	delay 4
	playsewithpan SE_W011, +63
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 0
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 1, -16, 4, 1, 4
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, -4, 1, 12, 1
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 7, 5, 1, 0x7FFF, 10, 0, 0
	delay 10
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 11
	delay 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 1, 0, 7
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	restorebg
	waitbgfadeout
	setarg 7, 0xFFFF
	waitbgfadein
	end

MegahornInContest:
	fadetobg BG_DRILL_CONTESTS
	waitbgfadeout
	createvisualtask sub_8117660, 5, 2304, 768, 0, -1
	goto MegahornContinue

Move_GUST:
	loadspritegfx 0x2719
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W016, +63
	createsprite gUnknown_08596270, 2, 0, -16
	createvisualtask sub_810DED8, 5, 1, 70
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 1, 0, 7, 1
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
	playsewithpan SE_W016B, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_WING_ATTACK:
	loadspritegfx 0x2719
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	loopsewithpan SE_W017, -64, 20, 2
	createvisualtask sub_80D5738, 2, 0, 12, 4, 1, 4
	createvisualtask sub_810DED8, 5, 1, 70
	createsprite gBattleAnimSpriteTemplate_85962A4, 2, -25, 0, 0, 0, 20
	createsprite gBattleAnimSpriteTemplate_85962A4, 2, 25, 0, 0, 0, 20
	delay 24
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, 24, 0, 0, 9
	delay 17
	createsprite gBasicHitSplatSpriteTemplate, 2, 16, 0, 1, 1
	createsprite gBasicHitSplatSpriteTemplate, 2, -16, 0, 1, 1
	loopsewithpan SE_W003, +63, 5, 2
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 11
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_PECK:
	loadspritegfx ANIM_TAG_135
	playsewithpan SE_W030, +63
	createvisualtask sub_80D622C, 2, 3, -768, 1, 2
	createsprite gUnknown_085973E8, 131, -12, 0, 1, 3
	waitforvisualfinish
	end

Move_AEROBLAST:
	loadspritegfx 0x27AA
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	call SetFlyingBg
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	call Aeroblast1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 5, 0, 50, 1
	call Aeroblast1
	call Aeroblast1
	call Aeroblast1
	call Aeroblast1
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 0
	playsewithpan SE_W013, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	delay 0
	call UnsetFlyingBg
	end

Aeroblast1:
	playsewithpan SE_W026, -64
	createsprite gUnknown_085962D4, 2, 14, -12, 0, -12, 15, 0, 0
	createsprite gUnknown_085962D4, 2, 26, 8, 12, 8, 15, 0, 0
	delay 3
	playsewithpan SE_W026, -64
	createsprite gUnknown_085962D4, 2, 14, -12, 0, -12, 15, 1, 0
	createsprite gUnknown_085962D4, 2, 26, 8, 12, 8, 15, 1, 0
	delay 3
	playsewithpan SE_W026, -64
	createsprite gUnknown_085962D4, 2, 14, -12, 0, -12, 15, 2, 0
	createsprite gUnknown_085962D4, 2, 26, 8, 12, 8, 15, 2, 0
	delay 3
	playsewithpan SE_W026, -64
	createsprite gUnknown_085962D4, 2, 14, -12, 0, -12, 15, 3, 0
	createsprite gUnknown_085962D4, 2, 26, 8, 12, 8, 15, 3, 0
	delay 3
	return

Move_WATER_GUN:
	loadspritegfx ANIM_TAG_155
	loadspritegfx 0x27A4
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createsprite gUnknown_08595208, 2, 20, 0, 0, 0, 40, -25
	playsewithpan SE_W145, -64
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 1, 0, 8, 1
	createsprite gUnknown_08597388, 4, 0, 0, 1, 2
	createsprite gUnknown_08595220, 2, 0, -15, 0, 15, 55
	playsewithpan SE_W152, +63
	delay 10
	createsprite gUnknown_08595220, 2, 15, -20, 0, 15, 50
	playsewithpan SE_W152, +63
	delay 10
	createsprite gUnknown_08595220, 2, -15, -10, 0, 10, 45
	playsewithpan SE_W152, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_CRABHAMMER:
	loadspritegfx ANIM_TAG_141
	loadspritegfx 0x27A4
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createsprite gUnknown_08597388, 4, 0, 0, 1, 0
	playsewithpan SE_W233B, +63
	delay 1
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 31, 3, 1, 32429, 10, 0, 0
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 1, -24, 0, 0, 4
	waitforvisualfinish
	delay 8
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 1, 0, 4
	waitforvisualfinish
	loopsewithpan SE_W152, +63, 20, 3
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 4, 8, 1
	createsprite gUnknown_08595238, 2, 10, 10, 20, 1
	delay 4
	createsprite gUnknown_08595238, 2, 20, -20, 20, 1
	delay 4
	createsprite gUnknown_08595238, 2, -15, 15, 20, 1
	delay 4
	createsprite gUnknown_08595238, 2, 0, 0, 20, 1
	delay 4
	createsprite gUnknown_08595238, 2, -10, -20, 20, 1
	delay 4
	createsprite gUnknown_08595238, 2, 16, -8, 20, 1
	delay 4
	createsprite gUnknown_08595238, 2, 5, 8, 20, 1
	delay 4
	createsprite gUnknown_08595238, 2, -16, 0, 20, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SURF:
	createvisualtask sub_8107954, 2, 0
	delay 24
	panse_1B SE_W057, -64, +63, +2, 0
	waitforvisualfinish
	end

Move_FLAMETHROWER:
	loadspritegfx 0x272D
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 0, 2, 46, 1
	delay 6
	createvisualtask sub_81076C8, 5, 100
	panse_1B SE_W053, -64, +63, +2, 0
	call Flamethrower1
	call Flamethrower1
	call Flamethrower1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 43, 1
	call Flamethrower1
	call Flamethrower1
	call Flamethrower1
	call Flamethrower1
	call Flamethrower1
	call Flamethrower1
	call Flamethrower1
	call Flamethrower1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Flamethrower1:
	createsprite gUnknown_08595158, 3, 10, 10, 0, 16
	delay 2
	createsprite gUnknown_08595158, 3, 10, 10, 0, 16
	delay 2
	return

Move_SANDSTORM:
	loadspritegfx 0x2815
	playsewithpan SE_W201, 0
	createvisualtask sub_8110BCC, 5, 0
	delay 16
	createsprite gBattleAnimSpriteTemplate_8596BA0, 0x28, 10, 2304, 96, 0
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, 0x28, 90, 2048, 96, 0
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, 0x28, 50, 2560, 96, 0
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, 0x28, 20, 2304, 96, 0
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, 0x28, 70, 1984, 96, 0
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, 0x28, 0, 2816, 96, 0
	delay 10
	createsprite gBattleAnimSpriteTemplate_8596BA0, 0x28, 60, 2560, 96, 0
	end

Move_WHIRLPOOL:
	loadspritegfx 0x27A5
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	delay 0
	createsprite gSimplePaletteBlendSpriteTemplate, 0, 4, 2, 0, 7, RGB(0, 13, 23)
	playsewithpan SE_W250, +63
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 2, 50, 1
	call WhirlpoolEffect
	call WhirlpoolEffect
	call WhirlpoolEffect
	delay 12
	createsprite gSimplePaletteBlendSpriteTemplate, 0, 4, 2, 7, 0, RGB(0, 13, 23)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

WhirlpoolEffect:
	createsprite gUnknown_08596B70, 130, 0, 28, 384, 50, 8, 50, 1
	delay 2
	createsprite gUnknown_08596B70, 130, 0, 32, 240, 40, 11, -46, 1
	delay 2
	createsprite gUnknown_08596B70, 130, 0, 33, 416, 40, 4, 42, 1
	delay 2
	createsprite gUnknown_08596B70, 130, 0, 31, 288, 45, 6, -42, 1
	delay 2
	createsprite gUnknown_08596B70, 130, 0, 28, 448, 45, 11, 46, 1
	delay 2
	createsprite gUnknown_08596B70, 130, 0, 33, 464, 50, 10, -50, 1
	delay 2
	return

Move_FLY:
	loadspritegfx 0x27AC
	loadspritegfx ANIM_TAG_135
	choosetwoturnanim FlySetUp, FlyUnleash
FlyEnd:
	waitforvisualfinish
	end

FlySetUp:
	playsewithpan SE_W019, -64
	createsprite gUnknown_08596340, 2, 0, 0, 13, 336
	goto FlyEnd

FlyUnleash:
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W104, -64
	createsprite gUnknown_08596358, 2, 20
	delay 20
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	playsewithpan SE_W013, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto FlyEnd

Move_BOUNCE:
	loadspritegfx 0x27AC
	loadspritegfx ANIM_TAG_135
	choosetwoturnanim BounceSetUp, BounceUnleash
BounceEnd:
	end

BounceSetUp:
	playsewithpan SE_W100, -64
	createsprite gUnknown_08596420, 2, 0, 0
	goto BounceEnd

BounceUnleash:
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W207, +63
	createsprite gUnknown_0859644C, 131
	delay 7
	playsewithpan SE_W025B, +63
	createsprite gBasicHitSplatSpriteTemplate, 130, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 5, 11, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto BounceEnd

Move_KARATE_CHOP:
	loadspritegfx ANIM_TAG_143
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W104, +63
	createsprite gUnknown_08595E68, 2, -16, 0, 0, 0, 10, 1, 3, 0
	waitforvisualfinish
	playsewithpan SE_W004, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 4, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_CROSS_CHOP:
	loadspritegfx ANIM_TAG_143
	loadspritegfx 0x282D
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W025, +63
	createsprite gUnknown_08595EC8, 2, 0, 0, 0
	createsprite gUnknown_08595EC8, 2, 0, 0, 1
	delay 0x28
	playsewithpan SE_W013, +63
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 31, 3, 1, 0x7FFF, 10, 0, 10
	createsprite gUnknown_085973D0, 3, 0, 0, 1, 20
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 7, 0, 9, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_JUMP_KICK:
	loadspritegfx ANIM_TAG_143
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, 2, 4, 4
	delay 3
	createsprite gUnknown_08595E80, 2, -16, 8, 0, 0, 10, 1, 1, 1
	playsewithpan SE_W026, +63
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, 1, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 5, 0, 7, 1
	playsewithpan SE_W004, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_HI_JUMP_KICK:
	loadspritegfx ANIM_TAG_143
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, -24, 0, 0, 8
	waitforvisualfinish
	delay 10
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 3
	delay 2
	createsprite gUnknown_08595E80, 2, -16, 8, 0, 0, 10, 1, 1, 1
	playsewithpan SE_W026, +63
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 1
	playsewithpan SE_W233B, +63
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 1, -28, 0, 0, 3
	delay 3
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 3, 0, 11, 1
	waitforvisualfinish
	delay 5
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 1, 0, 6
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_DOUBLE_KICK:
	loadspritegfx ANIM_TAG_143
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createsprite gUnknown_08595EB0, 3, 1, 20, 1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 4, 0, 6, 1
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_TRIPLE_KICK:
	loadspritegfx ANIM_TAG_143
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W233B, +63
	jumpifmoveturn 0, TripleKickLeft
	jumpifmoveturn 1, TripleKickRight
	goto TripleKickCenter
TripleKickContinue:
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

TripleKickLeft:
	createsprite gFistFootSpriteTemplate, 132, -16, -8, 20, 1, 1
	createsprite gBasicHitSplatSpriteTemplate, 131, -16, -16, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 4, 0, 6, 1
	goto TripleKickContinue

TripleKickRight:
	createsprite gFistFootSpriteTemplate, 132, 8, 8, 20, 1, 1
	createsprite gBasicHitSplatSpriteTemplate, 131, 8, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 4, 0, 6, 1
	goto TripleKickContinue

TripleKickCenter:
	createsprite gFistFootSpriteTemplate, 132, 0, 0, 20, 1, 1
	createsprite gBasicHitSplatSpriteTemplate, 131, 0, -8, 1, 1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	goto TripleKickContinue

Move_DYNAMIC_PUNCH:
	loadspritegfx ANIM_TAG_143
	loadspritegfx ANIM_TAG_135
	loadspritegfx 0x27D6
	loadspritegfx 0x2717
	delay 1
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W233B, +63
	createsprite gFistFootSpriteTemplate, 131, 0, 0, 20, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, 130, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 5, 0, 7, 1
	delay 1
	waitsound
	playsewithpan SE_W120, +63
	createvisualtask AnimTask_ShakeMon2, 5, ANIM_TARGET, 5, 0, 28, 1
	createsprite gBattleAnimSpriteTemplate_859371C, 3, 0, 0, 1, 1
	delay 6
	playsewithpan SE_W120, +63
	createsprite gBattleAnimSpriteTemplate_859371C, 3, 24, -24, 1, 1
	delay 6
	playsewithpan SE_W120, +63
	createsprite gBattleAnimSpriteTemplate_859371C, 3, -16, 16, 1, 1
	delay 6
	playsewithpan SE_W120, +63
	createsprite gBattleAnimSpriteTemplate_859371C, 3, -24, -12, 1, 1
	delay 6
	playsewithpan SE_W120, +63
	createsprite gBattleAnimSpriteTemplate_859371C, 3, 16, 16, 1, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_COUNTER:
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 18, 6, 1, 4
	playsewithpan SE_W233, -64
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, 20, 0, 0, 4
	delay 4
	createsprite gBasicHitSplatSpriteTemplate, 2, -15, 18, 1, 0
	playsewithpan SE_W233B, +63
	delay 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 25, 1
	createsprite gFistFootSpriteTemplate, 3, -15, 18, 8, 1, 0
	delay 3
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, -4, 1, 0
	playsewithpan SE_W233B, +63
	delay 1
	createsprite gFistFootSpriteTemplate, 3, 0, -4, 8, 1, 0
	delay 3
	createsprite gBasicHitSplatSpriteTemplate, 2, 15, 9, 1, 0
	playsewithpan SE_W233B, +63
	delay 1
	createsprite gFistFootSpriteTemplate, 3, 15, 9, 8, 1, 0
	delay 5
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 5
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_VITAL_THROW:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W233, -64
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 12, 4, 1, 2
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, 20, 0, 0, 4
	delay 2
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 1
	playsewithpan SE_W233B, +63
	delay 1
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 1, -24, 0, 0, 4
	waitforvisualfinish
	delay 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 7
	delay 11
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 1, 0, 10
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_ROCK_SMASH:
	loadspritegfx ANIM_TAG_058
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	delay 1
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 1
	createsprite gFistFootSpriteTemplate, 2, 0, 0, 8, 1, 0
	playsewithpan SE_W233B, +63
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 5, 1
	waitforvisualfinish
	playsewithpan SE_W088, +63
	createsprite gUnknown_08596B1C, 2, 0, 0, 20, 24, 14, 2
	createsprite gUnknown_08596B1C, 2, 5, 0, -20, 24, 14, 1
	createsprite gUnknown_08596B1C, 2, 0, 5, 20, -24, 14, 2
	createsprite gUnknown_08596B1C, 2, -5, 0, -20, -24, 14, 2
	createsprite gUnknown_08596B1C, 2, 0, -5, 30, 18, 8, 2
	createsprite gUnknown_08596B1C, 2, 0, 0, 30, -18, 8, 2
	createsprite gUnknown_08596B1C, 2, 0, 0, -30, 18, 8, 2
	createsprite gUnknown_08596B1C, 2, 0, 0, -30, -18, 8, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 7, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_SUBMISSION:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W104, -64
	waitplaysewithpan SE_W004, +63, 10
	waitplaysewithpan SE_W104, -64, 20
	waitplaysewithpan SE_W004, +63, 30
	waitplaysewithpan SE_W104, -64, 0x28
	waitplaysewithpan SE_W004, +63, 50
	waitplaysewithpan SE_W104, -64, 60
	waitplaysewithpan SE_W004, +63, 70
	waitplaysewithpan SE_W104, -64, 0x50
	waitplaysewithpan SE_W004, +63, 0x5A
	createvisualtask sub_80D5738, 2, 0, -18, 6, 6, 4
	createvisualtask sub_80D5738, 2, 1, 18, 6, 6, 4
	call Submission1
	call Submission1
	call Submission1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Submission1:
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, -12, 1, 1
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, 3, -12, 8, 1, 1
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, 3, 12, 0, 1, 1
	delay 8
	return

Move_SUNNY_DAY:
	loadspritegfx 0x27AD
	monbg ANIM_ATK_PARTNER
	setalpha 13, 3
	createvisualtask sub_8116620, 10, 0x781, 1, 0, 6, RGB_WHITE
	waitforvisualfinish
	panse_26 SE_W080, -64, +63, +1, 0
	call SunnyDay1
	call SunnyDay1
	call SunnyDay1
	call SunnyDay1
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 0x781, 1, 6, 0, RGB_WHITE
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

SunnyDay1:
	createsprite gUnknown_085954A0, 0x28
	delay 6
	return

Move_COTTON_SPORE:
	loadspritegfx 0x27AE
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	loopsewithpan SE_W077, +63, 0x12, 10
	call CottonSpore1
	call CottonSpore1
	call CottonSpore1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

CottonSpore1:
	createsprite gUnknown_085922EC, 2, 0, -20, 85, 80, 0
	delay 12
	createsprite gUnknown_085922EC, 2, 0, -10, 170, 80, 0
	delay 12
	createsprite gUnknown_085922EC, 2, 0, -15, 0, 80, 0
	delay 12
	return

Move_SPORE:
	loadspritegfx 0x27AE
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask sub_80FEE1C, 2
	loopsewithpan SE_W077, +63, 16, 11
	call Spore1
	call Spore1
	call Spore1
	waitforvisualfinish
	delay 1
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Spore1:
	createsprite gUnknown_085922EC, 130, 0, -20, 85, 80, 1
	delay 12
	createsprite gUnknown_085922EC, 130, 0, -10, 170, 80, 1
	delay 12
	createsprite gUnknown_085922EC, 130, 0, -15, 0, 80, 1
	delay 12
	return

Move_PETAL_DANCE:
	loadspritegfx ANIM_TAG_159
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W080, -64
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 12, 6, 6, 3
	createsprite gUnknown_0859231C, 2, 0, -24, 8, 140
	createsprite gUnknown_08592334, 2, 16, -24, 8, 100
	createsprite gUnknown_08592334, 2, -16, -24, 8, 100
	delay 15
	createsprite gUnknown_0859231C, 2, 0, -24, 8, 140
	createsprite gUnknown_08592334, 2, 32, -24, 8, 100
	createsprite gUnknown_08592334, 2, -32, -24, 8, 100
	delay 15
	createsprite gUnknown_0859231C, 2, 0, -24, 8, 140
	createsprite gUnknown_08592334, 2, 24, -24, 8, 100
	createsprite gUnknown_08592334, 2, -24, -24, 8, 100
	delay 30
	createsprite gUnknown_08592334, 2, 16, -24, 0, 100
	createsprite gUnknown_08592334, 2, -16, -24, 0, 100
	delay 30
	createsprite gUnknown_08592334, 2, 20, -16, 14, 80
	createsprite gUnknown_08592334, 2, -20, -14, 16, 80
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, 24, 0, 0, 5
	delay 3
	playsewithpan SE_W025B, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 6, 0, 8, 1
	waitforvisualfinish
	delay 8
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 7
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_RAZOR_LEAF:
	loadspritegfx 0x274F
	loadspritegfx 0x27B0
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	delay 1
	loopsewithpan SE_W077, -64, 10, 5
	createsprite gUnknown_08592390, 2, -3, -2, 10
	delay 2
	createsprite gUnknown_08592390, 2, -1, -1, 15
	delay 2
	createsprite gUnknown_08592390, 2, -4, -4, 7
	delay 2
	createsprite gUnknown_08592390, 2, 3, -3, 11
	delay 2
	createsprite gUnknown_08592390, 2, -1, -6, 8
	delay 2
	createsprite gUnknown_08592390, 2, 2, -1, 12
	delay 2
	createsprite gUnknown_08592390, 2, -3, -4, 13
	delay 2
	createsprite gUnknown_08592390, 2, 4, -5, 7
	delay 2
	createsprite gUnknown_08592390, 2, 2, -6, 11
	delay 2
	createsprite gUnknown_08592390, 2, -3, -5, 8
	delay 60
	playsewithpan SE_W013B, -64
	createsprite gUnknown_085923D8, 131, 20, -10, 20, 0, 22, 20, 1
	createsprite gUnknown_085923D8, 131, 20, -10, 20, 0, 22, -20, 1
	delay 20
	playsewithpan SE_W013, +63
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 2, 0, 8, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_NATURE_POWER:
Move_ANCIENT_POWER:
	loadspritegfx ANIM_TAG_058
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createsprite gBattleAnimSpriteTemplate_85972D8, 2, 4, 1, 10, 1
	createsprite gUnknown_08596C10, 2, 20, 32, -48, 50, 2
	createsprite gUnknown_08596C10, 2, 0, 32, -38, 25, 5
	createsprite gUnknown_08596C10, 2, 32, 32, -28, 40, 3
	createsprite gUnknown_08596C10, 2, -20, 32, -48, 50, 2
	createsprite gUnknown_08596C10, 2, 20, 32, -28, 60, 1
	createsprite gUnknown_08596C10, 2, 0, 32, -28, 30, 4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 30, 1
	playsewithpan SE_W082, -64
	delay 10
	createsprite gUnknown_08596C10, 2, 15, 32, -48, 25, 5
	createsprite gUnknown_08596C10, 2, -10, 32, -42, 30, 4
	delay 10
	createsprite gUnknown_08596C10, 2, 0, 32, -42, 25, 5
	createsprite gUnknown_08596C10, 2, -25, 32, -48, 30, 4
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, 16, 0, 0, 4
	delay 3
	playsewithpan SE_W120, +63
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 7
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_OCTAZOOKA:
	loadspritegfx 0x272E
	loadspritegfx 0x2721
	playsewithpan SE_W025B, -64
	createsprite gUnknown_08592DFC, 130, 20, 0, 0, 0, 20, 0
	waitforvisualfinish
	playsewithpan SE_W120, +63
	createsprite gUnknown_08592E30, 130, 8, 8, 1, 0
	delay 2
	createsprite gUnknown_08592E30, 130, -8, -8, 1, 0
	delay 2
	createsprite gUnknown_08592E30, 130, 8, -8, 1, 0
	delay 2
	createsprite gUnknown_08592E30, 130, -8, 8, 1, 0
	waitforvisualfinish
	end

Move_MIST:
	loadspritegfx 0x27A0
	monbg ANIM_ATK_PARTNER
	setalpha 12, 8
	loopsewithpan SE_W054, -64, 20, 15
	call Mist1
	call Mist1
	call Mist1
	call Mist1
	call Mist1
	call Mist1
	call Mist1
	delay 0x20
	createvisualtask sub_8115A04, 2, 10, 8, 2, 0, 14, RGB_WHITE
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

Mist1:
	createsprite gUnknown_08595C2C, 2, 0, -24, 48, 240, 0, 1
	delay 7
	return

Move_HAZE:
	waitforvisualfinish
	playsewithpan SE_W114, 0
	createvisualtask sub_810C0A0, 5
	delay 30
	createvisualtask sub_8116620, 10, 0x780, 2, 0, 16, RGB_BLACK
	delay 0x5A
	createvisualtask sub_8116620, 10, 0x780, 1, 16, 0, RGB_BLACK
	end

Move_FIRE_PUNCH:
	loadspritegfx ANIM_TAG_143
	loadspritegfx 0x272D
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask sub_8116620, 10, 4, 2, 0, 9, RGB_RED
	createsprite gUnknown_08595368, 0x81, 0
	createsprite gUnknown_08595368, 0x81, 64
	createsprite gUnknown_08595368, 0x81, 128
	createsprite gUnknown_08595368, 0x81, 196
	playsewithpan SE_W172, +63
	waitforvisualfinish
	createsprite gFistFootSpriteTemplate, 131, 0, 0, 8, 1, 0
	createsprite gBasicHitSplatSpriteTemplate, 130, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 15, 1
	call FireMoveEffect
	delay 4
	playsewithpan SE_W007, +63
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 4, 0, 9, 0, RGB_RED
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

FireMoveEffect:
	createsprite gUnknown_08595380, 0x81, 0, 10, 192, 176, 40
	createsprite gUnknown_08595380, 0x81, 0, 10, -192, 240, 40
	createsprite gUnknown_08595380, 0x81, 0, 10, 192, -160, 40
	createsprite gUnknown_08595380, 0x81, 0, 10, -192, -112, 40
	createsprite gUnknown_08595380, 0x81, 0, 10, 160, 48, 40
	createsprite gUnknown_08595380, 0x81, 0, 10, -224, -32, 40
	createsprite gUnknown_08595380, 0x81, 0, 10, 112, -128, 40
	return

Move_LEER:
	loadspritegfx 0x272B
	monbg ANIM_ATTACKER
	monbgprio_28 ANIM_ATTACKER
	setalpha 8, 8
	playsewithpan SE_W043, -64
	createsprite gUnknown_085CE150, 2, 24, -12
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -5, -5, 10, ANIM_ATTACKER, 1
	waitforvisualfinish
	delay 10
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 9, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 1, 0, 9, 1
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	blendoff
	delay 1
	waitforvisualfinish
	end

Move_DREAM_EATER:
	loadspritegfx 0x27A3
	loadspritegfx ANIM_TAG_031
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	playsewithpan SE_W060, -64
	call SetPsychicBackground
	setalpha 8, 8
	playsewithpan SE_W107, +63
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 5, 0, 15, 1
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -6, -6, 15, ANIM_TARGET, 1
	waitforvisualfinish
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 2, 25, 1
	call DreamEaterEffect
	waitforvisualfinish
	delay 15
	call HealingEffect
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	delay 1
	call UnsetPsychicBackground
	end
DreamEaterEffect:
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 3, 5, -18, -40, 35
	createsprite gUnknown_08592270, 3, -10, 20, 20, 39
	delay 4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 3, 0, 5, 28, 26
	createsprite gUnknown_08592270, 3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 3, -10, 20, 40, 39
	delay 4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 3, -5, 15, 16, 33
	createsprite gUnknown_08592270, 3, 10, -5, -32, 26
	delay 4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 3, 0, -15, -16, 36
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 3, 10, -5, -8, 26
	delay 4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 3, -5, 15, 16, 33
	createsprite gUnknown_08592270, 3, 0, -15, -16, 36
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	delay 4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 3, -5, 15, 16, 33
	createsprite gUnknown_08592270, 3, 10, -5, -40, 26
	delay 4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 3, -5, 15, 36, 33
	createsprite gUnknown_08592270, 3, 10, -5, -8, 26
	createsprite gUnknown_08592270, 3, -10, 20, 20, 39
	delay 4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 3, 0, 5, 8, 26
	createsprite gUnknown_08592270, 3, 5, -18, -20, 35
	delay 4
	return

Move_POISON_GAS:
	loadspritegfx 0x27BC
	loadspritegfx 0x27A6
	delay 0
	monbg ANIM_DEF_PARTNER
	monbgprio_29
	setalpha 12, 8
	delay 0
	playsewithpan SE_W054, -64
	createsprite gUnknown_08595C9C, 0x80, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 4
	playsewithpan SE_W054, -64
	createsprite gUnknown_08595C9C, 0x80, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 4
	playsewithpan SE_W054, -64
	createsprite gUnknown_08595C9C, 0x80, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 4
	playsewithpan SE_W054, -64
	createsprite gUnknown_08595C9C, 0x80, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 4
	playsewithpan SE_W054, -64
	createsprite gUnknown_08595C9C, 0x80, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 4
	playsewithpan SE_W054, -64
	createsprite gUnknown_08595C9C, 0x80, 64, 0, 0, -32, -6, 4192, 1072, 0
	delay 0x28
	loopsewithpan SE_W054, +63, 0x1C, 6
	createvisualtask sub_8115A04, 2, 4, 6, 2, 0, 12, RGB(26, 0, 26)
	waitforvisualfinish
	blendoff
	clearmonbg ANIM_DEF_PARTNER
	delay 0
	end

Move_BIND:
	createvisualtask AnimTask_SwayMon, 5, 0, 6, 3328, 4, ANIM_ATTACKER
	goto BindWrap

BindWrap:
	playsewithpan SE_W020, +63
	call BindWrap1
	call BindWrap1
	waitforvisualfinish
	end
BindWrap1:
	createvisualtask AnimTask_ScaleMonAndRestore, 5, 10, -5, 5, ANIM_TARGET, 0
	delay 16
	return

Move_WRAP:
	createvisualtask AnimTask_TranslateMonEllipticalRespectSide, 2, ANIM_ATTACKER, 6, 4, 2, 4
	goto BindWrap

Move_PSYBEAM:
	loadspritegfx 0x27B3
	playsewithpan SE_W060, -64
	call SetPsychicBackground
	createsoundtask sub_8158C58, 200, -64, 63, 3, 4, 0, 15
	call Psybeam1
	call Psybeam1
	createvisualtask AnimTask_SwayMon, 5, 0, 6, 2048, 4, ANIM_TARGET
	createvisualtask sub_8115A04, 2, 4, 2, 2, 0, 12, RGB(31, 18, 31)
	call Psybeam1
	call Psybeam1
	call Psybeam1
	call Psybeam1
	call Psybeam1
	call Psybeam1
	call Psybeam1
	call Psybeam1
	call Psybeam1
	waitforvisualfinish
	delay 1
	call UnsetPsychicBackground
	end
Psybeam1:
	createsprite gUnknown_0859663C, 130, 16, 0, 0, 0, 13, 0
	delay 4
	return

Move_HYPNOSIS:
	loadspritegfx 0x27B3
	call SetPsychicBackground
	call Hypnosis1
	call Hypnosis1
	call Hypnosis1
	createvisualtask sub_8115A04, 2, 4, 2, 2, 0, 12, RGB(31, 18, 31)
	waitforvisualfinish
	delay 1
	call UnsetPsychicBackground
	end
Hypnosis1:
	playsewithpan SE_W048, -64
	createsprite gUnknown_0859663C, 130, 0, 8, 0, 8, 27, 0
	createsprite gUnknown_0859663C, 130, 16, -8, 0, -8, 27, 0
	delay 6
	return

Move_PSYWAVE:
	loadspritegfx 0x27B5
	playsewithpan SE_W060, -64
	call SetPsychicBackground
	createvisualtask sub_81076C8, 5, 100
	createsoundtask sub_8158C58, 203, -64, 63, 2, 9, 0, 10
	call Psywave1
	call Psywave1
	createvisualtask sub_8115A04, 2, 4, 1, 4, 0, 12, RGB(31, 18, 31)
	call Psywave1
	call Psywave1
	call Psywave1
	call Psywave1
	waitforvisualfinish
	delay 1
	call UnsetPsychicBackground
	end
Psywave1:
	createsprite gUnknown_08595170, 131, 10, 10, 0, 16
	delay 4
	createsprite gUnknown_08595170, 131, 10, 10, 0, 16
	delay 4
	return

Move_ZAP_CANNON:
	loadspritegfx 0x27BB
	loadspritegfx ANIM_TAG_011
	playsewithpan SE_W086, -64
	createsprite gUnknown_08595764, 131, 10, 0, 0, 0, 30, 0
	createsprite gUnknown_08595790, 132, 10, 0, 16, 30, 0, 40, 0
	createsprite gUnknown_08595790, 132, 10, 0, 16, 30, 64, 40, 1
	createsprite gUnknown_08595790, 132, 10, 0, 16, 30, 128, 40, 0
	createsprite gUnknown_08595790, 132, 10, 0, 16, 30, 192, 40, 2
	createsprite gUnknown_08595790, 132, 10, 0, 8, 30, 32, 40, 0
	createsprite gUnknown_08595790, 132, 10, 0, 8, 30, 96, 40, 1
	createsprite gUnknown_08595790, 132, 10, 0, 8, 30, 160, 40, 0
	createsprite gUnknown_08595790, 132, 10, 0, 8, 30, 224, 40, 2
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 5, 1
	delay 15
	waitplaysewithpan SE_W085B, +63, 19
	call ElectricityEffect
	waitforvisualfinish
	end

Move_STEEL_WING:
	loadspritegfx 0x2719
	loadspritegfx ANIM_TAG_135
	loopsewithpan SE_W231, -64, 0x1C, 2
	createvisualtask sub_81144F8, 5, 0, 0, 0
	waitforvisualfinish
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	loopsewithpan SE_W017, -64, 20, 2
	createvisualtask sub_80D5738, 2, 0, 12, 4, 1, 4
	createvisualtask sub_810DED8, 5, 1, 70
	createsprite gBattleAnimSpriteTemplate_85962A4, 2, -25, 0, 0, 0, 20
	createsprite gBattleAnimSpriteTemplate_85962A4, 2, 25, 0, 0, 0, 20
	delay 24
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, 24, 0, 0, 9
	delay 17
	createsprite gBasicHitSplatSpriteTemplate, 2, 16, 0, 1, 1
	createsprite gBasicHitSplatSpriteTemplate, 2, -16, 0, 1, 1
	playsewithpan SE_W013, +63
	waitforvisualfinish
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 11
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_IRON_TAIL:
	loadspritegfx ANIM_TAG_135
	loopsewithpan SE_W231, -64, 0x1C, 2
	createvisualtask sub_81144F8, 5, 1, 0, 0
	waitforvisualfinish
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, 2, 4, 4
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, 130, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	createvisualtask sub_811489C, 5, 0, 1
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end

Move_POISON_TAIL:
	loadspritegfx ANIM_TAG_135
	loadspritegfx 0x27A6
	loopsewithpan SE_W231, -64, 0x1C, 2
	createvisualtask sub_81144F8, 5, 1, 1, RGB(24, 6, 23)
	waitforvisualfinish
	monbg ANIM_TARGET
	setalpha 12, 8
	createsprite gHorizontalLungeSpriteTemplate, 2, 4, 4
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, 130, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	playsewithpan SE_W233B, +63
	waitforvisualfinish
	createvisualtask sub_811489C, 5, 0, 1
	clearmonbg ANIM_TARGET
	blendoff
	call PoisonBubblesEffect
	waitforvisualfinish
	end

Move_METAL_CLAW:
	loadspritegfx ANIM_TAG_039
	loopsewithpan SE_W231, -64, 0x1C, 2
	createvisualtask sub_81144F8, 5, 0, 0, 0
	waitforvisualfinish
	createsprite gHorizontalLungeSpriteTemplate, 2, 6, 4
	delay 2
	playsewithpan SE_W013, +63
	createsprite gBattleAnimSpriteTemplate_8597138, 130, -10, -10, 0
	createsprite gBattleAnimSpriteTemplate_8597138, 130, -10, 10, 0
	createsprite gBattleAnimSpriteTemplate_85972D8, 2, -4, 1, 10, 3, 1
	delay 8
	createsprite gHorizontalLungeSpriteTemplate, 2, 6, 4
	delay 2
	playsewithpan SE_W013, +63
	createsprite gBattleAnimSpriteTemplate_8597138, 130, 10, -10, 1
	createsprite gBattleAnimSpriteTemplate_8597138, 130, 10, 10, 1
	createsprite gBattleAnimSpriteTemplate_85972D8, 2, -4, 1, 10, 3, 1
	waitforvisualfinish
	end

Move_NIGHT_SHADE:
	monbg ANIM_ATTACKER
	monbgprio_28 ANIM_ATTACKER
	playsewithpan SE_W060, -64
	fadetobg BG_GHOST
	waitbgfadein
	delay 10
	playsewithpan SE_W043, -64
	createvisualtask sub_811188C, 5, 85
	delay 70
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 12, 1
	createvisualtask sub_8115A04, 2, 4, 0, 2, 0, 13, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	delay 1
	restorebg
	waitbgfadein
	end

Move_EGG_BOMB:
	loadspritegfx 0x27D6
	loadspritegfx 0x27BF
	playsewithpan SE_W039, -64
	createsprite gUnknown_08593488, 130, 10, 0, 0, 0, 25, -32
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 16, 1
	createsprite gBattleAnimSpriteTemplate_859371C, 132, 6, 5, 1, 0
	playsewithpan SE_W120, +63
	delay 3
	createsprite gBattleAnimSpriteTemplate_859371C, 132, -16, -15, 1, 0
	playsewithpan SE_W120, +63
	delay 3
	createsprite gBattleAnimSpriteTemplate_859371C, 132, 16, -5, 1, 0
	playsewithpan SE_W120, +63
	delay 3
	createsprite gBattleAnimSpriteTemplate_859371C, 132, -12, 18, 1, 0
	playsewithpan SE_W120, +63
	delay 3
	createsprite gBattleAnimSpriteTemplate_859371C, 132, 0, 5, 1, 0
	playsewithpan SE_W120, +63
	delay 3
	waitforvisualfinish
	end

Move_SHADOW_BALL:
	loadspritegfx 0x27C0
	fadetobg BG_GHOST
	waitbgfadein
	delay 15
	createsoundtask sub_8158C58, 168, -64, 63, 5, 5, 0, 5
	createsprite gUnknown_08596D58, 130, 16, 16, 8
	waitforvisualfinish
	playsewithpan SE_W028, +63
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 8, 1
	waitforvisualfinish
	restorebg
	waitbgfadein
	end

Move_LICK:
	loadspritegfx 0x27C1
	delay 15
	playsewithpan SE_W122, +63
	createsprite gUnknown_08596D8C, 130, 0, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 16, 1
	waitforvisualfinish
	end

Move_FOCUS_ENERGY:
	loadspritegfx 0x27C8
	playsewithpan SE_W082, -64
	call EndureEffect
	delay 8
	createvisualtask sub_8115A04, 2, 2, 2, 2, 0, 11, RGB_WHITE
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 32, 1
	call EndureEffect
	delay 8
	call EndureEffect
	waitforvisualfinish
	end

Move_BIDE:
	choosetwoturnanim BideSetUp, BideUnleash
	end
BideSetUp:
	loopsewithpan SE_W036, -64, 0x9, 2
	createvisualtask sub_8115A04, 2, 2, 2, 2, 0, 11, RGB_RED
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 32, 1
	waitforvisualfinish
	end

BideUnleash:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	loopsewithpan SE_W036, -64, 0x9, 2
	createvisualtask sub_8116620, 10, 2, 2, 0, 11, RGB_RED
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 32, 1
	waitforvisualfinish
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, 24, 0, 0, 4
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_ATTACKER, 2, 0, 12, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 16, 1
	playsewithpan SE_W004, +63
	createsprite gBasicHitSplatSpriteTemplate, 1, 18, -8, 1, 1
	delay 5
	playsewithpan SE_W004, +63
	createsprite gBasicHitSplatSpriteTemplate, 1, -18, 8, 1, 1
	delay 5
	playsewithpan SE_W004, +63
	createsprite gBasicHitSplatSpriteTemplate, 1, -8, -5, 1, 1
	waitforvisualfinish
	delay 5
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 7
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 2, 2, 11, 0, RGB_RED
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_STRING_SHOT:
	loadspritegfx 0x27C3
	loadspritegfx 0x27C4
	monbg ANIM_DEF_PARTNER
	delay 0
	createsprite gSimplePaletteBlendSpriteTemplate, 5, 1, 2, 0, 9, RGB_BLACK
	waitforvisualfinish
	loopsewithpan SE_W081, -64, 0x9, 6
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	call StringShot1
	waitforvisualfinish
	playsewithpan SE_W081B, +63
	createsprite gUnknown_085969F8, 130, 0, 10
	delay 4
	createsprite gUnknown_085969F8, 130, 0, -2
	delay 4
	createsprite gUnknown_085969F8, 130, 0, 22
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	delay 1
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 5, 1, 2, 9, 0, RGB_BLACK
	end

StringShot1:
	createsprite gUnknown_085969E0, 130, 20, 0, 512, 20, 1
	delay 1
	return

Move_SPIDER_WEB:
	loadspritegfx 0x27C5
	loadspritegfx 0x27C4
	monbg ANIM_DEF_PARTNER
	delay 0
	createsprite gSimplePaletteBlendSpriteTemplate, 5, 1, 2, 0, 9, RGB_BLACK
	waitforvisualfinish
	monbgprio_28 ANIM_TARGET
	loopsewithpan SE_W081, -64, 0x9, 6
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	call SpiderWeb1
	waitforvisualfinish
	playsewithpan SE_W081B, +63
	createsprite gUnknown_08596A2C, 2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, 5, 1, 2, 9, 0, RGB_BLACK
	end

SpiderWeb1:
	createsprite gUnknown_085969E0, 130, 20, 0, 512, 20, 0
	delay 1
	return

Move_RAZOR_WIND:
	choosetwoturnanim RazorWindSetUp, RazorWindUnleash
RazorWindContinue:
	waitforvisualfinish
	end

RazorWindSetUp:
	loadspritegfx 0x2719
	playsewithpan SE_W016, -64
	createsprite gUnknown_08593550, 2, 32, 0, 16, 16, 0, 7, 40
	createsprite gUnknown_08593550, 2, 32, 0, 16, 16, 85, 7, 40
	createsprite gUnknown_08593550, 2, 32, 0, 16, 16, 170, 7, 40
	waitforvisualfinish
	playsewithpan SE_W016B, -64
	goto RazorWindContinue

RazorWindUnleash:
	loadspritegfx 0x27AA
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W013B, -64
	createsprite gUnknown_085962D4, 2, 14, 8, 0, 0, 22, 2, 1
	delay 2
	playsewithpan SE_W013B, -64
	createsprite gUnknown_085962D4, 2, 14, -8, 16, 14, 22, 1, 1
	delay 2
	playsewithpan SE_W013B, -64
	createsprite gUnknown_085962D4, 2, 14, 12, -16, -14, 22, 0, 1
	delay 17
	playsewithpan SE_W013, +63
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 10, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 2, 0, 10, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	goto RazorWindContinue

Move_DISABLE:
	loadspritegfx 0x2757
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 8, 8
	playsewithpan SE_W197, -64
	createsprite gUnknown_0853EE84, 0xD, 24, -16
	waitforvisualfinish
	createvisualtask sub_81045B0, 5
	loopsewithpan SE_W020, +63, 15, 4
	waitforvisualfinish
	delay 1
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_RECOVER:
	loadspritegfx 0x27A3
	loadspritegfx ANIM_TAG_031
	monbg ANIM_ATK_PARTNER
	setalpha 12, 8
	loopsewithpan SE_W025, -64, 0xD, 3
	createvisualtask sub_8115A04, 2, 2, 0, 6, 0, 11, RGB(31, 31, 11)
	call Recover1
	call Recover1
	call Recover1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	delay 1
	call HealingEffect
	waitforvisualfinish
	end

Recover1:
	createsprite gUnknown_085921E0, 2, 40, -10, 13
	delay 3
	createsprite gUnknown_085921E0, 2, -35, -10, 13
	delay 3
	createsprite gUnknown_085921E0, 2, 15, -40, 13
	delay 3
	createsprite gUnknown_085921E0, 2, -10, -32, 13
	delay 3
	createsprite gUnknown_085921E0, 2, 25, -20, 13
	delay 3
	createsprite gUnknown_085921E0, 2, -40, -20, 13
	delay 3
	createsprite gUnknown_085921E0, 2, 5, -40, 13
	delay 3
	return

Move_MIMIC:
	loadspritegfx 0x27A3
	setalpha 11, 5
	monbg_22 ANIM_DEF_PARTNER
	monbgprio_29
	panse_1B SE_W107, +63, -64, -3, 0
	createvisualtask sub_80FF458, 5, 128, 24
	delay 15
	createsprite gUnknown_085924DC, 130, -12, 24
	delay 10
	setarg 7, 0xFFFF
	waitforvisualfinish
	playsewithpan SE_W036, -64
	createvisualtask sub_8115A04, 2, 2, 0, 2, 0, 11, RGB_WHITE
	waitforvisualfinish
	clearmonbg_23 ANIM_DEF_PARTNER
	blendoff
	end

Move_CONSTRICT:
	loadspritegfx 0x27CA
	loopsewithpan SE_W010, +63, 6, 4
	createsprite gUnknown_08592494, 132, 0, 16, 0, 2
	delay 7
	createsprite gUnknown_08592494, 131, 0, 0, 0, 2
	createsprite gUnknown_08592494, 130, 0, 8, 1, 2
	delay 7
	createsprite gUnknown_08592494, 131, 0, -8, 1, 2
	delay 8
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 6, 1
	delay 20
	playsewithpan SE_W020, +63
	setarg 7, 0xFFFF
	waitforvisualfinish
	end

Move_CURSE:
	choosetwoturnanim CurseGhost, CurseStats
CurseGhost:
	loadspritegfx 0x27D7
	loadspritegfx 0x27D8
	monbg ANIM_ATK_PARTNER
	createvisualtask sub_8112758, 5
	waitforvisualfinish
	delay 20
	createsprite gUnknown_08596DD0, 2
	delay 60
	call CurseGhost1
	delay 0x29
	call CurseGhost1
	delay 0x29
	call CurseGhost1
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	delay 1
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W171, +63
	createsprite gBattleAnimSpriteTemplate_8596DE8, 130
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 14, 1
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 16, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end
CurseGhost1:
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 4, 0, 10, 0
	playsewithpan SE_W020, -64
	return
CurseStats:
	createvisualtask AnimTask_SwayMon, 5, 0, 10, 1536, 3, ANIM_ATTACKER
	waitforvisualfinish
	delay 10
	call CurseStats1
	waitforvisualfinish
	end
CurseStats1:
	playsewithpan SE_W082, -64
	createvisualtask sub_8116B14, 5
	createvisualtask sub_8115A04, 5, 2, 4, 2, 0, 10, RGB_RED
	return

Move_SOFT_BOILED:
	loadspritegfx 0x27DA
	loadspritegfx ANIM_TAG_203
	loadspritegfx ANIM_TAG_031
	monbg ANIM_ATK_PARTNER
	playsewithpan SE_W039, -64
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATTACKER, 0, 2, 6, 1
	createsprite gUnknown_085937B0, 4, 0, 16, 0
	createsprite gUnknown_085937B0, 4, 0, 16, 1
	delay 120
	delay 7
	playsewithpan SE_W030, -64
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 31, 3, 10, 0, RGB(12, 24, 30)
	createsprite gUnknown_0859381C, 3, 31, 16, 0, 1
	delay 8
	createsprite gUnknown_0859381C, 3, 31, 16, 0, 1
	delay 60
	setarg 7, 0xFFFF
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	call HealingEffect2
	end

Move_HEAL_BELL:
	loadspritegfx ANIM_TAG_205
	loadspritegfx ANIM_TAG_206
	loadspritegfx ANIM_TAG_203
	createvisualtask sub_8116620, 10, 10, 0, 0, 10, RGB_WHITE
	waitforvisualfinish
	createvisualtask sub_8105CB4, 5
	createsprite gUnknown_08593938, 2, 0, -24, 0, 1
	delay 12
	createsprite gUnknown_08593958, 0x28, 0, -24, 48, -18, 35, 0, 0
	createsprite gUnknown_08593958, 0x28, 0, -24, -48, 20, 30, 1, 1
	createsprite gUnknown_08593958, 0x28, 0, -24, -38, -29, 30, 2, 2
	createsprite gUnknown_08593958, 0x28, 0, -24, 36, 18, 30, 3, 3
	call HealBell1
	delay 0x21
	createsprite gUnknown_08593958, 0x28, 0, -24, 19, 26, 35, 4, 4
	createsprite gUnknown_08593958, 0x28, 0, -24, -34, -12, 30, 5, 5
	createsprite gUnknown_08593958, 0x28, 0, -24, 41, -20, 34, 6, 2
	createsprite gUnknown_08593958, 0x28, 0, -24, -15, 26, 32, 7, 0
	call HealBell1
	delay 0x21
	createsprite gUnknown_08593958, 0x28, 0, -24, -48, 18, 31, 0, 2
	createsprite gUnknown_08593958, 0x28, 0, -24, 48, -20, 30, 2, 5
	createsprite gUnknown_08593958, 0x28, 0, -24, 38, 29, 33, 4, 3
	createsprite gUnknown_08593958, 0x28, 0, -24, -36, -18, 30, 6, 1
	call HealBell1
	waitforvisualfinish
	createvisualtask sub_8105D60, 5
	waitforvisualfinish
	unloadspritegfx ANIM_TAG_205
	unloadspritegfx ANIM_TAG_206
	unloadspritegfx ANIM_TAG_203
	loadspritegfx ANIM_TAG_049
	playsewithpan SE_W234, -64
	createsprite gUnknown_08592B94, 16, -15, 0, 0, 0, 32, 60, 1
	delay 8
	createsprite gUnknown_08592B94, 16, 12, -5, 0, 0, 32, 60, 1
	waitforvisualfinish
	unloadspritegfx ANIM_TAG_049
	loadspritegfx ANIM_TAG_203
	playsewithpan SE_REAPOKE, -64
	createvisualtask sub_8116664, 10, 4, 3, 10, 0, 31500
	createvisualtask sub_8116620, 10, 10, 3, 10, 0, RGB_WHITE
	createsprite gUnknown_08593868, 16, 0, 0, 0, 1
	end
HealBell1:
	createvisualtask sub_8116664, 10, 4, 3, 8, 0, 31500
	createvisualtask sub_8116620, 10, 10, 3, 2, 10, RGB_WHITE
	createsprite gUnknown_0859381C, 0x28, 0, -24, 0, 1
	playsewithpan SE_W215, -64
	return

Move_FAKE_OUT:
	playsewithpan SE_W260, 0
	createvisualtask sub_8105EB0, 5
	waitforvisualfinish
	playsewithpan SE_W166, +63
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 5, 1
	createvisualtask sub_8106020, 3
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 3, 16, 0, RGB_WHITE
	end

Move_SCARY_FACE:
	loadspritegfx 0x27EA
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 27, 3, 0, 16, RGB_BLACK
	playsewithpan SE_W060, -64
	waitforvisualfinish
	delay 10
	playsewithpan SE_W043, -64
	createvisualtask sub_81064F8, 5
	delay 0xD
	createsprite gUnknown_08593A84, 0, -16, -8
	createsprite gUnknown_08593A84, 0, 16, -8
	waitforvisualfinish
	createvisualtask sub_810A094, 3, 20, 1, 0
	playsewithpan SE_W081B, +63
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 27, 3, 16, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_SWEET_KISS:
	loadspritegfx 0x27E8
	loadspritegfx 0x27EC
	createsprite gUnknown_08593AA8, 130, 16, -48
	playsewithpan SE_W215, +63
	delay 0x17
	playsewithpan SE_W215, +63
	delay 0x17
	playsewithpan SE_W215, +63
	waitforvisualfinish
	createsprite gBattleAnimSpriteTemplate_85939B8, 131, 160, -30
	playsewithpan SE_W213, +63
	createsprite gBattleAnimSpriteTemplate_85939B8, 131, -256, -42
	createsprite gBattleAnimSpriteTemplate_85939B8, 131, 128, -14
	createsprite gBattleAnimSpriteTemplate_85939B8, 131, 416, -38
	createsprite gBattleAnimSpriteTemplate_85939B8, 131, -128, -22
	createsprite gBattleAnimSpriteTemplate_85939B8, 131, -384, -31
	end

Move_LOVELY_KISS:
	loadspritegfx 0x27EB
	loadspritegfx 0x27ED
	createsprite gUnknown_08593AF0, 130, 0, -24
	playsewithpan SE_W060B, +63
	waitforvisualfinish
	playsewithpan SE_W213, +63
	createsprite gUnknown_08593AC0, 131, -256, -42
	createsprite gUnknown_08593AC0, 131, 128, -14
	createsprite gUnknown_08593AC0, 131, 416, -38
	createsprite gUnknown_08593AC0, 131, -128, -22
	end

Move_FURY_SWIPES:
	loadspritegfx 0x27EE
	createsprite gHorizontalLungeSpriteTemplate, 2, 5, 5
	delay 4
	playsewithpan SE_W010, +63
	createsprite gUnknown_08593B38, 130, 16, 0, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 5, 1
	delay 10
	createsprite gHorizontalLungeSpriteTemplate, 130, 5, 5
	delay 4
	playsewithpan SE_W010, +63
	createsprite gUnknown_08593B38, 130, -16, 0, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 7, 1
	end

Move_INGRAIN:
	loadspritegfx 0x27EF
	loadspritegfx 0x27A3
	createsprite gUnknown_0859254C, 2, 16, 26, -1, 2, 150
	playsewithpan SE_W010, -64
	delay 10
	createsprite gUnknown_0859254C, 2, -32, 20, 1, 1, 140
	playsewithpan SE_W010, -64
	delay 10
	createsprite gUnknown_0859254C, 2, 32, 22, 1, 0, 130
	playsewithpan SE_W010, -64
	delay 10
	createsprite gUnknown_0859254C, 2, -16, 25, -1, 3, 120
	playsewithpan SE_W010, -64
	delay 0x28
	createsprite gUnknown_0859258C, 3, 32, 26, -1, 3, 30
	delay 5
	playsewithpan SE_W145C, -64
	delay 5
	createsprite gUnknown_0859258C, 3, -48, 20, 1, 2, 30
	playsewithpan SE_W145C, -64
	delay 5
	playsewithpan SE_W145C, -64
	delay 5
	createsprite gUnknown_0859258C, 3, 48, 26, -2, 3, 18
	playsewithpan SE_W145C, -64
	delay 10
	waitforvisualfinish
	end

Move_PRESENT:
	loadspritegfx 0x27F0
	createvisualtask AnimTask_IsHealingMove, 2
	createsprite gUnknown_08592610, 130, 0, -5, 10, 2, -1
	playsewithpan SE_W039, -64
	delay 14
	playsewithpan SE_W145B, -64
	delay 14
	playsewithpan SE_W145B, 0
	delay 20
	playsewithpan SE_W145B, +63
	waitforvisualfinish
	jumpretfalse PresentDamage
	jumprettrue PresentHeal
	end

PresentDamage:
	loadspritegfx 0x27D6
	playsewithpan SE_W120, +63
	createsprite gBattleAnimSpriteTemplate_859371C, 131, 0, 0, 1, 1
	delay 6
	playsewithpan SE_W120, +63
	createsprite gBattleAnimSpriteTemplate_859371C, 131, 24, -24, 1, 1
	delay 6
	playsewithpan SE_W120, +63
	createsprite gBattleAnimSpriteTemplate_859371C, 131, -16, 16, 1, 1
	delay 6
	playsewithpan SE_W120, +63
	createsprite gBattleAnimSpriteTemplate_859371C, 131, -24, -12, 1, 1
	delay 6
	playsewithpan SE_W120, +63
	createsprite gBattleAnimSpriteTemplate_859371C, 131, 16, 16, 1, 1
	end

PresentHeal:
	loadspritegfx 0x27D3
	loadspritegfx ANIM_TAG_031
	playsewithpan SE_W234, +63
	createsprite gUnknown_08592658, 132, -16, 32, -3, 1
	delay 3
	createsprite gUnknown_08592658, 132, 16, 32, -3, -1
	delay 3
	createsprite gUnknown_08592658, 132, 32, 32, -3, 1
	delay 3
	createsprite gUnknown_08592658, 132, -32, 32, -3, 1
	delay 3
	createsprite gUnknown_08592658, 132, 0, 32, -3, 1
	delay 3
	createsprite gUnknown_08592658, 132, -8, 32, -3, 1
	delay 3
	createsprite gUnknown_08592658, 132, -8, 32, -3, 1
	delay 3
	createsprite gUnknown_08592658, 132, 24, 32, -3, 1
	delay 3
	createsprite gUnknown_08592658, 132, -24, 32, -3, 1
	waitforvisualfinish
	waitsound
	call HealingEffect2
	end

Move_BATON_PASS:
	loadspritegfx 0x27F2
	playsewithpan SE_W226, -64
	createvisualtask sub_8115A04, 2, 31, 1, 2, 0, 11, RGB(31, 22, 30)
	createsprite gUnknown_085CE370, 2
	end

Move_PERISH_SONG:
	loadspritegfx ANIM_TAG_206
	createsprite gUnknown_08593C0C, 4, 0, 0, 0
	createsprite gUnknown_08593C0C, 4, 1, 1, 16
	createsprite gUnknown_08593C0C, 4, 2, 1, 32
	createsprite gUnknown_08593C0C, 4, 3, 2, 48
	createsprite gUnknown_08593C0C, 4, 4, 2, 64
	createsprite gUnknown_08593C0C, 4, 5, 0, 80
	createsprite gUnknown_08593C0C, 4, 6, 0, 96
	createsprite gUnknown_08593C0C, 4, 7, 1, 112
	createsprite gUnknown_08593C0C, 4, 8, 2, 128
	createsprite gUnknown_08593C0C, 4, 9, 0, 144
	createsprite gUnknown_08593C0C, 4, 10, 2, 160
	createsprite gUnknown_08593C0C, 4, 11, 0, 176
	createsprite gUnknown_08593C0C, 4, 12, 1, 192
	createsprite gUnknown_08593C0C, 4, 13, 3, 208
	createsprite gUnknown_08593C0C, 4, 14, 3, 224
	createsprite gUnknown_08593C0C, 4, 15, 0, 240
	createsprite gUnknown_08593C24, 4, 15, 0, 0
	delay 20
	panse_1B SE_W195, -64, +63, +2, 0
	delay 0x50
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 3, 0, 16, RGB_BLACK
	createvisualtask sub_811489C, 5, 4, 0
	createvisualtask sub_811489C, 5, 5, 0
	createvisualtask sub_811489C, 5, 6, 0
	createvisualtask sub_811489C, 5, 7, 0
	delay 0x64
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 3, 16, 0, RGB_BLACK
	createvisualtask sub_811489C, 5, 4, 1
	createvisualtask sub_811489C, 5, 5, 1
	createvisualtask sub_811489C, 5, 6, 1
	createvisualtask sub_811489C, 5, 7, 1
	waitforvisualfinish
	end

Move_SLEEP_TALK:
	loadspritegfx 0x27F4
	createvisualtask AnimTask_SwayMon, 5, 0, 4, 4096, 2, ANIM_ATTACKER
	delay 20
	createsprite gUnknown_085CE190, 130, 0, 20, 5, -1
	playsewithpan SE_W173, -64
	delay 6
	createsprite gUnknown_085CE190, 130, 0, 20, 5, -1
	delay 6
	createsprite gUnknown_085CE190, 130, 0, 20, 5, -1
	delay 20
	createsprite gUnknown_085CE190, 130, 0, 20, 5, -5
	playsewithpan SE_W173, -64
	delay 6
	createsprite gUnknown_085CE190, 130, 0, 20, 5, -5
	delay 6
	createsprite gUnknown_085CE190, 130, 0, 20, 5, -5
	delay 20
	createsprite gUnknown_085CE190, 130, 0, 20, 5, -3
	playsewithpan SE_W173, -64
	delay 6
	createsprite gUnknown_085CE190, 130, 0, 20, 5, -3
	delay 6
	createsprite gUnknown_085CE190, 130, 0, 20, 5, -3
	waitforvisualfinish
	end

Move_HYPER_FANG:
	loadspritegfx 0x27D0
	playsewithpan SE_W044, +63
	delay 1
	delay 2
	createvisualtask AnimTask_IsContest, 2
	jumprettrue HyperFangInContest
	createvisualtask AnimTask_IsTargetPlayerSide, 2
	jumpretfalse HyperFangOnOpponent
	goto HyperFangOnPlayer
HyperFangContinue:
	waitbgfadeout
	createsprite gUnknown_085CE1DC, 130
	waitbgfadein
	createvisualtask AnimTask_ShakeMon, 3, ANIM_TARGET, 0, 10, 10, 1
	playsewithpan SE_W043, +63
	delay 20
	restorebg
	waitbgfadein
	waitforvisualfinish
	end

HyperFangOnOpponent:
	fadetobg BG_IMPACT_OPPONENT
	goto HyperFangContinue

HyperFangOnPlayer:
	fadetobg BG_IMPACT_PLAYER
	goto HyperFangContinue

HyperFangInContest:
	fadetobg BG_IMPACT_CONTESTS
	goto HyperFangContinue

Move_TRI_ATTACK:
	loadspritegfx 0x27F6
	createsprite gUnknown_085CE2F8, 130, 16, 0
	playsewithpan SE_W161, -64
	delay 20
	playsewithpan SE_W161, -64
	delay 20
	createsoundtask sub_8158C58, 220, -64, 63, 5, 6, 0, 7
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 0, 16, RGB_BLACK
	delay 16
	loadspritegfx 0x2731
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, -1, 0
	playsewithpan SE_W172B, +63
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, 0, 1
	delay 1
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, -1, -1
	delay 1
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, 2, 1
	delay 1
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, 1, -1
	delay 1
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, -1, 1
	delay 1
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, 1, -2
	delay 1
	createsprite gUnknown_08595410, 130, 0, 0, 30, 30, 3, 1
	delay 2
	createvisualtask sub_810A094, 2, 20, 3, 1, 1
	waitforvisualfinish
	loadspritegfx 0x2735
	createvisualtask sub_8115F10, 2, 257, 257, 257
	playsewithpan SE_W161B, +63
	createsprite gUnknown_085956C0, 130, 0, -48
	delay 1
	createsprite gUnknown_085956C0, 130, 0, -16
	delay 1
	createsprite gUnknown_085956C0, 130, 0, 16
	delay 20
	createvisualtask sub_810A094, 2, 20, 3, 1, 0
	delay 2
	createvisualtask sub_8115F10, 2, 257, 257, 257
	waitforvisualfinish
	loadspritegfx ANIM_TAG_141
	call FreezeEffect1
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 16, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_WILL_O_WISP:
	loadspritegfx 0x27F8
	loadspritegfx 0x27F7
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	playsewithpan SE_W052, -64
	waitplaysewithpan SE_W052, -64, 10
	createvisualtask sub_8159278, 2, -64, -64, 1, 0
	createsprite gUnknown_0859563C, 2, 0, 0, 0
	delay 3
	createsprite gUnknown_0859563C, 3, 0, 0, 1
	delay 3
	createsprite gUnknown_0859563C, 4, 0, 0, 2
	delay 3
	createsprite gUnknown_0859563C, 4, 0, 0, 3
	delay 0x28
	createvisualtask sub_8159278, 2, -64, 63, 2, 0
	waitforvisualfinish
	monbgprio_29
	playsewithpan SE_W172B, +63
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 13, 1
	createsprite gUnknown_0859566C, 2, 0
	createsprite gUnknown_0859566C, 2, 42
	createsprite gUnknown_0859566C, 2, 84
	createsprite gUnknown_0859566C, 2, 126
	createsprite gUnknown_0859566C, 2, 168
	createsprite gUnknown_0859566C, 2, 210
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_ENCORE:
	loadspritegfx 0x27F3
	loadspritegfx 0x2807
	createvisualtask sub_815ABEC, 2
	createvisualtask sub_8116960, 2, 248, 3, 0, 10, 0
	waitforvisualfinish
	createsprite gUnknown_085CE22C, 130, 0, -8
	createsprite gUnknown_085CE244, 2, -2, 0, 0, 0, 9
	createsprite gUnknown_085CE244, 2, 2, 0, 1, 0, 9
	createsprite gUnknown_085CE25C, 3, -2, 0, 0, 0, 9
	createsprite gUnknown_085CE25C, 3, 2, 0, 1, 0, 9
	delay 16
	createvisualtask sub_8159244, 5, 223, 63
	createvisualtask AnimTask_SwayMon, 5, 1, 8, 1536, 5, ANIM_TARGET
	waitforvisualfinish
	createvisualtask sub_8116960, 2, 248, 3, 10, 0, 1
	waitforvisualfinish
	createvisualtask sub_815AC8C, 2
	end

Move_TRICK:
	loadspritegfx 0x27F0
	loadspritegfx 0x27DF
	createsprite gUnknown_085926E8, 2, -40, 80
	createsprite gUnknown_085926E8, 2, -40, 208
	delay 16
	playsewithpan SE_W166, 0
	createvisualtask sub_8106020, 3
	createvisualtask sub_81060B0, 3
	delay 30
	playsewithpan SE_W104, 0
	delay 24
	playsewithpan SE_W104, 0
	delay 16
	playsewithpan SE_W104, 0
	delay 16
	playsewithpan SE_W104, 0
	delay 16
	playsewithpan SE_W104, 0
	delay 16
	playsewithpan SE_W104, 0
	delay 16
	playsewithpan SE_W213, 0
	createvisualtask AnimTask_ShakeMon, 3, ANIM_ATTACKER, 5, 0, 7, 2
	createvisualtask AnimTask_ShakeMon, 3, ANIM_TARGET, 5, 0, 7, 2
	waitforvisualfinish
	end

Move_WISH:
	loadspritegfx 0x27F9
	loadspritegfx ANIM_TAG_049
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 3, 0, 10, RGB_BLACK
	waitforvisualfinish
	panse_27 SE_W115, +63, -64, -3, 0
	createsprite gUnknown_085CE388, 0x28
	waitforvisualfinish
	delay 60
	loopsewithpan SE_W215, -64, 16, 3
	call GrantingStarsEffect
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 3, 10, 0, RGB_BLACK
	waitforvisualfinish
	end

Move_STOCKPILE:
	loadspritegfx 0x27FB
	playsewithpan SE_W025, -64
	createvisualtask sub_8115A04, 2, 2, 8, 1, 0, 12, RGB_WHITE
	createvisualtask sub_815B65C, 5
	call Stockpile1
	call Stockpile1
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 2, 0, 12, 0, RGB_WHITE
	end
Stockpile1:
	createsprite gUnknown_08592244, 2, 55, 55, 13
	delay 1
	createsprite gUnknown_08592244, 2, -55, -55, 13
	delay 1
	createsprite gUnknown_08592244, 2, 0, 55, 13
	delay 1
	createsprite gUnknown_08592244, 2, 0, -55, 13
	delay 1
	createsprite gUnknown_08592244, 2, 55, -34, 13
	delay 1
	createsprite gUnknown_08592244, 2, 55, 34, 13
	delay 1
	createsprite gUnknown_08592244, 2, -55, -34, 13
	delay 1
	createsprite gUnknown_08592244, 2, -55, 34, 13
	delay 1
	return

Move_SPIT_UP:
	loadspritegfx 0x27FD
	loadspritegfx ANIM_TAG_135
	playsewithpan SE_W036, -64
	createvisualtask sub_815B6B4, 5
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 8, 2
	delay 0x2D
	playsewithpan SE_W255, -64
	delay 3
	createsprite gUnknown_08593A50, 2, 0, 12
	createsprite gUnknown_08593A50, 2, 32, 12
	createsprite gUnknown_08593A50, 2, 64, 12
	createsprite gUnknown_08593A50, 2, 96, 12
	createsprite gUnknown_08593A50, 2, 128, 12
	createsprite gUnknown_08593A50, 2, 160, 12
	createsprite gUnknown_08593A50, 2, 192, 12
	createsprite gUnknown_08593A50, 2, 224, 12
	delay 5
	jumpifmoveturn 2, SpitUpStrong
	jumpifmoveturn 3, SpitUpStrongest
SpitUpContinue:
	delay 5
	createvisualtask sub_80D6388, 2, 0, 1, 8, 1, 0
	playsewithpan SE_W003, +63
	createsprite gUnknown_085973E8, 131, -12, 10, 1, 1
	delay 5
	playsewithpan SE_W003, +63
	createsprite gUnknown_085973E8, 131, 12, -10, 1, 1
	waitforvisualfinish
	end
SpitUpStrong:
	createsprite gUnknown_08593A50, 2, 16
	createsprite gUnknown_08593A50, 2, 80
	createsprite gUnknown_08593A50, 2, 144
	createsprite gUnknown_08593A50, 2, 208
	goto SpitUpContinue
SpitUpStrongest:
	createsprite gUnknown_08593A50, 2, 16
	createsprite gUnknown_08593A50, 2, 48
	createsprite gUnknown_08593A50, 2, 80
	createsprite gUnknown_08593A50, 2, 112
	createsprite gUnknown_08593A50, 2, 144
	createsprite gUnknown_08593A50, 2, 176
	createsprite gUnknown_08593A50, 2, 208
	createsprite gUnknown_08593A50, 2, 240
	goto SpitUpContinue

Move_SWALLOW:
	loadspritegfx 0x27FC
	loadspritegfx ANIM_TAG_031
	playsewithpan SE_W036, -64
	createvisualtask sub_815B778, 5
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 8, 2
	delay 0x26
	playsewithpan SE_W255, -64
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 2, 0, 12, 1
	call SwallowEffect
	jumpifmoveturn 2, SwallowGood
	jumpifmoveturn 3, SwallowBest
SwallowContinue:
	waitforvisualfinish
	call HealingEffect
	end
SwallowEffect:
	createsprite gUnknown_085CE418, 2, 0, -8
	delay 1
	createsprite gUnknown_085CE418, 2, -24, -8
	delay 1
	createsprite gUnknown_085CE418, 2, 16, -8
	delay 1
	createsprite gUnknown_085CE418, 2, -16, -8
	delay 1
	createsprite gUnknown_085CE418, 2, 24, -8
	delay 1
	return
SwallowGood:
	call SwallowEffect
	goto SwallowContinue
SwallowBest:
	call SwallowEffect
	call SwallowEffect
	goto SwallowContinue

Move_TRANSFORM:
	monbg ANIM_ATTACKER
	playsewithpan SE_W100, -64
	waitplaysewithpan SE_W107, -64, 48
	createvisualtask sub_815B7D0, 2, 0
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	end

Move_MORNING_SUN:
	loadspritegfx 0x2801
	loadspritegfx ANIM_TAG_031
	createvisualtask sub_815BB84, 5
	delay 8
	createvisualtask sub_8116620, 10, 0x781, 8, 0, 12, RGB_WHITE
	delay 14
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	call MorningSun1
	createvisualtask sub_8116620, 10, 0x781, 3, 12, 0, RGB_WHITE
	waitforvisualfinish
	waitsound
	call HealingEffect
	end

MorningSun1:
	createsprite gUnknown_085CE48C, 2, 30, 640
	delay 5
	return

Move_SWEET_SCENT:
	loadspritegfx 0x27FE
	playsewithpan SE_W230, -64
	createsprite gUnknown_085CE544, 2, 100, 0, 100
	delay 25
	setpan 0
	call SweetScentEffect
	createsprite gUnknown_085CE544, 2, 55, 0
	setpan +63
	createvisualtask sub_8115A04, 2, 20, 1, 5, 5, 13, RGB(31, 21, 21)
	call SweetScentEffect
	waitforvisualfinish
	end

SweetScentEffect:
	createsprite gUnknown_085CE544, 2, 70, 1, 64
	delay 2
	createsprite gUnknown_085CE544, 2, 60, 0, 64
	delay 5
	createsprite gUnknown_085CE544, 2, 80, 1, 64
	delay 2
	createsprite gUnknown_085CE544, 2, 58, 0, 120
	delay 2
	createsprite gUnknown_085CE544, 2, 100, 0, 120
	delay 2
	createsprite gUnknown_085CE544, 2, 90, 0, 64
	delay 2
	createsprite gUnknown_085CE544, 2, 48, 0, 64
	delay 2
	createsprite gUnknown_085CE544, 2, 95, 1, 80
	delay 2
	createsprite gUnknown_085CE544, 2, 100, 0, 120
	delay 2
	createsprite gUnknown_085CE544, 2, 75, 1, 64
	delay 2
	createsprite gUnknown_085CE544, 2, 85, 0, 120
	delay 2
	return

Move_HYPER_BEAM:
	loadspritegfx 0x27A3
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 4, 0, 16, RGB_BLACK
	waitforvisualfinish
	delay 10
	playsewithpan SE_W063, -64
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 4, 1
	waitforvisualfinish
	delay 30
	createsoundtask sub_8158C58, 247, -64, 63, 1, 15, 0, 5
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATTACKER, 0, 4, 50, 1
	createvisualtask sub_8115D94, 2, 10147, 1, 12, 31, 16, 0, 0
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 50, 1
	createvisualtask sub_8116620, 10, 4, 2, 0, 11, RGB(25, 25, 25)
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	call HyperBeam1
	createvisualtask sub_8116620, 10, 4, 2, 11, 0, RGB(25, 25, 25)
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 4, 16, 0, RGB_BLACK
	end

HyperBeam1:
	createsprite gUnknown_08592288, 130
	createsprite gUnknown_08592288, 130
	delay 1
	return

Move_FLATTER:
	loadspritegfx 0x27F3
	loadspritegfx 0x2800
	createvisualtask sub_8159244, 5, 223, 63
	createvisualtask sub_815ABEC, 2
	createvisualtask sub_8116960, 2, 248, 3, 0, 10, 0
	waitforvisualfinish
	createsprite gUnknown_085CE5C0, 130, 0, -8, 80
	delay 0
	createsprite gVerticalDipSpriteTemplate, 2, 5, 2, ANIM_TARGET
	delay 10
	createsprite gVerticalDipSpriteTemplate, 2, 5, 2, ANIM_TARGET
	delay 0
	createvisualtask sub_8159210, 5, 229, -64
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	call Flatter1
	delay 5
	createvisualtask sub_8159210, 5, 229, 63
	waitforvisualfinish
	createvisualtask sub_8116960, 2, 248, 3, 10, 0, 1
	waitforvisualfinish
	createvisualtask sub_815AC8C, 2
	end

Flatter1:
	createsprite gUnknown_085CE5A8, 0x28, 0
	createsprite gUnknown_085CE5A8, 0x28, 1
	return

Move_ROLE_PLAY:
	monbg ANIM_ATK_PARTNER
	createvisualtask sub_8116620, 10, 4, 2, 0, 16, RGB_WHITE
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 0, 10, RGB_BLACK
	waitforvisualfinish
	playsewithpan SE_W161, -64
	waitplaysewithpan SE_W197, -64, 30
	createvisualtask sub_815CED8, 2
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	createvisualtask sub_8116620, 10, 4, 2, 16, 0, RGB_WHITE
	delay 8
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 2, 10, 0, RGB_BLACK
	end

Move_REFRESH:
	loadspritegfx ANIM_TAG_203
	loadspritegfx ANIM_TAG_049
	playsewithpan SE_W287, -64
	createvisualtask sub_815DFCC, 2, 0
	waitforvisualfinish
	playsewithpan SE_W234, -64
	call GrantingStarsEffect
	waitforvisualfinish
	playsewithpan SE_REAPOKE, -64
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 31, 3, 10, 0, RGB(12, 24, 30)
	createsprite gUnknown_0859381C, 3, 0, 0, 0, 0
	end

Move_BLAZE_KICK:
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	loadspritegfx 0x272D
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W172, +63
	createsprite gUnknown_08595F14, 131, 0, 0, 1, 30
	createvisualtask sub_8116620, 10, 4, 2, 0, 7, RGB_WHITE
	delay 30
	playsewithpan SE_W007, +63
	createsprite gBasicHitSplatSpriteTemplate, 130, 0, 0, 1, 0
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 14, 1
	createvisualtask sub_8116620, 10, 4, 2, 0, 0, RGB_WHITE
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 31, 3, 1, 0, 8, 0, 0
	call FireMoveEffect
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_HYPER_VOICE:
	loadspritegfx ANIM_TAG_203
	createvisualtask sub_81590B8, 5, 0
	call HyperVoiceEffect
	waitforvisualfinish
	delay 8
	createvisualtask sub_81590B8, 5, 1
	call HyperVoiceEffect
	waitforvisualfinish
	end

HyperVoiceEffect:
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 31, 3, 8, 0, RGB_YELLOW
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -5, -5, 5, ANIM_ATTACKER, 0
	createsprite gUnknown_08593880, 0, 45, 0, 0, 0, 0, 0, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 1, 0, 6, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_DEF_PARTNER, 1, 0, 6, 1
	createvisualtask sub_81162A4, 2, 1, 0, 6, 1
	createvisualtask sub_8159078, 5
	return

Move_SAND_TOMB:
	loadspritegfx ANIM_TAG_074
	createsprite gSimplePaletteBlendSpriteTemplate, 0, 4, 2, 0, 7, RGB(19, 17, 0)
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 2, 43, 1
	playsewithpan SE_W328, +63
	call SandTombEffect
	call SandTombEffect
	call SandTombEffect
	delay 0x16
	createsprite gSimplePaletteBlendSpriteTemplate, 0, 4, 2, 7, 0, RGB(19, 17, 0)
	waitforvisualfinish
	end

SandTombEffect:
	createsprite gUnknown_08596B34, 130, 0, 32, 528, 30, 10, 50, 1
	delay 2
	createsprite gUnknown_08596B34, 130, 0, 36, 480, 20, 13, -46, 1
	delay 2
	createsprite gUnknown_08596B34, 130, 0, 37, 576, 20, 5, 42, 1
	delay 2
	createsprite gUnknown_08596B34, 130, 0, 35, 400, 25, 8, -42, 1
	delay 2
	createsprite gUnknown_08596B34, 130, 0, 32, 512, 25, 13, 46, 1
	delay 2
	createsprite gUnknown_08596B34, 130, 0, 37, 464, 30, 12, -50, 1
	delay 2
	return

Move_SHEER_COLD:
	fadetobg BG_ICE
	waitbgfadeout
	playsewithpan SE_W196, 0
	waitbgfadein
	loadspritegfx 0x271A
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createvisualtask sub_80A9EF4, 2
	waitplaysewithpan SE_W258, +63, 17
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	restorebg
	waitbgfadein
	end

Move_ARM_THRUST:
	loadspritegfx ANIM_TAG_143
	loadspritegfx ANIM_TAG_135
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createvisualtask sub_80D6134, 5, 8, 5, 0, 0
	delay 6
	createsprite gHorizontalLungeSpriteTemplate, 2, 4, 3
	delay 4
	playsewithpan SE_W207, +63
	createsprite gUnknown_08596034, 130, 10, -8, 14, 3
	waitforvisualfinish
	createvisualtask sub_80D6134, 5, 8, 5, 0, 1
	playsewithpan SE_W003, +63
	choosetwoturnanim ArmThrustRight, ArmThrustLeft
ArmThrustContinue:
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 4, 0, 6, 1
	waitforvisualfinish
	blendoff
	end
ArmThrustRight:
	createsprite gBasicHitSplatSpriteTemplate, 130, 8, 0, 1, 2
	goto ArmThrustContinue
ArmThrustLeft:
	createsprite gBasicHitSplatSpriteTemplate, 130, -8, 0, 1, 2
	goto ArmThrustContinue

Move_MUDDY_WATER:
	panse_1B SE_W250, -64, +63, +2, 0
	createvisualtask sub_8107954, 2, 1
	waitforvisualfinish
	end

Move_BULLET_SEED:
	loadspritegfx 0x2716
	createsprite gUnknown_0859351C, 130, 20, 0
	delay 5
	createsprite gUnknown_0859351C, 130, 20, 0
	delay 5
	createsprite gUnknown_0859351C, 130, 20, 0
	delay 5
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 30, 1
	createsprite gUnknown_0859351C, 130, 20, 0
	delay 5
	createsprite gUnknown_0859351C, 130, 20, 0
	delay 5
	createsprite gUnknown_0859351C, 130, 20, 0
	delay 5
	createsprite gUnknown_0859351C, 130, 20, 0
	delay 5
	createsprite gUnknown_0859351C, 130, 20, 0
	delay 5
	createsprite gUnknown_0859351C, 130, 20, 0
	delay 5
	createsprite gUnknown_0859351C, 130, 20, 0
	waitforvisualfinish
	end

Move_DRAGON_CLAW:
	loadspritegfx 0x272D
	loadspritegfx ANIM_TAG_039
	playsewithpan SE_W221B, -64
	createvisualtask sub_8116620, 10, 2, 4, 0, 8, RGB(31, 19, 0)
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 0, 2, 15, 1
	call DragonClawEffect
	call DragonClawEffect
	createsprite gHorizontalLungeSpriteTemplate, 2, 6, 4
	createsprite gUnknown_08596B88, 2, 0, 28, 528, 30, 13, 50, 0
	delay 2
	createvisualtask sub_8159210, 5, 136, 63
	createsprite gBattleAnimSpriteTemplate_8597138, 130, -10, -10, 0
	createsprite gBattleAnimSpriteTemplate_8597138, 130, -10, 10, 0
	createsprite gBattleAnimSpriteTemplate_85972D8, 2, -4, 1, 10, 3, 1
	createsprite gUnknown_08596B88, 2, 0, 32, 480, 20, 16, -46, 0
	delay 2
	createsprite gUnknown_08596B88, 2, 0, 33, 576, 20, 8, 42, 0
	delay 2
	createsprite gUnknown_08596B88, 2, 0, 31, 400, 25, 11, -42, 0
	delay 2
	createsprite gHorizontalLungeSpriteTemplate, 2, 6, 4
	createsprite gUnknown_08596B88, 2, 0, 28, 512, 25, 16, 46, 0
	delay 2
	createvisualtask sub_8159210, 5, 136, 63
	createsprite gBattleAnimSpriteTemplate_8597138, 130, 10, -10, 1
	createsprite gBattleAnimSpriteTemplate_8597138, 130, 10, 10, 1
	createsprite gBattleAnimSpriteTemplate_85972D8, 2, -4, 1, 10, 3, 1
	createsprite gUnknown_08596B88, 2, 0, 33, 464, 30, 15, -50, 0
	delay 2
	createsprite gUnknown_08596B88, 2, 0, 28, 528, 30, 13, 50, 0
	delay 2
	createsprite gUnknown_08596B88, 2, 0, 32, 480, 20, 16, -46, 0
	delay 2
	createsprite gUnknown_08596B88, 2, 0, 33, 576, 20, 8, 42, 0
	delay 2
	createsprite gUnknown_08596B88, 2, 0, 31, 400, 25, 11, -42, 0
	delay 2
	createsprite gUnknown_08596B88, 2, 0, 28, 512, 25, 16, 46, 0
	delay 2
	createsprite gUnknown_08596B88, 2, 0, 33, 464, 30, 15, -50, 0
	createvisualtask sub_8116620, 10, 2, 4, 8, 0, RGB(31, 19, 0)
	waitforvisualfinish
	end

DragonClawEffect:
	createsprite gUnknown_08596B88, 2, 0, 28, 528, 30, 13, 50, 0
	delay 2
	createsprite gUnknown_08596B88, 2, 0, 32, 480, 20, 16, -46, 0
	delay 2
	createsprite gUnknown_08596B88, 2, 0, 33, 576, 20, 8, 42, 0
	delay 2
	createsprite gUnknown_08596B88, 2, 0, 31, 400, 25, 11, -42, 0
	delay 2
	createsprite gUnknown_08596B88, 2, 0, 28, 512, 25, 16, 46, 0
	delay 2
	createsprite gUnknown_08596B88, 2, 0, 33, 464, 30, 15, -50, 0
	delay 2
	return

End:
	end

Move_MUD_SHOT:
	loadspritegfx 0x2813
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 0, 2, 46, 1
	delay 6
	createvisualtask sub_81076C8, 5, 100
	panse_1B SE_W250, -64, +63, +1, 0
	call MudShot1
	call MudShot1
	call MudShot1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 43, 1
	call MudShot1
	call MudShot1
	call MudShot1
	call MudShot1
	call MudShot1
	call MudShot1
	call MudShot1
	call MudShot1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

MudShot1:
	createsprite gUnknown_085950FC, 3, 10, 10, 0, 16
	delay 2
	createsprite gUnknown_085950FC, 3, 10, 10, 0, 16
	delay 2
	return

Move_METEOR_MASH:
	loadspritegfx 0x27F9
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	panse_1B SE_W112, -64, +63, +3, 0
	fadetobg BG_COSMIC
	waitbgfadein
	waitforvisualfinish
	createsprite gUnknown_085CE8DC, 131, -48, -64, 72, 32, 30
	delay 10
	createsprite gUnknown_085CE8DC, 131, -112, -64, 8, 32, 30
	delay 0x28
	createsprite gUnknown_08595F14, 131, 0, 0, 0, 30
	createsprite gUnknown_085CE8DC, 131, -80, -64, 40, 32, 30
	delay 20
	playsewithpan SE_W233B, +63
	createsprite gBasicHitSplatSpriteTemplate, 131, 0, 0, 1, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 5, 0, 20, 1
	waitforvisualfinish
	delay 10
	restorebg
	waitbgfadein
	waitforvisualfinish
	end

Move_REVENGE:
	loadspritegfx 0x2805
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W036, -64
	createsprite gUnknown_08596088, 2, 10, -10
	waitforvisualfinish
	createvisualtask sub_8115A04, 2, 2, 0, 4, 2, 8, RGB_RED
	waitforvisualfinish
	unloadspritegfx 0x2805
	loadspritegfx 0x2806
	createsprite gHorizontalLungeSpriteTemplate, 2, 6, 4
	delay 4
	playsewithpan SE_W207, +63
	createsprite gUnknown_085960D0, 130, 10, -10
	waitforvisualfinish
	unloadspritegfx 0x2806
	loadspritegfx ANIM_TAG_135
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 3, 0, 10, 1
	createsprite gUnknown_08597400, 131, -10, -8, 1, 1, 8
	playsewithpan SE_W233B, +63
	delay 8
	createsprite gUnknown_08597400, 131, 10, 8, 1, 1, 8
	playsewithpan SE_W025B, +63
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_POISON_FANG:
	loadspritegfx 0x27D0
	loadspritegfx 0x27A6
	playsewithpan SE_W044, +63
	createsprite gUnknown_085CE1DC, 130
	delay 10
	createvisualtask AnimTask_ShakeMon, 3, ANIM_TARGET, 3, 0, 10, 1
	waitforvisualfinish
	createvisualtask sub_8115A04, 2, 4, 0, 4, 0, 12, RGB(26, 0, 26)
	call PoisonBubblesEffect
	waitforvisualfinish
	end

Move_SUBSTITUTE:
	playsewithpan SE_W213, -64
	createvisualtask sub_815F20C, 2
	end

Move_FRENZY_PLANT:
	loadspritegfx 0x27EF
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, 0, 1, 2, 0, 5, RGB_BLACK
	waitforvisualfinish
	createsprite gUnknown_08592564, 2, 10, 8, 2, 0, 0, 100
	playsewithpan SE_W010, -64
	delay 5
	createsprite gUnknown_08592564, 2, 20, -8, -2, 0, 1, 95
	playsewithpan SE_W010, -43
	delay 5
	createsprite gUnknown_08592564, 2, 30, 8, -4, 0, 0, 90
	playsewithpan SE_W010, -22
	delay 5
	createsprite gUnknown_08592564, 2, 40, -8, 4, 0, 1, 85
	playsewithpan SE_W010, 0
	delay 5
	createsprite gUnknown_08592564, 2, 50, 8, 0, 0, 0, 85
	playsewithpan SE_W010, +21
	delay 5
	createsprite gUnknown_08592564, 2, 60, -8, -2, 0, 1, 85
	playsewithpan SE_W010, +42
	delay 5
	createsprite gUnknown_08592564, 2, 75, 8, 0, 0, 0, 85
	playsewithpan SE_W010, +63
	delay 5
	createsprite gUnknown_08592564, 2, 85, 16, 6, 0, 3, 80
	playsewithpan SE_W010, +63
	delay 5
	createsprite gUnknown_08592564, 2, 85, -16, -6, 0, 2, 75
	playsewithpan SE_W010, +63
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, 2, -10, -10, 1, 3
	playsewithpan SE_W003, +63
	createvisualtask AnimTask_ShakeMon, 3, ANIM_TARGET, 8, 0, 20, 1
	delay 3
	createsprite gBasicHitSplatSpriteTemplate, 2, 10, 8, 1, 3
	playsewithpan SE_W003, +63
	delay 3
	createsprite gBasicHitSplatSpriteTemplate, 2, 10, -3, 1, 2
	playsewithpan SE_W003, +63
	delay 3
	createsprite gBasicHitSplatSpriteTemplate, 2, -3, 1, 1, 2
	playsewithpan SE_W003, +63
	delay 2
	createsprite gBasicHitSplatSpriteTemplate, 2, -10, 1, 1, 1
	playsewithpan SE_W003, +63
	delay 2
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 10, 1, 1
	playsewithpan SE_W003, +63
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 0, 1, 2, 5, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

Move_METAL_SOUND:
	loadspritegfx 0x2814
	monbg ANIM_DEF_PARTNER
	monbgprio_2A ANIM_TARGET
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 2, 0, 8, 1
	call MetalSound1
	call MetalSound1
	call MetalSound1
	call MetalSound1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	delay 0
	waitforvisualfinish
	end

MetalSound1:
	panse_1B SE_W103, -64, +63, +2, 0
	createsprite gUnknown_08593458, 130, 16, 0, 0, 0, 30, 0
	delay 2
	return

Move_FOCUS_PUNCH:
	goto FocusPunch

FocusPunchEnd:
	waitforvisualfinish
	end

FocusPunch:
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_143
	delay 1
	createvisualtask AnimTask_IsContest, 2
	jumprettrue FocusPunchInContest
	createvisualtask AnimTask_IsTargetPlayerSide, 2
	jumpretfalse FocusPunchOnOpponent
	jumprettrue FocusPunchOnPlayer
FocusPunchContinue:
	waitbgfadein
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W207, +63
	createsprite gUnknown_08596104, 130
	delay 10
	createsprite gBasicHitSplatSpriteTemplate, 2, -10, -8, 1, 0
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 8, 0, 24, 1
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, 2, 10, 2, 1, 0
	playsewithpan SE_W233B, +63
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, 2, 10, -6, 1, 0
	playsewithpan SE_W233B, +63
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 8, 1, 0
	playsewithpan SE_W025B, +63
	waitforvisualfinish
	restorebg
	waitbgfadein
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto FocusPunchEnd

FocusPunchOnOpponent:
	fadetobg BG_IMPACT_OPPONENT
	goto FocusPunchContinue

FocusPunchOnPlayer:
	fadetobg BG_IMPACT_PLAYER
	goto FocusPunchContinue

FocusPunchInContest:
	fadetobg BG_IMPACT_CONTESTS
	goto FocusPunchContinue

Move_RETURN:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createvisualtask AnimTask_GetReturnPowerLevel, 2
	delay 2
	jumpreteq 0, ReturnWeak
	jumpreteq 1, ReturnMedium
	jumpreteq 2, ReturnStrong
	jumpreteq 3, ReturnStrongest
ReturnContinue:
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
ReturnWeak:
	createsprite gVerticalDipSpriteTemplate, 2, 16, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, -64
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, 2, 16, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, -64
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, 2, -10, -8, 1, 2
	createvisualtask sub_8159210, 5, 139, 63
	goto ReturnContinue
ReturnMedium:
	createsprite gVerticalDipSpriteTemplate, 2, 6, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, -64
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, 2, 6, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, -64
	waitforvisualfinish
	delay 11
	createsprite gHorizontalLungeSpriteTemplate, 2, 5, 4
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, 3, 0, 0, 1, 2
	createvisualtask sub_8159210, 5, 141, 63
	goto ReturnContinue
ReturnStrong:
	createsprite gVerticalDipSpriteTemplate, 2, 6, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, -64
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, 2, 6, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, -64
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, 2, 6, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, -64
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, 2, 6, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, -64
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, 2, -10, -8, 1, 2
	createvisualtask sub_8159210, 5, 123, 63
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, 2, 10, 10, 1, 2
	createvisualtask sub_8159210, 5, 123, 63
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, 2, 3, -5, 1, 2
	createvisualtask sub_8159210, 5, 123, 63
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, 2, -5, 3, 1, 2
	createvisualtask sub_8159210, 5, 123, 63
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	goto ReturnContinue
ReturnStrongest:
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 0, 0, 6, RGB_BLACK
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, 2, 16, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, -64
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, 2, 3, -5, 1, 2
	createvisualtask sub_8159210, 5, 123, 63
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, 2, 12, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, -64
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, 2, -10, -8, 1, 2
	createvisualtask sub_8159210, 5, 123, 63
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	waitforvisualfinish
	delay 4
	createsprite gVerticalDipSpriteTemplate, 2, 8, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, -64
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, 2, -10, -8, 1, 2
	createvisualtask sub_8159210, 5, 123, 63
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	waitforvisualfinish
	delay 2
	createvisualtask sub_81169C0, 2, 0, 4, 5, 1
	createsprite gVerticalDipSpriteTemplate, 2, 4, 1, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, -64
	createsprite gBasicHitSplatSpriteTemplate, 2, -10, -8, 1, 2
	createvisualtask sub_8159210, 5, 123, 63
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	createvisualtask sub_81169C0, 2, 0, 4, 5, 1
	waitforvisualfinish
	createsprite gVerticalDipSpriteTemplate, 2, 4, 2, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, -64
	delay 5
	createsprite gBasicHitSplatSpriteTemplate, 2, -10, -8, 1, 2
	createvisualtask sub_8159210, 5, 123, 63
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	createvisualtask sub_81169C0, 2, 0, 4, 5, 1
	waitforvisualfinish
	call ReturnStrongest1
	call ReturnStrongest1
	call ReturnStrongest1
	call ReturnStrongest1
	createsprite gBasicHitSplatSpriteTemplate, 2, -10, -8, 1, 0
	createvisualtask sub_8159210, 5, 141, 63
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 8, 0, 24, 1
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, 2, 10, 10, 1, 0
	createvisualtask sub_8159210, 5, 141, 63
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, 2, 3, -5, 1, 0
	createvisualtask sub_8159210, 5, 141, 63
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, 2, -5, 3, 1, 0
	createvisualtask sub_8159210, 5, 141, 63
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 0, 6, 0, RGB_BLACK
	goto ReturnContinue
ReturnStrongest1:
	createsprite gVerticalDipSpriteTemplate, 2, 4, 3, ANIM_ATTACKER
	createvisualtask sub_8159244, 5, 167, -64
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
	createvisualtask sub_8159210, 5, 123, 63
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	createvisualtask sub_81169C0, 2, 0, 4, 5, 1
	waitforvisualfinish
	return

Move_COSMIC_POWER:
	loadspritegfx ANIM_TAG_049
	createvisualtask sub_8159244, 5, 243, 0
	playsewithpan SE_W322, 0
	createvisualtask sub_8117610, 2, 0, 0, 15, 0
	waitforvisualfinish
	fadetobg BG_COSMIC
	waitbgfadeout
	createvisualtask sub_8117660, 2, 0, 128, 0, -1
	waitbgfadein
	delay 70
	createvisualtask sub_8159210, 5, 228, -64
	createsprite gUnknown_08592B7C, 2, -15, 0, 0, 0, 32, 60
	delay 8
	createsprite gUnknown_08592B7C, 2, 12, -5, 0, 0, 32, 60
	delay 0x28
	createvisualtask sub_8117610, 2, 0, 15, 0, 0
	waitforvisualfinish
	restorebg
	waitbgfadeout
	setarg 7, 0xFFFF
	waitbgfadein
	waitforvisualfinish
	end

Move_BLAST_BURN:
	loadspritegfx ANIM_TAG_035
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W221, -64
	createsprite gUnknown_08595428, 2, -32, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, 2, -20, -10, 24, 0, 0, 0
	createsprite gUnknown_08595428, 66, 0, -16, 24, 0, 0, 0
	createsprite gUnknown_08595428, 66, 20, -10, 24, 0, 0, 0
	createsprite gUnknown_08595428, 66, 32, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, 66, 20, 10, 24, 0, 0, 0
	createsprite gUnknown_08595428, 2, 0, 16, 24, 0, 0, 0
	createsprite gUnknown_08595428, 2, -20, 10, 24, 0, 0, 0
	delay 25
	playsewithpan SE_W172B, -64
	createsprite gUnknown_08595428, 2, -64, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, 6, -40, -20, 24, 0, 0, 0
	createsprite gUnknown_08595428, 70, 0, -32, 24, 0, 0, 0
	createsprite gUnknown_08595428, 70, 40, -20, 24, 0, 0, 0
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 6, 0, 8, 1
	createsprite gUnknown_08595428, 66, 64, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, 66, 40, 20, 24, 0, 0, 0
	createsprite gUnknown_08595428, 2, 0, 32, 24, 0, 0, 0
	createsprite gUnknown_08595428, 2, -40, 20, 24, 0, 0, 0
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 25
	playsewithpan SE_W172B, -64
	createsprite gUnknown_08595428, 2, -96, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, 6, -60, -30, 24, 0, 0, 0
	createsprite gUnknown_08595428, 70, 0, -48, 24, 0, 0, 0
	createsprite gUnknown_08595428, 70, 60, -30, 24, 0, 0, 0
	createsprite gBasicHitSplatSpriteTemplate, 130, -4, 3, 1, 0
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 12, 0, 20, 1
	createvisualtask sub_81162A4, 2, 2, 0, 10, 1
	createsprite gUnknown_08595428, 66, 96, 0, 24, 0, 0, 0
	createsprite gUnknown_08595428, 66, 60, 30, 24, 0, 0, 0
	createsprite gUnknown_08595428, 2, 0, 48, 24, 0, 0, 0
	createsprite gUnknown_08595428, 2, -60, 30, 24, 0, 0, 0
	createvisualtask sub_8115F10, 2, 257, 257, 257
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_ROCK_TOMB:
	loadspritegfx ANIM_TAG_250
	loadspritegfx ANIM_TAG_058
	createvisualtask sub_81162A4, 2, 2, 0, 10, 1
	waitforvisualfinish
	createsprite gUnknown_08596C58, 130, 20, 12, 64, 114, 0
	delay 8
	createvisualtask sub_81162A4, 2, 0, 2, 3, 1
	playsewithpan SE_W070, +63
	delay 8
	createsprite gUnknown_08596C58, 130, -20, 12, 64, 98, 0
	delay 8
	createvisualtask sub_81162A4, 2, 0, 2, 3, 1
	playsewithpan SE_W070, +63
	delay 8
	createsprite gUnknown_08596C58, 0xC2, 3, 6, 64, 82, 0
	delay 8
	createvisualtask sub_81162A4, 2, 0, 2, 3, 1
	playsewithpan SE_W070, +63
	delay 8
	createsprite gUnknown_08596C58, 130, -3, 13, 64, 66, 0
	delay 8
	createvisualtask sub_81162A4, 2, 0, 2, 3, 1
	playsewithpan SE_W070, +63
	delay 24
	playsewithpan SE_W063, +63
	createsprite gUnknown_085967AC, 0x85, 1, 50
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 20, 1
	createvisualtask sub_81162A4, 2, 2, 0, 10, 1
	waitforvisualfinish
	end

Move_SILVER_WIND:
	loadspritegfx 0x281F
	panse_1B SE_W016, -64, +63, +2, 0
	playsewithpan SE_W234, 0
	delay 0
	monbg ANIM_DEF_PARTNER
	monbgprio_29
	delay 0
	createvisualtask sub_8116664, 10, 1, 0, 0, 4, 0
	createvisualtask AnimTask_IsTargetOpponentSide, 2
	jumprettrue SilverWindOnPlayer
	fadetobg BG_BUG_OPPONENT
	waitbgfadeout
	createvisualtask sub_8117660, 5, 1536, 0, 0, -1
SilverWindContinue:
	delay 0
	createvisualtask sub_8116620, 10, 1, 0, 4, 4, RGB_BLACK
	waitbgfadein
	createsprite gUnknown_08592830, 0xC2, -32, 16, 0, 6, 2, 3, 1
	createsprite gUnknown_08592830, 0xC2, -8, 18, 64, 3, 2, 2, 1
	createsprite gUnknown_08592830, 120, -24, 18, 90, 5, 1, 2, 1
	createsprite gUnknown_08592830, 120, -40, 14, 128, 4, 1, 2, 1
	delay 0
	createsprite gUnknown_08592848, 0xC2, -32, 16, 0, 6, 2, 3, 1
	createsprite gUnknown_08592848, 0xC2, -8, 18, 64, 3, 2, 2, 1
	createsprite gUnknown_08592848, 120, -24, 18, 90, 5, 1, 2, 1
	createsprite gUnknown_08592848, 120, -40, 14, 128, 4, 1, 2, 1
	delay 0
	createsprite gUnknown_08592860, 0xC2, -32, 16, 0, 6, 2, 3, 1
	createsprite gUnknown_08592860, 0xC2, -8, 18, 64, 3, 2, 2, 1
	createsprite gUnknown_08592860, 120, -24, 18, 90, 5, 1, 2, 1
	createsprite gUnknown_08592860, 120, -40, 14, 128, 4, 1, 2, 1
	delay 6
	createsprite gUnknown_08592830, 0xC2, -4, 16, 0, 6, 1, 2, 1
	createsprite gUnknown_08592830, 0xC2, -16, 12, 192, 5, 2, 3, 1
	delay 0
	createsprite gUnknown_08592848, 0xC2, -4, 16, 0, 6, 1, 2, 1
	createsprite gUnknown_08592848, 0xC2, -16, 12, 192, 5, 2, 3, 1
	delay 0
	createsprite gUnknown_08592860, 0xC2, -4, 16, 0, 6, 1, 2, 1
	createsprite gUnknown_08592860, 0xC2, -16, 12, 192, 5, 2, 3, 1
	waitforvisualfinish
	playsewithpan SE_W016B, +63
	clearmonbg ANIM_DEF_PARTNER
	delay 0
	restorebg
	waitbgfadeout
	createvisualtask sub_8116664, 10, 1, 0, 4, 0, 0
	setarg 7, 0xFFFF
	waitbgfadein
	end

SilverWindOnPlayer:
	fadetobg BG_BUG_PLAYER
	waitbgfadeout
	createvisualtask sub_8117660, 5, -1536, 0, 0, -1
	goto SilverWindContinue

Move_SNATCH:
	playsewithpan SE_W036, -64
	createvisualtask AnimTask_WindUpLunge, 5, ANIM_ATTACKER, -12, 4, 10, 10, 12, 6
	end

Move_DIVE:
	loadspritegfx 0x2820
	loadspritegfx 0x2821
	choosetwoturnanim DiveSetUp, DiveAttack
DiveSetUp:
	loadspritegfx 0x27AC
	playsewithpan SE_W029, -64
	createsprite gUnknown_08596490, 2, 0, 0, 13, 336
	waitforvisualfinish
	playsewithpan SE_W291, -64
	createsprite gUnknown_085964CC, 3, 0
	call DiveSetUp1
	call DiveSetUp1
	call DiveSetUp1
	call DiveSetUp1
	call DiveSetUp1
	end
DiveSetUp1:
	createsprite gUnknown_085964E4, 5, 0, 0
	createsprite gUnknown_085964E4, 5, 1, 0
	return
DiveAttack:
	loadspritegfx 0x27A4
	loadspritegfx ANIM_TAG_155
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W153, +63
	createsprite gUnknown_085964CC, 131, 1
	call DiveAttack1
	call DiveAttack1
	call DiveAttack1
	call DiveAttack1
	call DiveAttack1
	delay 12
	call UnderWaterAttack1
	waitforvisualfinish
	visible ANIM_ATTACKER
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
DiveAttack1:
	createsprite gUnknown_085964E4, 0x85, 0, 1
	createsprite gUnknown_085964E4, 0x85, 1, 1
	return

Move_ROCK_BLAST:
	loadspritegfx ANIM_TAG_058
	loadspritegfx ANIM_TAG_135
	createsprite gHorizontalLungeSpriteTemplate, 2, 4, 6
	delay 3
	playsewithpan SE_W207, -64
	createsprite gUnknown_08596C98, 130, 16, 0, 0, 0, 25, 257
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, 131, 0, 0, 1, 1
	playsewithpan SE_W088, +63
	createsprite gUnknown_08596B1C, 130, 0, 0, 20, 24, 14, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 5, 1
	createsprite gUnknown_08596B1C, 130, 5, 0, -20, 24, 14, 1
	createsprite gUnknown_08596B1C, 130, 0, 5, 20, -24, 14, 2
	createsprite gUnknown_08596B1C, 130, -5, 0, -20, -24, 14, 2
	waitforvisualfinish
	end

Move_OVERHEAT:
	loadspritegfx 0x272D
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 18
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 0, 5, RGB(28, 0, 0)
	waitforvisualfinish
	createvisualtask sub_8117C44, 5
	waitforvisualfinish
	createvisualtask sub_8117CA0, 5, 0, 1
	delay 1
	createvisualtask sub_8117DD8, 5, 0
	delay 1
	playsewithpan SE_W082, -64
	createvisualtask sub_8117CA0, 5, 1, 0
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 2, 1, 0, 13, RGB(28, 0, 0)
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 2, 0, 15, 1
	waitforvisualfinish
	playsewithpan SE_W172B, -64
	createsprite gUnknown_08596FB0, 2, 1, 0, 30, 25, -20
	createsprite gUnknown_08596FB0, 2, 1, 32, 30, 25, -20
	createsprite gUnknown_08596FB0, 2, 1, 64, 30, 25, -20
	createsprite gUnknown_08596FB0, 2, 1, 96, 30, 25, -20
	createsprite gUnknown_08596FB0, 2, 1, 128, 30, 25, -20
	createsprite gUnknown_08596FB0, 66, 1, 160, 30, 25, -20
	createsprite gUnknown_08596FB0, 66, 1, 192, 30, 25, -20
	createsprite gUnknown_08596FB0, 66, 1, 224, 30, 25, -20
	delay 5
	createsprite gUnknown_08596FB0, 2, 1, 0, 30, 25, 0
	createsprite gUnknown_08596FB0, 2, 1, 32, 30, 25, 0
	createsprite gUnknown_08596FB0, 2, 1, 64, 30, 25, 0
	createsprite gUnknown_08596FB0, 2, 1, 96, 30, 25, 0
	createsprite gUnknown_08596FB0, 2, 1, 128, 30, 25, 0
	createsprite gUnknown_08596FB0, 66, 1, 160, 30, 25, 0
	createsprite gUnknown_08596FB0, 66, 1, 192, 30, 25, 0
	createsprite gUnknown_08596FB0, 66, 1, 224, 30, 25, 0
	delay 5
	createsprite gUnknown_08596FB0, 2, 1, 0, 30, 25, 10
	createsprite gUnknown_08596FB0, 2, 1, 32, 30, 25, 10
	createsprite gUnknown_08596FB0, 2, 1, 64, 30, 25, 10
	createsprite gUnknown_08596FB0, 2, 1, 96, 30, 25, 10
	createsprite gUnknown_08596FB0, 2, 1, 128, 30, 25, 10
	createsprite gUnknown_08596FB0, 66, 1, 160, 30, 25, 10
	createsprite gUnknown_08596FB0, 66, 1, 192, 30, 25, 10
	createsprite gUnknown_08596FB0, 66, 1, 224, 30, 25, 10
	delay 5
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, 131, -5, 3, 1, 0
	playsewithpan SE_W007, +63
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 10, 0, 25, 1
	delay 6
	createsprite gBasicHitSplatSpriteTemplate, 131, 8, -5, 1, 0
	playsewithpan SE_W007, +63
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, 131, 10, 10, 1, 0
	playsewithpan SE_W007, +63
	delay 8
	createsprite gBasicHitSplatSpriteTemplate, 131, 0, 0, 1, 0
	playsewithpan SE_W007, +63
	createvisualtask sub_8117DD8, 5, 1
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 2, -1, 0, 13, RGB(18, 18, 18)
	createvisualtask AnimTask_ShakeMon, 5, ANIM_ATTACKER, 3, 0, 15, 1
	waitforvisualfinish
	createvisualtask sub_8117D3C, 5, 0, 1
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 5, 0, RGB(28, 0, 0)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	waitforvisualfinish
	delay 15
	createvisualtask sub_8117D3C, 5, 1, 0
	delay 1
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 2, 0, 13, 0, RGB(18, 18, 18)
	waitforvisualfinish
	createvisualtask sub_8117C70, 5
	waitforvisualfinish
	end

Move_HYDRO_CANNON:
	loadspritegfx 0x27A5
	loadspritegfx 0x27A4
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	playsewithpan SE_W057, -64
	createsprite gUnknown_085951C0, 130
	delay 10
	createvisualtask sub_8115F10, 2, 257, 257, 257
	delay 30
	panse_1B SE_W056, -64, +63, +2, 0
	call HydroCannon1
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 10, 0, 40, 1
	createsprite gUnknown_08597388, 130, 0, 0, 1, 0
	call HydroCannon1
	createsprite gUnknown_08597388, 130, 0, 0, 1, 0
	call HydroCannon1
	createsprite gUnknown_08597388, 130, 0, 0, 1, 0
	call HydroCannon1
	createsprite gUnknown_08597388, 130, 0, 0, 1, 0
	call HydroCannon1
	createsprite gUnknown_08597388, 130, 0, 0, 1, 0
	call HydroCannon1
	createsprite gUnknown_08597388, 130, 0, 0, 1, 0
	waitforvisualfinish
	createvisualtask sub_8115F10, 2, 257, 257, 257
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
HydroCannon1:
	createsprite gUnknown_085951D8, 130, 10, -10, 0, 0, 15, 257
	delay 1
	createsprite gUnknown_085951D8, 130, 10, -10, 0, 0, 15, 257
	delay 1
	createsprite gUnknown_085951D8, 130, 10, -10, 0, 0, 15, 257
	delay 1
	createsprite gUnknown_085951D8, 130, 10, -10, 0, 0, 15, 257
	delay 1
	createsprite gUnknown_085951D8, 130, 10, -10, 0, 0, 15, 257
	return

Move_ASTONISH:
	loadspritegfx 0x2821
	playsewithpan SE_W227, -64
	createsprite gHorizontalLungeSpriteTemplate, 2, 4, 6
	delay 25
	createsprite gUnknown_085964E4, 0x85, 0, 1
	playsewithpan SE_W166, +63
	createsprite gUnknown_085964E4, 0x85, 1, 1
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 5, 1
	createvisualtask sub_8106020, 3
	waitforvisualfinish
	end

Move_SEISMIC_TOSS:
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_058
	setarg 7, 0
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	waitforvisualfinish
	createvisualtask AnimTask_GetSeismicTossDamageLevel, 3
	delay 1
	fadetobg BG_SEISMICTOSS_SKUUPPERCUT
	waitbgfadeout
	createvisualtask sub_811152C, 3
	playsewithpan SE_W327, 0
	waitbgfadein
	waitforvisualfinish
	createvisualtask sub_8111590, 3
	jumpreteq 0, SeismicTossWeak
	jumpreteq 1, SeismicTossMedium
	jumpreteq 2, SeismicTossStrong
SeismicTossContinue:
	restorebg
	waitbgfadeout
	setarg 7, 0xFFF
	waitbgfadein
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end
SeismicTossWeak:
	call SeismicToss1
	delay 16
	call SeismicToss2
	goto SeismicTossContinue
SeismicTossMedium:
	call SeismicToss1
	delay 14
	call SeismicToss2
	delay 14
	call SeismicToss1
	goto SeismicTossContinue
SeismicTossStrong:
	call SeismicToss2
	delay 10
	call SeismicToss1
	delay 10
	call SeismicToss2
	delay 10
	call SeismicToss1
	goto SeismicTossContinue
SeismicToss1:
	createsprite gBasicHitSplatSpriteTemplate, 131, -10, -8, 1, 1
	playsewithpan SE_W070, +63
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 5, 1
	createsprite gUnknown_08596CB0, 130, -12, 27, 2, 3
	createsprite gUnknown_08596CB0, 130, 8, 28, 3, 4
	createsprite gUnknown_08596CB0, 130, -4, 30, 2, 3
	createsprite gUnknown_08596CB0, 130, 12, 25, 4, 4
	return
SeismicToss2:
	createsprite gBasicHitSplatSpriteTemplate, 131, 10, -8, 1, 1
	playsewithpan SE_W088, +63
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 5, 1
	createsprite gUnknown_08596CB0, 130, -12, 32, 3, 4
	createsprite gUnknown_08596CB0, 130, 8, 31, 2, 2
	createsprite gUnknown_08596CB0, 130, -4, 28, 2, 3
	createsprite gUnknown_08596CB0, 130, 12, 30, 4, 3
	return

Move_MAGIC_COAT:
	loadspritegfx 0x27BA
	setalpha 0, 16
	waitplaysewithpan SE_W112, -64, 15
	createsprite gUnknown_085965C0, 3, 40, 0, 10170
	waitforvisualfinish
	delay 1
	blendoff
	end

Move_WATER_PULSE:
	loadspritegfx ANIM_TAG_155
	loadspritegfx 0x2830
	monbg ANIM_TARGET
	monbgprio_28 ANIM_TARGET
	playsewithpan SE_W145C, -64
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 0, 0, 7, RGB(0, 25, 28)
	delay 10
	createsprite gUnknown_085952F8, 66, 100, 100, 8, 1, 20, 40, 0
	createsprite gUnknown_085952F8, 66, 20, 100, 16, 2, 10, 35, 1
	createsprite gUnknown_085952F8, 66, 200, 80, 8, 1, 40, 20, 0
	createsprite gUnknown_085952F8, 66, 80, 60, 10, 3, 20, 50, 0
	createsprite gUnknown_085952F8, 66, 140, 100, 16, 1, 20, 30, 1
	playsewithpan SE_W145C, +63
	waitforvisualfinish
	playsewithpan SE_W202, -64
	createsprite gUnknown_08593470, 130, 0, 0, 40, 15
	delay 5
	playsewithpan SE_W202, -64
	createsprite gUnknown_08593470, 130, 0, 0, 40, 15
	delay 5
	playsewithpan SE_W202, -64
	createsprite gUnknown_08593470, 130, 0, 0, 40, 15
	delay 0xD
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 8, 18, 1
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 7, 0, RGB(0, 25, 28)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Move_PSYCHO_BOOST:
	loadspritegfx 0x27E4
	monbg ANIM_ATK_PARTNER
	fadetobg BG_PSYCHIC
	waitbgfadeout
	createvisualtask sub_815A5C8, 5
	waitbgfadein
	delay 6
	createvisualtask sub_8115A04, 2, 1, 2, 8, 0, 10, RGB_BLACK
	delay 0
	monbgprio_28 ANIM_ATTACKER
	setalpha 8, 8
	delay 10
	createvisualtask AnimTask_ShakeMon, 2, ANIM_ATTACKER, 3, 0, 240, 0
	loopsewithpan SE_W060B, -64, 14, 10
	createsprite gUnknown_08596920, 2
	delay 0x6E
	loopsewithpan SE_W060B, -64, 7, 10
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, -8, 1, 24, 1
	playsewithpan SE_W043, +63
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	call UnsetPsychicBackground
	end

Move_KNOCK_OFF:
	loadspritegfx 0x2825
	loadspritegfx ANIM_TAG_135
	createsprite gHorizontalLungeSpriteTemplate, 2, 4, 6
	delay 4
	playsewithpan SE_W233, +63
	createsprite gUnknown_085CE984, 130, -16, -16
	delay 8
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 31, 5, 1, 0x7FFF, 10, 0, 0
	createsprite gBasicHitSplatSpriteTemplate, 131, 0, 0, 1, 2
	playsewithpan SE_W004, +63
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 1, -12, 10, 0, 3
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 5
	delay 3
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 0, 3, 6, 1
	delay 5
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 1, 0, 6
	delay 10
	waitforvisualfinish
	end

Move_DOOM_DESIRE:
	createvisualtask sub_8114960, 2
	delay 1
	monbg ANIM_ATK_PARTNER
	createvisualtask sub_811489C, 5, 1, 0
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 0, 4, RGB_BLACK
	waitforvisualfinish
	setalpha 8, 8
	playsewithpan SE_W060, -64
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -4, -4, 15, ANIM_ATTACKER, 1
	waitforvisualfinish
	delay 20
	createvisualtask sub_811489C, 5, 1, 1
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 4, 0, RGB_BLACK
	waitforvisualfinish
	clearmonbg ANIM_ATK_PARTNER
	blendoff
	end

Move_SKY_UPPERCUT:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	fadetobg BG_SEISMICTOSS_SKUUPPERCUT
	waitbgfadeout
	playsewithpan SE_W327, -64
	createvisualtask sub_810DABC, 5, 55
	waitbgfadein
	setalpha 12, 8
	delay 0x26
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 0, 28, 0, 0, 5
	delay 4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 4, 0, 6, 1
	playsewithpan SE_W233B, +63
	createsprite gBasicHitSplatSpriteTemplate, 131, -28, 28, 1, 1
	delay 1
	playsewithpan SE_W233B, +63
	createsprite gBasicHitSplatSpriteTemplate, 131, -15, 8, 1, 1
	playsewithpan SE_W233B, +63
	delay 1
	playsewithpan SE_W233B, +63
	createsprite gBasicHitSplatSpriteTemplate, 131, -5, -12, 1, 1
	delay 1
	playsewithpan SE_W233B, +63
	createsprite gBasicHitSplatSpriteTemplate, 131, 0, -32, 1, 1
	delay 1
	playsewithpan SE_W233B, +63
	createsprite gBasicHitSplatSpriteTemplate, 131, 5, -52, 1, 1
	createsprite gSlideMonToOffsetSpriteTemplate, 2, 1, -26, 16, 1, 4
	delay 4
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 0, 3, 6, 1
	delay 30
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 0, 0, 6
	delay 4
	createsprite gSlideMonToOriginalPosSpriteTemplate, 2, 1, 0, 6
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	restorebg
	waitbgfadeout
	setarg 7, 0xFFFF
	waitbgfadein
	end

Move_SECRET_POWER:
	createvisualtask AnimTask_GetBattleTerrain, 5
	jumpargeq 0, BATTLE_TERRAIN_GRASS, Move_NEEDLE_ARM
	jumpargeq 0, BATTLE_TERRAIN_LONG_GRASS, Move_MAGICAL_LEAF
	jumpargeq 0, BATTLE_TERRAIN_SAND, Move_MUD_SHOT
	jumpargeq 0, BATTLE_TERRAIN_UNDERWATER, Move_WATERFALL
	jumpargeq 0, BATTLE_TERRAIN_WATER, Move_SURF
	jumpargeq 0, BATTLE_TERRAIN_POND, Move_BUBBLE_BEAM
	jumpargeq 0, BATTLE_TERRAIN_MOUNTAIN, Move_ROCK_THROW
	jumpargeq 0, BATTLE_TERRAIN_CAVE, Move_BITE
	jumpargeq 0, BATTLE_TERRAIN_BUILDING, Move_STRENGTH
	goto Move_SLAM

Move_TWISTER:
	loadspritegfx 0x274F
	loadspritegfx ANIM_TAG_135
	loadspritegfx ANIM_TAG_058
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	playsewithpan SE_W239, +63
	createsprite gUnknown_085923A8, 130, 120, 70, 5, 70, 30
	delay 1
	createsprite gUnknown_085923A8, 130, 115, 55, 6, 60, 25
	delay 1
	createsprite gUnknown_085923A8, 130, 115, 60, 7, 60, 30
	createsprite gUnknown_085923A8, 130, 115, 55, 10, 60, 30
	delay 3
	createsprite gUnknown_08596CC8, 130, 100, 50, 4, 50, 26
	delay 1
	createsprite gUnknown_085923A8, 130, 105, 25, 8, 60, 20
	delay 1
	createsprite gUnknown_085923A8, 130, 115, 40, 10, 48, 30
	delay 3
	createsprite gUnknown_08596CC8, 130, 120, 30, 6, 45, 25
	createsprite gUnknown_085923A8, 130, 115, 35, 10, 60, 30
	delay 3
	createsprite gUnknown_08596CC8, 130, 105, 20, 8, 40, 0
	delay 3
	createsprite gUnknown_085923A8, 130, 20, 255, 15, 32, 0
	createsprite gUnknown_085923A8, 130, 110, 10, 8, 32, 20
	waitforvisualfinish
	createsprite gBasicHitSplatSpriteTemplate, 131, -32, -16, 1, 3
	playsewithpan SE_W004, +63
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 3, 0, 12, 1
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_DEF_PARTNER, 3, 0, 12, 1
	delay 4
	createsprite gUnknown_085973A0, 131, 1, 3
	playsewithpan SE_W004, +63
	delay 4
	createsprite gUnknown_085973A0, 131, 1, 3
	playsewithpan SE_W004, +63
	delay 4
	createsprite gBasicHitSplatSpriteTemplate, 131, 32, 20, 1, 3
	playsewithpan SE_W004, +63
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_MAGICAL_LEAF:
	loadspritegfx 0x274F
	loadspritegfx 0x27B0
	loadspritegfx ANIM_TAG_135
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	delay 1
	loopsewithpan SE_W077, -64, 10, 5
	createvisualtask sub_81007C4, 5
	createsprite gUnknown_08592390, 2, -3, -2, 10
	delay 2
	createsprite gUnknown_08592390, 2, -1, -1, 15
	delay 2
	createsprite gUnknown_08592390, 2, -4, -4, 7
	delay 2
	createsprite gUnknown_08592390, 2, 3, -3, 11
	delay 2
	createsprite gUnknown_08592390, 2, -1, -6, 8
	delay 2
	createsprite gUnknown_08592390, 2, 2, -1, 12
	delay 2
	createsprite gUnknown_08592390, 2, -3, -4, 13
	delay 2
	createsprite gUnknown_08592390, 2, 4, -5, 7
	delay 2
	createsprite gUnknown_08592390, 2, 2, -6, 11
	delay 2
	createsprite gUnknown_08592390, 2, -3, -5, 8
	delay 60
	playsewithpan SE_W013B, -64
	createsprite gUnknown_085923D8, 131, 20, -10, 20, 0, 32, 20, 0
	createsprite gUnknown_085923D8, 131, 20, -10, 20, 0, 32, -20, 0
	delay 30
	playsewithpan SE_W013, +63
	createsprite gBasicHitSplatSpriteTemplate, 132, -10, -4, 1, 2
	createsprite gBasicHitSplatSpriteTemplate, 132, 10, 4, 1, 2
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	delay 20
	setarg 7, 0xFFFF
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

Move_ICE_BALL:
	loadspritegfx 0x273B
	loadspritegfx ANIM_TAG_141
	createvisualtask AnimTask_GetRolloutCounter, 5, 0
	jumpargeq 0, 4, IceBallSetIceBg
IceBallContinue:
	playsewithpan SE_W196, -64
	createsprite gUnknown_08595DE4, 130, 15, 0, -12, -16, 30, -40
	delay 0x1C
	playsewithpan SE_W280, +63
	createvisualtask AnimTask_GetRolloutCounter, 5, 0
	jumpargeq 0, 0, IceBallWeakest
	jumpargeq 0, 1, IceBallWeak
	jumpargeq 0, 2, IceBallMediun
	jumpargeq 0, 3, IceBallStrong
	jumpargeq 0, 4, IceBallStrongest
IceBallContinue2:
	createvisualtask AnimTask_GetRolloutCounter, 5, 0
	jumpargeq 0, 4, IceBallUnsetIceBg
IceBallEnd:
	end
IceBallSetIceBg:
	fadetobg BG_ICE
	goto IceBallContinue
IceBallUnsetIceBg:
	waitbgfadein
	delay 0x2D
	restorebg
	waitbgfadein
	goto IceBallEnd
IceBallWeakest:
	createvisualtask sub_80D6388, 2, 0, 1, 8, 1, 0
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	goto IceBallContinue2
IceBallWeak:
	createvisualtask sub_80D6388, 2, 0, 1, 10, 1, 0
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	goto IceBallContinue2
IceBallMediun:
	createvisualtask sub_80D6388, 2, 0, 1, 14, 1, 0
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	goto IceBallContinue2
IceBallStrong:
	createvisualtask sub_80D6388, 2, 0, 1, 18, 1, 0
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	goto IceBallContinue2
IceBallStrongest:
	createvisualtask sub_80D6388, 2, 0, 1, 30, 1, 0
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	call IceBall1
	goto IceBallContinue2
IceBall1:
	createsprite gUnknown_08595DFC, 132, -12, -16
	return

Move_WEATHER_BALL:
	loadspritegfx ANIM_TAG_283
	createsprite gVerticalDipSpriteTemplate, 2, 8, 1, ANIM_ATTACKER
	delay 8
	playsewithpan SE_W207, -64
	createsprite gUnknown_0853EE38, 2
	waitforvisualfinish
	delay 15
	playsewithpan SE_W197, 0
	createsprite gBattleAnimSpriteTemplate_859728C, 2, 31, 5, 1, 0x7FFF, 10, 0, 0
	waitforvisualfinish
	createvisualtask AnimTask_GetWeather, 2
	delay 1
	jumpreteq ANIM_WEATHER_NONE, WeatherBallNormal
	jumpreteq ANIM_WEATHER_SUN, WeatherBallFire
	jumpreteq ANIM_WEATHER_RAIN, WeatherBallWater
	jumpreteq ANIM_WEATHER_SANDSTORM, WeatherBallSandstorm
	jumpreteq ANIM_WEATHER_HAIL, WeatherBallIce
WeatherBallNormal:
	loadspritegfx ANIM_TAG_135
	createsprite gUnknown_0853EE50, 130, -30, -100, 25, 1, 0, 0
	waitforvisualfinish
	playsewithpan SE_W025B, +63
	createsprite gBasicHitSplatSpriteTemplate, 132, -10, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 8, 1
	waitforvisualfinish
	end
WeatherBallFire:
	loadspritegfx 0x272D
	createsprite gUnknown_0859559C, 130, -30, -100, 25, 1, 40, 10
	playsewithpan SE_W172, +63
	delay 10
	createsprite gUnknown_0859559C, 130, -30, -100, 25, 1, -40, 20
	playsewithpan SE_W172, +63
	delay 10
	createsprite gUnknown_0859559C, 130, -30, -100, 25, 1, 0, 0
	playsewithpan SE_W172, +63
	waitforvisualfinish
	playsewithpan SE_W172B, +63
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 8, 1
	waitforvisualfinish
	end
WeatherBallWater:
	loadspritegfx ANIM_TAG_155
	createsprite gUnknown_08595328, 130, -30, -100, 25, 1, 50, 10
	playsewithpan SE_W152, +63
	delay 8
	createsprite gUnknown_08595328, 130, -30, -100, 25, 1, -20, 20
	playsewithpan SE_W152, +63
	delay 0xD
	createsprite gUnknown_08595328, 130, -30, -100, 25, 1, 0, 0
	playsewithpan SE_W152, +63
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 0, 3, 8, 1
	playsewithpan SE_W202, +63
	waitforvisualfinish
	end
WeatherBallSandstorm:
	loadspritegfx ANIM_TAG_058
	createsprite gUnknown_08596CE0, 130, -30, -100, 25, 1, 30, 0
	playsewithpan SE_W088, +63
	delay 5
	createsprite gUnknown_08596CE0, 130, -30, -100, 25, 1, -40, 20
	playsewithpan SE_W088, +63
	delay 14
	createsprite gUnknown_08596CE0, 130, -30, -100, 25, 1, 0, 0
	playsewithpan SE_W088, +63
	waitforvisualfinish
	playsewithpan SE_W070, +63
	createsprite gUnknown_08596CB0, 130, -12, 27, 2, 3
	createsprite gUnknown_08596CB0, 130, 8, 28, 3, 4
	createsprite gUnknown_08596CB0, 130, -4, 30, 2, 3
	createsprite gUnknown_08596CB0, 130, 12, 25, 4, 4
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	waitforvisualfinish
	end
WeatherBallIce:
	loadspritegfx ANIM_TAG_263
	loadspritegfx ANIM_TAG_141
	createsprite gUnknown_08595D44, 130, -30, -100, 25, 25, -40, 20
	playsewithpan SE_W258, +63
	delay 10
	createsprite gUnknown_08595D44, 130, -30, -100, 25, 25, 40, 0
	playsewithpan SE_W258, +63
	delay 10
	createsprite gUnknown_08595D44, 130, -30, -100, 25, 25, 0, 0
	playsewithpan SE_W258, +63
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	playsewithpan SE_W196, +63
	call FreezeEffect1
	waitforvisualfinish
	end

Move_COUNT:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W003, +63
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

FreezeEffect1:
	createsprite gUnknown_08595B68, 130, -10, -10, 0
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B80, 130, 10, 20, 0
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B68, 130, -5, 10, 0
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B80, 130, 17, -12, 0
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B80, 130, -15, 15, 0
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B80, 130, 0, 0, 0
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B68, 130, 20, 2, 0
	playsewithpan SE_W196, +63
	return

FreezeEffect2:
	createsprite gUnknown_08595B68, 130, -10, -10, 1
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B80, 130, 10, 20, 1
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B68, 130, -29, 0, 1
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B80, 130, 29, -20, 1
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B68, 130, -5, 10, 1
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B80, 130, 17, -12, 1
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B68, 130, -20, 0, 1
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B80, 130, -15, 15, 1
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B80, 130, 26, -5, 1
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B80, 130, 0, 0, 1
	playsewithpan SE_W196, +63
	delay 4
	createsprite gUnknown_08595B68, 130, 20, 2, 1
	playsewithpan SE_W196, +63
	return

IcyWindEffect1: @ Unused
	loopsewithpan SE_W196, +63, 6, 4
	createsprite gUnknown_08595C04, 130, 0, 24, 0
	delay 4
	createsprite gUnknown_08595C04, 130, 8, 24, 0
	createsprite gUnknown_08595C04, 130, -8, 24, 0
	delay 4
	createsprite gUnknown_08595C04, 130, 16, 24, 0
	createsprite gUnknown_08595C04, 130, -16, 24, 0
	delay 4
	createsprite gUnknown_08595C04, 130, 24, 24, 0
	createsprite gUnknown_08595C04, 130, -24, 24, 0
	delay 4
	createsprite gUnknown_08595C04, 130, 32, 24, 0
	createsprite gUnknown_08595C04, 130, -32, 24, 0
	return

IcyWindEffect2:
	loopsewithpan SE_W196, +63, 6, 4
	createsprite gUnknown_08595C04, 130, 0, 24, 1
	delay 4
	createsprite gUnknown_08595C04, 130, 8, 24, 1
	createsprite gUnknown_08595C04, 130, -8, 24, 1
	delay 4
	createsprite gUnknown_08595C04, 130, 16, 24, 1
	createsprite gUnknown_08595C04, 130, -16, 24, 1
	delay 4
	createsprite gUnknown_08595C04, 130, 24, 24, 1
	createsprite gUnknown_08595C04, 130, -24, 24, 1
	delay 4
	createsprite gUnknown_08595C04, 130, 32, 24, 1
	createsprite gUnknown_08595C04, 130, -32, 24, 1
	delay 4
	createsprite gUnknown_08595C04, 130, 40, 24, 1
	createsprite gUnknown_08595C04, 130, -40, 24, 1
	delay 4
	createsprite gUnknown_08595C04, 130, 48, 24, 1
	createsprite gUnknown_08595C04, 130, -48, 24, 1
	return

GrantingStarsEffect:
	createsprite gUnknown_08592B7C, 2, -15, 0, 0, 0, 32, 60
	delay 8
	createsprite gUnknown_08592B7C, 2, 12, -5, 0, 0, 32, 60
	delay 8
	return

HealingEffect:
	playsewithpan SE_W071B, -64
	createsprite gUnknown_08592F2C, 2, 0, -5, 0, 0
	delay 7
	createsprite gUnknown_08592F2C, 2, -15, 10, 0, 0
	delay 7
	createsprite gUnknown_08592F2C, 2, -15, -15, 0, 0
	delay 7
	createsprite gUnknown_08592F2C, 2, 10, -5, 0, 0
	delay 7
	return

HealingEffect2:
	playsewithpan SE_W071B, +63
	createsprite gUnknown_08592F2C, 130, 0, -5, 1, 0
	delay 7
	createsprite gUnknown_08592F2C, 130, -15, 10, 1, 0
	delay 7
	createsprite gUnknown_08592F2C, 130, -15, -15, 1, 0
	delay 7
	createsprite gUnknown_08592F2C, 130, 10, -5, 1, 0
	delay 7
	return

PoisonBubblesEffect:
	createsprite gPoisonBubbleSpriteTemplate, 130, 10, 10, 0
	playsewithpan SE_W092, +63
	delay 6
	createsprite gPoisonBubbleSpriteTemplate, 130, 20, -20, 0
	playsewithpan SE_W092, +63
	delay 6
	createsprite gPoisonBubbleSpriteTemplate, 130, -20, 15, 0
	playsewithpan SE_W092, +63
	delay 6
	createsprite gPoisonBubbleSpriteTemplate, 130, 0, 0, 0
	playsewithpan SE_W092, +63
	delay 6
	createsprite gPoisonBubbleSpriteTemplate, 130, -20, -20, 0
	playsewithpan SE_W092, +63
	delay 6
	createsprite gPoisonBubbleSpriteTemplate, 130, 16, -8, 0
	playsewithpan SE_W092, +63
	return

WaterBubbleEffect:
	createsprite gWaterBubbleSpriteTemplate, 2, 10, 10, 0
	playsewithpan SE_W145C, +63
	delay 6
	createsprite gWaterBubbleSpriteTemplate, 2, 20, -20, 0
	playsewithpan SE_W145C, +63
	delay 6
	createsprite gWaterBubbleSpriteTemplate, 2, -20, 15, 0
	playsewithpan SE_W145C, +63
	delay 6
	createsprite gWaterBubbleSpriteTemplate, 2, 0, 0, 0
	playsewithpan SE_W145C, +63
	delay 6
	createsprite gWaterBubbleSpriteTemplate, 2, -20, -20, 0
	playsewithpan SE_W145C, +63
	delay 6
	createsprite gWaterBubbleSpriteTemplate, 2, 16, -8, 0
	playsewithpan SE_W145C, +63
	return

WaterBubbleEffect2:
	createsprite gWaterBubbleSpriteTemplate, 2, 10, 10, 1
	playsewithpan SE_W145C, +63
	delay 6
	createsprite gWaterBubbleSpriteTemplate, 2, -28, -10, 1
	playsewithpan SE_W145C, +63
	delay 6
	createsprite gWaterBubbleSpriteTemplate, 2, 20, -20, 1
	playsewithpan SE_W145C, +63
	delay 6
	createsprite gWaterBubbleSpriteTemplate, 2, -20, 15, 1
	playsewithpan SE_W145C, +63
	delay 6
	createsprite gWaterBubbleSpriteTemplate, 2, 0, 0, 1
	playsewithpan SE_W145C, +63
	delay 6
	createsprite gWaterBubbleSpriteTemplate, 2, 27, 8, 1
	playsewithpan SE_W145C, +63
	delay 6
	createsprite gWaterBubbleSpriteTemplate, 2, -20, -20, 1
	playsewithpan SE_W145C, +63
	delay 6
	createsprite gWaterBubbleSpriteTemplate, 2, 16, -8, 1
	playsewithpan SE_W145C, +63
	return

ElectricityEffect:
	playsewithpan SE_W085B, +63
	createsprite gElectricitySpriteTemplate, 130, 5, 0, 5, 0
	delay 2
	createsprite gElectricitySpriteTemplate, 130, -5, 10, 5, 1
	delay 2
	createsprite gElectricitySpriteTemplate, 130, 15, 20, 5, 2
	delay 2
	createsprite gElectricitySpriteTemplate, 130, -15, -10, 5, 0
	delay 2
	createsprite gElectricitySpriteTemplate, 130, 25, 0, 5, 1
	delay 2
	createsprite gElectricitySpriteTemplate, 130, -8, 8, 5, 2
	delay 2
	createsprite gElectricitySpriteTemplate, 130, 2, -8, 5, 0
	delay 2
	createsprite gElectricitySpriteTemplate, 130, -20, 15, 5, 1
	return

ConfusionEffect:
	loopsewithpan SE_W146, +63, 0xD, 6
	createsprite gConfusionDuckSpriteTemplate, 130, 0, -15, 0, 3, 90
	createsprite gConfusionDuckSpriteTemplate, 130, 0, -15, 51, 3, 90
	createsprite gConfusionDuckSpriteTemplate, 130, 0, -15, 102, 3, 90
	createsprite gConfusionDuckSpriteTemplate, 130, 0, -15, 153, 3, 90
	createsprite gConfusionDuckSpriteTemplate, 130, 0, -15, 204, 3, 90
	return

SetPsychicBackground:
	fadetobg BG_PSYCHIC
	waitbgfadeout
	createvisualtask sub_815A504, 5
	waitbgfadein
	return

UnsetPsychicBackground:
	restorebg
	waitbgfadeout
	setarg 7, 0xFFFF
	waitbgfadein
	return

SetFlyingBg:
	jumpifcontest SetBgFlyingContest
	fadetobg BG_FLYING
	waitbgfadeout
	createvisualtask sub_8117660, 5, -2304, 768, 1, -1
SetBgFlyingContinue:
	waitbgfadein
	return
SetBgFlyingContest:
	fadetobg BG_FLYING_CONTESTS
	waitbgfadeout
	createvisualtask sub_8117660, 5, 2304, 768, 0, -1
	goto SetBgFlyingContinue

UnsetFlyingBg:
	restorebg
	waitbgfadeout
	setarg 7, 0xFFFF
	waitbgfadein
	return

SetSolarbeamBg:
	createvisualtask AnimTask_IsContest, 2
	jumprettrue SetSolarbeamBgContest
	createvisualtask AnimTask_IsTargetPlayerSide, 2
	jumpretfalse SetSolarbeamBgOpponent
	goto SetSolarbeamBgPlayer
SetSolarbeamBgContinue:
	waitbgfadein
	return
SetSolarbeamBgContest:
	fadetobg BG_SOLARBEAM_CONTESTS
	goto SetSolarbeamBgContinue
SetSolarbeamBgPlayer:
	fadetobg BG_SOLARBEAM_PLAYER
	goto SetSolarbeamBgContinue
SetSolarbeamBgOpponent:
	fadetobg BG_SOLARBEAM_OPPONENT
	goto SetSolarbeamBgContinue

UnsetSolarbeamBg:
	restorebg
	waitbgfadein
	return

Status_Poison:
	loopsewithpan SE_W092, +63, 0xD, 6
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 18, 2
	createvisualtask sub_8115A04, 2, 2, 2, 2, 0, 12, RGB(30, 0, 31)
	end

Status_Confusion:
	loadspritegfx ANIM_TAG_073
	call ConfusionEffect
	end

Status_Burn:
	loadspritegfx 0x272D
	playsewithpan SE_W172, +63
	call Burn1
	call Burn1
	call Burn1
	waitforvisualfinish
	end

Burn1:
	createsprite gUnknown_08595504, 130, -24, 24, 24, 24, 20, 1, 1
	delay 4
	return

Status_Infatuation:
	loadspritegfx 0x27E2
	playsewithpan SE_W204, -64
	createsprite gUnknown_08593970, 3, 0, 20
	delay 15
	playsewithpan SE_W204, -64
	createsprite gUnknown_08593970, 3, -20, 20
	delay 15
	playsewithpan SE_W204, -64
	createsprite gUnknown_08593970, 3, 20, 20
	end

Status_Sleep:
	loadspritegfx 0x27F4
	playsewithpan SE_W173, -64
	createsprite gUnknown_08592C88, 2, 4, -10, 16, 0, 0
	delay 30
	createsprite gUnknown_08592C88, 2, 4, -10, 16, 0, 0
	end

Status_Paralysis:
	loadspritegfx ANIM_TAG_011
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 10, 1
	call ElectricityEffect
	end

Status_Freeze:
	playsewithpan SE_W196, 0
	loadspritegfx 0x271A
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	waitplaysewithpan SE_W258, +63, 17
	createvisualtask sub_80A9EF4, 2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Status_Curse:
	loadspritegfx 0x27D8
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W171, +63
	createsprite gBattleAnimSpriteTemplate_8596DE8, 130
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 14, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

Status_Nightmare:
	loadspritegfx 0x27ED
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W171, +63
	createsprite gBattleAnimSpriteTemplate_8596E00, 130
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 14, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	end

General_CastformChange:
	createvisualtask sub_815BB18, 2
	jumpreteq 1, AnimScript_82D7ECA
	goto AnimScript_82D7EB2
AnimScript_82D7EB2:
	monbg ANIM_ATTACKER
	playsewithpan SE_W100, -64
	waitplaysewithpan SE_W107, -64, 48
	createvisualtask sub_815B7D0, 2, 1
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	end
AnimScript_82D7ECA:
	createvisualtask sub_815BB58, 2, 1
	end

General_StatsChange:
	createvisualtask AnimTask_StatsChange, 5
	waitforvisualfinish
	end

General_SubstituteFade:
	monbg ANIM_ATTACKER
	createvisualtask sub_8172D98, 5
	createvisualtask sub_8116620, 10, 2, 0, 0, 16, RGB_WHITE
	waitforvisualfinish
	delay 1
	clearmonbg ANIM_ATTACKER
	delay 2
	blendoff
	createvisualtask sub_8116620, 10, 2, 0, 0, 0, RGB_WHITE
	createvisualtask sub_8172BF0, 2, 1
	end

General_SubstituteAppear:
	createvisualtask sub_815F20C, 2
	end

General_PokeblockThrow:
	createvisualtask sub_817345C, 2, 0
	createvisualtask sub_81732B0, 2
	delay 0
	waitplaysewithpan SE_W026, -64, 0x16
	createsprite gBattleAnimSpriteTemplate_85E5338, 131, -18, 12, 0, 32
	delay 50
	loopsewithpan SE_W039, +63, 19, 2
	createvisualtask AnimTask_SwayMon, 5, 1, 8, 1536, 2, ANIM_TARGET
	waitforvisualfinish
	createvisualtask sub_81732E4, 2
	end

General_ItemKnockoff:
	loadspritegfx 0x27F0
	createsprite gBattleAnimSpriteTemplate_8592628, 130
	end

General_TurnTrap:
	createvisualtask AnimTask_GetTrappedMoveAnimId, 5
	jumpargeq 0, TRAP_ANIM_FIRE_SPIN, Status_FireSpin
	jumpargeq 0, TRAP_ANIM_WHIRLPOOL, Status_Whrilpool
	jumpargeq 0, TRAP_ANIM_CLAMP, Status_Clamp
	jumpargeq 0, TRAP_ANIM_SAND_TOMB, Status_SandTomb
	goto Status_BindWrap
Status_BindWrap:
	loadspritegfx 0x27CA
	loopsewithpan SE_W010, +63, 6, 2
	createsprite gUnknown_08592494, 132, 0, 16, 0, 1
	delay 7
	createsprite gUnknown_08592494, 130, 0, 8, 1, 1
	delay 3
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_TARGET, 2, 0, 8, 1
	delay 20
	setarg 7, 0xFFFF
	playsewithpan SE_W020, +63
	waitforvisualfinish
	end
Status_FireSpin:
	loadspritegfx 0x272D
	playsewithpan SE_W221B, +63
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 2, 30, 1
	call FireSpinEffect
	call FireSpinEffect
	waitforvisualfinish
	stopsound
	end
Status_Whrilpool:
	loadspritegfx 0x27A5
	monbg ANIM_DEF_PARTNER
	monbgprio_28 ANIM_TARGET
	setalpha 12, 8
	delay 0
	createsprite gSimplePaletteBlendSpriteTemplate, 0, 4, 2, 0, 7, RGB(0, 13, 23)
	playsewithpan SE_W250, +63
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 2, 30, 1
	call WhirlpoolEffect
	call WhirlpoolEffect
	delay 12
	createsprite gSimplePaletteBlendSpriteTemplate, 0, 4, 2, 7, 0, RGB(0, 13, 23)
	waitforvisualfinish
	stopsound
	clearmonbg ANIM_DEF_PARTNER
	end
Status_Clamp:
	loadspritegfx 0x27A1
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W011, +63
	createsprite gUnknown_08597098, 2, -32, 0, 2, 819, 0, 10
	createsprite gUnknown_08597098, 2, 32, 0, 6, -819, 0, 10
	delay 10
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 3, 0, 5, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	waitforvisualfinish
	end
Status_SandTomb:
	loadspritegfx ANIM_TAG_074
	createsprite gSimplePaletteBlendSpriteTemplate, 0, 4, 2, 0, 7, RGB(19, 17, 0)
	createvisualtask AnimTask_ShakeMon, 5, ANIM_TARGET, 0, 2, 30, 1
	playsewithpan SE_W328, +63
	call SandTombEffect
	call SandTombEffect
	delay 0x16
	createsprite gSimplePaletteBlendSpriteTemplate, 0, 4, 2, 7, 0, RGB(19, 17, 0)
	waitforvisualfinish
	stopsound
	end

General_ItemEffect:
	loadspritegfx ANIM_TAG_203
	loadspritegfx ANIM_TAG_049
	delay 0
	playsewithpan SE_W036, -64
	createvisualtask sub_80D622C, 2, 16, 128, 0, 2
	waitforvisualfinish
	playsewithpan SE_W036, -64
	createvisualtask sub_80D622C, 2, 16, 128, 0, 2
	waitforvisualfinish
	playsewithpan SE_W036, -64
	createvisualtask sub_80D622C, 2, 16, 128, 0, 2
	waitforvisualfinish
	playsewithpan SE_W234, -64
	call GrantingStarsEffect
	waitforvisualfinish
	playsewithpan SE_REAPOKE, -64
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 2, 3, 7, 0, RGB(17, 31, 25)
	createsprite gUnknown_0859381C, 3, 0, 0, 0, 0
	waitforvisualfinish
	end

General_SmokeballEscape:
	loadspritegfx 0x2802
	monbg ANIM_ATTACKER
	setalpha 12, 4
	delay 0
	playsewithpan SE_BOWA2, +63
	createsprite gUnknown_085CE734, 0x80, 0, 32, 28, 30
	delay 4
	playsewithpan SE_BOWA2, +63
	createsprite gUnknown_085CE734, 127, 2, 12, 20, 30
	delay 12
	playsewithpan SE_BOWA2, +63
	createsprite gUnknown_085CE734, 0x7E, 2, -28, 4, 30
	delay 12
	playsewithpan SE_BOWA2, +63
	createsprite gUnknown_085CE734, 0x7C, 2, 14, -20, 30
	delay 4
	playsewithpan SE_BOWA2, +63
	createvisualtask sub_81136E8, 2, 2
	createsprite gUnknown_085CE734, 0x7B, 3, 4, 4, 30
	delay 14
	playsewithpan SE_BOWA2, +63
	createsprite gUnknown_085CE734, 0x7A, 3, -14, 18, 46
	delay 0
	createsprite gUnknown_085CE734, 0x79, 3, 14, -14, 46
	delay 0
	createsprite gUnknown_085CE734, 120, 3, -12, -10, 46
	delay 0
	createsprite gUnknown_085CE734, 0x77, 3, 14, 14, 46
	delay 0
	createsprite gUnknown_085CE734, 0x76, 3, 0, 0, 46
	waitforvisualfinish
	clearmonbg ANIM_ATTACKER
	invisible ANIM_ATTACKER
	delay 0
	blendoff
	end

General_HangedOn:
	createsprite gSimplePaletteBlendSpriteTemplate, 0, 2, 7, 0, 9, RGB_RED
	playsewithpan SE_W082, -64
	createvisualtask sub_815DB90, 5, 30, 128, 0, 1, 2, 0, 1
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 0, 2, 4, 9, 0, RGB_RED
	waitforvisualfinish
	delay 6
	createsprite gSlideMonToOriginalPosSpriteTemplate, 0, 0, 0, 15
	end

General_Rain:
	loadspritegfx 0x2783
	playsewithpan SE_W240, -64
	createvisualtask sub_8116620, 10, 0x781, 2, 0, 4, RGB_BLACK
	waitforvisualfinish
	createvisualtask AnimTask_CreateRaindrops, 2, 0, 3, 60
	createvisualtask AnimTask_CreateRaindrops, 2, 0, 3, 60
	delay 50
	waitforvisualfinish
	createvisualtask sub_8116620, 10, 0x781, 2, 4, 0, RGB_BLACK
	waitforvisualfinish
	end

General_Sun:
	goto Move_SUNNY_DAY

General_Sandstorm:
	goto Move_SANDSTORM

General_Hail:
	goto Move_HAIL

General_LeechSeedDrain:
	createvisualtask sub_817351C, 5
	delay 0
	goto Move_ABSORB

General_MonHit:
	loadspritegfx ANIM_TAG_135
	monbg ANIM_TARGET
	setalpha 12, 8
	playsewithpan SE_W003, +63
	createsprite gBasicHitSplatSpriteTemplate, 2, 0, 0, 1, 2
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 3, 0, 6, 1
	waitforvisualfinish
	clearmonbg ANIM_TARGET
	blendoff
	end

General_ItemSteal:
	loadspritegfx 0x27F0
	createvisualtask sub_8117F30, 2
	createvisualtask sub_8172ED0, 2
	delay 1
	createsprite gUnknown_08592670, 2, 0, -5, 10, 2, -1
	end

General_SnatchMove:
	loadspritegfx 0x27F0
	createvisualtask sub_8117E94, 2
	call AnimScript_82D85A3
	delay 1
	createvisualtask AnimTask_SwayMon, 2, 0, 5, 5120, 4, ANIM_TARGET
	waitforvisualfinish
	createvisualtask AnimTask_IsTargetSameSide, 2
	jumpretfalse SnatchOpposingMonMove
	goto SnatchPartnerMonMove
SnatchMoveContinue:
	waitforvisualfinish
	call AnimScript_82D85C3
	end
SnatchOpposingMonMove:
	playsewithpan SE_W104, -64
	createvisualtask sub_815F8F4, 2
	goto SnatchMoveContinue
SnatchPartnerMonMove:
	playsewithpan SE_W104, -64
	createvisualtask sub_815FFC4, 2
	goto SnatchMoveContinue

General_FutureSightHit:
	createvisualtask sub_8117F10, 2
	monbg ANIM_DEF_PARTNER
	playsewithpan SE_W060, -64
	call SetPsychicBackground
	setalpha 8, 8
	playsewithpan SE_W048, +63
	waitplaysewithpan SE_W048, +63, 8
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 4, 0, 15, 1
	createvisualtask AnimTask_ScaleMonAndRestore, 5, -5, -5, 15, ANIM_TARGET, 1
	waitforvisualfinish
	createvisualtask AnimTask_ShakeMon, 2, ANIM_TARGET, 4, 0, 24, 1
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	waitforvisualfinish
	delay 1
	call UnsetPsychicBackground
	end

General_DoomDesireHit:
	createvisualtask sub_8117F10, 2
	loadspritegfx 0x27D6
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 3, 0, 16, RGB_WHITE
	waitforvisualfinish
	delay 10
	createvisualtask sub_815C0A4, 5
	delay 0x9
	playsewithpan SE_W109, -64
	delay 0x9
	playsewithpan SE_W109, 0
	delay 0x9
	playsewithpan SE_W109, +63
	delay 25
	createvisualtask AnimTask_ShakeMonInPlace, 2, ANIM_TARGET, 10, 0, 20, 1
	playsewithpan SE_W120, +63
	createsprite gBattleAnimSpriteTemplate_859371C, 3, 0, 0, 1, 1
	delay 6
	playsewithpan SE_W120, +63
	createsprite gBattleAnimSpriteTemplate_859371C, 3, 24, -24, 1, 1
	delay 6
	playsewithpan SE_W120, +63
	createsprite gBattleAnimSpriteTemplate_859371C, 3, -16, 16, 1, 1
	delay 6
	playsewithpan SE_W120, +63
	createsprite gBattleAnimSpriteTemplate_859371C, 3, -24, -12, 1, 1
	delay 6
	playsewithpan SE_W120, +63
	createsprite gBattleAnimSpriteTemplate_859371C, 3, 16, 16, 1, 1
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 3, 16, 0, RGB_WHITE
	waitforvisualfinish
	end

General_FocusPunchSetUp:
	loadspritegfx 0x27C8
	playsewithpan SE_W082, -64
	call EndureEffect
	delay 8
	createvisualtask sub_8115A04, 2, 2, 2, 2, 0, 11, RGB_RED
	createvisualtask AnimTask_ShakeMon2, 2, ANIM_ATTACKER, 1, 0, 32, 1
	call EndureEffect
	delay 8
	call EndureEffect
	waitforvisualfinish
	end

General_IngrainHeal:
	loadspritegfx 0x27A3
	loadspritegfx ANIM_TAG_031
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 0, 4, RGB(13, 31, 12)
	waitforvisualfinish
	delay 3
	call AbsorbEffect
	waitforvisualfinish
	delay 15
	call HealingEffect
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 1, 4, 0, RGB(13, 31, 12)
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	end

General_WishHeal:
	loadspritegfx ANIM_TAG_049
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 3, 0, 10, RGB_BLACK
	waitforvisualfinish
	playsewithpan SE_W025, -64
	call GrantingStarsEffect
	waitforvisualfinish
	unloadspritegfx ANIM_TAG_049
	loadspritegfx ANIM_TAG_031
	call HealingEffect
	waitforvisualfinish
	createsprite gSimplePaletteBlendSpriteTemplate, 2, 1, 3, 10, 0, RGB_BLACK
	end

AnimScript_82D85A3:
	createvisualtask sub_8172E9C, 2
	jumpreteq 1, AnimScript_82D85B4
AnimScript_82D85B2:
	waitforvisualfinish
	return
AnimScript_82D85B4:
	createvisualtask sub_8172BF0, 2, 1
	waitforvisualfinish
	goto AnimScript_82D85B2

AnimScript_82D85C3:
	createvisualtask sub_8172E9C, 2
	jumpreteq 1, AnimScript_82D85D4
AnimScript_82D85D2:
	waitforvisualfinish
	return
AnimScript_82D85D4:
	createvisualtask sub_8172BF0, 2, 0
	waitforvisualfinish
	goto AnimScript_82D85D2

Special_LevelUp:
	playsewithpan SE_EXPMAX, 0
	createvisualtask sub_8170920, 2
	delay 0
	createvisualtask sub_8170A0C, 5, 0, 0
	waitforvisualfinish
	createvisualtask sub_81709EC, 2
	end

Special_SwitchOutPlayerMon:
	createvisualtask sub_8170BB0, 2
	delay 10
	createvisualtask sub_8170B04, 2
	end

Special_SwitchOutOpponentMon:
	createvisualtask sub_8170BB0, 2
	delay 10
	createvisualtask sub_8170B04, 2
	end

Special_BallThrow:
	createvisualtask sub_8170CFC, 2
	delay 0
	playsewithpan SE_NAGERU, 0
	createvisualtask sub_8170E04, 2
	createvisualtask AnimTask_IsBallBlockedByTrainer, 2
	jumpreteq 0xFFFF, BallThrowTrainerBlock
BallThrowEnd:
	waitforvisualfinish
	createvisualtask sub_8170D24, 2
	end
BallThrowTrainerBlock:
	loadspritegfx ANIM_TAG_135
	delay 25
	monbg ANIM_DEF_PARTNER
	setalpha 12, 8
	delay 0
	playsewithpan SE_W003, +63
	createsprite gBasicHitSplatSpriteTemplate, 130, -4, -20, 1, 2
	waitforvisualfinish
	clearmonbg ANIM_DEF_PARTNER
	blendoff
	goto BallThrowEnd

Special_SafariBallThrow:
	createvisualtask sub_8170CFC, 2
	delay 0
	createvisualtask sub_8170F2C, 2
	waitforvisualfinish
	createvisualtask sub_8170D24, 2
	end

Special_SubstituteToMon:
	createvisualtask sub_8172BF0, 2, 1
	end

Special_MonToSubstitute:
	createvisualtask sub_8172BF0, 2, 0
	end
