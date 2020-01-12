#ifndef MENU_OPTION_H
#define MENU_OPTION_H

#include <string>

class MenuOption
{
    private:
        std::string label;
        int option;

    public:
        MenuOption(std::string label, int option);
        ~MenuOption();
        void render();
};

#endif
