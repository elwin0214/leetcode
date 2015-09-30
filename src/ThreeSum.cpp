#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;



class Solution 
{

public:
	vector<vector<int> > threeSum(vector<int>& nums) 
	{
		vector<vector<int> > vec;
		if(nums.size()<3)
			return vec;
		std::sort(nums.begin(),nums.end());
		int i=0;
		int j=0;
		int k=0;
		int len=nums.size();
		
		for(; i<=len-3; i++)
		{
			int start=i+1;
			int end=len-1;
			while(start<end)
			{
				int sum=nums[i]+nums[start]+nums[end];
				if(sum==0)
				{
					vector<int> v;
					v.push_back(nums[i]);
					v.push_back(nums[start]);
 					v.push_back(nums[end]);
 					vec.push_back(v);
 					
 					while(start<end && nums[start]==nums[start+1])
 					{
 						start++;
 					}
 					while(end>start && nums[end]==nums[end-1])
 					{
 						end--;
 					}
 					end--;
				}
				if(sum>0)
				{
					end--;
				}
				if(sum<0)
				{
					start++;
				}
			}
			while(nums[i]==nums[i+1]&&i<=len-3)
			{
				i++;
			}
		}
		return vec;
		
	}

	
};

int main(){
	cout<<1<<endl;
	Solution s;
	vector<int> vec={13,14,1,2,-11,-11,-1,5,-1,-11,-9,-12,5,-3,-7,-4,-12,-9,8,-13,-8,2,-6,8,11,7,7,-6,8,-9,0,6,13,-14,-15,9,12,-9,-9,-4,-4,-3,-9,-14,9,-8,-11,13,-10,13,-15,-11,0,-14,5,-4,0,-3,-3,-7,-4,12,14,-14,5,7,10,-5,13,-14,-2,-6,-9,5,-12,7,4,-8,5,1,-10,-3,5,6,-9,-5,9,6,0,14,-15,11,11,6,4,-6,-10,-1,4,-11,-8,-13,-10,-2,-1,-7,-9,10,-7,3,-4,-2,8,-13};
	//vector<int> vec={-2,1,1,3};


 

	vector<vector<int> > v= s.threeSum(vec);
	//vec.push_back(4);
	//std::sort(vec.begin(),vec.end());
	 for(int i=0;i<v.size();i++){
	  	cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
	 }
	//cout<<s.threeSum(vec)<<endl;
}