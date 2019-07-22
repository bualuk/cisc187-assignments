# Stacks
The goal of this lab is to gain familiarity with the
`std::stack` class and
to understand some limitations of a stack.

## Restrictions
- Do not use any STL algorithms in this lab!
- In `reverse()`,
  use 1 or more sequential containers to perform the reverse operation.

**Things to notice**

1. Each of the function signatures provide `const` references
   to a stack, so your implementation must copy the provided parameter.
2. A `std::stack` is not *iterable*.  
   You can't use a range for loop or define an iterator.
3. Make a temporary local copy of the provided stack and operate on that
   you will end up destroying the temp copy in each function.

## Steps

### 1. Create files
Create the file `src/lab13.h`

In the steps that follow, place all code in the `mesa` namespace.

### 2. Template `contains`
Write a function template that determines if a \*[c]std::stack\*[r]
contains a user provided value:

```cpp
/**
 * Determine if a stack contains a provided value.
 *
 * @param val in the stack to search for.
 * @param s stack being searched
 * @return true if value exists in the stack.
 */
template <class T>
  bool contains (const T& value, const std::stack<T>& s);
```

### 3. Template `reverse`
Write a function template that reverses a `std::stack`:

```cpp
/**
 * Reverse the order of elements in a stack.
 * @return A new stack with its elements in reverse order.
 */
template <class T>
  std::stack<T> reverse(const std::stack<T>& s);
```

### 4. Template `equal_to`
Write a function template that compares two stacks:

```cpp
/**
 * Compare two stacks.
 * @return true if each element of both stacks
 *              passes the operator== test.
 * @return false otherwise
 */
template <class T>
  bool equal_to(const std::stack<T>& a,
                const std::stack<T>& b);
```


## Turnitin
Check your progress by running `make test` or `ctest -V`.
This will attempt to run all tests.
Check partial progress by running the tests for a single step.
You can run tests for a single step with an IDE or ctest,
for example, `ctest -R step2`.

- Add your new and modified files: `git add . . . `
- Save your changes: `git commit . . . `
- Submit your work for grading: `git push`


