/*
https://leetcode.com/problems/find-peak-element/

Find Peak Element My Submissions Question
Total Accepted: 45693 Total Submissions: 141275 Difficulty: Medium
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

*/
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        if (nums.size() == 0) return -1;
        if (nums.size() == 1) return 0;
        return findPeakElement(nums, 0, nums.size()-1);
    }

    int findPeakElement(vector<int> &nums, int start, int end)
    {
        if (start > end) return -1;


        int mid = (start + end) / 2;
        if (0 == mid)
        {
            int index = nums[0] > nums[1] ? 0 : -1;
            if (index >= 0)return index;
        }
        if (mid == nums.size()-1)
        {
            int index = nums[mid] > nums[0] ? mid : -1;
            return index;
        }


        if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
        {
            return mid;
        }
        int index=-1;

        if (nums[mid-1] < nums[mid])
        {
            index=findPeakElement(nums, start, mid-2);

        }
        else
        {
            index=findPeakElement(nums, start, mid-1);
        }
        if (index >= 0) return index;


        if (nums[mid] < nums[mid+1])
        {
            index=findPeakElement(nums, mid+1, end);

        }
        else
        {
            index=findPeakElement(nums, mid+2, end);
        }
        return index;

    }
};


int main()
{
    Solution sol;
    vector<int> nums={1, 2, 3, 1};
    cout<<sol.findPeakElement(nums)<<endl;

    nums={1, 2, 3};
    cout<<sol.findPeakElement(nums)<<endl;

    nums={1, 20,2, 3};
    cout<<sol.findPeakElement(nums)<<endl;

    nums={1,2};
    cout<<sol.findPeakElement(nums)<<endl;

    nums={3,2,1};
    cout<<sol.findPeakElement(nums)<<endl;
}
