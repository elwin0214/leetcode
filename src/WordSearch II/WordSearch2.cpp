
/*
https://leetcode.com/problems/word-search-ii/
Word Search II My Submissions Question

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.

思路：

注意trie tree 构造，判断是否为word。比如 "abc" "abcd"均为word


*/

#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>

using namespace std;

#define MAX_SIZE 26

class TrieNode{
private:
	vector<TrieNode*> children;

public:
	bool word;

public:
	TrieNode(bool word=false):children(MAX_SIZE),word(word)
	{
	}
	bool isWord()
	{
		return word;
	}
	TrieNode* &operator[](int index)
	{
		return children[index];
	}

};

class TrieTree{

private:
	TrieNode *root;

	void free(TrieNode *node){
		for (int i = 0;i < MAX_SIZE; i++)
		{
			if ((*node)[i] == NULL) continue;
			free((*node)[i]);
		}
		delete node;
	}

public:
	TrieTree(){
		root = new TrieNode();
	}
	TrieNode* getRoot()
	{
		return root;
	}
	void add(vector<string> &words)
	{
		for(int i = 0; i < words.size(); i++)
		{
			int len = words[i].size();
			TrieNode *node = root;
			for(int j=0; j < len; j++)
			{
				int index = words[i][j] - 'a';
				TrieNode *child = (*node)[index];
				if(child == NULL)
				{
					child = new TrieNode();
					(*node)[index] = child;
				}
				if(j == len - 1)//aaab,aaa or aaa,aaab !!! overwrite
				{
					child->word = true;
				}
				node = child;
			}
		}
	}
	~TrieTree(){
		free(root);
	}
	void show()
	{
		queue<TrieNode*> queue;
		queue.push(root);
		while(!queue.empty())
		{
			TrieNode *node = queue.front();
			queue.pop();
			for(int i = 0;i < MAX_SIZE; i++)
			{
				if ((*node)[i] == NULL) continue;
				queue.push((*node)[i]);
				cout<< ((char)(i + 'a'))<< i << "(" << (*node)[i]->word<<")" << " ";
			}
			cout<< endl;
		}
	}
	void list(vector<string> &vec, vector<char> &str, TrieNode *node)
	{
		for(int i = 0; i < MAX_SIZE; i++)
		{
			if ((*node)[i] == NULL)
				continue;
			str.push_back((char)('a' + i));
			if ((*node)[i]->isWord())
			{
				vec.push_back(string(str.begin(), str.end()));
			}

			list(vec,str,(*node)[i]);
			str.erase(str.end() - 1);
		}
	}
  void list(vector<string> &vec)
	{
		vector<char> v;
		list(vec, v, root); 
	}
};
 
class Solution {
public:
vector<string> findWords(vector<vector<char>>& board, vector<string> &words) 
{
	vector<string> result;
	int m = board.size();
	if(m == 0)
		return result;
	int n = board[0].size();

	vector<vector<int>> path;
	for(int i = 0; i < m; i++)
	{
		path.push_back(vector<int>(n));
	}
	TrieTree tree;
	tree.add(words);

	TrieNode *root = tree.getRoot();
 	vector<char> word;
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if((*root)[board[i][j] - 'a']!=NULL)
			{
				search(board, result, word, path, i, j, root);
			} 
		}
	}
	 

	return result;
}

void search(vector<vector<char>>& board, vector<string> &result, vector<char> &word, vector<vector<int>>& path, int i, int j, TrieNode *node)
{
	
	if (path[i][j] == 1)
	{
 		return;
	}
	TrieNode *child=(*node)[board[i][j] - 'a'];
	if (child == NULL)
	{
 		return;
	}
 
	path[i][j] = 1;
	word.push_back(board[i][j]);
	if(child->isWord())
	{
		child->word = false;
		string s(word.size(), ' ');
		int k = 0;

		for_each(word.begin(), word.end(), [&](char c){
			s[k++]=c;
		});
		result.push_back(s);
	}
	if(i < board.size() && i>0) 
	{
		search(board, result, word, path, i - 1, j, child);
	}
	if(i < board.size() - 1 && i >= 0)
	{
		search(board, result, word, path, i + 1, j, child);
	}
	if(j < board[0].size() && j > 0)
	{
		search(board, result, word, path, i, j - 1, child);
	}
	if(j < board[0].size()-1 && j>=0)
	{
		search(board, result, word, path, i, j + 1, child);
	}

	word.erase(word.end() - 1);
	path[i][j] = 0;
}
};

void print(vector<string> words)
{
	for(int i = 0; i < words.size(); i++)
	{
		cout<<words[i]<<endl;
	}
	cout<<endl;
}
void print(TrieTree &tree)
{
	vector<string> vec;
 	tree.list(vec);
 	for(int i=0;i<vec.size();i++)
 	{
 		cout<<vec[i]<<endl;
 	} 
 	cout<<endl;
}
int main(){
 Solution s;
 vector<vector<char>> board={{'a','b','c','e'},{'s','f','c','s'},{'a','d','e','e'}};
 vector<string> words={"see","abc","xyz","abce"};
 print(s.findWords(board,words));

 words={"abc"};
 print(s.findWords(board,words));

 board={{'a','b','c','d'}};
 words={"abc"};
 print(s.findWords(board,words));

 board={{'a','b','c','e'}};
 words={"abd"};
 print(s.findWords(board,words));

 board={{'a','a'}};
 words={"a"};
 print(s.findWords(board,words));

 board={{'a','b'},{'a','a'}};
 words={"aba","baa","bab","aaab","aaa","aaaa","aaba"};

 print(s.findWords(board,words));

}