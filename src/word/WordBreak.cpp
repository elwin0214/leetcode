
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
如果S满足，则存在k使得S[1,k]、S[k,n]也满足，使用动态规划。

dp[k]=1表示S[1,k]满足，对下标i，对所有使得dp[k]=1(k<i),

状态转移方程：
dp[i]=1 <= dp[k]==1 && dicts.contain(S[k,i]) {k>=0 && k<i}

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
  if(s.size()==0)return false;
  if(wordDict.size()==0)return false;
  int len=s.size();
  int dp[len+1];
  memset(dp,0,sizeof(dp));
  dp[0]=1;
  int index=0;
  for(int i=1; i<=len; i++)
  {
   for(int j=0;j<i;j++)
   {
    if(dp[j]==1){
      //cout<<j<<" "<<i<<" "<<s.substr(j,i-j)<<endl;
      if( wordDict.find(s.substr(j,i-j))!=wordDict.end())
      {
        dp[i]=1;
      }
    }
   }
  }
  return dp[len]==1;
 }
};

int main(){
 Solution s;
 string str="leetcode";
 unordered_set<string> uset={"leet","code"};
 cout<<s.wordBreak(str,uset)<<endl;

 str="abcde";
 uset={"ab","abc","de"};
 cout<<s.wordBreak(str,uset)<<endl;


 return 0;
}

