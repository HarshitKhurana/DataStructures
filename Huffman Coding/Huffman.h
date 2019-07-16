#pragma once

#include "BTNode-Comparison.h"

template <typename T>
class Huffman
{
  public : 
    priority_queue<BTNode<T> , vector<BTNode<T>> , Comparison<T> > pq;


};
