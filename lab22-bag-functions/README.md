# Bag class functions

The goal of this lab is to contunie creating a user defined
class template that encapulates data storage that can grow
and shrink dynamically.

## Steps

### 1. Copy bag files
Copy your `bag.h` from the previous lab,
or my solution into the `src` directory.

### 2. Function `reserve`
Implement a function that will add extra *capacity* to our bag storage.

```cpp
void reserve(size_t new_capacity);
```
Because our backing store is an array, we just can't make it bigger.
We need to copy the current bag data into a new array and assign 
it to the backing store.

**Note:**

- Do not allow the capacity to be set less than the current capacity
- Do not change the size of the bag
- Do not initialize any of the new memory.
  Why don't we need to do this?
- Do not leak any memory.

### 3. Function `resize`
Implement a function that will add extra *capacity* to our bag storage
**and** initialize any data past the current size.

```cpp
void resize(size_t new_capacity);
```

**Note:**

- Call reserve to do most of your work.
- Don't overwrite any data already in the bag -
  just initialize any new capacity.

### 4. Function `push_back`
Implement a function that will add one element to a bag.

```cpp
void push_back(T value);
```

The `push_back` function will need to check if there is space available
in the backing store for another element.

If there is no space left,
then use `reserve` to double the capacity of the bag.

Keep in mind that a default constructed bag has capacity == 0.

### 5. Function `pop_back`
Implement a function that will remove one element from a bag.

```cpp
void pop_back();
```

### 6. Bag allocator
Our bag class is quite generic, but makes two major assumptions:

- Every type `T` has a default constructor
- `delete[]` will destroy memory in all bag elements when we are done

The standard library provides facilities that help solve both problems.
An *allocator* is an object that can create, manage, and destroy
unitialized storage.

In this last step, we will refctor our bag to add an allocator.

Now would be a **very good time** to commit any work you have completed so far.

Refactoring recipie:

1. Modify the template declaration to include an allocator type:

   ```cpp
   template<class T, class Allocator = std::allocator<T>>
   ```

   We set the default allocator to be one generated from `T`,
   but a caller is free to supply one.
   Everyone else who doesn't need it can ignore it.
1. Add a private member of the template `Allocator` type
1. Replace all instances of `new` and `delete` with `allocate` and `destroy`
   For example:

   ```cpp
   data_ = new T*[size_];
   data_[i] = value;
   delete[] data_;
   ```

   becomes

   ```cpp
   std::allocator_traits<Allocator>::allocate(allocator_, size_);
   
   std::allocator_traits<Allocator>::construct(allocator_, &data_[i], value);

   for (size_t i = 0; i < size_; ++i) {
     std::allocator_traits<Allocator>::destroy(allocator_, &data_[i]);
   }

   ```

Because statements containing `std::allocator_traits<Allocator>::allocate` 
get long quickly, consider aliasing it:

```cpp
using memory = std::allocator_traits<Allocator>;

memory::allocate(allocator_, size_);

memory:construct(allocator_, &data_[i], value);

for (size_t i = 0; i < size_; ++i) {
 memory::destroy(allocator_, &data_[i]);
}

```

When finished, all the tests that passed before the change
should still all pass.

Allocators are a complex part of C++ and they have changed in
C++17 and C++20.
If you don't understand this part of the lab, don't panic.

## Turnitin
Check your progress by running `make test` or `ctest -V`.
This will attempt to run all tests.
Check partial progress by running the tests for a single step.
You can run tests for a single step with an IDE or ctest,
for example, `ctest -R step2`.

- Add your new and modified files: `git add . . . `
- Save your changes: `git commit . . . `
- Submit your work for grading: `git push`


