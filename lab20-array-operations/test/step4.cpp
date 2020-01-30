#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <iterator>

#include <doctest.h>
#include "../src/array.h"

SCENARIO( "function data() returns an array pointer" ) {

  WHEN( "mesa::array is declared" ) {
    THEN ("data returns a pointer to the first element") {
      mesa::array<int, 5> actual;
      CHECK(actual.data()+actual.size() == actual.end());
    }
  }

  WHEN( "mesa::array is declared" ) {
    THEN ("the std::distance between begin and end should equal the size") {
      mesa::array<int, 13> actual;
      CHECK(std::distance(actual.data(), actual.end()) == actual.size());
    }
  }

}

