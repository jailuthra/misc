#include<iostream>

using namespace std;

class Rectangle {
    int l,b;
  public:
    Rectangle (int, int);
    int area () { return l*b; }
};

Rectangle::Rectangle (int x, int y) {
    l = x;
    b = y;
}

int main() {
    Rectangle rect (3,4);
    Rectangle rect2 (5,7);
    cout << "rect area: " << rect.area() << endl;
    cout << "rect2 area: " << rect2.area() << endl;
    return 0;
}