#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <string>
#include <sstream>

#include <doctest.h>
#include "../src/bstree.h"

SCENARIO( "Test bstree(T)") {

  WHEN( "mesa::bstree(T) is declared with an int type" ) {
    int expected = 8;
    mesa::bstree<int> actual(expected);
    THEN( "the tree_node contains a value" ) {
      REQUIRE(actual.contains(expected) == true);
      // CHECK_MESSAGE(actual.left == nullptr, "Left child is not the nullptr");
      // CHECK_MESSAGE(actual.right == nullptr, "Left child is not the nullptr");
    }
  }

}


