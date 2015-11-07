

/*
https://leetcode.com/problems/add-and-search-word-data-structure-design/

Add and Search Word - Data structure design My Submissions Question
Total Accepted: 13958 Total Submissions: 68409 Difficulty: Medium
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.


*/

#include  <memory>
#include <string>
#include <iostream>

#define LEN 26
#define INDEX(x) ((x) - 'a')

using namespace std;

class TrieNode 
{
private:
    TrieNode* children[LEN];

protected:
    bool isWord;

friend class Trie;
public:
    // Initialize your data structure here.
    TrieNode():isWord(false) {
        memset(children, 0, sizeof(children));
    }
    ~TrieNode() {

    }
    TrieNode* &operator[](int i){
        return children[i];
    }

};

class Trie 
{
private:
    void free(TrieNode* node) 
    {
        for (int i = 0; i < LEN; i++)
        {
            if (NULL == (*node)[i]) continue;
            free((*node)[i]);
            //cout<<"delete "<<(char)(i+'a')<<endl;
        }
        delete node;   
    }
public:
    Trie() 
    {
        root = new TrieNode();
    }
    ~Trie() 
    {
        free(root);
    }


    // Inserts a word into the trie.
    void insert(string word) 
    {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = INDEX(word[i]);
            if((*node)[index] == NULL)
            {
                (*node)[index] = new TrieNode();
            }
            node = (*node)[index];
        }
        node->isWord=true;
    }

    // Returns if the word is in the trie.
    bool search(string &word, int pos, TrieNode* node) 
    {
        //TrieNode* node = root;

        if (pos == word.size())
        {
            return node->isWord;
        }
        if ('.' == word[pos])
        {
            for (int i = 0; i < LEN; i++)
            {
                TrieNode* n = (*node)[i];
                if (NULL == n) continue;
                if (search(word, pos+1, n)) return true;
            }
            return false;
        }
        else
        {
            int index = INDEX(word[pos]);
            if ((*node)[index] == NULL) return false;
            node = (*node)[index];
            return search(word, pos+1, node);
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool search(string &word) 
    {
        return search(word, 0, root);
    }

private:
    TrieNode* root;
};

class WordDictionary 
{
private:
    Trie trie;

public:
    void addWord(string word) 
    {
        trie.insert(word);
    }

    bool search(string word) 
    {
        return trie.search(word);
    }
};

int main()
{
    WordDictionary wd;
    wd.addWord("abc");
    wd.addWord("abcd");
     wd.addWord("cde");
    cout<<wd.search("abc")<<endl;
    cout<<wd.search("ab.")<<endl;
    cout<<wd.search("abc")<<endl;
    cout<<wd.search("ab.")<<endl;
    cout<<wd.search(".b.")<<endl;
    cout<<wd.search(".c.")<<endl;
    cout<<wd.search(".c..")<<endl;
    cout<<wd.search(".b..")<<endl;
}

