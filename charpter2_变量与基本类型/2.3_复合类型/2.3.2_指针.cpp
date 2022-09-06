#include <iostream>
#include <string>
using namespace std;

//指针
//指针本身是一个对象，可以先后指向不同的对象
//指针初始化与其他内置类型一致
void test1()
{
    int val = 42;
    int *p = &val;
    int *p2 = p;

    //类型要严格匹配
    // double *p3 = p;

    cout << *p << endl; //*解引用
    *p = 0;
    cout << *p << endl;
}

//空指针
void test2()
{
    int *p1 = nullptr;
    int *p2 = 0;
    int *p3 = NULL;

    int zero = 0;
    // int *p4 = zero;错误
}

// void* 指针
void test3()
{
    double pi = 3.14;
    void *p = &pi; // void*能存放任意类型指针
    // cout << *p << endl;//但是无法访问，因为对象类型不明确
}
int main(int argc, const char *argv[])
{
    test2();
    return 0;
}