#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <doctest.h>
#include <BigInt.h>

using mesa::BigInt;
using mesa::zero;
using mesa::one;

//
// For these tests to compile create:
//  -  operator++ and operator++(int), aka ++x and x++, respectively
//

TEST_CASE( "Test BigInt operator++") {
  BigInt actual;
  REQUIRE (operator==(zero, actual));
  REQUIRE (operator==(one, ++actual));
  actual = BigInt{98};
  CHECK (operator==(BigInt{99}, ++actual));
  CHECK (operator==(BigInt{100}, ++actual));
  actual = BigInt{9999};
  CHECK (operator==(BigInt{10000}, ++actual));
  CHECK (operator==(BigInt{10001}, ++actual));
}

TEST_CASE( "Test BigInt ++operator") {
  BigInt actual;
  REQUIRE (operator==(zero, actual));
  actual = actual++;
  CHECK (operator==(one, actual));
  actual = BigInt{298};
  actual = actual++;
  CHECK (operator==(BigInt{299}, actual));
  actual = actual++;
  CHECK (operator==(BigInt{300}, actual));
  actual = BigInt{8999};
  actual = actual++;
  CHECK (operator==(BigInt{9000}, actual));
  actual = actual++;
  CHECK (operator==(BigInt{9001}, actual));
}

