#include "Huffman.h"

# define print(x,y) cout <<"\t"<<x<<"\t"<<y<<endl
# define print3(x,y,z) cout <<"\t"<<x<<"\t"<<y<<"\t"<<z<<endl

  Huffman::Huffman()  // Make the hashmaps and priorityQ here.
  {
    pq = new priority_queue<BTNode *, vector<BTNode *> , Comparison>();
    forwardLookup = new unordered_map<string , int>();
    reverseLookup = new unordered_map<int , string>();
  }


  // Return false if already exists i.e unable to insert.
  bool Huffman::insert(string key , int value)  // Insert the Nodes here into the priority_queue well as both the hashmaps.
  {
    if (forwardLookup->count(key))
      return false;   // Already exists

    (*forwardLookup)[key] = value;     
    (*reverseLookup)[value] = key;     
    BTNode *node = new BTNode(value);   // Don't forget to delete this node in remove function from priority Q as well as both the hashmaps.
    // Insert in priority queue
    pq->push(node);
    return true;
  }


  void Huffman::remove()  // Remove the Nodes from priority_queue as well as both the hashmaps.
  { 
    // Fetch the top element from pQeueue delete it from queue and both the hashmaps.
    BTNode *temp = pq->top();
    int value = temp->getValue();
    string name = reverseLookup->at(value);

    forwardLookup->erase(name);
    reverseLookup->erase(value);
    delete temp;    // Delete Node from pQueue
    return;
  }


  // Pass by Reference
  void Huffman :: getCodes(unordered_map<string,string>* &codesMap , BTNode *rootNode)   // Return codes from the tree formed.
  {
    // Initially we will always recieve a non-NULL pointer, so no need to check initially
    
    // for all left children append "0" to the code and for all right children append "1" to the code.
    
    if (rootNode->left != nullptr)
    {
      print ("left" , rootNode->getValue());
      (*codesMap)[ std::to_string(rootNode->left->getValue())] = (string)(codesMap->at( to_string(rootNode->getValue())) + "0");
      getCodes( codesMap, rootNode->left);
    }
    if (rootNode->right != nullptr)
    {
      print ("right" , rootNode->getValue());
      (*codesMap)[std::to_string(rootNode->right->getValue())] = (string)(codesMap->at( to_string(rootNode->getValue())) + "1");
      getCodes( codesMap, rootNode->left);
    }
    return;
  }


   void Huffman :: makeHuffmanTree()   // Actual generation of huffman tree here.
  {
    // get 2 min nodes from the MinHeap/Priority_queue and sum up their values to generate a new node (for BT only and not hashmap) and insert it back in the PQ, 
    // with it's left and right nodes pointing to the nodes which were used to create this node.
    // repeat this process untill there is only 1 node left.
    // This way the tree is formed starting from that one node.

    cout <<"\tHuffMan tree is as : (parent : left : right) " <<endl;
    while ( pq->size() != 1)
    {
      BTNode *firstElem = pq->top();
      pq->pop();
      BTNode *secondElem = pq->top();
      pq->pop();

      int newNodeValue = firstElem->getValue() + secondElem->getValue();
      // Cannot directly use insert function here as it will also insert in the hashmap , which is not required.
      BTNode *newNode = new BTNode(newNodeValue);
      newNode->left = firstElem;  // Smaller of 2
      newNode->left = secondElem; // Bigger of 2
      pq->push(newNode);
    }
    // finally the priority Queue now only consists of 1 element which is the root of the Binary Tree.
    return;
  }


  void Huffman:: printNodes()        // Print the entire forwardLookup Hashmap.
  {
    cout <<"[*] Nodes are as : "<<endl;
    for ( auto itr = forwardLookup->begin(); itr != forwardLookup->end(); itr++)
      print (itr->first , itr->second);
    cout<<endl;
    return;
  }


  void Huffman::printCodes()        // Print the forward lookup table along with it's code as per Huffman Coding.
  {
    // Call makeHuffmanTree which will generate the tree for you, once the tree is generated call generateCodes() which will return the hashmap of codes.
    makeHuffmanTree();

    unordered_map<string, string> *codesMap = new unordered_map<string,string>; // Map of frequencyOfString : huffmanCode

    // It fills up the hashmap with all the codes , keep in mind it also consists of 'newNode' which are created for the purpose of creating the Huffman Tree.
    (*codesMap)[to_string(pq->top()->getValue())] = "";   // Assign empty string to it 
    getCodes(codesMap , pq->top());

    cout <<"[*] The Codes for the strings are as follows : "<<endl;
    for ( unordered_map<string, string> ::iterator itr = codesMap->begin(); itr != codesMap->end() ; itr++)
    {
      print3 ("temp\t" , itr->first , itr->second);
      // If this node exists in the reverse lookup table print it , else it is 'newNode' which was created for the purpose of completeing the Huffman Tree, delete it from codesMap
      if (reverseLookup->count( std::stoi(itr->first)) ) 
        // print (string , it's frequency , it's HuffmanCode)
        print3( reverseLookup->at( std::stoi(itr->first)) , itr->first, itr->second);
      else  // Remove it
      {
        codesMap->erase(itr->first);
      }
    }
    cout <<endl;
    return;
  }

  void Huffman::reset()
  {
    while ( !pq->empty())
    {
      BTNode *temp = pq->top();
      delete temp;
      pq->pop();
    }
    delete pq;
    delete forwardLookup;
    delete reverseLookup;
    return;
  }



