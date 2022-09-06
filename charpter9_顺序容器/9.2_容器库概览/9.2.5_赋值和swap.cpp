#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
using namespace std;

void test1()
{
    array<int, 3> a1 = {1, 2, 3};
    array<int, 3> a2 = {0};
    a1 = a2;
    // a2 = {0};array不允许使用assign和值列表进行赋值
}

//一、使用assign（仅顺序容器）
//允许从一个不同但相容的类型赋值，或者从子序列赋值
void test2()
{
    list<string> names;
    vector<const char *> odlstyle;
    names.assign(odlstyle.cbegin(), odlstyle.cend());

    list<string> slist1(1);
    slist1.assign(10, "Hiya!");
}

//二、使用swap
//除array外，swap不会对任何元素进行拷贝，删除或插入操作
//swap string会导致迭代器、引用和指针失效
//swap array会真正交换他们的元素，指针、引用和迭代器所绑定的元素保持不变，但是元素值已经进行了交换

//新标准库中，提供成员函数版本swap和非成员版本swap，使用后者是个好习惯
void test3()
{
    vector<string> svec1(10);
    vector<string> svec2(24);
    swap(svec1,svec2);//元素本身并为交换，swap只是交换了两个容器的数据结构
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}