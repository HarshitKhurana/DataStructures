#pragma once

#include "BSTree.h" 

// 1 object of this class represent 1 entire BST.

  // Constructor to create an object of this class with root value of `value`.
  template <typename T>
  BSTree<T> :: BSTree (T value)
  {
    this->value = value;
    this->root = new BTNode<T>(value);
  }

  // Function to insert a value in BST
  template <typename T>
  void BSTree<T> :: insert (BTNode<T> *root , T insValue)
  {
    // if current node is null the directly insert here.
    if (this->root == nullptr)
    {
      BTNode<T> *thisObj = new BTNode<T>(insValue);
      this->root = thisObj;
    }
    else
    {
      // comparer function returns true if first arg is greater than second arg.
      if (comparer(root->getValue(), insValue) )
        insert(root->left , insValue);      // Insert in left subtree
      else
        insert(root->right , insValue);      // Insert in rightsubtree
    }
  }

  // Function to remove a value from BST
  template <typename T>
  void BSTree<T> :: remove (BTNode<T> *root , T delValue)
  {
    // Use little head here , if the delValue is a root then you would need to re-arrange it's children
  }

  // Function to search a value in BST, return true if found else false.
  template <typename T>
  bool BSTree<T> :: search (BTNode<T> *root , T searchValue)
  {
    if (root == nullptr)
      return false;

    else if (root->getValue() == searchValue)
      return true;
    else
    {
      if (comparer(root->getValue(), searchValue) )
        search(root->left , searchValue);      // Insert in left subtree
      else
        search(root->right , searchValue);      // Insert in rightsubtree
    }

  }

  // Function to print The BST , the value of type decides PreOrder , InOrder , Post-Order traversal resp.
  template <typename T>
  void BSTree<T> :: print (BTNode<T> *root , int type)
  {
    // type = 0 -> Pre-Order
    // type = 1 -> In-Order
    // type = 2 -> Post-Order
    if (root == nullptr)
      return;

    if (type == 0)
    {
      cout << " " <<root->getValue();
      print (root->left  , type);
      print (root->right , type);
    }

    else if (type == 1)
    {
      print (root->left  , type);
      cout << " " <<root->getValue();
      print (root->right , type);
    }

    else if (type == 2)
    {
      print (root->left  , type);
      print (root->right , type);
      cout << " " <<root->getValue();
    }

  }

  // comparer function to evaluate which one is larger from x and y, return true if x is greater else returns false.
  template <typename T>
  bool BSTree<T> :: comparer (T x,T y)
  {
    return x>y ? true:false;
  }


