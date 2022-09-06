#include <iostream>
#include <string>
using namespace std;

//顶层const可以表示任意对象为常量
//底层const表示指针（引用）所指向（绑定）的对象是常量
void test1()
{
    int i = 3;
    int *const p1 = &i;//顶层const
    const int j = 88;//顶层const
    const int *p2 = &i;//底层const
    const int &ref = i;//底层const
    const int *const p3 = &i;//左边底层const ， 右边顶层const

    //对象执行拷贝操作时二者的区别
    //顶层const不受影响
    i = j;
    p2 = p3;
    //拷入拷出有相同的底层const，非常量可以拷贝给常量，反之不行
    // int *p4 = p1; x
    p2 = p3;
    // p3 = p2; x
    p2 = &i;
    // int &r = j; x
    const int &r2 = i;
}
int main(int argc, const char * argv[]){
    test1();
    return 0;
}