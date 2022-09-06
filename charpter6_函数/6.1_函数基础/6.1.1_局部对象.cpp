#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//行参和函数体内部定义的变量为局部变量
void test1()
{
}

//自动对象：只存在块执行期间的对象

//局部静态对象,存在于函数调用后知道程序终止
size_t count_calls()
{
    static size_t count = 0;
    return ++count;
}
void test2()
{
    for(int i=0;i<10;i++)
        cout<<count_calls()<<endl;
}
int main(int argc, const char *argv[])
{
    test2();
    return 0;
}