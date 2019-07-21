#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <string>

#include <doctest.h>
#include <lab9.h>

using std::string;

SCENARIO( "Find substring in C string") {

  GIVEN( "a valid C string" ) {
    WHEN( "HELLO is provided" ) {
      const char* orig = "HELLO";
      AND_WHEN("the substring is 'LL'" ) {
        THEN("find should return 'LLO'" ) {
          string actual = mesa::find(orig, "LL");
          string expected = "LLO";
          REQUIRE_MESSAGE(!actual.empty(), "response from find came back empty!");
          REQUIRE(actual == expected);
        }
      }
      AND_WHEN("the substring is 'HE'" ) {
        THEN("find should return 'HELLO'" ) {
          string actual = mesa::find(orig, "HE");
          string expected = "HELLO";
          REQUIRE_MESSAGE(!actual.empty(), "response from find came back empty!");
          REQUIRE(actual == expected);
        }
      }
      AND_WHEN("the substring is 'E'" ) {
        THEN("find should return 'ELLO'" ) {
          string actual = mesa::find(orig, "E");
          string expected = "ELLO";
          REQUIRE_MESSAGE(!actual.empty(), "response from find came back empty!");
          REQUIRE(actual == expected);
        }
      }
    }
    WHEN( "'one fish, red fish, two fish, blue fish' is provided" ) {
      const char* orig = "one fish, red fish, two fish, blue fish";
      AND_WHEN("the substring is 'blue'" ) {
        THEN("find should return 'blue fish'" ) {
          string actual = mesa::find(orig, "blue");
          string expected = "blue fish";
          REQUIRE_MESSAGE(!actual.empty(), "response from find came back empty!");
          REQUIRE(actual == expected);
        }
      }
      AND_WHEN("the substring is 'fish'" ) {
        THEN("find should return 'fish, red fish, two fish, blue fish'" ) {
          string actual = mesa::find(orig, "fish");
          string expected = "fish, red fish, two fish, blue fish";
          REQUIRE_MESSAGE(!actual.empty(), "response from find came back empty!");
          REQUIRE(actual == expected);
        }
      }
    }
  }
}

SCENARIO( "Compute the invariants of find") {

  GIVEN( "an empty C string" ) {
    WHEN( "nothing is provided" ) {
      const char* empty = "";
      THEN("the result should be the null cahracter" ) {
        auto actual = mesa::find(empty, "A");
        REQUIRE(!actual);
      }
    }
  }
}




