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
    一、一些算法使用重载形式传递一个谓词
        接受参数来代替< == 运算符的算法，以及那些不接受额外参数的算法，通常都是重载的函数
        unique(beg, end);  使用==运算符比较元素
        unique(beg, end, comp) 使用comp比较元素

    二、_if版本的算法
        接受一个元素值的算法通常有另外一个不同名的（不是重载的）版本，该版本接受一个谓词代替元素值
        find(beg, end, val)
        find_if(beg, end, pred)  查找第一个令pred为真的元素

    三、区分拷贝元素的版本和不拷贝的版本
        默认情况下，重排元素的算法将重排后的元素写会给定的输入序列中；另外一个版本将元素写到一个指定的输出目的位置
        reverse(beg, end); //反转输入范围中元素的排序
        reverse_copy(beg, end, dest) //将元素按逆序拷贝到dest
        romove_if(v1.begin(), v1.end(), [](int i){return i % 2;});//从v1中删除奇数元素
        remove_copy_if(v1.begin(), v1.end(), back_inserter(v2), [](int i){return i % 2;});//将偶数元素从v1拷贝到v2，v1不变
 */
void test1()
{
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}