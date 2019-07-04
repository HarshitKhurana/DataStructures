#include "Node.h"
#include <bits/stdc++.h>

Node<int> * takeInputLevelWise(Node<int> *root , int rootVal)
  {

    queue<Node<int> *> pendingNodes;    // Pointer to Node will be stored. (this is on stack)
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
      Node<int> *front = pendingNodes.front();
      pendingNodes.pop();

      int children;
      cout << "[*] Enter the number of children for "<< front->getValue() <<endl;
      cin>>children;

      cout <<"Enter children"<<endl;
      for (int i = 0 ; i < children  ;i++)
      {
        int temp;
        cin>>temp;
        Node<int> *thisChild = new Node<int>(temp);
        root->children->push_back(thisChild);
        pendingNodes.push(thisChild);
        cout <<"[*] Node with value "<<temp<<" created\n";
      }
    }
    return root;

  }


void printTreeLevelWise(Node<int> *root)
{
  cout <<"[*] The M-Way Tree is as : "<<endl;

  queue<Node<int> *> NodesQ;    // Pointer to Node will be stored.

  NodesQ.push(root);
  while (! NodesQ.empty())
  {
    Node<int> *front = NodesQ.front();
    NodesQ.pop();

    cout << "\t[*] "<<front->getValue();
    for ( unsigned int i = 0 ; i < front->children->size(); i ++)
    {
      cout << " : "<<front->children->at(i).getValue();
      NodesQ.push(front->children->at(i));
    }

  }
  return;
}

int main()
{
    int rootVal;
    cout << "[*] Enter the root of Tree";
    cin>>rootVal;

    Node<int> *root = new Node<int>(rootVal);

    takeInputLevelWise(root,rootVal);

    printTreeLevelWise(root);
}
