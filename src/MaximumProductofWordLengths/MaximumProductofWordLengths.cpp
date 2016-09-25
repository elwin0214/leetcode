/*
318. Maximum Product of Word Lengths My Submissions Question
Total Accepted: 5729 Total Submissions: 15215 Difficulty: Medium
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Hide Tags Bit Manipulation
Have you met this question in a real interview? Yes  No
Discuss


*/
#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    int maxProduct(vector<string>& words) 
    {
        vector<int> bits(words.size(), 0);
        int i = 0;
        for (auto word : words)
        {
            for (auto c : word)
            {
                bits[i] = bits[i] | 1 << (c - 'a');
            }
            i++;
        }

        int max = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j <words.size(); j++)
            {
                if ((bits[i] & bits[j]) > 0) continue;
                int product = words[i].size() * words[j].size();
                if (max < product)
                    max = product;
            }
        }
        return max;
    }
};

int main()
{
    Solution sol;
    {
        vector<string> vec = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
        cout<< (sol.maxProduct(vec)) << endl;
    }
    {
        vector<string> vec = {"a", "aa", "aaa", "aaaa"};
        cout<< (sol.maxProduct(vec)) << endl;
    }
}






