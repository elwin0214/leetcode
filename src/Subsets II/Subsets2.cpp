/*
https://leetcode.com/problems/subsets-ii/


Subsets II My Submissions Question
Total Accepted: 52097 Total Submissions: 182663 Difficulty: Medium
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
Subscribe to see which companies asked this question
*/
/*
view  /src/Subsets/Subsets.cpp
*/
class Solution {
public:
vector<vector<int>> subsetsWithDup(vector<int>& nums) {

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