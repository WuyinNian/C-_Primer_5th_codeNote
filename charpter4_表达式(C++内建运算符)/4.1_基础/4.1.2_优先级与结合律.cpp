#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void test1()
{
    int ia[] = {0,3,6,2,9};
    int last = *(ia+4);//last=9
    last = *ia + 4;//last = ia[0] + 4 = 4

    cin >> ia[0] >> last;//先读入ia[0],再读入last
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}