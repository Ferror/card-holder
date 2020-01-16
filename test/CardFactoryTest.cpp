#ifdef STAND_ALONE
    #define BOOST_TEST_MODULE MainTest
#endif

#include <boost/test/unit_test.hpp>

#include "../include/BusinessCard.h"
#include "../include/CardFactory.h"

BOOST_AUTO_TEST_SUITE(CardFactoryTest)

    BOOST_AUTO_TEST_CASE(TestItCreatesCardFromUserInput)
    {
        Card* card = CardFactory::createFromUserInput(std::string("phone"), std::string("name"), std::string("email"), std::string(""));

        BOOST_CHECK(card != nullptr);
        BOOST_CHECK(card->containPhrase("phone"));

        delete card;
    }

BOOST_AUTO_TEST_SUITE_END()
