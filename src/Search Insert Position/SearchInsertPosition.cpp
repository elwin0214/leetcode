/*
https://leetcode.com/problems/search-insert-position/
35. Search Insert Position  QuestionEditorial Solution  My Submissions
Total Accepted: 124285
Total Submissions: 323446
Difficulty: Medium
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

Subscribe to see which companies asked this question
*/

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    if (nums.size() <= 0) return 0;
    for (int i = 0; i < nums.size(); i++)
    {
      if(nums[i]>=target)return i;
      if(nums[i]<target)continue;
    }
    return nums.size();
  }
};
