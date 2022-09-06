#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void test1()
{
    //a[b], b是数组的维度，必须是一个常量表达式
    //数组中的元素必须是对象，所以不存在数组元素为引用的数组
    unsigned int cnt = 42;//?
    constexpr unsigned n = 42;
    int arr[10];
    int *ptrs[n];
    string nums[cnt];
}

void test2()
{
    //显示初始化数组    
    int arr1[3] = {1,2,3};
    int arr2[] = {1,2,3};
    int arr3[5] = {1,2,3};//剩下 默认初始化

    //字符数组,结尾有一个空字符
    char a1[] = "C++";//char a1[4];

    //不允许拷贝和赋值
    // int arr3[] = arr1;不允许用数组初始化数组
    // arr3 = arr1;不允许把一个数组直接赋给数组（有些编译器扩展允许，建议使用标准规定）
}

//复杂数组声明，由内向外阅读
void test3()
{
    int *arr1[10];//元素对象是  指向int的指针
    int arr2[10];
    int (*arr3)[10] = &arr2;//arr3 指向一个含有10个元素的数组
    int (&arr4)[10] = arr2;//arr4 引用一个含有10个元素的数组 
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}