#include<iostream>
#include<random>
using namespace std;

int main(){
  default_random_engine generator(time(NULL));
  uniform_int_distribution<int> distribution(1,6);
  cout << distribution(generator)<< endl;
  return 0;
}
