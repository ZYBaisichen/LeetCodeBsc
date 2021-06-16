/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-06-13 17:22:18
 * @LastEditors: baisichen
 * @Description: 
 */
#include "../../LeetCodeBsc.h"
using namespace std;
class Solution {
public:
	vector<double> dicesProbability_two(int n) {
		long max_sum = 6*n;
		vector<vector<double> > dp(n+1, vector<double>(max_sum+1, 0));

		for (int j=1; j<=6; j++) {
			dp[1][j] = 1.0/6.0;
		}

		for (int i=2;i<=n; i++) {
			for (int j=1; j<=6*i; j++) {
				for (int k=1; k<=6; k++) {
					if (j>k) {
						dp[i][j] += dp[i-1][j-k] / 6.0;
					}
				}
			}
		}

		vector<double> res;
		for (int j=n; j<=6*n; j++) {
			if (dp[n][j] != 0) {
				res.push_back(dp[n][j]);
			}
		}
		return res;
	}
    vector<double> dicesProbability(int n) {
		vector<double> dp(6*n+1, 0.0);
		for (int j=1; j<=6; j++) {
			dp[j] = 1.0/6.0;
		}

		for (int i=2;i<=n; i++) {
			for (int j=i*6; j>= i; j--) {
				dp[j] = 0;
				for (int k=1; k<=6; k++) {
					if (j>k && j-k>=i-1) { //不光要控制j的越界，还要控制上一个骰子的最小和是否越界
						dp[j] += dp[j-k] / 6.0;
					}
				}
			}
		}

		vector<double> res;
		for (int j=n; j<=6*n; j++) {
			if (dp[j] != 0) {
				res.push_back(dp[j]);
			}
		}
		return res;
	}
};