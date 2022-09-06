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
    // string提供了额外的insert和erase版本
    string s("Hello world!");
    s.insert(s.size(), 5, '!');
    s.erase(s.size() - 5, 5);

    //接受C风格字符数组的insert和assign版本
    const char *cp = "Stately, plump Buck";
    s.assign(cp, 7);
    cout << s << endl;
    s.insert(s.size(), cp + 7);
    cout << s << endl;

    string s2 = "something";
    s.insert(0, s2);
    cout << s << endl;
    s.insert(0, s2, 0, s2.size());
    cout << s << endl;
}

//一、append和repalce函数
void test2()
{
    string s("C++ Primer"), s2 = s;
    s.insert(s.size(), " 5th Ed.");
    s2.append(" 5th Ed.");

    s.erase(11, 3);
    s.insert(11, "6th");
    s2.replace(11, 3, "Sixth"); //从位置11开始，删除了3个字符，插入了5个新字符
}

//二、改变strinf的多种重载函数
void test3()
{
    /*
        assign总是替换所有内容
        append追加内容
        replace：一个位置一个长度；一个迭代器范围
        insert：一个下标或一个迭代器，插入之前位置
     */
}

//练习题
void func(string &s, const string &oldVal, const string &newVal)
{
    auto l = oldVal.size();
    if (!l)
        return;
    auto iter = s.begin();
    while (iter <= s.end() - 1)
    {
        auto iter1 = iter;
        auto iter2 = oldVal.begin();
        while (iter2 != oldVal.end() && *iter1 == *iter2)
        {
            iter1++;
            iter2++;
        }
        if (iter2 == oldVal.end())
        {
            iter = s.erase(iter, iter1);
            if (newVal.size())
            {
                iter2 = newVal.end();
                do
                {
                    iter2--;
                    iter = s.insert(iter, *iter2);
                } while (iter2 > newVal.begin());
            }
            iter += newVal.size();
        }
        else
            iter++;
    }
}
void exer9_43()
{
    string s = "tho thru tho!";
    func(s, "tho", "through");
    cout << s << endl;
    func(s, "through", "");
    cout << s << endl;
}

void func2(string &s, const string &oldVal, const string &newVal)
{
    auto l = oldVal.size();
    if (!l)
        return;
    int sL = 0;
    while (sL <= s.size() - 1)
    {
        int sR = sL;
        int oldR = 0;
        while (oldR != oldVal.size() && s[sR] == oldVal[oldR])
        {
            sR++;
            oldR++;
        }
        if (oldR == oldVal.size())
        {
            s.replace(sL, oldR, newVal);
            sL += newVal.size();
        }
        else
            sL++;
    }
}
void exer9_44()
{
    string s = "tho thru tho!";
    func2(s, "tho", "through");
    cout << s << endl;
    func2(s, "through", "");
    cout << s << endl;
}

string func3(string &name, const string &prefix, const string &suffix)
{
    auto iter = prefix.end();
    do
    {
        iter--;
        name.insert(name.begin(), *iter);
    } while (iter > prefix.begin());

    name.append(suffix);
    return name;
}
void exer9_45()
{
    string name("Xu");
    string p("Mr.");
    string s("III");
    cout << func3(name, p, s) << endl;
}
int main(int argc, const char *argv[])
{
    exer9_45();
    return 0;
}