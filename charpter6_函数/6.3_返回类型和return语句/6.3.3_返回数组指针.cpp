#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//因为数组不能拷贝，所以不能返回数组，但是可以返回数组的指针和引用
//定义繁琐，可以用类型别名
typedef int arrT[10]; //等价定义：using arrT = int[10]
arrT *func(int i){};  //返回一个指向含有十个整数的指针
void test1()
{
}

//声明一个返回数组指针的函数
int (*func(int i))[10]{};
void test2()
{
    int arr[10];
    int *p1[10];         //含有是个int指针的数组
    int(*p2)[10] = &arr; // p2是一个指针，指向含有10个整数的数组
}

//使用尾置返回类型
auto func(int i) -> int (*)[10] {}
void test3()
{
}

//使用decltype
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
decltype(odd) *arrPtr(int i)//decltype不负责把数组类型转换成对应的指针
{
    return (i % 2) ? &odd : &even;
}

string (&(exer6_36()))[10];

typedef string Text[10];
Text &exer6_37(char c);
auto exer6_37() -> string (&)[10];
string text[];
decltype(text) &exer6_37(int i);

int main(int argc, const char *argv[])
{
    test1();
    return 0;
}