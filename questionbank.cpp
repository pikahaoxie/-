#include "questionbank.h"
#include <iostream>

QuestionBank::QuestionBank(const std::string& name)
    : m_name(name), m_score(0), m_average(0)
{
}

std::string QuestionBank::getName() const
{
    return m_name;
}

void QuestionBank::changeName(const std::string& name)
{
    // 修改：改题库名称
    m_name = name;
}

bool QuestionBank::changeQuestion(int id, double a, double b, double c)
{
    // 修改：找到编号对应的题，改它的三边
    Triangle* t = findQuestion(id);
    if (t == nullptr) {
        return false;
    }
    t->chang(a, b, c);
    t->setQuestion(id);
    return true;
}

int QuestionBank::getCount() const
{
    return m_questions.size();
}

void QuestionBank::addQuestion(const Triangle& t)
{
    m_questions.push_back(t);
}

bool QuestionBank::removeQuestion(int id)
{
    for (auto it = m_questions.begin(); it != m_questions.end(); ++it) {
        if (it->getId() == id) {
            m_questions.erase(it);
            return true;
        }
    }
    return false;
}

Triangle* QuestionBank::findQuestion(int id)
{
    for (auto& t : m_questions) {
        if (t.getId() == id) {
            return &t;
        }
    }
    return nullptr;
}

void QuestionBank::doTest()
{
    int rightCount = 0;
    for (auto& t : m_questions) {
        t.out();
        std::cout << "请输入你的答案（面积）: ";
        double ans;
        std::cin >> ans;
        t.inputAnswer(ans);
        if (t.isRight()) {
            std::cout << "  回答正确！" << std::endl;
            rightCount++;
        } else {
            std::cout << "  回答错误，正确答案是 " << t.getCorrect() << std::endl;
        }
    }
    m_score = rightCount;
    m_average = m_questions.empty() ? 0 : 100.0 * rightCount / m_questions.size();
}

void QuestionBank::showAll() const
{
    std::cout << "题库《" << m_name << "》共 " << m_questions.size() << " 题：" << std::endl;
    for (const auto& t : m_questions) {
        t.out();
    }
    std::cout << "成绩: " << m_score << " 分  平均分: " << m_average << std::endl;
}

double QuestionBank::getScore() const
{
    return m_score;
}

double QuestionBank::getAverage() const
{
    return m_average;
}
