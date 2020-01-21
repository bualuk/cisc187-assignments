# Simple classes
Design and implement a few simple classes.
The goal is become comfortable writing code in a new style.
That is, encapsulating functions inside classes.

These classes do not need to reside in namespace mesa.

## Steps
Ensure all class data is private and implement the following:

### 1. Create files
Create the files `lab12.h` and `lab12.cpp`.

### 2. Class `Clock`
Define a class `Clock` in file `lab12.h`.
- It should have 1 member to store the time in a `double`.
- Add two functions to the class named `time`.
  One to change and one to retrieve the time.
- Implement the class in `lab12.cpp`.
### 3. Class `Complex`
Define a class `Complex` in file `lab12.h`.
- Add two `double` member variables: 
  one for the real part of the number and one for the imaginary part
- Create a default constructor to initialize the number to (0,0).  
  Use initializer list syntax.
- Create a two argument constructor to initialize the number to
  `(double real, double imaginary)`.
- Add functions to retrieve the complex value components
  (real part and imaginary part).
- Implement the class in `lab12.cpp`.
### 4. Class `Truck`
Define a class `Truck` in file `lab12.h`.
- Define a `uint16_t` member variable to store the number of tires on the vehicle.  
  Create a default constructor to initialize the tires to 6.
- Create a one argument constructor to initialize the tires to a provided value.
- Add a `void` function `pop_tire` that reduces the number of tires by 1.  
  Do not allow this function to reduce the number when the number of tires is already 0.
- Add a `uint16_t` function `tires` that returns the number of tires.
- Implement the class in `lab12.cpp`.
### 5. Class `Dog`
Create a `Dog` class from the following `struct`:

```cpp
  enum class Size {SMALL, MEDIUM, LARGE};

  struct Dog {
    std::string  name;
    Size sz;
  };
```

- Refactor the `struct` into a `class` in 
  file `lab12.h`.  
  Make `name` and `sz` private.
- Add a constructor so that the dog name and  size can be set when a Dog is created.
- Add default values for your Dog class: `"Fido"` and `Size::MEDIUM`.
- Add functions to retrieve name and Size.
- Add a function to change the name of a Dog.
- Add a function `std::string Dog::bark() const` such that:
  - `LARGE` dogs return "Woof"
  - `MEDIUM` dogs return "Ruff"
  - `SMALL` dogs return "Yip"

## Try this!
Consider writing a main that uses these classes.

## Turnitin
Check your progress by running `make test` or `ctest -V`.
This will attempt to run all tests.
Check partial progress by running the tests for a single step.
You can run tests for a single step with an IDE or ctest,
for example, `ctest -R step2`.

- Add your new and modified files: `git add . . . `
- Save your changes: `git commit . . . `
- Submit your work for grading: `git push`


