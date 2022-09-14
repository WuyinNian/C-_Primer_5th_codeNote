#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

//除forwar_list，其他容器都支持，rbegin,rend,crbegin,crend
//一、反向迭代器需要递减运算符
void test1()
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto r_iter = vec.rbegin(); r_iter != vec.rend(); r_iter++)
    {
        cout << *r_iter << endl; // 9, 8 ,...
    }
}

//二、反向迭代器和其他迭代器之间的关系
void test2()
{
    string line = "x,2,3,5,df,sfs,d,fds,fdsd,abc";
    auto comma = find(line.begin(), line.end(), ',');
    cout << string(line.begin(), comma) << endl; // x

    auto rcomma = find(line.rbegin(), line.rend(), ',');
    cout << string(line.rbegin(), rcomma) << endl;      // cba
    cout << string(rcomma.base(), line.end()) << endl; // abc
}

int main(int argc, const char *argv[])
{
    test2();
    return 0;
}