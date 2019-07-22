#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <numeric>
#include <stack>
#include <string>
#include <vector>

#include <doctest.h>
#include "../src/lab13.h"

SCENARIO( "Determine whether a stack contains a value" * doctest::timeout(0.5)) {

  GIVEN( "a stack of 10 ints, 0 through 9" ) {
    std::stack<int> x;
    WHEN( "the value is 0 through 9" ) {
      std::vector<int> v(10);
      std::iota(v.begin(), v.end(), 0);
      for (const auto& i: v) x.push(i);
      THEN( "contains should return true" ) {
        for (int i = 0; i < 9; ++i) {
          CAPTURE(i);
          REQUIRE(mesa::contains(i, x) == true);
        } 
      }
    }
    WHEN( "the value is -1" ) {
      THEN( "contains should return false" ) {
        REQUIRE(mesa::contains(-1, x) == false);
      }
    }
    WHEN( "the value is 10" ) {
      THEN( "contains should return false" ) {
        REQUIRE(mesa::contains(10, x) == false);
      }
    }
  }
  GIVEN( "a stack of 7 names, Alice through Greg" ) {
    std::stack<std::string> names;
    names.push("Alice");
    names.push("Bob");
    names.push("Clarice");
    names.push("Darla");
    names.push("Earl");
    names.push("Fran");
    names.push("Greg");

    WHEN( "the value is Alice" ) {
      THEN("contains should return true") {
        REQUIRE(mesa::contains(std::string("Alice"), names) == true);
      }
    }
    WHEN( "the value is Clarice" ) {
      THEN("contains should return true") {
        REQUIRE(mesa::contains(std::string("Clarice"), names) == true);
      }
    }
    WHEN( "the value is Greg" ) {
      THEN("contains should return true") {
        REQUIRE(mesa::contains(std::string("Greg"), names) == true);
      }
    }
    WHEN( "the value is fluffy" ) {
      THEN("contains should return false") {
        REQUIRE(mesa::contains(std::string("fluffy"), names) == false);
      }
    }
    WHEN( "the value is alice" ) {
      THEN("contains should return false because == is case sensitive") {
        REQUIRE(mesa::contains(std::string("alice"), names) == false);
      }
    }
  }
}

SCENARIO( "Compute the invariants of contains" * doctest::timeout(0.5)) {

  GIVEN( "any empty stack" ) {
    std::stack<int> i;
    THEN( "false should be returned for int input" ) {
      REQUIRE(mesa::contains(1, i) == false);
    }
    std::stack<double> d;
    THEN( "false should be returned for double input" ) {
      REQUIRE(mesa::contains(3.14, d) == false);
    }
    std::stack<std::string> s;
    THEN( "false should be returned for string input" ) {
      REQUIRE(mesa::contains(std::string("anything"), s) == false);
    }
  }
}




