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
##### -> The temporary nodes created as the sum of 2 smaller valued nodes are not added into the hashmap, becuase not required.
##### -> For all left children "0" is appended to code and for all right children "1" is appended.
##### -> 

##### -> Worst case `Time Complexity` of this is: `O(n)` , when the hash function returns the same value for all 'n' elements.
##### -> The `Space Complexity` of this is:`O(n)`, i.e the size of array holding the objects.

##### -> Files and their contents are as : 

|S.No| FileName               | Content                                                  
|----| -----------------------|:------------------------------------------------------|:
|1.  | BTNode.h               | Class For Binary Tree (Huffman Tree)                  |   
|2.  | Comparison.h           | For comparing 2 BTNode objects                        |   
|3.  | Huffman.h              | Header file defining members for HuffMan class        | 
|4.  | Huffman.cpp            | Implementation of HuffMan Class                       |   
|5.  | makefile               | File responsible for compiling/running etc            |   



