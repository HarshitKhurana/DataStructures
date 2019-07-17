
#include<iostream>
#include<climits>
#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Queue
{
  vector<T> *v;
  int size;       // Current size
  int capacity;   // Max capacity

  public:
    Queue();                // Create vector on heap here

    T top();                // Return top element of Queue   : O(1)

    void pop();             // Pop Top 'element' from Queue   : O(1)

    bool isEmpty();         // Returns true if empty  : O(1)

    int size();             // Return Size of stack : O(1)

    void push(T element);   // Push 'element' into Queue  : O(1)

};
