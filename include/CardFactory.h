#ifndef CARD_FACTORY_H
#define CARD_FACTORY_H

#include "Card.h"
#include "../vendor/tinyxml2/include/tinyxml2.h"

#include <string>

class CardFactory
{
    public:
        static Card* createFromXML(tinyxml2::XMLNode* child);
        static Card* createFromUserInput(std::string phoneNumber, std::string name, std::string email, std::string taxNumber);
};

#endif
