#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNAL

#include <map>

#include <doctest.h>
#include <json.hpp>

#include <lab28.h>

SCENARIO( "make a json pair: value and uom" ) {

  GIVEN( "A a value and a unit of measure" ) {
    auto expected = nlohmann::json::object({ {"uom","C"},{"value",10} });
    auto actual = make_json_pair("C", 10);
    THEN("A JSON object should be returned") {
      CHECK(expected["uom"] == actual["uom"]);
      CHECK(expected["value"] == actual["value"]);
    }
  }

  GIVEN( "A a value and a unit of measure" ) {
    auto expected = nlohmann::json::object({ {"uom","K"},{"value",280} });
    auto actual = make_json_pair("K", 280);
    THEN("A JSON object should be returned") {
      CHECK(expected["uom"] == actual["uom"]);
      CHECK(expected["value"] == actual["value"]);
    }
  }

  GIVEN( "A a value and a unit of measure" ) {
    auto expected = nlohmann::json::object({ {"uom","g/m**3"},{"value",17.12345} });
    auto actual = make_json_pair("g/m**3", 17.12345);
    THEN("A JSON object should be returned") {
      CHECK(expected["uom"] == actual["uom"]);
      CHECK(expected["value"] == actual["value"]);
    }
  }

}


