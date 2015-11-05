/*
https://leetcode.com/problems/surrounded-regions/

Surrounded Regions My Submissions Question
Total Accepted: 41099 Total Submissions: 271882 Difficulty: Medium
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

/*
unsolved
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        if (board.size() == 0)return;
        for (int i=0; i<board.size(); i++)
        {
            mark(board, i, 0);
        }
        for (int i=0; i<board.size(); i++)
        {
            mark(board, i, board[0].size()-1);
        }

        for (int j=0; j<board[0].size(); j++)
        {
            mark(board, 0, j);
        }
        for (int j=0; j<board[0].size(); j++)
        {
            mark(board, board.size()-1, j);
        }

        for (int i=0; i<board.size(); i++)
        {
            for (int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if(board[i][j] == '-')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
    
    void mark(vector<vector<char>>& board, int i, int j)
    {
        if (i < 0 || i > board.size() - 1 || j <0 || j > board[0].size() - 1)
            return;
        if (board[i][j] == 'X' || board[i][j] == '-') return;
        if (board[i][j] == 'O')
        {
            board[i][j] = '-';
        }
            
        if (i > 0) mark(board, i-1, j);
        if (i < board.size()-1) mark(board, i+1, j);
        if (j > 0) mark(board, i, j-1);
        if (j < board[0].size()-1) mark(board, i, j+1);
    }
};
void print(vector<vector<char>> results)
{
    for(int i=0; i<results.size(); i++)
    {
        for(int j=0; j<results[0].size(); j++)
        {
            cout<<results[i][j] <<" ";
        }
        cout<<endl;
    }
};

int main()
{

    Solution sol;

    {
        vector<vector<char>> board;
        board.push_back({'X','X'});
        board.push_back({'X','O'});
        sol.solve(board);
        print(board);
    }

    {
        vector<vector<char>> board;
        board.push_back({'X','X','X','X'});
        board.push_back({'X','O','X','X'});
        board.push_back({'X','O','O','X'});
        board.push_back({'X','O','X','X'});
        board.push_back({'X','X','X','O'});
        sol.solve(board);
        print(board);
    }

        {
        vector<vector<char>> board;
        board.push_back({'X','X','X','X','X','X'});
        board.push_back({'X','O','X','X','X','X'});
        board.push_back({'X','O','O','O','O','X'});
        board.push_back({'X','O','X','X','X','X'});
        board.push_back({'X','X','X','O','X','X'});
        sol.solve(board);
        print(board);
    }


}















