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
	int findTargetSumWays_common(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 0) return 0;
		int sum = 0;
		for (int i = 0; i < len; i++){
			sum += nums[i];
		}
		vector<vector<int>> dp(len + 1, vector<int>(1 + 2000, 0));
		//注意: 因为C++实现时不允许负数作为下标，题目中要求数组和不得大于1000，所以下标整体往后移1000
		dp[1][nums[0] + 1000] = 1;
		dp[1][-nums[0] + 1000] += 1;
		for (int i = 2; i <= len; i++) {
			//因为j<=target+1000,nums[i-1]<=1000，所以一定有j+nums[i-1]<=2000, 这也是为什么将数组定义成2000+1维度
			for (int j = -sum + 1000; j <= sum + 1000; j++) {
				int l = j - nums[i - 1]>0 ? dp[i - 1][j - nums[i - 1]] : 0;
				int r = j + nums[i - 1]<2000 ? dp[i - 1][j + nums[i - 1]] : 0;
				dp[i][j] = l + r;
			}
		}
		return dp[len][target + 1000];
	}
	int findTargetSumWays_01(vector<int>& nums, int target) {
		int len = nums.size();
		if (len == 0) return 0;
		int sum = 0;
		for (int i = 0; i < len; i++){
			sum += nums[i];
		}
		if (target>sum || (target+sum)%2 ==1) {
			return 0;
		}
		target = (target+sum)/2;
		vector<vector<int>> dp(len + 1, vector<int>(target+1, 0));
		for (int i=0;i<=len;i++){
			dp[i][0] =1;
		}
		dp[1][nums[0]]  = 1;
		for (int i=2;i<=len;i++) {
			for (int j=1;j<=target;j++) {
				dp[i][j] = dp[i-1][j];
				if (j>=nums[i-1]) {
					dp[i][j]+=dp[i-1][j-nums[i-1]];
				}
			}
		}

		return dp[len][target];
	}
};