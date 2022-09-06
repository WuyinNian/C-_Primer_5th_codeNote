#include <iostream>
#include <string>
using namespace std;
void test1()
{
    typedef double wage;
    typedef wage base, *p;
    using ID = int; // C++11

    //指针、常量、类型别名
    typedef char *ptrchar;
    //指向char的常量指针，const char *p1是错误的理解
    //ptrchar是指向char的指针，const是修饰ptrchar的，所以const修饰的不是char ，char指针，即p1是个char指针被const修饰，故p1为常量指针
    const ptrchar p1 = nullptr;
    const ptrchar *p2 = nullptr; //指向 指向char的常量指针 的指针
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}