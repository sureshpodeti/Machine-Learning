#include<iostream>
#include<iomanip> // this library must be imported

using namespace std;

int main(){
  //using setw function to set the width of output
  cout << setw(10) << "ten" << endl;

  // using setfill function to fill rest of width
  cout << setfill('*') << setw(80) << "-" << endl;

  // using setprecision to set precision
  cout << setprecision(3) << 2.1768 << endl;

  return 0;
}
