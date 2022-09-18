#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

// pair定义在utility头文件中
void test1()
{
    pair<string, string> anon;
    pair<string, size_t> word_count;
    pair<string, vector<int>> line;
    pair<string, string> author{"james", "joyce"};

    // pair的数据成员是public的，两个元素分别命名为first和second，map的对象是pair类型的
}

//二、创建pair对象的函数
//对返回值列表进行初始化
pair<string, int>
process(vector<string> &v)
{
    if (!v.empty())
    {
        return {v.back(), v.back().size()};
    }
    else
    {
        // return pair<string, int>();隐式构造返回值
        return make_pair(v.back(), v.back().size());
    }
}
void test2()
{
}

//练习题
void exer11_12()
{
    vector<pair<string, int>> vec;
    ifstream in("sample");
    if (!in)
    {
        cerr << "no file?" << endl;
        exit(1);
    }

    string s;
    int num;
    while (in >> s && in >> num)
    {
        vec.push_back(make_pair(s, num));
    }
    for (auto p : vec)
    {
        cout << p.first << " " << p.second << endl;
    }
}
int main(int argc, const char *argv[])
{
    exer11_12();
    return 0;
}