/*
https://leetcode.com/problems/h-index/

H-Index My Submissions Question
Total Accepted: 17427 Total Submissions: 65105 Difficulty: Medium
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

Show Hint 
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems



*/
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <vector>


using namespace std;
void print(vector<int> &v)
{
	for_each(v.begin(),v.end(),[](int &n){cout<<n<<" ";});
	cout<<endl;
}

class Solution {
public:
int hIndex(vector<int>& citations) 
{
	quicksort(citations, 0,citations.size()-1);
 	int result=0;
 	int size=0;
	for(int index=citations.size()-1; index>=0; index--)
	{
		size++;
		if(citations[index]<size)
		{
			break;
		}
		//if(citations[index-1]<size || index==0)
		//{
			result=max(result,size);
		//}
		
	}
  return  result;
}
 
void swap(int &i ,int &j)
{
	int tmp=i;
	i=j;
	j=tmp;
}

void quicksort(vector<int> &vec,int start,int end)
{
	if(start>=end)return;
	int i=start;
	int j=end;
	int key=vec[i];
	for(j=i+1;j<=end;j++)
	{
		if(vec[j]<=key)
		{
			i++;
			swap(vec[i],vec[j]);
		}
	}
	swap(vec[i],vec[start]);
	//print(vec);
	quicksort(vec,start,i-1);
	quicksort(vec,i+1,end);

}

};

int main()
{
	Solution s;

	vector<int> v={1,4,2,5,9,2,4,6};
	cout<<s.hIndex(v)<<endl;
	print(v);

	v={3,0,6,1,5};
	print(v);
	cout<<s.hIndex(v)<<endl;

	v={1,1,1,1,1};
	print(v);
	cout<<s.hIndex(v)<<endl;

	v={3,100,100,100,100};
	print(v);
	cout<<s.hIndex(v)<<endl;
	// s.quicksort(v, 0, v.size()-1);
	// print(v);


	// v={1,2,3};
	// s.quicksort(v, 0, v.size()-1);
	// print(v);

	// v={3,2,1};
	// s.quicksort(v, 0, v.size()-1);
	// print(v);

	// v={1,1,1};
	// s.quicksort(v, 0, v.size()-1);
	// print(v);
	map<int,pair<int,vector<int>* > > m;
	m.insert({1,{2,new vector<int>()}});

	return 0;
}