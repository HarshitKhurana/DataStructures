
#include "graph.h"
#include "dfs.h"
#include "bfs.h"

  Graph::Graph (int max_nodes , bool directional)
  {
    V = max_nodes;
    directed = directional;
    adjList = new list<int>[max_nodes]; // Array of max_nodes
  }
  
  void Graph::addEdge (int source , int destination) // source and destination both starts with 0
  {
    adjList[source].push_back(destination);   // dia-graph
    if ( !directed)
      adjList[destination].push_back(source);   // Bidirectional
  }

  void Graph::topologicalSortHelper( int start_node , bool visited[] , stack<int> &s) 
  {
    visited[start_node] = 1;  // Mark as visited

    for ( auto itr = adjList[start_node].begin() ; itr != adjList[start_node].end() ; itr++)
    {
      if ( !visited[*itr])
        topologicalSortHelper(*itr , visited , s);
    }
    s.push(start_node);
  }
    
  void Graph::topologicalSort()
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

  // void Graph::dfsHelper (int &start_node , bool visited[]) {}  // Defined in dfs.h
  // void Graph::dfs()                                            // Defined in dfs.h


