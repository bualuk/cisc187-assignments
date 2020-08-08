# Class inheritance


## 1. Base and derived classes: 30 minutes *maximum*
### Part a.
Given the following classes:    
```cpp
  class Animal {
    public:
    virtual void make_noise() {}
    void eat() {}
    void sleep() {}
    void roam() {}
  };

  class Canine : public Animal {
    public:
    void roam() {}
    void eat() {}
  };


  class Wolf : public Canine {
    public:
    void make_noise() {}
    void eat() {}

  };
```

And given:    
```cpp
  void call (Animal& a) {
    a.make_noise();
    a.roam();
    a.eat();
    a.sleep();
  }

  int main () {
    Wolf w;
    call(w);
  }
```

Identify which of the versions of the methods called by `Wolf w` are invoked.

### Part b.
Given the following classes:

```
Musician
RockStar
MusicFan
BassPlayer
ConcertPianist
```

- Identify appropriate derived classes and base classes.

- Draw an inheritance diagram that makes sense.  
  Not everything needs to be connected to something else.

  Don't over engineer this diagram.
  Simple ASCII art like:

  ```
   BassClass <|-- DerivedClass // inheritance
   Car  *-- Engine             // composition
  ```

  is sufficient.

### Part c.
Given the following classes:

```
  Bathtub     Bathroom     Bubbles     Sink
```

- Identify appropriate derived classes and base classes.

- Draw an inheritance diagram that makes sense.  
  Not everything needs to be connected to something else.

## 2. Inheritance Declarations
Identify the relationships that make sense.

If a relationship doesn't make sense, explain why.

```cpp
struct Base : Derived       // no. Relationship is backwards.
  
struct Oven : Kitchen       

struct Guitar : Instrument  

struct Person : Employee    
  
struct Ferrari : Engine     

struct FriedEgg : Food      

struct Beagle : Pet        

struct Porch : House       

struct Metal : Titanium    

struct GratefulDead : Band  
```


## 3. Abstract classes: 30 minutes *maximum*
Given the following classes and a main method that uses them:

```cpp
  class Car {
    public:
    // insert A here
  };

  class RaceCar : public Car {
    public:
    // insert B here
  };

  class ElectricCar : public Car {
    public:
    bool accelerate(int change) const override {
      std::cout << "Shhhh...  " << change << std::endl;
      return true;
    }
  };

  int main () {
    vector<Car*> cars(3);
    cars[0] = new RaceCar();
    cars[1] = new ElectricCar();
    cars[2] = new Car();

    for (int x = 0; x < cars.size(); x++) {
      cars[x]->accelerate(x);
    }
    return 0;
  }
```

Examine each of the 4 pairs of code that follow and
describe what would happen when inserted at locations "A" and "B".
For **each pair**, answer **all** of the following:

- Which do not compile? 
- Which compile and produce the following output?

  ```
  Vroom! 0 
  Shhhh... 1 
  Change is: 2
  ```

- For those that compile,
  but do not produce the output above, explain why they do not.

### Pair #1:
**A:**  
```cpp
bool accelerate(int change) const {
  std::cout << "Change is: " << change << std::endl;
  return true;
}
```

**B:**  
```cpp
  bool accelerate(int change) const {
    std::cout << "Vroom!  " << change << std::endl;
    return false;
  }
```

### Pair #2:
**A:**  
```cpp
virtual bool accelerate(int change) const {
  std::cout << "Change is: " << change << std::endl;
  return true;
}
```

**B:**  
```cpp
bool accelerate(int change) const {
  std::cout << "Vroom!  " << change << std::endl;
  return false;
}
```

### Pair #3:
**A:**  
```cpp
virtual bool accelerate(int change) const {
  std::cout << "Change is: " << change << std::endl;
  return true;
}
```

**B:**  
```cpp
bool accelerate(long change) const {
  std::cout << "Vroom!  " << change << std::endl;
  return false;
}
```

### Pair #4:
**A:**  
```cpp
virtual bool accelerate(int change) const {
  std::cout << "Change is: " << change << std::endl;
  return true;
}
```

**B:**  
```cpp
bool accelerate(long change) const override {
  std::cout << "Vroom!  " << change << std::endl;
  return false;
}
```

## Turnitin
- Add your new and modified files: `git add . . . `
- Save your changes: `git commit . . . `
- Submit your work for grading: `git push`

## Reflection
When you are done, take a moment to 
[rate this lab](https://forms.gle/hpzthryE5MiwjLss9).
