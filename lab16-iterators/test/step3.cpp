#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <vector>
#include <string>

#include <doctest.h>
#include "../src/lab16.h"

SCENARIO( "Append 'n' values to a container") {

  GIVEN( "a vector of size 7" ) {
    std::vector<unsigned> actual {33,22,11,0,1,2,3};
    WHEN( "append_n is called with a count of 5 and value = 8" ) {
      THEN( "the vector should add 5 8's to the end" ) {
        mesa::append_n(&actual, 5,8);
        std::vector<unsigned> expected = {33,22,11,0,1,2,3, 8,8,8,8,8};
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual[i] == expected[i]);
        }
      }
    }
  }

  GIVEN( "a hello string" ) {
    std::string actual = "Hello, world";
    WHEN( "append_n is called with a count of 3 and value = '!'" ) {
      THEN( "the string should have 3 '!'s to the end" ) {
        mesa::append_n(&actual, 5,'!');
        std::string expected = "Hello, world!!!";
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual[i] == expected[i]);
        }
      }
    }
  }
}

SCENARIO( "Compute the invariants of append_n") {
  GIVEN( "any container" ) {
    std::vector<int> actual;
    std::vector<int> expected;
    WHEN( "count == 0" ) {
      THEN( "no values should be modified" ) {
        mesa::append_n(&actual, 0,  999);
        REQUIRE(actual == expected);
      }
    }
  }
}




