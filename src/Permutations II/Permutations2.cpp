
/*
https://leetcode.com/problems/permutations-ii/
Permutations II

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

*/

/*
见 src/Permutations/Permutations.cpp
*/
#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
vector<vector<int>> permuteUnique(vector<int>& nums) 
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

      if (hit && last == nums[i])
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