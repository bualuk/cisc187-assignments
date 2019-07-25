#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <point.h>

SCENARIO( "Test point 2 arg constructor") {

  GIVEN( "a point constructed from 2 values" ) {
    mesa::point p {3,5};

    THEN( "the values should be 3,5" ) {
      CHECK (p.x == 3);
      CHECK (p.y == 5);
    }

    WHEN ("the values are 21,34") {
      mesa::point p {21,34};
      THEN( "the values should be 21,34" ) {
        CHECK (p.x == 21);
        CHECK (p.y == 34);
      }
    }

    WHEN ("the values are -8,-5") {
      mesa::point p {-8,-5};
      THEN( "the values should be -8,-5" ) {
        CHECK (p.x == -8);
        CHECK (p.y == -5);
      }
    }

  }

}








