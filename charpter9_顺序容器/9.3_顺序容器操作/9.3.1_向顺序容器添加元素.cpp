#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
using namespace std;

void test1()
{
    //一、使用push_back()
    //二、使用push_front()
    //三、在容器中的特定位置添加元素
    //四、插入范围内元素
    //五、使用insert的返回值
    list<string> lst;
    auto iter = lst.begin();
    string word;
    while (cin >> word)
        iter = lst.insert(iter, word); //等价调用push_front

    //六、使用emplace操作
    // emplace函数在容器中直接构造函数。传递给empalces函数的参数必须与元素类型的构造函数相匹配
}

//练习题
void exer9_18()
{
    string s;
    deque<string> d;
    while (cin >> s)
    {
        d.push_back(s);
    }
    auto it = d.begin();
    while (it != d.end())
    {
        cout << *it << endl;
        ++it;
    }
}
void exer9_19()
{
    string s;
    list<string> l;
    while (cin >> s)
    {
        l.push_back(s);
    }
    auto it = l.begin();
    while (it != l.end())
    {
        cout << *it << endl;
        ++it;
    }
}
void exer9_20()
{
    list<int> list;
    deque<int> d1, d2;
    for (auto &i : list)
    {
        if (i & 1)
            d1.push_back(i);
        else
            d2.push_back(i);
    }
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}