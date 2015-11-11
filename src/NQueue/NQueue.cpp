  /*



https://leetcode.com/problems/n-queens-ii/
N-Queens II My Submissions Question
Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.

思路：
dfs 二维数组保存路径和解

*/


#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
vector<vector<string>> solveNQueens(int n)
{
	int x=0;
	vector<vector<string>> grids;
	vector<int> vec;
	for(int x=0; x<n; x++)
	{
		vec.push_back(-1);
	}
	while(true)
	{
		while(true)
		{
			vec[x]++;
			if(vec[x]>=n)
			{
				vec[x]=-1;
				x--;
				break;
			}
			if(conflict(vec,x,vec[x]))
			{
				continue;
			}
			else
			{
				x++;
				break;
			}
		}
		if(vec[0]==-1)
		{
			break;
		}
		if(x>=n)
		{
			vector<string> grid;
			for(int i=0;i<n;i++)
			{
				string s(n,'.');
				s[vec[i]]='Q';
				grid.push_back(s);
			}
			grids.push_back(grid);
			x--;
			continue;
	 			//break;
		}
	}
	return grids;
}

bool conflict(vector<int> &vec,int x,int y)
{
	for (int i = 0; i < x; i++)
	{
		if(abs(x - i) == abs(y - vec[i]) || y == vec[i])
		{
			return true;
		}
		continue;
	}
	return false;
}
};

int main(){
	Solution nq;
 
	vector<vector<string>> grids=nq.solveNQueens(5);
	for(int i=0;i<grids.size();i++)
	{
		for(int j=0; j<grids[i].size();j++)
		{
			cout<<grids[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
	cout<<endl;
}