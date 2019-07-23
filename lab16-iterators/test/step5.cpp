#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <doctest.h>
#include "../src/lab16.h"

SCENARIO( "Print values from a vector if a predicate is satisfied") {
  GIVEN( "an vector of 10 ints" ) {
    std::vector<int> source = {0,1,4,6,8,1,3,5,7,9};
    WHEN( "the predicate is 'x < 6'" ) {
      THEN( "each character value < 6 should be printed" ) {
        std::ostringstream actual;
        auto cout_buff = std::cout.rdbuf(); // save pointer to std::cout buffer
        std::cout.rdbuf(actual.rdbuf());     // sub local for cout
        mesa::print_if(source, [](int i){ return i < 6;});
        std::cout.rdbuf(cout_buff);          // restore cout

        std::string expected = "0 1 4 1 3 5";
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual.str()[i] == expected[i]);
        }
      }
    }

    WHEN( "the predicate is 'x == 1'" ) {
      THEN( "each character value == 1 should be printed" ) {
        std::ostringstream actual;
        auto cout_buff = std::cout.rdbuf();
        std::cout.rdbuf(actual.rdbuf());
        mesa::print_if(source, [](int i){ return i == 1;});
        std::cout.rdbuf(cout_buff);

        std::string expected = "1 1";
        for (unsigned i = 0; i < expected.size(); ++i) {
          CAPTURE (i);
          REQUIRE(actual.str()[i] == expected[i]);
        }
      }
    }
  }
}



SCENARIO( "Test the invariants of print_if") {
  GIVEN( "an vector of 10 ints" ) {
    std::vector<int> source = {0,1,4,6,8,1,3,5,7,9};
    WHEN( "the predicate is 'x > 999'" ) {
      THEN( "nothing should be printed" ) {
        std::ostringstream actual;
        auto cout_buff = std::cout.rdbuf();
        std::cout.rdbuf(actual.rdbuf());
        mesa::print_if(source, [](int i){ return i > 999;});
        std::cout.rdbuf(cout_buff);
        REQUIRE(actual.str().empty() == true);
      }
    }
  }

  GIVEN( "an empty vector" ) {
    std::vector<int> source;
    WHEN( "the predicate is anything" ) {
      THEN( "nothing should be printed" ) {
        std::ostringstream actual;
        auto cout_buff = std::cout.rdbuf();
        std::cout.rdbuf(actual.rdbuf());
        mesa::print_if(source, [](int i){ return i < 6;});
        std::cout.rdbuf(cout_buff);
        REQUIRE(actual.str().empty() == true);
      }
    }

  }
}



