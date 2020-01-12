#include "../include/CardFactory.h"
#include "../include/BusinessCard.h"
#include "../include/PrivateCard.h"

#include <stdexcept>

Card* CardFactory::createFromXML(tinyxml2::XMLNode* child)
{
    tinyxml2::XMLNode* node = child->FirstChild();

    std::string type(node->FirstChild()->Value());
    node = node->NextSibling();
    std::string phoneNumber(node->FirstChild()->Value());
    node = node->NextSibling();
    std::string name(node->FirstChild()->Value());
    node = node->NextSibling();
    std::string email(node->FirstChild()->Value());

    if (type == "business") {
        node = node->NextSibling();
        std::string taxNumber(node->FirstChild()->Value());

        return new BusinessCard(phoneNumber, name, email, taxNumber);
    }

    if (type == "private") {
        return new PrivateCard(phoneNumber, name, email);
    }

    throw std::invalid_argument("invalid card type");
}

Card* CardFactory::createFromUserInput(
    std::string phoneNumber,
    std::string name,
    std::string email,
    std::string taxNumber
) {
    if (taxNumber.empty()) {
        return new PrivateCard(phoneNumber, name, email);
    }

    return new BusinessCard(phoneNumber, name, email, taxNumber);
}
