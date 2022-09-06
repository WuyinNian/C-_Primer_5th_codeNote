#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//聚合类使用户可以直接访问其成员，并且具有特殊的初始化语法形式。
/*
    特点：
    1.所有成员都是public
    2.没有定义构造函数
    3.没有类内初始值
    4.没有基类，也没有virtual函数
*/
void test1()
{
    struct Data
    {
        int val;
        string s;
    };

    Data val1 = {0, "Anna"};//可以用花括号初始化聚合类的数据成员，初始化的顺序要和声明的顺序一致
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}