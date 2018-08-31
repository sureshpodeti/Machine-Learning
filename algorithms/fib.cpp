#include<iostream>

using namespace std;

int fib(int n){
  if(n==0 || n==1){
    return(n);
  }
  // create an array length n
  int *A = new int[n];
  A[0] = 0;
  A[1] = 1;
  for(int i=2;i<=n;i++){
    A[i] = A[i-1] + A[i-2];
  }
  return(A[n]);
  
}
int main(){
  int n;
  cin >> n;
  cout << fib(n) << endl;
 
}
