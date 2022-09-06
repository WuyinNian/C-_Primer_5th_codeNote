#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void swap(int a, int b)
{
    int tmp = b;
    b = a;
    a = tmp;
}
void swap2(int *a,int *b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}
void test1()
{
    int a = 1, b = 2;
    //初始化非引用类型变量时，初始值拷贝给变量
    swap(a, b);
    cout << "a=" << a << ", b=" << b << endl;
    //当执行指针拷贝操作时，拷贝的是指针的值，拷贝后，两个指针是不同的指针，但是所指的对象是一样的，所以我们可以通过操作指针修改所指对象
    swap2(&a, &b);
    cout << "a=" << a << ", b=" << b << endl;
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}