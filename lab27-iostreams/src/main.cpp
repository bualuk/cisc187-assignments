#include <cstring>
#include <iostream>
#include <string>

#include "point.h"

/**
 * Display a usage statement for this program.
 */
static void usage(const char* name);
/**
 * Explain how to use this program
 */
static void help (const char* name);

int main(int argc, char** argv) {
  std::string fin = "mydata.txt";
  std::string fout = "mydata.out";
  for (int i=1; i < argc; ++i) {
    if (!std::strncmp(argv[i], "-h", 2)) {
      help(argv[0]);

    } else if (std::strncmp(argv[i], "-i", 2) == 0) {
      ++i;
      if (i < argc) {
        fin = argv[i];
      } else {
        std::cerr << "Error using '-i' argument: no input name specified\n";
        usage(argv[0]);
      }

    } else if (std::strncmp(argv[i], "-o", 2) == 0) {
      ++i;
      if (i < argc) {
        fout = argv[i];
      } else {
        std::cerr << "Error using '-o' argument: no output name specified\n";
        usage(argv[0]);
      }

    } else {
      std::cerr << "Unknown argument received!\n";
      usage(argv[0]);
    }
  }

  auto original_points = read_points(fin);
  if (!original_points.empty()) {
    std::cout << "\nPoints read in from file:\n"
      << original_points;
    write_points(original_points, fout);
  }

  return 0;
}


static void usage(const char* name) {
  std::cerr << "Usage: " << name << " [-h] [-i input_file] [-o output_file]\n";
}

static void help (const char* name) {
  usage(name);
  std::cerr << R"eot(
Options:
  -h   Show this text\n"
  -i   Input file name.  Default = 'mydata.txt.\n"
  -o   Output file name.  Default = 'mydata.out.\n"

)eot";
  exit(0);
}

