#include <iostream>
#include <string>
using namespace std;
void test1()
{
    //对常量的引用
    const int i = 1024;
    const int &ii = i;
    // ii = 2048;报错，对常量的引用与普通引用不同，无法通过引用修改值，
    // int &iii = i;报错，非常量引用试图指向一个常量
    int j = 2048;
    const int &jj = j;//允许将const引用绑定到与之对应类型的常量上,但不允许通过此引用修改值
    // jj = 20; 
    // int &jjj = jj * 2;错误，

    //绑定过程中出现类型转换
    double pi = 3.14;
    //const int tmp = pi; const int &a = tmp;临时量
    //此时a绑定的是临时量，而不是pi
    const int &a = pi;

}
int main(int argc, const char * argv[]){
    test1();
    return 0;
}