#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <stack>
#include <stdexcept>
#include <doctest.h>
#include <Add.h>
#include <BigInt.h>

using mesa::Add;
using mesa::BigInt;
using std::stack;

//
// For these tests to compile implement:
//  - mesa::Add
//

SCENARIO ("test ability to skip non-add command input") {
  std::stack<BigInt> actual;
  Add handler;
  bool response = true;
  GIVEN ("an empty stack") {
    WHEN ("the token is '2'") {
      response = handler.execute(actual, "2");
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



SCENARIO ("test ability to process addition input") {
  std::stack<BigInt> actual;
  Add handler;
  bool response = false;
  GIVEN ("a stack with operands: 2, 2") {
    actual.push(BigInt{2});
    actual.push(BigInt{2});
    WHEN ("the token is '+'") {
      response = handler.execute(actual, "+");
      THEN ("the stack should add them and push the result onto the stack: BigInt{4}") {
        REQUIRE (!actual.empty());
        REQUIRE (operator==(actual.top(), BigInt{4}));
      }
      AND_THEN ("execute should return true") {
        REQUIRE (response);
      }
    }
  }

  GIVEN ("a stack with operands: 1, 2, 3, 4") {
    WHEN ("the add handler is invoked once") {
      actual.push(BigInt{1});
      actual.push(BigInt{2});
      actual.push(BigInt{3});
      actual.push(BigInt{4});
      response = handler.execute(actual, "+");
      THEN ("the handler should add the two top elements and push the result onto the stack") {
        REQUIRE (operator==(actual.top(), BigInt{7}));
      }
      AND_THEN ("the stack should contain 3 elements") {
        REQUIRE (actual.size() == 3);
      }
      AND_THEN ("execute should return true") {
        REQUIRE (response);
      }
    }
  }

  GIVEN ("a stack with one operand") {
    WHEN ("the add handler is invoked") {
      actual.push(BigInt{1});
      
      THEN ("the handler should throw an invalid_argument exception") {
        CHECK_THROWS_AS(handler.execute(actual, "+"), std::invalid_argument);
      }
    }
  }

  GIVEN ("an empty stack") {
    WHEN ("the add handler is invoked") {
      THEN ("the handler should throw an invalid_argument exception") {
        CHECK_THROWS_AS(handler.execute(actual, "+"), std::invalid_argument);
      }
    }
  }
}



