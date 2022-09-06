#include <iostream>
#include <cctype>
#include <string>
using std::string;
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void test1()
{
    // empty() size()
    // vector<int>::size_type n; 正确
    // vector::size_type n;错误
}

//可以用下标访问已存在元素，不可以用下标添加元素
void test2()
{
}

void exer3_16()
{
    vector<int> nums;
    for (int i = 0; i < 10; i++)
    {
        nums.push_back(i);
    }
    for (auto i : nums)
    {
        cout << i << '\t';
    }
    cout << endl;
}
void exer3_17()
{
    vector<string> text;
    string word;
    while (cin >> word)
    {
        if (word == "q")
            break;
        text.push_back(word);
    }
    for (auto s : text)
    {
        for (auto c : s)
        {
            c = toupper(c);
            cout << c;
        }
        cout << endl;
    }
}
void exer3_20()
{
    vector<int> nums;
    int n;
    cout << "请输入你要输入的一组整数，用空格分隔：" << endl;
    while (cin >> n)
    {
        nums.push_back(n);
    }
    vector<int>::size_type i = 0, j = nums.size() - 1;
    for (; i < j; i++, j--)
    {
        cout << nums[i] + nums[j] << endl;
    }
    if (i == j)
        cout << nums[i] << endl;
}
int main(int argc, const char *argv[])
{
    exer3_20();
    return 0;
}