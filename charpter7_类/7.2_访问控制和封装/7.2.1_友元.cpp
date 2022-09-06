#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

Sales_data &add(const Sales_data &s1, const Sales_data &s2);
istream &read(istream &input, Sales_data &s);
ostream &print(ostream &output, const Sales_data &s);

//类可以运行其它类或者函数访问他的非公有成员，为类非成员函数接口提供访问私有成员的能力
//友元
class Sales_data
{
    //一般来说，最好在类的开始或者结尾集中定义友元，友元函数最好在使用之前声明
    friend Sales_data &add(const Sales_data &s1, const Sales_data &s2);
    friend istream &read(istream &input, Sales_data &s);
    friend ostream &print(ostream &output, const Sales_data &s);

public:
    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revernue(p * n) {}
    Sales_data(std::istream &input);
    string isbn() const
    {
        return bookNo;
    }
    Sales_data &combine(const Sales_data &rhs);

private:
    string bookNo;
    unsigned units_sold = 0;
    double revernue = 0.0;
    double avg_prive() const;
};

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

void test1()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}