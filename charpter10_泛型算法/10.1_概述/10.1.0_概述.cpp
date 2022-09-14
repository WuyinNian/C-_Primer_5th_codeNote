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

/*
    1. 大多数算法定义在algorithm头文件中，一组数值泛型算法定义在numeric头文件中
    2. 算法并不直接操作容器，一般由一个迭代器范围控制
 */
void test1()
{
    int val = 42;
    vector<int> vec;
    auto result = find(vec.cbegin(), vec.cend(), val); //成功返回指定迭代器，失败返回尾后迭代器
    cout << "The value: " << val
         << (result == vec.cend() ? " is not present." : " is present.") << endl;

    //类似，由于find操作的是迭代器，所以也可以查找别的容器
    string str = "a value";
    list<string> lst;
    auto result2 = find(lst.cbegin(), lst.cend(), str);

    //由于指针就像在内置数组上的指针一样，所以可以用find查找数组
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *result3 = find(begin(arr), end(arr), 3);
}

//一、算法如何工作
//二、 迭代器令算法不依赖于容器
//三、 算法依赖于元素类型

//练习题
void exer10_1()
{
    ifstream in("file");
    if (!in)
    {
        cerr << "No file" << endl;
        exit(1);
    }

    vector<int, allocator<int>> vec;
    int val;
    while (in >> val)
    {
        vec.push_back(val);
    }
    
    auto result = count(vec.cbegin(), vec.cend(), 5);
    cout << result << endl;
}
int main(int argc, const char *argv[])
{
    exer10_1();
    return 0;
}