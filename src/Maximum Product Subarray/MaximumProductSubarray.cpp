/*
Maximum Product Subarray My Submissions Question
Total Accepted: 46296 Total Submissions: 223249 Difficulty: Medium
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

Subscribe to see which companies asked this question
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        int positive = 1;
        int negative = 1;
        int maxProduct = nums[0];
        for (auto i : nums)
        {
            positive = positive * i;
            negative = negative * i;


            int g = max((negative), (positive));
            int l = min((negative), (positive));

            positive = g;
            negative = l;

            maxProduct = max(maxProduct, positive);


            if (positive <= 0)
            {
                positive = 1;
            }
            if (negative >= 0)
            {
                negative = 1;
            }
        }
        return maxProduct;
    }
    int abs(int a)
    {
        return a > 0 ? a : -a;
    }
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    int min(int a, int b)
    {
        return a > b ? b : a;
    }
};


int main()
{
    Solution sol;
    {
        vector<int> v = {1,2, -100, 2,-100,2,0,9,6};
        cout<<sol.maxProduct(v)<<endl;
    }
    {
        vector<int> v = {-2};
        cout<<sol.maxProduct(v)<<endl;
    }
    {
        vector<int> v = {3,-1,4};
        cout<<sol.maxProduct(v)<<endl;
    }
    {
        vector<int> v = {2,-5,-2,-4,3};
        cout<<sol.maxProduct(v)<<endl;
    }
    {
        vector<int> v = {2,-5,-2};
        cout<<sol.maxProduct(v)<<endl;
    }
}
 