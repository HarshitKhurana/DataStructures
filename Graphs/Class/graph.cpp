
#include "graph.h"

int main( int argc,  char *argv[])
{

  int nodes = 6;
  bool directional = true;
  Graph *g = new Graph(nodes , directional);
	g->addEdge(5, 2); 
	g->addEdge(5, 0); 
	g->addEdge(4, 0); 
	g->addEdge(4, 1); 
	g->addEdge(2, 3); 
	g->addEdge(3, 1);
	cout <<"topological Sort : " <<endl;
	g->topologicalSort();
  cout<<endl;
  delete g;

  directional = false;
  g = new Graph(nodes , directional);
	g->addEdge(0, 1); 
	g->addEdge(0, 4); 
	g->addEdge(1, 2); 
	g->addEdge(1, 3); 
	g->addEdge(1, 4); 
	g->addEdge(2, 3);
	g->addEdge(3, 4);
	cout <<"DFS : " <<endl;
	g->dfs();      
  cout<<endl;
  delete g;
}
