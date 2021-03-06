/*
https://leetcode.com/problems/n-queens/
N-Queens My Submissions Question

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]


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