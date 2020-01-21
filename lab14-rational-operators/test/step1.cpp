#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <cstdint>
#include <limits>
#include <string>
#include <sstream>

#include <doctest.h>
#include "../src/Rational.h"

SCENARIO( "test gcd") {
  WHEN( "the values passed to gcd are 54,24" ) {
    THEN( "the GCD 6" ) {
      REQUIRE(gcd(54,24) == 6);
    }
  }
  WHEN( "the values passed to gcd are 62,36" ) {
    THEN( "the GCD 2" ) {
      REQUIRE(gcd(62,36) == 2);
    }
  }
}

SCENARIO( "test invariants of gcd") {
  WHEN( "the numerator and denominator are both zero" ) {
    THEN("the GCD is 0") {
      REQUIRE(gcd(0,0) == 0);
    }
  }
  WHEN( "the numerator is zero" ) {
    THEN("the GCD is the denominator") {
      REQUIRE(gcd(0,8) == 8);
    }
  }
  WHEN( "the denominator is zero" ) {
    THEN("the GCD is the numerator") {
      REQUIRE(gcd(13,0) == 13);
    }
  }
  
}


SCENARIO( "Test Rational construction") {
  GIVEN( "a rational constructed with a int32_t" ) {
    Rational<std::int32_t> r;
    THEN( "the value should be 0" ) {
      REQUIRE (r.numerator() == 0);
      REQUIRE (r.denominator() == 1);
    }
  }
  GIVEN( "a rational constructed with a long" ) {
    Rational<long> r;
    THEN( "the value should be 0" ) {
      REQUIRE (r.numerator() == 0);
      REQUIRE (r.denominator() == 1);
    }
  }

}

SCENARIO( "Test Rational 2 argument  construction") {
  GIVEN( "a rational constructed with one argument" ) {
    WHEN("the numerator is 0") {
      Rational<int> r {0};
      THEN( "the value should be 0" ) {
        REQUIRE (r.numerator() == 0);
        REQUIRE (r.denominator() == 1);
      }
    }
    WHEN("the numerator is 1") {
      Rational<int> r {1};
      THEN( "the value should be 1" ) {
        REQUIRE (r.numerator() == 1);
        REQUIRE (r.denominator() == 1);
      }
    }
    WHEN("the numerator is -1") {
      Rational<std::int32_t> r {-1};
      THEN( "the value should be -1" ) {
        REQUIRE (r.numerator() == -1);
        REQUIRE (r.denominator() == 1);
      }
    }
    WHEN("the numerator is 13") {
      Rational<int> r {13};
      THEN( "the value should be 13" ) {
        REQUIRE (r.numerator() == 13);
        REQUIRE (r.denominator() == 1);
      }
    }
  }

  GIVEN( "a rational constructed with two parameters" ) {
    WHEN("the values are {0,1}") {
      Rational<std::uint32_t> r {0,1};
      THEN( "the value should be 0" ) {
        REQUIRE (r.numerator() == 0);
        REQUIRE (r.denominator() == 1);
      }
    }
    WHEN("the values are {-22,7}") {
      Rational<int32_t> r {-22,7};
      THEN( "the value should be -22/7" ) {
        REQUIRE (r.numerator() == -22);
        REQUIRE (r.denominator() == 7);
      }
    }
    WHEN("the values are {34,21}") {
      Rational<int> r {34,21};
      THEN( "the value should be 34/21" ) {
        REQUIRE (r.numerator() == 34);
        REQUIRE (r.denominator() == 21);
      }
    }
    WHEN("the values are {3,0}") {
      Rational<int> r {3,0};
      THEN( "the value should be 3/0" ) {
        CHECK (r.numerator() == 3);
        CHECK (r.denominator() == 0);
      }
    }
  }

}


SCENARIO ("test invariants of construction") {
  GIVEN ("a rational number with numerator and denominator 0") {
    WHEN("the numerator is 0, gcd(0,0) will segfault") {
      Rational<int> r {0,0};
      THEN( "just assign 0 to both and do not try to compute gcd(0,0)" ) {
        CHECK (r.numerator() == 0);
        CHECK (r.denominator() == 0);
      }
    }
  }
}


