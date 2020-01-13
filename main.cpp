#include "include/Controller.h"
#include "include/Menu.h"
#include "include/XMLDocument.h"

#include <iostream>

int main()
{
    Menu menu;
    XMLDocument document("../data/xml/cards.xml", new CardFactory);
    Controller controller(new XMLCardHolder(document));
    int chosenOption;

    do {
        menu.print();
        std::cout<<"Podaj wartosc: ";
        std::cin >> chosenOption;

        switch (chosenOption) {
            case 0:
                break;
            case 1:
                controller.createCard();
                break;
            case 2:
                controller.removeCard();
                break;
            case 3:
                controller.editCard();
                break;
            case 4:
                controller.import();
                break;
            case 5:
                controller.search();
                break;
            case 6:
                controller.print();
                break;
            case 7:
                controller.exportToXML();
                break;
            default:
                std::cout << "Invalid menu option" << std::endl;
                break;
        }
    } while (chosenOption != 0);

    return 0;
}
