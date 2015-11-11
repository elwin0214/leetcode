/*
https://leetcode.com/problems/combination-sum-iii/
*216.Combination Sum III
*/

/*
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Ensure that numbers within the set are sorted in ascending order.

Example 1:
Input: k = 3, n = 7
Output:
[[1,2,4]]
Example 2:
Input: k = 3, n = 9
Output:
[[1,2,6], [1,3,5], [2,3,4]]
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution 
{
public:
	vector<vector<int>> combinationSum3(int k, int n) 
	{
		vector<vector<int>> results;
		vector<int> result;
		vector<int> vec;
		for(int i=1; i<=9; i++)
		{
			vec.push_back(i);
		}
		select(results,result,vec,0,0,k,0,n);
		return results;
	}
	void select(vector<vector<int>> &results, vector<int> &result,vector<int> &vec, int index, int num, int size, int sum, int target)
	{
		for(; index < vec.size(); index++)
		{
			sum=sum + vec[index];
			num++;
			if(sum > target || num > size)
			{
				break;
			}
			if(sum==target && num==size)
			{
			result.push_back(vec[index]);
				results.push_back(result);
				result.erase(result.end()-1);
				break;
			}
			else
			{
				result.push_back(vec[index]);
				select(results,result,vec,index+1,num,size,sum,target);
				num--;
				sum=sum-vec[index];
				result.erase(result.end()-1);
			}
		}
	}
};

void print(vector<vector<int>> &result)
{
	for(int i=0;i<result.size();i++)
	{
		for(int j=0; j<result[i].size();j++)
			cout<<result[i][j]<<" ";
		cout<<endl;
	}
  cout<<endl;
}

int main(){
	Solution s;
    vector<vector<int>> vec=s.combinationSum3(3,7);
	print(vec);
	vec=s.combinationSum3(3,9);
	print(vec);

}