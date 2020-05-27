#ifndef MESA_CISC187_BINARY_SEARCH_TREE_H
#define MESA_CISC187_BINARY_SEARCH_TREE_H

// 
// Binary Search Tree
// Dave Parillo: 20190521
//

#include <iostream>

#include "tree_node.h"

namespace mesa {

  template <typename T>
  struct tree_iterator {
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef ptrdiff_t difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;

    tree_iterator() = default;
    tree_iterator(const tree::tree_node<T>* n) 
      : node{n} 
    { }

    constexpr
      const T& operator*() const noexcept {
      return node->value;
    }

    // move to the next largest value
    tree_iterator& operator++() { 
      if (node == nullptr) return *this;

      if (node->right != nullptr) {
        // find the smallest node on the right subtree
        node = mesa::tree::min_element(node->right);
      } else {
        // finished with right subtree and there is no right
        // search up for first parent with a non-null right child
        // or nullptr,
        auto parent = node->parent;
        while (parent != nullptr && node == parent->right) {
          node = parent;
          parent = parent->parent;
        }
        node = parent;
      }
      return *this; 
    }

    tree_iterator operator++(int) {
      tree_iterator tmp(*this); 
      ++*this; 
      return tmp;
    }

    const tree::tree_node<T>* node;
     };

} // end namespace mesa

// Regular
template <class T>
inline
bool operator==(const mesa::tree_iterator<T>& lhs, const mesa::tree_iterator<T>& rhs) {
  return lhs.node == rhs.node;
}
template <class T>
inline
bool operator!=(const mesa::tree_iterator<T>& lhs, const mesa::tree_iterator<T>& rhs) {
  return !(lhs == rhs);
}




namespace mesa {

  // a binary search tree
  template<class T>
    class bstree {
      public:
        typedef T value_type;
        typedef const tree_iterator<T> const_iterator;
        typedef const_iterator iterator;
        typedef const_iterator reverse_iterator;
        typedef const_iterator const_reverse_iterator;

        bstree() = default;
        explicit
          bstree(const T& value)
          : root{new tree::tree_node<T>{value}}
        { }

        // copy construct and assign
        bstree(const bstree& other) {
          root = mesa::tree::deep_copy(other.root);
        }
        bstree& operator=(const bstree& other) {
          bstree copy = other;
          std::swap(*this, copy);
          return *this;
        }

        // move construct and assign
        bstree(bstree&& other)
          : root{other.root}
        {
          other.root = nullptr;
        }
        bstree& operator=(const bstree&& other) {
          std::swap(root, other.root);
          return *this;
        }

        ~bstree() {
          mesa::tree::erase(root);
        }

        /**
         * Remove all elements from tree.
         */
        void erase() {
        }
        /**
         * Remove one value from a tree.
         */
        void erase (const T& ) {
        }

        constexpr
          bool empty() const noexcept { return root == nullptr; }

        bool contains(const T& value) const noexcept
        {
          return mesa::tree::contains (value, root);
        }

        /**
         * Find a value in tree
         */
        const_iterator find(const T& ) const noexcept {
          return const_iterator(nullptr); // stub
        }

        /**
         * Insert a new value in tree
         */
        const_iterator insert(const T& ) {
          return const_iterator(nullptr); // stub
        }

      private:
        tree::tree_node<T>* root = nullptr;

        /**
         * Insert a new value in the tree.
         * Duplicates are overwritten with the new value.
         */
        tree::tree_node<T>* 
          insert (const T& /* value */, tree::tree_node<T>*& node, tree::tree_node<T>* /* parent */)
          {
              return node;
          }

        // write a tree to an output stream
        friend
          std::ostream& operator<< (std::ostream& os, const bstree& node) {
            return os << node.root;
          }

    };


} // end namespace mesa

#endif


