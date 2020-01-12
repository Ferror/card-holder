#ifndef XML_CARD_HOLDER_H
#define XML_CARD_HOLDER_H

#include "CardHolder.h"
#include "Document.h"

#include <vector>

class XMLCardHolder : public CardHolder
{
    private:
        std::vector<Card*> cardList;

    public:
        XMLCardHolder();
        XMLCardHolder(Document& document);
        ~XMLCardHolder();
        void add(Card* card);
        void remove(int position);
        void import(Document document);
        void print();
};

#endif
