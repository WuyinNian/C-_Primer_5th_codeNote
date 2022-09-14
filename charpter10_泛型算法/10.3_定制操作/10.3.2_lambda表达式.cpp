#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
//求大于等于一个给定长度的单词有多少
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    sort(words.begin(), words.end());
    words.erase(unique(words.begin(), words.end()), words.end());
    stable_sort(words.begin(), words.end(), isShorter);

    //获取一个迭代器，指向第一个满足size()>=sz的元素
    //计算满足size>=sz的元素的数目
    //打印长度大于等于给定值的单词，每个单词后面跟一个空格
}

/*
    我们可以向算法传递任何类别的可调用对象
    目前两种可调用对象：函数和函数指针；另外两种，重载了函数调用运算符的类以及lambda表达式

    一、介绍lambda，lambda表达式代表一个可调用的代码单元
    [capture list](parameter list) -> return type {function body}
    [capture list]是一个lambda所在函数中定义的局部变量的列表（通常为空）

 */
void test1()
{
    // 可以忽略参数列别和返回类型，但是其他的必须含有
    // 返回值类型可以自动识别
    auto f = []
    { return 42; };

    //调用
    cout << f() << endl;
}

//二、向lambda传递参数
void test2()
{
    // lambda不能有默认实参，所以调用的实参数永远等于形参数
    //与isShorter函数完成相同功能的函数
    auto f = [](const string &s1, const string &s2)
    { return s1.size() < s2.size(); };
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    stable_sort(words.begin(), words.end(), f);
}

void test3(vector<string> &words, vector<string>::size_type sz)
{
    //将每个string的长度和biggies中的sz进行比较
    //一个lambda只有在其捕获列表中捕获一个它所在函数中的局部变量，才能在函数体中使用该变量
    stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2)
                { return s1.size() < s2.size(); });

    //三、使用捕获列表
    auto f = [sz](const string &s)
    { return s.size() >= sz; };
    //四、调用find_if
    auto wc = find_if(words.begin(), words.end(), f); //返回指向第一个大于等于sz元素的迭代器
    auto count = words.end() - wc;
    cout << count << endl;

    //五、for_each算法
    //捕获列表为空，是因为我们只对lambda所在函数中定义的非static变量使用捕获列表
    for_each(words.begin(), words.end(), [](const string &s)
             { cout << s << " ";});
    cout << endl;
    for_each(wc, words.end(), [](const string &s)
             { cout << s << " ";});
    cout << endl;
}

//练习题
void exer10_14()
{
    [](int a, int b) {return a + b;};
}
void exer10_15(int num)
{
    [num](int a) {return a + num;};
}

int main(int argc, const char *argv[])
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    test3(words, 4);
    return 0;
}