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

void XMLCardHolder::import(Document& document)
{
    for (Card* card : document.getCards()) {
        this->cardList.push_back(card);
    }
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
    try {
        return this->cardList.at(position);
    } catch (const std::out_of_range& e) {
        return nullptr;
    }
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

void XMLCardHolder::exportToDocument()
{
    tinyxml2::XMLDocument* document = new tinyxml2::XMLDocument();
    tinyxml2::XMLNode* pRoot = document->NewElement("cards");
    document->InsertFirstChild(pRoot);

    for (Card* card : this->cardList) {
        tinyxml2::XMLElement* pListElement = document->NewElement("card");

        pRoot->InsertEndChild(card->getXML(pListElement, document));
    }

    document->SaveFile("../data/export/out.xml");

    delete document;
}
