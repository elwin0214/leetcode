
/*
https://leetcode.com/problems/gray-code/
Gray Code My Submissions Question

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.


*/
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
/*
n=1:      0               1
n=2:  00       01      11     10     (append:01  10)
n=3 000 001 011 010 110 111 101 100  (append:01 10 01 10)
*/
class Solution 
{
public:
void append(vector<int> &vec,int step)
{
    for(int j=0; j<vec.size(); j++)
    {
        int index=j;
        int dur=j/step;
        if(dur%4==0||dur%4==3)
        {
            vec[index] = (vec[index]<<1);
        }
        else
        {
            vec[index] = (vec[index]<<1)+1;
        }
    }
}
vector<int> grayCode(int n) 
{
    int size=1<<n;
    vector<int> vec;
    for(int i=0;i<size;i++)
    {
        vec.push_back(0);
    }
    for(int i=0;i<n;i++)
    {
        append(vec,1<<(n-1-i));
    }
    return vec;
}
};

void print(vector<int> vec)
{
    for(int j=0;j<vec.size();j++)
    {
        cout<<vec[j]<<" ";
    }
    cout<<endl;
};

int main(){
	Solution s;
	vector<int> vec=s.grayCode(1);
	print(vec);
	vec.clear();
    vec=s.grayCode(2);
	print(vec);
	vec.clear();
	vec=s.grayCode(3);
	print(vec);
	vec.clear();
	vec=s.grayCode(4);
	print(vec);
	return 0;

}
