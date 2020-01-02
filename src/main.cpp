#include "../include/BusinessCard.h"
#include "../include/PrivateCard.h"
#include "../include/XMLDocument.h"
#include "../include/XMLCardHolder.h"

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

    XMLDocument document("../data/xml/cards.xml", CardFactory());
    XMLCardHolder holder(document);
    holder.print();

    return 0;
}
