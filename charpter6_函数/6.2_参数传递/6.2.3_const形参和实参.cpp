#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//实参初始化形参时会忽略掉顶层const
void func(const int i)//即可以传入常量也可以传入非常量
{
    cout<<i<<endl;
}
void func(int i){//重复定义func函数

}
void test1()
{
    int i = 1;
    const int j = 2;
    func(i);
    func(j);
}

//不改变变量值时，尽量使用常量引用
//避免误导调用者改变变量
//最大可能扩大所能接受的实参类型

int main(int argc, const char *argv[])
{
    test1();
    return 0;
}