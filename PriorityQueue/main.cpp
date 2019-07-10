
#include "Person.cpp"

#define print(x,y) cout <<"\t"<<x<<" : "<<y<<endl

void help()
{
  cout << "[*] Enter as follows : "<<endl;
  cout << "\t1. Insert a Person in Priority Queue" <<endl;
  cout << "\t2. Print entire Priority Queue" <<endl;
  cout << "\t3. Print number of objects in Priority Queue" <<endl;
  cout << "\t4. Print top of Priority Queue" <<endl;
  cout << "\t5. Remove top of Priority Queue" <<endl;
  cout << "\t9. To Quit" <<endl;
  return;
}

void clearScreen()
{
  cout << "\033[2J\033[1;1H";   // Special character for clearscreen.
  return;
}

// Take a copy of priorityQ and print it while popping elements
void printQ( priority_queue<Person, vector<Person>, Comparison> temp)
{
  cout << "[*] All Elements are as : "<<endl;
  while ( !temp.empty())
  {
    Person obj = temp.top();
    print (obj.getName() , obj.getAge());
    //cout << "\t"<<obj.getName() << " : " << obj.getAge()<<endl;
    temp.pop();
  }
  cout << endl;
  return;
}

int main( )		{
  string name ;
  int age , choice;

  priority_queue<Person, vector<Person>, Comparison> pq;

  clearScreen();
 while (true) 
 {
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
        {
          cout << "\t[*] Enter Name of Person : ";
          cin>>name;
          cout << "\t[*] Enter age of Person : ";
          cin>>age;
          Person *p = new Person(name , age);
          pq.push(*p); 
          break;
        }
      case 2:
        {
          printQ(pq);
          break;
        }
      case 3:
        {
          cout << "[*] Number of objects in Priority Queue : "<<pq.size() <<endl;
          break;
        }
      case 4:
        {
          Person tempObj = pq.top();
          cout << "[*] Top Object in Priority Queue : "<<tempObj.getName()<<","<<tempObj.getAge() <<endl;
          break;
        }
      case 5:
        {
          cout << "[*] Removing top Object from Priority Queue" <<endl;
          pq.pop();
        }
        break;
      case 9:
        return 0;
      default:
        {
          cout << "\t[#] That ain't an option, try again..."<<endl;
          break;
        }
    }
  }
}
