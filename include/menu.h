#ifndef GUARD_MENU_H
#define GUARD_MENU_H

#include "window.h"

struct MenuAction
{
   const u8 *text;
   u8 (*func)();
};

struct MenuAction2
{
    const u8 *text;
    void (*func)(u8);
};

void box_print(u8, u8, u8, u8, const void *, s8, const u8 *);
void sub_8198070(u8 windowId, bool8 copyToVram);
void SetWindowTemplateFields(struct WindowTemplate* template, u8 priority, u8 tilemapLeft, u8 tilemapTop, u8 width, u8 height, u8 palNum, u16 baseBlock);
void SetWindowBorderStyle(u8 windowId, bool8 copyToVram, u16 tileStart, u8 palette);
void reset_temp_tile_data_buffers(void);
int decompress_and_copy_tile_data_to_vram(u8 bg_id, const void *src, int size, u16 offset, u8 mode);
bool8 free_temp_tile_data_buffers_if_possible(void);
u64 sub_8198A50(struct WindowTemplate*, u8, u8, u8, u8, u8, u8, u16); // returns something but it isn't used, fix when menu.s is decomp'd

#endif // GUARD_MENU_H
