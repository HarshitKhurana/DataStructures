#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Adjacency List
class Graph
{
  int V;                        // total vertices
  list<int> *adjList;           // Array of Nodes of LL - Using internal LinkList which internally is Doubly LinkList
  bool directed;

  void topologicalSortHelper( int start_node , bool visited[] , stack<int> &s) ;
  void dfsHelper (int &start_node , bool visited[]) ;

  public:

  Graph (int max_nodes , bool directional);
  void addEdge (int source , int destination) ;
  void topologicalSort() ;
  void dfs();
  void bfs(int start_node) ;
};
