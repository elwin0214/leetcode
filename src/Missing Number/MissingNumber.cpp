/*

268. Missing Number My Submissions Question
Total Accepted: 31029 Total Submissions: 81933 Difficulty: Medium
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

*/
/*
交换法
最后值为-1的位置的index 就是目标值
要考虑没有交换的特殊值
*/
#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    int missingNumber(vector<int>& nums) 
    {
        int size = nums.size();
        int miss = -1;
        for (int i = 0; i < size; i++)
        {
            int val = nums[i];
            if (i == val) continue;
            while (i != val && val != -1)
            {

                if (val < size)
                {

                    swap(nums[i], nums[val]);
                    if (nums[i] == -1) 
                        miss = i;
                }
                else
                {
                    nums[i] = -1;
                    miss = i;
                }
                val = nums[i];
            }
        }

        return miss == -1 ? size : miss;
    }
    int missingNumber2(vector<int> &v)
    {
        int miss = 0;

        for (auto i : v)
        {
            miss = miss ^ i; 
        }
        int size = v.size();
        for (int i = 0; i <= size; i++)
        {
            miss = miss ^ i; 
        }
        return miss;
    }
};


int main()
{
    Solution sol;
    {
        vector<int> vec = {0,1,2,4,5};
        cout << sol.missingNumber(vec) << endl; 

    }
    {
        vector<int> vec = {1};
        cout << sol.missingNumber(vec) << endl; 

    }
    {
        vector<int> vec = {0,1,2};
        cout << sol.missingNumber(vec) << endl; 

    }
     {
        vector<int> vec = {2,0};
        cout << sol.missingNumber(vec) << endl; 

    }
    {
        vector<int> vec = {0,1,3,4,5};
        cout << sol.missingNumber2(vec) << endl; 
    }

    cout<<(1^2^1^0)<<endl;
    

    return 0;
}