#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

//如果空捕获列表，可以用函数实现，但是如果有捕获列表，函数不能实现同样的功能
bool check_size(const string &s, string::size_type sz) //不能传递给find_if，因为find_if的可调用函数只能接受一个参数
{
    return s.size() >= sz;
}

//一、标准库bind函数
//定义在functional头文件中，接受一个可调用对象，生成另一个可调用对象
void test1()
{
    //二、绑定check_size的sz参数
    //三、使用placeholder名字，占位符要要写成std::placeholders::_n
    auto check6 = bind(check_size, std::placeholders::_1, 6);
}

//四、bind的参数
//五、用bind重排参数顺序
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
void test2()
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    sort(words.begin(), words.end(), isShorter);
    sort(words.begin(), words.end(), bind(isShorter, _2, _1));
}

//六、绑定参数引用
ostream &print(ostream &os, const string &s, char c)
{
    return os << s << c;
}
void test3(ostream &os, char c)
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    for_each(words.begin(), words.end(), [&os, c](const string &s)
             { os << s << c; });

    // for_each(words.begin(), words.end(), bind(print, os, _2, c));//错误，不能拷贝os
    
    for_each(words.begin(), words.end(), bind(print, ref(os), _2, c));//ref()返回一个对象，包含引用，此对象是可以拷贝的
}

int main(int argc, const char *argv[])
{
    test1();
    return 0;
}