#ifndef GUARD_UI_MUGSHOT
#define GUARD_UI_MUGSHOT

#include "main.h"

void DrawMugshot(void); //VAR_0x8000 = mugshot id
void ClearMugshot(void);
void DrawMessageBoxAddOns(u8 windowId);
void ClearMessageBoxAddOns();
void DestroySpeakerIconSprite(void);
void ForceClearMessageBoxData(void);

#endif // GUARD_UI_MUGSHOT