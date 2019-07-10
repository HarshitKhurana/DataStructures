&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <h2> Huffman Coding</h2>

##### -> Huffman Coding is an efficient means to produce variable length codes , used in text compression.
##### -> To run it do the following steps :
```
user@localhost:~/$ git clone https://github.com/HarshitKhurana/DataStructures.git
user@localhost:~/$ cd DataStructures/HashMap
user@localhost:~/DataStructures/HashMap$ make install
user@localhost:~/DataStructures/HashMap$ make run

```

<hr/>

### Technical Insights
##### -> `Class` named `HashNode` is a user-defined data structure that actually holds the key-value pair.
##### -> `Class` named `HashMap` is a user-defined data structure that contains the map of the key-value pair i.e this class contains the collection of `objects` of `HashNode Class`.
##### -> Re-hashing of the entire Map is done if the loadFactor for the hashMap exceeds 70%, loadFactor is directly proportional to the chances of collisions occuring in the Table/HashMap.
##### -> Worst case `Time Complexity` of this is: `O(n)` , when the hash function returns the same value for all 'n' elements.
##### -> The `Space Complexity` of this is:`O(n)`, i.e the size of array holding the objects.

##### -> Files and their contents are as : 

|S.No| FileName                                  | Content                                                                 |
|----| ------------------------------------------|:-----------------------------------------------------------------------:|
|1.  | HashNode.h                                | Class to hold key-value pair objects.                                   |
|2.  | HashMap.h                                 | Class to hold the list of the 'key-value' pair objects                  |
|3.  | HashMap.cpp                               | File containing the implementation of functions defined in HashMap.h    |
|4.  | main.cpp                                  | Main file which runs the program                                        |
|5.  | makefile                                  | File responsible for compiling/running etc                              |



