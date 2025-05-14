#ifndef MENU__H
#define MENU__H
#include "stdint.h"

struct menuStruct
{
	uint8_t childrenNums;												// 记录子菜单个数
	uint8_t layerNum;													// 记录层级
	uint8_t num;														// 同级菜单排序
	const char* menuStr;												// 菜单字符串
	void (*Buttons)();													// 按键实现
	void (*Apps)();														//仅在底层绑定APP功能
	struct menuStruct *childrenMenus;
	struct menuStruct *parentMenus;
};
void initAStartMenu(struct menuStruct* menu);
void createSubMenu(uint8_t itemsNum, struct menuStruct* startMenu);
struct menuStruct* enterAimMenu(uint8_t layers, struct menuStruct* startMenu);
void setSubMenuStr(char strInf[][10], struct menuStruct* startMenu);
void pressButtonHandler(void);





#endif
