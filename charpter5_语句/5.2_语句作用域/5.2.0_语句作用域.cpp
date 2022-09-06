#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//可以在if、switch、for、while控制结构内定义变量，相应的变量仅在语句内部可见
void test1()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}