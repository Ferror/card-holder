#include "../include/MenuOption.h"

#include <iostream>
#include <utility>

MenuOption::MenuOption(std::string label, int option)
{
    this->label = std::move(label);
    this->option = option;
}

MenuOption::~MenuOption() = default;

void MenuOption::render()
{
    std::cout << this->option << ". " << this->label << std::endl;
}
