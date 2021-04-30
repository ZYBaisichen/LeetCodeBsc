/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-04-27 21:07:48
 * @LastEditors: baisichen
 * @Description: 494.目标和
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
	int change(int amount, vector<int>& coins) {
		int len = coins.size();
		if (len == 0) return 0;
		if (amount == 0) return 1;
		vector<vector<int>> dp(len + 1, vector<int>(amount + 1, 0));
		for (int i = 1; i <= len; i++) {
			dp[i][0] = 1;
		}
		for (int k = 1; k <= amount / coins[0]; k++) {
			dp[1][k*coins[0]] = 1;
		}
		for (int i = 2; i <= len; i++) {
			for (int j = 1; j <= amount; j++)
			{
				int sum = 0;
				for (int k = 0; k <= j / coins[i - 1]; k++) {
					sum += dp[i - 1][j - k*coins[i - 1]];
				}
				dp[i][j] = sum;
			}

		}
		return dp[len][amount];
	}
};