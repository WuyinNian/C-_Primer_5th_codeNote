#include <iostream>
#include <string>
using namespace std;

//引用给变量取了另外一个名字
void test()
{
    int a = 10;
    int &refA = a;
    // int &refAA;//错误，引用必须初始化

    //引用即别名
    refA = 20;
    cout << a << endl; // 20

    //引用本身不是对象，无法定义引用的引用
    // int &&ref_refA = refA;//报错

    //引用必须绑定在对象上，不能绑定在初始值上
    // int &ref = 10;//报错

    //引用类型与绑定对象类型要匹配
    double d = 1.1;
    // int &refD = d;//报错 
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}