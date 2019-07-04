#include "HashMap.h"

  template <typename KeyType , typename ValueType>
  void HashMap<KeyType ,ValueType> :: rehash()   
  {
     /* 
      * This function is called means loadFactor has exceeded 70%.
      * Re-create hashes for all the objects in the HashMap and re-write in a new HashMap of double the size previous and assign it's address to the HashMap object only (obv after adding all the key-value pair)
      */  

    int prevSize = maxSize;
    maxSize = 2*maxSize;
    HashNode<KeyType,ValueType> **prevArrayOfObjects = arrayOfObjects;    // Stored the previous list here.
    arrayOfObjects = new HashNode<KeyType , ValueType>*[maxSize];         // Create new list of double the size.

    // Now simply iterate over all the objects in the 'prevArrayOfObjects' and for every 'key-value' pair call insert function.
    for (int i = 0 ; i < prevSize ; i++ )
    {
      if (prevArrayOfObjects[i] != NULL )       //  insert in new List
      {
        HashNode<KeyType , ValueType> *head = prevArrayOfObjects[i];
        
        // for all the elements in the branch of this HashNode (if there is any)
        while ( head != NULL) {
          this->insert( head->getKey() , head->getValue());
          head = head->next;      
        }
      }
    }
    
    return;
  }


  template <typename KeyType , typename ValueType>
  int  HashMap<KeyType ,ValueType> ::  calculateHash(KeyType k)
  {
    /*
     * Returns the hash value of this key-pair which is the sum of all ASCII characters multiplied by their index in the key mod the maxSize
     */

    int hashValue = 0;
    string keyString = (string)k;     // Type cast into string and hope it gets typecasted properly.
    for (unsigned int i = 0 ; i < keyString.length() ; i++)
      hashValue += keyString[i] * i;

    return hashValue%maxSize;
  }


  template <typename KeyType , typename ValueType>
  HashMap <KeyType ,ValueType> ::  HashMap(int size)   
  {
    cout << "[*] Initial default size of HashMap is : " << size<<endl;
    currentSize = 0;
    loadFactor = 0;
    maxSize = size;
    arrayOfObjects = new HashNode<KeyType , ValueType>*[maxSize];

    // Initialise all objects with Null , will be useful in case of re-hashing i.e finding out what all indexes actually contain data and which ones not.
    for (int i = 0 ; i < maxSize ; i++)
    {
      arrayOfObjects[i] = NULL;
    }
  }


  template <typename KeyType , typename ValueType>
  bool  HashMap<KeyType ,ValueType> :: insert(KeyType k , ValueType v)    
  {
    // Before inserting no need to check for size because after every insertion a check for loadFactor is being done and since we will be inserting one by one thus no need to check size before.
    // Check the loadFactor after inserting if it's greater than 70% then call rehashing function.
    // For insertion just get the hash value and once you get it iterate over that branch in the HashMap and see if that particular key exists , if it does then update it's value otherwise if it doesn't already exists, then create new object for that 'key-Value' pair.
    /*
     * This function simply inserts the 'Key-Value' pair in the HashMap.
     */

    int hashValue = calculateHash(k);

    HashNode<KeyType, ValueType> *head  = arrayOfObjects[hashValue];
    HashNode<KeyType, ValueType> *obj = new HashNode<KeyType , ValueType>(k,v);   // On heap call delete while deleting it.

    HashNode<KeyType, ValueType> *itr = head;

    // Iterate to check if it already exists or not.
    while ( itr != NULL)
    {
      if ( itr->getKey() == k )
      {
        cout << "This key already exists, updating it's value"<<endl;
        itr->setValue(v);
        return true;
      }
      itr = itr->next;
    }

    obj->next = head;     // Add this new object to top of list.
    head = obj;           // Updating its head

    arrayOfObjects[hashValue] = head;       // Place it back on the array.

    currentSize += 1;     // Since a new element is added

    // Load Factor check for re-hashing to avoid collisions
    loadFactor = getLoadFactor();
    if (loadFactor > 0.70)
      rehash();
    cout << "[*] 'Key-Value' pair added successfully , current loadFactor : "<< loadFactor<<endl;
    return true;
  }


  template <typename KeyType , typename ValueType>
  bool  HashMap<KeyType ,ValueType> ::  update(KeyType k , ValueType v) 
  {
    /*
     * Function to update the key-Value pair of an already existing object, if no object with that key found then would create a new object and insert it.
     */
    return this->insert(k,v);
  }


  template <typename KeyType , typename ValueType>
  bool  HashMap<KeyType ,ValueType> :: remove(KeyType k )                    // Returns true if removing successful else returns false
  {
    /*
     * Function to remove the 'Key-Value' pair corresponding to the object pointed out by the key.
     */

    bool deletedElement = false;
    int hashValue = calculateHash(k);

    HashNode<KeyType , ValueType> *finalNode = arrayOfObjects[hashValue];
    if (finalNode == NULL)
    {
      cout << "[#] Element doesn't exists thus couldn't delete"<<endl;
      return deletedElement;
    }
    HashNode<KeyType , ValueType> *parent = finalNode;
    HashNode<KeyType , ValueType> *itr = finalNode;

    if (itr->getKey() == k)
    {
      // Delete this node and by delete , directly modify in final list since it was the first element itslef that matched.
      finalNode = itr->next;
      delete itr;
      deletedElement = true;
    }
    else
    {
      itr = itr->next; // We know for sure that the first element in the chain isn't the 'Key-Value' pair we are looking for.
      while ( itr != NULL)
      {
        if (itr->getKey() == k)
        {
          // Delete this node and by delete I mean , parent->next = currObject->next and delete currObject and then break;
          parent->next = itr->next;
          delete itr;
          deletedElement = true;
        }
        parent = itr;
        itr = itr->next;
      }
    }

    arrayOfObjects[hashValue]  = finalNode ;    // Finally placing back the value on the list.

    if (!deletedElement)
      cout << "[#] Element doesn't exists thus couldn't delete"<<endl;
    else
      cout << "[*] Element deleted successfully"<<endl;

    return deletedElement;
  }


  template <typename KeyType , typename ValueType>
  void  HashMap<KeyType ,ValueType> :: printAllObjects()
  {
    if (this->getSize() == 0)
    {
      cout << "[*] printAllObjects() : HashMap is empty"<<endl;
      return;
    }

    cout << "[*] printAllObjects() : The Objects are as : "<<endl;
    print("","");
    print("KEY","VALUE");
    print("","");
    for (int i = 0 ;i < currentSize ; i ++)
    {
      HashNode<KeyType , ValueType> *head = arrayOfObjects[i];
      while (head != NULL)
      {
        print (head->getKey(),head->getValue());
        head = head->next;
      }
      cout <<endl;
    }
    return;
  }


  template <typename KeyType , typename ValueType>
  void  HashMap<KeyType ,ValueType> :: printThisObject(KeyType k){
    /*
     * Prints sinegle object containing key value pair pointed by the key
     */
    if (this->getSize() == 0)
    {
      cerr << "[#] printThisObject() : HashMap is empty"<<endl;
      return;
    }
    for (int i = 0 ;i < currentSize ; i ++)
    {
      HashNode<KeyType , ValueType> *head = arrayOfObjects[i];
      while (head != NULL)
      {
        if (head->getKey() == k)
        {
          print("","");
          print("KEY","VALUE");
          print("","");
          print (head->getKey(),head->getValue());
          return;
        }
        head = head->next;
      }
      cout <<endl;
    }

    cerr << "[#] printThisObject() : Key Not found in HashMap "<<endl;
    return;
  }


  template <typename KeyType , typename ValueType>
  int  HashMap<KeyType ,ValueType> :: getLoadFactor(){
    /* Returns current Load Factor of hashMap.
     */
    return this->loadFactor;
  }
  

  template <typename KeyType , typename ValueType>
  int HashMap<KeyType ,ValueType> ::  getSize()
  {
    /* Returns current size of the HashMap.
     */
    return this->currentSize;
  }

