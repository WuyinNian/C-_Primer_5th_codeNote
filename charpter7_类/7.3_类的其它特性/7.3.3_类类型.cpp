#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//类不允许定义自身类型的成员，但可以定义指向自身类型的指针或引用
class Link_screen
{
    Link_screen *next;
    Link_screen &pre;
};
void test1()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}