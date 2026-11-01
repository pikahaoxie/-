#include"Moreshape.h"
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<cmath>
using namespace std;

Circle::Circle(){name="圆形";}
void Circle::getshape(){radius=rand()%10+1;}
double Circle::getMjAnswer() const{return PI*radius*radius;}
double Circle::getZcAnswer() const{return 2*PI*radius;}
void Circle::printquestion() const{
    cout<<"请计算一个半径为"<<radius<<"的圆的面积和周长"<<endl;
}

Rectangle::Rectangle(){name="长方形";}
void Rectangle::getshape(){
    length=rand()%10+1;
    width=rand()%10+1;
}
double Rectangle::getMjAnswer() const{return length*width;}
double Rectangle::getZcAnswer() const{return 2*(length+width);}
void Rectangle::printquestion() const{
    cout<<"请计算一个长为"<<length<<"，宽为"<<width<<"的长方形的面积和周长"<<endl;
}

Square::Square(){name="正方形";}
void Square::getshape(){side=rand()%10+1;}
double Square::getMjAnswer() const{return side*side;}
double Square::getZcAnswer() const{return 4*side;}
void Square::printquestion() const{
    cout<<"请计算一个边长为"<<side<<"的正方形的面积和周长"<<endl;
}

Triangle::Triangle(){name="三角形";}
void Triangle::getshape(){
    bool valid=false;
    while(!valid){
        side1=rand()%10+1;
        side2=rand()%10+1;
        side3=rand()%10+1;
        if(side1+side2>side3 && side1+side3>side2 && side2+side3>side1){
            valid=true;
        }
    }
}
double Triangle::getMjAnswer() const{
    double s=(side1+side2+side3)/2;
    return sqrt(s*(s-side1)*(s-side2)*(s-side3));
}
double Triangle::getZcAnswer() const{return side1+side2+side3;}
void Triangle::printquestion() const{
    cout<<"请计算一个边长为"<<side1<<","<<side2<<","<<side3<<"的三角形的面积和周长"<<endl;
}

Trapezoid::Trapezoid(){name="直角梯形";}
void Trapezoid::getshape(){
    base1=rand()%10+1;
    base2=rand()%10+1;
    height=rand()%10+1;
}
double Trapezoid::getMjAnswer() const{return (base1+base2)*height/2;}
double Trapezoid::getZcAnswer() const{return base1+base2+height+sqrt((base2-base1)*(base2-base1)+height*height);}
void Trapezoid::printquestion() const{
    cout<<"请计算一个底边为"<<base1<<"和"<<base2<<",高为"<<height<<"的直角梯形的面积和周长"<<endl;
}

