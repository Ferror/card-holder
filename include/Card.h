#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
    protected:
        std::string phoneNumber;
        std::string name;
        std::string email;

    public:
        virtual void render() = 0;
};

#endif
