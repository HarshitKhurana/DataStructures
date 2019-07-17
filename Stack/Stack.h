
#include<iostream>
#include<climits>
#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Stack
{
  vector<T> *v;
  int size;       // Current size
  int capacity;   // Max capacity

  public:
    Stack();                // Create vector on heap here

    T top();                // Return top element of Stack   : O(1)

    void pop();             // Pop Top 'element' from Stack   : O(1)

    bool isEmpty();         // Returns true if empty  : O(1)

    int size();             // Return Size of stack : O(1)

    void push(T element);   // Push 'element' into Stack  : O(1)

};
