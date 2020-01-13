#include "../include/PrivateCard.h"

#include <utility>
#include <iostream>

const char icon = 'P';

PrivateCard::PrivateCard(std::string phoneNumber, std::string name, std::string email)
{
    this->phoneNumber = std::move(phoneNumber);
    this->name = std::move(name);
    this->email = std::move(email);
}

PrivateCard::~PrivateCard() = default;

void PrivateCard::render()
{
    std::cout << "[" << icon << "] " << this->name << std::endl;
    std::cout << this->email << std::endl;
    std::cout << this->phoneNumber << std::endl;
}

void PrivateCard::renderWithId(int id)
{
    std::cout << "ID: " << id << std::endl;
    this->render();
}

void PrivateCard::changeName(std::string newName)
{
    this->name = newName;
}

void PrivateCard::changeEmail(std::string newEmailAddress)
{
    this->email = newEmailAddress;
}

void PrivateCard::changePhoneNumber(std::string newPhoneNumber)
{
    this->phoneNumber = newPhoneNumber;
}

bool PrivateCard::containPhrase(std::string phrase)
{
    if (this->name.find(phrase) != std::string::npos) {
        return true;
    }

    if (this->email.find(phrase) != std::string::npos) {
        return true;
    }

    return this->phoneNumber.find(phrase) != std::string::npos;
}

tinyxml2::XMLNode* PrivateCard::getXML(tinyxml2::XMLElement* element, tinyxml2::XMLDocument* document)
{
    tinyxml2::XMLElement* property;

    property = document->NewElement("type");
    property->SetText("business");
    element->InsertEndChild(property);

    property = document->NewElement("name");
    property->SetText(this->name.c_str());
    element->InsertEndChild(property);

    property = document->NewElement("phone-number");
    property->SetText(this->email.c_str());
    element->InsertEndChild(property);

    property = document->NewElement("email");
    property->SetText(this->email.c_str());
    element->InsertEndChild(property);

    return element;
}
