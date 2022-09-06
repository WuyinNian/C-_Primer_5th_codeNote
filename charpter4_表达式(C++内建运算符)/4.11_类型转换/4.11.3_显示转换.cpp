#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;


//避免使用强制类型转换
void test1()
{
    //强制类型转换
    int i, j;
    double slope = i / j;

    //命名的强制类型转换cast-name<type>(expression)
    // static_cast 只要不包含底层const，都可以使用static_cast
    void *p = &slope;
    double *dp = static_cast<double *>(p);

    // const_cast只能改变运算对象底层的const
    const char *pc;
    char *p = const_cast<char *>(pc);//正确，但通过p写值是未定义的

    //reinterpret_cast
    int *ip;
    char *pc = reinterpret_cast<char*>(ip);
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}