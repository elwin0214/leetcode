/*https://leetcode.com/problems/generate-parentheses/
Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/


#include <vector>
#include <iostream>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::string;
    

class Solution 
{

private:
vector<string> vec;

public:
vector<string> generateParenthesis(int n) 
{
    char array[2*n+1];
    append(array,0,n,n);
    return vec;
}

void append(char array[],int index,int left,int right)
{
    if(left>right)
        return;
    if(left<=0 && right<=0)
    {
        vec.push_back(string(array,index));
    	return;
    }
    	 
    if(left>0)
    {
        array[index++]='(';
        left--;
        append(array,index,left,right);
        left++;
        index--;
    }

    if(right>0)
    {    	 
        array[index++]=')';
        right--;
        append(array,index,left,right);
        right++;
        index--;
    }
}
};


int main()
{
    Solution s;
    vector<string> vec=s.generateParenthesis(10);
    for(int i=0;i<vec.size();i++)
 	  cout<<vec[i]<<endl;
    return 0;
}