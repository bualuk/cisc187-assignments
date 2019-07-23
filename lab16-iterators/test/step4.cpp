#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <string>
#include <vector>

#include <doctest.h>
#include "../src/lab16.h"

SCENARIO( "Copy values from a range if a predicate is satisfied") {

  GIVEN( "an array of 10 ints" ) {
    std::vector<unsigned> source = {0,2,4,6,8,1,3,5,7,9};
    WHEN( "the predicate is 'x >= 6'" ) {
      THEN( "each value > 6 should be copied to the destination" ) {
        std::vector<unsigned> actual(4);
        std::vector<unsigned> expected = {6,8,7,9};
        mesa::copy_if(source.begin(), source.end(), actual.begin(), [](int i){ return i >= 6;});
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual[i] == expected[i]);
        }
      }
    }
  }

  GIVEN( "a string" ) {
    std::string source = "The red dog is up";
    WHEN( "the predicate is 'a not vowel' and the value is 0" ) {
      THEN( "each non vowel char should be copied to the destination" ) {
        std::string expected = "Th rd dg s p";
        std::string actual(expected.size(), ' ');
        mesa::copy_if(source.begin(), source.end(), actual.begin(), 
           [](char i){ return i!='a'&&i!='e'&&i!='i'&&i!='o'&&i!='u';});
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual[i] == expected[i]);
        }
      }
    }
  }
}

SCENARIO( "Compute the invariants of copy_if") {

  GIVEN( "any container" ) {
    std::vector<int> source = {0,2,4,6,8,1,3,5,7,9};
    std::vector<int> actual;
    std::vector<int> expected;
    WHEN( "no value satifies the predicate" ) {
      //  mesa::copy_if(source.begin(), source.end(), actual.begin(), [](int i){ return i >= 999;});
      THEN( "no values should be copied" ) {
        REQUIRE(actual.empty() == true);
      }
    }
  }
}




