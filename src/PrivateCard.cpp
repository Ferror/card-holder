#include "../include/PrivateCard.h"

#include <utility>
#include <iostream>

const char icon = 'P';

PrivateCard::PrivateCard(std::string phoneNumber, std::string name, std::string email)
{
    this->phoneNumber = std::move(phoneNumber);
    this->name = std::move(name);
    this->email = std::move(email);
}

void PrivateCard::render()
{
    std::cout << "[" << icon << "] " << this->name << std::endl;
    std::cout << this->email << std::endl;
}

PrivateCard::~PrivateCard() = default;
