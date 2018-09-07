#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
  // static declaration of arrays 
  int A[]{1,2,3,4};
  int len = sizeof(A)/sizeof(int);
 
  // taking array input
  /*
  len = 3;
  cout << "enter three integers:";
  for(int i=0;i<3;i++)
    cin >> A[i];
  */
  
  //character array
  char name[] = "suresh"; // automatically appends \0 (null character) at the end
  char wife[] {'s', 'o', 'w', 'j', 'a', '\0'};
  
  cout << "len of char array:" << sizeof(name)/sizeof(char) << endl;
  cout << name << "-" << wife <<  endl;
  
  char child[20];
  cout << "write some name:";
  cin >> child;
  cout << sizeof(child)/sizeof(char) << endl;

  string  child_again;
  cout << "enter again name:";
  cin >> child_again;
  cout << child_again.length() << endl; 
  return 0;
}
