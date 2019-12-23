
// This is the private function which is actually finding the DFS.
void Graph::dfsHelper (int &start_node , bool visited[])
{
  visited[start_node] = true;
  cout << start_node << " ";
  for ( auto itr = adjList[start_node].begin() ; itr != adjList[start_node].end() ; itr++)
  {
    if ( ! visited[*itr] )
      dfsHelper( *itr , visited);
  }
}

// This is the actual public function available via interface
void Graph::dfs()
{
  bool visited[V];
  for ( int i = 0 ; i < V ; i ++)
  {
    for ( auto itr = adjList[i].begin() ; itr != adjList[i].end() ; itr++)
      if ( !visited [*itr] )
        dfsHelper(*itr , visited)  ;
  }
}
