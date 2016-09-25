/*
https://leetcode.com/problems/longest-common-prefix/

14. Longest Common Prefix  QuestionEditorial Solution  My Submissions
Total Accepted: 123749
Total Submissions: 416024
Difficulty: Easy
Write a function to find the longest common prefix string amongst an array of strings.

Subscribe to see which companies asked this question

Show Tags
Have you met this question in a real interview? Yes  

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    int position=0;
    int size=strs.size();
    if(size<=0)
      return "";
    if(size==1)
    {
      return strs[0]; 
    }
    while(true)
    {
      char pre;
      for(int i=0; i<size; i++)
      {
        if(position>=strs[i].length())
        {
          return strs[i].substr(0,position);
        }

        if(i!=0 && pre!=strs[i].at(position))
        {
          return strs[i].substr(0,position);
        }
        else
        {
          pre=strs[i].at(position);
        }
      }
      position++;
    }     
  }
}