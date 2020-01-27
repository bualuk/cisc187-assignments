#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <string>
#include <sstream>
#include <doctest.h>
#include "../src/lab18.h"

SCENARIO( "Test mesa::post_order") {
  std::stringstream actual;

  WHEN( "mesa::post_order is called with an int" ) {
    auto left = mesa::make_tree<int>(2);
    auto right = mesa::make_tree<int>(3);
    auto root = mesa::make_tree<int>(1, left, right);
    mesa::post_order(actual,root);
    auto expected = std::string("2 3 1 ");
    THEN( "the stream should contain 3 values" ) {
      CHECK(actual.str() == expected);
    }
  }

  WHEN( "mesa::make_tree is called with a double" ) {
    auto left = mesa::make_tree(2.71828);
    auto right = mesa::make_tree(1.618);
    auto root = mesa::make_tree(3.14, left, right);
    mesa::post_order(actual,root);
    auto expected = std::string("2.71828 1.618 3.14 ");
    THEN( "the tree returned should contain 3 values" ) {
      CHECK(actual.str() == expected);
    }
  }

  WHEN( "mesa::make_tree is called with a string" ) {
    auto left = mesa::make_tree<std::string>("cruel");
    auto right = mesa::make_tree<std::string>("world!");
    auto root = mesa::make_tree<std::string>("goodbye,", left, right);
    mesa::post_order(actual,root);
    auto expected = std::string("cruel world! goodbye, ");
    THEN( "the tree returned should contain 3 values" ) {
      CHECK(actual.str() == expected);
    }
  }

}


