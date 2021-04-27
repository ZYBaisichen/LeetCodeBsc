/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-04-27 14:13:45
 * @LastEditors: baisichen
 * @Description: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len==0)return 0;
        vector<vector<int>> dp(len+1, vector<int>(3, 0));
        dp[1][0] = 0;
        dp[1][1] = 0;
        dp[1][2] = -prices[0];
        int sell = false;
        for (int i=2;i<=len;i++) {
            dp[i][0]=max(dp[i-1][0], dp[i-1][1]);
            dp[i][1]=dp[i-1][2]+prices[i-1];
            dp[i][2]=max(dp[i-1][2], dp[i-1][0]-prices[i-1]);
        }
        return max(dp[len][0], dp[len][1]);
    }
};