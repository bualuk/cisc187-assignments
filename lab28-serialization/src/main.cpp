//
// A simple cgi program to compute abolute humidity
//
// Example output
// {
//   "input" : {
//     "air_temp": { "value": 20, "uom": "C"}
//   },
//   "output" : {
//     "absolute_humidity": { "value": 0.017293, "uom": "kg/m^3"},
//     "vapor_pressure": { "value": 23.397013, "uom": "hPa"}
//   }
// }
//
//

#include <cstring>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

#include <json.hpp>

#include "cgi.h"
#include "lab28.h"
#include "util.h"

using std::string;
using json = nlohmann::json;

static void usage(const char* name) {
  std::cerr << "Usage: " << name << " [-h|--help] [-v] "
#ifdef HAVE_SETENV
  << " [QUERY_STRING=value]\n";
#else
  << '\n';
#endif
}

[[noreturn]] 
static void help(const char* name) {
  usage(name);
  std::cerr << "Options:\n"
    << "  -h or --help         Show this text and exit\n"
#ifdef HAVE_SETENV
    << "  QUERY_STRING=value   Set the QUERY_STRING in GET request mode.\n\n";
#else
  << "\n";
#endif
  exit(0);
}

// process command line arguments,
// faking a CGI request, if needed.
void process_args(int argc, char** argv) {
  for (int i=1; i < argc; ++i) {
    if (!std::strcmp(argv[i], "-h") || !std::strcmp(argv[i], "--help")) {
      help(argv[0]);
#ifdef HAVE_SETENV
    } else if (std::strncmp(argv[i], "QUERY_STRING", 12) == 0) {
      // for testing, allow setting query string on the command line
      setenv("REQUEST_METHOD", "GET", true);
      std::string qs(argv[i]);
      qs.erase(qs.begin(), qs.begin()+13);
      setenv("QUERY_STRING", qs.c_str(), true);
#endif
    } else {
      std::cerr << "Unknown argument received, " << argv[i] << '\n';
      usage(argv[0]);
      exit(-1);
    }
  }
}

int main(int argc, char** argv) {
  cgi in;

  process_args(argc, argv);
  auto count = int(in.read());
  if (count == 0) {
    return count;
  }

  // We got some kind of GET request.
  // Validate and respond.
  auto response = validate(in.kvp);

  if (response.valid) {
    std::cout << json_header();
    calculate(&response);
  } else {
    std::cout << json_header(StatusCode::bad);
  }
  std::cout << response.doc.dump(2) << std::endl;
  return count;
}

