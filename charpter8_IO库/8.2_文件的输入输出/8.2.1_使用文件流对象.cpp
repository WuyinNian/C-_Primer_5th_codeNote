#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void test1()
{
    ifstream in("a.out");
    ofstream out;
}

class Sales_data
{
public:
    string bookNo;
    unsigned units_sold = 0;
    double revernue = 0.0;

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
double Sales_data ::avg_prive() const
{
    if (units_sold)
        return revernue / units_sold;
    else
        return 0;
}
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revernue += revernue;
    return *this; //返回调用该函数的对象
}
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
//一、 用fstream代替iostream&
/* int main(int argc, const char *argv[])
{
    ifstream input(argv[1]);
    ofstream output(argv[2]);
    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    }
    else
        cerr << "No data?" << endl;
    return 0;
} */

//二、成员函数open和close
void test2()
{
    ifstream in("a.out");   //构筑一个ifstream并打开文件
    ofstream out;           //输文件流未与任何文件关联
    out.open("a.out.copy"); //打开指定文件
    if (out)                //检查open是否成功,如果失败failbit会置位
    {
    }
    in.close();        //关闭文件
    in.open("a.out2"); //打开另外一个文件，如果open成功，则open会设置流的状态，使得good()为true
}

//三、自然构造和析构
void test3(int argc, const char *argv[])
{
    for (auto p = argv + 1; p != argv + argc; ++p)
    {
        ifstream input(*p);
        if (input)
            cout << *p << endl;
        else
            cerr << "couldn't open: " + string(*p);
    } //每个循环步input会离开作用域而被销毁，close会自动被调用
}

//练习题
void exer8_4()
{
    ifstream input("a.out");
    if (!input)
    {
        cout << "couldn't open!" << endl;
    }
    string line;
    vector<string> words;
    while (getline(input, line))
    {
        words.push_back(line);
    }
    input.close();

    vector<string>::const_iterator it = words.begin();
    while (it != words.end())
    {
        cout << *it << endl;
        ++it;
    }
}
void exer8_5()
{
    ifstream input("a.out");
    if (!input)
    {
        cout << "couldn't open!" << endl;
    }
    string line;
    vector<string> words;
    while (input >> line)
    {
        words.push_back(line);
    }
    input.close();

    vector<string>::const_iterator it = words.begin();
    while (it != words.end())
    {
        cout << *it << endl;
        ++it;
    }
}
int main(int argc, const char *argv[])
{
    exer8_4();
    return 0;
}