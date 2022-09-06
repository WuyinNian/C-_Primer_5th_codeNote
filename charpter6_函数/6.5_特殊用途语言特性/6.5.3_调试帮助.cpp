#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

// assert预处理宏，定义在cassert头文件中，由预处理器管理
// asser(expr)，为假终止程序并输出信息，为真，什么也不做
void test1()
{
}

// NDEBUG预处理变量，如果定义了NDUBUG，那么asser什么也不做
void print(const int ia[], size_t size)
{
#ifndef NDEBUG
    cerr << __func__ << ":array size is" << size << endl; //__func__是const char静态数组，用于存放函数的名字
#endif
}
// __FILE__ 存放文件名的字符串字面值
// __LINE__ 存放当前行号的整型字面值
// __TIME__ 存放文件编译时间的字符串字面值
// __DATE__ 存放文件编译日期的字符串字面值
void test2()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}