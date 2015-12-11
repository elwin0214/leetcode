
/*
https://leetcode.com/problems/single-number-iii/

Single Number III My Submissions Question
Total Accepted: 17714 Total Submissions: 43537 Difficulty: Medium
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

*/
#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int r = 0;
        vector<int> result;
        for (auto i : nums)
        {
            r = r ^ i;
        }
        int size = 8 * sizeof(int);
        int n1 = 0;
        int n2 = 0;

        int pos = 0;
        for (pos = 0; pos < size; pos++)
        {   
            if ((r & ( 1 << pos )) != 0) break;
        }
        int flag = r & (~(r - 1));
        for (auto i : nums)
        {
            if ((i & (1 << pos)) == 0)
                n1 = n1 ^ i;
            else
                n2 = n2 ^ i;
        }
        result.push_back(n1);
        result.push_back(n2);
        return result;
    }
};

int main(int argc, char const *argv[])
{   
    Solution sol;
    {
        vector<int> nums = {1, 2, 3, 4, 5, 5, 4, 9, 1, 9};
        vector<int> result = sol.singleNumber(nums);
        cout<<result[0]<<" "<<result[1]<<endl;
    }
    {
        vector<int> nums = { 2, 4, 3, 3};
        vector<int> result = sol.singleNumber(nums);
        cout<<result[0]<<" "<<result[1]<<endl;
    }
    {
        vector<int> nums = {83228806,-1717526682,1077617512,-1123081094,-580087697,-2008159651,-1328945687,-1724025951,1906414438,-1328945687,127027955,1599231006,-1015245959,1525771031,-1724025951,504069278,-421951591,1128109329,-1636948698,-1710739995,-990200330,-1885581982,1525771031,1261935573,-990200330,1585876929,278121904,-1348447747,1333211252,-1636948698,1128109329,1576801976,683467816,-1015245959,-1054654622,-196197385,1077617512,2047508274,-290544887,-705154692,504069278,-681249779,-520018417,1899454519,1333211252,1760011772,-1854431609,-421951591,46833585,1661877883,115910757,-1348447747,1261935573,-1854431609,-1710739995,1460311824,1585876929,766747336,1906414438,732062541,-1040314207,-1040314207,1576801976,2047508274,356648328,1899454519,908059332,1105519108,-722029362,1382440358,-1050023251,1661877883,-1122489884,-249225705,278121904,-1388723410,1727624697,127027955,-1122489884,-1050023251,1382440358,738046429,83228806,-249225705,82371534,-1717526682,-1885581982,-705154692,-722029362,-1054654622,1760011772,-1123081094,-2008159651,766747336,-580087697,46833585,115910757,1033398425,683467816,-681249779,908059332,-1388723410,1105519108,356648328,-520018417,-290544887,1599231006,738046429,82371534,732062541,1460311824,-196197385};
        vector<int> result = sol.singleNumber(nums);
        cout<<result[0]<<" "<<result[1]<<endl;
    }
 
    return 0;
}
