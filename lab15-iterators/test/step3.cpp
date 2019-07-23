#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <vector>
#include <string>

#include <doctest.h>
#include "../src/lab15.h"

SCENARIO( "Fill a container with increasing values") {

  GIVEN( "a vector of size 10" ) {
    std::vector<unsigned> actual(10);
    WHEN( "fill is called with a start value of 5" ) {
      THEN( "the vector should completely fill with sequentually increasing values" ) {
        mesa::fill(&actual, 5);
        std::vector<unsigned> expected = {5,6,7,8,9,10,11,12,13,14};
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual[i] == expected[i]);
        }
      }
    }
    WHEN( "fill is called with a start value of -8" ) {
      THEN( "the vector should completely fill with sequentually increasing values" ) {
        mesa::fill(&actual, -8);
        std::vector<int> expected = {-8,-7,-6,-5,-4,-3,-2,-1,0,1};
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual[i] == expected[i]);
        }
      }
    }
  }
  GIVEN( "a string of size 10" ) {
    WHEN( "fill is called with a string and start value of 100" ) {
      std::string actual(10, '\0');
      THEN( "the string should completely fill with sequentually increasing values" ) {
        mesa::fill(&actual, 100);
        std::string expected = "defghijklm";
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual[i] == expected[i]);
        }
      }
    }
  }
}

SCENARIO( "Compute the invariants of fill_sequence") {

  GIVEN( "any empty container" ) {
    std::vector<int> actual;
    std::vector<int> expected;
    WHEN( "begin == end" ) {
      THEN( "no values should be modified" ) {
        mesa::fill(&actual, 999);
        REQUIRE(actual == expected);
      }
    }
  }
}




