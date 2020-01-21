#ifndef MESA_LAB11_LIST_H
#define MESA_LAB11_LIST_H

#include <iosfwd>

// A simple linked list
struct list {
    int value = 0; 
    list* next = nullptr;

    explicit list(const int value = 0)
        : value{value} 
    { }

    // 
    // Insert a new value before the current element.
    // 
    list* insert(int);
};

// remove this element from list
// Return a pointer to the next element
list* erase(list*);

std::ostream& operator<<(std::ostream&, const list*);


#endif

