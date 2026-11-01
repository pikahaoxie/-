#ifndef MORESHAPE_H
#define MORESHAPE_H

#include"Shape.h"

class Circle:public Shape {
    private:
        double radius; // 圆的半径
    public:
        Circle();
        void getshape() override; // 生成随机的圆
        double getMjAnswer() const override; // 获取正确答案（面积）
        double getZcAnswer() const override; // 获取正确答案（周长）
        void printquestion() const override; // 打印问题

};

class Rectangle:public Shape {
    private:
        double length; // 长方形的长度
        double width;  // 长方形的宽度
    public:
        Rectangle();
        void getshape() override; // 生成随机的长方形
        double getMjAnswer() const override; // 获取正确答案（面积）
        double getZcAnswer() const override; // 获取正确答案（周长）
        void printquestion() const override; // 打印问题
};

class Square:public Shape {
    private:
        double side; // 正方形的边长
    public:
        Square();
        void getshape() override; // 生成随机的正方形
        double getMjAnswer() const override; // 获取正确答案（面积）
        double getZcAnswer() const override; // 获取正确答案（周长）
        void printquestion() const override; // 打印问题
};

class Triangle:public Shape {
    private:
        double side1; // 三角形的边长1
        double side2; // 三角形的边长2
        double side3; // 三角形的边长3
    public:
        Triangle();
        void getshape() override; // 生成随机的三角形
        double getMjAnswer() const override; // 获取正确答案（面积）
        double getZcAnswer() const override; // 获取正确答案（周长）
        void printquestion() const override; // 打印问题
};

class Trapezoid:public Shape {
    private:
        double base1; // 梯形的底边1
        double base2; // 梯形的底边2
        double height; // 梯形的高
    public:
        Trapezoid();
        void getshape() override; // 生成随机的梯形
        double getMjAnswer() const override; // 获取正确答案（面积）
        double getZcAnswer() const override; // 获取正确答案（周长）
        void printquestion() const override; // 打印问题
};
#endif