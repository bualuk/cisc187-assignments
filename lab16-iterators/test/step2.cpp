#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <iterator>
#include <vector>

#include <doctest.h>
#include "../src/lab16.h"

SCENARIO( "Fill a container with n copies of a value") {

  GIVEN( "a vector of 5 zeros" ) {
    std::vector<unsigned> actual(5);
    WHEN( "fill_n is called with a value of 1" ) {
      AND_WHEN( "the count is 3" ) {
      AND_WHEN( "the start iterator is begin" ) {
        THEN( "the first three values should change" ) {
          mesa::fill_n(actual.begin(), 3, 1);
          std::vector<unsigned> expected = {1,1,1,0,0};
          for (unsigned i = 0; i < expected.size(); ++i) {
            CAPTURE (i);
            REQUIRE(actual[i] == expected[i]);
          }
        }
      }
      AND_WHEN( "the start iterator is begin + 1" ) {
        THEN( "the first value should be 0 and the next three values should change" ) {
          mesa::fill_n(actual.begin()+1, 3, 1);
          std::vector<unsigned> expected = {0,1,1,1,0};
          for (unsigned i = 0; i < expected.size(); ++i) {
            CAPTURE (i);
            REQUIRE(actual[i] == expected[i]);
          }
        }
      }
      AND_WHEN( "the start iterator is begin + 2" ) {
        THEN( "the last three values should change" ) {
          mesa::fill_n(actual.begin()+2, 3, 1);
          std::vector<unsigned> expected = {0,0,1,1,1};
          for (unsigned i = 0; i < expected.size(); ++i) {
            CAPTURE (i);
            REQUIRE(actual[i] == expected[i]);
          }
        }
      }
      }
    }
  }
  GIVEN( "a vector of 5 zeros" ) {
    std::vector<unsigned> actual(5);
    WHEN( "fill_n is called with a value of 1" ) {
      AND_WHEN( "the count is 2" ) {
        THEN( "the middle value should change" ) {
          mesa::fill_n(actual.begin()+2, 1, 1);
          std::vector<unsigned> expected = {0,0,1,0,0};
          for (unsigned i = 0; i < expected.size(); ++i) {
            CAPTURE (i);
            REQUIRE(actual[i] == expected[i]);
          }
        }
      }
    }
  }
}

SCENARIO( "Compute the invariants of fill_n") {

  GIVEN( "any container" ) {
    std::vector<int> actual = {1,2,3};
    std::vector<int> expected = {1,2,3};
    WHEN( "count == 0" ) {
      THEN( "no values should be modified" ) {
        mesa::fill_n(&actual[0], 0, 1);
        REQUIRE(actual == expected);
      }
    }
  }
}




