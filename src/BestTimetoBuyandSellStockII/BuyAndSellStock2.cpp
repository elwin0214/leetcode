

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
Best Time to Buy and Sell Stock II

Best Time to Buy and Sell Stock II My Submissions Question
Total Accepted: 65863 Total Submissions: 165728 Difficulty: Medium
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Subscribe to see which companies asked this question

*/
#include <vector>

using std::vector;

class Solution {
public:
int maxProfit(vector<int>& prices)
{
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