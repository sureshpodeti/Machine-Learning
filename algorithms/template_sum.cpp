#include<iostream>

using namespace std;

template<class T>
T sum(T a, T b){
  T result = a+b;
  return result;
}

template<class T>
class Sum{
  T x, y;
public:
  Sum(T a, T b){
    x = a;
    y = b;
  }
  T sum();
};

template<class T> T Sum<T>::sum(){
  T s = x + y;
  return s;
}


// takes array of elements and returns sum
template<class T> T sum(T *A ){
  T result = A[0];
  int size = sizeof(A)/sizeof(T);
  cout << "size:" << size << endl;
  for(int i = 1; i<size;i++){
    result += A[i];
  }
  return result;
}



int main(){
  cout << sum<int>(10,20) << endl;
  cout << sum<float>(10.20, 30.45) << endl;
  Sum<int> s(24,67);
  cout << "sum from class:" << s.sum() << endl;
  int A[]{1,2,3,4,5,6};
  cout << "array sum:" << sum<int>(A) << endl;
  return 0;
}
