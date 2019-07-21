#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <doctest.h>
#include <BigInt.h>

using mesa::BigInt;
using mesa::zero;
using mesa::one;

//
// For these tests to compile create:
//  - all 6 comparison overloads
//


TEST_CASE( "Test BigInt operator==") {
  REQUIRE (operator==(BigInt{0}, zero));
  REQUIRE (operator==(BigInt{1}, one));

  BigInt x {987654321};
  BigInt y {987654321};
  BigInt z {987654321};
  CHECK (operator==(x,x));
  CHECK (operator==(x,y));
  CHECK (operator==(y,x));
  CHECK (operator==(y,z));
  CHECK (operator==(x,z));
}

TEST_CASE( "Test BigInt operator!=") {
  REQUIRE (operator!=(BigInt{0}, one));
  REQUIRE (operator!=(BigInt{1}, zero));

  BigInt x {"9876543210"};
  BigInt y {"9876543211"};
  CHECK (operator!=(x,y));
  CHECK (operator!=(y,x));
}

TEST_CASE( "Test BigInt operator>") {
  CHECK (operator>(one,zero));
  CHECK (!operator>(one,one));
  CHECK (operator>(BigInt {34},BigInt {33}));
  CHECK (!operator>(BigInt {9999},BigInt {9999}));
  CHECK (operator>(BigInt {"9876543211"},BigInt {"9876543210"}));
  CHECK (operator>(BigInt {"12345678901234567899876543211"},
                   BigInt {"12345678901234567899876543210"}));
}

TEST_CASE( "Test BigInt operator<") {
  CHECK (operator<(zero,one));
  CHECK (!operator<(one,zero));
  CHECK (!operator<(one,one));
  CHECK (operator<(BigInt {33},BigInt {34}));
  CHECK (!operator<(BigInt {9999},BigInt {9999}));
  CHECK (operator<(BigInt {"12345678901234567899876543210"},
                   BigInt {"12345678901234567899876543211"}));
}


TEST_CASE( "Test BigInt operator>=") {
  CHECK (operator>=(one,zero));
  CHECK (operator>=(one,one));
  CHECK (operator>=(BigInt {34},BigInt {33}));
  CHECK (operator>=(BigInt {9999},BigInt {9999}));
  CHECK (operator>=(BigInt {"9876543211"},BigInt {"9876543210"}));
  CHECK (operator>=(BigInt {"12345678901234567899876543210"},
                   BigInt {"12345678901234567899876543210"}));
}

TEST_CASE( "Test BigInt operator<=") {
  CHECK (operator<=(zero,one));
  CHECK (operator<=(one,one));
  CHECK (operator<=(BigInt {33},BigInt {34}));
  CHECK (operator<=(BigInt {9999},BigInt {9999}));
  CHECK (operator<=(BigInt {"12345678901234567899876543210"},
                   BigInt {"12345678901234567899876543211"}));
  CHECK (operator<=(BigInt {"12345678901234567899876543210"},
                   BigInt {"12345678901234567899876543210"}));
}

