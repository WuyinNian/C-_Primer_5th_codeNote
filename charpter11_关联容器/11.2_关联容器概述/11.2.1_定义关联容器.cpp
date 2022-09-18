#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

//关联容器（有序的和无序的）不支持顺序容器的位置相关操作，push_front, push_back
//关联容器的迭代器都是双向的

//初始化multimap和multiset
void test1()
{
    vector<int> vec;
    for (vector<int>::size_type i = 0; i != 10; i++)
    {
        vec.push_back(i);
        vec.push_back(i); //每个数重复保存一次
    }

    set<int> s(vec.begin(), vec.end());
    multiset ms(vec.begin(), vec.end());

    cout << vec.size() << endl;
    cout << s.size() << endl;
    cout << ms.size() << endl;
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}