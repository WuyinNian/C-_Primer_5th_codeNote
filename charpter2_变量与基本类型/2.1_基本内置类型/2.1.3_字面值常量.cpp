#include <iostream>
#include <string>
using namespace std;

//整型和浮点型字面值
void test1()
{
    int i = 024; //八进制 20
    cout << i << endl;
    i = 0x24; //十六进制 36
    cout << i << endl;

    float f = 3.14;
    cout << f << endl;
    cout<<10.<<endl;//double 10.0
    cout<<0.<<endl;//double 0.0
    cout<<0e0<<endl;//double 0.0
    cout<<.001<<endl;//doubke 0.001000000000000000021
    cout<<10e-2<<endl;//double 0.100000000000000000056
    cout<<3.14159E0<<endl;
}

//字符和字符串字面值
//转义序列见图
void test2()
{

    //末尾‘\0’ 表示空字符
    string s = "1234";              // const char[5] = {1234};
    cout << sizeof("1234") << endl; // 5
}

//指定字面值类型见图
void test3()
{
}

// bool字面值类型
void test4()
{
    bool f = true;
    f = false;
}

//指针字面值类型
void test5()
{
    int *p = nullptr;
    cout << p << endl;
}

//练习
void exer()
{
    cout<<"2M\n";
    cout<<"2\tM\n";
}
int main(int argc, const char *argv[])
{
    exer();
    return 0;
}