#include <iostream>
#include <string>
using namespace std;

//类型转换
void test1()
{
    //非布尔类型的算术值赋给bool类型：if 0 false, else 1
    bool a = 42;
    cout << a << endl; // 1

    // bool值赋给非bool类型，true=1，false=0
    int i = a;
    cout << i << endl; // 1

    //浮点型=>整型，取整数部分
    i = 3.14;
    cout << i << endl; // 3

    //整型=>浮点型，小数部分记为0
    //如果整型所占空间超过浮点类型的容量，精度损失
    double pi = i;
    float f = i;
    cout << pi << endl; // 3
    cout << f << endl;  // 3
    printf("%f\n", pi); // 3.000000  MacBook Air M1, VSCode 1.69, clang 13.1.6
    printf("%f\n", f);  // 3.000000

    //赋给无符号类型一个超过他范围的值, 实际的值是（-1）% 256 所得的余数
    unsigned char c = -1;
    cout << sizeof(char) << endl; // 1 byte
    cout << (int)c << endl;       // 255

    //赋给带符号类型一个超过他范围的值,结果是未定义的
    char cc = 128;
    cout << (int)cc << endl; //-128
    cc = 129;
    cout << (int)cc << endl; //-127
}

//含有无符号类型的表达式
//带符号类型 和 无符号类型不要混用
void test2()
{
    unsigned u = 10;
    int i = -42;
    cout << i + i << endl; //-84
    //先将有符号数转换为无符号数再相加，-42 % 2^32 = 4294967254
    cout << sizeof(int) << endl;
    cout << i + u << endl; // 4294967264

    unsigned u1 = 42, u2 = 10;
    cout << u1 - u2 << endl; // 32
    //保证结果不是负数，将-32 % 2^32 = 4294967264
    cout << u2 - u1 << endl; // 4294967264
}

//练习
void exer()
{
    unsigned u1 = 10, u2 = 42;
    int i1 = 10, i2 = 42;

    cout<<u1-u2<<endl;//-32 % 2^32 = 4294967264
    cout<<u2-u1<<endl;//32

    cout<<i1-i2<<endl;//-32
    cout<<i2-i1<<endl;//32

    cout<<i1-u1<<endl;//0
    cout<<u1-i1<<endl;//0
}
int main(int argc, const char *argv[])
{
    exer();
    return 0;
}