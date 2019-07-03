
#include"HashMap.cpp"
#include<stdlib.h>

int main( int argc,  char *argv[]){

  cout << "[*] HashMap Code\n"<<endl;
  int choice = 0 ;
  cout << "Enter as follows : "<<endl;
  cout << "\t1. Insert a key-value pair" <endl;
  cout << "\t2. Update a key-value pair" <endl;
  cout << "\t3. Delete a key-value pair" <endl;
  cout << "\t4. Print all key-Value pairs present" <endl;
  cout << "\t5. To Quit" <endl;
  cin>>choice;

  HashMap<string, string> hashMapObject ;

  while (true)  {
    switch (choice)
    {
      case 1:
        string key , value;
        cout << "Enter Key to insert : ";
        cin>>key;
        cout << "Enter value to insert : ";
        cin>>value;
        hashMapObject.insert(key , value) ; 
        cout << "[*] Inserted pair in HashMap"<<endl;
        break;
      case 2:
        string key , value;
        cout << "Enter Key to update : ";
        cin>>key;
        cout << "Enter value to update : ";
        cin>>value;
        hashMapObject.update(key , value) ; 
        cout << "[*] Updated pair in HashMap"<<endl;
        break;
      case 3:
        string key ;
        cout << "Enter Key to delete : ";
        cin>>key;
        hashMapObject.remove(key) ; 
        cout << "[*] Deleted pair from HashMap"<<endl;
        break;
      case 4:
        hashMapObject.printAllObjects();
        break;
      case 5:
        exit(0);
        break;
      default:
        cout << "That ain't an option"<<endl;
        break;
    }
  }
  return 0;
}
