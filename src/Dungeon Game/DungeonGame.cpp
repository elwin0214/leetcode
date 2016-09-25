/*

174. Dungeon Game My Submissions Question
Total Accepted: 19590 Total Submissions: 99839 Difficulty: Hard
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)  -3  3
-5  -10 1
10  30  -5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.

Subscribe to see which companies asked this question


*/
//!!! wait to commit
#include <iostream>
#include <vector>


using namespace std;
void print(int *a, int n);

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        if (dungeon.size() <= 0) return 0;
        int n = dungeon[0].size();
        int m = dungeon.size();
        int before[n];
        int current[n];

        memset(before, 0 , sizeof(before));
        memset(current, 0, sizeof(current));

        int index = 0 ;
        int i = 0;
        int j = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    current[j] = dungeon[i][j];
                }
                else if (j == 0)
                {
                    current[j] = before[j] + dungeon[i][j];
                }
                else if (i == 0)
                {
                    current[j] = current[j-1] + dungeon[i][j];
                }
                else
                    current[j] = max(current[j-1], before[j]) + dungeon[i][j];
            }
            print(current, n);
            memcpy(before, current, sizeof(before));
            print(before, n);

            memset(current, 0, sizeof(current));
        }
        return 0 - before[n-1];
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }
};


void print(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<< a[i] <<" ";
    }
    cout<<endl;
};

int main()
{
    Solution sol;

    {
        vector<vector<int>> vec = {{-2, -3, 3},{-5, -10, 1}, {10, 30, -5}};
        cout << sol.calculateMinimumHP(vec) << endl;
    }


    return 0;
}










