#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void test1()
{
    int a, b;
    while (cin >> a >> b)
    {
        try
        {
            if (a != b)
                throw runtime_error("Data must refer to same number.");
        }
        catch (runtime_error err)
        {
            cout << err.what() << "\nTry Again? y or n" <<endl;
            char c;
            cin >> c;
            if(c == 'n')
                break;
        }
    }
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}