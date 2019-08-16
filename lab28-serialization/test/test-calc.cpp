#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNAL

#include <map>
#include <string>

#include <doctest.h>
#include <json.hpp>

#include <lab28.h>

SCENARIO( "Check if calculate runs with validated inputs" ) {
  auto expected = nlohmann::json::object({ {"status","success"} });
  std::map<std::string, std::string> kvp;
  std::string msg = "Required input parameter not defined.";

  GIVEN( "A simple valid response structure" ) {
    response_t expected = {true, json::object({ {"status","success"} })};

    expected.air_temp = 22;
    auto actual = expected;
    calculate(&actual);
    CHECK(actual.doc["status"] == expected.doc["status"]);
    CHECK(actual.valid == expected.valid);
    CHECK(actual.doc["output"]["absolute_humidity"] == doctest::Approx(19.36));
  }
  GIVEN( "input air temp out of bounds for vapor pressure" ) {
    expected.air_temp = 60.1;
    auto actual = expected;
    calculate(&actual);

    REQUIRE(actual.doc["status"] == std::string("warn"));
      THEN("The status should == 'warn'") {
        CHECK(std::string("warn") == actual.doc["status"]);
      }
      AND_THEN("The valid flag should be 'true'") {
        CHECK(true == actual.valid);
      }
      AND_THEN("The message parameter should be defined") {
        CHECK(actual.doc["message"] == msg);
      }
  }
}


