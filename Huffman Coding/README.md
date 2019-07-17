&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <h2> Huffman Coding</h2>

##### -> Huffman Coding is an efficient means to produce variable length codes , used in text compression.
##### -> Data Structures used in the implementation will be Priority Queue, Binary Tree and Hashmap.
##### -> 
##### -> 
##### -> To run it do the following steps :
```
user@localhost:~/$ git clone https://github.com/HarshitKhurana/DataStructures.git
user@localhost:~/$ cd DataStructures/Huffman\ Coding
user@localhost:~/DataStructures/Huffman Coding$ make install
user@localhost:~/DataStructures/Huffman Coding$ make run

```

<hr/>

### Technical Insights
##### -> As of now this implementation does not support duplicate enteries both in frequency as well as char/string, i.e if you have used a frequency value you cannot re-use it and same is with the character/string.
##### -> The purpose of huffman coding is to generate short codes to reduce the size , but in this implementation, we are more focussed on understanding the implementation so the 'huffman code' produced is a string value  of the binary code i.e if the huffman code is '0010' then instead of printing '2' (which actually represent these bytes) it will print the string '00010' only.
##### -> 
##### -> Re-hashing of the entire Map is done if the loadFactor for the hashMap exceeds 70%, loadFactor is directly proportional to the chances of collisions occuring in the Table/HashMap.
##### -> Worst case `Time Complexity` of this is: `O(n)` , when the hash function returns the same value for all 'n' elements.
##### -> The `Space Complexity` of this is:`O(n)`, i.e the size of array holding the objects.

##### -> Files and their contents are as : 

|S.No| FileName                                  | Content                                                                 |
|----| ------------------------------------------|:-----------------------------------------------------------------------:|
|1.  | HashNode.h                                | Class to hold key-value pair objects.                                   |
|4.  | main.cpp                                  | Main file which runs the program                                        |
|5.  | makefile                                  | File responsible for compiling/running etc                              |



