#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
using namespace std;

//成功返回string::size_type
//失败返回string::npos static成员，-1, const string::size_type
void test1()
{
    string names("AnnaBelle");
    auto pos1 = names.find("Anna"); // pos1==0

    //大小写敏感
    string lowercase("annabelle");
    auto pos2 = lowercase.find("Anna"); // pos2==npos

    //定位name中第一个数字下标
    string numbers("0123456789"), name("r2d2");
    auto pos = name.find_first_of(numbers); // 1
    //定位不在参数中第一个字符
    string dept("4279d348");
    pos = dept.find_first_not_of(numbers); // 4

    //一、指定从哪里开始搜索
    pos = 0;
    while ((pos = name.find_first_of(numbers, pos)) != string::npos)
    {
        cout << "found number at index: " << pos << " elemnt is " << name[pos] << endl;
        ++pos;
    }

    //逆向搜索
    string river("Mississippi");
    auto first_pos = river.find("is");//1
    auto last_pos = river.rfind("is");//4
}

int main(int argc, const char *argv[])
{
    test1();
    return 0;
}