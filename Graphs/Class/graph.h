#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Adjacency List
class Graph
{
  int V;                        // total vertices
  list<int> *adjList;           // Array of Nodes of LL - Using internal LinkList which internally is Doubly LinkList
  bool directed;

  void topologicalSortHelper( int start_node , bool visited[] , stack<int> &s)
  {
    visited[start_node] = 1;  // Mark as visited

    for ( auto itr = adjList[start_node].begin() ; itr != adjList[start_node].end() ; itr++)
    {
      if ( !visited[*itr])
        topologicalSortHelper(*itr , visited , s);
    }
    s.push(start_node);
  }

  void dfsHelper (int &start_node , bool visited[])
  {
    visited[start_node] = true;
    cout << start_node << " ";
    for ( auto itr = adjList[start_node].begin() ; itr != adjList[start_node].end() ; itr++)
    {
      if ( ! visited[*itr] )
        dfsHelper( *itr , visited);
    }
  }
  
  public:

  Graph (int max_nodes , bool directional)
  {
    V = max_nodes;
    directed = directional;
    adjList = new list<int>[max_nodes]; // Array of max_nodes
  }
  
  void addEdge (int source , int destination) // source and destination both starts with 0
  {
    adjList[source].push_back(destination);   // dia-graph
    if ( !directed)
      adjList[destination].push_back(source);   // Bidirectional
  }

  void topologicalSort()
  {
    stack<int> s;
    bool visited[V] = {0};
    for (int i  = 0 ; i < V ; i++)
    {
      if ( !visited[i])
      {
        topologicalSortHelper(i , visited , s);
      }
    }

    // Print the stack
    while( !s.empty())
    {
      cout << s.top()<< " ";
      s.pop();
    }
  }

  void dfs()
  {
    bool visited[V];
    for ( int i = 0 ; i < V ; i ++)
    {
      for ( auto itr = adjList[i].begin() ; itr != adjList[i].end() ; itr++)
        if ( !visited [*itr] )
          dfsHelper(*itr , visited)  ;
    }
  }

};
