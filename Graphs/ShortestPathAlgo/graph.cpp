
#include "graph.h"
#include "dijkastra.h"
#include "bellmanFord.h"
#include "floydWarshall.h"

  Graph::Graph (int max_nodes , bool directional)
  {
    V = max_nodes;
    directed = directional;
    adjList.resize(V);  // Always resize, it actually changes the size whereas reserve doesn't change, it make sures that when reqd you get alteast that much.

    for (int i = 0 ; i < V; i ++)
      adjList[i].resize(V); // Always resize.
  }
  
  void Graph::addEdge (int source , int destination , int weight) // source and destination both starts with 0
  {
    adjList[source][destination] = weight;     // dia-graph
    if ( !directed)
      adjList[destination][source] = weight;     // Bidirectional
    return;
  }

  void Graph::printDetails()
  {
    cout <<"Graph is as : "<<endl;
    for (int i = 0 ; i < adjList.size();i++)
      for(int j = 0 ; j < adjList[i].size() ; j++)
        cout << i <<" : " << j << " : " <<adjList[i][j]<<endl;
  }

  void Graph::dfsHelper( int start_node , bool visited[])
  {
    visited[start_node] = 1;
    cout << start_node<<" ";
    for (int i = 0 ; i < adjList[start_node].size() ; i++)
    {
      if ( i!= start_node && !visited[ i ])
        dfsHelper(i , visited);
    }
    return;
  }

  void Graph::dfs()
  {
    bool visited[V] = {0};
    cout<<endl;
    for (int i = 0 ; i < adjList.size(); i++)
    {
      for(int j = 0 ; j < adjList[i].size(); j++)
      {
        if ( i != j && !visited[j])
          dfsHelper( j , visited) ;
      }
    }
    cout<<endl;
    return;
  }

  void Graph::printSingleSourceShortestPath (int start_node , vector<int> &path_weight)  
  {
    for (int i = 0 ; i < path_weight.size() ; i ++)
      cout <<start_node <<" --("<<path_weight[i]<<")-->"<<i<<endl;
  }

  void Graph::printAllPairShortestPath (vector<vector<int> > &path_weight)  
  {
    for (int start_node = 0 ; start_node < path_weight.size() ; start_node ++)
      for (int i = 0 ; i < path_weight.size() ; i ++)
        cout <<start_node <<" --("<<path_weight[start_node][i]<<")-->"<<i<<endl;
  }

