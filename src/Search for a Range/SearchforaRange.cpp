
/*
https://leetcode.com/problems/search-for-a-range/

Search for a Range My Submissions Question
Total Accepted: 65757 Total Submissions: 235163 Difficulty: Medium
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
Have you met this question in a real interview? Yes  No
Discuss

*/
#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size() - 1;

        
        int left = -1;
        int right = -1;
        while (start <= end)
        {
            int mid = (start + end ) / 2;
            if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                left = searchLeft(nums, start, mid, target);//nums[mid] == target
                right =searchRight(nums, mid, end, target);//nums[mid] == target
                break;
            }
        }

        vector<int> result;
        result.reserve(2);
        result.push_back(left);
        result.push_back(right);
        return result;

    }

    int searchLeft(vector<int> &nums, int start, int end, int target)
    {
        while (start <= end)
        {
            if (nums[start] == target) return start;
            int mid = (start + end) / 2;

            if (nums[mid] == target)
            {
                end = mid - 1;// 如果是 end = mid 会死循环 [1,3] 1
            }
            else
            {
                start = mid + 1;
            }
        }
        return end + 1;
    }
    int searchRight(vector<int> &nums, int start, int end, int target)
    {
        while (start <= end)
        {
            if (nums[end] == target) return end;
            int mid = (start + end) / 2;
            if (nums[mid] == target)
            {
                start = mid + 1;// 如果是 end = mid 会死循环 [1,3] 1
            }
            else
            {
                end = mid - 1;
            }
        }
        return start - 1;//找不到 直接在 start - 1就是
    }
};

void test(const vector<int> &nums, int target)
{
    Solution sol;
    vector<int> array = nums;
    vector<int> result = sol.searchRange(array, target);
    cout<<result[0] <<" "<<result[1]<<endl;

};
int main()
{
    
    test({1,2,3,3,4,5},3);
    test({1,2,3,3,4,5},6);
    test({1},1);
    test({2},1);
    test({1,3},1);
}