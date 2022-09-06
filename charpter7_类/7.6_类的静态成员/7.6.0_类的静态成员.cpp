#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

// 一、声明静态成员
class Account
{
public:
    void calculate()
    {
        amount = +amount * interestRate;
    }
    static double rate()
    {
        return interestRate;
    }
    static void rate(double);

private:
    string owner;
    double amount;

    // static成员与所有Account成员共享
    static double interestRate;
    static double initRate();

    //使用初始化的静态数据成员指定数组成员的维度
    static constexpr int period = 30;
    double daily_tbl[period];
};

//二、使用类的静态成员
void test1()
{
    double r;
    r = Account::rate(); //使用作用域运算符访问静态成员

    //调用静态成员函数rate的等价形式
    Account ac1;
    Account *ac2 = &ac1;
    r = ac1.rate();
    r = ac2->rate();
}

//三、定义静态成员，类内，类外都能定义
void Account::rate(double newRate) // static关键字只出现在类内部的声明语句中
{
    interestRate = newRate;
}
double Account::interestRate = initRate();

//四、静态成员的类内初始化，见Account类

//五、静态成员能用于某些场景，2⃣️普通成员不能
class Bar
{
public:
private:
    static Bar mem1; //静态成员可以是不完全类型
    Bar *mem2;
    // Bar mem3 //非静态成员必须是完全类型
};
class Screen
{
public:
    Screen &clear(char c = bkground);//静态成员可以作为默认实参
    // Screen &clear(int i = x);//非静态成员不可以作为默认实参
private:
    static const char bkground;
    int x;
};

int main(int argc, const char *argv[])
{
    test1();
    return 0;
}