

/*
https://leetcode.com/problems/search-a-2d-matrix/

Search a 2D Matrix My Submissions Question
Total Accepted: 61879 Total Submissions: 190867 Difficulty: Medium
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

Subscribe to see which companies asked this question
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.size() == 0) return false;
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row - 1;
        
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (matrix[mid][col-1] == target) return true;
            else if (matrix[mid][col-1] > target)
            {
                end = mid;
                continue;
            }
            else
            {
                start = mid + 1;
                continue;
            }
        }
        int r = end;
        start = 0;
        end = col - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (matrix[r][mid] == target) return true;
            else if (matrix[r][mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    

    {
        vector<vector<int>> vec={{1},{2}};
        cout<<sol.searchMatrix(vec,2)<<endl;
        cout<<sol.searchMatrix(vec,1)<<endl;
        cout<<sol.searchMatrix(vec,3)<<endl;

    }
    {
        vector<vector<int>> vec={{1},{2},{5}};
        cout<<sol.searchMatrix(vec,1)<<endl;
 
    }
}















