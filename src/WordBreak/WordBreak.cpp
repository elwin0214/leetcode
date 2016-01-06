
/*
https://leetcode.com/problems/word-break/
Word Break

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

*/
/*
思路：
S=s1s2....sn
如果S满足可分割，则存在k使得S[1,k]、S[k,n]也满足，问题可以分解，考虑使用动态规划。

dp[k]=1表示S[1,k]满足可分割，对dp[k+1]，对所有使得dp[i]==1(i<=k)的情况，判断S[i+1,k+1] 是否在dict中进而判断

dp[k+1]是否等于1。

状态转移方程：
dp[k+1]=1 <= dp[i]==1 && dicts.contain(S[i+1,k+1]) {k>=0 && k<i}

example：
S="abcdef"
dict=["abd","abc","def","ab","cdef","abcd"]

k=1,dp[1]=0;
k=2,dp[2]=1; dict.contains("ab")
k=3,dp[3]=1;dict.contains("abc")
k=4,因为dp[0]=1,dp[2]=1("ab"),dp[3]=1("abc"),此时要考虑"cd","d","abcd"是否在dict中，进而判断dp[4]是否等于1


注意：
初始值，即dp[0]=1

*/
#include <unordered_set>
#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, unordered_set<string>& wordDict) 
  {
    if (s.size() == 0) return false;
    if (wordDict.size() == 0) return false;
    int len = s.size();
    int dp[len+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int index = 0;
    for (int i = 1; i <= len; i++)
    {
      for (int j = 0;j < i; j++)
      {
        if (dp[j] == 1)
        {
        //cout<<j<<" "<<i<<" "<<s.substr(j,i-j)<<endl;
          if( wordDict.find(s.substr(j,i-j)) != wordDict.end())
          {
            dp[i] = 1;
          }
        }
      }
    }
    return dp[len] == 1;
  }
};

int main(){
  Solution s;
  string str = "leetcode";
  unordered_set<string> uset = {"leet","code"};
  cout << s.wordBreak(str,uset)<<endl;

  str = "abcde";
  uset = {"ab","abc","de"};
  cout << s.wordBreak(str,uset) <<endl;

  return 0;
}

