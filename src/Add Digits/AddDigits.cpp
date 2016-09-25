/*
https://leetcode.com/problems/add-digits/

258. Add Digits  QuestionEditorial Solution  My Submissions
Total Accepted: 127198
Total Submissions: 255839
Difficulty: Easy
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Show Hint 
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

*/

class Solution
{
public:
  int addDigits(int num) 
  {
    if(0 == num)
      return 0;
    return num % 9 == 0 ? 9 : num % 9;
  }
};