#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <doctest.h>
#include <lab19.h>

SCENARIO( "Test Complex class") {
  WHEN( "a complex number is created" ) {
    Complex c;

    THEN( "the default real and imaginary parts should == 0" ) {
      REQUIRE (c.real() == doctest::Approx(0));
      REQUIRE (c.imaginary() == doctest::Approx(0));
    }
  }
  WHEN( "the complex number is {0,0}" ) {
    Complex c {0,0};
    THEN( "the real and imaginary parts should == 0" ) {
      REQUIRE (c.real() == doctest::Approx(0));
      REQUIRE (c.imaginary() == doctest::Approx(0));
    }
  }
  WHEN( "the complex number is {-3,1}" ) {
    Complex c {-3,1};
    THEN( "the real part should == -3 and imaginary part should == 1" ) {
      REQUIRE (c.real() == doctest::Approx(-3));
      REQUIRE (c.imaginary() == doctest::Approx(1));
    }
  }
  WHEN( "the complex number is {5,8}" ) {
    Complex c {5,8};
    THEN( "the real part should == 5 and imaginary part should == 8" ) {
      REQUIRE (c.real() == doctest::Approx(5));
      REQUIRE (c.imaginary() == doctest::Approx(8));
    }
  }
  WHEN( "the complex number is {13.8,-21.13}" ) {
    Complex c {13.8,-21.13};
    THEN( "the real part should == 13.8 and imaginary part should == -21.13" ) {
      REQUIRE (c.real() == doctest::Approx(13.8));
      REQUIRE (c.imaginary() == doctest::Approx(-21.13));
    }
  }
}


