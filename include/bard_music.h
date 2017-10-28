#ifndef GUARD_BARD_MUSIC_H
#define GUARD_BARD_MUSIC_H

// Exported type declarations


struct BardSound
{
    /*0x00*/ u8 var00;
    /*0x01*/ s8 var01;
    /*0x02*/ u16 var02;
    /*0x04*/ u16 volume;
    /*0x06*/ u16 var06;
};

struct BardPhoneme
{
    /*0x00*/ u16 length;
    /*0x02*/ u16 pitch;
};

struct BardSong
{
    /*0x00*/ u8 currWord;
    /*0x01*/ u8 currPhoneme;
    /*0x02*/ u8 phonemeTimer;
    /*0x03*/ u8 state;
    /*0x04*/ s16 length;
    /*0x06*/ u16 volume;
    /*0x08*/ s16 pitch;
    /*0x0A*/ s16 voiceInflection;
    /*0x0C*/ u16 lyrics[6];
    /*0x18*/ struct BardPhoneme phonemes[6];
    /*0x30*/ const struct BardSound *sound;
};

// Exported RAM declarations

// Exported ROM declarations

extern const u16 gUnknown_085F5490;

#endif //GUARD_BARD_MUSIC_H
