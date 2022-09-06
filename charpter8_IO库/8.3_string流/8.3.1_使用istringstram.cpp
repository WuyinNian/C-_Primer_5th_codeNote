#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phones;
};
void test1()
{
    string line, word;         //分别保存输入的行和单词
    vector<PersonInfo> people; //保存来自输入的所有记录
    while (getline(cin, line))
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
}

//练习
void exer8_10()
{
    ifstream in("sample");
    if (!in)
        cout << "error!" << endl;
    vector<string> words;
    string line, word;
    while (getline(in, line))
    {
        words.push_back(line);
    }
    in.close();

    vector<string>::const_iterator it = words.begin();
    while (it != words.end())
    {
        istringstream iss(*it);
        while (iss >> word)
        {
            cout << word << " ";
        }
        cout << endl;
        ++it;
    }
}
void exer8_11()
{
    string line, word;         //分别保存输入的行和单词
    vector<PersonInfo> people; //保存来自输入的所有记录
    istringstream record;      //讲记录绑定到刚读入的行
    while (getline(cin, line))
    {
        PersonInfo info; //创建一个保存来自输入的所有记录
        record.clear();  //重复使用字符串流时，每次都要调用clear
        record.str(line);
        record >> info.name;   //读取名字
        while (record >> word) //读取电话号码
        {
            info.phones.push_back(word); //保持他们
        }
        people.push_back(info); //讲一个人的记录追加到people末尾
    }
}
int main(int argc, const char *argv[])
{
    exer8_10();
    return 0;
}