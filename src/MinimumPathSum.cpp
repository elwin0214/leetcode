#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution 
{
public:
	int minPathSum(vector<vector<int>>& grid) 
	{

		int m=grid.size();
		if(m<=0)
			return 0;
		int n=grid[0].size();
		if(n<=0)
			return 0;

		int path[m][n];
    for(int i=0; i<m; i++)
    {

    	for(int j=0; j<n; j++)
    	{
    		if(i==0 && j==0)
    		{
    			path[i][j]=grid[i][j];
    		}
    		else if(i==0)
    		{
    			path[i][j]=path[i][j-1]+grid[i][j];
    		}
    		else if(j==0)
    		{
    			path[i][j]=path[i-1][j]+grid[i][j];
    		}
    		else
    		{
    			path[i][j]=min(path[i-1][j],path[i][j-1])+grid[i][j];
    		}  
    	}
    }
    return path[m-1][n-1];    
	}
};
int main()
{
	Solution s;
	vector<vector<int>> vec;
	cout<<s.minPathSum(vec)<<endl; 
	vec={{}};
	cout<<s.minPathSum(vec)<<endl; 
	vec={{1,1,1}};
	cout<<s.minPathSum(vec)<<endl; 
	vec={{1,2,3},{1,2,3}};
	cout<<s.minPathSum(vec)<<endl; 
	vec={{1,2,3},{1,1,1}};
	cout<<s.minPathSum(vec)<<endl; 
}
