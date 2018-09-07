#include<iostream>
using namespace std;

class Rectangle{
  int width, height; //privat members
  public:
  Rectangle(int,int);
  int area(){
    return(width*height);
  }
};



Rectangle::Rectangle(int x, int y){
  width = x;
  height = y;
}
int main(){
  Rectangle rect(3,4);
  cout << rect.area() << endl;

}
