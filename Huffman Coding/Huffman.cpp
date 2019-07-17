#pragma once

# define print(x,y) cout <<x<<"\t"<<y

#include "Huffman.h"

  Huffman :: Huffman()  // Make the hashmaps and priorityQ here.
  {
    pq = new priority_queue<BTNode , vector<BTNode> , Comparison>();
    forwardLookup = new unordered_map<string , int>();
    reverseLookup = new unordered_map<int , string>();
  }

  // Return false if already exists i.e unable to insert.
  bool insert(string key , int value)  // Insert the Nodes here into the priority_queue well as both the hashmaps.
  {
    if (forwardLookup->count(key))
      return false;   // Already exists

    forwardLookup[key] = value;     
    reverseLookup[value] = key;     
    BTNode *node = new BTNode(value);   // Don't forget to delete this node in remove function from priority Q as well as both the hashmaps.
    return true;
  }

  void remove()  // Remove the Nodes from priority_queue as well as both the hashmaps.
  { 
    // Fetch the top element from pQeueue delete it from queue and both the hashmaps.
    BTNode *temp = pq->top();
    int value = temp->getValue();
    string name = reverseLookup[value];

    forwardLookup->erase(name);
    reverseLookup->erase(value);
    delete temp;    // Delete Node from pQueue
    return;
  }

  void makeHuffmanTree();   // Actual generation of huffman tree here.

  void printNodes()        // Print the entire forwardLookup Hashmap.
  {
    cout <<"[*] Nodes are as : "<<endl;
    for ( BTNode itr = forwardLookup->begin(); itr != forwardLookup->end(); itr++)
      print (itr->first , itr->second);
    cout<<endl;
    return;
  }

  void printCodes()        // Print the forward lookup table along with it's code as per Huffman Coding.
  {
    // where do you get the code from bitch ?
  }

