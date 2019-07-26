#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <doctest.h>
#include "../src/Rational.h"

const Rational<int> zero = Rational<int>{0};
const Rational<int> one = Rational<int>{1};

SCENARIO( "Check multiplication") {
  GIVEN( "a single rational" ) {
    WHEN("multiplied to itself") {
      THEN( "it should equal a*a" ) {
        REQUIRE (one*one == one);
        REQUIRE (Rational<int>{13/3}+Rational<int>{13/3} == Rational<int>{26/3});
      }
    }
    WHEN("zero is multiplied by anything") {
      THEN( "the result is zero" ) {
        REQUIRE (zero*zero == zero);
        REQUIRE (one*zero == zero);
        REQUIRE (zero*one == zero);
        REQUIRE (Rational<int>{2}*zero == zero);
        REQUIRE (zero*Rational<int>{-22,7} == zero);
      }
    }
    WHEN("one is multiplied by anything") {
      THEN( "the value is unchanged" ) {
        REQUIRE (zero*one == zero);
        REQUIRE (Rational<int>{13}*one == Rational<int>{13});
        REQUIRE (Rational<int>{-34}*one == Rational<int>{-34});
        REQUIRE (Rational<int>{1,9}*one == Rational<int>{1,9});
        REQUIRE (one*Rational<int>{-22,7} == Rational<int>{-22,7});
      }
    }
  }
  GIVEN( "two rationals" ) {
    REQUIRE (Rational<int>{2} * Rational<int>{3} == Rational<int>{6});
    REQUIRE (Rational<int>{5} * Rational<int>{-4} == Rational<int>{-20});
    WHEN("using *= ") {
      Rational<int> a {1,2};
      Rational<int> b {2};
      Rational<int> c {1,2};
      Rational<int> d {2};
      THEN( "a *= b should change a in the same manner as a = a*b" ) {
        REQUIRE (a*b == c*d);
        a*=b;
        REQUIRE (a == c*d);
      }
    }
  }
}



