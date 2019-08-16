#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNAL

#include <map>
#include <string>

#include <doctest.h>
#include <json.hpp>

#include <lab28.h>

SCENARIO( "add input air temp to response" ) {
  auto expected = nlohmann::json::object({ {"status","success"} });
  std::map<std::string, std::string> kvp;

  GIVEN( "input 'air_temp'" ) {

    WHEN("air_temp is 10") {
      expected["input"]["air_temp"] = 10;
      kvp["air_temp"] = "10";
      auto actual = validate(kvp);
      THEN("The input value should be stored in the response_t.air_temp") {
        CHECK(10 == actual.air_temp);
      }
      AND_THEN("The status should == 'success'") {
        CHECK(expected["status"] == actual.doc["status"]);
      }
      AND_THEN("The valid flag should be 'true'") {
        CHECK(true == actual.valid);
      }
    }

    WHEN("air_temp is 8.8") {
      expected["input"]["air_temp"] = 8.8;
      kvp["air_temp"] = "8.8";
      auto actual = validate(kvp);
      THEN("The input value should be stored in the response_t.air_temp") {
        CHECK(8.8 == actual.air_temp);
      }
      AND_THEN("The status should == 'success'") {
        CHECK(expected["status"] == actual.doc["status"]);
      }
      AND_THEN("The valid flag should be 'true'") {
        CHECK(true == actual.valid);
      }
    }

    WHEN("air_temp is -3.14") {
      expected["input"]["air_temp"] = -3.14;
      kvp["air_temp"] = "-3.14";
      auto actual = validate(kvp);
      THEN("The input value should be stored in the response_t.air_temp") {
        CHECK(-3.14 == actual.air_temp);
      }
      AND_THEN("The status should == 'success'") {
        CHECK(expected["status"] == actual.doc["status"]);
      }
      AND_THEN("The valid flag should be 'true'") {
        CHECK(true == actual.valid);
      }
    }

  }

}


