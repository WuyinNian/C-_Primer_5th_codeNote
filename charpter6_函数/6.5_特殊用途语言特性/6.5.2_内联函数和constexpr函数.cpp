#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//内联函数可以避免函数调用的开销
//将它在每个调用点内联地展开
//一般来说，内联函数用于优化规模较小，流程 直接，频繁调用的函数
inline const string &shorterStr(const string &s1, const string &s2)
{
    return (s1.size() < s2.size()) ? s1 : s2;
}
void test1()
{
}

// constexpr函数,能用于常量表达式的函数
//规定：
// 1.返回值类型和形参类型必须是字面值类型
// 2.有且只有一条return语句
constexpr int new_sz()
{
    return 42;
}
constexpr size_t scale(size_t cnt)
{
    return new_sz() * cnt;
}
void test2()
{
    constexpr int foo = new_sz(); //编译器把对constexpr函数的调用替换成其结果值，constexpr函数被隐式指定为内联函数
    int arr[scale(2)];
    int i = 2;
    int a2[scale(i)];//constexpr函数不一定返回常量表达式
}
int main(int argc, const char *argv[])
{
    test2();
    return 0;
}