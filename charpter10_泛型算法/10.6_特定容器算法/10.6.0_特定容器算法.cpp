#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

//链表类型list和forward_list定义了几个成员函数形式的算法
//独有的sort, merge, remove, reverse
//对于list和forwa_list，应该优先使用内部算法而不是通用版本

//一、splice成员，链表数据结构特有的，不需要通用版本
//二、链表特有的操作会改变容器
void test1()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}