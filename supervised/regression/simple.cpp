#include<iostream>
#include<Eigen>

using namespace std;
using namespace Eigen;
int main(){
  // features
  Matrix<double, 3,2> X;
  X << 1,1,
    1,2,
    1,3;
  // target values
  Vector3d Y;
  Y << 1,2,2;

  // compute the parameter values theta
  Vector2d theta = ((X.transpose()*X).inverse())*(X.transpose()*Y);
  cout << theta << endl << endl;
  
  return 0;
}
