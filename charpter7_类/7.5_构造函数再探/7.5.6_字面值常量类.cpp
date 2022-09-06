#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//数据成员都是字面值类型的聚合类是字面值常量类
/*
    如果一个类不是聚合类，但它符合下述要求，则它也是一个字面值常量类
    1.数据成员都是字面值类型
    2.类至少有一个constexpr构造函数
    3.如果数据成员含有类内初始值在，则内置类型成员的初始值必须是一条常量表达式
    4.如果成员属于某种类类型，则初始值必须使用成员自己的constexpr构造函数
    5.类必须使用析构函数的默认定义，该成员负责销毁类的对象
*/

// constexpr构造函数
void test1()
{
    class Debug
    {
    public:
        constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
        constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) {}
        constexpr bool any() {return hw || io || other;}
        void set_hw(bool b) {hw = b;}
        void set_io(bool b) {io = b;}
        void set_other(bool b) {hw = b;}
    private:
        bool hw;
        bool io;
        bool other;
    };
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}