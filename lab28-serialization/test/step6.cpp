#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNAL

#include <map>
#include <string>

#include <doctest.h>
#include <json.hpp>

#include <lab28.h>

SCENARIO( "Check if calculate runs with validated inputs" ) {
  std::map<std::string, std::string> kvp;

  GIVEN( "A simple valid response structure" ) {
    WHEN("air temp is high") {
      kvp["air_temp"] = "22";
      auto expected = make_json_pair("g/m**3", 19.36);
      auto actual = validate(kvp);
      calculate(&actual);
      auto correct_value = actual.doc["output"]["absolute_humidity"]["value"];
      THEN("The status should == 'success'") {
        CHECK(std::string("success") == actual.doc["status"]);
      }
      AND_THEN("The valid flag should be 'true'") {
        CHECK(true == actual.valid);
      }
      AND_THEN("The absolute humidity should be correct") {
        CHECK(expected["uom"] == 
            actual.doc["output"]["absolute_humidity"]["uom"]);
        CHECK(expected["value"] ==
            doctest::Approx(correct_value).epsilon(0.05));
      }
    }
  }

  GIVEN( "input air temp out of bounds for vapor pressure" ) {

    WHEN("air temp is high") {
      kvp["air_temp"] = "60.1";
      auto expected = make_json_pair("g/m**3", 130.6);
      auto actual = validate(kvp);
      calculate(&actual);
      auto correct_value = actual.doc["output"]["absolute_humidity"]["value"];
      AND_THEN("The absolute humidity should be correct") {
        CHECK(expected["uom"] == 
            actual.doc["output"]["absolute_humidity"]["uom"]);
        CHECK(expected["value"] ==
            doctest::Approx(correct_value).epsilon(0.05));
      }
    }

    WHEN("air temp is low") {
      kvp["air_temp"] = "-45.1";
      auto expected = make_json_pair("g/m**3", 0.11);
      auto actual = validate(kvp);
      calculate(&actual);
      auto correct_value = actual.doc["output"]["absolute_humidity"]["value"];
      AND_THEN("The absolute humidity should be correct") {
        CHECK(expected["uom"] == 
            actual.doc["output"]["absolute_humidity"]["uom"]);
        CHECK(expected["value"] ==
            doctest::Approx(correct_value).epsilon(0.05));
      }
    }

  }

}


