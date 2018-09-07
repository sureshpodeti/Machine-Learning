#include<iostream>
#include<iomanip>
using namespace std;

struct Person{
  int age;
  float salary;
};
int main(){
  /*
  Person *p = new Person[2];
  p->age = 25;
  p->salary = 34500.69;
  
  (p+1)-> age = 20;
  (p+1)-> salary = 23456.89;

  cout  << p->age << "-" << p->salary << endl;
  cout << (p+1)->age << "-" << (p+1)->salary << endl;
  */
  Person *p = new Person;
  p->age = 23;
  p->salary = 23456.00;

  cout << p->age << "-" << p->salary << endl;
  
   
  return 0;
}
