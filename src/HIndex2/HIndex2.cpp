
/*


H-Index II My Submissions Question
Total Accepted: 12764 Total Submissions: 40325 Difficulty: Medium
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

Hint:

Expected runtime complexity is in O(log n) and the input is sorted.
Subscribe to see which companies asked this question

Hide Tags Binary Search
Hide Similar Problems (M) H-Index


*/
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        if (citations.size() == 0) return 0;

        int start = 0;
        int end = citations.size() - 1;
        int size = 0;
        int max = 0;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            size = citations.size() - mid;
            if (citations[mid] < size)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
                max = max < size ? size : max;
            }

        }
        return max;
    }
};

int main()
{
    Solution sol;
    {
        vector<int> vec ={1, 1, 1};
        cout<<sol.hIndex(vec)<<endl;
    }

    {
        vector<int> vec ={1, 3, 10};
        cout<<sol.hIndex(vec)<<endl;
    }
     
    
    
}