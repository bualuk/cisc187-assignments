#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <doctest.h>
#include "../src/Rational.h"

const Rational<int> zero = Rational<int>{0};
const Rational<int> one = Rational<int>{1};

SCENARIO( "Check addition") {
  GIVEN( "a single rational" ) {
    WHEN("added to itself") {
      THEN( "it should equal a+a" ) {
        REQUIRE (one+one == Rational<int>{2});
        REQUIRE (Rational<int>{13/3}+Rational<int>{13/3} == Rational<int>{26/3});
      }
    }
    WHEN("zero is added to anything") {
      THEN( "the identity value should be preserved" ) {
        REQUIRE (zero+zero == zero);
        REQUIRE (one+zero == one);
        REQUIRE (zero+one == one);
        REQUIRE (Rational<int>{2}+zero == Rational<int>{2});
        REQUIRE (zero+Rational<int>{-22,7} == Rational<int>{-22,7});
      }
    }
    WHEN("one is added to anything") {
      THEN( "the value should increase by 1" ) {
        REQUIRE (Rational<int>{2}+one == Rational<int>{3});
        REQUIRE (one+Rational<int>{-22,7} == Rational<int>{-15,7});
      }
    }
  }
  GIVEN( "two rationals" ) {
    REQUIRE (Rational<int>{2} + Rational<int>{3} == Rational<int>{5});
    REQUIRE (Rational<int>{2} + Rational<int>{-2} == zero);
    WHEN("using += ") {
      Rational<int> a {1,2};
      Rational<int> b {2};
      Rational<int> c {1,2};
      Rational<int> d {2};
      THEN( "a += b should change a in the same manner as a = a+b" ) {
        REQUIRE (a+b == c+d);
        a+=b;
        REQUIRE (a == c+d);
      }
    }
  }
}



