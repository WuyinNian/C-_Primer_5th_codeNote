#include <iostream>
#include <string>
using namespace std;
void test1()
{
    const double pi = 3.14;
    // double *p = &pi;错误，普通指针无法指向常量对象
    const double *cp = &pi;
    // *cp = 3; 错误，不能赋值

    //类型匹配的一个例外，常量指针指向非常量对象（const int * 指向 int * ）
    int a = 2;
    const int *r = &a;

    //对常量引用和指向常量的指针一样，自以为是地指向了一个常量（实际上可能是个非常量），所以自觉地不改变其值
    // *r = 3;
}

//指针是对象，而引用不是，所以允许把指针本身定为常量
void test2()
{
    int a = 99;
    int *const ptr_a = &a;//不变的是ptr_a的地址值，而不是a
    int b = 2;
    *ptr_a = 98;
    // ptr_a = &b;错误

    const double pi = 3.14;
    const double *const ptr_pi = &pi;//指向常量对象的常量指针，
    double c = 9.9;
    // ptr_pi = &c;错误

}
int main(int argc, const char * argv[]){
    test1();
    return 0;
}