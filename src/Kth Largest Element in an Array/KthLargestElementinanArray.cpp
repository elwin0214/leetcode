/*
https://leetcode.com/problems/kth-largest-element-in-an-array/

Kth Largest Element in an Array My Submissions Question
Total Accepted: 31078 Total Submissions: 105073 Difficulty: Medium
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
struct Compare
{
    bool operator()(int a, int b)
    {
        return a > b ? true :false;
    }
};
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        vector<int> vec;
        vec.reserve(k);
        Compare cmp;
        //make_heap(vec.begin(), vec.end(), cmp);
        int index = 0;
        for (auto i : nums)
        {
             
            index++;
            if (index <= k)
            {
                vec.push_back(i);
                make_heap(vec.begin(), vec.end(), cmp);
                continue;
            }
            if (i <= vec[0]) continue;
            pop_heap(vec.begin(), vec.end(), cmp);

            vec.pop_back();
            vec.push_back(i);
            
            push_heap(vec.begin(), vec.end(), cmp);
        }
        return vec[0];
        
    }
};

int main()
{
    vector<int> v = {1, 4, 3, 4};
    Compare cmp;
    sort(v.begin(), v.end(), cmp);
    for_each(v.begin(), v.end(), [](int i){
        cout<<i<<" ";
    });
    cout<<endl;
    make_heap(v.begin(), v.end(), cmp);
    for_each(v.begin(), v.end(), [](int i){
        cout<<i<<" ";
    });
    cout<<endl;
    cout<<v.back()<<endl;


    Solution sol;
    vector<int> nums = {1, 3, 6, 9, 5, 2, 10 };

    cout<<sol.findKthLargest(nums,6);

}










