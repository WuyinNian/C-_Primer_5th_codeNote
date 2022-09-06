#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
using namespace std;

/* 
    1. 每个顺序容器都有front成员函数
    2. 除forwad_list外，都有back成员函数
 */
void test1()
{
    vector<int> vec = {1,2,3};
    if(!vec.empty())
    {
        auto val = *vec.begin(), val2 = vec.front();
        auto val3 = *(--vec.end()), val4 = vec.back();//forward_list不能递减迭代器，且不支持back()
    }
}

//一、访问成员函数返回的是引用
void test2()
{
    vector<int> vec = {1,2,3};
    if(!vec.empty())
    {
        vec.front() = 42;
        auto &v = vec.back();
        v = 1024;
        auto v2 = vec.back();//v2不是引用，是一个拷贝
        v2 = 0;
    }
}

//二、下标操作和安全的随机访问
void test3()
{
    vector<string> svec;//空vector
    cout << svec[0]; //运行时错误：svec中没有元素
    cout << svec.at(0); //抛出out_of_range异常

}
int main(int argc, const char *argv[])
{
    test3();
    return 0;
}