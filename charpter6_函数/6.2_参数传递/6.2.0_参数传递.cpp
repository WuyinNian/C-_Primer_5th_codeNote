#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//每次调用函数都会重新创建它的形参，并用传入的实惨初始化形参
//引用传递（传引用调用）：引用形参是对应实参的别名
//值传递（传值调用）：当实参的值拷贝给形参时，实参和形参是两个独立的对象
void test1()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}