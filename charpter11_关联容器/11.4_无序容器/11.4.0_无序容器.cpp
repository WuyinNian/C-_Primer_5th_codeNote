#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

//一、使用无序容器
//统计出现次数，但单词不会按字典序排序
void test1()
{
    unordered_map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];
    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second << ((w.second) > 1 ? " times" : " time") << endl;
}

//二、管理桶
/*
    1.无序容器在存储上组织为一组桶，每个桶保存0个或多个元素，无序容器使用一个哈希函数将元素映射到桶
    2.容器将具有一个特定哈希值的所有元素都保存在相同的桶中
    3.无序容器的性能依赖于哈希函数的质量和桶的数量和大小
 */

//三、无序容器对关键字类型的要求
//不能直接定义关键字为自定义类类型的无序容器，不能直接使用hash模板，要提供自己的重载版本
class Sales_data
{
public:
    string isbn() const {};
};
size_t hasher(const Sales_data &sd)
{
    return hash<string>()(sd.isbn());
}
bool eqOp(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}
void test2()
{
    using SD_multiset = unordered_set<Sales_data, decltype(hasher) *, decltype(eqOp) *>;
    //参数是桶的大小，哈希函数指针和相等性判断运算指针
    SD_multiset bookstore(42, hasher, eqOp);
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}