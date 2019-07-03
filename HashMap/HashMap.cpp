#include "HashMap.h"

template <typename KeyType , typename ValueType>
HashMap<KeyType , ValueType>::HashMap(int size)
{
  cout << "[*] Initial size of HashMap as asked by user is : " << size<<endl;
  maxSize = size;
  arrayOfObjects = new HashNode<KeyType , ValueType>*[maxSize];

  // Initialise all objects with Null , will be useful in case of re-hashing i.e finding out what all indexes actually contain data and which ones not.
  for (int i = 0 ; i < maxSize ; i++)
    arrayOfObjects[i] = NULL;
}


template <typename KeyType , typename ValueType>
void HashMap <KeyType , ValueType>:: rehash()
{
   /* 
    * This function is called means loadFactor has exceeded 70%.
    * Re-create hashes for all the objects in the array and re-write in a new array of double the size previous and assign it to the previous array only (obv after adding all the key-value pair)
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
        this->insert( head->key , head->value );
        head = head->next;      
      }
    }
  }
  
  return;
}

template <typename KeyType , typename ValueType>
int  HashMap<KeyType , ValueType> :: calculateHash(KeyType k)
{
  /*
   * Returns the hash value of this key-pair which is the sum of all ASCII characters in the key.
   */

  int hashValue = 0;
  string keyString = (string)k;     // Type cast into string and hope it gets typecasted properly.
  for (int i = 0 ; i < keyString.length() ; i++)
    hashValue += keyString[i];

  return hashValue;
}

template <typename KeyType , typename ValueType>
int  HashMap <KeyType , ValueType>:: size()
{
  return this->currentSize;
}

template <typename KeyType , typename ValueType>
bool HashMap<KeyType , ValueType> :: insert(KeyType k , ValueType v)    
{
  // Before inserting no need to check for size because after every insertion a check for loadFactor is being done and since we will be inserting one by one thus no need to check size before.
  // Check the loadFactor after inserting if it's greater than 70% then call rehashing function.
  // For insertion just get the hash value and once you get it iterate over that branch in the List/Array/Chain of arrayOfObjects and wherever you find NULL just place the element there.

  /*
   * This function simply inserts the 'Key-Value' pair in the Array of Objects.
   */

  bool inserted = false;
  int hashValue = calculateHash(k);
  HashNode<KeyType, ValueType> itr  = arrayOfObjects[hashValue];

  // Reach the end of list where itr->next is NULL.
  while (itr->next != NULL)
  {
    itr = itr->next;
  }
  HashNode<KeyType, ValueType> obj(k,v);
  itr->next = obj;
  inserted = true;

  currentSize += 1;     // Since a new element is added

  // Load Factor check for re-hashing to avoid collisions
  int loadFactor = 1.0 * (currentSize/ maxSize);
  if (loadFactor < 0.70)
    rehash();
}

// Everything is done in insert function only, no need to do it seperately.
template <typename KeyType , typename ValueType>
bool HashMap <KeyType , ValueType>:: update(KeyType k , ValueType v) 
{
  /*
   * Function to update the key-Value pair of an already existing object, if no object with that key found then would create a new object and insert it.
   */
  return this->insert(k,v);
}

template <typename KeyType , typename ValueType>
bool HashMap <KeyType , ValueType>:: remove(KeyType k )                  
{
  /*
   * Function to remove the 'Key-Value' pair corresponding to the object pointed out by the key.
   */
  int hashValue = calculateHash(k);

  HashNode<KeyType , ValueType> finalNode = arrayOfObjects[hashValue];
  HashNode<KeyType , ValueType> parent = finalNode;
  HashNode<KeyType , ValueType> itr = finalNode;

  bool deletedElement = false;
  if (itr->key == k)
  {
    // Delete this node and by delete , directly modify in final list since it was the first element itslef that matched.
    finalNode = itr->next;
    free itr;
    deletedElement = true;
  }
  else
  {
    itr = itr->next; // We know for sure that the first element in the chain isn't the 'Key-Value' pair we are looking for.
    while ( itr != NULL)
    {
      if (itr->key == k)
      {
        // Delete this node and by delete I mean , parent->next = currObject->next and free currObject and then break;
        parent->next = itr->next;
        free itr;
        deletedElement = true;
      }
      parent = itr;
      itr = itr->next;
    }
  }

  arrayOfObjects[hashValue]  = finalNode :    // Finally placing back the value on the list.
  return deletedElement;
}


template <typename KeyType , typename ValueType>
void HashMap<KeyType , ValueType> :: printAllObjects()
{
  cout << "[*] printAllObjects() : The Objects are as : "<<endl;
  for (int i = 0 ;i < currentSize ; i ++)
  {
    HashNode<KeyType , ValueType> *itr = arrayOfObjects[i];
    while (itr->next != NULL)
    {
      cout << itr->key <<" --- "<<itr->Value;
    }
    cout <<endl;
  }
}
