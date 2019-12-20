
#include "../include/BusinessCard.h"
#include "../include/PrivateCard.h"

int main()
{
    BusinessCard BCard(
        std::string("a"),
        std::string("b"),
        std::string("c"),
        std::string("d")
    );
    PrivateCard PCard(
        std::string("b"),
        std::string("c"),
        std::string("d")
    );

    PCard.render();
    BCard.render();

    return 0;
}
