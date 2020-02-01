#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <utility>
#include <doctest.h>
#include <BigInt.h>

using mesa::BigInt;
using mesa::zero;

//
// For these tests to compile create:
//  - a copy constructor,
//  - a copy assignment overload,
//  - a move constructor,
//  - a move assignment overload,
//


TEST_CASE("Test BigInt copy construction") {
  BigInt a {9876};
  BigInt b = a;
  REQUIRE_MESSAGE (operator==(a,b), "b was not constructed from a");
  BigInt x {"98765432109876543210987654321"};
  BigInt y = x;
  REQUIRE_MESSAGE (operator==(x,y), "y was not constructed from x");
}


TEST_CASE("Test BigInt copy assignment") {
  BigInt x {"98765432109876543210987654321"};
  BigInt y;
  REQUIRE (operator==(zero,y));
  y = x;
  REQUIRE_MESSAGE (operator==(x,y), "x is not a copy of y");
  y = BigInt{13};
  REQUIRE_MESSAGE (operator!=(x,y), "x changed when we modified y");
  auto z = y;
  REQUIRE_MESSAGE (operator==(z,y), "z is not a copy of y");
  REQUIRE (operator!=(x, z));
}


TEST_CASE("Test BigInt move construction") {
  BigInt a {9876};
  BigInt b = std::move(a);
  REQUIRE_MESSAGE (operator==(BigInt{9876},b), "b was not constructed from a");
  REQUIRE_MESSAGE (a.as_vector().empty(), "a was not moved");
  BigInt x {"98765432109876543210987654321"};
  BigInt y = std::move(x);
  REQUIRE_MESSAGE (x.as_vector().empty(), "x was not moved");
  REQUIRE_MESSAGE (operator==(BigInt{"98765432109876543210987654321"},y), 
                   "y was not constructed from x");
}


TEST_CASE("Test BigInt move assignment") {
  BigInt x {"98765432109876543210987654321"};
  BigInt y;
  REQUIRE (operator==(y,zero));
  y = std::move(x);
  REQUIRE_MESSAGE (x.as_vector().empty(), "x was not moved");
  REQUIRE_MESSAGE (operator==(BigInt{"98765432109876543210987654321"},y), 
                   "y was not constructed from x");
}


