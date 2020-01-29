#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <string>
#include <sstream>
#include <doctest.h>
#include "../src/lab18.h"

SCENARIO( "Test mesa::in_order") {
  std::stringstream actual;

  WHEN( "mesa::in_order is called with an int" ) {
    auto left = mesa::make_tree<int>(2);
    auto right = mesa::make_tree<int>(3);
    auto root = mesa::make_tree<int>(1, left, right);
    mesa::in_order(actual,root);
    auto expected = std::string("2 1 3 ");
    THEN( "the stream should contain 3 values" ) {
      CHECK(actual.str() == expected);
    }
  }

  WHEN( "mesa::make_tree is called with a double" ) {
    auto left = mesa::make_tree(2.71828);
    auto right = mesa::make_tree(1.618);
    auto root = mesa::make_tree(3.14, left, right);
    mesa::in_order(actual,root);
    auto expected = std::string("2.71828 3.14 1.618 ");
    THEN( "the tree returned should contain 3 values" ) {
      CHECK(actual.str() == expected);
    }
  }

  WHEN( "mesa::make_tree is called with a string" ) {
    auto left = mesa::make_tree<std::string>("cruel");
    auto right = mesa::make_tree<std::string>("world!");
    auto root = mesa::make_tree<std::string>("goodbye,", left, right);
    mesa::in_order(actual,root);
    auto expected = std::string("cruel goodbye, world! ");
    THEN( "the tree returned should contain 3 values" ) {
      CHECK(actual.str() == expected);
    }
  }

}

