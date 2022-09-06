#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
using namespace std;
/*
    为了实现快速随机访问，vector将元素连续储存。向vector和string中添加元素，如果没有空间容纳新元素，容器必须分配新的空间保存已有元素和新元素，
    释放掉旧空间。如果一次添加重新分配一次，性能会很慢。
    解决方法：预留空间
 */

//一、管理容量的成员函数

//二、capacity和size
void test1()
{
    vector<int> v;
    cout << "v: size: " << v.size() << " capacity: " << v.capacity() << endl;
    for (vector<int>::size_type ix = 0; ix != 24; ix++)
        v.push_back(ix);
    cout << "v: size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.reserve(50);
    cout << "v: size: " << v.size() << " capacity: " << v.capacity() << endl;

    //用光预留空间
    while (v.size() != v.capacity())
        v.push_back(0);
    cout << "v: size: " << v.size() << " capacity: " << v.capacity() << endl;

    v.push_back(42);
    cout << "v: size: " << v.size() << " capacity: " << v.capacity() << endl;

    v.shrink_to_fit();
    cout << "v: size: " << v.size() << " capacity: " << v.capacity() << endl;
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}