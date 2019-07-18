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
    this->value = value;
    this->left  = nullptr;
    this->right = nullptr;
  }

  int getValue()
  {
    return this->value;
  }
};

