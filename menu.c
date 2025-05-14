#include "menu.h"
#include <stdlib.h>



void initAStartMenu(struct menuStruct* menu)
{
	menu->childrenNums = 0;
	menu->layerNum = 0;
	menu->num = 0;
	menu->menuStr = "Start Menu";
	menu->childrenMenus = NULL;
	menu->parentMenus = NULL;
	//	menu->Buttons = pressButtonHandler;
	menu->Apps =  NULL;
}

void createSubMenu(uint8_t itemsNum, struct menuStruct* startMenu)
{
	uint8_t i = 0;
	struct menuStruct menuList[itemsNum];
	startMenu->childrenMenus = (struct menuStruct*)malloc(sizeof(menuList[itemsNum]));			//在单片机上不加会导致分配不到内存
	startMenu->childrenNums = itemsNum;
	for (i = 0; i < itemsNum; i++)
	{
		struct menuStruct menu;
		startMenu->childrenMenus[i] = menu;
		initAStartMenu(&startMenu->childrenMenus[i]);
		startMenu->childrenMenus[i].parentMenus = startMenu;
		startMenu->childrenMenus[i].num = i;
		startMenu->childrenMenus[i].menuStr = "default";
		startMenu->childrenMenus[i].layerNum = startMenu->layerNum + 1;
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

void setSubMenuStr(char strInf[][20], struct menuStruct* startMenu)
{
	uint8_t i = 0;
	for (i = 0; i < startMenu->childrenNums; i++)
	{
		startMenu->childrenMenus[i].menuStr = strInf[i];
	}
}







//void pressButtonHandler(void)
//{
//	printf("Pressed Button Handler!\n");
//	printf("我按Q啦~~~\n");
//}

//void appHandler(void)
//{
//	printf("Pressed Button Handler!\n");
//	printf("我按Q啦~~~\n");
//}

//void appChangStatus()
//{
//	printf("APP Change STATUS Handler!\n");

//}
