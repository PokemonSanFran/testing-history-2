#ifndef GUARD_UI_MENU_H
#define GUARD_UI_MENU_H

#include "main.h"

void Task_OpenMenuFromStartMenu(u8 taskId);
void Menu_Init(MainCallback callback);
void ClearStartMenuDataBeforeExit();
void Menu_FreeResources(void);
void Menu_RunSetup(void);

#endif // GUARD_UI_MENU_H
