#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

/* 
    一、迭代器范围：迭代器范围的概念是标准库的基础 
    [begin,end)

    二、使用左闭合范围蕴含的编程假定
        1. begin == end, 则范围为空
        2. begin != end， 则范围至少包含一个元素
        3. begin递增可以使得 begin==end
*/
void test1()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}