#include <iostream>
#include <string>
using namespace std;

//C++11
//auto声明符让编译器帮我们分析表达式表示的类型
void test1()
{
    //一个auto声明只能有一个基本类型
    auto x = 3,*p = &x;
    // auto sz = 0,pi = 3.14; x

    //识别的是引用对象的类型
    int i = 9,&r = i;
    auto a = r;

    //auto会忽略顶层const 保留底层auto
    const int b = a, &r2 = b;
    auto c = b;//b的顶层特性被忽略掉
    auto d = r2;//r2是b的别名，b是一个顶层const
    auto e = &a;//整型指针
    auto f = &b;//指向整形常量的指针（对整型常量b取地址是底层const）
    auto *j = &b;

    //如果需要保留顶层const
    const auto g = b;//auto推演的类型是int，g 是const auto
    auto &h = b;//h是绑定整形常量的引用
    // auto &i = 88; x 非整型常量 不能绑定整型常量
    const auto &k = 88;
}
int main(int argc, const char * argv[]){
    test1();
    return 0;
}