#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <doctest.h>
#include "../src/Rational.h"

static const Rational<int> zero = Rational<int>{0};
static const Rational<int> one = Rational<int>{1};
static const auto inf = Rational<int>{0,0};

SCENARIO( "Check division") {
  GIVEN( "a single rational" ) {
    WHEN("divided into itself") {
      THEN( "result should equal 1" ) {
        REQUIRE (one/one == one);
        REQUIRE (Rational<int>{3}/Rational<int>{3} == one);
        REQUIRE (Rational<int>{13/3}/Rational<int>{13/3} == one);
      }
    }
    WHEN("one is divided into anything") {
      THEN( "the value should remain unchanged" ) {
        REQUIRE (Rational<int>{2}/one == Rational<int>{2});
        REQUIRE (Rational<int>{-22,7}/one == Rational<int>{-22,7});
        REQUIRE (Rational<int>{1,2}/one == Rational<int>{1,2});
      }
    }
    WHEN("zero is divided into anything") {
      THEN( "the result should be infinity" ) {
        REQUIRE (zero/zero == inf);
        REQUIRE (one/zero == inf);
        REQUIRE (Rational<int>{2}/zero == inf);
        REQUIRE (Rational<int>{-22,7}/zero == inf);
      }
    }
  }
  GIVEN( "two rationals" ) {
    REQUIRE (Rational<int>{2} / Rational<int>{3} == Rational<int>{2,3});
    REQUIRE (Rational<int>{2} / Rational<int>{-2} == Rational<int>{-1});
    REQUIRE (Rational<int>{22,7} / Rational<int>{-22,7} == Rational<int>{-1});
    WHEN("using /= ") {
      Rational<int> a {1,2};
      Rational<int> b {2};
      Rational<int> c {1,2};
      Rational<int> d {2};
      THEN( "a /= b should change a in the same manner as a = a/b" ) {
        REQUIRE (a/b == c/d);
        a/=b;
        REQUIRE (a == c/d);
      }
    }
  }
}



