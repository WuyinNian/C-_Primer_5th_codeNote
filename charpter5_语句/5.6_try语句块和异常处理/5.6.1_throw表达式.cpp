#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void test1()
{
    int a;
    int b;
    cin >> a >> b;
    if (a != b)
        throw runtime_error("Data must refer to same number.");
    cout << a + b << endl;
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}