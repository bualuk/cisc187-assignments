#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <string>
#include <sstream>

#include <doctest.h>
#include "../src/tree_node.h"

SCENARIO( "Test tree(T)") {

  WHEN( "mesa::tree_node(T) is declared with an int type" ) {
    int expected = 8;
    mesa::tree_node<int> actual(expected);
    THEN( "the tree_node contains a value" ) {
      REQUIRE(actual.value == expected);
      CHECK_MESSAGE(actual.left == nullptr, "Left child is not the nullptr");
      CHECK_MESSAGE(actual.right == nullptr, "Left child is not the nullptr");
    }
  }

  WHEN( "mesa::tree_node(T) is declared with a double type" ) {
    double expected = 2.781828;
    mesa::tree_node<double> actual(expected);
    THEN( "the tree_node contains a value" ) {
      REQUIRE(actual.value == expected);
    }
  }

  WHEN( "mesa::tree_node(T) is declared with a string type" ) {
    std::string expected = "hello, there!";
    mesa::tree_node<std::string> actual(expected);
    THEN( "the tree_node contains a value" ) {
      REQUIRE(actual.value == expected);
    }
  }

  WHEN( "mesa::tree_node(T) is declared with a UDT" ) {
    struct test_step {
      int x = 3;
      int y = 4;
    };
    test_step expected;
    mesa::tree_node<test_step> actual(expected);
    THEN( "the tree_node contains a value" ) {
      REQUIRE(actual.value.x == expected.x);
      REQUIRE(actual.value.y == expected.y);
    }
  }

}



