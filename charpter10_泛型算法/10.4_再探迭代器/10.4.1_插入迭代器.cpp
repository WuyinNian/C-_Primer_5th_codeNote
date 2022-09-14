#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
#include <iterator>
using namespace std;

// iterator头文件
//插入器是一个迭代器适配器，接受一个容器生成一个迭代器
void test1()
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 5, 7};
    auto it = vec.begin() + vec.size() / 2;
    int val = 42;
    // *it = val;如果it是由inserter生成的迭代器，该语句与下两行语句效果一样
    it = vec.insert(it, val);
    it++;

    list<int> lst = {1, 2, 3, 4};
    list<int> lst2, lst3;                                         //空list
    copy(lst.cbegin(), lst.cend(), front_inserter(lst2));         // 4 3 2 1
    copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin())); // 1 2 3 4
}

//练习题
void exer10_27()
{
    vector<int> vec = {9, 4, 2, 0, 5, 4, 5, 4, 7};
    list<int> lst;
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), inserter(lst, lst.begin())); //要求重复元素是相邻的
    for_each(lst.begin(), lst.end(), [](const int a)
             { cout << a << " "; });
    cout << endl;
}
int main(int argc, const char *argv[])
{
    exer10_27();
    return 0;
}