#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <stack>
#include <doctest.h>
#include <BigInt.h>
#include <OperandPusher.h>

using mesa::BigInt;
using mesa::OperandPusher;
using std::stack;

//
// For these tests to compile implement:
//  - mesa::OperandPusher
//

SCENARIO ("test ability to skip non-numeric input") {
  std::stack<BigInt> actual;
  OperandPusher handler;
  bool response = true;
  GIVEN ("an empty stack") {
    WHEN ("the token is '+'") {
      response = handler.execute(actual, "+");
      THEN ("the stack should remain empty") {
        REQUIRE (actual.empty());
      }
      AND_THEN ("execute should return false") {
        REQUIRE (response == false);
      }
    }

    WHEN ("the token is '*'") {
      response = handler.execute(actual, "*");
      THEN ("the stack should remain empty") {
        REQUIRE (actual.empty());
      }
      AND_THEN ("execute should return false") {
        REQUIRE (response == false);
      }
    }

    WHEN ("the token is '^'") {
      response = handler.execute(actual, "^");
      THEN ("the stack should remain empty") {
        REQUIRE (actual.empty());
      }
      AND_THEN ("execute should return false") {
        REQUIRE (response == false);
      }
    }

    WHEN ("the token is '!'") {
      response = handler.execute(actual, "!");
      THEN ("the stack should remain empty") {
        REQUIRE (actual.empty());
      }
      AND_THEN ("execute should return false") {
        REQUIRE (response == false);
      }
    }
  }
}



SCENARIO ("test ability to process numeric input") {
  std::stack<BigInt> actual;
  OperandPusher handler;
  bool response = false;
  GIVEN ("an empty stack") {
    WHEN ("the token is '2'") {
      response = handler.execute(actual, "2");
      THEN ("the stack should contain BigInt{2}") {
        REQUIRE (!actual.empty());
        REQUIRE (operator==(actual.top(), BigInt{2}));
      }
      AND_THEN ("execute should return true") {
        REQUIRE (response);
      }
    }

    WHEN ("the token is '0'") {
      response = handler.execute(actual, "0");
      THEN ("the handler should push the token onto the stack") {
        REQUIRE (operator==(actual.top(), BigInt{0}));
      }
      AND_THEN ("execute should return true") {
        REQUIRE (response);
      }
    }

    WHEN ("the token is '123456789012345678901234567890'") {
      response = handler.execute(actual, "123456789012345678901234567890");
      THEN ("the handler should push the token onto the stack") {
        REQUIRE (operator==(actual.top(), BigInt{"123456789012345678901234567890"}));
      }
      AND_THEN ("execute should return true") {
        REQUIRE (response);
      }
    }
    WHEN ("two numeric tokens are processed") {
      response = handler.execute(actual, "123456789012345678901234567890");
      response = handler.execute(actual, "5");
      THEN ("the handler size should be 2") {
        REQUIRE (actual.size() == 2);
      }
      AND_THEN ("the last token added should be on the top of the stack") {
        REQUIRE (operator==(actual.top(), BigInt{"5"}));
      }
      AND_THEN ("execute should return true") {
        REQUIRE (response);
      }
    }
  }
}



