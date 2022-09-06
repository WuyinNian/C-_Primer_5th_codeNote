#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//表达式语句：执行表达式并丢弃结果
void test1()
{
    int val = 1;
    val + 5;     //没有什么实际用处的表达式
    cout << val; //一句有用的表达式
}

//空语句，用单个分号表示
//别多写分号，也别漏写分号
void tes2()
{
    string s;
    while (cin >> s && s != "sought")
        ; //空语句
}

//复合语句(块),{}
//一个块就是一个作用域，块不以分号结束
void test3()
{
    int val=1;
    while(val<=10)
    {
        val++;
    }
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}