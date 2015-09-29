#include <vector>
using std::vector;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=0)
    		return 0;
        int result=0;
        for(int i=0;i<prices.size()-1;i++)
        {
        	result=result+(prices[i]>prices[i+1]?0:prices[i+1]-prices[i]);
        }
        return result;
    }
};

int main(){
	
	return 0;
}