#include "../include/XMLDocument.h"

XMLDocument::XMLDocument(const char *filename, CardFactory factory)
{
    this->fileName = filename;
    this->factory = factory;
}

std::vector<Card*> XMLDocument::getCards()
{
    std::vector<Card*> list;
    tinyxml2::XMLDocument document;
    document.LoadFile(this->fileName);
    tinyxml2::XMLNode* child = document.FirstChildElement("cards")->FirstChild();

    while (child != nullptr) {
        list.push_back(this->factory.createFromXML(child));

        child = child->NextSibling();
    }

    return list;
}
