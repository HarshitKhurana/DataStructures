#pragma once

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template <typename T>
class Node
{
  T value;

  public:

  vector<Node<T> *> children;    // vector of child nodes, on stack only, but it holds the Node objects which are constructed on heap (and thus a pointer in their defn.)

  Node(T value)
  {
    this->value = value;
  }

  T getValue()
  {
    return this->value;
  }
};

