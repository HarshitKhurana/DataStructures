&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <h2> HashMap Working</h2>

##### -> To simply put a hashmap in C++ is a Data Structure that helps to access a value which related to its' corresponding key in O(1) time.
##### -> The way it does is by keeping a map of all the key-value pairs and whenever a new pair is added or the `value` corresponding to a particular `key` is asked for it simply looks up in the map and returns.
##### -> The code is an implementation of HashMap with *`Seperate Chaining`* which means that incase of a collision (i.e the case when hash values of 2 keys are same), a new branch will be formed at that specific index and all the 'Key-Value' pair that returns the same hash the corresponding object will be pushed in that seperate branch/list.
##### -> The hash function used here is the sum of ASCII value of all characters in the key multiplied by their indexes and finally modulus with maxSize of List.(can be modified in HashMap.cpp though).
##### -> To run it do the following steps :
```
user@localhost:~/$ git clone https://github.com/HarshitKhurana/DataStructures.git
user@localhost:~/$ cd DataStructures/HashMap
user@localhost:~/$ make install
user@localhost:~/$ make run

```

<hr/>

### Technical Insights
##### -> `Class` named `HashNode` is a user-defined data structure that actually holds the key-value pair.
##### -> `Class` named `HashMap` is a user-defined data structure that contains the map of the key-value pair i.e this class contains the collection of `objects` of `HashNode Class`.
##### -> Files and their contents are as : 

|S.No| FileName                                  | Content                                                                 |
|----| ------------------------------------------|:-----------------------------------------------------------------------:|
|1.  | HashNode.h                                | Class to hold key-value pair objects.                                   |
|2.  | HashMap.h                                 | Class to hold the list of the 'key-value' pair objects                  |
|3.  | HashMap.cpp                               | File containing the implementation of functions defined in HashMap.h    |
|4.  | main.cpp                                  | Main file which runs the program                                        |
|5.  | makefile                                  | File responsible for compiling/running etc                              |

##### -> Re-hashing of the entire Map is done if the loadFactor for the hashMap exceeds 70%, loadFactor is directly proportional to the chances of collisions occuring in the Table/HashMap.


