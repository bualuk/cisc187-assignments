#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <doctest.h>
#include "../src/Rational.h"

const Rational<int> zero = Rational<int>{0};
const Rational<int> one = Rational<int>{1};

SCENARIO( "Check subtraction") {
  GIVEN( "a single rational" ) {
    WHEN("subtracted from itself") {
      THEN( "result should equal 0" ) {
        REQUIRE (one-one == zero);
        REQUIRE (Rational<int>{13/3}-Rational<int>{13/3} == zero);
      }
    }
    WHEN("zero is subtracted from anything") {
      THEN( "the identity value should be preserved" ) {
        REQUIRE (zero-zero == zero);
        REQUIRE (one-zero == one);
        REQUIRE (Rational<int>{2}-zero == Rational<int>{2});
        REQUIRE (Rational<int>{-22,7}-zero == Rational<int>{-22,7});
      }
    }
    WHEN("one is subtracted from anything") {
      THEN( "the value should decrease by 1" ) {
        REQUIRE (Rational<int>{2}-one == one);
        REQUIRE (Rational<int>{-22,7}-one == Rational<int>{-29,7});
        REQUIRE (Rational<int>{1,2}-one == Rational<int>{-1,2});
      }
    }
  }
  GIVEN( "two rationals" ) {
    REQUIRE (Rational<int>{2} - Rational<int>{3} == Rational<int>{-1});
    REQUIRE (Rational<int>{2} - Rational<int>{-2} == Rational<int>{4});
    REQUIRE (Rational<int>{22,7} - Rational<int>{-22,7} == Rational<int>{44,7});
    WHEN("using += ") {
      Rational<int> a {1,2};
      Rational<int> b {2};
      Rational<int> c {1,2};
      Rational<int> d {2};
      THEN( "a -= b should change a in the same manner as a = a-b" ) {
        REQUIRE (a-b == c-d);
        a-=b;
        REQUIRE (a == c-d);
      }
    }
  }
}



