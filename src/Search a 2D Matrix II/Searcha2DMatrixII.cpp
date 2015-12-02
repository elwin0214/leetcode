

/*

https://leetcode.com/problems/search-a-2d-matrix-ii/


Search a 2D Matrix II My Submissions Question
Total Accepted: 20902 Total Submissions: 67224 Difficulty: Medium
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

Subscribe to see which companies asked this question

*/

/*
两个指针 start=(si,sj) ,end=(ei, ej)
不断朝目标值逼近，每次丢弃一行、一列。
if (matrix[ei][sj] == target) return true; 不加这一句判断左右对角，会在case 3下死循环
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
        int si = 0;
        int sj = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int ei = row - 1;
        int ej = col - 1;
        while (true)
        {  
            while (matrix[ei][sj] > target && ei > si) ei--;
            while (matrix[si][ej] > target && ej > sj) ej--;


            while (matrix[si][ej] < target && si < ei) si++;
            while (matrix[ei][sj] < target && sj < ej) sj++;

            if (matrix[si][ej] == target) return true;
            if (matrix[ei][sj] == target) return true;

            if (matrix[si][sj] == target) return true;
            if (matrix[ei][ej] == target) return true;

            if (si == ei && sj == ej) return false;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    //case 1
    {
        vector<int> vec1={1,   4,  7, 11, 15};
        vector<int> vec2={2,   5,  8, 12, 19};
        vector<int> vec3={3,   6,  9, 16, 22};
        vector<int> vec4={10, 13, 14, 17, 24};
        vector<int> vec5={18, 21, 23, 26, 30};
        vector<vector<int>> matrix={vec1,vec2,vec3,vec4,vec5};

        cout<<sol.searchMatrix(matrix, 6)<<endl;
        cout<<sol.searchMatrix(matrix, 15)<<endl;
        cout<<sol.searchMatrix(matrix, 20)<<endl;
    }
    //case 2
    {
        vector<int> vec1={1};
        vector<vector<int>> matrix={vec1};
        cout<<sol.searchMatrix(matrix, 20)<<endl;
    }
    //case 3
    {
        vector<int> vec1={5,6,9};
        vector<int> vec2={9,10,11};
        vector<int> vec3={11,14,18};

        vector<vector<int>> matrix={vec1,vec2,vec3};

        cout<<sol.searchMatrix(matrix, 9)<<endl;
    }
    return 0;
}



