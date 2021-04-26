/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-04-26 10:54:43
 * @LastEditors: baisichen
 * @Description: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len==0)return 0;
        vector<vector<int>> buy(len+1, vector<int>(k+1, 0));
        vector<vector<int>> sell(len+1, vector<int>(k+1, 0));
        for (int i=1;i<=len;i++) {
            buy[i][0] = sell[i][0] = 0;
            buy[i][1] = -prices[i-1];
        }
        for (int j=1;j<=k;j++) {
            buy[1][j] = -prices[0];
            sell[1][j] = 0;
        }

        for (int i=2;i<=len;i++) {
            for(int j=1;j<=k;j++) {
                buy[i][j] = max(buy[i-1][j], sell[i-1][j-1]-prices[i-1]);
                sell[i][j] = max(sell[i-1][j], buy[i-1][j]+prices[i-1]);
            }
        }
        return sell[len][k];
    }
};