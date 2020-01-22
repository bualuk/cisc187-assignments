#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <cstdint>
#include <doctest.h>
#include "../src/rational.h"

SCENARIO( "Test rational 1 argument  construction") {
  GIVEN( "a rational constructed with one argument" ) {
    WHEN("the numerator is 0") {
      rational<int> r {0};
      THEN( "the value should be 0" ) {
        REQUIRE (r.numerator() == 0);
        REQUIRE (r.denominator() == 1);
      }
    }
    WHEN("the numerator is 1") {
      rational<int> r {1};
      THEN( "the value should be 1" ) {
        REQUIRE (r.numerator() == 1);
        REQUIRE (r.denominator() == 1);
      }
    }
    WHEN("the numerator is -1") {
      rational<std::int32_t> r {-1};
      THEN( "the value should be -1" ) {
        REQUIRE (r.numerator() == -1);
        REQUIRE (r.denominator() == 1);
      }
    }
    WHEN("the numerator is 13") {
      rational<int> r {13};
      THEN( "the value should be 13" ) {
        REQUIRE (r.numerator() == 13);
        REQUIRE (r.denominator() == 1);
      }
    }
  }
}

SCENARIO( "Test rational 2 argument construction") {
  GIVEN( "a rational constructed with two parameters" ) {
    WHEN("the values are {0,1}") {
      rational<std::uint32_t> r {0,1};
      THEN( "the value should be 0" ) {
        REQUIRE (r.numerator() == 0);
        REQUIRE (r.denominator() == 1);
      }
    }
    WHEN("the values are {-22,7}") {
      rational<int32_t> r {-22,7};
      THEN( "the value should be -22/7" ) {
        REQUIRE (r.numerator() == -22);
        REQUIRE (r.denominator() == 7);
      }
    }
    WHEN("the values are {34,21}") {
      rational<int> r {34,21};
      THEN( "the value should be 34/21" ) {
        REQUIRE (r.numerator() == 34);
        REQUIRE (r.denominator() == 21);
      }
    }
    WHEN("the values are {3,0}") {
      rational<int> r {3,0};
      THEN( "the value should be 3/0" ) {
        CHECK (r.numerator() == 3);
        CHECK (r.denominator() == 0);
      }
    }
  }

}


