#include <iostream>
#include <string>
using namespace std;
//声明：名字为程序所知，规定变量的类型和名字
//定义：负责创建与名字关联的实体，规定变量的类型和名字，并申请储存空间，可能初始化（取决于函数内外）
extern int i;      // 声明而非定义i
extern int ii = 1; //声明并定义i
int j;             //声明并定义j
void test()
{
    extern int a; //声明
    // extern int aa = 4; //无法初始化extern修饰的局部变量

    int k;        //声明
    int kk = 0;   //定义
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}