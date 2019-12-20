#ifndef PRIVATE_CARD_H
#define PRIVATE_CARD_H

#include "Card.h"

class PrivateCard : public Card
{
    public:
        PrivateCard(std::string phoneNumber, std::string name, std::string email);
        ~PrivateCard() = default;
};

#endif
