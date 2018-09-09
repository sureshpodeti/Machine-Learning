#include<iostream>
#include<Eigen>

using namespace std;
using namespace Eigen;

  int main(){
    /* -------- matrix declaration -------*/
  Matrix3d A;
  Matrix<int, 3,3> B;

  /* ---------- initialize matrix A  ------*/
  A << 1,0,0,
    0,1,0,
    0,0,1;

  // initialize matrix B
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
      B(j,i) = 0;  // because it is efficient, eigen stores matrices in column-major order by default
  }



  /*  -------printing matrix ---------- */ 
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
      cout << A(j,i) << " ";
    cout << endl;
  }


  //easy way
  cout << A << endl;


  /*  ---------- different types of matrices -------------*/
  Matrix3f C, E, F;
  Matrix4d D, G;

  // Initialize to uniform random value in range [-1,1]
  C = Matrix3f::Random();

  // to intialize to Identity matrix
  D = Matrix4d::Identity();


  // Initialize to all zeros
  E = Matrix3f::Zero();

  // Initializze to all ones
  F = Matrix3f::Ones();

  // Initialize all to constant vlaue 4.5
  G = Matrix4d::Constant(4.5);

  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++)
      cout << G(j, i) << " ";
    cout << endl;
  }
  
  
  /*-------------  Matrix operations; original matrix retains its original value, any operations results in new matrix ---------*/
  Matrix4f M1 = Matrix4f::Random();
  Matrix4f M2 = Matrix4f::Constant(2.2);

  cout << M1 + M2 << endl; // matrix addition

  cout << M1*M2 << endl;  // matrix multiplication
  
  cout << M1 - M2 << endl; // matrix substraction

  // transponse of matrix
  Matrix3d I;
  I << 1,2,3,
    4,5,6,
    7,8,9;

  cout << "\n Tranpose:\n";
  cout << I.transpose() << endl;


  // inverse of matrix
  Matrix3d J = Matrix3d::Identity();
  cout << "\nInverse of matrix\n";
  cout << J.inverse() << endl;


  // Square of each element of the matrix
  // element wise operations to matrix: this is done by asking eigen to treat
  // the matrix as a general array by invoking array() method
  cout << "\nSquaring matrix element wise\n";
  cout << I.array().square() << endl;


  cout << "\nMultiply two matrices element-wise\n";
  Matrix3d K = Matrix3d::Identity();
  cout << "\nMultiplication element wise\n";
  cout << I*K << endl;

  //Relational operations;only (==) and (!=) are only relational operations on matrix
  cout << "two matrices same:" << (M1 == M2) << endl; // it will not work if M1 == M2

  // but, all relational operations are applied on elment wise matrix
  cout << "\ncheck if M1<=M2\n";
  cout << (M1.array() <= M2.array()) << endl;
  
  return 0;
}
