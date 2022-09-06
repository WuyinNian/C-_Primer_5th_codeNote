#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = b;
    b = a;
    a = tmp;
}
void test1()
{
    int a = 1, b = 2;
    //引用形参绑定实参对象
    swap(a, b);
    cout << "a=" << a << ", b=" << b << endl;
}

//使用引用避免拷贝
bool isLong(const string &a, const string &b)
{
    return a.size() > b.size();
}
void test2()
{
    string s1 = "xhkjdfhasj";
    string s2 = "fjksadbckns";
    cout << isLong(s1, s2) << endl;
}

//使用引用形参返回额外信息
//定义一个fand_char函数返回string对象中某个char第一次出现的位置以及出现的次数
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto position = s.size(); //第一次出现的位置(如果有的话)
    occurs = 0;               //出现次数形参的值
    for (decltype(position) i = 0; i != s.size(); i++)
    {
        if (s[i] == c)
        {
            if (position == s.size())
            {
                position = i;
            }
            ++occurs;
        }
    }
    return position;
}
void test3()
{
    string s = "dfhhjkjbadjkbcdshfoifweon";
    string::size_type count = 0;
    int p = find_char(s, 'x', count);
    cout << "position: " << p << ", count: " << count << endl;
}

int main(int argc, const char *argv[])
{
    test3();
    return 0;
}