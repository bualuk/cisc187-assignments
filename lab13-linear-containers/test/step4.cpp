#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <algorithm>
#include <deque>
#include <stack>
#include <string>
#include <vector>

#include <doctest.h>
#include "../src/lab13.h"

SCENARIO( "Compare two stacks for equality" * doctest::timeout(0.5)) {

  GIVEN( "two stack of 10 ints, 0 through 9" ) {
    std::deque<int> v = {0,1,2,3,4,5,6,7,8,9};
    std::stack<int> x(v);
    std::stack<int> y(v);

    WHEN( "the values are equal" ) {
      THEN("equal_to should return true") {
        while (!x.empty()) {
          REQUIRE (mesa::equal_to(x,y) == true);
          x.pop();
          y.pop();
        }
      }
    }
  }

  GIVEN( "a stack of 7 names, Alice through Greg" ) {
    std::stack<std::string> x;
    std::stack<std::string> y;
    x.push("Alice");
    x.push("Bob");
    x.push("Clarice");
    x.push("Darla");
    x.push("Earl");
    x.push("Fran");
    x.push("Greg");
    y = x;

    WHEN( "the values are equal" ) {
      THEN("equal_to should return true") {
        while (!x.empty()) {
          REQUIRE (mesa::equal_to(x,y) == true);
          x.pop();
          y.pop();
        }
      }
    }
  }
}

SCENARIO( "Compute the invariants of equal_to" * doctest::timeout(0.5) ) {

  GIVEN( "one or more empty stacks" ) {
    std::stack<int> a;
    std::stack<int> b;
    b.push(1);
    WHEN( "the first stack is empty and the second is not" ) {
      THEN( "equal_to should return false" ) {
        REQUIRE(mesa::equal_to(a,b) == false);
      }
    }
    a.push(1);
    b.pop();
    WHEN( "the second stack is empty and the first is not" ) {
      THEN( "equal_to should return false" ) {
        REQUIRE(mesa::equal_to(a,b) == false);
      }
    }
    a.pop();
    WHEN( "the both stacks are empty" ) {
      THEN( "equal_to should return true" ) {
        REQUIRE(mesa::equal_to(a,b) == true);
      }
    }
  }
}


