# Algorithms
The goal of this lab is to gain more
practice working with STL algorithms.

## Restrictions
- Do not use any STL algorithms in this lab!

## Steps

### 1. Create files
Create the files `lab17.h`, `lab17.cpp`, and `main.cpp`

In the steps that follow, place all code in the `mesa` namespace.

### 2. Template `make_vector`
Write a function that makes a very specific vector:

```cpp
// Return a vector is size sz
// filled with values in the range 1..max,
// increasing sequentially until max is reached.
//
// If max is reached and the vector is not yet filled,
// Then reset continue filling the vector starting at 1.
//
// For example, given:
// sz = 12 and max = 3,
// the returned vector should contain:
// {1,2,3,1,2,3,1,2,3,1,2,3}
std::vector<int>
  mesa::make_vector(const std::size_t& sz,
                    const std::uint16_t& max);
```

You must use one of:
- `std::iota`, 
- `std::generate`, or 
- `std::for_each` to fill the vector.

The idea here is to accomplish the goal of filling the vector 
while minimizing use of hand-rolled loops.

This is not a template, so implement it in `lab17.cpp`.

### 3. Template `expunge_letter`
Write a function template `expunge_letter` that
accepts four parameters:

- two iterators delineating an input range,
- one iterator delineating the start of an output range, 
- and a `char`.

```cpp
template <class InputIt, class OutputIt>
  OutputIt mesa::expunge_letter(InputIt first,
                                InputIt last,
                                OutputIt dest, char c);
```

The template copies the `char`s in the input range that
*do not* contain the specified character to the output range.  
The function should return an iterator one past the 
last location written.
Do not use loops.

(Hint: Use the `remove_copy_if` algorithm and a custom function).

If you need a reference for any standard algorithm API's, use 
https://www.cppreference.com. 


## Try This!
Implement a function `main` that uses the templates implemented in this lab.

Performing this extra step will help you understand how to use
the functions you created in the lab.


## Turnitin
Check your progress by running `make test` or `ctest -V`.
This will attempt to run all tests.
Check partial progress by running the tests for a single step.
You can run tests for a single step with an IDE or ctest,
for example, `ctest -R step2`.

- Add your new and modified files: `git add . . . `
- Save your changes: `git commit . . . `
- Submit your work for grading: `git push`


