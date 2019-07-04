
#include"HashMap.cpp"
#include<stdlib.h>

void help()
{
  cout << "[*] Enter as follows : "<<endl;
  cout << "\t1. Insert a key-value pair" <<endl;
  cout << "\t2. Update a key-value pair" <<endl;
  cout << "\t3. Delete a key-value pair" <<endl;
  cout << "\t4. Print the key-Value pair for key provided by user" <<endl;
  cout << "\t5. Print all key-Value pairs present" <<endl;
  cout << "\t6. Print current Number of 'Key-value' pairs and Load Factor of HashMap" <<endl;
  cout << "\t9. To Quit" <<endl;
  return;
}

void clearScreen()
{
  cout << "\033[2J\033[1;1H";   // Special character for clearscreen.
  return;
}

int main( int argc,  char *argv[]){

  int sizeOfHashMap = 5;
  string key , value;

  HashMap<string, string> hashMapObject(sizeOfHashMap) ;
  int choice = 11 ;

  clearScreen();      // to clear screen
  cout << "\t\t\t\t\t\tHashMap Code\n"<<endl;

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
        hashMapObject.insert(key , value) ; 
        break;
      case 2:
        cout << "\t[*] Enter Key to update : ";
        cin>>key;
        cout << "\t[*] Enter value to update : ";
        cin>>value;
        hashMapObject.update(key , value) ; 
        break;
      case 3:
        cout << "\t[*] Enter Key to delete : ";
        cin>>key;
        hashMapObject.remove(key) ; 
        break;
      case 4:
        cout << "\t[*] Enter Key to look out for: ";
        cin>>key;
        hashMapObject.printThisObject(key);
        break;
      case 5:
        hashMapObject.printAllObjects();
        break;
      case 6:
        cout << "[*] Load Factor of HashMap : "<<hashMapObject.getLoadFactor()<<endl;
        cout << "[*] Currently number of 'Key-Value' pairs stored in HashMap : "<<hashMapObject.getSize()<<endl;
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
