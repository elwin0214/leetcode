  /*



https://leetcode.com/problems/n-queens-ii/
N-Queens II My Submissions Question
Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.



*/
/*
思路： dfs搜索，用一个数组保存路径。
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution
{
public:
int totalNQueens(int n) 
{
	int x=0;
	vector<vector<int>> totalVec;
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
				break; //backtrack after node 'x'
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
			break; //finished
		}
		if(x>=n)
		{
	 			//
			totalVec.push_back(vec);
			x--;
			continue; //backtrack 
			//break; //only one solution
		}
	}
	return totalVec.size();
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
	cout<<nq.totalNQueens(5);
	 
}