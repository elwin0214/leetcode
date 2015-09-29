#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class BitMap{

private:
	vector<int> vec;
	int bitSize;
	int bitNums;



public:
	BitMap(int capacity){
		this->bitNums=capacity;
		this->bitSize=sizeof(int)-1;
		int size=capacity%bitSize>0?capacity/bitSize:(capacity/bitSize+1);
		for(int i=0;i<size;i++){
			vec.push_back(0);
		}
	}
}
class Solution {


public:


    int findDuplicate(vector<int>& nums)
     	{

    		vector<int>::iterator it;
    		int result=0;
        	for(it=nums.begin();it!=nums.end();it++)
        	{
        		result=result^(*it);

        	}
        	for(int i=0;i<nums.size()-1;i++)
        	{
        		result=result^(i+1);
        	}
        	return result;

    }

};

int main(){
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(1);
	Solution solution;
	cout<<solution.findDuplicate(vec)<<endl;

	return 0;
}