

/*
https://leetcode.com/problems/maximal-rectangle/

Maximal Rectangle My Submissions Question
Total Accepted: 34081 Total Submissions: 151472 Difficulty: Hard
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
Have you met this question in a real interview? Yes  No
Discuss
*/
//!!! wait to commit
#include <vector>

using namespace std;

struct Rect
{
    int x;
    int y;
    Rect(): x(0), y(0)
};
class Solution 
{
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if (matrix.size() == 0)return 0;
        int size = matrix[0].size();
        vector<Rect> before(size);
        vector<Rect> current(size);

        int max_size = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == 0 && matrix[i][j] == '1') 
                {
                    current[j].x = 1;
                    current[j].y = 1;
                }
                else if (j == 0 && matrix[i][j] == '1') 
                {
                    current[j].x = 1;
                    current[j].y = 1;
                } 
                else if (matrix[i][j] == '1')
                {
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
    return 0;
}