
/*
https://leetcode.com/problems/word-ladder/

Word Ladder My Submissions Question
Total Accepted: 57713 Total Submissions: 296250 Difficulty: Medium
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
Subscribe to see which companies asked this question


*/
#include <memory>
#include <string>
#include <queue>
#include <unordered_set>
#include <iostream>



using namespace std;



class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) 
    {
        queue<string> q;
        q.push(beginWord);
        q.push("-");
        int dep = 1;
        bool hit = false;
        while(!q.empty())
        {
            string word = q.front();
            q.pop();
            if (word == "-")
            {
                if (q.empty()) break;
                dep++;
                q.push("-");
                continue;
            }
            if (isLadder(word, endWord))
            {
                hit = true;
                break;
            }
            for(auto itr = wordList.begin(); itr != wordList.end();)
            {
                if (isLadder(word, (*itr)))
                {
                    auto next_itr = itr;
                    next_itr++;
                    q.push(*itr);
                    wordList.erase(itr);
                    itr = next_itr;
                }
                else
                {
                    itr++;
                }
            }
        }
        return !hit ? 0 : (dep + 1);
    }

 
    bool isLadder(const string &a, const string &b)
    {
        int diff = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                diff++;
            }
            if (diff > 1) return false;
        }
        return diff == 1;
    }
};

int main()
{

    Solution sol;

{
    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList = {"hot","dot","dog","lot","log"};
    cout<<sol.ladderLength(beginWord, endWord, wordList)<<endl;

}

{
    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList = {"hot","cog","dot","dog","hit","lot","log"};
    cout<<sol.ladderLength(beginWord, endWord, wordList)<<endl;

}
{
        unordered_set<string> wordList = {"hot","dot","dog","lot","log"};
        for (auto i : wordList )
            {cout<<i<<" ";}
        cout<<endl;
        auto itr = wordList.begin();
        auto itr2 = itr;
        itr2++;
        wordList.erase(itr);
        cout << (*itr2)<<endl;
        itr2++;
        cout << (*itr2)<<endl;

        //wordList.erase(itr);

}

}