#ifndef MENU_H
#define MENU_H

#include "MenuOption.h"

#include <vector>

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
