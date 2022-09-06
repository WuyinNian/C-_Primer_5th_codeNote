#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

void test1()
{
    vector<int> v;
    for (int i = 0; i < 21; i++)
    {
        v.push_back(i + 1);
    }
    auto diff = v.begin() - v.end(); // difference_type:带符号整型
    cout << "diff:" << diff << endl;
    auto l = v.begin();
    auto r = v.end();
    auto mid = v.begin() + (r - l) / 2;//迭代器中为定义加法，所以不用（r+l）/2
    int target = 10;
    while (mid != r && *mid != target)
    {
        if (target < *mid)
            r = mid - 1;
        else
            l = mid + 1;
        mid = l + (r - l) / 2;
    }
    cout << *mid << endl;
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}