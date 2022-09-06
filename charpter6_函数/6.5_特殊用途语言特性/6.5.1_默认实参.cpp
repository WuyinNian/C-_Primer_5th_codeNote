#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

typedef string::size_type sz;
void test1()
{
    //一旦形参被赋予默认值，其后面的形参必须有默认值
    string screen(sz ht = 24, sz wid = 48, char backgrnd = ' ');
    string window = screen();
    window = screen(66);
    window = screen(66, 256);
    window = screen(66, 256, '#');

    // window = screen(,,'?');只能省略尾部的实参
    window = screen('?'); //等价于window = screen('?',48,' ');
}

//默认形参初始值
sz wd = 80;
sz ht();
char def = ' ';
string screen(sz = ht(), sz = wd, char def);
string window = screen(); // screen(ht(),80,' ')
void text2()
{
    def = '*';
    sz wd = 100;
    window = screen(); // screen(ht(),80,'*')
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}