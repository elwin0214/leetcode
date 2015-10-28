/*
https://leetcode.com/problems/3sum-closest/
3Sum Closest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;



class Solution 
{

public:
	int threeSumClosest(vector<int>& nums, int target) 
	{
		if(nums.size()<3)
			return -1;
		std::sort(nums.begin(),nums.end());
		int i=0;
		int j=0;
		int k=0;
		int len=nums.size();

		int value=nums[0]+nums[1]+nums[2];
		for(; i<=len-3; i++)
		{
			int start=i+1;
			int end=len-1;
			while(true)
			{
				int sum=nums[i]+nums[start]+nums[end];
				if(sum>=target)
				{
					if(abs(value-target)>abs(sum-target))
					{
						value=sum;
					}
					end--;
				}
				if(sum<target)
				{
					if(abs(value-target)>abs(sum-target))
					{
						value=sum;
					}
					start++;
				}
				if(end==start)break;
			}
		}
		return value;
		
	}
	int abs(int v)
	{
		return v>0?v:-v;
	}
	
};

int main(){
	Solution s;
	vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	//vec.push_back(4);
	std::sort(vec.begin(),vec.end());
	// for(int i=0;i<vec.size();i++){
	// 	cout<<vec[i]<<" ";
	// }
	cout<<s.threeSumClosest(vec,3)<<endl;
}