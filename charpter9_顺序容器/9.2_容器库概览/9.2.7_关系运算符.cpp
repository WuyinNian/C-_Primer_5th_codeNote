#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
using namespace std;

/*
    每个容器都支持==、!=
    除无序关联容器，< <= > >=
    比较规则：
        1. 大小相同，元素相对应
        2. 大小不同，小容器元素等于大容器元素，小容器小于大容器
        3。 两个容器都不是另一个前缀子序列，比较第一个不相等元素

    Note:只有当容器元素类型定义了相应的比较运算符时，才可以使用关系运算符比较两个容器
 */
void test1()
{
}

bool list_vector_equal(const vector<int> &v, const list<int> &l)
{
    if (v.size() != l.size())
        return false;

    auto vb = v.cbegin();
    auto ve = v.cend();
    auto lb = l.cbegin();
    for (; vb != ve; vb++, lb++)
    {
        if (*vb != *lb)
            return false;
    }
    return true;
}
void exer9_16()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}