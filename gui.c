//
// Created by Cyber on 2025/5/13.
//
#include "gui.h"

void guiInit(void)
{
    struct menuStruct startMenu;
    initAStartMenu(&startMenu);
    createSubMenu(12, &startMenu);
    char strInf[12][10]={"1","2","3","4","5","6","7","8","9","10","11","12"};


}

void guiChangeStatus(void)