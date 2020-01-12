#ifndef BUSINESS_CARD_H
#define BUSINESS_CARD_H

#include "Card.h"

class BusinessCard : public Card
{
    private:
        std::string taxNumber;

    public:
        BusinessCard(std::string phoneNumber, std::string name, std::string email, std::string taxNumber);
        ~BusinessCard();
        void render() override;
        void renderWithId(int id) override;
        void changeName(std::string newName) override;
        void changeEmail(std::string newEmailAddress) override;
        void changePhoneNumber(std::string newPhoneNumber) override;
        bool containPhrase(std::string phrase) override;
};

#endif
