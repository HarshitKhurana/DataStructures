
#include"Huffman.cpp"
#include<stdlib.h>

void help()
{
  cout << "[*] Enter as follows : "<<endl;
  cout << "\t1. Insert a key-value pair" <<endl;
  cout << "\t2. Print All Nodes " <<endl;
  cout << "\t3. Print HuffMan Codes" <<endl;
  cout << "\t4. Reset (delete all enteries) "<<endl;
  cout << "\t9. To Quit" <<endl;
  return;
}

void clearScreen()
{
  cout << "\033[2J\033[1;1H";   // Special character for clearscreen.
  return;
}

int main( int argc,  char *argv[]){


  Huffman hf;

  clearScreen();      // to clear screen
  cout << "\t\t\t\t\t\t HuffMan Coding\n"<<endl;

  string key; 
  int value , choice; 

  while (true)  {
  help();
  cout << "\n[*] Enter choice: ";
  cin>>choice;
  if ( choice < 1 || choice > 10 )
  {
    cerr <<"[#] Invalid choice, please run again and provide valid input"<<endl;
    exit(1);   // user screwed up
  }
    switch (choice)
    {
      case 1:
        cout << "\t[*] Enter Key to insert : ";
        cin>>key;
        cout << "\t[*] Enter value to insert : ";
        cin>>value;
        hf.insert(key , value) ; 
        break;
      case 2:
        hf.printNodes(); 
        break;
      case 3:
        hf.printCodes(); 
        break;
      case 4:
        hf.reset();
        break;
      case 9:
        exit(0);
        break;
      default:
        cout << "\t[#] That ain't an option, try again..."<<endl;
        break;
    }
  }
  return 0;
}

