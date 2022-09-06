#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

//定义在类内的函数都是隐式inline函数
class Sales_data
{
public:
    string bookNo;
    unsigned units_sold = 0;
    double revernue = 0.0;


    //拷贝、赋值和析构
    //如果我们不主动定义他们，编译器将自动合成，但某些类不能依赖于合成的版本，详情12、13章中介绍

    //合成默认构造函数，只有类中没有声明任何构造函数，编译器才会自动生成默认构造函数
    //某些类不能依赖于默认构造函数，原因有三点：见书本
    //定义构造函数
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {} //冒号和括号之间的内容：构造函数初始值列表
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revernue(p * n) {}
    Sales_data(std::istream &input);

    //常量成员函数：
    /*
        默认情况下，this的类型：指向类类型非常量版本的常量指针，例如Sales_data *const，意味着我们不能把this绑定到一个常量对象上

        如果isbn()是一个普通函数且this是一个普通的指针参数，则我们应该把this声明成const Sales_data *const，毕竟在isbn函数体
        内，不会改变this所指的对象，所以把this设置为指向常量的指针有助于提高函数的灵活性

        然而，this是隐式的不会出现在参数列表里，所以在参数列表后面引入const表示this是一个指向常量的指针，像这样使用const的成员函数
        被称为常量成员函数

        因为this是指向常量的指针，故isbn()不会写入新值，只可以读取调用他对象的数据成员

        常量对象，及其指针或引用都只能调用常量成员函数
    */
    string isbn() const
    {
        return bookNo; //在类内，bookNo定义在isbn后面，isbn也能调用bookNo，因为编译器首先编译成员声明，再编译成员函数体
    }
    double avg_prive() const;
    Sales_data &combine(const Sales_data &rhs);
};

//在类外定义构造函数
Sales_data::Sales_data(istream &input)
{
    read(input, *this);
}

//在类的外部定义成员变量
double Sales_data ::avg_prive() const
{
    if (units_sold)
        return revernue / units_sold;
    else
        return 0;
}

//定义一个返回this对象的成员函数
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revernue += revernue;
    return *this; //返回调用该函数的对象
}

//一般来说，如果非成员函数是类的借口，则类的声明和这些函数的声明应该在同一个头文件中
Sales_data &add(const Sales_data &s1, const Sales_data &s2)
{
    Sales_data sum = s1;
    sum.combine(s2);
    return sum;
}
istream &read(istream &input, Sales_data &s)
{
    double price = 0.0;
    input >> s.bookNo >> s.units_sold >> price;
    s.revernue = s.units_sold * price;
    return input;
}
ostream &print(ostream &output, const Sales_data &s)
{
    output << s.isbn() << " " << s.units_sold << " "
           << s.revernue << " " << s.avg_prive();
    return output;
}

//使用改进的Sales_data类
void test1()
{
    Sales_data total;
    if (read(cin, total))
    {
        Sales_data trans;
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total.combine(trans);
            }
            else
            {
                print(cout, total);
                total = trans;
            }
        }
        print(cout, total);
    }
    else
    {
        cout << "Not data?" << endl;
    }
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}