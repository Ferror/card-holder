#include "../include/XMLCardHolder.h"

#include <iostream>

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

void XMLCardHolder::printWithId()
{
    int i = 0;

    for (Card* card : this->cardList) {
        card->renderWithId(i);
        i++;
    }
}

Card* XMLCardHolder::get(int position)
{
    return this->cardList.at(position);
}

Card* XMLCardHolder::getByPhrase(std::string phrase)
{
    for (Card* card : this->cardList) {
        if (card->containPhrase(phrase)) {
            return card;
        }
    }

    throw std::invalid_argument("There is no card with phrase: " + phrase);
}
