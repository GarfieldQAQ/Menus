#include "menu.c"
#include <stdio.h>
#include<iostream>
using namespace std;
class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int currentIndex = 0;
        int temp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i]==0)
            {
                temp = nums[currentIndex];
                nums[currentIndex] = nums[i];
                nums[i] = temp;
                currentIndex ++;
            }
        }
        for (int i = currentIndex; i < nums.size(); i++)
        {
            if (nums[i]==1)
            {
                temp = nums[currentIndex];
                nums[currentIndex] = nums[i];
                currentIndex ++;
            }
        }
        for (int i = currentIndex; i < nums.size(); i++)
        {
            if (nums[i]==2)
            {
                temp = nums[currentIndex];
                nums[currentIndex] = nums[i];
                currentIndex ++;
            }
        }

    }
};
int main (void)
{
    struct menuStruct startMenu;
    initAStartMenu(&startMenu);
    createSubMenu(10, &startMenu);
    createSubMenu(10,&startMenu.childrenMenus[0]);
    char strInf[10][20]={"1","2","3","4","5","6","7","8","9","10"};
    setSubMenuStr(strInf,&startMenu);
    setSubMenuStr(strInf,&startMenu.childrenMenus[0]);
    printf("%s\n",startMenu.childrenMenus[9].menuStr);
    printf("%s\n",startMenu.childrenMenus[0].childrenMenus[9].menuStr);
    return 0;
} 
