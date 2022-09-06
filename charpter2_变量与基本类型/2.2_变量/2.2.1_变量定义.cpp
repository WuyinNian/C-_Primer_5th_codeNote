#include <iostream>
#include <string>
using namespace std;
// 初始值
//初始化不是赋值，初始化是在创建变量时赋予其一个初始值
//赋值是擦除当前对象的值，用一个新的值来替代
void test1()
{

}

//列表初始化
void test2()
{
    long double pi = 3.1415926536;
    int a = {pi};//C++11之前因为可能因为存在精度缺失，而报错，因为可以通过报错保证了精度不缺失
    int b = (pi);//编译通过，精度缺失
    int c = pi;//编译通过，精度缺失
}

//默认初始化
int b;//函数体外的内置类型会被初始化为0
void test3()
{
    //函数内内置数据类型不被初始化
    int v;
    cout<<v<<endl;//理论上v无法访问，值为1？编译器不被要求报此类错误
    cout<<b<<endl;//0

    //绝大多数类支持不显示初始化
    string s;//""空串

}

//练习
string str;
int i;
void exer()
{
    int li;
    string ls;
    cout<<str<<endl;//""
    cout<<i<<endl;//0
    cout<<li<<endl;//1  
    cout<<ls<<endl;//""

}
int main(int argc, const char * argv[]){
    exer();
    return 0;
}