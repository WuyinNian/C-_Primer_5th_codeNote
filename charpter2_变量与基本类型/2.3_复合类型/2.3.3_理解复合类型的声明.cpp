#include <iostream>
#include <string>
using namespace std;
void test1()
{
    //指向指针的指针
    int val = 42;
    int *p1 = &val;
    int **p2 = &p1;

    //指向指针的引用
    int *&ref = p1;
    *ref = 43;
    cout << val << endl;//43
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}