#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <string>
#include <vector>

#include <doctest.h>
#include "../src/lab15.h"

SCENARIO( "Insert values if a predicate is satisfied") {

  GIVEN( "an array of 10 ints" ) {
    std::vector<unsigned> actual = {0,2,4,6,8,1,3,5,7,9};
    WHEN( "the predicate is 'x >= 6' and the value is 0" ) {
      THEN( "each value > 6 should have a zero inserted before it" ) {
        mesa::insert_each_if(&actual, 0, [](int i){ return i >= 6;});
        std::vector<unsigned> expected = {0,2,4,0,6,0,8,1,3,5,0,7,0,9};
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual[i] == expected[i]);
        }
      }
    }
  }
  GIVEN( "an array of 10 char" ) {
    std::vector<unsigned char> actual = {0,2,4,6,8,1,3,5,7,9};
    WHEN( "the predicate is 'x < 5' and the value is 255" ) {
      THEN( "each value > 6 should have a zero inserted before it" ) {
        mesa::insert_each_if(&actual, 255, [](unsigned char i){ return i < 5;});
        std::vector<unsigned char> expected = {255,0,255,2,255,4,6,8,255,1,255,3,5,7,9};
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual[i] == expected[i]);
        }
      }
    }
  }
}

SCENARIO( "Compute the invariants of insert_each_if") {

  GIVEN( "any container" ) {
    std::vector<int> actual = {0,2,4,6,8,1,3,5,7,9};
    std::vector<int> expected = {0,2,4,6,8,1,3,5,7,9};
    WHEN( "no value satifies the predicate" ) {
      mesa::insert_each_if(&actual, 999, [](int x){return x>999;});
      THEN( "no values should be inserted" ) {
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual[i] == expected[i]);
        }
      }
    }
  }
  GIVEN( "an empty container" ) {
    std::vector<int> actual;
    WHEN( "any predicate is used" ) {
      mesa::insert_each_if(&actual, 999, [](int x){return x==0;});
      THEN( "no values should be inserted" ) {
          REQUIRE(actual.empty() == true);
      }
    }
  }
}




