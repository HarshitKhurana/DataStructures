#pragma once

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// The value stored in Nodes will be int only.

class BTNode
{
  public:

  int value;
  BTNode *left;     // Left Child
  BTNode *right;    // Right Child

  BTNode(int value)
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

