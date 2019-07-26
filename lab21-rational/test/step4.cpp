#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <cstdint>
#include <doctest.h>
#include "../src/Rational.h"

SCENARIO( "Test Rational 2 argument  construction") {
  GIVEN( "a rational constructed with one argument" ) {
    WHEN("the numerator is 0") {
      Rational<int> r {0};
      THEN( "the value should be 0" ) {
        REQUIRE (r.numerator() == 0);
        REQUIRE (r.denominator() == 1);
      }
    }
    WHEN("the numerator is 1") {
      Rational<int> r {1};
      THEN( "the value should be 1" ) {
        REQUIRE (r.numerator() == 1);
        REQUIRE (r.denominator() == 1);
      }
    }
    WHEN("the numerator is -1") {
      Rational<std::int32_t> r {-1};
      THEN( "the value should be -1" ) {
        REQUIRE (r.numerator() == -1);
        REQUIRE (r.denominator() == 1);
      }
    }
    WHEN("the numerator is 13") {
      Rational<int> r {13};
      THEN( "the value should be 13" ) {
        REQUIRE (r.numerator() == 13);
        REQUIRE (r.denominator() == 1);
      }
    }
  }

  GIVEN( "a rational constructed with two parameters" ) {
    WHEN("the values are {0,1}") {
      Rational<std::uint32_t> r {0,1};
      THEN( "the value should be 0" ) {
        REQUIRE (r.numerator() == 0);
        REQUIRE (r.denominator() == 1);
      }
    }
    WHEN("the values are {-22,7}") {
      Rational<int32_t> r {-22,7};
      THEN( "the value should be -22/7" ) {
        REQUIRE (r.numerator() == -22);
        REQUIRE (r.denominator() == 7);
      }
    }
    WHEN("the values are {34,21}") {
      Rational<int> r {34,21};
      THEN( "the value should be 34/21" ) {
        REQUIRE (r.numerator() == 34);
        REQUIRE (r.denominator() == 21);
      }
    }
    WHEN("the values are {8,16}") {
      Rational<int> r {8,16};
      THEN( "gcd should reduce the value to 1/2" ) { 
        CHECK (r.numerator() == 1);
        CHECK (r.denominator() == 2);
      }
    }
    WHEN("the values are {90,30}") {
      Rational<int> r {90,30};
      THEN( "gcd should reduce the value to 3" ) { 
        CHECK (r.numerator() == 3);
        CHECK (r.denominator() == 1);
      }
    } WHEN("the values are {3,0}") {
      Rational<int> r {3,0};
      THEN( "the value should be 3/0" ) {
        CHECK (r.numerator() == 3);
        CHECK (r.denominator() == 0);
      }
    }
  }

}


SCENARIO ("test invariants of construction") {
  GIVEN ("a rational number with numerator and denominator 0") {
    WHEN("the numerator is 0, gcd(0,0) will segfault") {
      Rational<int> r {0,0};
      THEN( "just assign 0 to both and do not try to compute gcd(0,0)" ) {
        CHECK (r.numerator() == 0);
        CHECK (r.denominator() == 0);
      }
    }
  }
}



