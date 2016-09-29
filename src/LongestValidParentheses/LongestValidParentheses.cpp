/*
https://leetcode.com/problems/longest-valid-parentheses/
Longest Valid Parentheses

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

Subscribe to see which companies asked this question

*/

/*
  dp[i] 表示 s[0, i]中以S[i]结尾的字符串包含的 括号对数
 * dp[i+1]=
 * 1.S[i]=='(' =>0
   2.S[i]==')'&& dp[i]==0  
    2.1 "[$group]()" => "[$group1][$group2]"
    2.2 "[$group]))" => "[$group]))"
   3.ch[i]==')' && dp[i]!=0 => ")[$group])" or  "([$group])"

  2.2 与 3 不同的地方在 一个有匹配 一个没有匹配
 * merge  groups: [$group1][$group2]=>[$group]
 *
 */
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <memory>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    int len=s.size();
    int max_len=0;
    int dp[len];
    memset(dp, 0, sizeof(dp));
    for(int index = 0; index < len; index++){

      char ch = s[index];
      if(index == 0){
        continue;
      }
      if (ch == '(') {
        dp[index]=0;
      } else {
        if (dp[index-1] == 0){
          if (s[index-1] == '(') {  // new group
            dp[index]=1;
          }
        }else{// ([$group]) =>embody
          int prev_char = index - dp[index-1]*2-1;
          if (prev_char >= 0 && s[prev_char] == '(') {
            dp[index] = dp[index - 1]+1;
          }
        }
        //merge group :1.[$group1][$group2]  2.[$group1][$index][$group2]
        int pre_grp = index-dp[index]*2;
        if (pre_grp >= 0) {
          dp[index] = dp[pre_grp] + dp[index];
        } 
      }
      max_len=max(max_len, dp[index]);
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