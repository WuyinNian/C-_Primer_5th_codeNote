#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <list>
using namespace std;

//多个版本
//当不需要写访问时，应该使用cbegin和cend
void test1()
{
    list<string> a = {"aa","bb","cc"};
    auto it1 = a.begin();//list<string>::iterator
    auto it2 = a.rbegin();//list<string>::reverse_iterator
    auto it3 = a.cbegin();//list<string>::const_iterator
    auto it4 = a.crbegin();//list<string>::const_reverse_iterator
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}