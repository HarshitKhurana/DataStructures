#pragma once

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template <typename T>
class BTNode
{
  public:

  T value;
  BTNode <T> *left;     // Left Child
  BTNode <T> *right;    // Right Child

  BTNode(T value)
  {
    this->left  = nullptr;
    this->value = value;
    this->right = nullptr;
  }

  T getValue()
  {
    return this->value;
  }
};


// Below class is required in order to decide priority based on the value of the nodes
template <typename T>
class Comparison
{
  public:
  bool operator()( BTNode<T> &node1 , BTNode<T> &node2)
  {
    return node1.getValue() < node2.getValue();
  }
};


