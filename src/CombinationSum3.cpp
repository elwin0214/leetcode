#include <vector>
#include <iostream>
using namespace std;

/*
*216.Combination Sum III
*/
class Solution {
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
	void select(vector<vector<int>> &results,vector<int> &result,vector<int> &vec,int index,int num,int size,int sum,int target)
	{
		for(; index<vec.size(); index++)
		{
			sum=sum+vec[index];
			num++;

			if(sum>target || num>size)
			{
				break;
			}
				//select(results,result,vec,index+1,num-1,size,sum-vec[index],target);
			if(sum==target && num==size)
			{
				result.push_back(vec[index]);
				results.push_back(result);
				result.erase(result.end()-1);
				//num--;
				//sum=sum-vec[index];
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