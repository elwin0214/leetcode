

/*
https://leetcode.com/problems/permutation-sequence/

Permutation Sequence My Submissions Question
Total Accepted: 42083 Total Submissions: 179023 Difficulty: Medium
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

*/
/*
思路：分组 求位置
S={1，2，3，... n}
k=k-1; 减1 便于计算

a1 = (k)/((n-1)!) + 1 ; k = k%((n-1)!)=> 第一个数是 是S里面的第a1个数，

a2 = (k)/((n-2)!) + 1; k=...  => 第二个数是 S里面第a2个数（去掉上一步的a1个数后）
*/
#include <iostream>
#include  <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int array[n+1];
        array[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            array[i] = array[i-1] * i; 
        }
        vector<int> visited(n, 0);
        string result;
        result.reserve(n);
        k = k -1;
        for (int i = 1; i <= n ; i++)
        {
            int index = k / array[n-i];
            k = (k % array[n-i]);            
            for (int j = 0; j < visited.size(); j++)
            {
                if (visited[j] != 0)continue;
                if(index == 0)
                {
                    visited[j] = 1;
                    result.push_back(static_cast<char>(j + 1 + '1' -1));
                    break;
                }
                index--;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout<<sol.getPermutation(9,10)<<endl;
}