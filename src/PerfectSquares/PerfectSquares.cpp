/*
https://leetcode.com/problems/perfect-squares/
Perfect Squares My Submissions Question
Total Accepted: 13329 Total Submissions: 46333 Difficulty: Medium
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

*/
/*
思路：

数列：1，4，9，16.....m*m

a[k]表示对于k的目标值

if(i*i=(k+1)){
    a[k+1]=1
}else{
    a[k+1]=min({a[k+1-i*i]+1|i*i>=1&&i*i<(k+1)})
}


*/
#include <iostream>
#include <math.h>
#include <memory>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (0 == n) 
            return 0;

        int m = sqrt(n);
        int a[n];
        memset(a, 0, sizeof(a));
        a[0] = 1;
        for (int k = 1; k < n; k++) {
            int s = sqrt(k + 1);
            if (s * s == (k + 1)) {
                a[k] = 1;
                continue;
            }
            int min = k + 1;

            for (int i = 1; i <= s; i++) {
                int tmp = a[k - i * i] + 1;
                min = min > tmp ? tmp : min;
            }
            a[k] = min;
           // cout<<(1+k)<<" "<<min<<endl;
        }
        return a[n-1];
    }
};
int main() {
    Solution sol;

    cout<<sol.numSquares(13)<<endl;
    cout<<sol.numSquares(12)<<endl;

    return 0;
}