/*

https://leetcode.com/problems/combinations/

Combinations My Submissions Question
Total Accepted: 57874 Total Submissions: 181259 Difficulty: Medium
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Subscribe to see which companies asked this question
*/

/*
s1s2....sn
分解成如下子问题
a）包含s1的，在s2...sn 选n-1个
b)不含有s1，包含s2的，s3...sn 选n-1个
...


*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> results;
        vector<int> result;
        result.reserve(k);
        combine(results, result, 1, n, k);
        return results;
    }

    void combine(vector<vector<int>> &results,vector<int> &result, int pos, int n, int k)
    {
        if (result.size() == k)
        {
            results.push_back(result);
            return;
        }
        if(result.size() + n - pos +1 <k)//optimize
        {
            return;
        }
        for (int i=pos; i<=n; i++)
        {

            result.push_back(i);
            combine(results, result, i+1, n, k);
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
};

int main(){
    Solution sol;

    print(sol.combine(3,2));
}