#ifndef GUARD_NEW_MENU_HELPERS_H
#define GUARD_NEW_MENU_HELPERS_H

#include "text.h"
#include "task.h"

void sub_81971D0(void);
void sub_8197200(void);
void sub_81973A4(void);
void NewMenuHelpers_DrawDialogueFrame(u8, u8);
void sub_819746C(u8 windowId, bool8 copyToVram);
void NewMenuHelpers_DrawStdWindowFrame(u8, u8);
u16 AddTextPrinterParameterized(u8 windowId, u8 fontId, const u8 *str, u8 speed, void (*callback)(struct TextSubPrinter *, u16), u8 fgColor, u8 bgColor, u8 shadowColor);
void DisplayItemMessageOnField(u8 taskId, const u8 *src, TaskFunc callback);
void sub_8197434(u8 a0, u8 a1);
void SetStandardWindowBorderStyle(u8 a0, u8 a1);
void sub_8197930(void);
u8 GetPlayerTextSpeed(void);
void sub_81978B0(u16 arg0);

#endif // GUARD_NEW_MENU_HELPERS_H
