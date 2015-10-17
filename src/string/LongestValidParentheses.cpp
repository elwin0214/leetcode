/*
https://leetcode.com/problems/longest-valid-parentheses/
*/
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <memory>

using namespace std;
/*
 * dp[i+1]=
 * 1.ch[i]=='(' =>0
   2.ch[i]==')'&& dp[i]==0  
    2.1 "[$group]()" => "[$group1][$group2]"
    2.2 "[$group]))" => "[$group]))"
   3.ch[i]==')' && dp[i]!=0 => ")[$group])" or  "([$group])"

 * merge  groups: [$group1][$group2]=>[$group]
 *
 */
class Solution {
public:
  int longestValidParentheses(string s) {
    int len=s.size();
    int max_len=0;
    int dp[len];
    memset(dp,0,sizeof(dp));
    for(int index=0; index<len; index++){

      char ch = s[index];
      if(index == 0){
        continue;
      }
      if (ch == '(') {
        dp[index]=0;
      } else {
        if (dp[index-1] == 0){
          if(s[index-1] == '(') {  // new group
            dp[index]=1;
          }
        }else{// ([$group]) =>embody
          int prev_char=index-dp[index-1]*2-1;
          if (prev_char >= 0 && s[prev_char] == '(') {
            dp[index]=dp[index-1]+1;
          }
        }
        //merge group :1.[$group1][$group2]  2.[$group1][$index][$group2]
        int pre_grp=index-dp[index]*2;
        if (pre_grp >= 0) {
          dp[index] = dp[pre_grp]+dp[index];
        } 
      }
      max_len=max(max_len,dp[index]);
    }
    return max_len*2;
  }
};

int main(){
  Solution s;
  cout<<s.longestValidParentheses("()")<<endl;

  cout<<s.longestValidParentheses("(()")<<endl;

  cout<<s.longestValidParentheses("(()(()()(")<<endl;

  cout<<s.longestValidParentheses("(()()()())(")<<endl;

  int i=2;

  return 0;
}