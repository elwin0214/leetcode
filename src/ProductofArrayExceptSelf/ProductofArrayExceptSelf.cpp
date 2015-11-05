
/*
https://leetcode.com/problems/product-of-array-except-self/
Product of Array Except Self


Product of Array Except Self My Submissions Question
Total Accepted: 22210 Total Submissions: 58151 Difficulty: Medium
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

Subscribe to see which companies asked this question

*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    int start = 0;
    vector<int> result(size,1);
    int prd=1;
    for(int index=0; index<size; index++) {
      result[index] = result[index]*prd;
      prd = prd*nums[index];
    }
    prd=1;
    for(int index=size-1; index>=0; index--) {
      result[index] = result[index]*prd;
      prd = prd*nums[index];
    }
    return result;
  }
};

void print(const vector<int> &v) {
  for_each(v.begin(), v.end(), [](int n){
    cout<<n<<" ";
  });
  cout<<endl;
};
int main() {
  Solution s;
  vector<int> v={1,2,3};
  print(s.productExceptSelf(v));

  v.clear();
  print(s.productExceptSelf(v));

  v={2,2,3};
  print(s.productExceptSelf(v));

  v={2};
  print(s.productExceptSelf(v));

}