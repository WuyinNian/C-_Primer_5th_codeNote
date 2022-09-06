#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

void test1()
{
    char ca[] = {'C', '+', '+', '\0'};
    cout << strlen(ca) << endl; // ca必须以空字符结尾，不然会strlen会往前遇到空字符结束
}

//比较字符串
void test2()
{
    string s1 = "nianwuyin";
    string s2 = "nianwuyio";
    if (s1 > s2) // nianwuyio
        cout << s1 << endl;
    else
        cout << s2 << endl;

    const char ch1[] = "nianwuyin";
    const char ch2[] = "nianwuyio";
    // if (ch1 > ch2) // nianwuyin,无定义，试图比较两个无关地址
    //     cout << ch1 << endl;
    // else
    //     cout << ch2 << endl;
    if (strcmp(ch1, ch2) > 0) // nianwuyio
        cout << ch1 << endl;
    else
        cout << ch2 << endl;
}

//目标字符串的大小由调用者指定
void test3()
{
    string s1 = "nianwuyin";
    string s2 = "nianwuyio";
    char ch1[] = "nianwuyin";
    char ch2[] = "nianwuyio";

    string s = s1 + " " + s2;
    cout << s << endl;

    char ch[21] = ""; //估计错，容易出错
    strcpy(ch, ch1);
    strcat(ch, " ");
    strcat(ch, ch2);
    cout << ch << endl;
}
int main(int argc, const char *argv[])
{
    test3();
    return 0;
}