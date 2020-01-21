#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <numeric>
#include <vector>

#include <doctest.h>
#include <lab12.h>

SCENARIO( "Test Clock class") {
  WHEN( "a clock is created" ) {
    Clock c;

    THEN( "the default value should be 0" ) {
      CHECK (c.time() == doctest::Approx(0));
    }
  }
  WHEN( "the the time is set to 43425.5" ) {
    Clock c;
    c.time(43425.5);
    THEN( "the time returned should be the same" ) {
      CHECK (c.time() == doctest::Approx(43425.5));
    }
  }
  WHEN( "the the time is set to 1517287309.75" ) {
    Clock c;
    c.time(1517287309.75);
    THEN( "the time returned should be the same" ) {
      CHECK (c.time() == doctest::Approx(1517287309.75));
    }
  }
  WHEN( "the the time is set to -1234567" ) {
    Clock c;
    c.time(-1234567);
    THEN( "the time returned should be the same" ) {
      CHECK (c.time() == doctest::Approx(-1234567));
    }
  }
}


