#include<iostream>
#include<random>
#include<ctime>

using namespace std;

int main(){
  default_random_engine generator(time(NULL));
  uniform_int_distribution<int> distribution(1,100);
  cout << distribution(generator)<< endl;
  //cout << distribution::b << endl;
  return 0;
}


