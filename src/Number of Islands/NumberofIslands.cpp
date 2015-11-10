

/*
https://leetcode.com/problems/number-of-islands/

Number of Islands My Submissions Question
Total Accepted: 25550 Total Submissions: 104343 Difficulty: Medium
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        if (grid.size() == 0) return 0;
        int num = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j <grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    num++;
                    dfs(grid, i, j);
                }
            }
        }
        return num;
    }

    void dfs(vector<vector<char>>& grid, int i, int j)
    {
        if (i < 0 || i >= grid.size()) return;
        if (j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] == '0' || grid[i][j] == '-') return;
        grid[i][j] = '-';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};



int main()
{
    Solution sol;

    {
        vector<vector<char>> grid = {{'1','1','1','0'},{'1','1','1','0'},{'1','1','1','0'}};
        cout<<sol.numIslands(grid)<<endl;
    }
    {
        vector<vector<char>> grid = {{'1','1','0','0'},{'1','0','1','0'},{'1','0','0','0'}};
        cout<<sol.numIslands(grid)<<endl;
    }

}