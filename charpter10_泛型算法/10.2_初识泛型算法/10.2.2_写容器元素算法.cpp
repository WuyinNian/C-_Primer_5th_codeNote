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

//序列原大小至少不小于我们要写入元素个数
void test1()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    fill(vec.begin(), vec.end(), 0);                     //将每个元素重置为0
    fill(vec.begin(), vec.begin() + vec.size() / 2, 10); //只要输入序列是有效的，写入操作就是安全的
}

//一、算法不检查写操作
void test2()
{
    // fill_n, 将给定元素赋给指定位置开始的n个元素
    vector<int> vec = {1, 2, 3, 4, 5};
    fill_n(vec.begin(), vec.size(), 0);
}

//二、介绍back_inserter，定义在头文件iterator
//一个保证算法有足够元素空间来容纳输出数据的方法是使用插入迭代器
void tets3()
{
    // back_inserter，接受一个容器的引用，返回与该容器绑定的插入迭代器
    vector<int> vec;
    auto it = back_inserter(vec);
    *it = 42; //容器现在有一个元素，42，push_back

    fill_n(back_inserter(vec), 10, 0);
}

//三、拷贝算法
//向目的位置迭代器指向的输出序列写入数据，目的序列至少包含和输入序列一样的元素数目
void test4()
{
    int a1[] = {0, 12, 3, 4, 5, 6, 7, 8, 9};
    int a2[sizeof(a1) / sizeof(*a1)];
    auto ret = copy(begin(a1), end(a1), begin(a2)); //指向a2尾元素后的指针

    list<int> lst(10, 0);
    vector<int> vec(10,1);
    replace(lst.begin(), lst.end(), 0, 42);              //将lst中0替换为42
    replace_copy(lst.begin(), lst.end(), vec.begin(), 0, 42); //将lst中元素拷贝被vec，并将0替换为42
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}