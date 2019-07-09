&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <h2> Binary Search Tree </h2>

##### -> A Binary Search Tree(BST) is a special kind of Binary Tree in which the node to the left of root are smaller than root and the ones on right are greater than root  
##### -> The left and the right sub-tree are BST in themselves.
##### -> A BST can hold only distinct keys.
##### -> Time Complexities are as : 

|S.No| Operation                                 | Time Complexity                                    |
|----| ------------------------------------------|:---------------------------------------------------:|
|1.  | Searching  - Average Case                 | O(logN) ( Balanced BST)                            |  
|2.  | Searching  - Worst Case                   | O(N) ( Skewed BST)                                 | 
|2.  | Deletion   - Worst Case                   | O(N) ( In case of root element being deleted)      | 

##### -> In insertion or search if the current element is smaller than the root then go to left else go to right.

##### -> To run it do the following steps :
```
user@localhost:~/$ git clone https://github.com/HarshitKhurana/DataStructures.git
user@localhost:~/$ cd DataStructures/Tree/BST
user@localhost:~/DataStructures/Tree/BST$ make install
user@localhost:~/DataStructures/Tree/BST$ make run

```

##### -> The folder structure is as follows : 

|S.No| FileName                                  | Content                                                                 |
|----| ------------------------------------------|:-----------------------------------------------------------------------:|
|1.  | BTNode.h                                  | Class to hold a single Node object.                                     |
|2.  | BSTree.cpp                                | Implementation of Binary Search Tree                                    |
|3.  | main.cpp                                  | Main file which runs the program                                        |
|4.  | makefile                                  | File responsible for compiling/running etc                              |


&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <h3>Note : </h3> 

##### -> Inorder traversal of BST always produces sorted output.
##### -> We can construct a BST with only Preorder or Postorder or Level Order traversal. 
##### -> Number of unique BSTs with n distinct keys is Catalan Number

##### -> Balanced BST :  It is a BST in which the difference in length of left SubTree and right SubTree is between "-1 to 1".

