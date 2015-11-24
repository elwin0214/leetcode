

/*
https://leetcode.com/problems/container-with-most-water/

Container With Most Water My Submissions Question
Total Accepted: 59385 Total Submissions: 181146 Difficulty: Medium
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

Subscribe to see which companies asked this question

Show Tags
Hide Similar Problems

*/
#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int start = 0;
        int end = height.size() - 1;
        int area = min(height[start], height[end]) * (end - start);


        while (start < end)
        {

            if (height[start] < height[end])
            {
                int before = height[start];
                while(before >= height[start] && start < end)
                {
                    start++;
                }
                if (start >= end)break;
                area = max(area, min(height[start], height[end]) * (end - start));
            }
            else
            {
                int before = height[end];
                while(before >= height[end] && start < end)
                {
                    end--;
                }
                if (start >= end)break;
                area = max(area, min(height[start], height[end]) * (end - start));
            }
        }
        return area;
    }
    int min(int a, int b)
    {
        return a > b ? b : a;
    }
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
};

int main()
{
    Solution sol;
    {
        vector<int> vec = {1,2,3};
        cout<<sol.maxArea(vec)<<endl; 
    }
    {
        vector<int> vec = {1,2};
        cout<<sol.maxArea(vec)<<endl; 
    }
    {
        vector<int> vec = {1,2,200,2,300,4,5};
        cout<<sol.maxArea(vec)<<endl; 
    }
}