#ifndef PRIVATE_CARD_H
#define PRIVATE_CARD_H

#include "Card.h"

class PrivateCard : public Card
{
    public:
        PrivateCard(std::string phoneNumber, std::string name, std::string email);
        ~PrivateCard();
        void render() override;
        void renderWithId(int id) override;
        void changeName(std::string newName) override;
        void changeEmail(std::string newEmailAddress) override;
        void changePhoneNumber(std::string newPhoneNumber) override;
        bool containPhrase(std::string phrase) override;
        tinyxml2::XMLNode* getXML(tinyxml2::XMLElement* element, tinyxml2::XMLDocument* document) override;
};

#endif
