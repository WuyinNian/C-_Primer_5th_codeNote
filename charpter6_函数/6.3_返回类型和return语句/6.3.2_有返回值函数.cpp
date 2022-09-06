#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

// C++保证return语句和返回值类型相同，
bool str_subrange(const string &s1, const string &s2)
{
    if (s1.size() == s1.size())
        return s1 == s2;
    auto size = (s1.size() < s2.size()) ? s1.size() : s2.size();
    for (decltype(size) i = 0; i != size; i++)
    {
        if (s1[i] != s2[i])
            return false; //没有返回值，编译器会报错
    }
    return true; //如果没有return语句，编译可能检查不出来，所以在for循环含有return语句的程序末尾应加上return语句
}
void test1()
{
    str_subrange("dhsakj", "sdhakjs");
}

//值是如何被返回的
//返回值的方式和初始化一个变量或形参的方式完全一样：返回的值用于初始化调用点的一个临时量，该临时量就是函数调用的结果
string make_plural(size_t str, const string &word, const string &ending)
{
    return (str > 1) ? word + ending : word; //返回一个临时string对象
}
//形参和返回值都是引用，函数结果和返回结果都不会拷贝string对象
const string &shorterStr(const string &s1, const string &s2)
{
    return (s1.size() < s2.size()) ? s1 : s2;
}
void test2()
{
}

//不要返回局部对象的引用或指针
//函数结束后，局部对象所占的储存空间会被释放，因此其引用或指针最后会指向无效的内存空间，返回的是未定义的值
const string &manip()
{
    string str;
    if (!str.empty())
        return str;
    else
        return "empty";
}
void test3()
{
}

//返回类类型的函数和调用运算符
void test4()
{
    auto sz = shorterStr("hjkdas", "sdna").size(); //满足左结合律
}

//引用返回左值，其它返回类型得到左值
char &getVal(string &str, string::size_type ix)
{
    return str[ix];
}
void test5()
{
    string s("a value");
    cout << s << endl;
    getVal(s, 0) = 'A'; //引用返回左值，可以为其赋值
    cout << s << endl;
}

//列表初始化返回值
//如果是内置类型，{}最多包含一个值
//如果是类类型，由其实现的初始化决定
vector<string> process()
{
    string s1 = "dasjkj";
    string s2 = "sndasnkl";
    if (s1.empty())
        return {};
    else if (s1 == s2)
        return {"funx", "ok"};
    else
        return {"funx", s1, s2};
}
void test6()
{
}

//主函数的返回值，如果没有return语句，默认隐式插入return 0
//一个函数调用自身称为递归，主函数不能递归
int main(int argc, const char *argv[])
{
    test5();
    return 0;
}