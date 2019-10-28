#pragma once

#include "BTNode.h"
#include "Comparison.h"

class Huffman
{
  public : 
    priority_queue<BTNode *, vector<BTNode *> , Comparison> *pq;   // Just a pointer 

    unordered_map<string , int > *forwardLookup;                // For finding frequency by using value of string as key.
    unordered_map<int, string> *reverseLookup;                // For finding valus of string by using frequency as key.
    // Thus cannot use duplicate string or duplicate frequency.

    Huffman();  // Make the hashmaps and priorityQ here.

    bool insert(string key, int value);  // Insert the Nodes here into the priority_queue well as both the hashmaps.

    void remove();  // Remove the Nodes from priority_queue as well as both the hashmaps.

    void makeHuffmanTree();   // Actual generation of huffman tree here.

    void printNodes();        // Print the entire forwardLookup Hashmap.

    void printCodes();        // Print the forward lookup table along with it's code as per Huffman Coding.

    void getCodes(unordered_map<string,string>* &codesMap , BTNode *rootNode);    // Put the values of huffman code in the codesMap

    void reset();   // Delete all hashmaps priority Queues and all BT Nodes.

    void printTree( BTNode *root);   // print The Huffman tree

};
