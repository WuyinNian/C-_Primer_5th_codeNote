#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

//将文本文件根据指定规则转换成另一个文本
//一、单词转换程序
//二、建立转换映射
//三、生成转换文本
map<string, string> buildMap(ifstream &map_file)
{
    map<string, string> m;
    string key;
    string value;
    string line;
    while (map_file >> key && getline(map_file, value))
    {
        if (value.size() > 1)
        {
            m[key] = value.substr(1);
        }
        else
        {
            cout << "no rule of " << key << endl;
        }
    }
    return m;
}
const string &transform(const string &s, map<string, string> &m)
{
    auto map_it = m.find(s);
    if (map_it != m.end())
    {
        return map_it->second;
    }
    else
    {
        return s;
    }
}
void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while (getline(input, text))
    {
        istringstream stream(text);
        string word;
        bool fristword = true;
        while (stream >> word)
        {
            if (fristword)
            {
                fristword = false;
            }
            else
            {
                cout << " ";
            }
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}
void test1()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}