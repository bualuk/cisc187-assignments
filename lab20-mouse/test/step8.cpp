#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <mouse.h>
#include <doctest.h>

SCENARIO( "Test mouse 1 arg construction") {

  GIVEN( "a mouse that is not 'Alice'" ) {
    mesa::mouse m{"Buddy"};
    THEN( "the name should be 'Buddy'" ) {
      CHECK (m.name() == "Buddy");
    }
    AND_THEN( "the default location still should be 0,0" ) {
      mesa::point expected {0,0};
      CAPTURE(expected.x);
      CAPTURE(expected.y);
      CHECK ((m.location() == expected));
    }
  }

  GIVEN( "another mouse that is not 'Alice'" ) {
    mesa::mouse m{"clara"};
    THEN( "the name should be 'clara'" ) {
      CHECK (m.name() == "clara");
    }
    AND_THEN( "the default location still should be 0,0" ) {
      mesa::point expected {0,0};
      CAPTURE(expected.x);
      CAPTURE(expected.y);
      CHECK ((m.location() == expected));
    }
  }

}


