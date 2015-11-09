

/*

https://leetcode.com/problems/basic-calculator/

Basic Calculator My Submissions Question
Total Accepted: 16445 Total Submissions: 87631 Difficulty: Medium
Implement a basic calculator to evaluate a simple expression string.

The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.

Subscribe to see which companies asked this question
*/

#define DIGIT(x) ((x) + 1 -'1')
#include <iostream>
#include <stack>


using namespace std;

class Solution 
{
public:
    int calculate(string s) 
    {
        stack<char> op_stk;
        stack<int> val_stk;
        int val = 0;
        bool isDigit = false;
        for (int i = 0; i < s.size(); i++)
        {   
            char c = s[i];
            
            if (c == '(')
            {
                op_stk.push(c);
            }
            else if (c == ')')
            {
                if (isDigit)
                {
                    val_stk.push(val);
                    isDigit = false;
                }
                cal(op_stk, val_stk);
                op_stk.pop();
                cal(op_stk, val_stk);
            }
            else if ( c == '+' || c == '-' )
            {
                if (isDigit)
                {
                    val_stk.push(val);
                    isDigit = false;
                }
                cal(op_stk, val_stk);
                op_stk.push(c);
            }
            else //digit
            {
                if (c == ' ')
                {
                    if (i < s.size() - 1)
                        continue;
                    else
                    {
                        val_stk.push(val);
                        cal(op_stk, val_stk);
                        break;
                    }

                }
                if (!isDigit) 
                {
                    isDigit = true;
                    val = 0;
                }
                val = val * 10 + DIGIT(c);
                if (i == s.size() - 1)
                {
                    val_stk.push(val);
                    cal(op_stk, val_stk);
                }
            }
        }
        return val_stk.top();
    }
    void cal(stack<char> &op_stk, stack<int> &val_stk)
    {        
        while (!op_stk.empty())
        {
            char op = op_stk.top();
            if ('+' ==  op || '-' == op  )
            {
                op_stk.pop();
                int j = val_stk.top();
                val_stk.pop();
                int i = val_stk.top();
                val_stk.pop();
                val_stk.push(cal(op, i, j));
            }
            else
            {
                break;
            }
             
        }
    }
    int cal(char op, int i, int j)
    {
        int r = op == '+' ? (i + j) : (i - j);
        //cout<<op<<" "<<i<<" "<<j<<endl;
        return r;
    }
};

int main()
{
    Solution sol;
    cout<<sol.calculate(" 30")<<endl;
    cout<<sol.calculate(" 90 + 30")<<endl;
    cout<<sol.calculate(" 50  ")<<endl;

    cout<<sol.calculate("1+2")<<endl;
    cout<<sol.calculate("1+2-2")<<endl;
    cout<<sol.calculate("(1+2)-2")<<endl;
    cout<<sol.calculate("(1+2)-(1+2)")<<endl;
    cout<<sol.calculate("(1+2)-(1+2)")<<endl;
    cout<<sol.calculate("(1+2)-(1+2)+(1+1)")<<endl;
    cout<<sol.calculate("(1+2)-((1+2)+(1+1))")<<endl;
    cout<<sol.calculate("(1+2)+2+3-((1+2)+(1+1))")<<endl;
}