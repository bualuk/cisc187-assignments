#ifndef MESA_PROJECT2_TREE_H
#define MESA_PROJECT2_TREE_H

// 
// Tree manipulation functions
//

#include <iostream>
#include <string>

namespace mesa {

  // a recursive binary tree
  template<class T>
    struct tree {
      T value;
      tree<T>* left = nullptr;
      tree<T>* right = nullptr;
    };


} // end namespace mesa

#endif

