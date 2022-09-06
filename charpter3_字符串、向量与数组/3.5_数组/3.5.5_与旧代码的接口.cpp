#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void test1()
{
    string s = "hello";
    const char *str = s.c_str();
    const char *str1 = s.c_str();
    cout << str << endl;
    cout << str1 << endl;

    //用数组初始化vector
    char ch[] = "hello";
    vector<char> v(begin(ch), end(ch));
    vector<char> v2(ch+1, ch+3);
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}