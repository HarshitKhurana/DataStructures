#include "HashNode.h"

# pragma once   // Gaurding against re-compilcation.

class HashMap
{
  HashNode<KeyType , ValueType> **arrayOfObjects;   // the array containing the key-value pair ( Dynamic - On Heap )
  int maxSize;   // Maximum number of objects that can be stored in the array
  int currentsize;  // current size of array at current moment.

  // Functions which will be called only via other functions present in this class only.
  
  void rehash();                                // Function which re-hash the entire hashMap and re-calculate all indices once the loadfactor goes beyond 70%.
  int  size();                                  // Returns current size of the array of objects.
  int  calculateHash(KeyType k, ValueType v);                                  // The function which calculates and returns the hash for that key-value pair.


  // Functions which will be called direclty via object of this class.
  public:

    HashMap();   // Constructor to create hashmap object for insertion/updation/deletion of key-value pair.

    bool insert(KeyType k , ValueType v);       // Returns true if insertion was successful else returns false
    bool update(KeyType k , ValueType v);       // Returns true if update was successful else returns false
    bool remove(KeyType k );                    // Returns true if removing successful else returns false
    void printAllObjects();                     // Function to print All objects present in Array.

};
