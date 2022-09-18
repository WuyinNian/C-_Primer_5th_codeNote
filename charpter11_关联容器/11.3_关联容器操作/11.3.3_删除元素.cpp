#include <iostream>
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

//三个版本的erase
void test1()
{
    map<string,int> m = {{"a",1},{"a",2},{"b",3},{"d",4}};
    //删除一个关键字，返回删除数量
    if(m.erase("a"))
        cout<<"ok "<<endl;
    else
        cout<<"not found"<<endl;

    
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}