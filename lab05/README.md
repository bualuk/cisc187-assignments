# Functions
The purpose of this lab is to practice working with
function parameters and namespaces.


## Pass by reference and pass by value: 2 points, 30 minutes *maximum*
This exercise is taken from
*Programming: Principles and Practice Using C++*.
Addison-Wesley Professional, 2nd edition,
June 2014. ISBN: 978-0321992789.

Given 3 functions:

```cpp
 void swap_v (int a, int b);
 void swap_r (int& a, int& b);
 void swap_cr(const int& a, const int& b);
```

And given that each function has the same body:

```cpp
   {
      int temp;
      temp = a;
      a = b;
      b = temp;
   }
```

This is a simple form of the *copy and swap idiom*.

Without compiling, 
determine the output of these functions and complete the table.
Not all of the examples in the table below will compile.
Which of these calls compile?
Provide an explanation for each function call that does not compile.

Given the following definitions of `x` and `y` when passed to `swap`:

```cpp
int x = 7;
int y = 9;
```

| Definitions and Function Call | Compiles (Y/N) | Explanation |
| ---                           | ---            | ---         |
| `swap_v(x,y);`                |                |                   |
| `swap_r(x,y);`                |                |                   |
| `swap_cr(x,y);`               |                |                   |

And when the following literals are passed to `swap`:

| Definitions and Function Call | Compiles (Y/N) | Explanation       |
| ---                           | ---            | ---               |
`swap_v(3,5);`                  |                |                   |
`swap_r(3,5);`                  |                |                   |

Given the following definitions of `cx` and `cy` when passed to `swap`:

```cpp
const int cx = 7;
const int cy = 9;
```

| Definitions and Function Call | Compiles (Y/N) | Explanation       |
| ---                            | ---           | ---               |
| `swap_v(cx,cy);`               |               |                   |
| `swap_r(cx,cy);`               |               |                   |

And when the following literals are passed to `swap`:

| Definitions and Function Call | Compiles (Y/N) | Explanation           |
| ---                               | ---            | ---               |
| `swap_v(3.5,8.13);`               |                |                   |
| `swap_r(3.5,8.13);`               |                |                   |

Given the following definitions of `dx` and `dy` when passed to `swap`:

```cpp
double dx = 3.5;
double dy = 8.13;
```

| Definitions and Function Call | Compiles (Y/N) | Explanation       |
| ---                           | ---            | ---               |
| `swap_v(dx,dy);`              |                |                   |
| `swap_r(dx,dy);`              |                |                   |


## Debugging: 2 points, 30 minutes
Examine the program provided in the src folder.

What is the expected output? Record your answer here.


Now compile and run the program `src/lab5`.
What is the actual output?


What is wrong with this program?  What changes need to be made to fix it?

Make your changes, make sure the program compiles and runs.
When complete, the program should print:

```
original values:
a: 10, b: 20
after swap and add:
a: 21, b: 11
```

when running with default arguments.

## Turnitin

- Add your new and modified files: `git add . . .`
- Save your changes: `git commit . . .`
- Submit your work for grading: `git push`


