#include<iostream>
#include<random>
#include<ctime>

using namespace std;
int main(){
  default_random_engine generator(time(NULL));
  normal_distribution<double> distribution(0.0,1.0);
  cout << distribution(generator) << endl;
  return 0;
}


