
/*
https://leetcode.com/problems/largest-number/


Largest Number My Submissions Question
Total Accepted: 33243 Total Submissions: 194071 Difficulty: Medium
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags

*/

/*
compare funcutor  strict weak ordering
comapre :

654 与 6543   =>6546543
654 与 6549   =>6549654
*/
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <sstream>

using namespace std;


struct Less{

public:
    bool operator()(int x, int y)
    {
        int a = x;
        int b = y;
        if(a == b) return false;
        if(a == 0) return true;
        if(b == 0) return false;
        int wa = width(a);
        int wb = width(b);
        int nums_a[wa + wb];
        int nums_b[wa + wb];

        int index_a = 0;
        int index_b = wb;

        for (int i = 1; i <= wa; i++)
        {
            int na = a / (pow(10, (wa-i)));
            a = a - na *(pow(10, (wa-i)));
            nums_a[index_a++] = na;
            nums_b[index_b++] = na;
        }
        
        index_b = 0;
        for (int i = 1; i <= wb; i++)
        {
            int nb = b / (pow(10, (wb-i)));
            b = b -nb * (pow(10, (wb-i)));
            nums_a[index_a++] = nb;
            nums_b[index_b++] = nb;
        }

        for (int i = 0; i < wa + wb; i++)
        {
            if (nums_a[i] > nums_b[i]) return false;
            if (nums_a[i] < nums_b[i]) return true;
        }
        return true;
    }
    int width(int n)
    {
        int w = 0;
        while (n > 0)
        { 
            n=n/10;
            w++;
        }
        return w;
    }

};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
    
        std::sort(nums.begin(), nums.end(),Less());

        // for_each(nums.begin(), nums.end(), [](int &n){
        //     cout<<n<<" ";
        // });
        //cout<<endl;
        string str;
        bool zero = true;
        for (auto it = nums.rbegin(); it != nums.rend(); it++)
        {
            if (0 != (*it))
            {
                zero = false;
            }
            stringstream ss;
            ss << (*it);
            string s = ss.str();
            str.append(s);
        }
        if (zero) return "0";
        return  str;
    }
};

int main() {
    //cout<<(pow(10,2))<<endl;
    Solution sol;
    //Less less;
    // cout<<less(12,34)<<endl;
    // cout<<less(1235,123)<<endl;
    // cout<<less(0,1)<<endl;
    // cout<<less(9,0)<<endl;
    //cout<<less(0,0)<<endl;

    {
        vector<int> vec={1,61,32};
        cout<<sol.largestNumber(vec)<<endl;
    }
    
    {
        vector<int> vec={1,0,32};
        cout<<sol.largestNumber(vec)<<endl;
    }

    {
        vector<int> vec={0,0,0};
        cout<<sol.largestNumber(vec)<<endl;
    }

    {
        vector<int> vec={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        //vector<int> vec={1,61,32};
        //vector<int> vec={0,0,0};
        cout<<sol.largestNumber(vec)<<endl;
    }
       {
        vector<int> vec={0,1,2,3};
           //vector<int> vec={1,61,32};
        //vector<int> vec={0,0,0};
        cout<<sol.largestNumber(vec)<<endl;
    }
    






}