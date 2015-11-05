/*

https://leetcode.com/problems/spiral-matrix/

Spiral Matrix My Submissions Question
Total Accepted: 44307 Total Submissions: 209412 Difficulty: Medium
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].


*/
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> result;
        if (matrix.size() == 0)
            return result; 
        int row = matrix.size();
        int col = matrix[0].size();
        result.reserve(row * col);
        int direct = 1;
        int i = 0,j = 0;
        int loop = 1;

        while (true)
        {
            if (col * row == result.size())break;
            if (1 == direct)
            {
                result.push_back(matrix[i][j]);
                if (j == col-loop)
                {
                    i++;
                    direct = 2;
                    continue;
                }
                j++;
                continue;
            }
            else if (2 == direct)
            {
                result.push_back(matrix[i][j]);
                if (i == row-loop)
                {   
                    j--;
                    direct = 3;
                    continue;
                }
                i++;
                continue;
            }
            else if (3 == direct)
            {
                result.push_back(matrix[i][j]);
                if (j == loop-1)
                {
                    i--;
                    direct = 4;
                    continue;
                }
                j--;
                continue;
            }
            else if (4 == direct)
            {
                result.push_back(matrix[i][j]);
                if (i == loop)
                {
                    j++;
                    loop++;
                    direct = 1;
                    continue;
                }
                i--;
                continue;
            }
        }
        return result;
    }
};

void print(vector<int > result)
{
    for_each(result.begin(), result.end(),[](int n){
        cout<<n<<" ";
    });
    cout<<endl;
};

int main()
{
    Solution sol;

    {
        vector<vector<int>> matrix;
        matrix.push_back({1,2,3});
        matrix.push_back({4,5,6});
        matrix.push_back({7,8,9});  
        print(sol.spiralOrder(matrix));
    }

    {
        vector<vector<int>> matrix;
        matrix.push_back({1,2,3});
        matrix.push_back({4,5,6});
         
        print(sol.spiralOrder(matrix));
    }
}