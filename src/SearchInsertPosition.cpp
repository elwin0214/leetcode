#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) {
    	if(nums.size()<=0)
            return 0;
        for(int i=0;i<nums.size();i++)
        {
        	if(nums[i]>=target)return i;
        	if(nums[i]<target)continue;

        }
        return nums.size();

    }
};
int main(){
	Solution s;
	vector<int> vec;
	vec.push_back(1);
	cout<<s.searchInsert(vec,2);

	return 0;
}

