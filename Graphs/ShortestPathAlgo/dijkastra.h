void Graph::dijkstra(int start_node)
{
  vector<int> shortest_distance(V , INT_MAX); // Vector of size 'v' initialised with infinity i.e max distance

  for (int i = 0 ; i < adjList[start_node].size() ; i ++)
    shortest_distance[i] = adjList[start_node][i];

  for (int k = 0 ; k < adjList.size() ; k ++)
  {
    for (int i = 0 ; i < adjList[start_node].size() ; i++)
    {
      int &temp_elem = adjList[start_node][i];
      temp_elem = min (temp_elem , adjList[start_node][k] + adjList[k][i]); 
    }
  }

  for (int i = 0 ; i < adjList[start_node].size() ; i ++)
    shortest_distance[i] = adjList[start_node][i];

  return printSingleSourceShortestPath(start_node , shortest_distance);
}
