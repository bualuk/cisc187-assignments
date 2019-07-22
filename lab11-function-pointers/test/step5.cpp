#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <algorithm>
#include <vector>
#include <doctest.h>
#include <lab11.h>

SCENARIO( "Use greater to sort a vector") {
  GIVEN( "an array of unordered ints" ) {
    std::vector<int> x = {0,2,4,6,8,1,3,5,7,9};
    std::vector<int> expected = {9,8,7,6,5,4,3,2,1,0};
    WHEN( "the greater function is used in std::sort" ) {
      THEN( "the vector should be sorted descending" ) {
        std::sort(&x[0], &x[x.size()], mesa::greater<int,int>);
        REQUIRE( x == expected);
      }
    }
  }
}


