#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <mouse.h>

SCENARIO( "Test direction") {

  GIVEN( "direction is defined in the mesa namespace" ) {
    mesa::direction d;
    THEN( "the default value should be CENTER" ) {
      REQUIRE (d == mesa::direction::CENTER);
    }
  }

  WHEN( "direction is assigned a value" ) {

    THEN( "the value UP should exist" ) {
      mesa::direction d = mesa::direction::UP;
      CHECK (d == mesa::direction::UP);
    }

    AND_THEN( "the value DOWN should exist" ) {
      mesa::direction d = mesa::direction::DOWN;
      CHECK (d == mesa::direction::DOWN);
    }

    AND_THEN( "the value LEFT should exist" ) {
      mesa::direction d = mesa::direction::LEFT;
      CHECK (d == mesa::direction::LEFT);
    }

    AND_THEN( "the value RIGHT should exist" ) {
      mesa::direction d = mesa::direction::RIGHT;
      CHECK (d == mesa::direction::RIGHT);
    }

  }

}


