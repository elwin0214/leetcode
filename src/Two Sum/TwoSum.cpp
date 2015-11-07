

/*
https://leetcode.com/problems/two-sum/

Two Sum My Submissions Question
Total Accepted: 152689 Total Submissions: 805132 Difficulty: Medium
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

Subscribe to see which companies asked this question
*/
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        multimap<int,int> m;
        int index = 1;
        for_each(nums.begin(), nums.end(), [=, &m, &index](int i){

            m.insert({i, index++});
            
        });
        int i = 0;
        int j = nums.size() - 1;
        auto start = m.begin();
        auto end = m.end();
        end--;

        vector<int> result;
        while (start != end)
        {
            int sum = start->first + end->first;
            cout<<(start->first) <<" "<<(end->first)<<endl;
            if (sum == target)
            {
                if(start->second < end->second)
                {
                    return {start->second, end->second};
                }
                else
                {
                    return {end->second, start->second};
                }
            }
            else if (sum < target) 
            {
                start++;
            }
            else
            {
                end--;
            }
        }

        return {};
    }
};

int main()
{
    Solution sol;
    {
    vector<int> nums = {1,4,7,2,5,6};
    vector<int> result = sol.twoSum(nums,8);
    for_each(result.begin(), result.end(), [](int &n){
        cout<<n<<endl;
    });
    }

    {
    vector<int> nums = {0,4,2,0};
    vector<int> result = sol.twoSum(nums,0);
    for_each(result.begin(), result.end(), [](int &n){
        cout<<n<<endl;
    });
    }

    //sort(m.begin(), m.end());

}

