#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;

void test1()
{
    //一、向map添加元素
    map<int, int> m = {{1, 2}};
    m.insert(2, 4);
    m.insert(make_pair(3, 6));
    m.insert(pair<int, int>(4, 8));
    m.insert(map<int, int>::value_type(5, 10));

    //二、检测insert的返回值，依赖于容器类型和参数
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
    {
        auto it = word_count.insert({word, 1});
        if (!it.second) //如果insert未发生，即word已经在map里
            it.first->second++;
    }

    //三、展开递增语句
    /* 
        it：保存insert返回值，是一个pair
        it.first：pair的第一个成员，是一个指向给定关键字的元素的map迭代器
        it.first->：解引用map迭代器，提取map元素，也是一个pair
        it.first->second：map值部分
        it.first->second++：值递增
     */

    //四、向multimap或multiset添加元素
    //允许接受重复的关键字
    multimap<string,string> author;
    author.insert({"a,b","book1"});
    author.insert({"a,b","book2"});
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}