#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//每个输出流管理一个缓冲区，用来保存程序读写的数据
/*
    导致缓冲刷新（即，数据真正写到输出设备或文件）的原因有很多：
    1.程序正常结束
    2.缓冲区满，需要刷新缓冲，而后新的数据才能继续写入缓冲区
    3.使用操纵符显示刷新缓冲区
    4.在每个输出操作后，用操纵符unitbuf设置流的内部状态来清空缓冲区。默认情况下，对cerr是设置unitbuf的，因此写到cerr的内容都是立即刷新的
    5.一个输出流可能被关联到另一个流。关联到的流的缓冲区会被刷新

    PS:程序崩溃是无法刷新缓冲区
*/

//一、刷新输出缓冲区
void test1()
{
    cout << "hi" << endl;
    cout << "hi" << flush;
    cout << "hi" << ends;
}

//二、unitbuf操作符
void test2()
{
    cout << unitbuf;
    //这之间的输出都立即刷新，无缓冲
    cout << nounitbuf;
}

//三、关联输入和输出流
void test3()
{
    //标准库在cout和cin关联在一起，所有输出都会在读操作之前被打印出来
    int ival;
    cin >> ival;// 该语句会导致cout的缓冲区被刷新

    //tie的两个重载版本
    //tie()，返回指向这个流的指针，如果对象未关联到流，则返回空指针
    //tie(ostreanm *o)，将自己关联到此ostream。即x.tie(&o)将流x关联到输出流o
    cin.tie(&cout);
    ostream *old_tie = cin.tie(nullptr);//cin不再与其它流关联
    cin.tie(&cerr);
    cin.tie(old_tie);
    // 每个流最多同时关联到一个流，多个流可以同时关联一个输出流
}

int main(int argc, const char *argv[])
{
    test1();
    return 0;
}