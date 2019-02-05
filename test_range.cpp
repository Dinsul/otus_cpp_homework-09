#define BOOST_TEST_MODULE test_range

#include "range.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_range)

BOOST_AUTO_TEST_CASE(test_split)
{
    auto runRes   = split("", '.');
    auto rightRes = std::vector<std::string>{};

    BOOST_CHECK(runRes == rightRes);

    runRes   = split("11.", '.');
    rightRes = std::vector<std::string>{"11"};

    BOOST_CHECK(runRes == rightRes);

    runRes   = split("11", '.');
    rightRes = std::vector<std::string>{"11"};

    BOOST_CHECK(runRes == rightRes);

    runRes   = split(".22", '.');
    rightRes = std::vector<std::string>{"", "22"};

    BOOST_CHECK(runRes == rightRes);

    runRes   = split("11.22", '.');
    rightRes = std::vector<std::string>{"11", "22"};

    BOOST_CHECK(runRes == rightRes);
}

BOOST_AUTO_TEST_SUITE_END()
