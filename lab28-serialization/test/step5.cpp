#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNAL

#include <map>
#include <string>

#include <doctest.h>
#include <json.hpp>

#include <lab28.h>

SCENARIO( "handle invalid input air temp" ) {
  auto expected = nlohmann::json::object({ {"status","error"} });
  std::map<std::string, std::string> kvp;
  std::string msg = "Required input parameter not defined.";

  GIVEN( "invalid 'air_temp'" ) {

    WHEN("air_temp is missing") {
      auto actual = validate(kvp);
      THEN("The status should == 'error'") {
        CHECK(expected["status"] == actual.doc["status"]);
      }
      AND_THEN("The valid flag should be 'false'") {
        CHECK(false == actual.valid);
      }
      AND_THEN("The message parameter should be defined") {
        CHECK(actual.doc["message"] == msg);
      }
    }

    WHEN("air_temp value is null") {
      std::string value;
      kvp["air_temp"] = value;
      auto actual = validate(kvp);
      THEN("The status should == 'error'") {
        CHECK(expected["status"] == actual.doc["status"]);
      }
      AND_THEN("The valid flag should be 'false'") {
        CHECK(false == actual.valid);
      }
      AND_THEN("The message parameter should be defined") {
        CHECK(actual.doc["message"] == msg);
      }
    }

    // WHEN("air_temp is -3.14") {
    //   expected["input"]["air_temp"] = -3.14;
    //   kvp["air_temp"] = "-3.14";
    //   auto actual = validate(kvp);
    //   THEN("The input value should be stored in the response_t.air_temp") {
    //     CHECK(-3.14 == actual.air_temp);
    //   }
    //   AND_THEN("The status should == 'success'") {
    //     CHECK(expected["status"] == actual.doc["status"]);
    //   }
    //   AND_THEN("The valid flag should be 'true'") {
    //     CHECK(true == actual.valid);
    //   }
    // }

  }

}


