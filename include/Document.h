#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "../vendor/tinyxml2/include/tinyxml2.h"
#include "Card.h"

#include <vector>

class Document
{
    public:
        virtual ~Document() = default;
        virtual std::vector<Card*> getCards() = 0;
};

#endif
