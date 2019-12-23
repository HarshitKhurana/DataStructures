#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Adjacency List
class Graph
{
  int V;                                  // total vertices
  vector<vector<int> > adjList;           // Array of Nodes of LL - Using internal LinkList which internally is Doubly LinkList
  bool directed;
  void dfsHelper(int start_node , bool visited[]);

  void printSingleSourceShortestPath(int start_node, vector<int>& );
  void printAllPairShortestPath(vector<vector<int> >& path_weight );
  public:

  Graph (int max_nodes , bool directional);
  void addEdge (int source , int destination , int weight) ;
  void dfs();
  void printDetails();
  void dijkstra(int start_node);
  void bellmanFord();
  void floydWarshall();

};
