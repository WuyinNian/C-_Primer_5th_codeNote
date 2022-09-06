#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};
bool valid(string nums)
{
    return true;
}
string format(const string &nums)
{
    return nums;
}
void test1()
{
    string line, word;         //分别保存输入的行和单词
    vector<PersonInfo> people; //保存来自输入的所有记录
    ifstream in("sample");
    if (!in)
        cerr << "error!" << endl;
    while (getline(in, line))
    {
        PersonInfo info;            //创建一个保存来自输入的所有记录
        istringstream record(line); //讲记录绑定到刚读入的行
        record >> info.name;        //读取名字
        while (record >> word)      //读取电话号码
        {
            info.phones.push_back(word); //保持他们
        }
        people.push_back(info); //讲一个人的记录追加到people末尾
    }
    in.close();

    ostringstream os;
    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
        {
            if (!valid(nums))
            {
                badNums << " " << nums;
            }
            else
            {
                formatted << " " << format(nums);
            }
        }
        if (badNums.str().empty())
            os << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input error: " << entry.name << " invalid numbers " << badNums.str() << endl;
    }
    cout << os.str();
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}