#ifndef MESA_LAB27_POINT_H
#define MESA_LAB27_POINT_H

#include <iosfwd>
#include <string>
#include <vector>

struct point {
  int x;
  int y;
  point(int x = 0, int y = 0)
    : x{x}, y{y}
  {}
};

void write_points(const std::vector<point>& points, const std::string& fname);
std::vector<point> read_points (const std::string& fname);

std::ostream& operator<<(std::ostream& os, const std::vector<point>& p);

#endif

