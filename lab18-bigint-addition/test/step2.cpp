#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <vector>

#include <doctest.h>
#include <lab18.h>

SCENARIO( "Add the digits of two vectors") {
  GIVEN( "x = {2} and y = {3}" ) {
    std::vector<int> x   {2};
    std::vector<int> y   {3};

    std::vector<int> actual = mesa::add(x, y);
    std::vector<int> expected = {5};
    THEN( "the size should be 1" ) {
      CHECK (actual.size() == expected.size());
    }
    AND_THEN( "the result should be 5" ) {
      REQUIRE(actual.back() == expected.back());
    }
  }

  GIVEN( "x = {1,2} and y = {3,4}") {
    std::vector<int> x   {1,2};
    std::vector<int> y   {3,4};

    std::vector<int> actual = mesa::add(x, y);
    std::vector<int> expected = {4,6};
    THEN( "each digit should be in a separate element of the vector" ) {
      CHECK (actual.size() == expected.size());
    }
    AND_THEN( "the result should be 46" ) {
      for (unsigned i = 0; i < expected.size(); ++i) {
        CAPTURE (i);
        CHECK_MESSAGE(actual[i] == expected[i], "digit " << i << " is incorrect");
      }
    }
  }

  GIVEN( "x = {0,9} and y = {0,3}") {
    std::vector<int> x   {0,9};
    std::vector<int> y   {0,3};

    std::vector<int> actual = mesa::add(x, y);
    std::vector<int> expected = {1,2};
    THEN( "each digit should be in a separate element of the vector" ) {
      CHECK (actual.size() == expected.size());
    }
    AND_THEN( "the result should be 12" ) {
      for (unsigned i = 0; i < expected.size(); ++i) {
        CAPTURE (i);
        CHECK_MESSAGE(actual[i] == expected[i], "digit " << i << " is incorrect");
      }
    }
  }

  GIVEN( "x = {9,9} and y = {1}") {
    std::vector<int> x   {9,9};
    std::vector<int> y   {1};

    std::vector<int> actual = mesa::add(x, y);
    std::vector<int> expected = {1,0,0};
    THEN( "each digit should be in a separate element of the vector" ) {
      CHECK (actual.size() == expected.size());
    }
    AND_THEN( "the result should be 100" ) {
      for (unsigned i = 0; i < expected.size(); ++i) {
        CAPTURE (i);
        CHECK(actual[i] == expected[i]);
      }
    }
  }

  GIVEN( "the two example vectors from the lab") {
    std::vector<int> x   {9,9,0,1,2,3,4,5,6,7,8,9};
    std::vector<int> y         {9,8,7,6,5,4,3,2,1,9};

    std::vector<int> actual = mesa::add(x, y);
    std::vector<int> expected = {1,0,0,0,0,0,0,0,0,0,0,0,8};
    THEN( "the leading 0's should be removed" ) {
      CHECK (actual.size() == expected.size());
    }
    AND_THEN( "the result should be 1000000000008" ) {
      for (unsigned i = 0; i < expected.size(); ++i) {
        CAPTURE (i);
        CHECK(actual[i] == expected[i]);
      }
    }
  }
}

