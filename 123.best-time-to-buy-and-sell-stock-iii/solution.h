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
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len==0) return 0;
        int buy1,buy1_b,buy2,buy2_b;
        buy1=buy1_b=buy2=buy2_b =-prices[0];
        int sell1, sell1_b, sell2, sell2_b;
        sell1=sell1_b=sell2=sell2_b = 0;
        for (int i=1;i<len;i++) {
            buy1 = max(buy1_b, -prices[i]);
            sell1 = max(buy1_b+prices[i], sell1_b);
            buy2 = max(sell1_b-prices[i], buy2_b);
            sell2 = max(buy2_b+prices[i], sell2_b);
            buy1_b =buy1;
            sell1_b = sell1;
            buy2_b = buy2;
            sell2_b = sell2;
        }
        return sell2;
    }
};