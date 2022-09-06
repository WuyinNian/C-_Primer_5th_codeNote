#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

//读写string对象
void test1()
{
    string s1;
    cin >> s1; //读到空白为止
    cout << s1 << endl;

    string s2;
    cin >> s1 >> s2; //第一个输入到s1，第二个输入到s2
    cout << s1 << s2 << endl;
}

//读写未知个数的string对象
void test2()
{
    string s;
    while (cin >> s)
    {
        cout << s << endl; //反复读取直到文件末尾
    }
}

//使用getline读取一整行
void test3()
{
    string line;
    getline(cin, line);//cin流中的换行符也读进来，但不存进line中而被抛弃，返回流参数

    while (getline(cin,line))//可以读空格
    {
        cout<<line<<endl;
    }
}

//empty()  size()
void test4()
{
    // string line;
    // while(getline(cin,line))
    // {
    //     if(!line.empty())
    //     {
    //         cout<<line<<endl;
    //     }
    // }

    // while(getline(cin,line))
    // {
    //     if(line.size()<5)//返回字符串的字符数
    //     {
    //         cout<<line<<endl;
    //     }
    // }

    string s = "123";
    cout<<s.size()<<endl;//返回字符串的字符数类型是,std::size_type,属于unsigned,足够大
    auto size = s.size();//std::size_t,切记，这是一个无符号整数
}

//比较string对象
void test5()
{
    string s1 = "Hello";
    string s2 = "Hello World!";//s1<s2
    string s3 = "Hi!";//s3>s2>s1
}

//字符串相加
void test6()
{
    string s1 = "hello";
    string s2 = "world!";
    //字符串字面值不是标准库类型string对象
    //+运算符两侧至少一个是string对象
    // string s3 = "hello" + "," + s2;//错误
}
int main(int argc, const char *argv[])
{
    test4();
    return 0;
}