/*
https://leetcode.com/problems/reverse-words-in-a-string/

Reverse Words in a String My Submissions Question
Total Accepted: 81310 Total Submissions: 529683 Difficulty: Medium
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Subscribe to see which companies asked this question

*/

#include <string>
#include <iostream>

using  namespace std;

class Solution {
public:
    void reverseWords(string &s) 
    {
        if (s.size() == 0) return;
        int end = s.size() - 1;
        int start = 0;
         while (s[end] == ' ' && end >=0)
        {
            end--;
         } 
        while (s[start] == ' ' && start <= s.size() - 1)
        {
            start++;
         } 
        if(start > end)
        {
            s.resize(0);
            return;
        }
        reverse(s, 0, end);

        int i = 0;
        int j = 0;
        bool hit = false;
        int distance = 0;
         for (; j < s.size(); j++)
        {
            if (!hit)
            {
                if (s[j] != ' ')
                {
                    distance = j - i;
                    hit = true;
                }
            }
            if (hit && s[j] == ' ')
            {
                reverse(s, i, j-1);
                hit = false;
                i = j + 1 - distance;
            }
            if(hit && j == s.size() - 1)
            {
                reverse(s, i, j);
                hit = false;
                i = j - distance;
                s.resize(i+1);
                return;
            }
        }
        s.resize(i-1);  
    }

    void reverse(string &s, int start, int end)
    {
        while (start < end) swap(s[start++], s[end--]); 
    }
};
int main()
{
    Solution sol;

    string s=" where  is  he ";
    sol.reverseWords(s);
    cout<<s<<""<<endl;

    s="  ";
    //s.resize(2);
    sol.reverseWords(s);
    cout<<s<<endl;

    s="he   here";
    //s.resize(2);
    sol.reverseWords(s);
    cout<<s<<endl;

    s="he  is  here";
    //s.resize(2);
    sol.reverseWords(s);
    cout<<s<<endl;

    s="a";
    //s.resize(2);
    sol.reverseWords(s);
    cout<<s<<endl;


}