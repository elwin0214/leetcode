/*

https://leetcode.com/problems/maximum-subarray/


Maximum Subarray My Submissions Question
Total Accepted: 82773 Total Submissions: 236141 Difficulty: Medium
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

Subscribe to see which companies asked this question

*/

/*
Array=[a1,a2,....an]
Sum[i] 表示以ai结尾的和最大的sub array


*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        if (nums.size() == 0)
            return 0;
        int sum = nums[0];
        int max = sum;
        for (int i=1; i<nums.size(); i++)
        {
            if(sum < 0)
                sum = nums[i];
            else
                sum = sum +nums[i];

            max = max < sum ? sum : max;
        }
        return max;
    }
};

int main()
{
    Solution sol;
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<sol.maxSubArray(nums)<<endl;


}