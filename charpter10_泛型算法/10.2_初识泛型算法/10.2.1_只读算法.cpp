#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
#include <numeric>
using namespace std;

//一、算法和元素类型
void test1()
{
    // accumulate的第三个参数类型决定了函数中使用哪个加法运算符以及返回值的类型
    vector<string> vec;
    string sum = accumulate(vec.cbegin(), vec.cend(), string("")); // string定义了+运算符
    // string sum2 = accumulate(vec.cbegin(), vec.cend(), "");        // const char*未定义了+运算符，该调用是错的
}

//操作两个序列的算法
// equal,用于确定序列是否保存相同的值，它将一个序列中的每个元素与第二个序列中的对应元素进行比较。如果所有元素相等返回true，否则false
void test2()
{
    vector<string> roster1;
    list<const char *> roster2;
    equal(roster1.cbegin(), roster1.cend(), roster2.begin()); // roster2中的元素个数至少等于roster1
}

//练习题
void exer10_3()
{
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto result = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << result << endl;
}
void exer10_4()
{
    vector<double> vec = {0, 3.5, 4.6};
    auto result = accumulate(vec.cbegin(), vec.cend(), 0); // result是整型的
    cout << result << endl;
}
void exer10_5()
{
    // equal使用==比较,如果元素类型是const char*，比较的是地址值
}
int main(int argc, const char *argv[])
{
    exer10_4();
    return 0;
}