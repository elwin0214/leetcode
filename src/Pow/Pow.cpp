
/*


Pow(x, n) My Submissions Question
Total Accepted: 73976 Total Submissions: 270018 Difficulty: Medium
Implement pow(x, n).

Subscribe to see which companies asked this question

*/
#include <iostream>
#include <math.h>

using namespace std;

class Solution 
{
public:
    double myPow(double x, int n) 
    {
        long m =(long)n;
        if (m >= 0)
        {
            return powPositive(x, m);
        }
        else
        {
            return 1 / powPositive(x, (-m));
        }
         
    }
    double powPositive(double x, long n) 
    {

        if (n == 0) return 1;
        if (n == 1) return x;
        long num = n / 2;
        double r = powPositive(x, num);
        return r * r * powPositive(x, n - 2 * num);
    }
};

int main()
{
     cout<<pow(2,2)<<endl;
    Solution sol;
    cout<<sol.myPow(2, 10)<<endl;
    cout<<sol.myPow(1.00000, 2147483648)<<endl;
 

    return 0;
}