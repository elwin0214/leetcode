/*

Unique Paths II My Submissions Question
Total Accepted: 52219 Total Submissions: 183482 Difficulty: Medium
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

Subscribe to see which companies asked this question

*/
#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        unsigned path[row][col];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    path[i][j] = 0;
                    continue;
                }
                if (i == 0 && j == 0)
                {
                     path[i][j] = 1;
                     continue;
                }
                if (i == 0)
                {
                    path[i][j] = path[i][j-1];
                    continue;
                }
                if (j == 0)
                {
                    path[i][j] = path[i-1][j];
                    continue;
                }
                path[i][j] = path[i][j-1] + path[i-1][j];

            }
        }
        return path[row-1][col-1];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grids={{0,0,0},{0,1,0},{0,0,0}};
    cout<<sol.uniquePathsWithObstacles(grids)<<endl;
}