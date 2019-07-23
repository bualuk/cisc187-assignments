# Exploring Iterators
The goal of this lab is to gain more
practice working with iterator operations.

## Restrictions
- Do not use any STL algorithms in this lab!

## Steps

### 1. Create files
Create the files `lab16.h` and `main.cpp`

In the steps that follow, place all code in the `mesa` namespace.

### 2. Template `fill_n`
Write a function template that appends values.

```cpp
// Add the given value to the first 'count' elements
// in the range beginning at first, if count > 0.
//
// If count == 0, then do nothing\m[]
template<class OutputIterator, class T>
  void fill_n(OutputIterator first,
              const std::size_t count,
              const T& value);
```

### 3. Template `append_n`
Write a function template that appends count copies of
a value to a container.  
Use this signature:

```cpp
template<class Container, class T>
  void append_n(Container* c,
                const std::size_t count,
                const T& value);
```

Note that the first parameter is a (non-owning) pointer to the container.

This function should call `mesa::fill_n` and use
`std::back_inserter` to append values.

### 4. Template `copy_if`
Write a function template that copies values 
from a range to a destination range,
if a condition is met.  
Use this signature:

```cpp
template<class InputIterator,
         class OutputIterator, class Predicate>
  void copy_if(InputIterator first,
               InputIterator last,
               OutputIterator dest,
               Predicate p);
```

The predicate function should evaluate the current input
iterator value and return a `bool`.

### 5. Function `print_if`
Write a function that copies vector elements to `std::cout`
if the container elements meet a condition.  
Use this signature:

```cpp
inline 
void print_if(std::vector<int> source,
              std::function<bool(int)> p);
```

This function should call `mesa::copy_if` and use
`std::ostream_iterator<int>` as the destination.

Make the function `inline` and implement it in the lab header.

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


