#include "questionbank.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

QuestionBank::QuestionBank() : totalQuestions(0), correctAnswers(0) {}//构造函数初始化
QuestionBank::~QuestionBank() {
    for (size_t i = 0; i < shapes.size(); ++i) {
        delete shapes[i]; // 释放每个形状对象的内存
    }
    shapes.clear(); // 清空向量
}

Shape* createRandomShape() {
    int Type = rand() % 5; // 随机选择形状类型
    Shape* shape = nullptr;
    switch (Type) {
        case 0:return new Circle();
        case 1:return new Rectangle();
        case 2: return new Square();
        case 3: return new Triangle();
        case 4: return new Trapezoid();
        default:return nullptr;
    }
}// 创建随机形状对象

void QuestionBank::generateQuestions(int num) {
    totalQuestions = num;
    correctAnswers = 0;
    for (int i = 0; i < num; ++i) {
        Shape* shape = createRandomShape();
        shape->getshape(); // 生成随机形状
        shapes.push_back(shape); // 将形状添加到向量中
    }
    cout << "已生成 " << num << " 道题目。" << endl;
}// 生成题目

void QuestionBank::startQuiz() {
    for (int i = 0; i < shapes.size(); ++i) {
        cout << "第 " << (i + 1) << " 题：" << endl;
        shapes[i]->printquestion(); // 打印问题
        cin >> *shapes[i]; // 输入用户答案
        if (shapes[i]->isRight()) {
            cout << "回答正确！" << endl;
            correctAnswers++;
        } else {
            cout << "回答错误！" << endl;
        }
    }
    cout << "答题结束！总共答对了 " << correctAnswers << " 道题目。" << endl;
    // 实验四需求（6）汇总成绩并输出：成绩=答对题数，平均分=答对比例×100
    double avg = (totalQuestions > 0) ? correctAnswers * 100.0 / totalQuestions : 0.0;
    cout << "成绩汇总：答对 " << correctAnswers << " / " << totalQuestions
         << " 题，平均分 = " << fixed << setprecision(2) << avg << " 分" << endl;
}// 开始答题

void QuestionBank::reviewQuestions() const {
    cout << "回顾题目：" << endl;
    for (int i = 0; i < shapes.size(); ++i) {
        cout << "第 " << (i + 1) << " 题：" << endl;
        shapes[i]->printquestion(); // 打印问题
        cout << "正确答案：面积 = " << fixed << setprecision(2) << shapes[i]->getMjAnswer()
             << ", 周长 = " << fixed << setprecision(2) << shapes[i]->getZcAnswer() << endl;
        if (shapes[i]->isRight()) {
            cout << "你的回答是正确的。" << endl;
        } else {
            cout << "你的回答是错误的。" << endl;
        }
    }
}// 回顾题目