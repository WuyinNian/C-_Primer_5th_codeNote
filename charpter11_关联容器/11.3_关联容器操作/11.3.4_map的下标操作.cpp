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

//mape和unordered_map提供下标运算符和at
void test1()
{
    //[]下标运算符，map[key]=mapped，如果元素不存在，会创建一个元素
    //只能对非const的map使用

    //一、使用下标操作的返回值
    // 返回mapped_type 左值
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}