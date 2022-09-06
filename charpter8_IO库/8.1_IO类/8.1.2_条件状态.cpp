#include <iostream>
#include <stdexcept>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void test1()
{
    int val;
    cin >> val; //如果输入字符则cin进入错误状态

    // 确定一个流对象的状态最简单的方法是将它当作一个条件来使用
    while (cin >> val)
    {
    }
}

/*
    一、查询流的状态:
    badbit:系统级错误
    failbit:可恢复错误
    eofbit,failbit:文件结束
    goodbit:为0，为发生错误
*/

/*
    二、管理条件状态：


*/
void test2()
{
    auto old_state = cin.rdstate(); //记录cin的当前状态
    cin.clear();                    //使cin有效
    // process_input(cin);//使用cin
    cin.setstate(old_state); //将cin置为原有状态
}

// exer8.1
istream &get(istream &is)
{
    char c;
    auto old_state = is.rdstate();
    while (is >> c, !is.eof())
    {
        if (is.bad())
        {
            throw runtime_error("IO流错误");
        }
        if (is.fail())
        {
            cerr << "data error, try again:" << endl;
            is.clear();
            is.ignore(100, '\n');
            continue;
        }
        cout << c << endl;
    }
    is.clear();
    return is;
}
void exer8_1()
{
    get(cin);
}
int main(int argc, const char *argv[])
{
    exer8_1();
    return 0;
}