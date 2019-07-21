#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <cstddef>
#include <string>

#include <doctest.h>
#include <lab9.h>

using std::string;

static void do_check(string orig) {
  THEN( "an exact copy should be created on the free store" ) {
    const char* expected = orig.c_str();
    auto actual = mesa::copy(&orig[0]);
    REQUIRE(actual != expected);
    for (int i = 0; actual[i]; ++i) {
      CAPTURE (i);
      CHECK(actual[i] == expected[i]);
    }
    //delete[] actual;
  }
}

SCENARIO( "Copy C string") {

  GIVEN( "a valid C string" ) {
    WHEN( "'howdy alice' is provided" ) {
      do_check("howdy alice");
    }
    WHEN( "'bye bob' is provided" ) {
      do_check("bye bob");
    }
    WHEN( "'The rain in Spain' is provided" ) {
      do_check("The rain in Spain");
    }
    WHEN( "'~!@#$-09876asdf;lkj' is provided" ) {
      do_check("~!@#$-09876asdf;lkj");
    }
  }

  GIVEN( "a C string with only null" ) {
    WHEN( "'\0' (null) is provided" ) {
      do_check("\0");
    }
  }

}


