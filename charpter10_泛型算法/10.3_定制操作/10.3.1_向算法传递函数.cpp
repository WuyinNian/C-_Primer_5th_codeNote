#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

//一、谓词，谓词是一个可调用的表达式，其返回结果是一个能用作条件的值
//元素类型必须能转换为谓词的参数类型
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
void test1()
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    sort(words.begin(), words.end(), isShorter);
}

//二、排序算法
void test2()
{
    //稳定排序算法stable_sort算法，相同长度的元素按字典序列排列，维持大小相等元素原有顺序
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    sort(words.begin(), words.end());
    for (auto &c : words)
    {
        cout << c << " ";
    }
    cout << endl;

    auto unique_end = unique(words.begin(), words.end());
    for (auto &c : words)
    {
        cout << c << " ";
    }
    cout << endl;

    words.erase(unique_end, words.end());
    for (auto &c : words)
    {
        cout << c << " ";
    }
    cout << endl;

    stable_sort(words.begin(), words.end(), isShorter);
    for (auto &c : words)
    {
        cout << c << " ";
    }
    cout << endl;
}
int main(int argc, const char *argv[])
{
    test2();
    return 0;
}