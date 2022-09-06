#include <iostream>
#include <string>
using namespace std;

// C++11
//常量表达式，值不会改变且编译过程就能得到计算结果的表达式
void test1()
{
    // constexpr 用来验证是不是常量表达式；
    //一般来说，如果你认定变量是一个常量表达式，你就声明称constexpr
    constexpr int a = 12;

    // constexpr和指针，constexpr仅对指针有效，与指针所指的对象无关
    const int *p1 = nullptr;     //底层指针
    constexpr int *p2 = nullptr; //顶层指针
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}