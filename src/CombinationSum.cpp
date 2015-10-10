#include <vector>
#include <iostream>
using namespace std;
/*
* 39.Combination Sum
*/
class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
  {
    vector<vector<int>> results;
    vector<int> result;
    sort(candidates.begin(),candidates.end());
    select(results,result,candidates,0,0,target);
    return results;
  }
  void select(vector<vector<int>>& results,vector<int>& result,vector<int>& candidates,int index,int sum,int target)
  {
    for(; index<candidates.size();index++)
    {
    	if(candidates[index]==candidates[index+1])
    	{

    		continue;//discard duplicated
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
      select(results,result,candidates,index,sum,target);
      result.erase(result.end()-1);
      sum=sum-candidates[index];
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
  vector<int> candidates={2,2};
  vector<vector<int>> vec=s.combinationSum(candidates,3);
  cout<<vec.size()<<endl;
	candidates={1,2};
	vec=s.combinationSum(candidates,3);
	print(vec);
	candidates={2,2,3,5,6};
	vec=s.combinationSum(candidates,9);
	print(vec);

	candidates={2,5,9};
	vec=s.combinationSum(candidates,11);
	print(vec);
}