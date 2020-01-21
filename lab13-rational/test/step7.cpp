#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <sstream>
#include <string>
#include <doctest.h>
#include "../src/Rational.h"

SCENARIO( "Stream one Rational") {
  GIVEN( "a rational number" ) {
    WHEN("the Rational is 0") {
      Rational<int> r;
      THEN( "the value should output '0'" ) {
        std::ostringstream os;
        os << r;
        auto actual = os.str();
        std::string expected = "0";
        REQUIRE(actual == expected);
      }
    }
    WHEN("the Rational is 0, 5") {
      Rational<int> r {0,5};
      THEN( "the value should output '0'" ) {
        std::ostringstream os;
        os << r;
        auto actual = os.str();
        std::string expected = "0";
        REQUIRE(actual == expected);
      }
    }
    WHEN("the rational is 1/2") {
      Rational<int> r {1,2};
      THEN( "the value should output '1/2'" ) {
        std::ostringstream os;
        os << r;
        auto actual = os.str();
        std::string expected = "1/2";
        REQUIRE(actual == expected);
      }
    }
    WHEN("the rational is {-22,7}") {
      Rational<int> r {-22,7};
      THEN( "the value should output '-22/7'" ) {
        std::ostringstream os;
        os << r;
        auto actual = os.str();
        std::string expected = "-22/7";
        REQUIRE(actual == expected);
      }
    }
    WHEN("the denominator is 0 and the numerator is not") {
      Rational<int> r {5,0};
      THEN( "the value should output 'inf'" ) {
        std::ostringstream os;
        os << r;
        auto actual = os.str();
        std::string expected = "inf";
        REQUIRE(actual == expected);
      }
    }
    WHEN("the numerator and denominator are equal") {
      Rational<int> r {3,3};
      THEN( "the value should output '1'" ) {
        std::ostringstream os;
        os << r;
        auto actual = os.str();
        std::string expected = "1";
        REQUIRE(actual == expected);
      }
    }
  }
}

