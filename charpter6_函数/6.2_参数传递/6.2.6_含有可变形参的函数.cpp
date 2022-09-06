#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//处理不同数量实参的函数
// initializer_list形参，标准库类型
void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); *beg++)
    {
        cout << *beg << " ";
    }
    cout << endl;
}
void error_msg(error_code e, initializer_list<string> list)
{
    cout << e.message() << ",";
    for (auto &elm : list)
    {
        cout << elm << " ";
    }
    cout << endl;
}
void test1(string s1, string s2)
{
    if (s1 != s2)
    {
        error_msg(error_code(), {"funcx", s1, s2});
    }
    else
    {
        error_msg(error_code(), {"funcx", "okay"});
    }
}

//省略符形参，一般用于与C函数交互的程序
void foo(int i,...);
void foo(...);


int main(int argc, const char *argv[])
{
    test1("xu", "xu");
    return 0;
}