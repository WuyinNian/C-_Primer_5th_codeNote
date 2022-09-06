#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void exer6_25(const char *s1, const char *s2)
{
    cout << string(s1) + string(s2) << endl;
}
//使用argv中的实参时，可选的实参从argv[1]开始，argv[0]保存程序的名字，而非用户输入
int main(int argc, const char *argv[])
{
    for (int i = 1; i <= 5; i++)
    {
        cout << argv[i] << endl;
    }
    return 0;
}