# Functions and pointers
This exercise is intended to build your understanding of
using pointers with functions and
introduces passing functions as arguments to functions.

## Steps

### 1. Create files
Create the file `lab11.h`, `lab11.cpp`, and `main.cpp`

### 2. Function `count_if`
Write a function template:

```cpp
template <class DataPointer, class Predicate>
size_t mesa::count_if(DataPointer begin,
                      DataPointer end, Predicate p);
```

The `mesa::count_if` should return
the number of occurrences of items between `begin` and `end`
that satisfy the predicate function `p`.

Do not include `end` values in the count.

A `predicate` is a function that takes a single parameter
and returns a `bool`.

### 3. Function `is_odd`
Write the predicate 

````cpp 
constexpr bool mesa::is_odd(long value)
```

that returns `true`
if `value` is odd.

### 4. Function `greater`
Write a binary function template 

```cpp
constexpr bool mesa::greater(T a, U b)
```

that returns `true`
if `a` is greater than `b`.

A *binary function* is a function that takes two parameters
and returns a value.
It need not return a `bool`.
The common arithmetic functions 
(addition, multiplication, equivalence operations, etc.)
are all binary functions.

### 5. Function `main`
Create a program in `main.cpp` that uses all the functions
from the previous steps in this lab.

To use `mesa::greater`, call `std::sort`.

`std::sort` takes two data pointers and a binary function.

## Turnitin
Check your progress by running `make test` or `ctest -V`.
This will attempt to run all tests.
Check partial progress by running the tests for a single step.
You can run tests for a single step with an IDE or ctest,
for example, `ctest -R step2`.

- Add your new and modified files: `git add . . . `
- Save your changes: `git commit . . . `
- Submit your work for grading: `git push`


