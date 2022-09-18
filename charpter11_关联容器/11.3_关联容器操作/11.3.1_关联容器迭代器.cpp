#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

//解引用关联容器迭代器的到是一个value_type值的引用
// map的value_type是一个pair，可以改变pair的值，但是不能改变关键字成员的值
void test1()
{
}

//一、set的迭代器是const的
// set的iterartor和const_iterator都是只读不写的
void test2()
{
    set<int> s = {1, 2, 3, 4};
    auto it = s.begin();
    if (it != s.end())
    {
        // *it = 42;  错误：只读不写
        cout << *it << endl;
    }
}

//二、遍历关联迭代器
void test3()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
    {
        ++word_count[word]; //提取word中的技术器并加1
    }
    auto it = word_count.begin();
    while (it != word_count.end())
    {
        //按关键字字典序升序排列
        cout << it->first << " occurs " << it->second << ((it->second > 1 ? " times" : " time")) << endl;
        ++it;
    }
}

//三、关联容器和算法
/*
    1.不对关联容器使用泛型算法
    2.可用于只读区元素的算法
    3.如果真要使用算法，当作源序列或者目的位置
 */

//练习题
void exer11_15()
{
    map<int, vector<int>> m;
    // mapped_type: vector<int>
    // key_type: int
    // value_type: pair<int,vector<int>>
}
void exer11_15()
{
    map<int, vector<int>> m;
    auto it = m.begin();
    it->second = {1,2};
}

int main(int argc, const char *argv[])
{
    test3();
    return 0;
}