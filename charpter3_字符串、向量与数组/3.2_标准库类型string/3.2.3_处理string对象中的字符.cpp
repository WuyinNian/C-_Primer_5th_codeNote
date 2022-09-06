#include <iostream>
#include <string>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::string;

//处理每个字符，使用C++11定义的基于范围的for语句
//不需要改变遍历序列的大小
void test1()
{
    //访问字符串中的字符
    string s = "hello world!";
    for (auto c : s)
        cout << c;
    cout << endl;

    //改变字符串中的字符
    for (auto &c : s)
    {
        c = toupper(c);
        cout << c;
    }
    cout << endl;

    //处理一部分字符，下标符[]和迭代器（后面介绍）
    s[5] = ',';
    for (auto c : s)
        cout << c;
    cout << endl;

    //使用下标进行迭代
    s[5] = ' ';
    for (decltype(s.size()) i = 0; i != s.size() && !isspace(s[i]); i++)
    {
        s[i] = tolower(s[i]);
        cout << s[i];
    }
    cout << endl;
}

//使用下标执行随机访问
//把十进制数转换成十六进制数
void test2()
{
    const string hexdigitals = "0123456789ABCDEF";
    string result;
    string::size_type n;
    while (cin >> n)
    {
        if (n < hexdigitals.size())
            result += hexdigitals[n];
        else
            break;
    }
    cout << result << endl;
}

//练习题
void exer3_6()
{
    string s = "nianwuyin";
    for (auto &c : s)
    {
        c = 'X';
        cout << c;
    }
    cout << endl;
    for (char &c : s)
    {
        c = 'Y';
        cout << c;
    }
    cout << endl;
}
void exer3_10()
{
    string s = "hello,world!";
    for (auto &c : s)
    {
        if (!ispunct(c))
            cout << c;
    }
    cout << endl;
}
int main(int argc, const char *argv[])
{
    exer3_10();
    return 0;
}