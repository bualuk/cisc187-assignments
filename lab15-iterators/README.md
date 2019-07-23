# Iterators
The goal of this lab is to 
practice working with basic iterator operations.

## Restrictions
- Do not use any STL algorithms in this lab!

**Things to notice**

1. You will need to use the iterator position returned from
   STL container `insert` and `erase` functions.

   Calling `insert` and `erase` invalidates the current iterator and
   often all forward iterators.
2. The STL container `insert` functions all insert new elements **before**
   the current iterator position.

   This means the 'current iterator' position is *before* 
   the position used before insert was called.

Think about what you will need to do to avoid an infinite loop.

## Steps

### 1. Create files
Create the files `lab15.h` and `main.cpp`.

In the steps that follow, place all code in the `mesa` namespace
unless otherwise noted.

### 2. Template `fill_sequence`
Write a function template that fills a range with increasing values.

```cpp
// Fill the range [first, last) with sequentially
// increasing values,
// starting with value and repetitively evaluating ++value.
template<class ForwardIterator, class T>
  void fill_sequence(ForwardIterator first,
                     ForwardIterator last, T value);
```

### 3. Template `fill`
Write a function template that fills a container using a starting value.  
Use this signature:

```cpp
template<class Container, class T>
  void fill(Container* c, const T value);
```

Note that the first parameter is a (non-owning) pointer to the container.

This function should call `fill_sequence` to fill
the entire container with values.

### 4. Template `equal_to`
Write a function template that inserts a value into a container,
each time a condition is met.  
Use this signature:

```cpp
template<class Container, class T, class Predicate>
  void insert_each_if(Container* c,
                      const T value,
                      Predicate p);
```

This function should loop on each element in the container,
pass the current iterator value to the predicate,
and insert the value **only** if the predicate returns `true`.

The predicate function should evaluate the current iterator value and
return a `bool`.

### 5. Template `erase_if`
Write a function template that erases all values from a container,
**each time** a condition is met.  
Use this signature:

```cpp
template<class Container, class Predicate>
  void erase_if(Container* c, Predicate p);
```

This function should loop on each element in the container,
pass the current iterator value to the predicate,
and erase the element **only** if the predicate returns `true`.

The predicate function should evaluate the current iterator value and
return a `bool`.

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


