
/*

https://leetcode.com/problems/maximal-square/

Maximal Square My Submissions Question
Total Accepted: 17377 Total Submissions: 81818 Difficulty: Medium
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

*/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0)return 0;
        int size = matrix[0].size();
        vector<int> before(size, 0);
        vector<int> current(size, 0);
        int max_size = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == 0 && matrix[i][j] == '1') current[j] = 1;
                else if (j == 0 && matrix[i][j] == '1') current[j] = 1;
                else if (matrix[i][j] == '1')
                {
                    //int min = matrix[i-1][j] < matrix[i][j-1] ? matrix[i-1][j] :matrix[i][j-1];
                    int min_value = min(current[j-1], before[j]);
                    if (0 == min_value)
                        current[j] = 1;
                    else 
                        current[j] = min_value + (matrix[i-min_value][j-min_value] == '1' ? 1 : 0);
                }

                max_size = max(max_size, current[j]);
            }
            std:swap(current, before);
                for_each(current.begin(), current.end(),[](int &n){
                    n = 0;
                });
        }
        return max_size * max_size;
    }
};


int main()
{
    Solution sol;
    {
        vector<vector<char>> matrix = {{'1','1','1'}};
        cout<<sol.maximalSquare(matrix)<<endl;
    }

    {
        vector<vector<char>> matrix = {{'1','1','1'},{'1','1','0'}};
        cout<<sol.maximalSquare(matrix)<<endl;
    }

        {
        vector<vector<char>> matrix = {{'1','1','1'}};
        cout<<sol.maximalSquare(matrix)<<endl;
    }


    return 0;
}