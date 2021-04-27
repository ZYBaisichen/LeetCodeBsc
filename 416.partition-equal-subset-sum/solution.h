/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-04-27 21:07:48
 * @LastEditors: baisichen
 * @Description: 416. 分割等和子集
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
		int len = nums.size();
		if (len<2) return false;
		int maxNum = INT_MIN, sum = 0;
		for (int i = 0; i<len; i++) {
			if (maxNum<nums[i]) {
				maxNum = nums[i];
			}
			sum += nums[i];
		}
		if (sum % 2 != 0) {
			return false;
		}
		int target = sum / 2;
        if (maxNum > target) return false;
		vector<vector<bool>> dp(len + 1, vector<bool>(target+1, false));
		for (int i = 0; i<=len; i++) {
			dp[i][0] = true;
		}
		dp[1][nums[0]] = true;
		for (int i = 2; i <= len; i++) {
			for (int j = 1; j <= target; j++)
			{
				if (nums[i - 1] > j) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
				}
			}

		}
		return dp[len][target];
	}
};