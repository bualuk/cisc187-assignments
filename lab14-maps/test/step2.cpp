#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <string>
#include <doctest.h>
#include <lab14.h>

SCENARIO( "Transform a string to lower case") {

  GIVEN( "a valid string" ) {
    WHEN( "HELLO is provided" ) {
      std::string orig = "HELLO";
      std::string expected = "hello";
      std::string actual = mesa::to_lower(orig);
      THEN( "the string should become hello" ) {
        REQUIRE(actual.compare(expected) == 0);
      }
    }
    WHEN( "'Goodbye, World!' is provided" ) {
      std::string orig = "Goodbye, World!";
      std::string expected = "goodbye, world!";
      std::string actual = mesa::to_lower(orig);
      THEN( "the string should become 'goodbye, world!'" ) {
        REQUIRE(actual.compare(expected) == 0);
      }
    }
    WHEN( "'ncdSNCVFIEncGckdJdXsM' is provided" ) {
      std::string orig = "ncdSNCVFIEncGckdJdXsM";
      std::string expected = "ncdsncvfiencgckdjdxsm";
      std::string actual = mesa::to_lower(orig);
      THEN( "the string should become 'ncdsncvfiencgckdjdxsm'" ) {
        REQUIRE(actual.compare(expected) == 0);
      }
    }
  }
}

SCENARIO( "Compute the invariants of to_lower") {

  GIVEN( "an empty string" ) {
    WHEN( "nothing is provided" ) {
      std::string orig;
      std::string expected;
      std::string actual = mesa::to_lower(orig);
      THEN( "nothing should be returned" ) {
        REQUIRE(actual.compare(expected) == 0);
      }
    }
  }
}




