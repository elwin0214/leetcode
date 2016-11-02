#include <assert.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
  int continuous(string& s1, string& s2)
  {
    vector<int> v(s2.size() + 1, 0);
    vector<vector<int>> lens(s1.size() + 1, v);

    int max = 0;
    for (int i = 1; i <= s1.size(); i++)
    {
      for (int j = 1; j <= s2.size(); j++)
      {
        if (s1[i - 1] == s2[j - 1]) lens[i][j] = lens[i - 1][j - 1] + 1;
        else 
          lens[i][j] = 0;

        max = max < lens[i][j] ? lens[i][j] : max;
      }
    }
    return max;
  }

  int nocontinuous(string& s1, string& s2)
  {
    vector<int> v(s2.size() + 1, 0);
    vector<vector<int>> lens(s1.size() + 1, v);

    int result = 0;
    for (int i = 1; i <= s1.size(); i++)
    {
      for (int j = 1; j <= s2.size(); j++)
      {
        if (s1[i - 1] == s2[j - 1]) 
          lens[i][j] = lens[i - 1][j - 1] + 1;
        else 
          lens[i][j] = max (lens[i - 1][j], lens[i][j - 1]);

        result = result < lens[i][j] ? lens[i][j] : result;
      }
    }
    return result;
  }
};

int main()
{
  Solution sol;
  string s1 = "abc";
  string s2 = "ac";

  cout << sol.continuous(s1, s2) << endl;
  cout << sol.nocontinuous(s1, s2) << endl;
  return 0;
}