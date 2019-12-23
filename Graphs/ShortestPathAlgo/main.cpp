
#include "graph.h"

void insertEdge(Graph *g , int nodes)
{
  for (int i = 0 ; i < nodes; i ++)
    for (int j = 0 ; j < nodes; j ++)
      g->addEdge(i,j,i*j);
}

int main( int argc,  char *argv[])
{

  int nodes = 6;
  bool directional = true;
  Graph *g = new Graph(nodes , !directional);
  insertEdge(g,nodes);
  // g->printDetails();
  g->dfs();
  cout <<"Dijkstra shortes path , starting from node 2: "<<endl;
  g->dijkstra(2);
  delete g;
}
