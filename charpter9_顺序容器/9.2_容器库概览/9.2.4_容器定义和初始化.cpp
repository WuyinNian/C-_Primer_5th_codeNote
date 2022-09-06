#include <iostream>
#include <cctype>
#include <string>
#include <array>
#include <vector>
using namespace std;

//一、将一个容器初始化为另一个容器的拷贝
//拷贝时，容器类型和元素类型必须相同
void test1()
{
    vector<string> authors = {"aa", "bb", "cc"};
    vector<const char *> articles = {"a", "an", "the"};

    vector<string> list2(authors);
    vector<string> list3(authors.begin(), authors.end());
}

//二、列表初始化
void test2()
{
    vector<string> authors = {"aa", "bb", "cc"};
    vector<const char *> articles = {"a", "an", "the"};
}

//三、与顺序容器大小相关的构造函数
void test3()
{
    vector<int> ivec(10, -1);
}

//四、标准库array具有固定大小
void test4()
{
    int digs[10] = {1,2,3,4,5,6,7,8,9,0};
    array<int, 10>::size_type i;
    array<int, 10> j;
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}