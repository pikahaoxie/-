// 实验3 题目1：题库类组合三角形题目类（简单几何图形题库系统）
// 三角形题目类 = Triangle + 题目编号/用户答案/正确答案（部分类）
// 题库类（整体类）组合多个三角形题目类对象
// 测试入口：创建题库、增删改查题目、做题判分
#include <iostream>
#include "triangle.h"
#include "questionbank.h"

int main()
{
    // 1. 创建题库（整体类）—— 初始化
    QuestionBank bank("几何题库");

    // 2. 创建三角形题目（部分类）并设置题目编号，加入题库
    Triangle t1(3, 4, 5);   t1.setQuestion(1);
    Triangle t2(2, 3, 4);   t2.setQuestion(2);
    Triangle t3(6, 8, 10);  t3.setQuestion(3);
    bank.addQuestion(t1);
    bank.addQuestion(t2);
    bank.addQuestion(t3);

    std::cout << "===== 题库初始状态 =====" << std::endl;
    bank.showAll();

    // 3. 修改：改题库名称
    bank.changeName("我的几何题库");
    std::cout << "\n===== 修改题库名称后 =====" << std::endl;
    bank.showAll();

    // 4. 修改：把题目2 的三边改成 5,12,13
    std::cout << "\n===== 修改题目2的三边为(5,12,13) =====" << std::endl;
    if (bank.changeQuestion(2, 5, 12, 13)) {
        Triangle* t = bank.findQuestion(2);
        if (t) {
            std::cout << "修改后，";
            t->out();
            std::cout << "计算得到正确答案 = " << t->calculateAnswer() << std::endl;
        }
    } else {
        std::cout << "修改失败" << std::endl;
    }

    // 5. 做一套题：出题 → 输入答案 → 判分
    std::cout << "\n===== 开始做题 =====" << std::endl;
    bank.doTest();

    // 6. 查询题目
    std::cout << "\n===== 查询题目3 =====" << std::endl;
    Triangle* t3q = bank.findQuestion(3);
    if (t3q) {
        t3q->out();
        std::cout << "题目3正确答案(面积) = " << t3q->getCorrect() << std::endl;
    } else {
        std::cout << "未找到题目3" << std::endl;
    }

    // 7. 删除题目3
    std::cout << "\n===== 删除题目3 =====" << std::endl;
    std::cout << (bank.removeQuestion(3) ? "删除成功" : "删除失败") << std::endl;

    // 8. 最终状态
    std::cout << "\n===== 最终题库状态 =====" << std::endl;
    bank.showAll();

    return 0;
}
