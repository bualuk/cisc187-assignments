#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <vector>
#include <doctest.h>
#include <lab11.h>


SCENARIO( "Evaluate odd values") {

  WHEN( "the value is unsigned odd" ) {
    std::vector<unsigned> x = {1,3,5,7,9,11,999,11213,667};
    THEN( "is_odd should return true" ) {
      for (const auto& value: x) {
        CAPTURE(value);
        REQUIRE( mesa::is_odd(value) == true);
      }
    }
  }
  WHEN( "the value is unsigned even" ) {
    std::vector<unsigned> x = {2,4,6,12,998,11212,666};
    THEN( "is_odd should return false" ) {
      for (const auto& value: x) {
        CAPTURE(value);
        REQUIRE( mesa::is_odd(value) == false);
      }
    }
  }

  WHEN( "the value is odd" ) {
    std::vector<long> x = {-1,1,-5,-11213,-987654321};
    THEN( "is_odd should return true" ) {
      for (const auto& value: x) {
        CAPTURE(value);
        REQUIRE( mesa::is_odd(value) == true);
      }
    }
  }
  WHEN( "the value is even" ) {
    std::vector<long> x = {2,-2,-4,-11212,987654328};
    THEN( "is_odd should return false" ) {
      for (const auto& value: x) {
        CAPTURE(value);
        REQUIRE( mesa::is_odd(value) == false);
      }
    }
  }
}

