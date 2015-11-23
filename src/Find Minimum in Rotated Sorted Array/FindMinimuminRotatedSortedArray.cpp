/*


Find Minimum in Rotated Sorted Array My Submissions Question
Total Accepted: 69499 Total Submissions: 201729 Difficulty: Medium
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems



*/

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return nums[0] > nums[1] ? nums[1] : nums[0];
        if (nums[0] < nums[nums.size()-1]) return nums[0];
        return findMin(nums, 0, nums.size()-1);
    }

    int findMin(vector<int> &nums, int start, int end)
    {

        int mid = (start + end) / 2;
        
        if (nums[mid] > nums[end])
        {
            if (end - mid == 1) return nums[end];
            return findMin(nums, mid, end);
        }

        if (mid - start == 1) return nums[mid];//end - start >= 1
        return findMin(nums, start, mid);
    }
};

int main()
{
    Solution sol;
    {
        vector<int> vec = {3,4,5,0,1,2};
        cout<<sol.findMin(vec)<<endl; 
    }
    {
        vector<int> vec = {4,5,6,2,3};
        cout<<sol.findMin(vec)<<endl; 
    }
    {
        vector<int> vec = {1,2,3,0};
        cout<<sol.findMin(vec)<<endl; 
    }
    {
        vector<int> vec = {1,2,3};
        cout<<sol.findMin(vec)<<endl; 
    }
    return 0;
}



