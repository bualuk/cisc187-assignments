#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <cstdint>
#include <limits>
#include <doctest.h>
#include "../src/Rational.h"


SCENARIO( "convert a rational to a double") {
  //      CHECK (275 == doctest::Approx(actual));
  GIVEN ("a valid rational number") {
    WHEN("the Rational is 0") {
      Rational<int> r {0};
      THEN( "the value should convert to 0" ) {
        REQUIRE (r.to_double() == 0);
        //REQUIRE (double(r) == 0);
      }
    }
    WHEN("the rational is 1/2") {
      Rational<int> r {1,2};
      THEN( "the value should convert to 0.5" ) {
        REQUIRE (r.to_double() == doctest::Approx(0.5));
        //REQUIRE (double(r) == doctest::Approx(0.5));
      }
    }
    WHEN("the rational is {-22,7}") {
      Rational<int> r {-22,7};
      THEN( "the value should convert to -pi" ) {
        REQUIRE (r.to_double() == doctest::Approx(-3.14).epsilon(0.01));
        //REQUIRE (double(r) == doctest::Approx(-3.14).epsilon(0.01));
      }
    }
  }
}

SCENARIO ("test invariants of to_double") {
  GIVEN ("a rational number with denominator 0") {
    WHEN("the numerator is 1") {
      Rational<int> r {1,0};
      THEN( "the value should convert +inf" ) {
        REQUIRE (r.to_double() == std::numeric_limits<double>::infinity());
      }
    }
    WHEN("the numerator is 0") {
      Rational<int> r {0,0};
      THEN( "the value should convert +inf" ) {
        REQUIRE (r.to_double() == std::numeric_limits<double>::infinity());
      }
    }
  }
}

