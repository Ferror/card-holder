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
        void add(Card* card) override;
        void remove(int position) override;
        Card* get(int position) override;
        Card* getByPhrase(std::string phrase) override;
        void import(Document document) override;
        void print() override;
        void printWithId();
};

#endif
