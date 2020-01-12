#ifndef MENU_H
#define MENU_H

#include <vector>
#include "MenuOption.h"

class Menu
{
    private:
        std::vector<MenuOption> optionList;

    public:
        Menu();
        ~Menu();
        void print();
};

#endif
