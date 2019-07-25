#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <point.h>

SCENARIO( "Test point struct default construction") {

  GIVEN( "a default point" ) {
    mesa::point p;

    THEN( "the default values should be 0,0" ) {
      CHECK (p.x == 0);
      CHECK (p.y == 0);
    }

    WHEN( "the values are set to -3,2" ) {
      p.x = -3;
      p.y = 2;
      THEN( "the values should be update" ) {
        CHECK (p.x == -3);
        CHECK (p.y == 2);
      }
    }

    WHEN( "the values are set to 13,21" ) {
      p.x = 13;
      p.y = 21;
      THEN( "the values should be update" ) {
        CHECK (p.x == 13);
        CHECK (p.y == 21);
      }
    }

  }

}


