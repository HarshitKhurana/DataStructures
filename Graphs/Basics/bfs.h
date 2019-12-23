
void Graph::bfs(int start_node)
{
  // Initialise bool array and queue
  bool visited[V] {0};
  queue<int> q;

  // Insert start node in q and mark it as visited.
  q.push(start_node);
  visited[start_node] = true;

  while ( !q.empty())
  {
    // Pull top element from queue , print it 
    int front_elem = q.front();
    q.pop();
    cout << front_elem<<" ";

    // insert child nodes of top_element in the queue
    for ( auto itr = adjList[front_elem].begin() ; itr != adjList[front_elem].end() ; itr++)
    {
      if ( !visited[*itr])        
        {
          q.push(*itr);
          visited[*itr] = true;
        }
    }

  }
  return ;
}