#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <doctest.h>
#include "../src/lab8.h"

SCENARIO( "Compute the area of a circle") {

  GIVEN( "a circle of radius > 0" ) {
    WHEN( "1 is provided" ) {
      THEN( "PI should be returned" ) {
        REQUIRE( mesa::area(1) == doctest::Approx(M_PI));
      }
    }
    WHEN( "2 is provided" ) {
      THEN( "4*PI should be returned" ) {
        CHECK( mesa::area(2) == doctest::Approx(4.*M_PI));
      }
    }
    WHEN( "8.5 is provided" ) {
      THEN( "226.98 should be returned" ) {
        CHECK( mesa::area(8.5) == doctest::Approx(226.98));
      }
    }
    WHEN( "13.21 is provided" ) {
      THEN( "548.221 should be returned" ) {
        CHECK( mesa::area(13.21) == doctest::Approx(548.221));
      }
    }
  }
}

SCENARIO( "Compute the invariants of circle area") {

  GIVEN( "a circle of radius <= 0" ) {
    WHEN( "0 is provided" ) {
      THEN( "0 should be returned" ) {
        REQUIRE( mesa::area(0) == 0);
      }
    }
    WHEN( "-2 is provided" ) {
      THEN( "0 should be returned" ) {
        CHECK( mesa::area(-2) == 0);
      }
    }
    WHEN( "-8.5 is provided" ) {
      THEN( "0 should be returned" ) {
        CHECK( mesa::area(-8.5) == 0);
      }
    }

  }
}




