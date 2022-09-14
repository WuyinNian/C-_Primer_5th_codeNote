#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;

//一、istream_iterator操作
void test1()
{
    ifstream in("sample");
    istream_iterator<string> str_it(in);

    vector<int> vec;
    istream_iterator<int> int_it(cin);
    istream_iterator<int> eof; //默认初始化，尾后迭代器
    while (int_it != eof)
    {
        vec.push_back(*int_it++);
    }

    vector<int> vec2(int_it, eof); //从迭代器范围构造vec
}

//二、使用算法操作流迭代器
//三、istream_iterator允许使用懒惰求值
void test2()
{
    istream_iterator<int> in(cin), eof;
    cout << accumulate(in, eof, 0) << endl;
}

//四、ostream_iterator操作，不允许空的或尾后位置的ostream_iterator
void test3()
{
    vector<int> vec = {1, 2, 3, 4, 5, 56};
    ostream_iterator<int> out_it(cout, " "); //第二个参数必须是C字符传风格，输出每个元素后打印此字符串
    for (auto e : vec)
    {
        *out_it++ = e;
    }
    cout << endl;

    copy(vec.begin(), vec.end(), out_it);
    cout << endl;
}

//五、使用流迭代器处理类类型
//类类型中要实现输入运算符，输出运算符
/* void test4()
{
    istream_iterator<Sales_data> item_iter(cin), eof;
    ostream_iterator<Sales_data> out_iter(cout, "\n");

    Sales_data sum = *item_iter++;
    while (item_iter != eof)
    {
        if (item_iter->isbn() == sum.isbn())
        {
            sum.combine(*item_iter++);
        }
        else
        {
            out_iter = sum;
            sum = *item_iter++;
        }
    }
} */

//练习题
void exer10_29()
{
    ifstream in("sample");
    if (!in)
        cerr << "no data?" << endl;
    istream_iterator<string> in_iter(in), eof;
    vector<string> vec;
    while (in_iter != eof)
    {
        vec.push_back(*in_iter++);
    }
    for_each(vec.begin(), vec.end(), [](string& s)
             { cout << s << " "; });
    cout << endl;
}

int main(int argc, const char *argv[])
{
    exer10_29();
    return 0;
}