#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <vector>
#include <doctest.h>
#include <lab11.h>


SCENARIO( "Count values mathcing a predicate") {

  auto is_even = [](int i){ return i % 2 == 0;};
  auto gt_6 = [](int i){ return i >= 6;};
  auto gt_7 = [](int i){ return i > 7;};

  GIVEN( "an array of 10 ints" ) {
    std::vector<int> x = {0,2,4,6,8,1,3,5,7,9};
    WHEN( "the entire array is examined for evens" ) {
      THEN( "count_if should return 5" ) {
        REQUIRE( mesa::count_if(&x[0], &x[x.size()], is_even) == 5);
      }
    }
    WHEN( "the entire array is examined for values > 7" ) {
      THEN( "count_if should return 2" ) {
        REQUIRE( mesa::count_if(&x[0], &x[x.size()], gt_7) == 2);
      }
    }
    WHEN( "the part of array is examined for values >= 6" ) {
      THEN( "count_if should return 0" ) {
        REQUIRE( mesa::count_if(&x[3], &x[x.size()], gt_6) == 4);
      }
    }
  }
  GIVEN( "an array of 10 doubles" ) {
    std::vector<double> x = {0,2,4,6.99,8.01,1,3.14,5,7,9};
    WHEN( "the entire array is examined for values > 7" ) {
      THEN( "count_if should return 2" ) {
        REQUIRE( mesa::count_if(&x[0], &x[x.size()],
                  [](double i){ return i > 7; } ) == 2);
      }
    }
    WHEN( "the part of array is examined for values >= 6" ) {
      THEN( "count_if should return 0" ) {
        REQUIRE( mesa::count_if(&x[3], &x[x.size()],
                  [](double i){ return i >= 6; } ) == 4);
      }
    }
  }
}

SCENARIO( "Compute the invariants of count_if") {

  auto is_even = [](int i){ return i % 2 == 0;};

  GIVEN( "any empty container" ) {
    std::vector<int> x = {0,2,4,6,8,1,3,5,7,9};
    WHEN( "begin == end" ) {
      THEN( "0 should be returned" ) {
        REQUIRE( mesa::count_if(&x[0], &x[0], is_even) == 0);
      }
    }
  }
}




