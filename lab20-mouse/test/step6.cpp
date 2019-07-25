#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <point.h>

SCENARIO( "Test point == and !=") {

  GIVEN( "a point" ) {
    mesa::point a {3,5};
    THEN( "that point should always equal itself" ) {
      CAPTURE (a.x);
      CAPTURE (a.y);
      CHECK ((a == a));
    }

    WHEN ("the point 'p' is the same as point 'a'") {
      mesa::point p = a;
      CAPTURE (a.x);
      CAPTURE (a.y);
      CAPTURE (p.x);
      CAPTURE (p.y);
      THEN( "the points should have the same values" ) {
        CHECK ((p == a));
        CHECK ((p != a) == false);
      }
    }

    WHEN ("the  p.x is the differnt from a.x") {
      mesa::point p = a;
      p.x = 17;
      CAPTURE (a.x);
      CAPTURE (a.y);
      CAPTURE (p.x);
      CAPTURE (p.y);
      THEN( "the != operator should return true" ) {
        CHECK ((p != a));
        CHECK ((p == a) == false);
      }
    }

    WHEN ("the  p.y is the differnt from a.y") {
      mesa::point p = a;
      p.y = 15;
      CAPTURE (a.x);
      CAPTURE (a.y);
      CAPTURE (p.x);
      CAPTURE (p.y);
      THEN( "the != operator should return true" ) {
        CHECK ((p != a));
        CHECK ((p == a) == false);
      }
    }

  }

}








