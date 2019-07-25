#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <mouse.h>
#include <doctest.h>

SCENARIO( "Test mouse default construction") {
  GIVEN( "a default mouse" ) {
    mesa::mouse m;
    THEN( "the default name should be Alice" ) {
      CHECK (m.name() == "Alice");
    }
    AND_THEN( "the default location should be 0,0" ) {
      mesa::point expected {0,0};
      CAPTURE(expected.x);
      CAPTURE(expected.y);
      CHECK ((m.location() == expected));
    }
  }

}


