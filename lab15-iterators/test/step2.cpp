#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <vector>
#include <string>

#include <doctest.h>
#include "../src/lab15.h"

SCENARIO( "Fill a container with increasing values") {

  GIVEN( "a vector of size 10" ) {
    std::vector<unsigned> actual(10);
    WHEN( "fill_sequence is called with a start value of 1" ) {
      THEN( "the vector should completely fill with sequentually increasing values" ) {
        mesa::fill_sequence(actual.begin(), actual.end(), 1);
        std::vector<unsigned> expected = {1,2,3,4,5,6,7,8,9,10};
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual[i] == expected[i]);
        }
      }
    }
    WHEN( "fill_sequence is called with a start value of -3" ) {
      THEN( "the vector should completely fill with sequentually increasing values" ) {
        mesa::fill_sequence(actual.begin(), actual.end(), -3);
        std::vector<int> expected = {-3,-2,-1,0,1,2,3,4,5,6};
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual[i] == expected[i]);
        }
      }
    }
  }
  GIVEN( "a string of size 10" ) {
    WHEN( "fill_sequence is called with a string and start value of 65" ) {
      std::string actual(10, '\0');
      THEN( "the string should completely fill with sequentually increasing values" ) {
        mesa::fill_sequence(actual.begin(), actual.end(), 65);
        std::string expected = "ABCDEFGHIJ";
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
    std::vector<int> actual(10);
    std::vector<int> expected(10);
    WHEN( "begin == end" ) {
      THEN( "no values should be modified" ) {
        mesa::fill_sequence(&actual[0], &actual[0], 1);
        REQUIRE( actual == expected);
      }
    }
  }
}




