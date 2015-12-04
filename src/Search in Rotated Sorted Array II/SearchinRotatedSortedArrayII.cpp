

/*


Search in Rotated Sorted Array II My Submissions Question
Total Accepted: 50600 Total Submissions: 161529 Difficulty: Medium
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
Have you met this question in a real interview? Yes  No
Discuss



*/
/*
与 Search in Rotated Sorted Array I 相比，会出现相等的值，
如果nums[start] == nums[mid] || nums[end] == nums[mid] 不好判断，
所以去掉重复值(step a/b)，这样就不会出现 nums[start] == nums[mid] || nums[end] == nums[mid]
*/
#include <iostream>
#include <vector>

using namespace std;


class Solution 
{
public:
    bool search(vector<int>& nums, int target) 
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {

            
            while (start < end && nums[start] == nums[start+1]) start++; //step a
            while (start < end && nums[end] == nums[end-1]) end--; //step b
            int mid = (start + end) / 2;
            if (nums[mid] == target) return true;
            if (nums[start] < nums[end])
            {
                if (nums[mid] < target)
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
            else //[start,end] 类似于 5 6 7 8 9 1 2 3 4
            {
                if (nums[start] <= nums[mid])  //step a [start,mid]递增 ，这里用<=把 最小的解，比如start==mid理解为递增数列处理, 
                {
                    if (nums[mid] < target || target < nums[start]) start = mid + 1;
                    else end = mid - 1;
                }
                else //step b[mid,end]递增
                {
                    if (nums[mid] < target && target <= nums[end]) start = mid + 1;//必须是<=，不然会漏掉
                    else end = mid - 1;
                }
               
            }
        }
        return false;   
    }
};

int main()
{
    Solution sol;
    {
        vector<int> nums = { 6,7,8,9,2,3,4,5};
        cout<<sol.search(nums,3)<<endl;
        cout<<sol.search(nums,1)<<endl; 
    }

    {
        vector<int> nums = {3,1};
        cout<<sol.search(nums,1)<<endl; 
        cout<<sol.search(nums,3)<<endl; 

    }
    {
        vector<int> nums = {1,3};
        cout<<sol.search(nums,1)<<endl; 
        cout<<sol.search(nums,3)<<endl; 

    }
    {
        vector<int> nums = {5,1,3};
        cout<<sol.search(nums,1)<<endl; 
        cout<<sol.search(nums,3)<<endl; 

    }
    {
        vector<int> nums = {5,5,5,5,5,5,5,1,3};
        cout<<sol.search(nums,1)<<endl; 
        cout<<sol.search(nums,3)<<endl; 

    }
    {
        vector<int> nums = {1};
        cout<<sol.search(nums,0)<<endl; 

    }
    {
        vector<int> nums = {1,3,1,1,1};
        cout<<sol.search(nums,3)<<endl; 

    }
    {
        vector<int> nums = {1,2,2,2,0,1,1};
        cout<<sol.search(nums,0)<<endl; 

    }
     {
        vector<int> nums = {2,0};
        cout<<sol.search(nums,0)<<endl; 

    }

}