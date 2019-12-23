
#include "graph.h"

int main( int argc,  char *argv[])
{

  int nodes = 6;
  bool uniDirectional = true;
  cout << "Graph 1"<<endl;
  Graph *g = new Graph(nodes , uniDirectional);
	g->addEdge(5, 2); 
	g->addEdge(5, 0); 
	g->addEdge(4, 0); 
	g->addEdge(4, 1); 
	g->addEdge(2, 3); 
	g->addEdge(3, 1);
	cout <<"DFS  uniDirectional-"<<uniDirectional <<endl;
  g->dfs();      
  cout<<endl;
  cout <<"BFS uniDirectional-"<<uniDirectional<<" with start node 0 : " <<endl;
  g->bfs(0);      
  cout<<endl;
  cout <<"topological Sort uniDirectional-"<<uniDirectional<<endl;
	g->topologicalSort();
  cout<<endl;
  delete g;

  cout <<endl<<"*******************************************************"<<endl;
  uniDirectional = false;
  g = new Graph(nodes , uniDirectional);
  cout << "Graph 2"<<endl;
  g->addEdge(0, 1); 
	g->addEdge(0, 4); 
	g->addEdge(1, 2); 
	g->addEdge(1, 3); 
	g->addEdge(1, 4); 
	g->addEdge(2, 3);
	g->addEdge(3, 4);
  cout <<"DFS  uniDirectional-"<<uniDirectional <<endl;
  g->dfs();      
  cout<<endl;
  cout <<"BFS uniDirectional-"<<uniDirectional<<" with start node 0 : " <<endl;
  g->bfs(0);      
  cout<<endl;
  cout <<"topological Sort uniDirectional-"<<uniDirectional<<endl;
  g->topologicalSort();
  cout<<endl;
  delete g;
}
