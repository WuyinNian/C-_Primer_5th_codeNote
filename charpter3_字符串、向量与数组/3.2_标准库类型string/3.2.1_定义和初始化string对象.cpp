#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

void test1()
{
    //直接初始化
    string s1;
    string s2(s1);
    string s6(5,'v');
    string s4("value");

    //拷贝初始化
    string s3 = s1;
    string s5 = "value";
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}