# Lambda expressions
This exercise is intended to build your understanding of
lambda expressions and refactoring existing code.

The main objective is to replace 
the rotation functions in the week 6 cipher example
with lambda expressions.


## Steps

### 1. Remove the `using transform` line.
Delete the line containing `using transform`.

We won't be using this alias.

### 2. Function `render_text`
Modify the signature of `render_text` replacing the deleted
transform with an equivalent `std::function`.

Recall that `std::transform` takes both the return value and
parameter types as template arguments. 

### 3. Functions `rot13` and `rot47`
Rewrite the `rot13` and `rot47` functions as lambda expressions.

Keep in mind these lambda expressions will not automatically 
deduce the correct return type,
so your lambdas must explicitly define the return type.

## Turnitin
Check your progress by using the executable.
Run your program and ensure it enciphers / deciphers text exactly as 
before modification.

Run as:

```
echo "Hello, World!" | ./lab12
```

or

```
echo "Hello, World!" | ./lab12 -f

for example.


- Add your new and modified files: `git add . . . `
- Save your changes: `git commit . . . `
- Submit your work for grading: `git push`


