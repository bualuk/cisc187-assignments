#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <numeric>
#include <stack>
#include <string>
#include <vector>

#include <doctest.h>
#include "../src/lab13.h"

SCENARIO( "Reverse a stack" * doctest::timeout(0.5)) {

  GIVEN( "a stack of 10 ints, 0 through 9" ) {
    std::stack<int> x;
    std::vector<int> v(10);
    std::iota(v.begin(), v.end(), 0);
    for (const auto& i: v) x.push(i);

    std::stack<int> expected;
    std::iota(v.rbegin(), v.rend(), 0);
    for (const auto& i: v) expected.push(i);
    WHEN( "the values are reversed" ) {
      std::stack<int> reversed = mesa::reverse (x);
      THEN("the reversed stack size should equal the original") {
          REQUIRE (reversed.size() == expected.size());
      }
      AND_THEN("the reversed stack should equal the expected") {
        while (!reversed.empty()) {
          REQUIRE (reversed.top() == expected.top());
          reversed.pop();
          expected.pop();
        }
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

    std::stack<std::string> expected;
    expected.push("Greg");
    expected.push("Fran");
    expected.push("Earl");
    expected.push("Darla");
    expected.push("Clarice");
    expected.push("Bob");
    expected.push("Alice");
    WHEN( "the names are reversed" ) {
      std::stack<std::string> reversed = mesa::reverse (names);
      THEN("the reversed stack size should equal the original") {
          REQUIRE (reversed.size() == expected.size());
      }
      AND_THEN("the reversed stack should equal the expected") {
        while (!reversed.empty()) {
          REQUIRE (reversed.top() == expected.top());
          reversed.pop();
          expected.pop();
        }
      }
    }
  }
}

SCENARIO( "Compute the invariants of reverse" * doctest::timeout(0.5)) {

  GIVEN( "an empty stack" ) {
    std::stack<int> in;
    THEN( "an empty stack should be returned" ) {
      auto expected = mesa::reverse(in);
      REQUIRE(expected.empty() == true);
    }
  }
}


