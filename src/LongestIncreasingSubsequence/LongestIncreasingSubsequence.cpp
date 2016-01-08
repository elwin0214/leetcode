

/*

300. Longest Increasing Subsequence My Submissions Question
Total Accepted: 12527 Total Submissions: 38443 Difficulty: Medium
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
/*

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if (nums.size() == 0) return 0;
        vector<int> length(nums.size(), 1);  //第i个元素表示nums[i]结尾的最长子串
        int max = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int sub_max = length[i];
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] && sub_max < length[j] + 1)
                {
                    sub_max = length[j] + 1;
                }
            }
            //cout<< nums[i] << " "<<sub_max<<endl;
            length[i] = sub_max;
            max = max < sub_max ? sub_max : max;
        }
        return max;
    }
};


int main()
{
    {
        Solution sol;
        vector<int> vec = {10, 9, 2, 5, 3, 7, 101, 18};
        cout<< sol.lengthOfLIS(vec)<<endl;
    }
    {
        Solution sol;
        vector<int> vec = {1,3,6,7,9,4,10,5,6};
        cout<< sol.lengthOfLIS(vec)<<endl;
    }
    return 0;
}