
/*


Implement Trie (Prefix Tree) My Submissions Question
Total Accepted: 20446 Total Submissions: 82520 Difficulty: Medium
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

Subscribe to see which companies asked this question
*/
#include  <memory>
#include <string>
#include <iostream>

#define LEN 26
#define INDEX(x) ((x) - 'a')
using namespace std;

class TrieNode {
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

class Trie {
private:
    void free(TrieNode* node) {
        for (int i = 0; i < LEN; i++)
        {
            if (NULL == (*node)[i]) continue;
            free((*node)[i]);
            //cout<<"delete "<<(char)(i+'a')<<endl;
        }
        delete node;   
    }
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        free(root);
    }


    // Inserts a word into the trie.
    void insert(string word) {
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
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = INDEX(word[i]);
            if ((*node)[index] == NULL)
            {
                return false;
            }
            node = (*node)[index];
        }
        return node->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            int index = INDEX(prefix[i]);
            if ((*node)[index] == NULL)
            {
                return false;
            }
            node = (*node)[index];
        }
        return true;
    }

private:
    TrieNode* root;
};

 

int main(){
    {
    Trie trie;
    trie.insert("abc");
    trie.insert("ab");
    cout<<trie.search("ab")<<endl;
    cout<<trie.search("abc")<<endl;
    cout<<trie.startsWith("abc")<<endl;
    cout<<trie.startsWith("ab")<<endl;
    cout<<trie.startsWith("abcd")<<endl;
    }
    cout<<"==="<<endl;
    {
        Trie trie;
        trie.insert("hello");
        cout<<trie.search("hell")<<endl;
        cout<<trie.search("helloa")<<endl;
        cout<<trie.search("hello")<<endl;
        cout<<trie.startsWith("hell")<<endl;
        cout<<trie.startsWith("helloa")<<endl;
        cout<<trie.startsWith("hello")<<endl;
    }

    // struct Arr a;

    // a[0]=new int(1);
    // int* p=a[0];
    // cout<<(*p)<<endl;

     


}
