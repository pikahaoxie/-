#include <iostream>
#include "triangle.h"

int main()
{
    Triangle t(3, 4, 5);
    t.out();
    std::cout << "周长：" << t.Getzhouchang() << std::endl;
    std::cout << "面积：" << t.Getmianji() << std::endl;
    t.type();
    return 0;
}
