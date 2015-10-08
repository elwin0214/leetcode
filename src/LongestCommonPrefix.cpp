#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
using std::string;

class Solution 
{
public:
	string longestCommonPrefix(vector<string>& strs) 
	{
		int position=0;
		int size=strs.size();
		if(size<=0)
			return "";
		if(size==1)
		{
			return strs[0];	
		}
		while(true)
		{
			char pre;
			for(int i=0; i<size; i++)
			{
				if(position>=strs[i].length())
				{
					return strs[i].substr(0,position);
				}

				if(i!=0 && pre!=strs[i].at(position))
				{
					return strs[i].substr(0,position);
				}
				else
				{
					pre=strs[i].at(position);
				}
			}
			position++;
		}     
	}
};
int main(){
	Solution s;
	vector<string> vec;
	cout<<s.longestCommonPrefix(vec)<<endl;

	vec.clear();
	vec.push_back("ab");
	cout<<s.longestCommonPrefix(vec)<<endl;

	vec.clear();
	vec.push_back("ab");
	vec.push_back("cd");
	cout<<s.longestCommonPrefix(vec)<<endl;

	vec.clear();
	vec.push_back("abc");
	vec.push_back("abcde");
	vec.push_back("abcd");
	cout<<s.longestCommonPrefix(vec)<<endl;
}
