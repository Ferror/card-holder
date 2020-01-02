#ifndef CARD_FACTORY_H
#define CARD_FACTORY_H

#include "Card.h"
#include "../vendor/tinyxml2/tinyxml2.h"

#include <string>

class CardFactory
{
    public:
        Card* createFromXML(tinyxml2::XMLNode* child);
};

#endif
