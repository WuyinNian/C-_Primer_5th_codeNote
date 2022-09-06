#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//确定候选函数和可行函数
//函数匹配第一步：确定候选函数
//候选函数两个特征：1.与被调用函数同名；2.在调用点可见
//第二步考察本次调用提供的实参，然后从候选函数中选出能被这组实参调用的函数，称为可行函数
void test1()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}