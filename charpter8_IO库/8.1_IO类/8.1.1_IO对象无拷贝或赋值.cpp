#include <fstream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;


//由于不能拷贝IO对象，故通常以引用方式传递和返回流，读写IO会改变其状态，因此传递和返回的引用不能是const的
void test1()
{
    ofstream out1, out2;
    // out1 = out2; 错误：不能对流对象赋值
    // ofstream print(ofstream); 错误：不能初始化ofstream参数
    // out2 = print(out2); 错误：不能拷贝流对象
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}