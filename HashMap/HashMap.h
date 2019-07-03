#pragma once      // gaurd against multi-compilation.

#include "HashNode.h"

#define print(x,y) cout <<x<<"\t:\t"<<y<<endl

template <typename KeyType , typename ValueType>
class HashMap
{
  
  HashNode<KeyType , ValueType> **arrayOfObjects;   // the array containing the key-value pair ( Dynamic - On Heap )
  int maxSize;   // Maximum number of objects that can be stored in the array
  int currentSize ;  // current size of array at current moment.
  double loadFactor;    // Load Factor of the HashMap

  // Private : Functions which will be called only via other functions present in this class only.
  void rehash();   // Function which re-hash the entire hashMap and re-calculate all indices once the loadfactor goes beyond 70%.

  // The function which calculates and returns the hash for that key-value pair.
  int  calculateHash(KeyType k);

  
  // Public : Functions which will be called direclty via object of this class.
  public:

    // Constructor to create hashmap object for insertion/updation/deletion of key-value pair.
    HashMap(int size);   

    // Returns true if insertion was successful else returns false
    bool insert(KeyType k , ValueType v);    

    // Everything is done in insert function only, no need to do it seperately.
    bool  update(KeyType k , ValueType v); 

    // Returns true if removing successful else returns false
    bool remove(KeyType k);      

    // Function to print All objects present in Array.
    void printAllObjects();

    // Returns current loadFactor.
    int getLoadFactor();

    // Returns current size of the array of objects.
    int  getSize();
};
