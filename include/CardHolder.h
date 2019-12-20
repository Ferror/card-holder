#ifndef CARD_HOLDER_H
#define CARD_HOLDER_H

#include "Card.h"
#include "Document.h"

class CardHolder
{
    public:
        virtual void add() = 0;
        virtual void remove(int position) = 0;
        virtual void removeElement(Card card) = 0;
        virtual Card get(int position) = 0;
        virtual Card getElement(Card card) = 0;
        virtual Document createDocument() = 0;
        virtual void import(Document document) = 0;
};

#endif
