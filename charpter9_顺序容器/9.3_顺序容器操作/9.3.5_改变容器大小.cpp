#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
using namespace std;

//array不支持resize
void test1()
{
    list<int> ilist(10,42);
    ilist.resize(15);//将5个0，添加到末尾
    ilist.resize(25,-2);//将10个值为-1的元素添加到ilist末尾
    ilist.resize(-5);//将ilist末尾删除20个元素
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}