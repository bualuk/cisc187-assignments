#ifndef MESA_CISC187_TREE_NODE_H
#define MESA_CISC187_TREE_NODE_H

// 
// A single node for a binary search tree
// Dave Parillo: 20190521
//

#include <iostream>

namespace mesa {
  namespace tree {

    // a binary tree node
    template<class T>
      struct tree_node {
        T value;
        tree_node<T>* left;
        tree_node<T>* right;
        tree_node<T>* parent; // link to parent simplifies iterators
        tree_node(const T& value = T{}, 
            tree_node<T>* left = nullptr,
            tree_node<T>* right = nullptr,
            tree_node<T>* parent = nullptr)
          : value{value}
        , left{left}
        , right{right}
        , parent{parent}
        { }
      };


    /**
     * Determine if a value is currently in the tree.
     *
     * The tree must satisfy the binary search property.
     *
     * @return true if the value is found
     * @return false otherwise
     */
    template <class T>
      bool contains (const T& value, tree_node<T>* root)
      {
        if(root == nullptr) return false;
        if(value < root->value) {
          return contains(value, root->left);
        } else if(root->value < value) {
          return contains(value, root->right);
        }
        return true; 
      }

    /**
     * Copy en entire tree.
     *
     * @return a new subtree that is a copy of 'root'
     */
    template <class T>
      tree_node<T>* deep_copy(tree_node<T>* root)
      {
        if (root == nullptr) return root;
        return new tree_node<T>(
            root->value,
            deep_copy(root->left),
            deep_copy(root->right),
            root->parent
            );
      }

    /**
     * Delete an entire tree.
     */
    template <class T>
      void erase(tree_node<T>*& )
      {
      }

    /**
     * Remove a value from a tree if it exists.
     * Duplicates are overwritten with the new value.
     */
    template <class T>
      void erase (const T& , tree_node<T>*& )
      {
      }

    /**
     * Find a pointer to the tree_node containing a value.
     *
     * The tree must satisfy the binary search property.
     *
     * @return a pointer to the node, if found
     * @return nullptr otherwise
     */
    template <class T>
      tree_node<T>* find (const T& , tree_node<T>* root)
      {
        return root; 
      }

    /**
     * Find the smallest item in a subtree.
     *
     * The tree must satisfy the binary search property.
     *
     * @return the smallest item.
     *         or the nullptr for empty trees.
     */
    template <class T>
      tree_node<T>* min_element(tree_node<T>* root )
      {
        return root;
      }


    /**
     * Find the largest item in a subtree.
     *
     * The tree must satisfy the binary search property.
     *
     * @return the largest item.
     *         or the nullptr for empty trees.
     */
    template <class T>
      tree_node<T>* max_element(tree_node<T>* root )
      {
        return root;
      }


  } // end namespace tree
} // end namespace mesa

// write a tree to an output stream, infix
  template <class T>
std::ostream& operator<< (std::ostream& os, const mesa::tree::tree_node<T>* node)
{
  if (node == nullptr) return os;
  os << node->left; 
  os << node->value << ' ';
  os << node->right;
  return os;
}

#endif


