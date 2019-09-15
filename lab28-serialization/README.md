# JSON Serialization
This exercise is intended to explore object serialization
using JSON.

JSON (JavaScript Object Notation) is a lightweight data-interchange format.
It is easy for humans to read and write.
It is easy for machines to parse and generate.
It is based on a subset of JavaScript Programming Language.
JSON is a text format that is completely language independent 
but uses conventions familiar to programmers of the C-family of languages,
including C, C++, C#, Java, JavaScript, Perl, and Python. 

This lab uses a popular json serialization library
that may become part of the STL one day.
Documentation for the library is here:
https://nlohmann.github.io/json/


## Steps

### 1. Compile project 'as is'
You should be able to build and run this program.
The provided project should produce an executable named `calc`.

Don't worry about running it now, the last step discusses that.

### 2. Function `make_json_pair(string uom, double value)`
Implement a function that creates a `json::object`
with 2 values:
- A value
- A string containing the value units, the 'unit of measure'

The returned JSON should use the parameter names
'uom' and 'value'.
For example:

```json
{
  "uom": "C",
  "value": 20.0
}
```

### 3. Function `validate` initialize
The validate function will be built up in steps.
The first task is to initialize the return value
with a default status.

Although the validate function takes a `map` as input,
this step will ignore it for now.
For this test step, just create a default response.
The default response should set:
- The `valid` to true
- The `doc` object to `{"status" : "success"}`

### 4. Add input air temperature to `validate`
Extend the `validate` function to add the air temperature
passed in the map.

**Game plan:**
- Search for the key `"air_temp"` in the query params map.
- If found, convert the map value to floating point and
  add it the response member variable `air_temp`.
- Add the input air temp and uom to the response doc object.

  You can assume the input air temperature uom is "C".

  Use `make_json_pair` to create the uom and value.

  Add the pair to a nested JSON object.

The final structure should look like this:

```json
"input": {
  "air_temp": {
    "uom": "C",
    "value": 20.0
  }
}
  ```

### 5. Add a validation error message to `validate`
Extend the `validate` function to add error
status if the air temperature key is not found in the map.

**Game plan:**
- Search for the key `"air_temp"` in the query params map.
- If the key is found, add a condition that the value
  must not be empty.
- If not found, update the response doc object:

  - set the "status" to "error"
  - set "message" to "Required input parameter not defined."

### 6. Function `calculate` absolute humidity
Use the passed in response air temperature to calculate 
absolute humidity and add the result to the response doc object.
The uom of the returned absolute humidity is
already defined in the response object by default.

Use `make_json_pair` to create the uom and value.

### 7. Add a warning to `calculate`
Extend the `calculate` function to generate a warning
if the air temperature is out of limits.

If the input air temperature is < -45C or > 60C,
then update the status with a warning message:

- set the "status" to "warn"
- set "message" to 
  "The valid input limits for air temperature are between -45C and 60C"

### 8. Run calculator
If all the previous steps are correct,
the you should be able to run the program on the command line.
The simplest way is:

```
REQUEST_METHOD=GET QUERY_STRING=air_temp=20 src/calc
```

but you can also set `REQUEST_METHOD` and `QUERY_STRING` as
environment variables, if that's easier.

```
REQUEST_METHOD "GET"
QUERY_STRING "air_temp=20"
```

and then just run the program.

These variables are normally set by a web server when running 
the program as a CGI program.

Copying it into a web serbver as a CGI program is possible,
but beyond the scope of this lab.

The output should look something like:

```
Status: 200 OK
Content-type: application/json

{
  "input": {
    "air_temp": {
      "uom": "C",
      "value": 20.0
    }
  },
  "output": {
    "absolute_humidity": {
      "uom": "g/m**3",
      "value": 17.24050321275904
    },
  },
  "status": "success"
}
```

## Try This!
The main program is merely a skeleton that could be extended in many ways.
Some ideas:
- Run it in a web server (IIS, nginx, apache)
  - XAMPP is a simple way to install a demo preconfigured
    apache web server on Windows.
- Add the ability to accept different units:
  - input air temp in deg F
- accept a list of air temperature values and return
  a JSON array of results
- add other calulators

## Turnitin
Check your progress by running `make test` or `ctest -V`.
This will attempt to run all tests.
Check partial progress by running the tests for a single step.
You can run tests for a single step with an IDE or ctest,
for example, `ctest -R step2`.

- Add your new and modified files: `git add . . . `
- Save your changes: `git commit . . . `
- Submit your work for grading: `git push`

