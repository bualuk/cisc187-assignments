#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNAL

#include <map>
#include <string>

#include <doctest.h>
#include <json.hpp>

#include <lab28.h>

SCENARIO( "initialize validate response" ) {

  GIVEN( "Any input (not used)" ) {
    std::map<std::string, std::string> dummy;
    dummy["air_temp"] = 10;
    auto expected = nlohmann::json::object({ {"status","success"} });
    auto actual = validate(dummy);
    THEN("The status should == 'success'") {
      CHECK(expected["status"] == actual.doc["status"]);
    }
    AND_THEN("The valid flag should be 'true'") {
      CHECK(true == actual.valid);
    }
  }

}


