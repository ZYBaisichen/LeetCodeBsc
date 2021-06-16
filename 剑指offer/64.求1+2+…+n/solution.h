/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-13 20:31:12
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int max_profit  = 0;
		int len = prices.size();
		if (len==0) return 0;
		int min_price = prices[0];
		for (int i=1; i<len; i++) {		
			int profit = prices[i] - min_price;
			max_profit = max(profit, max_profit);
			min_price = min(prices[i], min_price);
		}
		return max_profit;
    }
};