SCENARIO( "convert a rational to a double") {
  //      CHECK (275 == doctest::Approx(actual));
  GIVEN ("a valid rational number") {
    WHEN("the Rational is 0") {
      Rational<int> r {0};
      THEN( "the value should convert to 0" ) {
        REQUIRE (r.to_double() == 0);
      }
    }
    WHEN("the rational is 1/2") {
      Rational<int> r {1,2};
      THEN( "the value should convert to 0.5" ) {
        REQUIRE (r.to_double() == doctest::Approx(0.5));
      }
    }
    WHEN("the rational is {-22,7}") {
      Rational<int> r {-22,7};
      THEN( "the value should convert to -pi" ) {
        REQUIRE (r.to_double() == doctest::Approx(-3.14).epsilon(0.01));
      }
    }
  }
}

SCENARIO ("test invariants of to_double") {
  GIVEN ("a rational number with denominator 0") {
    WHEN("the numerator is 1") {
      Rational<int> r {1,0};
      THEN( "the value should convert +inf" ) {
        REQUIRE (r.to_double() == std::numeric_limits<double>::infinity());
      }
    }
    WHEN("the numerator is 0") {
      Rational<int> r {0,0};
      THEN( "the value should convert +inf" ) {
        REQUIRE (r.to_double() == std::numeric_limits<double>::infinity());
      }
    }
  }
}


SCENARIO( "convert a rational to a string") {
  GIVEN ("a valid rational number") {
    WHEN("the Rational is 0") {
      Rational<int> r {0};
      THEN( "the value should convert to the string '0'" ) {
        REQUIRE (std::string(r) == std::string("0"));
      }
    }
    WHEN("the Rational is 0, 5") {
      Rational<int> r {0,5};
      THEN( "the value should convert to the string '0'" ) {
        REQUIRE (std::string(r) == std::string("0"));
      }
    }
    WHEN("the rational is 1/2") {
      Rational<int> r {1,2};
      THEN( "the value should convert to the string '1/2'" ) {
        REQUIRE (std::string(r) == std::string("1/2"));
      }
    }
    WHEN("the rational is {-22,7}") {
      Rational<int> r {-22,7};
      THEN( "the value should convert to the string '-22/7'" ) {
        REQUIRE (std::string(r) == std::string("-22/7"));
      }
    }
    WHEN("the denominator is 0 and the numerator is not") {
      Rational<int> r {5,0};
      THEN( "the value should convert to the string 'inf'" ) {
        REQUIRE (std::string(r) == std::string("inf"));
      }
    }
    WHEN("the numerator and denominator are equal") {
      Rational<int> r {3,3};
      THEN( "the value should convert to the string '1'" ) {
        REQUIRE (std::string(r) == std::string("1"));
      }
    }
  }
}

SCENARIO( "Stream one Rational") {
  GIVEN( "a rational number" ) {
    WHEN("the Rational is 0") {
      Rational<int> r;
      THEN( "the value should output '0'" ) {
        std::ostringstream os;
        os << r;
        auto actual = os.str();
        std::string expected = "0";
        REQUIRE(actual == expected);
      }
    }
    WHEN("the Rational is 0, 5") {
      Rational<int> r {0,5};
      THEN( "the value should output '0'" ) {
        std::ostringstream os;
        os << r;
        auto actual = os.str();
        std::string expected = "0";
        REQUIRE(actual == expected);
      }
    }
    WHEN("the rational is 1/2") {
      Rational<int> r {1,2};
      THEN( "the value should output '1/2'" ) {
        std::ostringstream os;
        os << r;
        auto actual = os.str();
        std::string expected = "1/2";
        REQUIRE(actual == expected);
      }
    }
    WHEN("the rational is {-22,7}") {
      Rational<int> r {-22,7};
      THEN( "the value should output '-22/7'" ) {
        std::ostringstream os;
        os << r;
        auto actual = os.str();
        std::string expected = "-22/7";
        REQUIRE(actual == expected);
      }
    }
    WHEN("the denominator is 0 and the numerator is not") {
      Rational<int> r {5,0};
      THEN( "the value should output 'inf'" ) {
        std::ostringstream os;
        os << r;
        auto actual = os.str();
        std::string expected = "inf";
        REQUIRE(actual == expected);
      }
    }
    WHEN("the numerator and denominator are equal") {
      Rational<int> r {3,3};
      THEN( "the value should output '1'" ) {
        std::ostringstream os;
        os << r;
        auto actual = os.str();
        std::string expected = "1";
        REQUIRE(actual == expected);
      }
    }
  }
}

