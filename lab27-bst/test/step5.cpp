#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <random>
#include <vector>

#include <doctest.h>
#include "../src/bstree.h"

SCENARIO( "Test bstree erase") {
  std::vector<int> expected = {1,3,4,6,7,8,10,13,14};
  auto vec = expected;
  std::random_device rd;
  std::mt19937 g(rd());

  std::shuffle(vec.begin(), vec.end(), g);


  GIVEN ( "the lab example tree values" ) {
    mesa::bstree<int> test_tree;
    for (auto& v : vec) {
      test_tree.insert(v);
    }

    WHEN (" each value is removed" ) {
      THEN ( "contains(value) is false" ) {
        for (const auto& v: vec) {
          CHECK(test_tree.contains(v) == true);
          test_tree.erase(v);
          CHECK(test_tree.contains(v) == false);
        }
        REQUIRE(test_tree.empty() == true);
      }
    }

  }
}

