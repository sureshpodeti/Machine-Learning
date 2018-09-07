#include<iostream>

using namespace std;


template <class T> T GetMax (T a, T b) {
  T result;
  result = (a>b)?a:b;
  return(result);
}

template < class T, class U> 
T display( U b){
  cout << b << endl;

}

int main(){
  int i = 5, j = 6;
  cout << GetMax<int>(i,j) << endl;
  cout << GetMax<char>('a', 'b') << endl;
  display<void,string> ("suresh podeti");
  return 0;
}
