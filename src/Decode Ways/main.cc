/*
91. Decode Ways
https://leetcode.com/problems/decode-ways/description/

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.


*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  int str2int(string& s)
  {
    if (s[0] == '0') return -1;
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
      sum = sum * 10;
      sum += s[i] + 1 - '1';
    }
    return sum;
  }

  int numDecodings(string str) 
  {
    if (str.size() == 0) return 0;
    if (str[0] == '0') return 0;
    int size = str.size();
    std::vector<int> nums(size + 1);
    nums[0] = 1;
    nums[1] = 1;
    for (int i = 2; i < size + 1; i++)
    {
      int k = i - 1;
      string s = str.substr(k, 1);
      int n = str2int(s);
      if (n > 0 && n <= 9)
        nums[i] = nums[i - 1];
      s = str.substr(k - 1, 2);
      n = str2int(s);
      if (n >= 1 && n <= 26)
        nums[i] += nums[i-2];

      if (nums[i] == 0) return 0;
    }
    return nums[size];
  }
};

int main()
{
  Solution s;
  cout << s.numDecodings("12") << endl;
  cout << s.numDecodings("12121212") << endl;
  cout << s.numDecodings("") << endl;
  cout << s.numDecodings("0") << endl;
  cout << s.numDecodings("1200") << endl;
  cout << s.numDecodings("130") << endl;
  cout << s.numDecodings("210") << endl;
  cout << s.numDecodings("101") << endl;


  return 0;
}