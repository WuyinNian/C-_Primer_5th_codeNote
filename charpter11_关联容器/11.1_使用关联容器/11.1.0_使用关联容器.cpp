#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

//一、使用map
//单词计数程序
void test1()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
    {
        ++word_count[word]; //提取word中的技术器并加1，如果下标符还未在map中，会创建一个新元素
    }
    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second << ((w.second > 1 ? " times" : " time")) << endl;
    }
}

//二、使用set
//使用set保存想忽略的单词，只对不在集合中的单词统计出现次数
void test2()
{
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
    string word;
    while (cin >> word)
    {
        if (exclude.find(word) == exclude.end())
            ++word_count[word]; //提取word中的技术器并加1
    }
    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second << ((w.second > 1 ? " times" : " time")) << endl;
    }
}

//练习题
// string &trans(string &s)
// {
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] >= 'A' && s[i] <= 'Z')
//             s[i] -= 'A' - 'a';
//         else if (s[i] == ',' || s[i] == '.')
//             s[i] = '\0';
//     }
//     return s;
// }
void exer11_4()
{
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
    string word;
    while (cin >> word)
    {
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] >= 'A' && word[i] <= 'Z')
                word[i] -= 'A' - 'a';
            else if (word[i] == ',' || word[i] == '.')
                word.erase(i,1);//不能使用word[i]='\0'
        }
        if (exclude.find(word) == exclude.end())
            ++word_count[word]; //提取word中的计数器并加1
    }
    for (const auto &w : word_count)
    {
        cout << w.first << " occurs " << w.second << ((w.second > 1 ? " times" : " time")) << endl;
    }
}
int main(int argc, const char *argv[])
{
    exer11_4();
    return 0;
}