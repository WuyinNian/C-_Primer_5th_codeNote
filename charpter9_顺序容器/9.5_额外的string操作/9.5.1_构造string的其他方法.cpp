#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
using namespace std;

void test1()
{
    const char *cp = "Hello World!!!"; //以空字符结束的数组
    char noNull[] = {'H', 'i'};
    string s1(cp);
    string s2(noNull, 2);
    string s3(noNull); //未定义，noNull不是空字符结尾
    string s4(cp + 6, 5);
    string s5(s1, 6, 5);
    string s6(s1, 6);
    string s7(s1, 6, 20);
    string s8(s1, 16);
}

//一、substr操作
void test()
{
    string s("hello world");
    int pos = 0, n = 5;
    string s1 = s.substr(pos, n); //从pos开始的n个字符
}

//练习题
void exer9_41()
{
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    string s(str.data(), str.size());
    cout << s << endl;
}
void exer9_42()
{
    string s;
    s.reserve(100);
    char c;
    while (cin >> c)
    {
        s.push_back(c);
    }
    cout << s << endl;
}

int main(int argc, const char *argv[])
{
    exer9_41();
    return 0;
}