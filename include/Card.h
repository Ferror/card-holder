#ifndef CARD_H
#define CARD_H

#include "../vendor/tinyxml2/include/tinyxml2.h"

#include <string>

class Card
{
    protected:
        std::string phoneNumber;
        std::string name;
        std::string email;

    public:
        virtual ~Card() = default;
        virtual void render() = 0;
        virtual void renderWithId(int id) = 0;
        virtual void changeName(std::string newName) = 0;
        virtual void changeEmail(std::string newEmail) = 0;
        virtual void changePhoneNumber(std::string newPhoneNumber) = 0;
        virtual bool containPhrase(std::string phrase) = 0;
        virtual tinyxml2::XMLNode* getXML(tinyxml2::XMLElement* element, tinyxml2::XMLDocument* document) = 0;
};

#endif
