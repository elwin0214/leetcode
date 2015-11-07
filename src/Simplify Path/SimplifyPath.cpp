

/*
https://leetcode.com/problems/simplify-path/
Simplify Path My Submissions Question
Total Accepted: 39810 Total Submissions: 194072 Difficulty: Medium
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Subscribe to see which companies asked this question

Hide Tags Stack String
Have you met this question in a real interview? Yes  No
Discuss



*/
#include <stack>
#include <iostream>

using namespace std;

class Solution 
{
public:
    string simplifyPath(string path) 
    {
        stack<char>  s;
        int i = 0;
        for (; i < path.size(); i++)
        {
            if (!s.empty() && s.top() == '/' && path[i] == '/')continue;
            if (!s.empty())
            {
                //if(s.top() == '/' && path[i] == '/') continue;
                bool check = false;
                if (s.top() == '.' && '/' == path[i])
                {
                    check = true;
                }
                else if(path[i] == '.' && i == path.size()-1)
                {
                    s.push(path[i]);
                    check = true;
                }
                else
                {
                    s.push(path[i]);
                }
                if (check)
                {
                    int dot_num = 0;
                    while ('.' == s.top() )
                    {
                        s.pop();
                        dot_num++;
                    }
                    if (dot_num == 0) continue;
                    if (dot_num == 1) continue;
                    if (dot_num == 2)
                    {
                        
                        s.pop();
                        if (s.empty()) 
                        {
                            s.push('/');
                            //s.push('.');
                            //s.push('.');
                        }
                        else
                            while('/' != s.top()) s.pop();
                    }
                    if (dot_num > 2)
                    {
                        while(dot_num-- > 0) s.push('.'); 
                    }
                }

            }
            else
            {
                s.push(path[i]);
            }
        }
        
        if (s.top() == '/' && s.size() > 1)
        {
            s.pop();
        }
        string str(s.size(),' ');
        int index = s.size() - 1;
        while (!s.empty())
        {
            char c = s.top();
            str[index--] = c;
            s.pop();
        }
        return str;
    }
};

int main()
{
    Solution sol;

    cout<<sol.simplifyPath("/a/b/./c/")<<endl;
    cout<<sol.simplifyPath("/a/../b/./c/")<<endl;
    cout<<sol.simplifyPath("/a/../b/./c")<<endl;
    cout<<sol.simplifyPath("/../")<<endl;
    cout<<sol.simplifyPath("/./")<<endl;

    cout<<sol.simplifyPath("/")<<endl;
    cout<<sol.simplifyPath("///")<<endl;
    cout<<sol.simplifyPath("/.")<<endl;

    cout<<sol.simplifyPath("/...")<<endl;
    cout<<sol.simplifyPath("/abc/...")<<endl;

}