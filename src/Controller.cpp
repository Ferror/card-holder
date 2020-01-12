#include "../include/Controller.h"
#include "../include/XMLDocument.h"
#include "../include/XMLCardHolder.h"

#include <iostream>

void Controller::createCard()
{
    std::cout << "You choose create card option" << std::endl;
}

void Controller::removeCard()
{
    std::cout << "You choose remove card option" << std::endl;
}

void Controller::editCard()
{
    std::cout << "You choose edit card option" << std::endl;
}

void Controller::import()
{
    std::cout << "You choose import card option" << std::endl;
}

void Controller::search()
{
    std::cout << "You choose search card option" << std::endl;
}

void Controller::print()
{
    XMLDocument document("../data/xml/cards.xml", CardFactory());
    XMLCardHolder holder(document);
    holder.print();
}
