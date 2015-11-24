/*


Spiral Matrix II My Submissions Question
Total Accepted: 41810 Total Submissions: 126692 Difficulty: Medium
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
Subscribe to see which companies asked this question


*/
#include <vector>
#include <iostream>

using namespace std;
void print(vector<vector<int>> &results)
{
    for (int i = 0; i < results.size(); i++)
    {
        for (int j = 0; j < results[0].size(); j++)
        {
            cout<<results[i][j]<<" ";
        }
        cout<<endl;
    }
};
class Solution 
{
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> results;
        if (0 == n) return results;
        int i = 0;
        int j = 0;
        for (int k = 0; k < n; k++)
        {
            vector<int> v(n, 0);
            results.push_back(std::move(v));
        }
        int m = 1;
        int direct = 1;
        while (true)
        {
            if (m > n*n) break;
            if (1 == direct)
            {
                while (j < n && results[i][j] == 0)
                    results[i][j++] = m++;
                j--;
                i++;
                direct = 2;
            }
            else if (2 == direct)
            {
                while (i < n && results[i][j] == 0)
                    results[i++][j] = m++; 
                i--;
                j--;
                direct = 3;
            }
            else if (3 == direct)
            {
                while (j >= 0 && results[i][j] == 0)
                    results[i][j--] = m++; 
                j++;
                i--;
                direct = 4;
            }
            else
            {
                while (i >= 0 && results[i][j] == 0)
                    results[i--][j] = m++;
                i++;
                j++;
                direct = 1;
            }
        }
        return results;
    }
};

int main()
{
    Solution sol;
    {
        vector<vector<int>> results = sol.generateMatrix(2);
        print(results);
    }
    {
        vector<vector<int>> results = sol.generateMatrix(3);
        print(results);
    }
    {
        vector<vector<int>> results = sol.generateMatrix(10);
        print(results);
    }
    return 0;
}