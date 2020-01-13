#include "../include/Menu.h"

#include <iostream>

Menu::Menu()
{
    std::vector<MenuOption> list;

    list.push_back(MenuOption("Close program", 0));
    list.push_back(MenuOption("Create card", 1));
    list.push_back(MenuOption("Remove card", 2));
    list.push_back(MenuOption("Edit card", 3));
    list.push_back(MenuOption("Import cards", 4));
    list.push_back(MenuOption("Find card", 5));
    list.push_back(MenuOption("Print cards", 6));
    list.push_back(MenuOption("Export cards to xml file", 7));

    this->optionList = list;
}

Menu::~Menu() = default;

void Menu::print()
{
    std::cout << "Menu: " << std::endl;

    for (MenuOption option : this->optionList) {
        option.render();
    }
}
