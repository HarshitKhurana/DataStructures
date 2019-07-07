
#include "BTNode.h" 


  // comparer function to evaluate which one is larger from x and y, return true if x is greater else returns false.
  bool comparer (int x,int y)
  {
    return x>y ? true:false;
  }

  // Function to insert a value in BSint
  BTNode<int> *insert (BTNode<int> *root , int insValue)
  {
    // if current node is null the directly insert here.
    if (root == NULL)
    {
      BTNode<int> *thisObj = new BTNode<int>(insValue);
      root = thisObj;
    }
    else
    {
      // comparer function returns true if first arg is greater than second arg.
      if ( comparer(root->getValue(), insValue) )
        root->left  = insert(root->left , insValue);      // Insert in left subtree
      else
        root->right = insert(root->right , insValue);      // Insert in rightsubtree
    }
    return root;
  }

  // Function to remove a value from BSint and return root of remaining tree.
  BTNode<int> * remove (BTNode<int> *root , int delValue)
  {
    if (root == NULL)
      root = NULL;

    else if (root->getValue() == delValue)
    {
      // if only 1 child make it point to current node
      if ( root->left == NULL)
        root =  root->right;
      else if ( root->right == NULL)
        root =  root->left;

      // Use little head here , if the delValue is a root then you would need to re-arrange it's children
      // Simple store all the elements of that tree in a vector remove the node and then call insert function back on all nodes present in the vector. -> Worst case O(n).
      // Use a queue to iterate over BST in BFS manner.
      else if ( (root->left != NULL) && (root->right != NULL) )
      {
        vector<BTNode<int> *> v;    // To Store all nodes
        queue <BTNode<int> *> q;     // To iterate over entire tree
        q.push(root);
        //v.push_back(root);      // We don't want the root of this array to also be a part of our new tree because we want to remove it , right ? YES.
        while (!q.empty())
        {
          BTNode<int> *front = q.front();
          q.pop();
          if ( front->left != NULL)
          {
            q.push(front->left);
            v.push_back(front->left);
          }
          if ( front->right != NULL)
          {
            q.push(front->right);
            v.push_back(front->right);
          }
        }
        // Now the vector has all the elements of that Tree/Sub-Tree.
        
        // Here simply create a new tree with all the elements and return the root of it, at root keep the element.
        BTNode<int> *newRoot = new BTNode<int> (v.at(0)->getValue()); // first element of array.
        delete v.at(0);
        for (unsigned int i = 1; i < v.size() ; i ++)
        {
          newRoot = insert(newRoot , v.at(i)->getValue());
          // since all the objects are on heap , make sure to delete them
          delete v.at(i);
        }
        root = newRoot;   // return the root of newly formed array.
      }
    }
    else
    {
      // comparer function returns true if first arg is greater than second arg.
      if (comparer(root->getValue() ,delValue))
        root = remove(root->left , delValue);
      else
        root = remove(root->right , delValue);
    }
    return root;
  }

  // Function to search a value in BSint, return true if found else false.
  bool  search (BTNode<int> *root , int searchValue)
  {
    if (root == NULL)
      return false;

    else if (root->getValue() == searchValue)
      return true;
    else
    {
      if (comparer(root->getValue(), searchValue) )
        return search(root->left , searchValue);      // Insert in left subtree
      else
        return search(root->right , searchValue);      // Insert in rightsubtree
    }
  }

  // Function to print inthe BSint , the value of type decides PreOrder , InOrder , Post-Order traversal resp.
  void  print (BTNode<int> *root , int type)
  {
    // type = 0 -> Pre-Order
    // type = 1 -> In-Order
    // type = 2 -> Post-Order
    if (root == NULL)
      return;

    if (type == 0)
    {
      cout << " " <<root->getValue();
      print (root->left  , type);
      print (root->right , type);
    }

    else if (type == 1)
    {
      print (root->left  , type);
      cout << " " <<root->getValue();
      print (root->right , type);
    }

    else if (type == 2)
    {
      print (root->left  , type);
      print (root->right , type);
      cout << " " <<root->getValue();
    }

  }



