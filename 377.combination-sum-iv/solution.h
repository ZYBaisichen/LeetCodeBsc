/*** 
 * @Author: baisichen
 * @Date: 2021-04-22 10:58:26
 * @LastEditTime: 2021-04-23 11:17:46
 * @LastEditors: baisichen
 * @Description: 矩形区域不超过K的最大数值和
 */
#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    
    int count =0;
    int combinationSum4_dfs(vector<int>& nums, int target) {
        int len=nums.size();
        if (len==0) return 0;
        for (int i=0;i<len;i++) {
            combinationSumCore(nums, target, i, 0);
        }
        return count;
    }
    void combinationSumCore(vector<int>& nums, int target, int i, int curSum) {
        if ((curSum+nums[i]) == target) {
            count++;
            return;
        } else if ((curSum+nums[i]) > target) {
            return;
        }
        int len=nums.size();
        for (int i=0;i<len;i++) {
            combinationSumCore(nums, target, i, curSum);
        }
    }

    int combinationSum4_dp(vector<int>& nums, int target) {
        long long len=nums.size();
        if (len==0) return 0;
        vector<long long> dp(target+1, 0);
        dp[0] = 1;
        for (long long i=1;i<=target;i++) {
            for (long long j=0;j<len;j++) {
                if (i>=nums[j] && dp[i - nums[j]] < INT_MAX - dp[i]) {
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};