

/*
https://leetcode.com/problems/longest-palindromic-substring/

Longest Palindromic Substring My Submissions Question
Total Accepted: 78247 Total Submissions: 367140 Difficulty: Medium
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems


*/
/*
 从左到右逐个计算，如果当前元素被之前的某个最大回文串覆盖到了，可以利用对称点节省运算。
 http://www.open-open.com/lib/view/open1419150233417.html
*/
#include <memory>
#include <iostream>

using namespace std;

class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        if(s.size() == 0)
        {
            return "";
        }
        int size = 2*s.size() + 1;
        char array[size]; 

        int index = 0;
        for (int i = 0; i < s.size(); i++)
        {
            array[index++] = '#';
            array[index++] = s[i];
        }
        array[index] = '#';

        int len[size];
        memset(len, 0, sizeof(len));

        int max = 0;
        int pos = 0;
        for(index = 0; index < size; index++)
        {
            if (index > 0)// 从第2个元素开始计算
            {
                int boundary = pos + max -1;
                if (boundary > index)//
                {
                    int p = 2*pos - index;//对称点
                    if (index + len[p] - 1 < boundary)//
                    {
                        len[index] = len[p];
                        continue;
                    }
                    else
                    cal(array, len, size, index, boundary - index + 1);
                }
                else
                    cal(array, len, size, index, 1);
            }
            else
                cal(array, len, size, index, 1);
            if (max < len[index])
            {
                max = len[index];
                pos = index;
            }
            
        }
       
        int width = max - 1;
        int start = (pos - max + 1) / 2; 
        return s.substr(start, width);
    }

    void cal(char *array, int *len, int size, int index, int offset)
    {
        int i = index - offset;
        int j = index + offset;
        int l = offset;
        for (; i >= 0 && j < size;)
        {
            if (array[i--] == array[j++])
            {
                l++;
            }
            else
            {
                break;
            }
        }
        len[index] = l;
    }
};

int main()
{
    Solution sol;
    cout<<sol.longestPalindrome("a")<<endl;
    cout<<sol.longestPalindrome("ab")<<endl;

    cout<<sol.longestPalindrome("aba")<<endl;
    cout<<sol.longestPalindrome("aaaabababab")<<endl;
    cout<<sol.longestPalindrome("aaaaaaaaa")<<endl;

}





