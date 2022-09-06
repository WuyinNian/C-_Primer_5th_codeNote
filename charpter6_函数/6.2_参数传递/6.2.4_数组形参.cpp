#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//数组的两个重要性质
// 1.数组不允许拷贝
// 2.在使用数组时通常会将其转换为指针
//所以我们无法使用值传递的方式使用数组参数，而是使用数组首元素的指针
//以下三个函数是等价的，传入的参数类型均为const int*
// void print(const int *arr){};
// void print(const int arr[]){};
// void print(const int arr[10]){}; //我们期望数组里有多少元素，实际传入参数时不一定
void test1()
{
    int i = 0, j[2] = {1, 2};
    // print(&i);
    print(j); // j转换成int*指向j[0]
}

//以数组作为形参时，也保证不越界，因为传入的是首元素的指针而不知道数组的尺寸，所以有三种方式来管理
//一、使用标记指定数组长度，适用于数据中有明显标记的，像int这种就不适用
void print(const char *p)
{
    if (p)
    {
        while (*p)
        {
            cout << *(p++) << endl;
        }
    }
}
//二、使用标准库规范
void print(const int *begin, const int *end)
{
    while (begin != end)
    {
        cout << *begin++ << endl;
    }
}
//三、显示传递一个表示数组大小的形参
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        cout << ia[i] << endl;
    }
}
void test2()
{
    int nums[2] = {1, 2};
    print(begin(nums), end(nums));
    print(nums, end(nums) - begin(nums));
}

//数组引用形参
void print(int (&arr)[2])
{
    for (auto i : arr)
    {
        cout << i << endl;
    }
}
void test3()
{
    int i = 0, j[2] = {1, 2};
    int k[3] = {1, 2, 3};
    // print(&i);实参不是含有10个元素的数组
    // print(k);实参不是含有10个元素的数组
    print(j);
}

//传递多维数组
//matrix指向数组的首元素，该元素是指向含有10个int值的数组
////等价定义:void print(int matrix[][10],size_t size){}
void print(int (*matrix)[10],size_t size){}
void test4()
{

}
int main(int argc, const char *argv[])
{
    test3();
    return 0;
}