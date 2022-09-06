#include <iostream>
#include <string>
using std::string;
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void test1()
{
    vector<int> vec;
    for(int i = 0;i<100;i++)
    {
        vec.push_back(i);
    }

    vector<string> text;
    string word;
    while(cin>>word)
    {
        text.push_back(word);
    }
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}