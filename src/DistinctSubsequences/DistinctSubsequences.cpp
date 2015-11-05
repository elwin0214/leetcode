/*
https://leetcode.com/problems/distinct-subsequences/

Distinct Subsequences 

Difficulty: Hard

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

*/

/*
思路：
S=s1s2...sn
T=t1t2...tn

分解成子问题，t1 与S 匹配情况，t1t2与S匹配情况.....

  a b a b c
a 1 0 1 0 0
b 0 1 0 1 0   (在a的基础上)
c 0 0 0 0 1   (在b的基础上)

*/
#include <iostream>
#include <memory>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) 
    {
        int source_len=s.size();
        int target_len=t.size();

        int dp[target_len][source_len];
        memset(dp, 0, sizeof(dp));

        for (int i=0; i<target_len; i++)
        {
            bool hit = false;
            for (int j=0; j<source_len; j++)
            {
                if (i > 0)
                {
                    if(!hit && (dp[i-1][j]==1))
                    {
                        hit=true;
                        continue;
                    }
                }
                else
                {
                    hit=true;
                }
            
                if (hit)
                {
                //cout<<hit<<" "<<s[j] <<" "<<t[i]<<endl;
                    if(t[i] == s[j])
                    dp[i][j] = 1;
                }
            }
            if (!hit) return 0;
        }

      
        for (int i=0; i<target_len; i++)
        {
            int sum=0;
            bool hit=false;
            for (int j=0; j<source_len; j++)
            {
                if (!hit && dp[i][j]==1)
                {
                    hit=true;
                }
                if (!hit) continue;
                if (0 == i )
                {
                    if(j < source_len - 1) dp[i][j+1] = dp[i][j+1]+dp[i][j];
                }
                else
                {
                    if (dp[i][j] < 0)
                    {
                        dp[i][j] = dp[i][j-1];
                    }
                    else
                    {
                        dp[i][j] = dp[i][j-1] + dp[i][j] * dp[i-1][j-1];
                    }
                }
            }
        }

        // for (int i=0; i<target_len; i++)
        // {
        //     for(int j=0; j<source_len; j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[target_len-1][source_len-1];
    }


};


int main()
{
    Solution sol;
    cout<<sol.numDistinct("abc","ac")<<endl;
    cout<<sol.numDistinct("abbcc","ac")<<endl;
    cout<<sol.numDistinct("abbbcc","abc")<<endl;
    cout<<sol.numDistinct("ddd","dd")<<endl;

    return 0;
}