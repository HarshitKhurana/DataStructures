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

