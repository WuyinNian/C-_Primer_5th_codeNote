#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//如果成员是const、引用或者或者某种未提供默认构造函数的类类型，我们必须通过
//构造函数初始值列表为这些成员提供初值
class ConstRef
{
public:
    ConstRef(int ii);

private:
    int i;
    const int ci;
    int &ri;
};
//建议养成使用构造函数初始值的习惯
//初始化的顺序只与数据成员在类中出现的次序有关，而与初始值列表的顺序无关
//不能同时存在两个有默认实参的构造函数，否则会产生二义性，因为有默认实参的构造函数为默认构造函数
ConstRef::ConstRef(int ii) : i(ii), ci(ii), ri(ii) {}
void test1()
{
}


int main(int argc, const char *argv[])
{
    test1();
    return 0;
}