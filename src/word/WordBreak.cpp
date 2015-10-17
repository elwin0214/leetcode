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

