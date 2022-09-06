#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
using namespace std;

/*
    向容器添加元素后：
    1. 如果容器是vector或string，且储存空间重新分配，迭代器、引用、指针失效；若不重新分配储存空间，插入位置之前的元素有效，之后的元素失效
    2. deque，除首尾位置之外插入元素迭代器、指针、引用都会失效；首尾位置迭代器失效，引用和指针不会失效
    3. list和forward_list，都有效

    删除容器元素
    1. vector和string，被删元素之前都有效
    2. deque，首尾之外任何位置删除元素，其它都失效；首尾位置删除元素，其它位置不失效
    3. list和forward_list，都有效
 */
void test1()
{
}

//一、编写改变容器的循环程序
void test2()
{
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            iter += 2; //跳过当前元素以及插入到它之前的元素
        }
        else
        {
            iter = vi.erase(iter); // iter指向我们删除元素之后的元素
        }
    }
}

//二、不要保存end返回的迭代器
void test3()
{
    //灾难：该循环是未定义
    vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto begin = v.begin(), end = v.end(); //保存尾后迭代器是个坏主意，因为添加/删除vector/string元素，end总会失效
    while (begin != end)                   //应该使用begin != v.end();
    {
        ++begin; //在元素之后插入元素
        begin = v.insert(begin, 42);
        ++begin; //跳过刚刚加入的元素
    }
}

//练习题
void exer9_31()
{
    list<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while (iter != vi.end())
    {
        if (*iter % 2)
        {
            iter = vi.insert(iter, *iter);
            iter++; //跳过当前元素以及插入到它之前的元素
            iter++; //跳过当前元素以及插入到它之前的元素
        }
        else
        {
            iter = vi.erase(iter); // iter指向我们删除元素之后的元素
        }
    }
    forward_list<int> l = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = l.before_begin();
    auto curr = l.begin();
    while (curr != l.end())
    {
        if (*iter % 2)
        {
            curr = l.insert_after(curr,*curr);//插入到当前元素之后，返回新插入元素位置
            prev = curr;
            curr++;
        }
        else
        {
            iter = vi.erase(iter); // iter指向我们删除元素之后的元素
        }
    }
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}