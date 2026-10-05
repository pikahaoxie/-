#ifndef TRIANGLE_H
#define TRIANGLE_H
class Triangle {
private:
    double s_a;
    double s_b;
    double s_c;
    int m_id;               // 题目编号（部分类：三角形题目类）
    double m_userAnswer;    // 用户答案
    double m_correctAnswer; // 正确答案（面积）

public:
    Triangle(double side1, double side2, double side3);
    void chang(double s1, double s2, double s3);
    double GetA() const;
    double GetB() const;
    double GetC() const;
    void out() const;
    double Getzhouchang() const;
    double Getmianji() const;
    void type() const;

    // 题目相关操作（按实验要求加入的成员对应的操作）
    void setQuestion(int id);         // 设置题目编号
    int getId() const;                // 获取题目编号
    void inputAnswer(double ans);     // 输入用户答案
    double calculateAnswer();         // 计算得到正确答案
    double getCorrect() const;        // 获取正确答案
    bool isRight() const;             // 判断对错
};
    #endif
