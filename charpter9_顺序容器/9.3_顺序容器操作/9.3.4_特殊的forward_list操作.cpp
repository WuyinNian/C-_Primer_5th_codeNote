#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <forward_list>
#include <deque>
using namespace std;

// forwad_list中的插入或删除元素的操作要关注两个迭代器，目标元素及其前驱
void test1()
{
    forward_list<int> flst = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto prev = flst.before_begin(); //表示flst的首前元素
    auto curr = flst.begin();
    while (curr != flst.end())
    {
        if (*curr % 2)
            curr = flst.erase_after(prev);
        else
        {
            prev = curr;
            ++curr;
        }
    }
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}