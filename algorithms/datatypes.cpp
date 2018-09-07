#include<iostream>
#include<iomanip>
using namespace std;

int main(){
  bool status(true);
  if(!status){
    cout << "status is true" << endl;
  }else{
    cout << "status is false" << endl;
  }

 
  // setw function allows to set the minimum width of the next output
  cout << setw(10) << "ten" << "four" << endl;
  // padding with some character 
  cout << setfill('*')<< setw(80) << "-" << endl;


  // setting precision
  cout << setprecision(3) << 2.71828 << endl;
  return 0;
}
