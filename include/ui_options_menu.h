#ifndef GUARD_UI_OPTIONS_MENU_H
#define GUARD_UI_OPTIONS_MENU_H

#include "main.h"

void Task_OpenOptionsMenuFromStartMenu(u8 taskId);
void Options_Menu_Init(MainCallback callback);
void CB2_InitUIOptionMenu(void);

#endif // GUARD_UI_OPTIONS_MENU_H