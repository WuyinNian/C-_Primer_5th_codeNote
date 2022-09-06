#include <iostream>
#include <string>
using namespace std;

struct Sales_data
{
    //C++11 可以为设定类内初始值
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

void test1()
{
    //......
}
int main(int argc, const char * argv[]){
    test1();
    return 0;
}