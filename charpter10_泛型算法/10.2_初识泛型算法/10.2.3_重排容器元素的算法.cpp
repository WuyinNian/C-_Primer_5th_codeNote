#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;

//一、消除重复单词
//二、使用unique
//三、使用容器操作删除元素
void test1()
{
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    sort(words.begin(), words.end());
    for (auto &c : words)
    {
        cout << c << " ";
    }
    cout << endl;
    auto unique_end = unique(words.begin(), words.end()); //使得不重复的元素出现在开始的部分, 返回不重复区域的后一个位置
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
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}