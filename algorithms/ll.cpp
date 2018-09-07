#include<iostream>
using namespace std;

struct Node{
  string name;
  int age;
  float salary;
};

int main(){
  int n;
  cout << "Enter no.of records you want to insert:";
  cin >> n;
  

  Person *p = new Person;
  p->name = "Suresh Podeti";
  p->age = 25;
  p->salary = 14560.89;
  cout << p->name << "-" << p->age << "-" << p->salary << endl;
  
  return 0;
}
