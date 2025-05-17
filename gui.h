//
// Created by Cyber on 2025/5/13.
//

#ifndef GUI_H
#define GUI_H
#include "menu.h"

struct guiStruct
{
    struct menuStruct menu;
    uint8_t fontHeight;
    uint8_t rows;
};


void guiInit(struct menuStruct *startMenu);



#endif //GUI_H
