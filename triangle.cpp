#include "triangle.h"
#include <iostream>
#include <cmath>

Triangle::Triangle(double side1, double side2, double side3)
    : s_a(side1), s_b(side2), s_c(side3), m_id(0), m_userAnswer(0)
{
    // 构造时顺便算出正确答案（面积）
    m_correctAnswer = Getmianji();
}

void Triangle::chang(double s1, double s2, double s3)
{
    s_a = s1;
    s_b = s2;
    s_c = s3;
    // 三边变了，正确答案要跟着重新算
    m_correctAnswer = Getmianji();
}

double Triangle::GetA() const
{
    return s_a;
}

double Triangle::GetB() const
{
    return s_b;
}

double Triangle::GetC() const
{
    return s_c;
}

void Triangle::out() const
{
    std::cout << "题号" << m_id << ": 三角形(" << s_a << "," << s_b << "," << s_c << ")"
              << "  正确答案(面积) = " << m_correctAnswer << std::endl;
}

double Triangle::Getzhouchang() const
{
    return s_a + s_b + s_c;
}

double Triangle::Getmianji() const
{
    double p = (s_a + s_b + s_c) / 2.0;
    double areaSquare = p * (p - s_a) * (p - s_b) * (p - s_c);
    if (areaSquare < 0) {
        return 0.0;
    }
    return std::sqrt(areaSquare);
}

void Triangle::type() const
{
    const double eps = 1e-9;

    if (s_a + s_b <= s_c || s_a + s_c <= s_b || s_b + s_c <= s_a) {
        std::cout << "这不是三角形！" << std::endl;
        return;
    }

    bool isRight = std::fabs(s_a * s_a + s_b * s_b - s_c * s_c) < eps ||
                   std::fabs(s_a * s_a + s_c * s_c - s_b * s_b) < eps ||
                   std::fabs(s_b * s_b + s_c * s_c - s_a * s_a) < eps;

    if (isRight) {
        std::cout << "这是一个直角三角形！" << std::endl;
        return;
    }

    bool isAcute = s_a * s_a + s_b * s_b > s_c * s_c &&
                   s_a * s_a + s_c * s_c > s_b * s_b &&
                   s_b * s_b + s_c * s_c > s_a * s_a;

    if (isAcute) {
        std::cout << "这是一个锐角三角形！" << std::endl;
    } else {
        std::cout << "这是一个钝角三角形！" << std::endl;
    }
}

// ===== 题目相关操作（部分类：三角形题目类）=====

void Triangle::setQuestion(int id)
{
    m_id = id;
}

int Triangle::getId() const
{
    return m_id;
}

void Triangle::inputAnswer(double ans)
{
    m_userAnswer = ans;
}

double Triangle::calculateAnswer()
{
    // 计算得到正确答案
    m_correctAnswer = Getmianji();
    return m_correctAnswer;
}

double Triangle::getCorrect() const
{
    return m_correctAnswer;
}

bool Triangle::isRight() const
{
    // 浮点比较用容差，用户输入近似答案也能判对
    return std::fabs(m_userAnswer - m_correctAnswer) < 0.01;
}
