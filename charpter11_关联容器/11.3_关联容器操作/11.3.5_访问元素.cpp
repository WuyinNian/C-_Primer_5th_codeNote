#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

//一、对map使用find代替下标操作
//如果不存在关键字，不需要插入元素的情况
void test1()
{
    
}
//二、在multimap和multiset中查找元素
//使用find找到第一个指向特定元素的迭代器，count统计个数，对迭代器做有限次迭代

//三、一种不同的，面向迭代器的解决方法
/* 
    low_bound()，返回指向指定关键字的第一个迭代器，如果不存在返回第一个大于指定关键字的位置
    upper_bound()，返回指向指定关键字的最后一个迭代器，如果不存在返回第一个大于指定关键字的位置
 */

//四、equal_range函数
//返回一个迭代器pair<low_bound,upper_bound>

int main(int argc, const char *argv[])
{
    test1();
    return 0;
}