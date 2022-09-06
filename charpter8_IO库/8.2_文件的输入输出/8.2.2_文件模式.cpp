#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//一、以out模式打开文件会丢弃已有数据
void test1()
{
    // a.out会被截断
    ofstream out("a.out");
    ofstream out2("a.out", ofstream::out);
    ofstream out3("a.out", ofstream::out | ofstream::trunc);

    //保留ofstream打开的文件中已有数据的唯一方法是显式指定app或in模式
    ofstream app("a.out", ofstream::app);
    ofstream app("a.out", ofstream::out | ofstream::app);
}

//二、每次调用open时都会确定文件模式
void test2()
{
    ofstream out;
    out.open("a.out");//模式隐含设置为 输出和截断
    out.close();
    out.open("a.out", ofstream::app);//模式输出为追加
    out.close();
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}