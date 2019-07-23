#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <set>
#include <vector>

#include <doctest.h>
#include "../src/lab15.h"

SCENARIO( "Erase values from a vector if a predicate is satisfied") {
  GIVEN( "an array of 10 ints" ) {
    std::vector<unsigned> actual = {0,2,4,6,8,1,3,5,7,9};
    WHEN( "the predicate is 'x >= 6'" ) {
      THEN( "each value > 6 should be removed" ) {
        mesa::erase_if(&actual, [](int i){ return i >= 6;});
        std::vector<unsigned> expected = {0,2,4,1,3,5};
        REQUIRE(actual.size() == expected.size());
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual[i] == expected[i]);
        }
      }
    }
  }
  GIVEN( "an array of 10 ints" ) {
    std::vector<int> actual = {0,2,4,6,8,1,3,5,7,9};
    WHEN( "the predicate checks for even values" ) {
      THEN( "each even element should be removed" ) {
        mesa::erase_if(&actual, [](int i){ return i % 2 == 0;});
        std::vector<int> expected = {1,3,5,7,9};
        REQUIRE(actual.size() == expected.size());
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual[i] == expected[i]);
        }
      }
    }
  }
}

SCENARIO( "Erase values from a set if a predicate is satisfied") {
  GIVEN( "a set of 10 items" ) {
    std::set<int> actual = {1,2,3,5,8,13,21,34};
    WHEN( "the predicate is checking for odd values" ) {
      THEN( "each odd element should be removed: the set should contain 2,8,34" ) {
        mesa::erase_if(&actual, [](int i){ return i%2 != 0;});
        std::set<int> expected = {2,8,34};
        REQUIRE(actual.size() == expected.size());
        REQUIRE(actual == expected);
      }
    }
  }
}

SCENARIO( "Compute the invariants of erase_if") {

  GIVEN( "any container" ) {
    std::vector<int> actual = {0,2,4,6,8,1,3,5,7,9};
    std::vector<int> expected = {0,2,4,6,8,1,3,5,7,9};
    WHEN( "no value satifies the predicate" ) {
      mesa::erase_if(&actual, [](int x){return x>999;});
      THEN( "no values should be erased" ) {
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual[i] == expected[i]);
        }
      }
    }
  }
  GIVEN( "an empty container" ) {
    // this test is mostly checking against segfault on empty containers
    std::vector<int> actual;
    WHEN( "any predicate is used" ) {
      mesa::erase_if(&actual, [](int x){return x==0;});
      THEN( "no values should be erased" ) {
          REQUIRE(actual.empty() == true);
      }
    }
  }
}




