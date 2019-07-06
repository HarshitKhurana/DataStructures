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
    this->left  = NULL;
    this->value = value;
    this->right = NULL;
  }

  T getValue()
  {
    return this->value;
  }
};

