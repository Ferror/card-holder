#ifndef BUSINESS_CARD_H
#define BUSINESS_CARD_H

#include "Card.h"

class BusinessCard : public Card
{
    private:
        std::string taxNumber;

    public:
        BusinessCard(std::string phoneNumber, std::string name, std::string email, std::string taxNumber);
        ~BusinessCard() = default;
};

#endif
