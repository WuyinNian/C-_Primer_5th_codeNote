#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

//定义lambda时，编程器生成了一个与lambda对应的未命名的类类型

//一、值捕获，前提是变量可以拷贝，被捕获的值是在创建lambda时拷贝，不是调用时，因此随后对变量的修改不会影响lambda内的值
void test1()
{
    size_t v1 = 42;
    auto f = [v1]()
    { return v1; };
    v1 = 0;
    auto j = f(); // j = 42
}

//二、引用捕获，
void test2()
{
    size_t v1 = 42;
    auto f = [&v1]()
    { return v1; };
    v1 = 0;
    auto j = f(); // j = 0，f2保存的是引用，而非拷贝

    //引用有时候是必要的
    //当函数接受一个ostream对象，由于不能拷贝，所以只能捕获引用
}

//三、隐式捕获
void test3(vector<string> &words, vector<string>::size_type sz)
{
    stable_sort(words.begin(), words.end(), [](const string &s1, const string &s2)
                { return s1.size() < s2.size(); });

    //在捕获列表输入& =
    //和显示捕获混合引用的时候，一个元素必须是&或=
    auto f = [=](const string &s)
    { return s.size() >= sz; };
    auto wc = find_if(words.begin(), words.end(), f);
    auto count = words.end() - wc;
    cout << count << endl;

    for_each(words.begin(), words.end(), [](const string &s)
             { cout << s << " "; });
    cout << endl;
    for_each(wc, words.end(), [](const string &s)
             { cout << s << " "; });
    cout << endl;
}

//四、可变lambda
//默认情况下，对于一个值被拷贝的变量，lambda不会改变其值。如果我们希望改变，需要加上mutable
void test4()
{
    size_t val = 42;
    auto f = [val]() mutable
    { return ++val; };
    val = 0;
    auto j = f(); // j==43
}

//五、指定lambda返回类型
void test5()
{
    //使用transform和一个lambda将一个序列中的负值替换为其绝对值
    vector<int> vec = {0, 1, -2, 3, -4, 5, -6, 7, -8, 9};
    transform(vec.begin(), vec.end(), vec.begin(), [](int val)
              { return val < 0 ? -val : val; });

    //错误，不能推断lambda的返回类型
    // transform(vec.begin(), vec.end(), vec.begin(), [](int val)
    //           { if(val<0) return -val; else return val; });

    transform(vec.begin(), vec.end(), vec.begin(), [](int val) -> int
              { if(val<0) return -val; else return val; });
}

//练习
bool mt4(const int &a)
{
    return a > 4;
}
void exer10_20()
{
    vector<int> vec = {9, 4, 2, 5, 4, 5, 4, 7};
    auto res = count_if(vec.begin(), vec.end(), mt4);
    cout << res << endl;
}

void exer10_21(int num)
{
    auto f = [&num]() -> bool
    { !num ? num-- : 0; };
}

int main(int argc, const char *argv[])
{
    exer10_21(10);
    return 0;
}