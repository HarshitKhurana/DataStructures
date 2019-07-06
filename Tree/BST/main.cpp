
#include"BSTree.cpp"

void help()
{
  cout <<"[*] Select as follows : "<<endl;
  cout << "\t 1. For Insertion "<<endl;
  cout << "\t 2. For Searching "<<endl;
  cout << "\t 3. For Deletion  "<<endl;
  cout << "\t 4. For Printing "<<endl;
  cout << "\t 9. To Quit"<<endl;
}

void clearScreen()
{
  cout << "\033[2J\033[1;1H";   // Special character for clearscreen.
  return;
}


int main( int argc,  char *argv[]){
  int choice, type , element;
  int a;
  cout <<"[*] Enter first element to initialise BST : ";
  cin>>a;
  BSTree<int> *root = new BSTree<int>(a);
  clearScreen();
  while (1){
    help();
    cin>>choice;
    switch (choice)
    {
        case 1:
          cout <<"[*] Enter Element to insert : ";
          cin>>element;
          insert(root,element);
          cout <<"[*] Element inserted successfully"<<endl;
          break;
        case 2:
          cout <<"[*] Enter Element to search : ";
          cin>>element;
          cout << "[*] Element Exists : "<< search(root,element)<<endl;
          break;
        case 3:
          cout <<"[*] Enter Element to delete : ";
          cin>>element;
          remove(root,element);
          cout <<"[*] Element deleted successfully"<<endl;
          break;
        case 4:
          cout << "\t Select type - 0 for Pre-Order , 1 for In-Order and 2 for Post-Order (default In-Order)"<<endl;
          cin >>type;
          if ( (type != 0) || (type != 1) || (type != 2) )
            type = 0;
          print(root,type);
          break;
        case 9:
          return 0;
        default:
          cerr <<"[#] Not a valid option, try again..."<<endl;
          break;
    }
  }
}
