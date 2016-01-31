

/*


Sudoku Solver My Submissions Question
Total Accepted: 41694 Total Submissions: 178682 Difficulty: Hard
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

*/

/*
思路：dfs + 回溯
状态表示：这里一共81个格子，这里一共用以下2种数据结构存储状态：
1）vector<vector<char > >：一个9*9 二维数组，表示81个格子填的数字
2）vector<int>：数组里面的每个整数表示一个bitset，1-9 中有填的数字，
   这里有三个数组，分别表示9行，9列，9个3*3的格子里面数字的布局，方便计算
*/

#include <iostream>
#include <vector>

using namespace std;

#define SIZE 9


struct Sudoku
{

    //vector<int> pos_bit;
    vector<int> grp_nums_bit;//9 个3*3的格子数字填写布局
    vector<int> v_nums_bit;//9行数字填写布局
    vector<int> h_nums_bit;//9列数字填写布局

    Sudoku():grp_nums_bit(SIZE),v_nums_bit(SIZE),h_nums_bit(SIZE)
    {

    }
    void parse(vector<vector<char > >& board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                    mark(i, j, board[i][j] + 1 - '1');
            }
        }
    }

    void mark(int x, int y, int num)
    {
        //pos_bit[i] = pos_bit[i] | (1 << j);
        int grp_index =  (x / 3) * 3 + (y / 3);
        grp_nums_bit[grp_index] = grp_nums_bit[grp_index] | (1 << (num - 1));
        v_nums_bit[x] =  v_nums_bit[x] | (1 << (num - 1));
        h_nums_bit[y] =  h_nums_bit[y] | (1 << (num - 1));
    }

    void unmark(int x, int y, int num)
    {
        //pos_bit[i] = pos_bit[i] & ~(1 << j);
        int grp_index =  (x / 3) * 3 + (y / 3);
        grp_nums_bit[grp_index] = grp_nums_bit[grp_index] & ~(1 << (num - 1));
        v_nums_bit[x] =  v_nums_bit[x] & ~(1 << (num - 1));
        h_nums_bit[y] =  h_nums_bit[y] & ~(1 << (num - 1));
    }
     

    bool writeable(int nums, int num)
    {
        return (nums & (1 << (num - 1))) == 0;
    }
    bool writeable(vector<vector<char > >& board, int x, int y, int num)
    {
        int grp_index =  (x / 3) * 3 + (y / 3);
        return writeable(grp_nums_bit[grp_index], num) 
                && writeable(v_nums_bit[x], num) 
                && writeable(h_nums_bit[y], num);
    }

    void write(vector<vector<char > >& board)
    {
        parse(board);
        vector<int> blank_positions;
        int index = 0;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {

                if (board[i][j] == '.')
                {
                    blank_positions.push_back(index);
                }
                index++;
            }
        }
        int blank_size = blank_positions.size();
        vector<int> num_stack(blank_size);
        //num_stack.resize(blank_size);
        index = 0;
        bool result = false;
        while (true)
        {
            int x = blank_positions[index] / SIZE;
            int y = blank_positions[index] % SIZE;
            //
            bool succ = false;
            if (num_stack[index] > 0)// 清除旧值
                unmark(x, y, num_stack[index]);
            int num = num_stack[index] + 1;
            for (; num <= SIZE; num++)
            {
                if (writeable(board, x, y, num))
                {
                    mark(x, y, num);
                    succ = true;
                    break;
                }
            }
            if (succ)
            {
                //cout<<index<<" "<<num<<endl;
                num_stack[index] = num;
                index++;
            }
            else
            {   
                num_stack[index] = 0;//回溯后，下次到这里时重新开始
                index--;
                //
            }
            if (index < 0)
            {
                result = false;
                break;
            }
            if (index >= num_stack.size())
            {
                result = true;
                break;
            }
        }
        if (result){
            for (int i = 0; i < num_stack.size(); i++)
            {
                int x = blank_positions[i] / SIZE;
                int y = blank_positions[i] % SIZE;
                board[x][y] = num_stack[i] + '1' - 1;
            } 
        }
       
    }
};

class Solution 
{
public:
    void solveSudoku(vector<vector<char > >& board) 
    {
        Sudoku sudoku;
        sudoku.write(board);
        
    }
};

int main()
{
    Solution sol;
    vector<vector<char > > board;
    board.push_back({'5','3','.','.','7','.','.','.','.'});
    board.push_back({'6','.','.','1','9','5','.','.','.'});
    board.push_back({'.','9','8','.','.','.','.','6','.'});

    board.push_back({'8','.','.','.','6','.','.','.','3'});
    board.push_back({'4','.','.','8','.','3','.','.','1'});
    board.push_back({'7','.','.','.','2','.','.','.','6'});

    board.push_back({'.','6','.','.','.','.','2','8','.'});
    board.push_back({'.','.','.','4','1','9','.','.','5'});
    board.push_back({'.','.','.','.','8','.','.','7','9'});

    sol.solveSudoku(board);

    for (auto i : board)
    {
        for (auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}