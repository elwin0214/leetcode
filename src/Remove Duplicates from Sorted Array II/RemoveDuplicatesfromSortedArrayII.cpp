/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

Remove Duplicates from Sorted Array II My Submissions Question
Total Accepted: 58702 Total Submissions: 188129 Difficulty: Medium
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question


*/

#include <vector>
#include <iostream>

using namespace std;

class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.size() == 0) return 0;
        int start = 1;
        int index = -1;
        int value = nums[0];
        int same = 1;
        for ( ; start < nums.size(); start++)
        {
            if (value == nums[start])
            {
                same++;
            }
            else
            {
                value = nums[start];
                same = 1;
            }
            if (index > 0 && index < start && same <= 2)//
            {
                nums[index] = nums[start];
                index++;
            }
            if (index < 0 && same == 3)//find position
            {
                index = start;
            }
        }
        if (index > 0){
            nums.resize(index);
        }
        return nums.size();
    }
};
void print(vector<int> &v)
{
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;
};
int main()
{
    Solution sol;
    {
        vector<int> vec={1,2,3};
        sol.removeDuplicates(vec);
        print(vec);
    }
    {
        vector<int> vec={1,1,1};
        sol.removeDuplicates(vec);
        print(vec);
    }
    {
        vector<int> vec={1,1,2,2,2,3,3,4,5,5,5,5,5};
        sol.removeDuplicates(vec);
        print(vec);
    }
    {
        vector<int> vec={1};
        sol.removeDuplicates(vec);
        print(vec);
    }
    {
        vector<int> vec={1,2};
        sol.removeDuplicates(vec);
        print(vec);
    }
}


