/*

https://leetcode.com/problems/combination-sum-ii/

Combination Sum II My Submissions Question
Total Accepted: 53602 Total Submissions: 204930 Difficulty: Medium
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
Subscribe to see which companies asked this question

*/
#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> results;
        vector<int> result;
        sort(candidates.begin(),candidates.end());
        select(results,result,candidates,0,0,target);
        return results;
    }
    void select(vector<vector<int>>& results,vector<int>& result,vector<int>& candidates,int index,int sum,int target)
    {
        int beforeIndex = -1;
        for(; index<candidates.size();index++)
        {
            beforeIndex = index;
            while(candidates[index] == candidates[index+1] && index < candidates.size() - 1)
            {
                //beforeIndex = -1 == beforeIndex ? index : beforeIndex;
                //continue;//discard duplicated
                index++;
            }
            sum=sum+candidates[index];
            result.push_back(candidates[index]);
            if(sum>target)
            {
                result.erase(result.end()-1);
                break;
            }
            if(sum==target)
            {
                results.push_back(result);
                result.erase(result.end()-1);
                break;
            }
            select(results,result,candidates,beforeIndex+1,sum,target);
            result.erase(result.end()-1);
            sum=sum-candidates[index];
        }
    }
};

void print(vector<vector<int>> &results)
{
    for(vector<int> v: results)
    {
        for(auto i : v)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    Solution sol;
    {
        vector<int> vec={1};
        vector<vector<int>> results=sol.combinationSum2(vec,2);
        print(results); 
    }
    {
       vector<int> vec={2,2,2};
        vector<vector<int>> results=sol.combinationSum2(vec,4);
        print(results); 
    }
}




