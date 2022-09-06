#include <iostream>
#include <string>
using namespace std;


extern const int bufsize = 1024;////如果const对象想在其他文件共享，则需要加上extern
void test1()
{
    // const对象必须初始化
    const int size = sizeof(int);
    const int a = 10;
    // const int b;报错
    int b = a;

    //默认状态下，const对象仅在文件内有效
    //如果const对象想在其他文件共享，则需要加上extern
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}