# C/C++ Review
Review the core programming concepts you learned in your first semester of C or C++.

Name: <Your name here>

## Overview
The primary objective of this first lab is to review
programming concepts from your first semester and
to begin working with unit tests.

## Making Change: 2.5 points, 30 minutes *maximum*
1. In your own words, without simply rewriting the code as plain text,
describe what [this function](src/change.cpp) is attempting to do:




2. Work through the logic manually (without compiling). 

Write down the expected output.




3. Compile and run the `test_change` program on buffy.
   Record the output.




4. Did the actual output match your expectations?

What is the key programming 'lesson learned' here?




5. Fix the code in `change.h` and `change.cpp` so that it passes the tests.


## Code reading: 1 point, 30 minutes *maximum*
For each of the problems that follow,
describe the intended program output, if any, and
whether the program compiles or not.

If it doesn't compile or produces unintended output,
what changes could be made to fix it?

**Reading #1**

```cpp
#include <iostream>
#include <string>

int main () {
  const std::string dudes[4] = {"paco", "fred", "connor", "shoney"};
  for (int i = 0; i <= 4; ++i) {
    std::cout << dudes[i] << std::endl;
  }
  return 0;
}
```
What is the problem (if any)?

Fixed code:




**Reading #2**

```cpp
#include <iostream>

int main () {
  double x;
  double y = x;
  double z = 2.0 + x;

  std::cout << y << " and " << z << ".\n";
  return 0;
}
```
What is the problem (if any)?

Fixed code:




**Reading #3**

```cpp
#include <iostream>
#include <string>

int main () {
  for (int i = 0; i < 9; ++i) {
    int x = 5;
    std::string pet = "Dog - ";
    if (i < 3) {
      ++x;
    } else {
      x += 2;
    }
  }
  std::cout << pet << x << '\n';
}

```
What is the problem (if any)?

Fixed code:




**Reading #4**

```cpp
#include <iostream>
#include <string>

int main () {
  int sa[4][3] = {{1,2,3,4}, {5,6,7}};

  std::cout << "first: " << sa[0][0] << '\n';
  std::cout << "last:  " << sa[4][3] << '\n'; 
}

```
What is the problem (if any)?

Fixed code:



## Expressions: 0.5 points, 30 minutes
For each expression below, indicate if it compiles.
If yes, what is the result?
If no, what's wrong?

a.  
```cpp
double x = 5 + 1/2;
```


b.  
```cpp
double x = 5 + 1/2.0;
```


c.  
```cpp
int y = 5 + 1/2.0;
```


d.  
```cpp
double x = 5 + (float)2/3.0;
```


e.  
```cpp
double x = 5 + 2^3;
```


f.  
```cpp
double x = (int) 5.0 << 1;
```


g.  
```cpp
bool z = false;
double x = 4 | (int)(!z);
```

## Turnitin
Check your progress by running `make test` or `ctest -V`.

- Add your new and modified source files: 
  ```
  git add src
  git add README.md
  ```
- Save your changes: `git commit -m 'finished lab2'`
- Submit your work for grading: `git push`


