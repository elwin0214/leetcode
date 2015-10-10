
#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class NQueue
{
  public:
    vector<int> oneNQueue(int n)
    {
    	int x=0;
    	vector<int> vec;
	 	  for(int x=0; x<n; x++)
	 	  {
	 		  vec.push_back(-1);
	 	  }
	 	  while(true)
	 	  {
	 		  while(true)
	 		  {
	 			  vec[x]++;
	 			  if(vec[x]>=n)
	 			  {
	 				  vec[x]=-1;
	 				  x--;
	 				  break;
	 			  }
	 			  if(conflict(vec,x,vec[x]))
	 			  {
	 				  continue;
	 			  }
	 			  else
	 			  {
	 				  x++;
	 				  break;
	 			  }
	 		  }
	 		  if(vec[0]==-1)
	 		  {
	 			  break;
	 		  }
	 		  if(x>=n)
	 		  {
	 			 break;
	 		  }
	 	  }
	 	  return vec;
	 }

    vector<vector<int>> totalNQueues(int n)
	  {
	 	  int x=0;
	 	  vector<vector<int>> totalVec;
	 	  vector<int> vec;
	 	  for(int x=0; x<n; x++)
	 	  {
	 		  vec.push_back(-1);
	 	  }
	 	  while(true)
	 	  {
	 		  while(true)
	 		  {
	 			  vec[x]++;
	 			  if(vec[x]>=n)
	 			  {
	 				  vec[x]=-1;
	 				  x--;
	 				  break;
	 			  }
	 			  if(conflict(vec,x,vec[x]))
	 			  {
	 				  continue;
	 			  }
	 			  else
	 			  {
	 				  x++;
	 				  break;
	 			  }
	 		  }
	 		  if(vec[0]==-1)
	 		  {
	 			  break;
	 		  }
	 		  if(x>=n)
	 		  {
	 			  totalVec.push_back(vec);
	 			  x--;
	 			  continue;
	 			//break;
	 		  }
	 	  }
	 	  return totalVec;
      }

	   bool conflict(vector<int> &vec,int x,int y)
	   {
        for(int i=0; i<x; i++)
	 		  {
	 			  if(abs(x-i)==abs(y-vec[i]) || y==vec[i])
	 			  {
	 				  return true;
	 			  }
	 			  continue;

	 		  }
	 		  return false;
	    }
};

int main(){
	NQueue nq;
	vector<int> vec=nq.oneNQueue(5);
	for(int i=0;i<vec.size();i++)
	{
		cout<<vec[i]<<" ";
	}
	cout<<endl;
	vector<vector<int>> totalVec=nq.totalNQueues(4);
	for(int i=0;i<totalVec.size();i++)
	{
		for(int j=0; j<totalVec[i].size();j++)
			cout<<totalVec[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}