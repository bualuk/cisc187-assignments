# Maps
This exercise is intended to build your understanding of
associative containers.

The goal of this lab is to compute and display the 
frequency of words encountered in a word list.
Both case sensitive and case insensitive frequencies will be generated.

In the steps that follow,
unless otherwise noted, place all code in the `mesa` namespace.

## Steps

### 1. Create files
Create the file `lab14.h`, `lab14.cpp`, and `main.cpp`

### 2. Function `to_lower`
Create a function `to_lower` that converts a string to all lower case characters.

```cpp
std::string to_lower(const std::string&);
```

**Bonus:**  do this without using any raw loops.

### 3. Stream extraction overload
Create an overload for function `operator<<` that streams a word list
to a provided output stream.

```cpp
std::ostream&
  operator<<(std::ostream&, const std::map<string, size_t>&);
```

Do **not** put the `operator<<` function in the  `mesa` namespace.


### 4. Function `frequency_table`
Create a function `frequency_table` with the following characteristics:


- It should take 2 parameters 

  - a word list: a `vector<string>` of words and
  - a function that performs some operation on each word in the list.

    ```cpp
    std::map<std::string, size_t>
      frequency_table(const std::vector<std::string>&,
                      std::function<std::string (const std::string&)>);
    ```

- Create a new empty frequency table: a `map<string, size_t>`.
- Loop on each word in the `vector` and use the function to make a
frequency table entry.
- Each time a value is added or modified in the frequency table,
update the word count in the map.

  Recall map keys are unique.
  Duplicate keys are silently replaced with new values.
- Return the new map.

The test cases call the `frequency_table` function, providing
`to_lower` as the function parameter.

The remaining steps are optional extra practice.

### 5. Function `main`
Create a function in `main.cpp` called `print_common` that takes
two parameters:
- a `map<string, size_t>` and
- a minimum frequency.

It should print all elements in the map where
the word frequency is greater than or equal to the frequency provided.

In `main.cpp` create a program that uses your functions from the previous steps.

a. Define a
`vector<string>` of words.  You may use this data:

```
"bake", "foo", "Alice", "Bob", "darla", "MAP",
"make", "alice", "Darla", "bat", "SET",
"set", "FOO", "AlicE", "bob", "BAT", "map"
```

b. Make a word list map from the vector and print it.

   Call the function `frequency_table` with the word list and 
   a function that simply returns whatever string is provided.  
   (Yes, this function does nothing).

c. Make a lowercase version of the word list map and print it.

   Call the function `frequency_table` with the word list and 
   a function that converts a string to lower case.

d. Print all the 'common' lowercase words.

   Call `print_common` with the lower case map and a minimum frequency of 2.

   When complete, your output should resemble the following:

   ```
   word frequencies:
   AlicE   1    Alice  1    Bob    1
   Darla   1    FOO    1    alice  1
   bait    1    bake   1    bat    1
   bob     1    darla  1    foo    1
   make    1    map    1    maps   1
   seat    1    set    1

   case insensitive frequencies:
   alice   3    bait   1    bake   1
   bat     1    bob    2    darla  2
   foo     2    make   1    map    1
   maps    1    seat   1    set    1

   common words:
   alice   3
   bob     2
   darla   2
   foo     2
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


