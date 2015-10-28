/*
https://leetcode.com/problems/word-search/
Word Search My Submissions Question

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

思路：
找到入口，递归搜索，位置标记

*/

#include <vector>
#include <iostream>
#include <string>
using namespace std;
 

class Solution {
public:
bool exist(vector<vector<char>>& board, string word) 
{
	int m=board.size();
	if(m==0)return false;
	int n=board[0].size();

	vector<vector<int>> path;
	for(int i=0;i<m;i++)
	{
		path.push_back(vector<int>(n));
	}
	bool r=false;
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(board[i][j]==word[0])
			{
				r=search(board,path,0,i,j,word);
				cout<<r<<endl;
				if(r)break;
			}
			
		}
		if(r)break;
	}
	
	return r;
}
bool search(vector<vector<char>>& board,vector<vector<int>>& path,int index,int i,int j,string& word)
{
	//cout<<" -- "<<index<<" "<<i<<" "<<j<<endl;
	if(i>=board.size() || i<0)return false;
	if(j>=board[0].size() || j<0)return false;
	if(path[i][j]==1)return false;
	if(word[index]!=board[i][j])return false;
	

	path[i][j]=1;
	//cout<<board[i][j]<<" "<<index<<" "<<word[index]<<" "<<i<<" "<<j<<endl;
	index++;
	if(word.size()==index){
		return true;
	}
	
	if(search(board,path,index,i-1,j,word)
	||search(board,path,index,i+1,j,word)
	||search(board,path,index,i,j+1,word)
	||search(board,path,index,i,j-1,word))
	{
		return true;
	}
	path[i][j]=0;
	//index--;
	return false;

}
};

int main(){
 Solution s;
 vector<vector<char>> board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
 string word="SEE";
 cout<<s.exist(  board,   word)<<endl;

 word="ABC";
 cout<<s.exist(  board,   word)<<endl;

 board={{'A','B','C','E'}};
 word="ABC";
 cout<<s.exist(  board,   word)<<endl;

 board={{'A','B','C','E'}};
 word="ABD";
 word="ABD";
 cout<<s.exist(  board,   word)<<endl;

  board={{'a','b','c'},{'a','e','d'},{'a','f','g'}};
 word="abcdefg";
 cout<<s.exist(  board,   word)<<endl;
}