/*
https://leetcode.com/problems/permutations/
Permutations My Submissions Question
Total Accepted: 72051 Total Submissions: 219083 Difficulty: Medium
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

*/
/*
对于s1,s2....sn
分解成：
a)s1 开头的，s2s3...sn 继续分解
b)s2 开头的，s1s3...sn 继续分解
......




*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        vector<int> result;
        result.reserve(nums.size());
        vector<bool> visited(nums.size(),false);
        permute(results, result, nums, visited);
        return results;

    }
    void permute(vector<vector<int>> &results, vector<int> &result, vector<int> &nums, vector<bool> &visited)
    {
        if (result.size() == nums.size())
        {
            results.push_back(result);
            return;
        }

        bool hit = false;
        int last = -1;
        for (int i=0; i<nums.size(); i++)
        {

            if (visited[i]) continue;

            if (hit && last == nums[i])//去掉相等的值
            {
                last = nums[i];
                continue;
            };
            last = nums[i];
            hit = true;

            result.push_back(nums[i]);
            visited[i] = true;
            permute(results, result, nums, visited);
            visited[i] = false;
            result.erase(result.end()-1);
        }
    }
};

void print(vector<vector<int>> results)
{
    for(int i=0; i<results.size(); i++)
    {
        for(int j=0; j<results[0].size(); j++)
        {
            cout<<results[i][j] <<" ";
        }
        cout<<endl;
    }
}

int main()
{
    Solution sol;
    vector<int> nums={1,2,3};
    print(sol.permute(nums));

    nums={2,2,3};
    print(sol.permute(nums));
    return 0;
}