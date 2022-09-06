#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//迭代器运算符
void test1()
{
    string s("hello world!");
    auto it = s.begin();
    while (it != s.end() && !isspace(*it))
    {
        //如果容器成员类型是类的话
        //(*it).属性 <==> it->属性
        *it = toupper(*it);
        it++;
    }
    cout << s << endl;
}

//迭代器类型
void test2()
{
    vector<int> v;
    vector<int>::iterator vIt;//能读写
    vector<int>::const_iterator cVIt;//只能读
    auto it3 = v.cbegin();//const_iterator
}

//凡是使用迭代器的循环体，都不要向容器增减元素，迭代器会发生变化
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}