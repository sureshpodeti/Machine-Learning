#include<iostream>

using namespace std;

int main(){
  //pointer initialization to null
  int *p = NULL;
  p = new int;
  if(!p){
    cout << "allocation memory failed\n";
  }else{
    *p = 29;
    cout << "value of p:" << *p << endl;
  }

  // Requesting block of memory
  float *r = new float(75.25);
  cout << "value of r:" << *r << endl;

  // requesting block of memory size n
  int n =5;
  int *q = new int[5];
  
  if(!q){
    cout << "allocation of memory failed\n";
  }else{
    for(int i=0; i<n;i++)
      q[i] = i+1;
   
    for(int i =0;i<n;i++)
      cout << q[i] << " ";
    cout << endl;
  }

  // freed the allocated memory
  delete p;
  delete r;
  
  //freed the block of allocated memory
  delete[] q;
}
