#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    int start = 0;
    vector<int> result(size,1);
    int prd=1;
    for(int index=0; index<size; index++) {
      result[index] = result[index]*prd;
      prd = prd*nums[index];
    }
    prd=1;
    for(int index=size-1; index>=0; index--) {
      result[index] = result[index]*prd;
      prd = prd*nums[index];
    }
    return result;
  }
};

void print(const vector<int> &v) {
  for_each(v.begin(), v.end(), [](int n){
    cout<<n<<" ";
  });
  cout<<endl;
};
int main() {
  Solution s;
  vector<int> v={1,2,3};
  print(s.productExceptSelf(v));

  v.clear();
  print(s.productExceptSelf(v));

  v={2,2,3};
  print(s.productExceptSelf(v));

  v={2};
  print(s.productExceptSelf(v));

}