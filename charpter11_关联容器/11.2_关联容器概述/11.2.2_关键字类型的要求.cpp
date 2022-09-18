#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
#include <map>

using namespace std;

//默认情况下，标准库使用关键字类型<运算符来比较两个关键字
/*
    一、有序容器的关键字类型，严格弱序
    1.两个关键字不同时小于等于对方，如果k1小于等于k2，那么k2绝不小于等于k1
    2.k1小于等于k2，k2小于等于k3，则k1必小于等于k3
    3.两个关键字，任何一个都不小于等于另外一个，那么称这两个关键字是等价的
*/

/*
    二、使用关键字类型的比较函数
    可以使用cpmpareIsbn函数来定义一个multiset
    bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
    {
        return lhs.isbn()<rhs.isbn();
    }
    multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);//添加元素时，我们调用compareIsbn进行排序
*/
void test1()
{
}

//练习题
string &trans(string &s)
{
    for (int p = 0; p < s.size(); p++)
    {
        if (s[p] >= 'A' && s[p] <= 'Z')
            s[p] -= 'A' - 'a';
        else if (s[p] == '.' || s[p] == ',')
            s.erase(p, 1);
    }
    return s;
}
void exer11_9()
{
    ifstream in("sample");
    if (!in)
    {
        cout << "No file?" << endl;
        exit(1);
    }
    map<string, list<int>> word_lineno;
    string line;
    string word;
    int lineno = 0;
    while (getline(in, line))
    {
        lineno++;
        istringstream l_in(line);
        while (l_in >> word)
        {
            trans(word);
            word_lineno[word].push_back(lineno);
        }
    }
    for (const auto &w : word_lineno)
    {
        cout << w.first << " row: ";
        for (const auto &i : w.second)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void exer11_10()
{
    /* 
        有序容器要求关键字类型必须支持比较操作<
     */
}
void exer11_11()
{
    //typedef bool (*pf)(const Sales_data &lhs, const Sales_data &rhs)
}
int main(int argc, const char *argv[])
{
    exer11_9();
    return 0;
}