#include <vector>
#include <queue>
#include <iostream>
#include <string>
#include <algorithm>


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
	print(v);
	cout<<s.hIndex(v)<<endl;

	v={3,0,6,1,5};
	print(v);
	cout<<s.hIndex(v)<<endl;

	v={1,1,1,1,1};
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
}