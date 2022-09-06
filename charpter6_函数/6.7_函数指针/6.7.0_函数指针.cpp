#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//函数指针指向的函数，而非对象
bool lengthCompare(const string &s1, const string &s2)
{
    return s1.size() > s2.size();
}
void test1()
{
    //声明函数指针，用指针替换函数名即可
    bool (*pf)(const string &, const string &); //未初始化

    //使用函数指针
    pf = lengthCompare;              // pf指向名为lengthCompare的函数
    pf = &lengthCompare;             // pf指向名为lengthCompare的函数，与15行等价
    bool b1 = pf("dajsk", "adaskj"); //调用pf指向的函数

    //在指向不同函数类型的指针不存在转换规则
    char cstringCompare(const char &, const char &);
    // pf = cstringCompare;错误，形参类型不匹配
    int length(const string &, const string &);
    // pf = length;错误，返回类型不匹配
}

//函数指针形参
//不能定义函数类型的形参，但是可以是指向函数的指针
void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &)){}
// void useBigger(const string &s1,const string &s2, bool (*pf)(const string &, const string &));和上行等价
void test2()
{
    //自动将lengthCompare转换成指针
    useBigger("dsajk", "dasjk", lengthCompare);
}

//简化函数指针使用的代码
typedef bool func(const string &, const string &);
typedef decltype(lengthCompare) func2;
typedef bool (*func3)(const string &, const string &);
typedef decltype(lengthCompare) *func4;

//返回指向函数的指针
using F = int(int *, int);
using PF = int (*)(int *, int);
PF f(int);
// F f1(int);错误
// F *f1(int);
// int (*f1(int))(int *ptr, int i);
auto f1(int) -> int (*)(int *, int);
decltype(lengthCompare) *getFunc(const string &s); // decltype作用于某个函数时，返回的是函数类型，所以要显式加上*告知返回的是指针

//练习题6.7
int fun(int i, int j);
int add(int i, int j)
{
    return i + j;
}
void exer()
{
    vector<decltype(fun) *> v;
    v.push_back(add);
    cout << v[0](1, 2) << endl;
}
int main(int argc, const char *argv[])
{
    exer();
    return 0;
}