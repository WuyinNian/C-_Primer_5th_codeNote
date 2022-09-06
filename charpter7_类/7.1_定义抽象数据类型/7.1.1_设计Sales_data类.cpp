#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

class Sales_data
{
private:
    string bookNo;
    unsigned units_sold = 0;
    double sellingprice = 0.0;
    double saleprice = 0.0;
    double discount = 0.0;

public:
    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &rhs);
};
Sales_data &add(const Sales_data &s1, const Sales_data &s2)
{
}
istream &read(istream &input, Sales_data &s)
{
}
ostream &print(ostream &output, const Sales_data &s)
{
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