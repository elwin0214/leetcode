

/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Longest Substring Without Repeating Characters My Submissions Question
Total Accepted: 105242 Total Submissions: 509502 Difficulty: Medium
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

Subscribe to see which companies asked this question

Hide Tags Hash Table Two Pointers String
Hide Similar Problems (H) Longest Substring with At Most Two Distinct Characters


*/

/*

step 1:
3 - (-1) -1 = 3
i        j 
|        |
-1 0 1 2 3 4 5 6 
   a b c a

step 2: 小于step1

3 - 0 = 3; 
   i     j 
   |     |
-1 0 1 2 3 4 5 6 
   a b c a


step 3:
6-1-1 = 4
     i         j
     |         |
-1 0 1 2 3 4 5 6
   a a b c d e 

*/
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;
class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int> map;

        int size = s.size();
        int i = -1;
        int j = 0;

        char ch = s[0];
        bool add = true ;
        int max = 0;
        for(; j < size; add ? j++ : i++)
        {
            if (add )
            {
                char ch = s[j];
                auto itr = map.find(ch);
                if (map.end() == itr || (itr->second) == 0)
                {
                    map[ch] = 1;
                }
                else
                {
                    max = max < (j - i - 1) ? (j - i - 1) : max;// step 1
                    (itr -> second)++;
                    add = false;
                }
            }
            else
            {
                char ch = s[i];
                auto itr = map.find(ch);
                (itr->second)--;
                if (itr->second == 1)
                {
                    add = true;
                    //max = max < (j - i) ? (j - i) : max; //step 2
                }
            }

            //map[]
        }
        max = max < (j - i - 1) ? (j - i - 1) : max;  //step 3
        return max;
    }
};

int main()
{
    Solution sol;
    cout<<sol.lengthOfLongestSubstring("abcabcbb")<<endl;

    cout<<sol.lengthOfLongestSubstring("abc")<<endl;

    cout<<sol.lengthOfLongestSubstring("abc")<<endl;

    cout<<sol.lengthOfLongestSubstring("aaaa")<<endl;

    cout<<sol.lengthOfLongestSubstring("dvdf")<<endl;

}