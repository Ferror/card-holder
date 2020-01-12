#ifdef STAND_ALONE
    #define BOOST_TEST_MODULE MainTest
#endif

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(MenuOptionTest)

    BOOST_AUTO_TEST_CASE(PassTest)
    {
        BOOST_CHECK_EQUAL(std::string("Myszka"), "Myszka");
    }

BOOST_AUTO_TEST_SUITE_END()
