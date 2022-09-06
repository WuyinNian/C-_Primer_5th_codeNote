#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void test1()
{
    if(1)
    ;

    if(1)
    ;
    else
    ;

    //嵌套if

    //注意使用花括号
}

//垂悬else，有多个if，else应该和谁匹配
//C++规定按就近原则分配
void test2()
{

}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}