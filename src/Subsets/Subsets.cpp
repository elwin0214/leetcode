/*

https://leetcode.com/problems/subsets/


Subsets My Submissions Question
Total Accepted: 70444 Total Submissions: 242192 Difficulty: Medium
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
Subscribe to see which companies asked this question

Hide Tags
*/
/*
默认数组中有一个空值，可以选择
类似于 src/Combinations/Combinations.cpp 中构造子问题的思路

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        vector<int> result;
        result.reserve(nums.size());
        subsets(results, result, nums, 0);
        //results.push_back(vector<int>(0));
        return results;
    }

    void subsets(vector<vector<int>> &results, vector<int> &result, vector<int> &nums, int pos)
    {

        
        if (pos == nums.size()){
            results.push_back(result);
            return;
        }
        results.push_back(result);

        bool compare = false;
        int last = -1;
        for (int i = pos; i < nums.size(); i++)
        {
            if (compare)
            {
                if (last == nums[i])continue;
            }
            if (!compare) compare = true;
            last = nums[i];
            result.push_back(nums[i]);
            subsets(results, result, nums, i+1);
            result.erase(result.end()-1);
        }
    }
};

void print(vector<vector<int>> results){
    for (int i = 0; i < results.size(); i++)
    {
        for (int j = 0; j < results[i].size(); j++)
        {
            cout<<results[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Solution sol;
    vector<int> vec={1,2,2,3};

    print(sol.subsets(vec));
}