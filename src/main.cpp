#include "../include/Controller.h"
#include "../include/Menu.h"

#include <iostream>

int main()
{
    Menu menu;
    int chosenOption;

    do {
        menu.print();
        std::cout<<"Podaj wartosc: ";
        std::cin >> chosenOption;

        switch (chosenOption) {
            case 0:
                break;
            case 1:
                Controller::createCard();
                break;
            case 2:
                Controller::removeCard();
                break;
            case 3:
                Controller::editCard();
                break;
            case 4:
                Controller::import();
                break;
            case 5:
                Controller::search();
                break;
            case 6:
                Controller::print();
                break;
            default:
                std::cout << "Invalid menu option" << std::endl;
                break;
        }
    } while (chosenOption != 0);

    return 0;
}
