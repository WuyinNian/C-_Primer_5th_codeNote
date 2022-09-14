#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

/* 
    迭代器定义了一组公共操作。特定的迭代器有自己额外的操作
    一、迭代器类别
        1.输入迭代器：读取序列中的元素。一个输入迭代器必须支持==、!=、++、*、->等价于(*it).member
        2.输出迭代器：只写而不读元素，输入迭代器的补集，必须支持++、*
            向一个已经解引用的输出赋值，就是将值写入他所指的元素
            向一个输出迭代器只能赋值一次，只能用于单遍扫描
        3.前向迭代器：可以读写元素，多遍扫描
        4.双向迭代器：前向迭代器基础上，多--
        5.随机访问迭代器：常量时间内访问任意元素的能力
            支持< > <= >= - + -+ += ,迭代器减法， 下标运算符iter[n] 等价于*(iter[n])
            sort array deque string vector 访问内置数组的指针


 */
void test1()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}