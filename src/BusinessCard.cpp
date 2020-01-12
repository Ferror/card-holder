#include "../include/BusinessCard.h"

#include <utility>
#include <iostream>

const char icon = 'B';

BusinessCard::BusinessCard(std::string phoneNumber, std::string name, std::string email, std::string taxNumber)
{
    this->phoneNumber = std::move(phoneNumber);
    this->name = std::move(name);
    this->email = std::move(email);
    this->taxNumber = std::move(taxNumber);
}

BusinessCard::~BusinessCard() = default;

void BusinessCard::render()
{
    std::cout << "[" << icon << "] " << this->name << std::endl;
    std::cout << this->email << std::endl;
    std::cout << this->phoneNumber << std::endl;
}

void BusinessCard::renderWithId(int id)
{
    std::cout << "ID: " << id << std::endl;
    this->render();
}

void BusinessCard::changeName(std::string newName)
{
    this->name = newName;
}

void BusinessCard::changeEmail(std::string newEmailAddress)
{
    this->email = newEmailAddress;
}

void BusinessCard::changePhoneNumber(std::string newPhoneNumber)
{
    this->phoneNumber = newPhoneNumber;
}

bool BusinessCard::containPhrase(std::string phrase)
{
    if (this->name.find(phrase) != std::string::npos) {
        return true;
    }

    if (this->email.find(phrase) != std::string::npos) {
        return true;
    }

    if (this->taxNumber.find(phrase) != std::string::npos) {
        return true;
    }

    return this->phoneNumber.find(phrase) != std::string::npos;
}
