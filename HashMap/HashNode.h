#include<iostream>
#include<climits>
#include<cmath>

using namespace std;

template <typename KeyType, typename ValueType>   
class HashNode{

  KeyType key;
  ValueType value;
  HashNode *next;     // Pointer to next (used incase of collision , otherwise NULL)

  public:
    HashNode(KeyType k , ValueType v)
    {
      this->key = k;
      this->value = v;
      this->next = NULL;      // (Keep in mind that here we are/[want to] assigning the pointer value = NULL , and not to the value pointed by the pointer)
    }

};
