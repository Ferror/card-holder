#ifdef STAND_ALONE
    #define BOOST_TEST_MODULE MainTest
#endif

#include <boost/test/unit_test.hpp>

#include "../include/PrivateCard.h"

BOOST_AUTO_TEST_SUITE(PrivateCardTest)

    BOOST_AUTO_TEST_CASE(TestItContainsPhrase)
    {
        PrivateCard* privateCard = new PrivateCard(
            std::string("phone"),
            std::string("name"),
            std::string("email")
        );

        BOOST_CHECK(privateCard->containPhrase(std::string("phone")));
        BOOST_CHECK(privateCard->containPhrase(std::string("email")));
        BOOST_CHECK(privateCard->containPhrase(std::string("name")));

        delete privateCard;
    }

    BOOST_AUTO_TEST_CASE(TestItChangesName)
    {
        PrivateCard* privateCard = new PrivateCard(
            std::string("phone"),
            std::string("name"),
            std::string("email")
        );

        BOOST_CHECK(privateCard->containPhrase(std::string("name")));

        privateCard->changeName(std::string("super"));

        BOOST_CHECK(privateCard->containPhrase(std::string("name")) == false);
        BOOST_CHECK(privateCard->containPhrase(std::string("super")));

        delete privateCard;
    }

    BOOST_AUTO_TEST_CASE(TestItChangesEmail)
    {
        PrivateCard* privateCard = new PrivateCard(
            std::string("phone"),
            std::string("name"),
            std::string("email")
        );

        BOOST_CHECK(privateCard->containPhrase(std::string("email")));

        privateCard->changeEmail(std::string("gmail"));

        BOOST_CHECK(privateCard->containPhrase(std::string("email")) == false);
        BOOST_CHECK(privateCard->containPhrase(std::string("gmail")));

        delete privateCard;
    }

BOOST_AUTO_TEST_SUITE_END()
