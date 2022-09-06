#include <iostream>
#include <string>

//每个名字需要独立的using声明
// (除非函数太多)不要用using namespace std; (命名污染, "霸权", 使得所有库函数默认都是std这家公司的,
// 其他namespace公司的同名函数就被偷梁换柱了, 并且此时编译器可能不报错的)
// 正确做法:
// 一条条写using std::cin, 后面再省略cin也很方便
using std::cin;
using std::cout;
using std::endl;

//using声明一般不包含在头文件中，为了避免始料未及的名字冲突
void test1()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}