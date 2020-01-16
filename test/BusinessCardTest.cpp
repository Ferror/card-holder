#ifdef STAND_ALONE
    #define BOOST_TEST_MODULE MainTest
#endif

#include <boost/test/unit_test.hpp>

#include "../include/BusinessCard.h"

BOOST_AUTO_TEST_SUITE(BusinessCardTest)

    BOOST_AUTO_TEST_CASE(TestItContainsPhrase)
    {
        BusinessCard* businessCard = new BusinessCard(
            std::string("phone"),
            std::string("name"),
            std::string("email"),
            std::string("tax-number")
        );

        BOOST_CHECK(businessCard->containPhrase(std::string("phone")));
        BOOST_CHECK(businessCard->containPhrase(std::string("email")));
        BOOST_CHECK(businessCard->containPhrase(std::string("name")));
        BOOST_CHECK(businessCard->containPhrase(std::string("tax-number")));
        BOOST_CHECK(businessCard->containPhrase(std::string("tax")));
        BOOST_CHECK(businessCard->containPhrase(std::string("number")));

        delete businessCard;
    }

    BOOST_AUTO_TEST_CASE(TestItChangesName)
    {
        BusinessCard* businessCard = new BusinessCard(
                std::string("phone"),
                std::string("name"),
                std::string("email"),
                std::string("tax-number")
        );

        BOOST_CHECK(businessCard->containPhrase(std::string("name")));

        businessCard->changeName(std::string("super"));

        BOOST_CHECK(businessCard->containPhrase(std::string("name")) == false);
        BOOST_CHECK(businessCard->containPhrase(std::string("super")));

        delete businessCard;
    }

    BOOST_AUTO_TEST_CASE(TestItChangesEmail)
    {
        BusinessCard* businessCard = new BusinessCard(
            std::string("phone"),
            std::string("name"),
            std::string("email"),
            std::string("tax-number")
        );

        BOOST_CHECK(businessCard->containPhrase(std::string("email")));

        businessCard->changeEmail(std::string("gmail"));

        BOOST_CHECK(businessCard->containPhrase(std::string("email")) == false);
        BOOST_CHECK(businessCard->containPhrase(std::string("gmail")));

        delete businessCard;
    }

BOOST_AUTO_TEST_SUITE_END()
