#include<iostream>
using namespace std;



template<class T>
class Sum{
  T a, b;
public:
  Sum(T x, T y){
    this->a = x;
    this->b =y;
  }
  T sum();
};

template<class T> T Sum<T>::sum(){
  return this->a + this->b;
}


int main(){
  Sum<int> s(10,20);
  cout << s.sum() << endl;
  return 0;
}
