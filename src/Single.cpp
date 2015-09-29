

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>::iterator it;
    	int result=0;
        for(it=nums.begin();it!=nums.end();it++)
        {
        	result=result^(*it);
		}
		return result;
    }
};