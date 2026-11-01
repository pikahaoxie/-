#include "Shape.h"
#include <iostream>


using namespace std;

Shape::Shape() : userAnswer_1(0.0), userAnswer_2(0.0) {}
Shape::~Shape() {}
string Shape::getName() const {
    return name;
}
bool Shape::isRight() const {
    return (abs(userAnswer_1 - getMjAnswer()) < 0.01) && (abs(userAnswer_2 - getZcAnswer()) < 0.01);
}
istream& operator>>(istream& is, Shape& s) {
    cout<<"请用户输入计算的面积";
    is>>s.userAnswer_1;
    cout<<"请用户输入计算的周长";
    is>>s.userAnswer_2;
    return is;
}
