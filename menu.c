#include "menu.h"
#include <stdlib.h>



void initAStartMenu(struct menuStruct* menu)
{
	menu->childrenNums = 0;
	menu->layerNum = 0;
	menu->num = 0;
	menu->menuStr = "Start Menu";
	menu->childrenMenus = nullptr;
	menu->parentMenus = nullptr;
	menu->Apps =  nullptr;
}

void createSubMenu(uint8_t itemsNum, struct menuStruct* startMenu)
{
	uint8_t i = 0;
	struct menuStruct menuList[itemsNum];
	startMenu->childrenMenus = (struct menuStruct*)malloc(sizeof(menuList[itemsNum]));			//在单片机上不加会导致分配不到内存
	startMenu->childrenNums = itemsNum;
	for (i = 0; i < itemsNum; i++)
	{
		initAStartMenu(&startMenu->childrenMenus[i]);
		startMenu->childrenMenus[i].parentMenus = startMenu;
		startMenu->childrenMenus[i].num = i;
		startMenu->childrenMenus[i].menuStr = (const char*)malloc(sizeof("default"));						//为string申请好空间，因为变量常驻不需要考虑free
		startMenu->childrenMenus[i].menuStr = "default";
		startMenu->childrenMenus[i].layerNum = startMenu->layerNum + 1;
	}
}

struct menuStruct* enterSubMenu(uint8_t num, struct menuStruct* startMenu)
{
	return &startMenu->childrenMenus[num];
}

struct menuStruct* enterUpMenu( struct menuStruct* startMenu)
{
	return startMenu->parentMenus;
}

void setSubMenuStr(char strInf[][20], struct menuStruct* startMenu)
{
	uint8_t i = 0;
	for (i = 0; i < startMenu->childrenNums; i++)
	{
		startMenu->childrenMenus[i].menuStr = (char*)sizeof(strInf[i]);
		startMenu->childrenMenus[i].menuStr = strInf[i];
	}
}

void normalMenuApp(void)
{

}
void specificMenuApp(void)
{

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
