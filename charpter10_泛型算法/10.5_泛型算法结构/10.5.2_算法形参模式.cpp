#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <algorithm>
using namespace std;
/*
    4种形式：
    alg(beg, end, other args)
    alg(beg, end, dest, other args)
    alg(beg, end, beg2, other args)
    alg(beg, end, beg2, end2, other args)
 */

//一、接受单个目标迭代器的算法
void test1()
{
    // dest参数是一个表示算法可以写入目的位置的迭代器
    // 向输出迭代器写入数据的算法都假定目标空间足够容纳写入的数据
}

//二、接受第二个输入序列的算法
// 第二个序列至少和第一个序列一样大
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}