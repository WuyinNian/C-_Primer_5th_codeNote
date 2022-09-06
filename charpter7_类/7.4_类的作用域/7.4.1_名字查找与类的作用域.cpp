#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//类内，编译器处理完全部的声明后再处理函数体
typedef double Money;
string bal;
class Account
{
public:
    Money balance()
    {
        return bal;
    }

private:
    // 一般来说，内层作用域可以重新定义外层作用域中的名字，但是对于类类型来说则不行，需要特殊处理
    // typedef double Money;错误，不能重新定义Money
    Money bal;
};
void test1()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}