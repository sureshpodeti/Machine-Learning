#include<iostream>
#include<random>
using namespace std;

int main(){
  // to get random number between 0  to RAND_MAX
  cout << "Random number:" << rand() << endl;

  // to get RAND_MAX
  cout << "RAND_MAX:" << RAND_MAX <<  endl;

  // to get different random number;use seed
  srand(time(NULL));
  cout << "random number between (0-RAND_MAX):"<< rand() << endl;

  // to get random number between 0 to 9
  cout << "random number between (0-9):" << rand()%10  << endl;


  // to get random between 1 to 10
  cout << "random number between(1-10):" << rand()%10+1 << endl;
  return 0;
}
