#include "menu.h"


void initAStartMenu(struct menuStruct* menu)
{
	menu->childrenNums = 0;
	menu->layerNum = 0;
	menu->num = 0;
	menu->menuStr = "Start Menu";
	menu->childrenMenus = NULL;
	menu->parentMenus = NULL;
	menu->Buttons = pressButtonHandler;
	menu->Apps =  NULL;
}

void createSubMenu(uint8_t itemsNum, struct menuStruct* startMenu)
{
	uint8_t i = 0;
	struct menuStruct menuList[itemsNum];
	startMenu->childrenMenus = menuList;
	startMenu->childrenNums = itemsNum;
	for (i = 0; i < itemsNum; i++)
	{
		initAStartMenu(&menuList[i]);
		menuList[i].parentMenus = startMenu;
		menuList[i].num = i;
		menuList[i].menuStr = "default";
		menuList[i].layerNum = startMenu->layerNum + 1;
	}
}

struct menuStruct* enterAimMenu(uint8_t layers, struct menuStruct* startMenu)
{
	uint8_t i;
	struct menuStruct* tempPtr;
	tempPtr = startMenu;
	for(i = 0; i < layers; i++)
	{
		tempPtr = tempPtr->childrenMenus;
	}
	return tempPtr;
}

void setSubMenuStr(char strInf[][10], struct menuStruct* startMenu)
{
	uint8_t i = 0;
	for (i = 0; i < startMenu->childrenNums; i++)
	{
		startMenu->childrenMenus[i].menuStr = strInf[i];
	}
}

void pressButtonHandler(void)
{
	printf("Pressed Button Handler!\n");
	printf("Œ“∞¥Q¿≤~~~\n");
}
