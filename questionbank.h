#ifndef QUESTIONBANK_H
#define QUESTIONBANK_H

#include <string>
#include <vector>
#include "Shape.h"
#include "Moreshape.h"

class QuestionBank {
private:
    std::vector<Shape*> shapes; // 存储题目的向量
    int totalQuestions; // 总题目数
    int correctAnswers; // 正确答案数
public:
    QuestionBank(); // 构造函数
    ~QuestionBank(); // 析构函数
    void generateQuestions(int num); // 生成题目
    void startQuiz(); // 开始答题
    void reviewQuestions() const; // 回顾题目
};
#endif
    
