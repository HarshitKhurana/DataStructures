
#include"BTree.cpp"
#include"BTNode.h"

void dfs ()
{
  cout <<"[*] Insert the tree in DFS format"<<endl;
  BTNode<int> *root = inputDataDFS();
  cout <<"[*] The InOrder DFS representation of Tree formed is as : "<<endl;
  printDataDFS(root);
  cout<<endl;
  return;
}

void bfs()
{
  return;
}

void graphical()
{
  return;
}


void help()
{
  cout <<"[*] Select as follows : "<<endl;
  cout << "\t 1. for taking input and printing in DFS Format"<<endl;
  cout << "\t 2. for taking input and printing in BFS Format"<<endl;
  cout << "\t 3. for taking input and printing in graphical Format"<<endl;
  cout << "\t 9. To Quit"<<endl;
}

int main( int argc,  char *argv[]){
  int choice;
  while (1){
    help();
    cin>>choice;
    switch (choice)
    {
        case 1:
          dfs();
          break;
        case 2:
          bfs();
          break;
        case 3:
          graphical();
          break;
        case 9:
          return 0;
        default:
          cerr <<"[#] Not a valid option, try again..."<<endl;
          break;
    }
  }
}
