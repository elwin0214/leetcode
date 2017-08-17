/*
https://leetcode.com/problems/trapping-rain-water/description/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
#include <iostream>
#include <vector>
using namespace std;
/*
  1.找左边右边最大值，求矩形面积
  2.减去多计算的面积

  另外一种 https://discuss.leetcode.com/topic/5125/sharing-my-simple-c-code-o-n-time-o-1-space/2
*/
class Solution {
public:
  int trap(vector<int>& height) {
    if (height.size() <= 2) return 0;

    int start = 0;
    int end = height.size() - 1;
    int max_left = height[0]; 
    int max_right = height[end];

    int base = 0;
    int result = 0;
    while (start < end - 1)
    {
      if (max_left <= max_right)
      {
        result = result + (max_left - base) * (end - start - 1);
        base = max_left;
        while (start < end - 1)
        {
          start++;
          if (height[start] <= max_left)
          {
            result -= height[start];
            continue;
          } 
          max_left = height[start];
          result -= base;
          break;
        }
      }
      else
      {
        result = result + (max_right - base) * (end - start - 1);
        base = max_right;
        while (start < end - 1)
        {
          end--;
          if (height[end] <= max_right)
          {
            result -= height[end];
            continue;
          }
          max_right = height[end];
          result -= base;
          break;
        }
      }
    }
    return result;
  }
};


int main()
{ 
  std::vector<int> v = {2,0,2};
  Solution sol;
  cout << sol.trap(v) << endl;
  return 0;
}