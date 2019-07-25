#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>
#include <doctest.h>
#include <point.h>

SCENARIO( "Test point copy constructor") {

  GIVEN( "a point" ) {
    mesa::point a {3,5};

    WHEN ("the point is constructed from another point") {
      std::vector<mesa::point> v;
      v.push_back(a);
      THEN( "the points should have the same values" ) {
        CHECK (v[0].x == a.x);
        CHECK (v[0].y == a.y);
      }
    }

    WHEN ("the point is copied to another point") {
      mesa::point p = a;
      THEN( "the values should match in both points" ) {
        CHECK (p.x == a.x);
        CHECK (p.y == a.y);
      }
    }

  }

}








