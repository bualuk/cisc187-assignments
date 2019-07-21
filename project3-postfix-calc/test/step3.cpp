#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <limits>
#include <string>
#include <vector>
#include <doctest.h>
#include <BigInt.h>

using mesa::BigInt;
using mesa::zero;
using mesa::one;
using std::string;
using std::vector;


//
// For these tests to compile create:
//  - a default constructor,
//  - a constructor to create a bigint from a string,
//  - a constructor to create a bigint from a long,
//  - a string conversion overload
//  - a function 'as_vector' to return a copy of the underlying storage
//


SCENARIO( "Test BigInt default construction") {
  GIVEN( "a default big int" ) {
    BigInt b;
    THEN( "the default value should be 0" ) {
      REQUIRE (string(b) == "0");
    }
    THEN( "the default value should == BigInt::zero" ) {
      REQUIRE (string(b) == string(zero));
    }
    THEN( "the default value should == BigInt::zero" ) {
      REQUIRE (string(b) == string(zero));
    }
  }
}

TEST_CASE("Test BigInt construction from an integral type") {
  REQUIRE_MESSAGE (string(BigInt{0}) == "0", "This test uses the std::string conversion operator");
  CHECK (string(BigInt{0}) == string(zero));
  CHECK (string(BigInt{1}) == "1");
  CHECK (string(BigInt{1}) == string(one));
  BigInt actual {11235813};
  CHECK (string(actual) == "11235813");
  vector<int> expected = {1,1,2,3,5,8,1,3};
  for (auto i = 0u; i < expected.size(); ++i) {
      CAPTURE(i);
      CHECK(actual.as_vector()[i] == expected[i]);
  }
}

TEST_CASE("Test BigInt construction from -1") {
  auto max = std::numeric_limits<unsigned long>::max();
  BigInt a = {max};
  BigInt b = {max};
  CHECK (string(a) == string(b));
  BigInt c = {max};
  BigInt d = {static_cast<unsigned long>(-1)};
  CHECK (string(c) == string(d));
}

TEST_CASE("Test BigInt construction from a std::string") {
  REQUIRE (string(BigInt{"0"}) == "0");
  REQUIRE (string(BigInt{"1"}) == "1");
  BigInt actual {"11235813"};
  REQUIRE (string(actual) == "11235813");
  vector<int> expected = {1,1,2,3,5,8,1,3};
  for (auto i = 0u; i < expected.size(); ++i) {
      CAPTURE(i);
      CHECK(actual.as_vector()[i] == expected[i]);
  }
}

TEST_CASE("Test BigInt construction from a std::string with leading zeros") {
  CHECK (string(BigInt{"01"}) == "1");
  CHECK (string(BigInt{"001"}) == "1");
  CHECK (string(BigInt{"010"}) == "10");
  BigInt actual {"011235813"};
  vector<int> expected = {1,1,2,3,5,8,1,3};

  CHECK (string(actual) == "11235813");
  auto actual_size = actual.as_vector().size();
  CHECK (actual_size == expected.size());
  for (auto i = 0u; i < expected.size(); ++i) {
      CAPTURE(i);
      CHECK(actual.as_vector()[i] == expected[i]);
  }
}

TEST_CASE("Test BigInt construction from a std::string with only zeros") {
  CHECK (string(BigInt{"00"}) == "0");
  CHECK (string(BigInt{"000"}) == "0");
}

TEST_CASE("Test BigInt construction from a std::string with surrounding spaces") {
  CHECK (string(BigInt{" 1"}) == "1");
  CHECK (string(BigInt{"  1"}) == "1");
  CHECK (string(BigInt{"01 "}) == "1");
  CHECK (string(BigInt{" 1 "}) == "1");
  BigInt actual {"   011235813    "};
  vector<int> expected = {1,1,2,3,5,8,1,3};

  CHECK (string(actual) == "11235813");
  auto actual_size = actual.as_vector().size();
  CHECK (actual_size == expected.size());
  for (auto i = 0u; i < expected.size(); ++i) {
      CAPTURE(i);
      CHECK(actual.as_vector()[i] == expected[i]);
  }
}

TEST_CASE("Test BigInt construction from a long std::string") {
  BigInt actual {"987654321098765432109876543210"};
  CHECK (string(actual) == "987654321098765432109876543210");
  vector<int> expected = {
    9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0,9,8,7,6,5,4,3,2,1,0
  };
  for (auto i = 0u; i < expected.size(); ++i) {
      CAPTURE(i);
      CHECK(actual.as_vector()[i] == expected[i]);
  }
}


