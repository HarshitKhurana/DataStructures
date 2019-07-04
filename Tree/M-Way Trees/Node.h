#pragma once

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template <typename T>
class Node
{
  T value;

  public:

  vector<Node<T>> *children;    // vector of child nodes

  Node(T value)
  {
    this->value = value;
    children = NULL;                // Initiialise with NULL
  }

  // returns vector object.
  vector<Node<T>> getChildren()
  {
    return this->children;
  }

  T getValue()
  {
    return this->value;
  }
};

