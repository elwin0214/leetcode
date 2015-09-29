#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
/*
 *S[j]=a[j]-min(j-1);
 *max(S[j])
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size()<=0)
        return 0;
        int max_profit=0;
        int min=prices[0];
        for(int i=1;i<prices.size();i++){
            if(min>prices[i-1])min=prices[i-1];
            max_profit=(prices[i]-min)>max_profit?(prices[i]-min):max_profit;
        }
         
        return max_profit;
        }

    };

int main(){
	Solution s;
	vector<int> vec;
	cout<<s.maxProfit(vec)<<endl;

	vec.push_back(5);
	cout<<s.maxProfit(vec)<<endl;
	vec.push_back(6);
	cout<<s.maxProfit(vec)<<endl;
	vec.push_back(10);
	cout<<s.maxProfit(vec)<<endl;
	vec.push_back(2);
	cout<<s.maxProfit(vec)<<endl;
	vec.push_back(20);
	cout<<s.maxProfit(vec)<<endl;
	vec.push_back(1);
	vec.clear();
	vector<int> vec2;
	vec2.push_back(4);
	vec2.push_back(1);
	vec2.push_back(2);

	cout<<s.maxProfit(vec2)<<endl;
	return 0;
}
