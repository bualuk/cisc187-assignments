#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <doctest.h>
#include "../src/Rational.h"

SCENARIO( "test gcd") {
  GIVEN( "a denominator = 1" ) {
    WHEN( "the numerator is positive" ) {
      THEN( "the GCD equals the numerator" ) {
        REQUIRE(gcd(13,1) == 1);
      }
    }
    WHEN( "the numerator is negative" ) {
      THEN( "the GCD equals the absolute value of the numerator" ) {
        REQUIRE(gcd(-13,1) == 1);
      }
    }
  }
  WHEN( "the values passed to gcd are 54,24" ) {
    THEN( "the GCD 6" ) {
      REQUIRE(gcd(54,24) == 6);
    }
  }
  WHEN( "the values passed to gcd are 62,36" ) {
    THEN( "the GCD 2" ) {
      REQUIRE(gcd(62,36) == 2);
    }
  }
  WHEN( "the values passed to gcd are -62,36" ) {
    THEN( "the GCD 2" ) {
      REQUIRE(gcd(-62,36) == 2);
    }
  }
  WHEN( "the values passed to gcd are -62,-36" ) {
    THEN( "the GCD 2" ) {
      REQUIRE(gcd(-62,-36) == 2);
    }
  }

}

SCENARIO( "test invariants of gcd") {
  WHEN( "the numerator and denominator are both zero" ) {
    THEN("the GCD is 0") {
      REQUIRE(gcd(0,0) == 0);
    }
  }
  WHEN( "the numerator is zero" ) {
    THEN("the GCD is the denominator") {
      REQUIRE(gcd(0,8) == 8);
    }
  }
  WHEN( "the denominator is zero" ) {
    THEN("the GCD is the numerator") {
      REQUIRE(gcd(13,0) == 13);
    }
  }
  
}

