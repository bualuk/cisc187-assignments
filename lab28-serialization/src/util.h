#ifndef MESA_LAB28_UTIL_H
#define MESA_LAB28_UTIL_H

#include <map>
#include <string>

// Converts a hex character to its char eqivalent
inline
char from_hex(const char ch) {
  return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
}


// Transform URL encoded characters into plain text.
std::string decode(const std::string& source);

// HTTP response codes
enum class StatusCode { ok = 200, no_content = 204, bad = 400};

// return a json content-type
std::string json_header (StatusCode code = StatusCode::ok);

#endif

