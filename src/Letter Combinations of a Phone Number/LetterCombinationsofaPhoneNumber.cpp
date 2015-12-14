/*

Letter Combinations of a Phone Number My Submissions Question
Total Accepted: 62330 Total Submissions: 231908 Difficulty: Medium
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

Subscribe to see which companies asked this question

*/

#include <iostream>
#include <vector>

using namespace std;

struct TelTable
{
    vector<string> table;
    TelTable()
    {
        table.reserve(8);
        table.push_back("abc");
        table.push_back("def");
        table.push_back("ghi");
        table.push_back("jkl");
        table.push_back("mno");
        table.push_back("pqrs");
        table.push_back("tuv");
        table.push_back("wxyz");
    }
    string& operator[](int index)
    {
        return table[index];
    }
};

class Solution 
{
private:
    TelTable table;
public:
    Solution()
    {
        
    }
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> results;
        if (0 == digits.size())
            return results;
        vector<char> str;
        str.reserve(digits.size());
        letterCombinations(results, digits, 0, str);
        return results;
    }

    void letterCombinations(vector<string> &results, string &digits, int index, vector<char> &str) 
    {
        if (index == digits.size())
        {
            //cout<<string(str.begin(),str.end())<<endl;

            results.push_back(string(str.begin(),str.end()));

            return ;
        }

        string letter = table[digits[index] + 1 - '1' - 2];
        for (int i = 0; i < letter.size(); i++)
        {
            str.push_back(letter[i]);
            index++;
            letterCombinations(results, digits, index, str); 
            str.erase(str.end() - 1);
            index--;
        }
    }
};

void print(vector<string> &results)
{
    for (auto i : results)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}
int main()
{
    // vector<char> str;
    // str.push_back('a');
    // string s(str.begin(), str.end());
    // cout<<s<<endl;
    Solution sol;
    vector<string> results = sol.letterCombinations("23");
    print(results);
    return 0;
}