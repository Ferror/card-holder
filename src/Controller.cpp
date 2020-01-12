#include "../include/Controller.h"
#include "../include/XMLDocument.h"
#include "../include/XMLCardHolder.h"

#include <iostream>

Controller::Controller(XMLCardHolder* holder)
{
    this->holder = holder;
}

void Controller::createCard()
{
    std::string name, phoneNumber, emailAddress, taxNumber;

    std::cout << "You choose create card option" << std::endl;
    std::cout << "Provide data" << std::endl;
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Phone number: ";
    std::cin >> phoneNumber;
    std::cout << "Email address: ";
    std::cin >> emailAddress;
    std::cout << "Tax number (if not press enter): ";
    std::cin >> taxNumber;

    this->holder->add(CardFactory::createFromUserInput(phoneNumber, name, emailAddress, taxNumber));
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
    this->holder->print();
}

Controller::~Controller()
{
    delete this->holder;
}
