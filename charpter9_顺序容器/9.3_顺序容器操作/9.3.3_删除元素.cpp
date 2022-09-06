#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
using namespace std;

/*
    一、pop_front和pop_back
        1. vector, string不支持前者
        2. forward_list不支持后者
        3. 不对空容器进行操作
        4. 返回void，如果需要保存，在弹出前保存它
*/
void test1()
{
}

/*
    二、从容器内部删除一个元素
        erase从指定迭代器位置删除元素，返回删除最后一元素的后一个位置的迭代器
 */
void test2()
{
    list<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto it = lst.begin();
    while (it != lst.end())
    {
        if (*it % 2)
            it = lst.erase(it);
        else
            ++it;
    }
}

/*
    三、删除多个元素
 */
void test3()
{
    vector<int> lst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto elem1 = lst.begin(), elem2 = lst.end();
    elem1 = lst.erase(elem1, elem2);

    lst.clear();
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}