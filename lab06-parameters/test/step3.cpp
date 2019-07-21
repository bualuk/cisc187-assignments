#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#include <doctest.h>

#include <lab6.h>
#include "util.h"

SCENARIO( "scale a triangle") {

  GIVEN( "a valid {3,4,5} trigon" ) {
    auto triangle = mesa::make_triple(2,1);
    WHEN( "the scale factor == 2" ) {
      mesa::scale(triangle,2.f);
      THEN( "a {6,8,10} triangle should be returned" ) {
        CHECK( triangle.a  == doctest::Approx(6));
        CHECK( triangle.b  == doctest::Approx(8));
        REQUIRE( triangle.c  == doctest::Approx(10));
      }
    }
    WHEN( "the scale factor == 0.5" ) {
      mesa::scale(triangle,0.5f);
      THEN( "a {1.5,2,2.5} triangle should be returned" ) {
        CHECK( triangle.a  == doctest::Approx(1.5));
        CHECK( triangle.b  == doctest::Approx(2));
        REQUIRE( triangle.c  == doctest::Approx(2.5));
      }
    }
  }
}



SCENARIO( "validate invariants of scale") {

  GIVEN( "a invalid input parameters" ) {
    auto triangle = mesa::make_triple(4,3);
    WHEN( "factor is <= 0.01" ) {
      mesa::scale(triangle,0.009f);
      THEN( "the trigon should not be modified" ) {
        CHECK( triangle.a  == doctest::Approx(7));
        CHECK( triangle.b  == doctest::Approx(24));
        REQUIRE( triangle.c  == doctest::Approx(25));
      }
    }
    WHEN( "factor is zero" ) {
      mesa::scale(triangle,0.f);
      THEN( "the trigon should not be modified" ) {
        CHECK( triangle.a  == doctest::Approx(7));
        CHECK( triangle.b  == doctest::Approx(24));
        REQUIRE( triangle.c  == doctest::Approx(25));
      }
    }
    WHEN( "factor is negative" ) {
      mesa::scale(triangle,-9.99f);
      THEN( "the trigon should not be modified" ) {
        CHECK( triangle.a  == doctest::Approx(7));
        CHECK( triangle.b  == doctest::Approx(24));
        REQUIRE( triangle.c  == doctest::Approx(25));
      }
    }
  }
}



