#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
/*
 *S[n]=root[1]+root[2]+..+root[k]+..root[n]
      =S[0]*S[n-1]+S[1]*S[n-2]+...+S[k-1]*S[n-k]+....S[n-1]*S[0]
*/
class Solution {
	
public:
    int numTrees(int n) {
    	vector<int> vec;
    	for(int i=0; i<=n; i++)
    		vec.push_back(0);
    	vec[0]=1;
    	vec[1]=1;
    	vec[2]=2;
        int sum=0;
        for(int i=0; i<=n; i++)
        {
        	if(vec[i]==0)
            {	
                int sum=0;
                for(int j=0; j<i; j++)
                {
                    sum=sum+vec[j]*vec[i-j-1];
                }
                vec[i]=sum;
        	}
        }
        return vec[n]; 
    }
};
int main(){
	Solution s;
	cout<<s.numTrees(1)<<endl;
	cout<<s.numTrees(2)<<endl;
	cout<<s.numTrees(6)<<endl;
	cout<<s.numTrees(19)<<endl;

	return 0;
}