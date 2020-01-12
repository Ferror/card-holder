#include "../include/XMLCardHolder.h"

XMLCardHolder::XMLCardHolder(Document& document)
{
    this->cardList = document.getCards();
}

XMLCardHolder::XMLCardHolder()
{
    std::vector<Card*> emptyList;

    this->cardList = emptyList;
}

XMLCardHolder::~XMLCardHolder()
{
    for (Card* card : this->cardList) {
        delete card;
    }
}

void XMLCardHolder::add(Card* card)
{
    this->cardList.push_back(card);
}

void XMLCardHolder::remove(int position)
{
    this->cardList.erase(this->cardList.begin() + position);
}

void XMLCardHolder::import(Document document)
{
    this->cardList = document.getCards();
}

void XMLCardHolder::print()
{
    for (Card* card : this->cardList) {
        card->render();
    }
}
