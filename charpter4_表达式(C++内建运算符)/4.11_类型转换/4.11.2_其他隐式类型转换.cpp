#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void test1()
{
    //数组转换成指针
    int ia[10];
    int *p = ia;//ia转换成指向数组首元素的指针

    //指针的转换,有继承关系的类型之间也存在另外一种指针转换关系
    int *p2 = 0;
    p2 = nullptr;

    //转换成bool类型
    // if(cp) :
    //while(*p)
    char *cp;

    //转换成常量
    int i;
    const int &ref1 = i;
    const int *p = &i;
    
    //类类型转换
    string s = "dasjlkd";//字符串字面值转换成string类型
    while(cin>>s);//cin转换成bool
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}