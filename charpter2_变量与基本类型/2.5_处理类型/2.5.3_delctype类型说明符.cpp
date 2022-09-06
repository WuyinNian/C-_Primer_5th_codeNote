#include <iostream>
#include <string>
using namespace std;

// C++11
// delctype(f()) sum = x;
void test1()
{
    //直接返回括号里面的类型
    const int a = 9, &b = a;
    decltype(a) c = 8; // int
    //值的注意的是，这里的引用指的就是引用本身，而不是绑定的对象，属于一个例外
    decltype(b) d = a;
}

// delctype与引用
void test2()
{
    int a = 42, *b = &a, &c = a;
    decltype(c + 0) d;  //加法的结果是int
    decltype(*b) e = a; //解引用指针是指针所指的对象，还能给这个对象赋值，故e的类型为int &

    decltype(a) f;       // int f
    decltype((a)) g = f; // int &g = f, 变量是一个可以作为赋值语句坐值的特殊的表达式，给变量加上括号会把他当成是一个表达式
}

//练习题
/*
    auto和decltype的区别：
    auto和decltype的区别主要有三个方面:
    第一
    auto类型说明符用编译器计算变量的初始值来推断其类型
    而decltype虽然也让编译器分析表达式并得到它的类型，但是不实际计算表达式的值。
    第二
    编译器推断出来的auto类型有时候和初始值的类型并不完全一样，编译器会适当地改变结果类型使其更符合初始化规则。例如，auto--般会忽略掉顶层
    const,而把底层const保留下来。
    与之相反，decltype会保留变量的顶层const.
    第三
    与auto不同，decltype的结果类型与表达式形式密切相关，如果变量名加上了一对括号，则得到的类型与不加括号时会有不同。如果decltype使用的
    是一个不加括号的变量，则得到的结果就是该变量的类型;如果给变量加上了一层或多层括号，则编译器将推断得到引用类型。
*/
int main(int argc, const char *argv[])
{
    test2();
    return 0;
}