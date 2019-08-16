
#include <iostream>
#include <map>
#include <string>

#include <json.hpp>
#include "lab28.h"

using std::string;
using json = nlohmann::json;
using kvp_map = std::map<std::string, std::string>;

// step 2: wrap a uom / value pair in a json object
json make_json_pair(const string& uom, double value) {
  return {};
}

response_t validate (const kvp_map& query_params) {

  // step 3: create a default response status
  response_t response;

  // step 4: add input air_temp to response

  // step 5: add a validation error to response

  return response;
}

void calculate (response_t* response) {

  // step 6: calculate absolute humidity

  // step 7: add a warning message to response

}


