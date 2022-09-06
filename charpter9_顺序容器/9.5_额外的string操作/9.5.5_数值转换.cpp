#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
using namespace std;


void test1()
{
    int i = 42;
    string s = to_string(i);
    double d = stod(s);

    string s2 = "pi = 3.14";
    d = stod(s2.substr(s2.find_first_of(+-.0123456789)));
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}