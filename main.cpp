#include "menu.c"

int main (void)
{
    struct menuStruct startMenu;
    initAStartMenu(&startMenu);
    createSubMenu(10, &startMenu);
    char strInf[10][10]={"1","2","3","4","5","6","7","8","9","10"};
    setSubMenuStr(strInf,&startMenu);
    printf("%s\n",startMenu.childrenMenus[9].menuStr);
    startMenu.Subs();
    return 0;
} 
