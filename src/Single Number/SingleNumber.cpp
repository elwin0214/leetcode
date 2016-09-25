/*
https://leetcode.com/problems/single-number/

136. Single Number  QuestionEditorial Solution  My Submissions
Total Accepted: 157673
Total Submissions: 304347
Difficulty: Easy
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
*/

class Solution {
public:
  int singleNumber(vector<int>& nums) 
  {
    vector<int>::iterator it;
    int result = 0;
    for(it = nums.begin(); it != nums.end(); it++)
    {
      result = result^(*it);
    }
    return result;
  }
};