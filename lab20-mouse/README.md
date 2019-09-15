# Mouse class
Implement some functions in a **very** simple mouse simulation.
The goal is to implement a mouse that can turn and move in a specified direction.

Define all of the types in the `namespace` mesa.
## Steps

### 1. Create files
Create the files `point.h`, `mouse.h`, `mouse.cpp`,
and `main.cpp`.

### 2. Scoped enum
Define a scoped `enum` named `direction` in file `mouse.h`.
It should define the following values:

```
CENTER, LEFT, RIGHT, UP, DOWN
```

The order does not matter, except for `CENTER`, which should be first.
### 3. Default construct point
Define a `struct point` in file `point.h`:

```cpp
struct point {
  int x;
  int y;
};
```

Ensure your `point` has a default constructor.
### 4. Two-arg point constructor
Create a 2 argument constructor to make a point from 2 ints.
Make sure the first argument initializes `point.x`.
### 5. Copy constructor
This test verifies your point is 'copy constructible'.
Depending on how you implemented your point,
this test may pass without your doing anything.

If this test fails,
then create a copy constructor to make a point from another point.
### 6. Point equivalence
Create 2 functions to check if 2 points are equivalent to eachother:

```cpp
inline
bool operator==(const point& lhs, const point& rhs) { . . .

inline
bool operator!=(const point& lhs, const point& rhs) { . . .
```

Define these in `point.h`,
but do **not** put them in the mesa namespace.
### 7. Class mouse
Declare a class `mouse` in file `mouse.h`:
Create private member variables for the mouse name and the mouse position.

The name should be stored in a `std::string` and
the position should be stored in a `mesa::point`.

The default name of your mouse should be 'Alice'.

Add public member functions to retrieve the name and location of a mouse:

```cpp
std::string name ();
point location ();
```
### 8. Mouse constructors
Create a 1 arg mouse constructor,
so that we can create a mouse with a name.

Ensure your mouse also has a default constructor.
### 9. Function `move`
Add a public member function to the `mouse` class to move the mouse:

```cpp
/**
 * Move the mouse a distance in a given direction.
 *
 * @param dir movement direction
 *        Choices are UP, DOWN, LEFT, RIGHT, and CENTER.
 *        CENTER means no movement, even if dir != 0
 *
 *        UP and RIGHT are positive movements in the
 *        y  and x directions respectively.
 *
 * @param distance amount to move
 *        distance < 0 is ok: means move in reverse
 *        distance == 0 means no move
 * @return the new mouse position or
 *         the old position, if no movement occurred
 */
point move (direction dir, int distance);
```

This function should modify the mouse private `location`.
### 10. Function `main`
Create a main that:
- Creates a new mouse object
- Moves it at least once in the 4 cardinal directions

## Turnitin
Check your progress by running `make test` or `ctest -V`.
This will attempt to run all tests.
Check partial progress by running the tests for a single step.
You can run tests for a single step with an IDE or ctest,
for example, `ctest -R step2`.

- Add your new and modified files: `git add . . . `
- Save your changes: `git commit . . . `
- Submit your work for grading: `git push`


