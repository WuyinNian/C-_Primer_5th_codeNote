#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//函数重载：函数名字相同但是形参列表不同

//重载与const形参
//拥有顶层const形参和没有const顶层的形参无法区分，所以二者不构成重载
int func(int i);  // int func(const int i);二者等价
int func(int *i); // int func(int *const i);二者等价
//底层const构成重载
int func(int &r);
int func(const int &r);
int func(char *p);
int func(const char *p);
void test1()
{
}

// const_cast和重载
const string &shorterStr(const string &s1, const string &s2)
{
    return s1.size() > s2.size() ? s1 : s2;
}
string &shorterStr(string &s1, string &s2)
{
    auto &r = shorterStr(const_cast<const string &>(s1), const_cast<const string &>(s2));
    return const_cast<string &>(r);
}

int main(int argc, const char *argv[])
{
    test1();
    return 0;
}