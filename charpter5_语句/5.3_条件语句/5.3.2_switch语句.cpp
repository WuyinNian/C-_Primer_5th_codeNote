#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void test1()
{
    // case 对应的值必须是整型常量表达式
    switch (1)
    {
    case 1:
        break;
    default:
        break;
    }
}


int main(int argc, const char *argv[])
{
    test1();
    return 0;
}