#ifndef QUESTIONBANK_H
#define QUESTIONBANK_H

#include <string>
#include <vector>
#include "triangle.h"

class QuestionBank {
private:
    std::string m_name;               // 题库名称
    std::vector<Triangle> m_questions;// 组合：包含的所有三角形题目类对象（对象数组）
    double m_score;                   // 所做题目的成绩
    double m_average;                 // 平均分

public:
    QuestionBank(const std::string& name);              // 初始化
    void changeName(const std::string& name);           // 修改：改题库名称
    bool changeQuestion(int id, double a, double b, double c); // 修改：改某道题的三边
    std::string getName() const;                        // 获取名称
    int getCount() const;                               // 获取题目数量
    void addQuestion(const Triangle& t);                // 增加题目
    bool removeQuestion(int id);                        // 删除题目
    Triangle* findQuestion(int id);                     // 查询题目
    void doTest();                                      // 做一套题：出题→输入→判分
    void showAll() const;                               // 输出所有题目
    double getScore() const;                            // 获取成绩
    double getAverage() const;                          // 获取平均分
};

#endif // QUESTIONBANK_H
