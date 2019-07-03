#include<iostream>
#include<climits>
#include<cmath>

using namespace std;

template <typename KeyType, typename ValueType>   
class HashNode{

  KeyType key;
  ValueType value;

  public:
    HashNode *next;     // Pointer to next (used incase of collision , otherwise NULL)
    HashNode(KeyType k , ValueType v)
    {
      this->key = k;
      this->value = v;
      this->next = NULL;      // (Keep in mind that here we are/[want to] assigning the pointer value = NULL , and not to the value pointed by the pointer)
    }

    KeyType getKey()
    {
      return this->key;
    }

    ValueType getValue()
    {
      return this->value;
    }

    // No option to modify key, it will need to new object.
    void setValue(ValueType v)
    {
      this->value = v;
    }
};
