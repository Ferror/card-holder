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

void BusinessCard::render()
{
    std::cout << "[" << icon << "] " << this->name << std::endl;
    std::cout << this->email << std::endl;
}
