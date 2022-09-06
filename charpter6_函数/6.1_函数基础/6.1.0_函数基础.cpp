#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//返回值类型 函数名 行参列表 函数体
int fact(int val)
{
    int res = 1;
    while (val > 1)
    {
        res *= val--;
    }
    return res;
}

//函数调用
void test1()
{
    int j = fact(5);
    cout << "5! = " << j << endl;

    //形参和实参
    //实参是形参的初始值
    // fact("hello");//错误：const char*不能转换成int
}


int main(int argc, const char *argv[])
{
    test1();
    return 0;
}