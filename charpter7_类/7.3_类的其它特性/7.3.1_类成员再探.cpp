#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Screen
{
public:
    typedef string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd, char c) : height(ht), width(wd), content(ht * wd, c) {}
    char get() const //读取光标处的字符
    {
        return content[cursor]; //隐式内联
    }
    inline char get(pos r, pos c) const; //显示内联
    Screen &move(pos r, pos c);          //能在之后被设为内联

    void some_member() const
    {
        ++access_ctr; //虽然some_member是个const函数，但是仍可改变可变数据成员
    }

private:
    string content;
    pos cursor = 0;
    pos height = 0, width = 0;

    mutable size_t access_ctr; //可变数据成员，任何函数都能改变他的值
};
inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width; //计算行的位置
    cursor = row + c;    //在行内将光标移动到指定的列
    return *this;
}
inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;     //计算行的位置
    return content[row + c]; //返回给定列的字符
}

class Window_mgr
{
private:
    vector<Screen> screens{Screen(24, 80, ' ')};//类数据成员的初始值
};

void test1()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}