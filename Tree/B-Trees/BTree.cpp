
#include "BTNode.h"
#include <bits/stdc++.h>

// 1 Object of this class would represent an entire tree i.e 1 root represents an entire intree.



  // Level order insertion using queue.
  BTNode<int> *inputDataBFS ()
  {
    /* inthis function asks for input in BFS format and return the root of the tree created.
     */
    int newRootValue;
    cout <<"[*] Enter value , value of '-1' means not to create object : ";
    cin >> newRootValue;
    if (newRootValue == -1)
      return nullptr;

    BTNode<int> *newRoot = new BTNode<int> (newRootValue);
    queue<BTNode<int> *> insertQ;
    insertQ.push(newRoot);

    while ( !insertQ.empty())
    {
      BTNode<int> *front =  insertQ.front();
      insertQ.pop();
      string direction;

      for (int i = 0  ; i < 2;  i ++)
      {
        direction = (i==0?"left":"right");
        int Child ;
        cout << "[*] Insert "<<direction<<" child of "<<front->getValue()<<endl;
        cin>>Child ;

        if ( Child != -1)
        {
          BTNode<int> *childObj = new BTNode<int>(Child);
          if (i==0)
            front->left = childObj;
          else
            front->right = childObj;
          insertQ.push(childObj);
        }

      }

    }
    return newRoot;
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

  // Level order traversal using queue.
  void printDataBFS (BTNode<int> *root)
  {
    queue<BTNode<int> *> traverseQ;
    traverseQ.push (root);

    while ( ! traverseQ.empty())
    {
      BTNode<int> *front = traverseQ.front();
      traverseQ.pop();
      if (front != nullptr && front->left != nullptr && front->right != nullptr)
      {
        cout << "Parent : "<<front->getValue()<<" -> \tLeft : "<<front->left->getValue()<<"\tRight : "<<front->right->getValue()<<endl;
        traverseQ.push(front->left);
        traverseQ.push(front->right);
      }
    }
    cout<<endl;
  }


  void printDataDFS (BTNode<int> *root)
  {
    if (root == nullptr)
      return;
    cout << root->getValue()<< " ";
    printDataDFS(root->left);
    printDataDFS(root->right);
}; 

