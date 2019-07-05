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
      cout << "[*] Enter the number of children for "<< front->getValue() << " : ";
      cin>>children;

      for (int i = 0 ; i < children  ;i++)
      {
        cout << "\t[*] Enter child "<<i<<" of " <<front->getValue() <<" : ";
        int temp;
        cin>>temp;
        Node<int> *thisChild = new Node<int>(temp);
        front->children.push_back(thisChild);
        pendingNodes.push(thisChild);
        cout <<"\t\t[*] A child Node with value "<<temp<<" created\n";
      }
    }
    return root;

  }


void printTreeLevelWise(Node<int> *root)
{
  cout <<"[*] The M-Way Tree is as : "<<endl;

  queue<Node<int> *> NodesQ;    // Pointer to Node will be stored.

  NodesQ.push(root);
  cout << endl<<"\tParent -> Children"<<endl<<endl;
  while (! NodesQ.empty())
  {
    Node<int> *front = NodesQ.front();
    NodesQ.pop();

    cout << "\t[*] "<<front->getValue()<<" ->";
    unsigned int x =  front->children.size();
    for ( unsigned int i = 0 ; i < x; i ++)
    {
      cout << " " <<front->children.at(i)->getValue();
      NodesQ.push(front->children.at(i));
      if ( (i+1) != x)
        cout << ",";
    }
    cout<<endl;

  }
  return;
}

int main()
{
    int rootVal;
    cout << "[*] Enter the root of Tree : ";
    cin>>rootVal;

    Node<int> *root = new Node<int>(rootVal);

    takeInputLevelWise(root,rootVal);

    printTreeLevelWise(root);
}
