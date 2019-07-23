#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <numeric>
#include <vector>

#include <doctest.h>
#include <lab17.h>

SCENARIO( "Make the lab10a vector") {
  WHEN( "size = 10 and max = 2" ) {
    std::vector<int> actual = mesa::make_vector(10, 2);
    std::vector<int> expected = {1,2,1,2,1,2,1,2,1,2};
    THEN( "the size should be 10" ) {
      CHECK (actual.size() == expected.size());
    }
    AND_THEN( "the result should be {1,2,1,2...}" ) {
      for (unsigned i = 0; i < expected.size(); ++i) {
        CAPTURE (i);
        REQUIRE(actual[i] == expected[i]);
      }
    }
  }
  WHEN( "the max is equal to or greater than size" ) {
    std::vector<int> actual = mesa::make_vector(21, 21);
    std::vector<int> expected(21);
    std::iota(expected.begin(), expected.end(), 1);
    THEN( "the result should be a sequence the same as std::iota" ) {
      for (unsigned i = 0; i < expected.size(); ++i) {
        CAPTURE (i);
        REQUIRE(actual[i] == expected[i]);
      }
    }
  }
}

SCENARIO( "Compute the invariants of make_vector") {

  WHEN( "the size parameter is 0" ) {
    std::vector<int> actual = mesa::make_vector(0, 2);
    THEN( "the vector should be empty" ) {
      REQUIRE(actual.size() == 0);
    }
  }
}


