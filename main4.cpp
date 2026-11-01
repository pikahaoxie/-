// 实验4 题目1：简单几何图形题库系统（多态性与虚函数）
// 基类 Shape 定义虚函数接口，5 个子类（正方形/长方形/圆形/三角形/梯形）各自实现面积与周长计算
// 题库类 QuestionBank 组合 vector<Shape*>（基类指针动态数组）统一管理多种图形题目
// 测试入口：菜单提示 → 输入题目数 → 随机出题 → 逐题输入面积/周长 → 判分 → 成绩汇总 → 回看
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "questionbank.h"

using namespace std;

int main() {
    srand((unsigned int)time(0));   // 随机种子：保证每次运行生成的题目不同

    cout << "==============================================" << endl;
    cout << "     欢迎使用【几何图形练习系统】实验四      " << endl;
    cout << "  题目类型：正方形 / 长方形 / 圆形 / 三角形 / 梯形" << endl;
    cout << "==============================================" << endl;

    QuestionBank bank;                     // 创建题库对象（组合关系：题库拥有题目）

    int num;
    cout << "请输入本次练习的题目数（1~10）：";
    cin >> num;
    if (num < 1 || num > 10) {
        cout << "输入不合法，已按默认 3 题进行。" << endl;
        num = 3;
    }

    bank.generateQuestions(num);           // 随机生成 num 道题目（随机类型 + 随机参数）
    cout << endl << "----- 开始答题 -----" << endl;
    bank.startQuiz();                      // 逐题：显示图形 → 输入面积和周长 → 自动判分

    cout << endl << "----- 题目回看 -----" << endl;
    bank.reviewQuestions();                // 回看所有题目及答案

    cout << endl << "练习结束，谢谢使用！" << endl;
    return 0;
}
