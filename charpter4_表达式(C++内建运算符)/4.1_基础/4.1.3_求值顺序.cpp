#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void test1()
{
    //对于没有指定执行顺序的运算符，如果表达式指向并修改了同一个对象，将发生错误并产生为定义行为
    int i = 0;
    cout << i << " " << ++i << endl;//不确定i先执行 还是++i先执行
    
    //四种运算符明确规定执行顺序：
    //&&  
    //||
    //?:
    //, 

    //建议处理方式：加括号 保险
}

int main(int argc, const char *argv[])
{
    test1();
    return 0;
}