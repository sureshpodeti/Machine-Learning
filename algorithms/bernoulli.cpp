#include<iostream>
#include<random>
#include<ctime>
using namespace std;

int main(){
  // define random generator engine
  default_random_engine generator(time(NULL));

  // define bernoulli distribution 
  bernoulli_distribution distribution(0.5);
  int count = 0;

  // generator random variable
  cout << distribution(generator) << endl;
  for(int i=0;i<1000;i++)if(distribution(generator) == 1)++count;

  cout << count << endl;

  return 0;


}
