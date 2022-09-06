#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void test1()
{
    string nums[] = {"one","two","three"};
    string *p1 = &nums[0];
    string *p2 = nums;// p1 <=> p2

    int arr1[] = {1,2,3};
    auto arr2(arr1);//arr2 指向int的指针
    decltype(arr1) arr3 = {2,3,4};//arr3  数组
    // arr3 = arr1; 数组无法拷贝赋值
    arr3[2] = 9; 

    //指针也是迭代器
    int *p3 = arr1;
    p3++;//指向arr1[1]
    int *p4 = &arr1[3];//尾后指针

    //定义在iterator头文件中,begin 和 end已数组为参数
    int *beg = begin(arr1);
    int *last = end(arr1);
    auto diff = begin(arr1) - end(arr1);
    cout<<diff<<endl;

    //内置的下标运算所用的索引值和vector和string不一样，是有符号类型的
    cout<<p4[-3]<<endl;//arr1[0]
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}