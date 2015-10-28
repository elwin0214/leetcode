/*
https://leetcode.com/problems/word-break-ii/
Word Break II 
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

思路：
参考 word break。
数组多了一维，用来记录满足当前条件满足时，各个下标

S[1,k]满足，则dp[k] 是一个数组。dp[k][j]==1 => S[1,j]满足

*/

#include <unordered_set>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> wordBreak(string s, unordered_set<string>& wordDict) 
  {
    vector<string> results;
    if(s.size()==0)return results;
    if(wordDict.size()==0)return results;
    int len=s.size();
    int **dp=new int*[len+1];
    int p[len+1];
    memset(p,0,sizeof(p));
    for(int i=0; i<len+1; i++)
    {
      dp[i]=new int[len+1];
      memset(dp[i],0,(len+1)*4);
    }
    p[0]=1;
    int index=0;
    for(int i=1; i<=len; i++)
    {
      for(int j=0;j<i;j++)
      {
        if(p[j]==1){
        if( wordDict.find(s.substr(j,i-j))!=wordDict.end())
        {
          p[i]=1;
          dp[i][j]=1;
        }
      }
    }
  }
  if(p[len]!=1)return results;
  vector<int> positions;
  list(results,s,positions,dp,len,len);
  for(int i=0; i<len+1; i++)
  {
    delete[] dp[i];
  }
  return results;//return dp[len]==1;
 }
void print(int **p,int len)
{
  for(int i=0 ;i<=len; i++)
  {
    for(int j=0 ;j<=len; j++)
    {
      cout<<p[i][j] <<" ";
    }
    cout<<endl;
  }
}
 void list(vector<string> &result,string &str,vector<int> &positions,int **dp,int len,int i)
 {
    //if(i==len && p[i]!=1)return;
    if(i==0){
      string s;
      s.reserve(str.size()+positions.size()+1);
      int last=0;
      for(int pos=positions.size()-2; pos>=0; pos--)
      {
        //if(pos>=1){
        s=s.append(str.substr(last,positions[pos]-last));
        s.append(" ");
        last=positions[pos];
      }
      s.append(str.substr(last,len-last));
      result.push_back(s);
    };
   
    for(int j=0; j<len; j++)
    {
      if(dp[i][j]!=1)continue;
         //str.substr(j,i-j);
      positions.push_back(j);
      list(result,str,positions,dp,len,j);
      positions.erase(positions.end()-1);
    }
     
 }
 
};



void print(vector<string> &vec)
{
  for_each(vec.begin(),vec.end(),[](string &s){
    cout<<s<<endl;
  });
  cout<<endl;
}




int main(){

  
    

  Solution s;
 string str="leetcode";
 unordered_set<string> uset={"leet","code"};
 vector<string> r=s.wordBreak(str,uset);
  print(r);
 
 str="abcde";
 uset={"ab","abc","de","cde"};
 r=s.wordBreak(str,uset);
 print(r);
 
 

 return 0;
}

