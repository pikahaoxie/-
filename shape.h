#ifndef SHAPES_H
#define SHAPES_H
#include<string>

using namespace std;

const double PI = 3.14159265358979323846; // 圆周率常量

class Shape {
protected:
    string name; // 多边形名称
    double userAnswer_1;    // 用户答案面积
    double userAnswer_2;    // 用户答案周长
public:
    Shape();
    virtual ~Shape();
    virtual void getshape() = 0; // 生成随机的多边形
    virtual double getMjAnswer() const = 0; // 获取正确答案（面积）
    virtual double getZcAnswer() const = 0; // 获取正确答案（周长）
    virtual void printquestion() const = 0; // 打印问题
    std::string getName() const; // 获取多边形名称
    bool isRight() const;// 判断用户答案是否正确
    friend istream& operator>>(istream& is,  Shape& s);// 重载输入运算符
};
#endif