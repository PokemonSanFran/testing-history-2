#ifndef GUARD_UI_MENU_H
#define GUARD_UI_MENU_H

#include "main.h"

void Task_OpenMenuFromStartMenu(u8 taskId);
void Task_OpenMenuFromOverworld(u8 taskId);
void StartMenu_Menu_Init(MainCallback callback, bool8 calledFromOverworld);
#endif // GUARD_UI_MENU_H
