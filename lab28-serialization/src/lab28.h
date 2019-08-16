#ifndef MESA_LAB28_LAB28_H
#define MESA_LAB28_LAB28_H

// Absolute Humidity calculator
//
// Currently computes the absolute humidity of a
// saturated parcel of air (100% relative humidity)
//
// Absolute Humidity is defined as:
// - the mass of water vapor contained in a unit volume of air.
//
// Inputs:
//  - Air temperature (deg C)
//
// Output:
//  - Absolute humidity (g / m**3)
//  - Vapor pressure (hPa - aka millibar)
//


#include <cmath>
#include <map>
#include <string>

#include <json.hpp>

// Response values from the calculator
struct response_t {
  bool valid = false;
  nlohmann::json doc;
  double air_temp = -99.0;     // Celsius
  std::string uom = "g/m**3";  // output unit of measure
  response_t() = default;
  response_t(bool v, nlohmann::json d) 
    : valid{v}, doc{d} 
  {}
  response_t(const response_t&) = default;
  response_t& operator=(const response_t& other) = default;
};

// validate the query string read in by the program
response_t validate (const std::map<std::string, std::string>& query_params);

// build a json object for a specific UOM and value pair
nlohmann::json make_json_pair(const std::string& uom, double value);

// Perform all required calculations and
// modify the response structure with results
void calculate (response_t* response);

// convert Celsius to Kelvin
constexpr double cvt_c_k(double c) { return c + 273.16; }

// convert Kelvin to Celsius
constexpr double cvt_k_c(double k) { return k - 273.16; }

// convert Celsius to Fahrenheit
constexpr double cvt_c_f(double c) { return (9.0 / 5.0) * c + 32.0; }

// convert Fahrenheit to Celsius
constexpr double cvt_f_c(double f) { return (5.0 / 9.0) * (f - 32.0); }

// return vapor pressure over liquid water in hPa
// using air_temp in celsius.
inline double vapor_pres (double air_temp) {
  return 6.112 * std::exp((17.62*air_temp) / (243.12 + air_temp));
}

// compute absolute humidity in g / m**3
// using air_temp in celsius.
inline double abs_humidity (double air_temp) {
  // Specific gas constant for water vapor
  constexpr double R = 461.514;
  return 1e5 * vapor_pres(air_temp) / (R * cvt_c_k(air_temp));
}

#endif

