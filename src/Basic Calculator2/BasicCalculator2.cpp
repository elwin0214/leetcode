/*

https://leetcode.com/problems/basic-calculator-ii/

Basic Calculator II My Submissions Question
Total Accepted: 12755 Total Submissions: 59696 Difficulty: Medium
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

*/
#define DIGIT(x) ((x) + 1 -'1')

#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution 
{
public:
    int calculate(string s) 
    {
        stack<char> op_stack;
        stack<int> val_stack;

        int val = 0;
        bool isDigit = false;

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            switch (ch){
            case '*':
            case '/':

                if (isDigit)
                {
                    isDigit = false;
                    val_stack.push(val);
                }
                cal(val_stack, op_stack, ch);
                op_stack.push(ch);
                break;
            case '+':

            case '-':
                if (isDigit)
                {
                    isDigit = false;
                    val_stack.push(val);
                }
                cal(val_stack, op_stack, ch);
                op_stack.push(ch);
                break;
            case ' ':
                if (isDigit)
                {
                    isDigit = false;
                    val_stack.push(val);
                }
                break;
            default:
                if (!isDigit)
                {
                    isDigit = true;
                    val = 0;
                }
                val = val * 10 + DIGIT(ch);
            }

        }
        if(isDigit)
        {
            val_stack.push(val);
        }
        cal(val_stack, op_stack, '#');
        return val_stack.top();

    }

    bool priority(char op1, char op2)
    {
        if (op2 == '#')
        {
            return true;
        }
        if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/'))
            return false;
        else 
            return true;
    }
    void cal(stack<int> &val_stack, stack<char> &op_stack, char op)
    {
        while (!op_stack.empty())
        {
            if (priority(op_stack.top(), op))
            {
                char op_before = op_stack.top();
                op_stack.pop();
                int v2 = val_stack.top();
                val_stack.pop();
                int v1 = val_stack.top();
                val_stack.pop();
                val_stack.push(cal(v1, v2, op_before));
            }
            else
            {
                break;
            }
        }
    }
    int cal(int v1, int v2, char op)
    {
        //cout<<v1 <<" "<<op<<" "<<v2<<endl;
        switch(op)
        {
            case '+':
                return v1 + v2;
            case '-':
                return v1 - v2;
            case '*':
                return v1 * v2;
            case '/':
                return v1 / v2;
            default:
                exit(1);
                return 0;    
        }
    }
};

int main()
{
    Solution sol;
    cout<<sol.calculate("2*3")<<endl;
    cout<<sol.calculate("2*3 - 3*4")<<endl;
    cout<<sol.calculate("2*3 +3 -9")<<endl;
    cout<<sol.calculate("2*3 +3 -9 ")<<endl;
    cout<<sol.calculate("2*3 +3 -9 + 6/ 3")<<endl;

}
