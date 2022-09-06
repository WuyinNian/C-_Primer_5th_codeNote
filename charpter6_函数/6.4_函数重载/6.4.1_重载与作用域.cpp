#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//如果我们在内层作用域声明名字，他将屏蔽外层作用域中的同名实体
string read();
void print(const string &);
void print(double);
void test1()
{
    bool read = false;//屏蔽read（）函数
    // string s = read();错误
    void print(int);
    // print("value");错误
    print(3.14);//正确，调用的是print(int)
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}