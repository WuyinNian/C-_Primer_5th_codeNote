#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//为了确定最佳匹配，编译器将实参类型到形参类型的转换划分成以下等级
//1.精确匹配：实参类型和形参类型相同；实参从数组类型或函数类型转换为对应的指针类型；向实参添加或删除顶层const
//2.通过const的转换实现的匹配
//3.通过类型提升实现的匹配
//4.通过算术类型转换或指针转换实现的匹配
//5.通过类类型转换实现的匹配
void test1()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}