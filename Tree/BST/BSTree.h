#pragma once

#include "BSTree.h" 

// 1 object of this class represent 1 entire BST.

class BSTree : public BTNode {

  public:

  // Constructor to create an object of this class with root value of `value`.
  BSTree (T value);

  // Function to insert a value in BST
  void insert (BTNode<T> *root , T insValue);

  // Function to remove a value from BST
  void remove (BTNode<T> *root , T delValue);

  // Function to search a value in BST, return true if found else false.
  bool  search (BTNode<T> *root , T searchValue);

  // Function to print The BST , the value of type decides PreOrder , InOrder , Post-Order traversal resp.
  void print (BTNode<T> *root , int type);
  
  // comparer function to evaluate which one is larger from x and y, return true if x is greater else returns false.
  bool  comparer (T x,T y);

};
