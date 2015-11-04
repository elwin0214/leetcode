
/*
https://leetcode.com/problems/palindrome-partitioning/
Palindrome Partitioning My Submissions Question
Total Accepted: 51356 Total Submissions: 188195 Difficulty: Medium

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

*/
/*
思路：
字符串S=s1s2...sn 对字符串S可以分成的各种子串 进行判断求解。

递归法，按照下面的过程可以处理所有的解。

对于S[1,n+1],
如果S[1,2]是回文，递归处理S[2,n+1]
如果S[1,3]是回文，递归处理S[3,n+1]
...
如果S[1,n]是回文，递归处理S[n,n+1]


也可以理解成一个树，dfs求解，类似于排列组合算法





*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string > > results;
        vector<int> position;
        partition(s, 0, position,results);
        return results;
    }

    void partition(string &s, int pos, vector<int> &positions,vector<vector<string>> &results) 
    {
        if (pos >= s.size()) 
        {
            int start=0;
            vector<string> result;
            result.reserve(positions.size());
            for (int i=0; i<positions.size(); i++) 
            {
                result.push_back(s.substr(start,positions[i]-start));
                start = positions[i];
            }
            results.push_back(std::move(result));
        }
        for (int i=pos+1; i<=s.size(); i++) 
        {
            if (!isPalindrome(s, pos, i)) 
            {
                continue;
            }
            //cout<<i<<endl;
            positions.push_back(i);
            partition(s,i,positions,results);
            positions.erase(positions.end()-1);
        }
    }

    bool isPalindrome(string &s, int start,int end) 
    {
        end--;
        while (start < end)
        {
            if(s[start++] == s[end--])
                continue;
            else 
                return false;
        }
        return true;
    }

};

void print(vector<vector<string>> results) 
{
    for(int i=0; i<results.size(); i++) 
    {
        for(int j=0; j<results[i].size(); j++) 
        {
            cout<<results[i][j]<<" ";
        }
        cout<<endl;
    }
};


int main()
{
    Solution s;

    vector<vector<string>> results= s.partition("abc");
    print(results);

    results= s.partition("aac");
    print(results);

    results= s.partition("aa");
    print(results);
    return 0;
}