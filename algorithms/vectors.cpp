#include<iostream>
#include<Eigen>

using namespace std;
using namespace Eigen;

int main(){
  // Vector in eigen is nothing more tha a matrix with a single column
  
  /* ------------------- declaration ------------------*/
  Vector3d A;
   // Vector3d<int, 3,1> B; will not work
  Matrix<float, 3,1> B;


  /* --------- initialization ----------------*/
  A << 1,2,3;
  cout << A << endl << endl;

 
  for(int i=0;i<3;i++)
     B(i) = 1;
  
  cout << B << endl << endl;


  //initialization using constructor
  Vector3f C(1.0f, 2.0f, 3.0f);
  cout << C << endl << endl;

  /* ---------------accessing elements ----------*/
  cout << A(2) << endl << endl;
  

  /*  -- ---- utility functions ------------*/
  Vector3f v1 = Vector3f::Ones();
  Vector3f v2 = Vector3f::Zero();
  Vector4d v3 = Vector4d::Random();
  Vector4d v4 = Vector4d::Constant(2.2);

  cout << v1 << endl << endl;
  cout << v2 << endl << endl;
  cout << v3 << endl << endl;
  cout << v4 << endl << endl;

  /* ------------- Arthmetic operations ---------*/
  cout << v1 + v2 << endl << endl; 

  cout << v1 - v2 << endl << endl;

  //scalar multiplication
  cout << v4*2 << endl << endl;

 
  /* ------------ Relational operators: only equality(==) and inequality(!=)
  relational operators that work with vectors 
   */

  cout << (Vector2f::Ones() *3 == Vector2f::Constant(3)) << endl << endl;


  /*-------------- Matrix-vector multiplication -------------------*/
  // works if matrix and vector dimension agree
  Vector4f v5 = Vector4f(1.0f, 2.0f, 3.0f, 4.0f);
  cout << Matrix4f::Random()*v5 << endl << endl; //works
  

  /* ------- transpose of vector -----------*/
  cout << Vector4d::Random().transpose() << endl << endl;


  /* ---------- common operator: dot prodct, cross product, normalized----------*/
  cout << "dot product:"<< v1.dot(v2) << endl << endl;
  cout<< Vector4i::Constant(2).normalized() << endl << endl;
  cout << v1.cross(v2) << endl << endl;


  /* --------element-wise operations on vectors -------*/
  cout << v1.array() * v2.array() << endl << endl; 
  cout << v1.array().sin() << endl;
  
    return 0;
}
