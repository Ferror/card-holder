#ifdef STAND_ALONE
    #define BOOST_TEST_MODULE MainTest
#endif

#include <boost/test/unit_test.hpp>

#include "../include/XMLCardHolder.h"
#include "../include/PrivateCard.h"

BOOST_AUTO_TEST_SUITE(XMLCardHolderTest)

    BOOST_AUTO_TEST_CASE(TestItReturnsNullPointerWhenCardListIsEmpty)
    {
        XMLCardHolder* holder = new XMLCardHolder;

        BOOST_CHECK(holder->get(0) == nullptr);
        BOOST_CHECK(holder->get(1) == nullptr);

        delete holder;
    }

    BOOST_AUTO_TEST_CASE(TestItAddsCardToList)
    {
        XMLCardHolder* holder = new XMLCardHolder;

        holder->add(new PrivateCard(std::string("phone"), std::string("name"), std::string("email")));

        BOOST_CHECK(holder->get(0) != nullptr);
        BOOST_CHECK(holder->get(0)->containPhrase(std::string("phone")));

        delete holder;
    }

    BOOST_AUTO_TEST_CASE(TestItRemovesCardFromList)
    {
        XMLCardHolder* holder = new XMLCardHolder;

        holder->add(new PrivateCard(std::string("phone"), std::string("name"), std::string("email")));

        BOOST_CHECK(holder->get(0) != nullptr);
        holder->remove(0);
        BOOST_CHECK(holder->get(0) == nullptr);

        delete holder;
    }

BOOST_AUTO_TEST_SUITE_END()
