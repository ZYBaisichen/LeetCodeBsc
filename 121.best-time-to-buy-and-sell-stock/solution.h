/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-04-24 17:26:22
 * @LastEditors: baisichen
 * @Description: 买卖股票最佳时机，只能买卖一次
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int maxProfit_dfs(vector<int>& prices) {
        int len = prices.size();
        if (len==0) return 0;
        int ans = 0;
        for (int i=0;i<len-1;i++) {
            int max_i = INT_MIN;
            for (int j=i+1;j<len;j++) {
                if (max_i<prices[j]-prices[i]) {
                    max_i= max(prices[j]-prices[i], 0);
                }
            }
            ans = max(max_i, ans);
        }
        return ans;
    }
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len==0) return 0;
        int ans = 0;
        int min_price = prices[0];
        for (int i=0;i<len;i++) {
            if (min_price > prices[i]) {
                min_price = prices[i];
            }
            ans = max(prices[i]-min_price, ans);
            min_price = min(min_price, prices[i]);
        }
        return ans;
    }
};