# Big Integer addition
The goal of today's lab is to practice working with STL algorithms
and to get a start in the capabilities required in 
[Project #3](../project3-postfix-calc).

## Steps

### 1. Create files
Create the files `lab18.h` and `lab18.cpp`.

In the steps that follow, place all code in the `mesa` namespace.

### 2. Function `add`
Write a function that takes two `vector<int>` parameters.

The input vectors should each contain digits in the range 0 - 9.
For example:

```cpp
//     Most significant digit                      least
//               v                                   v
vector<int> x   {0,0,0,0,0,0,0,9,9,0,1,2,3,4,5,6,7,8,9};
vector<int> y                     {9,8,7,6,5,4,3,2,1,9};
```

Your add function should use the `std::transform`
algorithm to add each digit of the two input vectors
and store the results in a new vector.

The result should be: `1000000000008`

You may use `std::plus<int>()` to perform the addition
and then check for carry as a second step, or write a custom lambda.
When the addition is complete, ensure no element in the answer container > 9.

Feel free to write a small main program to help
verify your results.

## Things to be aware of
1. Remember to make sure your destination is large enough to hold
   all your digits, including carry.
2. The `std::transform` algorithm will only push back
   to the destination
   if a `std::back_inserter` is the destination iterator.
3. If the least significant digit is at the 'end' of the vector,
   then push back is very inefficient approach.

   You have two choices:

   a) If using vectors ordered as in the example,
      then ensure your results vector is large enough
      ahead of time to hold all digits 
      and use a reverse iterator to set values as the addition proceeds
      from left to right (least to most significant)
      
   b) Reverse the order of the values in x and y,
      and perform the addition right to left,
      which will now be least to most significant.

   The results can be added to using a `std::back_inserter`
   and the final results reversed again.

If you need a reference for standard library API's, use 
https://www.cppreference.com. 

## Turnitin
Check your progress by running `make test` or `ctest -V`.
This will attempt to run all tests.
Check partial progress by running the tests for a single step.
You can run tests for a single step with an IDE or ctest,
for example, `ctest -R step2`.

- Add your new and modified files: `git add . . . `
- Save your changes: `git commit . . . `
- Submit your work for grading: `git push`


