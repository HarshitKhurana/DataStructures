### [\*] Shortest Path Algos - Graphs

* First go through the basics (if not already visited).
* Shortest path algo for graph.
* Will be using adjacency matrix for all 3 algos.

</hr>

* All seperate files are there for different algorithmic implementation.  (Easy to add and remove)
* Use makefile for compiling and executing.
* Use as:

```bash
$ make clean
$ make all
$ make run
```


#### [\*] Dijkstras Algo
* Single Source Shortes Path algo.
* Only work for non-negative weights.
* Greedy approach.
* Requires starting edge, from which it should calculate the distance to all nodes.
* Time Complexity : O(E\*log(V))

> **REQUIREMENT:** All edges must have non-negative weights otherwise it will be stuck in an infinite loop cycle.

* Basically what it does is :
```bash
distance(A,C) = min (distance(A,c) , distance(A,B) + distance(B,C))
```

#### [\*] Bellman Ford Algo
* Single Source Shortes Path algo.
* Works for non-negative weights too
* DP like approach.
* Requires starting edge, from which it should calculate the distance to all nodes.
* Time Complexity : O(E\*V)
  * For a complete graph E aprox= V^2. 
  * Thus worst case Time Complexity : E(V^3)


> **DRAWBACK:** It will not yield correct answer in case of negative weight cycle.

**Ques** How to find negative weight cycle in a graph ?

**Ans**  Run the Bellman Ford Algo `|V|-1` times (where V is the total number of vertices in the graph) and if there is no -ve weight cycle then the answer should be the shortest path. Now run this 1 more time , and if there is any change in the shortes path or it's distance then that means there is certainly a negative weight cycle in the graph.


#### [\*] Floyd-Warshall Algo
* It is an all pair shortest path algo i.e unlike Dijkastra or BellMan ford algo it finds the shortest path from and to every node in the graph.
* Time Complexity : O(V^3)
* Uses adjacency martrix and not list.
* It can be used to detect negative weight cycle.


**Ques:** How do we find negative weight cycle using Floyd-Warshall algo ?

**Ans:** Floyd Warshall algo is an all pair shortest path algo i.e it finds the shortest path from and to every node in the graph. Also we know that from every node to itself the shortest possible distance is '0' thus once the shortest distance for all pairs are calculated we simply iterate over the matrix and see if the distance from a node to itself is less than '0' then it means that the graph contains a negative weight cycle.

