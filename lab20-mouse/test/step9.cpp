#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <mouse.h>
#include <doctest.h>

using mesa::direction;
using mesa::point;

SCENARIO( "Move a mouse") {
  GIVEN( "a default mouse" ) {
    mesa::mouse m{"nibbles"};
    THEN( "the default position should be 0,0" ) {
      CHECK ((m.location() == point{0,0}));
    }

    AND_WHEN( "move(direction::RIGHT,1) is called" ) {
      auto actual = m.move(direction::RIGHT,1);
      THEN( "the new position should be returned" ) {
        CHECK ((actual == point{1,0}));
      }
      
      AND_THEN( "the new position should be 1,0" ) {
        CHECK ((m.location() == point{1,0}));
      }
    }

    AND_WHEN( "move(direction::UP,1) is called" ) {
      auto actual = m.move(direction::UP,1);
      THEN( "the new position should be 0,1" ) {
        CHECK ((actual == point{0,1}));
      }
    }

    AND_WHEN( "move(direction::LEFT,1) is called" ) {
      auto actual = m.move(direction::LEFT,1);
      THEN( "the new position should be -1,0" ) {
        CHECK ((actual == point{-1,0}));
      }
    }
  }
}

SCENARIO( "Move a mouse backwards") {
  GIVEN( "a default mouse" ) {
    mesa::mouse m{"chaddar"};
    THEN( "the default position should be 0,0" ) {
      CHECK ((m.location() == point{0,0}));
    }

    AND_WHEN( "move(direction::RIGHT,-1) is called" ) {
      auto actual = m.move(direction::RIGHT,-1);
      THEN( "the new position should be returned" ) {
        CHECK ((actual == point{-1,0}));
      }
      
      AND_THEN( "the new position should be -1,0" ) {
        CHECK ((m.location() == point{-1,0}));
      }
    }

    AND_WHEN( "move(direction::UP,-1) is called" ) {
      auto actual = m.move(direction::UP,-1);
      THEN( "the new position should be 0,-1" ) {
        CHECK ((actual == point{0,-1}));
      }
    }

    AND_WHEN( "move(direction::LEFT,-1) is called" ) {
      auto actual = m.move(direction::LEFT,-1);
      THEN( "the new position should be 1,0" ) {
        CHECK ((actual == point{1,0}));
      }
    }

    AND_WHEN( "move(direction::DOWN,1) is called" ) {
      auto actual = m.move(direction::DOWN,-1);
      THEN( "the new position should be 0,1" ) {
        CHECK ((actual == point{0,1}));
      }
    }
  }
}


SCENARIO( "Move a mouse around") {
  GIVEN( "a mouse" ) {
    mesa::mouse m{"squeakers"};
    THEN( "the default position should be 0,0" ) {
      CHECK ((m.location() == point{0,0}));
    }

    AND_WHEN( "move(RIGHT,7) is called" ) {
      auto actual = m.move(direction::RIGHT,7);
      THEN( "the new position should be returned" ) {
        CHECK ((actual == point{7,0}));
      }
    }

    WHEN( "UP,5, then LEFT,3 is called" ) {
      auto actual = m.move(direction::UP,5);
      actual = m.move(direction::LEFT,3);
      THEN( "the new position should be -3,5" ) {
        CHECK ((actual == point{-3,5}));
      }
    }

    WHEN( "moving RIGHT,3 UP,5 DOWN,8, and LEFT 13 is called" ) {
      auto actual = m.move(direction::RIGHT,3);
      actual = m.move(direction::UP,5);
      actual = m.move(direction::DOWN,8);
      actual = m.move(direction::LEFT,13);
      THEN( "the new position should be -10,-3" ) {
        CHECK ((actual == point{-10,-3}));
      }
    }

  }
}


