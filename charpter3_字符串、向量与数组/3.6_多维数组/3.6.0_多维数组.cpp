#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//初始化
void test1()
{
    int arr1[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}};
    int arr2[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr3[3][4] = {{0}, {1}, {2}};
    int arr4[3][4] = {0, 1, 2, 3};
}

//下标引用
void test2()
{
    int arr[1][2][3];
    int arr1[2][3];
    //用arr的首元素为arr最后一行最后一个元素赋值
    arr1[1][2] = arr[0][0][0];
    //把arr2绑定到arr1的第二行元素数组上
    int(&arr2)[3] = arr1[1];

    // 范围for循环遍历
    int cnt = 0;
    for (auto &row : arr1) // int (&row)[3]
    {
        for (auto &col : row)
        {
            col = cnt;
            cnt++;
        }
    }

    //使用范围for循环处理多维数组时，除了最内层for循环，其他层均需要使用&引用
    //防止转化成指针
    for (const auto &row : arr1)
    {
        for (auto col : row)
        {
            cout << col << '\t';
        }
        cout << endl;
    }

    //指针与多维数组
    int(*p)[3] = arr1; // p指向含有4个整数的数组
    // int *p[3];p是以整型指针为元素的数组
    p = &arr1[1]; // p指向arr1的最后一行
}

void test3()
{
    int arr1[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}};

    for (auto p = arr1; p != arr1 + 3; p++)
    {
        for (auto q = *p; q != *p + 4; q++)
        {
            cout << *q << '\t';
        }
        cout << endl;
    }

    for (auto p = begin(arr1); p != end(arr1); p++)
    {
        for (auto q = begin(*p); q != end(*p); q++)
        {
            cout << *q << '\t';
        }
        cout << endl;
    }

    //类型别名简化多位数组指针
    using int_array = int[4];
    for (int_array *p = arr1; p != arr1 + 3; p++)
    {
        for (int *q = *p; q != *p + 4; q++)
        {
            cout << *q << '\t';
        }
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr1[i][j] << '\t';
        }
        cout << endl;
    }
}

int main(int argc, const char *argv[])
{
    test3();
    return 0;
}