#include "Person.h"
#include <iostream>
#include <memory>


std::ostream& operator<<(std::ostream& os, const Person& rhs) {
  os << rhs.name() << '\t';
  if (rhs.has_child()) os << *(rhs.child()) << ' ';
  return os;
}

