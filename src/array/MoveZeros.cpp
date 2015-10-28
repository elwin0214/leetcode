#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int i= -1;
    int j= 0;
    for (; j<nums.size(); j++) {
      if (nums[j] == 0) {
        if (i == -1) i = j;
        continue;
      }else {
        if (i == -1)continue;
        nums[i]=nums[j];
        i++;
      }
    }
    if (i == -1) return;
    for (; i<nums.size(); i++) {
      nums[i] = 0;
    }  
  }
};
void print(const vector<int> &v) {
  for_each(v.begin(), v.end(), [](int n){
    cout<<n<<" ";
  });
  cout<<endl;
};
int main(){
  Solution s;
  vector<int> v;
  v={1,2,3,0,0,0};
  s.moveZeroes(v);
  print(v);

  v={1,0,3,0,0,0};
  s.moveZeroes(v);
  print(v);

  v={1,0,3,0,0,9};
  s.moveZeroes(v);
  print(v);

  v={1,2,3,6,8,9};
  s.moveZeroes(v);
  print(v);

}