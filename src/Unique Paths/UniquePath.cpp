
/*


Unique Paths My Submissions Question
Total Accepted: 68827 Total Submissions: 200396 Difficulty: Medium
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?



*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        unsigned path[m][n];
    //memset(path,0,sizeof(path));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        //cout<<i<<j<<endl;
        if (i == 0 || j == 0) {
          path[i][j] = (unsigned)1;
          continue;
        }
        
        path[i][j] = path[i-1][j] + path[i][j-1];
      }
    }
    return path[m-1][n-1]; 
    }
};