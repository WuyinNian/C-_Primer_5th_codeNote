#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <stack>
using namespace std;

/*
    三个顺序容器适配器：stack、queue、priority_queue
    本质上：一个适配器是一种机制，能使某种事物的行为看起来像另外一种事物一样
 */

//一、定义一个适配器
//对给定的适配器，使用哪些容器是有限制的，取决于容器和适配器功能匹配
void test1()
{
    deque<int> deq = {0, 1, 2, 3, 4, 5};
    stack<int> stk(deq);

    vector<string> svec;
    stack<string, vector<string>> str_stk;
    stack<string, vector<string>> str_stk2(svec);
}

//二、栈适配器， pop push top  emplace
//默认基于deque构造
void tets2()
{
    stack<int> intStack;
    for (size_t ix = 0; ix != 10; ix++)
    {
        intStack.push(ix);
    }
    while (!intStack.empty())
    {
        int value = intStack.top();
        intStack.pop();
    }
}

//三、队列适配器，queue priority_queue

//练习题
enum obj_type
{
    LP,
    RP,
    ADD,
    SUB,
    VAL
};
struct obj
{
    obj(obj_type type, double val = 0)
    {
        t = type;
        v = val;
    }
    obj_type t;
    double v;
};
inline void skipws(string &exp, size_t &p)
{
    p = exp.find_first_not_of(" ", p);
}
inline void new_val(stack<obj> &so, double v)
{
    if (so.empty() || so.top().t == LP)
    {
        so.push(obj(VAL, v));
    }
    else if (so.top().t == ADD || so.top().t == SUB)
    {
        obj_type type = so.top().t;
        so.pop();
        if (type == ADD)
            v += so.top().v;
        else
            v = so.top().v - v;
        so.pop();
        so.push(obj(VAL, v));
    }
    else
        throw invalid_argument("缺少运算符");
}
void exer9_52()
{
    stack<obj> so;
    string expr;
    size_t p = 0, q;
    double v;

    cout << "请输入表达式：" << endl;
    getline(cin, expr);

    while (p < expr.size())
    {
        skipws(expr, p);//跳过空格
        if (expr[p] == '(')
        {
            so.push(obj(LP));
            p++;
        }
        else if (expr[p] == '+' || expr[p] == '-')
        {
            if (so.empty() || so.top().t != VAL)
                throw invalid_argument("缺少运算数");

            if (expr[p] == '+')
                so.push(obj(ADD));
            else
                so.push(obj(SUB));

            p++;
        }
        else if (expr[p] == ')')
        {
            p++;
            if (so.empty())
                throw invalid_argument("未匹配右括号");

            if (so.top().t == LP)
                throw invalid_argument("空括号");

            if (so.top().t == VAL)
            {
                v = so.top().v;
                so.pop();

                if (so.empty() || so.top().t != LP)
                    throw invalid_argument("未匹配右括号");

                so.pop();//把左括号弹出
                new_val(so, v);
            }
            else
            {
                throw invalid_argument("缺少运算数");
            }
        }
        else
        {
            v = stod(expr.substr(p), &q);
            p += q;
            new_val(so, v);
        }
    }
    
    if (so.size() != 1 || so.top().t != VAL)
        throw invalid_argument("非法表达式");

    cout << so.top().v << endl;
}
int main(int argc, const char *argv[])
{
    exer9_52();
    return 0;
}