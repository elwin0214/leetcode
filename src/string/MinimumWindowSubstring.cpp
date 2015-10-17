/*
https://leetcode.com/problems/minimum-window-substring/
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

#include <algorithm>
#include <memory>

using namespace std;

#define LEN 256
/*
*/
class Solution {
public:
  string minWindow(string s, string t) {
    //int []
    int dict_len=LEN;
    int dict[LEN]={-1};
    for_each(t.begin(), t.end(), [&dict](char &c){
      int index=(int)c;
      dict[index]=(-1==dict[index]?1:(dict[index]+1));
    });

    int start = 0;
    int end = 0;
    int source_len = s.size();
    int source[LEN] = {-1};
    int min_len = s.size()+1;
    string min_str;

    int search_char = -1;

    for (; end<source_len; end++) {
      char ch=s[end];
      if (-1 == dict[ch]) continue;
      source[ch] = (-1==source[ch]? 1 : (source[ch] + 1));
      if (source[ch] < dict[ch]) continue;
      if ( search_char!= -1 && ch != search_char) continue;

      if (!match(source ,dict, dict_len)) continue;

      for (; start <= end; start++) {
        char ch=s[start];
        if (source[ch] == -1)continue;
        source[ch]--;
        if (source[ch] >= dict[ch]) {
          continue;
        }
        cout<<end<<" "<<start<<" "<<s.substr(start,end-start+1)<<" min_len:"<<min_len<<",dis:"<<(end-start)<<endl;
        if (min_len > (end-start+1)) {
          min_str = s.substr(start,end-start+1);
          min_len=end-start+1;
        }
        search_char = ch;
        start++;
        break;
      }

    }

    return min_str;
  }
  bool match(int *source ,int *dict, int len) {
    for (int i=0; i<len; i++) {
      if (source[i] >= dict[i]) continue;
      return false;
    }
    return true;
  }
};

int main() {
  Solution s;

  cout<<s.minWindow("ADOBECODEBANC","ABC")<<endl;
  cout<<s.minWindow("ADOBECODEBANC","")<<endl;

  cout<<"aa "<<s.minWindow("aa","aa")<<endl;

  cout<<"abc "<<s.minWindow("abc","d")<<endl;

  cout<<"aa "<<s.minWindow("aa","a")<<endl;

  cout<<"aba "<<s.minWindow("aba","a")<<endl;

  cout<<"abc "<<s.minWindow("abc","c")<<endl;

  cout<<"cabwefgewcwaefgcf "<<s.minWindow("cabwefgewcwaefgcf","cae")<<endl;

  cout<<"a "<<s.minWindow("a","a")<<endl;

 
  // map<int,int> m;
  // auto it=m.insert({1,2});
  // cout<<(it.first->second)<<" "<<(it.second)<<endl;
  // it=m.insert({1,3});
  // cout<<(it.first->second)<<" "<<(it.second)<<endl;
  // cout<<(m[1])<<endl;

  // set<int> st;
  // st.insert(2);
  // st.insert(1);
  // st.insert(3);

  // auto i=st.begin();
  // cout<<(*i)<<endl;

  return 0;
}