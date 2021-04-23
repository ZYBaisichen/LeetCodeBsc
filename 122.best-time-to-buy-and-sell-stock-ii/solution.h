/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-04-23 21:22:44
 * @LastEditors: baisichen
 * @Description: 矩形区域不超过K的最大数值和
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int maxProfit_dp(vector<int>& prices) {
        int len = prices.size();
        if (len==0) return 0;
        vector<vector<int>> dp(len+1, vector<int>(2, 0));
        dp[1][0] = 0;
        dp[1][1] = -prices[0];
        for (int i = 2; i <= len; i++)
        {
            /* code */
            dp[i][0] = max(dp[i-1][1]+prices[i-1], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i-1]);
        }
        return dp[len][0];
    }

    int maxProfit_tanxin(vector<int>& prices) {
        int len = prices.size();
        if (len==0) return 0;
        int res = 0;
        for (int i=1;i<len;i++) {
            res += max(0, prices[i]-prices[i-1]);
        }        
        return res;
    }
};