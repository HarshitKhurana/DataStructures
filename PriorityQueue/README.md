&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <h2> Priority Queue <-> Min/Max Heap </h2>

##### -> To simply put a Priority Queue is a simple queue that instead uses a factor which may or may not be the order of occurence for a node to calculate it's `priority`.
##### -> As soon as the nodes are pulled from this priority Queue, the nodes with highest priorities starts popping out.
##### -> Binary heap is used for the implementation of Priority Queue because it's the most efficient way.
##### -> Will be using STL because Heap is already implemented.
##### -> To run it do the following steps :
```
user@localhost:~/$ git clone https://github.com/HarshitKhurana/DataStructures.git
user@localhost:~/$ cd DataStructures/PriorityQueue
user@localhost:~/DataStructures/PriorityQueue$ make install
user@localhost:~/DataStructures/PriorityQueue$ make run

```

##### -> The code will take 2 inputs the name and the age and the most elder person is assigned the highest priority (i.e old person has higher priority)
<hr/>

### Technical Insights
##### -> Files and their contents are as : 

|S.No| FileName                                  | Content                                                                 |
|----| ------------------------------------------|:-----------------------------------------------------------------------:|
|1.  | Person.cpp                                | Person class having age and name atttributes                            |
|2.  | main.cpp                                  | Main file containing implementation using STL                           |
|3.  | makefile                                  | File responsible for compiling/running etc                              |

