#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Sales_data
{
public:
    string bookNo;
    unsigned units_sold = 0;
    double revernue = 0.0;

    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {} //冒号和括号之间的内容：构造函数初始值列表
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revernue(p * n) {}
    Sales_data(std::istream &input);

    string isbn() const
    {
        return bookNo; //在类内，bookNo定义在isbn后面，isbn也能调用bookNo，因为编译器首先编译成员声明，再编译成员函数体
    }
    double avg_prive() const{};
    Sales_data &combine(const Sales_data &rhs){};
};
void test1()
{
    string null_book = "9-999-99999-9";
    Sales_data item;
    item.combine(null_book);//string隐式转换为Sales_data

    //只允许一步类类型转换
    // item.combine("1123");错误
}

//抑制构造函数定义的隐式转换
//将构造函数声明为explict加以阻止
//explict只作用于直接初始化，不作用于赋值
void test2()
{

}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}