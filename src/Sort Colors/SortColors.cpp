/*

Sort Colors My Submissions Question
Total Accepted: 76406 Total Submissions: 229051 Difficulty: Medium
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Subscribe to see which companies asked this question

*/

#include <vector>
#include <iostream>

using namespace std;
void print(vector<int> vec)
{
    cout<<"print ";
    for_each(vec.begin(), vec.end(), [](int i){
        cout<<i<<" ";
    });
    cout<<endl;
};
class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        if (nums.size() == 0) return ;
        if (nums.size() == 1) return ;
        int start = 0;
        int end = nums.size() - 1;


        while (start < end)
        {
            while (start < end && nums[start] < 1) start++;
            while (start < end && nums[end] >= 1) end--;
            if (start < end) swap(nums[start], nums[end]);
        } 

        end = nums.size() - 1;
        while (start < end)
        {
            while (start < end && nums[start] < 2) start++;
            while (start < end && nums[end] >= 2) end--;
            if (start < end) swap(nums[start], nums[end]);
        } 
         
    }
};

int main()
{
    Solution sol;
    {
        vector<int> v1 = {1};
        sol.sortColors(v1);
        print(v1);
    }
    {
        vector<int> v1 = {1,0,2};
        sol.sortColors(v1);
        print(v1);
    }
    {
        vector<int> v1 = {1,0,0,1,2,2};
        sol.sortColors(v1);
        print(v1);
    }
}
