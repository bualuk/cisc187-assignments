#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

#include "average.h"
#include "student.h"

void add_student(std::vector<student*>* students, std::istringstream& iss) {
  // Your code here. 
  // Implement a function to add one student and their grades from the input stream to the vector
}

std::vector<student*> load_classroom() {
  std::string line;
  // Your code here. Init a new classroom
  while (getline(std::cin, line)) {
    std::istringstream stream(line);
    // Your code here. add students to the classroom

    line.clear();
  }
  // Your code here. Return your classroom
}

std::ostream& operator<< (std::ostream& os, const std::vector<student*>& rhs) {
  // Your code here. Implement a function to print all students
}

std::ostream& operator<< (std::ostream& os, const student* rhs) {
  // Your code here. Implement a function to print one student
}


