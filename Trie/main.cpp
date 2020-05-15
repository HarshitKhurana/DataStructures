
#include "Trie.cpp"

void help()
{
  cout << endl<<"\t\t\t Trie"<<endl;
  cout <<"[*] Select as follows : "<<endl;
  cout << "\t 1. For Insertion "<<endl;
  cout << "\t 2. For Searching "<<endl;
  cout << "\t 3. For finding prefix"<<endl;
  cout << "\t 4. To clearScreen"<<endl;
  cout << "\t 9. To Quit : ";
}

void clearScreen()
{
  cout << "\033[2J\033[1;1H";   // Special character for clearscreen.
  return;
}


int main( int argc,  char *argv[]){

    clearScreen();
    Trie t;

    while (true)    {
        int option;
        help();
        cin>>option;
        string s;
        switch(option)
        {
          case 1:
            cout <<"[*] Enter value to insert: ";
            cin>>s;
            t.insert(s);
            cout <<"[*] Value inserted successfully in Trie"<<endl;
            break;
          case 2:
            cout << "[*] Enter string to search in Trie: ";
            cin >> s;
            if ( t.search(s) )
                cout << "[*] String present in trie" << endl;
            else
                cout << "[*] String not present in trie" << endl;
            break;
          case 3:
            cout << "[*] Enter prefix to search in Trie: ";
            cin >> s;
            if ( t.startsWith(s) )
                cout << "[*] Prefix present in trie" << endl;
            else
                cout << "[*] Prefix not present in trie" << endl;
            break;
          case 4:
            clearScreen();
            break;
         case 9:
            return 0;
          default:
            cout <<"\t[#] That ain't an option, try again..."<<endl;
            break;
        }
    }
  }
