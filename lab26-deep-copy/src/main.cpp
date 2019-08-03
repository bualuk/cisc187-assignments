#include "Person.h"

#include <iostream>
#include <memory>

using std::shared_ptr;
using std::cout;

// Given 2 Persons that are copies of each other
// change one of them and print both
// only the changed person should be different
void change_and_compare(Person&, Person&);

// Copy a Person using the copy constructor
void copy_construct(Person&);

// Copy a Person using copy assignment
void copy_assign(Person&);

int main () 
{
  // Deep copy scenario #1
  // create objects a,b,c
  Person a {"Alice"};
  shared_ptr<Person> b (new Person{"Bob"});
  auto c = std::make_shared<Person>("Carol");

  (*b).child(c);
  a.child(b);

  cout << "Copy constructor test: \n";
  cout << "Original: \t";
  cout << a << '\t';
  copy_construct(a);

  // Deep copy scenario #2
  // create objects d,e,f
  Person d {"Dan"};
  auto e = std::make_shared<Person>("Edith");
  auto f = std::make_shared<Person>("Fred");

  e->child(f);
  d.child(e);

  cout << "\nCopy assignment test: \n";
  cout << "Original: \t";
  cout << d << '\t';
  copy_assign(d);

  cout << std::endl;
  return 0;
}

void copy_assign(Person& x)
{
  Person xcopy;
  xcopy = x;
  change_and_compare(x, xcopy);
}

void copy_construct(Person& x)
{
  Person xcopy(x);
  change_and_compare(x, xcopy);
}

void change_and_compare(Person& x, Person& y)
{
  cout << "Copy: \t";
  cout << y << std::endl;

  cout << "changing only the 'copy' objects: \n";
  y.name("111");
  y.child()->name("222");
  y.child()->child()->name("333");
  cout << "Original: \t";
  cout << x << '\t';
  cout << "Copy: \t";
  cout << y << std::endl;
}


