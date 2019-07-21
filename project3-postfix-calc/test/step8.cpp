#define DOCTEST_CONFIG_NO_POSIX_SIGNALS
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest.h>
#include <BigInt.h>

using mesa::BigInt;
using mesa::zero;
using mesa::one;

//
// For these tests to compile create:
//  -  operator* and *=
//


TEST_CASE( "Test BigInt operator* simple") {
  REQUIRE (operator==(zero, zero*zero));
  REQUIRE (operator==(BigInt{0}, zero*one));
  REQUIRE (operator==(BigInt{0}, BigInt{99}*zero));

  REQUIRE (operator==(BigInt{4}, BigInt{2}*BigInt{2}));
  REQUIRE (operator==(BigInt{6}, BigInt{2}*BigInt{3}));
}
TEST_CASE( "Test BigInt operator* identity") {
  REQUIRE (operator==(BigInt{1}, one*one));
  REQUIRE (operator==(BigInt{99}, BigInt{99}*one));
  CHECK (operator==(BigInt{"12345678901234567891234567890123456789"}, 
                    BigInt{"12345678901234567891234567890123456789"}*one));
}

TEST_CASE( "Test BigInt operator* commutative property") {
  REQUIRE (operator==(BigInt{2}*BigInt{3}, 
                      BigInt{3}*BigInt{2}));
  REQUIRE (operator==(BigInt{34}*BigInt{21}, 
                      BigInt{21}*BigInt{34}));
  REQUIRE (operator==(BigInt{222}*BigInt{111}*BigInt{333}, 
                      BigInt{333}*BigInt{111}*BigInt{222}));
}

TEST_CASE( "Test BigInt operator* associative property") {
  // x*(y*z) == (x*y)*z
  auto a = BigInt{2}*BigInt{3}; 
  auto b = BigInt{3}*BigInt{4}; 
  REQUIRE (operator==(a*BigInt{4}, b*BigInt{2}));

  auto c = BigInt{98765}*BigInt{"9876543209990123456790"}; 
  auto d = BigInt{"9876543209990123456790"}*BigInt{9999}; 
  REQUIRE (operator==(c*BigInt{9999}, d*BigInt{98765}));
}

TEST_CASE( "Test BigInt operator* distributive property") {
  // x*(y+z) == x*y + x*z
  auto a = BigInt{4}*BigInt{9}; 
  auto b = BigInt{4}*BigInt{6}; 
  auto c = BigInt{4}*BigInt{3}; 
  REQUIRE (operator==(a, b+c));
}

TEST_CASE( "Test BigInt operator* with carry") {
  REQUIRE (operator==(BigInt{32100}, BigInt{321}*BigInt{100}));
  REQUIRE (operator==(BigInt{17982}, BigInt{999}*BigInt{18}));

  CHECK (operator==(BigInt{"97546105788873647310"}, 
                    BigInt{"9876543210"}*BigInt{"9876543211"}));
  CHECK (operator==(BigInt{"888888791111112"}, 
                    BigInt{"99999999"}*BigInt{"8888888"}));
  CHECK (operator==(BigInt{"8888888888888888888888887999991111111111111111111111112"}, 
                    BigInt{"999999999999999999999999999999"}
                   *BigInt{"8888888888888888888888888"}));
  REQUIRE (operator==(BigInt{3628800}, 
                      BigInt{1}*BigInt{1}*BigInt{2}*BigInt{3}
                     *BigInt{4}*BigInt{5}*BigInt{6}*BigInt{7}
                     *BigInt{8}*BigInt{9}*BigInt{10}));
}

TEST_CASE( "Test BigInt operator*= simple") {
  auto actual = BigInt{99};
  actual*=zero;
  REQUIRE (operator==(zero, actual));
  actual=BigInt{100};
  actual*=one;
  REQUIRE (operator==(BigInt{100}, actual));
  actual=BigInt{100};
  actual*=actual;
  REQUIRE (operator==(BigInt{10000}, actual));
}

TEST_CASE( "Test BigInt operator*= with carry") {
  auto actual=BigInt{999};
  actual*=BigInt{18};
  REQUIRE (operator==(BigInt{17982}, actual));

  actual=BigInt{9999};
  actual*=BigInt{888};
  REQUIRE (operator==(BigInt{8879112}, actual));

  actual=BigInt{987665};
  actual*=BigInt{567890};
  REQUIRE (operator==(BigInt{"560885076850"}, actual));

  actual=BigInt{"9876543211"};
  actual*=BigInt{"9876543210"};
  CHECK (operator==(BigInt{"97546105788873647310"}, actual));
  actual=BigInt{"8888888"};
  actual*=BigInt{"99999999"};
  CHECK (operator==(BigInt{"888888791111112"}, actual));
  actual=BigInt{"999999999999999999999999999999"};
  actual*=BigInt{"8888888888888888888888888"};
  REQUIRE (operator==(BigInt{"8888888888888888888888887999991111111111111111111111112"}, actual));
}


