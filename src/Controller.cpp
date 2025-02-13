#include "../include/Controller.h"
#include "../include/XMLDocument.h"
#include "../include/XMLCardHolder.h"

#include <iostream>

Controller::Controller(XMLCardHolder* holder)
{
    this->holder = holder;
}

Controller::~Controller()
{
    delete this->holder;
}

void Controller::createCard()
{
    std::string name, phoneNumber, emailAddress, taxNumber, userInputChoose;

    std::cout << "You choose create card option" << std::endl;

    do {
        std::cout << "Business or Private card? [business/private]: ";
        std::cin >> userInputChoose;
    } while (userInputChoose != "business" && userInputChoose != "private");

    std::cout << "Provide data" << std::endl;
    std::cout << "Name: ";
    std::cin >> name;
    std::cout << "Phone number: ";
    std::cin >> phoneNumber;
    std::cout << "Email address: ";
    std::cin >> emailAddress;

    if (userInputChoose == "business") {
        std::cout << "Tax number (if not press enter): ";
        std::cin >> taxNumber;
    }

    this->holder->add(CardFactory::createFromUserInput(phoneNumber, name, emailAddress, taxNumber));
}

void Controller::removeCard()
{
    int cardIdToRemove;

    std::cout << "You choose remove card option" << std::endl;
    this->holder->printWithId();
    std::cout << "Type card id you want to delete: ";
    std::cin >> cardIdToRemove;
    this->holder->remove(cardIdToRemove);
    std::cout << "Removed card successfully" << std::endl;
}

void Controller::editCard()
{
    int cardIdToRemove;
    std::string userAction, userActionValue;

    std::cout << "You choose edit card option" << std::endl;
    this->holder->printWithId();
    std::cout << "Type card id you want to edit: ";
    std::cin >> cardIdToRemove;
    Card* card = this->holder->get(cardIdToRemove);
    card->render();
    std::cout << "What would you like to edit [name, email, phone]: ";
    std::cin >> userAction;
    std::cout << "New " << userAction << " is: ";
    std::cin >> userActionValue;

    if (userAction == "name") {
        card->changeName(userActionValue);
    }

    if (userAction == "phone") {
        card->changePhoneNumber(userActionValue);
    }

    if (userAction == "email") {
        card->changeEmail(userActionValue);
    }
}

void Controller::import()
{
    std::string userDocumentPath;

    std::cout << "You choose import card option" << std::endl;
    std::cout << "Provide document path: ";
    std::cin >> userDocumentPath;

    //example imput path: ../data/import/in.xml
    try {
        XMLDocument document(userDocumentPath, new CardFactory);
        this->holder->import(document);
    } catch (...) {
        std::cout << "Card not found file for provided path: \"" << userDocumentPath << "\"" << std::endl;
    }
}

void Controller::search()
{
    std::string userSearchPhrase;

    std::cout << "You choose search card option" << std::endl;
    std::cout << "Provide search phrase: ";
    std::cin >> userSearchPhrase;

    try {
        this->holder->getByPhrase(userSearchPhrase)->render();
    } catch (...) {
        std::cout << "Card not found for provided search phrase: \"" << userSearchPhrase << "\"" << std::endl;
    }
}

void Controller::print()
{
    this->holder->print();
}

void Controller::exportToXML()
{
    this->holder->exportToDocument();
}
