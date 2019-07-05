
#include "BTNode.h"

// 1 Object of this class would represent an entire tree i.e 1 root represents an entire intree.

  BTNode<int> *inputDataBFS ()
  {
    /* inthis function asks for input in BFS format and return the root of the tree created.
     */
    cout <<"[*] Input intree row-wise (BFS)"<<endl;
    return nullptr;
  }

  BTNode<int>* inputDataDFS(int count = 0)
  {
    /* inthis function asks for input in DFS format and return the root of the tree created.
     */

    int newRootValue ; 
    if (count == 0)
      cout <<"[*] Enter value , value of '-1' means not to create object : ";
  else
      cout <<", value of '-1' means not to create object : ";
    cin >> newRootValue;
    if (newRootValue == -1)
      return nullptr;

    BTNode<int> *newRoot = new BTNode<int> (newRootValue);

    cout <<"\t[*] Enter left of : "<<newRoot->getValue();
    newRoot->left  = inputDataDFS(count+1); 
    cout <<"\t[*] Enter right of : "<<newRoot->getValue();
    newRoot->right = inputDataDFS(count+1); 

    return newRoot;
  }

  void printDataBFS (BTNode<int> *root){}


  void printDataDFS (BTNode<int> *root)
  {
    if (root == nullptr)
      return;
    cout << root->getValue()<< " ";
    printDataDFS(root->left);
    printDataDFS(root->right);
}; 

